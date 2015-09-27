//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "PrimaryUser.h"
#include "ChannelControl.h"
#ifdef PU_CHA

Define_Module(PrimaryUser)

static int parseInt(const char *s, int defaultValue)
{
    if (!s || !*s)
        return defaultValue;

    char *endptr;
    int value = strtol(s, &endptr, 10);
    return *endptr == '\0' ? value : defaultValue;
}

PrimaryUser::PrimaryUser() {
    // TODO Auto-generated constructor stub

}

PrimaryUser::~PrimaryUser()
{
    // TODO Auto-generated destructor stub
}

void PrimaryUser::initialize(int stage){


   if(stage==0){
        IChannelControl *ccglobal=getGlobalChannelControl();
        puRef.puRange=par("puRange");
      //  puRef.meantimeON=par("meanTimeON");
      //  puRef.meantimeOFF=par("meanTimeOFF");
        puRef.PUstatus=parseInt(par("PUstatus"),0);
        //get the position from the display tag


    //    Coord currPos=check_and_cast<IMobility*>(getSubmodule("mobility"))->getCurrentPosition();

        puRef.puPosition.x=par("positionX");
        puRef.puPosition.y = par("positionY");
        puRef.puPosition.z=0;//two demension coord

        puRef.channel=par("Channel"); //channel index
        //add this new PU to global channel control
        puRef.transitionM[0]=par("pOFFOFF");
        puRef.transitionM[1]=par("pONON");
        puRef.timeframe=par("timeframe");

        puRef.channel=par("Channel");
        ONtimeout=new cMessage();
        OFFtimeout=new cMessage();
        randomnumberger=getRNG(0);

      //  std::cout<<"PrimaryUser::initialize, "<< endl;
        ccglobal->addPU(&puRef);

        timeframe=par("timeframe");

    //  ccglobal->addPU(this);
    }
}

