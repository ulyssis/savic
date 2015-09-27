/***************************************************************************
 * file:        ChannelAccess.cc
 *
 * author:      Marc Loebbers, Rudolf Hornig, Zoltan Bojthe
 *
 * copyright:   (C) 2004 Telecommunication Networks Group (TKN) at
 *              Technische Universitaet Berlin, Germany.
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 *              For further information see file COPYING
 *              in the top level directory
 **************************************************************************/


#include "ChannelAccess.h"
#include "IMobility.h"
#include "UDPPacket_m.h"
#include "AirFrame_m.h"
#include "IPv4Datagram.h"

#define coreEV (ev.isDisabled()||!coreDebug) ? ev : ev << logName() << "::ChannelAccess: "

simsignal_t ChannelAccess::mobilityStateChangedSignal = SIMSIGNAL_NULL;
#ifdef PU_CHA
simsignal_t ChannelAccess::PUStateChangedSignal = SIMSIGNAL_NULL;

#endif

static int parseInt(const char *s, int defaultValue)
{
    if (!s || !*s)
        return defaultValue;

    char *endptr;
    int value = strtol(s, &endptr, 10);
    return *endptr == '\0' ? value : defaultValue;
}

// the destructor unregister the radio module
ChannelAccess::~ChannelAccess()
{
    if (cc && myRadioRef)
    {
        // check if channel control exist
        IChannelControl *cc = dynamic_cast<IChannelControl *>(simulation.getModuleByPath("channelControl"));
        if (cc)
             cc->unregisterRadio(myRadioRef);
        myRadioRef = NULL;
    }
}
/**
 * Upon initialization ChannelAccess registers the nic parent module
 * to have all its connections handled by ChannelControl
 */
void ChannelAccess::initialize(int stage)
{
    BasicModule::initialize(stage);

    if (stage == 0)
    {
        cc = getChannelControl();

        nb = NotificationBoardAccess().get();
        hostModule = findHost();
     //   std::cout<<"ChannelAccess::initialize, hostModule full path, "
               // <<hostModule->getFullPath().c_str()<<endl;
        positionUpdateArrived = false;
        // register to get a notification when position changes
        mobilityStateChangedSignal = registerSignal("mobilityStateChanged");
        hostModule->subscribe(mobilityStateChangedSignal, this);
#ifdef PU_CHA
       // puStateList.insert(std::pair<char*,int>("pu[0]",OFF));
       // puStateList.insert(std::pair<char*,int>("pu[1]",OFF));

#ifdef CAVCAPBUFFER

        CheckBufferMsg=new cMessage();
        schedulecounter=0;
#endif
#ifdef MULTI_CHA

#endif
#endif

    }
    else if (stage == 2)
    {

        if (!positionUpdateArrived)
        {
            radioPos.x = parseInt(hostModule->getDisplayString().getTagArg("p", 0), -1);
            radioPos.y = parseInt(hostModule->getDisplayString().getTagArg("p", 1), -1);

            if (radioPos.x == -1 || radioPos.y == -1)
                error("The coordinates of '%s' host are invalid. Please set coordinates in "
                        "'@display' attribute, or configure Mobility for this host.",
                        hostModule->getFullPath().c_str());

            const char *s = hostModule->getDisplayString().getTagArg("p", 2);
            if (s && *s)
                error("The coordinates of '%s' host are invalid. Please remove automatic arrangement"
                        " (3rd argument of 'p' tag)"
                        " from '@display' attribute, or configure Mobility for this host.",
                        hostModule->getFullPath().c_str());
        }
/*#ifdef MULTI_CHA

        numChannel=getParentModule()->getParentModule()->getParentModule()->getSubmodule("channelControl")->getAncestorPar("numChannels").longValue();
         std::cout<<"ChannelAccess::ini, numChannel: "<<numChannel<<endl;
#endif*/
        myRadioRef = cc->registerRadio(this);

        cc->setRadioPosition(myRadioRef, radioPos);
#ifdef PU_CHA
        cc->allocatePU(myRadioRef,radioPos);
#endif

#ifdef PU_CHA
        PUStateChangedSignal=registerSignal("puStateChanged");
        PrimaryUser* PUModule;
        int PUNo=getParentModule()->getParentModule()->getParentModule()->par("numPU");
       // std::cout<<"ChannelAccess::ini, numPU: "<<PUNo<<endl;
        for(int i=0;i<PUNo;i++)
        {
            std::string puname="pu[";
            std::stringstream ss;
            ss << i;
            std::string stringi = ss.str();

            puname.append(stringi);
            puname.append("]");
            PUModule=check_and_cast<PrimaryUser*>(getParentModule()->getParentModule()->getParentModule()->getModuleByRelativePath(puname.c_str()));
        //   std::cout<<"ChannelAccess::initialize, pu path: "<<getParentModule()->getParentModule()->getParentModule()->getModuleByRelativePath(puname.c_str())->getFullPath()<<endl;
           if(isInfluencedPU(PUModule))
           {
              PUModule->subscribe(PUStateChangedSignal,this);

              puStateList.insert(std::pair<PrimaryUser*, int>(PUModule,OFF));

              // the one who emit the signal should subscribe the signal
           }
        }
#endif
        /*
         *  availability on all channels is set to OFF
         */
        std::cout<<"AllChannelState is set to be OFF" << "\n";
        for(int i=0;i<cc->getNumChannels();i++)
        {
            myRadioRef->AllChannelState[i]=OFF;
        }
        std::cout<<"ChannelAccess:initialize, parentmodule, "<<this->getParentModule()->getParentModule()->getSubmodule("manetrouting",-1)->getFullPath()<<endl;

    }
//    else if (stage==3){
//
//
//    }
}

IChannelControl *ChannelAccess::getChannelControl()
{
    IChannelControl *cc = dynamic_cast<IChannelControl *>(simulation.getModuleByPath("channelControl"));
    if (!cc)
        throw cRuntimeError("Could not find ChannelControl module with name 'channelControl' in the toplevel network.");
    return cc;
}

/**
 * This function has to be called whenever a packet is supposed to be
 * sent to the channel.
 *
 * This function really sends thisInfluencedPUe message away, so if you still want
 * to work with it you should send a duplicate!
 */



void ChannelAccess::sendToChannel(AirFrame *msg)
{
//    coreEV << "sendToChannel: sending to gates\n";
//    if(simTime()>7000)
//    {
//        if(getParentModule()->getParentModule()->getIndex()==40)
//        {
//              msg->setAccPhyTime(0);
//        }
//        msg->setPhyTime(simTime());
//    }

    // delegate it to ChannelControl
   // std::cout<<"ChannelAccess::sendToChannel, channelState: "<<myRadioRef->channelState<<endl;
#ifdef PU_CHA

    IRoutingTable* routingTableNe=check_and_cast<IRoutingTable*>(getParentModule()->getParentModule()->getSubmodule("routingTable"));
    IPv4Address myAddr=routingTableNe->getRouterId();

    int isUDPpkt=0;

        if(myRadioRef->channelState==OFF)
        {
            //std::cout<<"ChannelAccess::sendToChannel, channelState is OFF,"<<endl;
#ifndef BUFFER_WHEN_NEIGHBOUR_IS_ON
            cc->sendToChannel(myRadioRef, msg);

            CHECKBUFFER_INTERVAL=this->getParentModule()->getParentModule()->getSubmodule("manetrouting")->getAncestorPar("ewt").doubleValue();
            std::cout<<this->getParentModule()->getParentModule()->getSubmodule("manetrouting")->getName() << "-Vcap:: ";
            std::cout << this->getParentModule()->getParentModule()->getSubmodule("manetrouting")->getAncestorPar("ewt").doubleValue() <<endl;

            CHECKBUFFER_INTERVAL = (CHECKBUFFER_INTERVAL==0 || CHECKBUFFER_INTERVAL >1) ? 0.1:CHECKBUFFER_INTERVAL;
#ifdef UNIFORMED_CHECKBUFFER_INTERVAL
                        CHECKBUFFER_INTERVAL = 0.1;
#endif
            BUFFER_OUTOFDATE= CHECKBUFFER_INTERVAL*200;
            std::cout<<"ChannelAccess::sendToChannel, checkbuffer interval: "<<CHECKBUFFER_INTERVAL << " on node " << myAddr <<  " at time " << simTime() <<endl;

#endif
#ifdef BUFFER_WHEN_NEIGHBOUR_IS_ON
            //TODO: If the channelState on me is OFF && channelState on receiver is OFF, send out
            // if the receiver is in state ON, do nothing.

            if(simTime() < 7100){
                cc->sendToChannel(myRadioRef, msg);
            }

            if(simTime() > 7100)
            {
                AirFrame *msgdup = msg->dup();
                cc->sendToChannel(myRadioRef, msg);

// if this pkt is udppacket, and the nexthop is ON,then buffer
                std::string packetName = msgdup->getName();
                std::string UDPName ("UDPBasicAppData");
                isUDPpkt = packetName.compare(0, 15, UDPName);  // 0:    They compare equal
                if (!isUDPpkt){

                    bool receiverisOFF = cc->checkNextHop_Channel_State(myRadioRef, msgdup);
                    if(!receiverisOFF)                         // the receiver state is ON on corresponding channel
                    {
                        msgdup->setInbuffer(1);
                        buffer.insert(std::pair<AirFrame*, simtime_t>(msgdup, simTime()));

//                    std::string mode = getParentModule()->getParentModule()->getParentModule()->par("mode");
//                    std::string resultFileName = getParentModule()->getParentModule()->getModuleByRelativePath("manetrouting")->getAncestorPar("resultFileName");
//                    resultFileName+=mode;
//                    resultFileName+="_UDPpktRecord.csv";
//                    const char *resultFileNamechar=resultFileName.c_str();
//                    std::ofstream fileio (resultFileNamechar,std::ios::app);
//                    if(fileio.is_open()){
//                        fileio << msgdup->getName() <<" " <<myAddr.getDByte(3) <<" " << simTime() << endl;
//                        fileio.flush();
//                        fileio.close();
//                        }
//
//                        std::cout << "ChannelAccess.cc::sendToChannel(AirFrame *msg): sents packet "<< msgdup->getName() << " into buffer on " << myAddr <<", buffer.size = " << buffer.size() << endl;


                        if (schedulecounter==0)
                        {
                        CHECKBUFFER_INTERVAL=this->getParentModule()->getParentModule()->getSubmodule("manetrouting")->getAncestorPar("ewt").doubleValue();
                        std::cout<<this->getParentModule()->getParentModule()->getSubmodule("manetrouting")->getName() << "-Vcap:: ";
                        std::cout << this->getParentModule()->getParentModule()->getSubmodule("manetrouting")->getAncestorPar("ewt").doubleValue() <<endl;

                        CHECKBUFFER_INTERVAL = (CHECKBUFFER_INTERVAL==0 || CHECKBUFFER_INTERVAL >1) ? 0.1:CHECKBUFFER_INTERVAL;
//                        BUFFER_OUTOFDATE= CHECKBUFFER_INTERVAL*10;
#ifdef UNIFORMED_CHECKBUFFER_INTERVAL

                        CHECKBUFFER_INTERVAL = 0.1;
#endif
                        BUFFER_OUTOFDATE= CHECKBUFFER_INTERVAL*200;
                        std::cout<<"ChannelAccess::sendToChannel(), checkbuffer interval: "<<CHECKBUFFER_INTERVAL << " on node " << myAddr <<  " at time " << simTime() <<endl;

                        scheduleAt(simTime()+CHECKBUFFER_INTERVAL, CheckBufferMsg);
                    //   std::cout<<"ChannelAccess::sendToChannel,checkbuffer msg scheduled"<<endl;
                        }
                        schedulecounter++;

                    }
                }

                else{
                    delete msgdup;
                }
            }
#endif
        }


        if(myRadioRef->channelState==ON)
        {
            // channel is occupied,  buffer the msg, with buffer time
       // std::cout<<"ChannelAccess::sendToChannel, channelState is ON,"<<endl;
        //myRadioRef->channel=
#ifdef CAVCAPBUFFER
            std::string packetName = msg->getName();
            std::string UDPName ("UDPBasicAppData");
            isUDPpkt = packetName.compare(0, 14, UDPName);
            if (!isUDPpkt){
//                    cancelEvent(CheckBufferMsg);
                msg->setInbuffer(1);
                buffer.insert(std::pair<AirFrame*, simtime_t>(msg,simTime()));
                std::cout << "put " << msg->getName() <<" into buffer at " << simTime() <<", buffer's size on "<< myAddr << " is " << buffer.size() << endl;
                std::cout<<"ChannelAccess::sendToChannel, channelState is ON, put packet "<< msg->getName()  << " into buffer, checkbuffer interval: "<<CHECKBUFFER_INTERVAL<<endl;


            // the first packet is sent to buffer, CheckBufferMsg is generated for once. from now on, the buffer will be checked for every CHECKBUFFER_INTERVAL.
            if (schedulecounter==0)
            {
                CHECKBUFFER_INTERVAL=this->getParentModule()->getParentModule()->getSubmodule("manetrouting")->getAncestorPar("ewt").doubleValue();
            std::cout<<this->getParentModule()->getParentModule()->getSubmodule("manetrouting")->getName() << endl;
            CHECKBUFFER_INTERVAL = (CHECKBUFFER_INTERVAL==0) ? 0.1:CHECKBUFFER_INTERVAL;
#ifdef UNIFORMED_CHECKBUFFER_INTERVAL

                        CHECKBUFFER_INTERVAL = 0.1;
#endif
            BUFFER_OUTOFDATE= CHECKBUFFER_INTERVAL*200;
                std::cout<<"ChannelAccess::sendToChannel(), checkbuffer interval: "<<CHECKBUFFER_INTERVAL << " on node " << myAddr <<  " at time " << simTime() <<endl;
              // CHECKBUFFER_INTERVAL=this->getParentModule()->getParentModule()->getParentModule()->getParentModule()->getSubmodule("pu[0]")->getAncestorPar("timeframe").doubleValue();
               // CHECKBUFFER_INTERVAL*=this->getParentModule()->getAncestorPar("ewtinterval").doubleValue();
              // std::cout<<"ChannelAccess::sendToChannel, checkbuffer interval: "<<CHECKBUFFER_INTERVAL<<endl;
        //std::cout<<"ChannelAccess::sendToChannel, channelState is ON, checkbuffer interval: "<<CHECKBUFFER_INTERVAL<<endl;
                scheduleAt(simTime()+CHECKBUFFER_INTERVAL, CheckBufferMsg);
        //   std::cout<<"ChannelAccess::sendToChannel,checkbuffer msg scheduled"<<endl;
            }
            schedulecounter++;
                }
            else{
                delete msg;
            }
#endif
         }

#endif

#ifndef PU_CHA
    cc->sendToChannel(myRadioRef, msg);
#endif

}