void PrimaryUser::receiveSignal (cComponent *source, simsignal_t signalID, long l)
{    Enter_Method_Silent();
//    if(signalID==SEARCH::PUStartSignal) //change from VCap::PUStartSignal to SEARCH::PUStartSignal
    if(signalID==VCap::PUStartSignal) //change from VCap::PUStartSignal to SEARCH::PUStartSignal
     {   int newstate=dtm(OFF);
         std::cout<<puRef.puPosition<<", PrimaryUser::receiveSignal, PUStartSignal received"<<endl;
         cancelEvent(OFFtimeout);
         cancelEvent(ONtimeout);
         if(newstate==ON)//if new state is ON then
         {
             puRef.PUstatus=ON;
             emit(ChannelAccess::PUStateChangedSignal,ON);
            // std::cout<<"PrimaryUser::receiveSignal, new state is ON"<<endl;
             scheduleAt(simTime()+timeframe, ONtimeout);
             return;
         }
         if(newstate==OFF)
         {
             puRef.PUstatus=OFF;
            // std::cout<<"PrimaryUser::receiveSignal, new state is OFF"<<endl;
             scheduleAt(simTime()+timeframe, OFFtimeout);
             return;
         }
     }
     //test whether SEARCH::PUStartSignal is received.
//     if(signalID == SEARCH::PUStartSignal)
//         {
//         int receivePUStartSignal=1;
//         }
}
void PrimaryUser::handleMessage(cMessage* msg)
{    //std::cout<<puRef.puPosition<<", PrimaryUser::handleMessage. "<<endl;
#ifdef CTM
    //receive a self msg, geton or getoff timeout, CTM should change state according to the transition matrix
    if (msg==ONtimeout){
        puRef.PUstatus=ctm(ON);
        if(puRef.PUstatus==ON)
        {
            SimTime staytime=getOnDuration();
            scheduleAt(simTime()+staytime, ONtimeout);
        }
        else if(puRef.PUstatus==OFF)
        {
             SimTime staytime=getOffDuration();
             scheduleAt(simTime()+staytime, OFFtimeout);
         }
    }
    if(msg==OFFtimeout)
    {   puRef.PUstatus=ctm(OFF);
        if(puRef.PUstatus==ON)
        {
           SimTime staytime=getOnDuration();
           scheduleAt(simTime()+staytime, ONtimeout);
        }
        else if(puRef.PUstatus==OFF)
        {
           SimTime staytime=getOffDuration();
           scheduleAt(simTime()+staytime, OFFtimeout);
        }

    }
#endif


    if (msg==ONtimeout)
    {       cancelEvent(OFFtimeout);
            cancelEvent(ONtimeout);

            int newstate=dtm(ON);//last status is ON

            if(newstate==ON)
            {
                puRef.PUstatus=newstate;
                scheduleAt(simTime()+timeframe, ONtimeout);
                //std::cout<<puRef.puPosition<<", PrimaryUser::handleMessage, last state is ON , new state is ON"<<endl;
            }
            else if(newstate==OFF)
            {
                puRef.PUstatus=newstate;
                scheduleAt(simTime()+timeframe, OFFtimeout);
              //   std::cout<<puRef.puPosition<<", PrimaryUser::handleMessage, last state is ON , new state is OFF"<<endl;
                 //PU status changed, emit PUstateChange signal
                emit(ChannelAccess::PUStateChangedSignal, OFF);
                 //std::cout<<puRef.puPosition<<", PrimaryUser::handleMessage, emit PUStateChangedSignal \n";
            }
     }
    if(msg==OFFtimeout)
    {       cancelEvent(ONtimeout);
            cancelEvent(OFFtimeout);
            int newstate=dtm(OFF);
            if(newstate==ON)
            {
                puRef.PUstatus=newstate;
                scheduleAt(simTime()+timeframe, ONtimeout);
          //     std::cout<<puRef.puPosition<<", PrimaryUser::handleMessage, last state is OFF , new state is ON"<<endl;
               //PU status changed, emit PUstateChange signal
                emit(ChannelAccess::PUStateChangedSignal,ON);
                //std::cout<<puRef.puPosition<<", PrimaryUser::handleMessage, emit PUStateChangedSignal \n";
            }
            else if(newstate==OFF)
            {
                puRef.PUstatus=newstate;
               // std::cout<<puRef.puPosition<<", PrimaryUser::handleMessage, last state is OFF , new state is OFF"<<endl;
                scheduleAt(simTime()+timeframe, OFFtimeout);
            }

     }



}

int PrimaryUser::dtm(int lastStatus)
{  double pOFFOFF=puRef.transitionM[0];
   double pONON=puRef.transitionM[1];
  // std::cout<<puRef.puPosition<<", PrimaryUser::dtm, pOFFOFF: "<<pOFFOFF<<", pONON: "<<pONON<<endl;

   if(lastStatus==ON)
   {
       //int randno=randomnumberger->intRand(100);
       int randno=rand()% 100 + 1;
       //std::cout<<puRef.puPosition<<", PrimaryUser::dtm, lastStatus ON, randno: "<<randno<<", pONON*100:"<<pONON*100<<endl;
       if (randno>=(pONON*100))
       {
           return OFF;
       }
       else
           return ON;

   }
   if(lastStatus==OFF)
   {
       //int randno=randomnumberger->intRand(100);
        int randno=rand() % 100 + 1;
  //     std::cout<<puRef.puPosition<<", PrimaryUser::dtm, lastStatus OFF, randno: "<<randno<<", pOFFOFF*100: "<<pOFFOFF*100<<endl;
       if (randno>=(pOFFOFF*100))
       {
         return ON;
       }
       else
         return OFF;
   }
   std::cout<<"dtm error, return default off"<<endl;
   return OFF;

}


#ifdef CTM
int PrimaryUser::ctm()
{

}
#endif
IChannelControl* PrimaryUser::getGlobalChannelControl(){
    IChannelControl *ccglobal = dynamic_cast<ChannelControl*>(simulation.getModuleByPath("channelControl"));
    if (!ccglobal)
               throw cRuntimeError("Could not find ChannelControl module with name 'channelControl' in the toplevel network.");
           return ccglobal;
}


void PrimaryUser::setChannel(int newchannel)
{
    puRef.channel=newchannel;

}

#endif