#ifdef CAVCAPBUFFER
void ChannelAccess::displayBuffer()
{   Buffer::iterator bufferit;
    for(bufferit=buffer.begin();bufferit!=buffer.end();bufferit++)
    {
        std::cout<<"ChannelAccess::displayBuffer, airframe id:"<<bufferit->first<<", bufferred time:"<< simTime() - bufferit->second<<endl;
    }
    std::cout<<endl;
}
#endif
void ChannelAccess::receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj)
{  // std::cout<<"ChannelAccess::receiveSignal"<<endl;
    if (signalID == mobilityStateChangedSignal)
    {
        IMobility *mobility = check_and_cast<IMobility*>(obj);
        radioPos = mobility->getCurrentPosition();
        positionUpdateArrived = true;

        if (myRadioRef)
        {
          cc->setRadioPosition(myRadioRef, radioPos);
        }

    }

}
#ifdef PU_CHA

void ChannelAccess::receiveSignal(cComponent *source, simsignal_t signalID, long l)
{  // std::cout<<"ChannelAccess::receiveSignal"<<endl;

#ifndef MULTI_CHA
    if(signalID==PUStateChangedSignal)
    {
      // std::cout<<"ChannelAccess::receiveSignal, PUStateChangedSignal received"<<endl;
       PrimaryUser *srcPU=check_and_cast<PrimaryUser*>(source);
       //so primary user should emit the signal

       if(isInfluencedPU(srcPU))
       {

           //std::cout<<"ChannelAccess::receiveSignal, PUStateChangedSignal, before change channel state:"<< myRadioRef->channelState<<endl;
         //  std::cout<<endl;
         //  std::cout<<"srcPU is :"<<srcPU->getFullName()<<", l is: "<<l<<endl;
           PUStateList::iterator pustatelistit=puStateList.find(srcPU);
           pustatelistit->second=l;

 /*          for(PUStateList::iterator puit=puStateList.begin();puit!=puStateList.end();puit++)
           {
               std::string networkname="Fg80211Net.";
               networkname+=puit->first;
             //  std::cout<<"current fullname of pu:"<<puit->first<<", networkname: "<<networkname<<endl;

              if(srcPU->getFullPath()==networkname)
              {
                puit->second=l;
               // std::cout<<"change in PUState: "<<puit->first<<endl;
              }

           }
*/

           myRadioRef->channelState=OFF;
           for(PUStateList::iterator puit=puStateList.begin();puit!=puStateList.end();puit++)
           {   // std::cout<<"PUState: "<<puit->first<<" : "<<puit->second<<endl;
               if(puit->second==ON&&puit->first->puRef.channel==myRadioRef->channel)
               {//   std::cout<<"channelState set to ON"<<endl;
                   myRadioRef->channelState=ON;
                   return;
                 //
               }
           }



       //    std::cout<<"ChannelAccess::receiveSignal, PUStateChangedSignal change to channelState:"<<myRadioRef->channelState<<"from source: "<< source->getFullName()<<endl;

       }

    }
#endif
#ifdef MULTI_CHA
    if(signalID==PUStateChangedSignal)
    {
        IRoutingTable* RoutingTable = check_and_cast<IRoutingTable*> ( hostModule->getSubmodule("routingTable"));
        IPv4Address myAddr = RoutingTable->getRouterId();
if(myAddr.getDByte(3)==17)
    {
    int seebug=1;
    }
//        std::cout<< myAddr.getDByte(3)<<" Executes ChannelAccess::receiveSignal, PUStateChangedSignal, location is ("<< radioPos.x << ", " << radioPos.y << ")" << endl;

        PrimaryUser *srcPU=check_and_cast<PrimaryUser*>(source);
        //so primary user should have emitted the signal

        if(!isInfluencedPU(srcPU))
        {
            std::cout<<"ChannelAccess::receiveSignal, PUStateChangedSignal, but is not influenced PU"<<endl;
        }
        if(isInfluencedPU(srcPU))
        {
//          std::cout<<"ChannelAccess::receiveSignal, PUStateChangedSignal, pu influences my radio, pu channel: "<<srcPU->puRef.channel<<
//                  ", myRadioRef->channel: "<< myRadioRef->channel<<endl;
//            std::cout<<"ChannelAccess::receiveSignal, srcPU is :"<<srcPU->getFullName()<<", l is: "<<l<<endl;


//            myRadioRef->AllChannelState[srcPU->puRef.channel] = l;

            PUStateList::iterator pustatelistit=puStateList.find(srcPU);
            if(pustatelistit==puStateList.end())// srcPU is not in the list
           {
            // std::cout<<"ChannelAccess::receiveSignal, pu is not in the list , insert."<<endl;
             puStateList.insert(std::pair<PrimaryUser*, int>(srcPU,l));
           }
           else //srcPU is in the list then channel the state of the PU
           {
              // std::cout<<"ChannelAccess::receiveSignal, pu is in the list l: "<<l<<endl;
              pustatelistit->second=l;
           }
        }

          //  myRadioRef->channelState=OFF;
            for(int i=0;i<cc->getNumChannels();i++)
            {
                myRadioRef->AllChannelState[i]=OFF;
            }

            for(PUStateList::iterator puit=puStateList.begin();puit!=puStateList.end();puit++)
            {   // std::cout<<"PUState: "<<puit->first<<" : "<<puit->second<<endl;

                if(puit->second==ON)
                {   //std::cout<<"channelState set to ON"<<endl;
                    myRadioRef->AllChannelState[puit->first->puRef.channel]=ON;
                }

            }

//            int* channelState = myRadioRef->AllChannelState;
//            std::cout<< myAddr.getDByte(3) << "'s channel availability on the two channels is: " << myRadioRef->AllChannelState[0] << ", " <<myRadioRef->AllChannelState[1] << std::endl;
//            std::cout<< &(myRadioRef->AllChannelState) <<" " << channelState<< "\n";
//            std::cout<< myAddr.getDByte(3) << "'s channel availability on the two channels is: " << *channelState <<  ", " << *(channelState+1) << std::endl;
//            std::cout<< &(myRadioRef->AllChannelState) <<" " << channelState<< "\n";
        }

#endif
}


bool ChannelAccess::isInfluencedPU(PrimaryUser* pu)
{   PUlist::iterator listit;
  //  std::cout<<"ChannelAccess::isInfluencedPU"<<endl;
    for(listit=myRadioRef->influencePUlist.begin();listit!=myRadioRef->influencePUlist.end();listit++)
    {

        if(pu->puRef.puPosition==listit->puPosition)
       {
//            std::cout<<"ChannelAccess::isInfluencedPU, return true,"<<listit->puPosition<<endl;

              return true;
       }

    }
  //  std::cout<<"ChannelAccess::isInfluencedPU, return false"<<endl;
    return false;
}
#endif

