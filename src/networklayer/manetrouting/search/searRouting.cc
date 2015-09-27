// System includes:

// OMNET includes:

// INET includes:
#include "Coord.h"
#include "IMobility.h"
#include "IPv4Datagram.h"
#include "IPv4ControlInfo.h"
#include "ControlManetRouting_m.h"

#include <iostream>
#include <fstream>
// SEARCH includes:
#include "searRouting.h"
#include "Radio.h"
#include <math.h>
#include <cmath>        // std::abs

Define_Module(SEARCH);
simsignal_t SEARCH::PUStartSignal = SIMSIGNAL_NULL;
#define INITIAL_DISTANCE 1000;

SEARCH::posTable_t SEARCH::posTable;
Coord dstPos;

// how to find IP of the dst from .ini file
//IPv4Address dstAddr("168.192.0.2");

IPv4Address srcAddr, dstAddr;
int updateInterval; // retransmit rreq after time of updateInterval
int workingChannelIndex =0; // the index the the routing path on channel of channelIndex
int sentUDPPakcets =0;
int arrivedRreqrNum =0;
int arrivedUDPNum =0;
Record_numHops lsit_numberHops;

SEARCH::SEARCH()
{
    // TODO Auto-generated constructor stub
}

SEARCH::~SEARCH()
{
    // TODO Auto-generated destructor stub
}


void SEARCH::initialize(int stage)
{
	if(stage==4)
	    {
	    registerRoutingModule();
		registerPosition(); // We register for position information, but unfortunately we will not get up-to-date information before the first update

		// Determine position and IP:
		IRoutingTable* routingTable=check_and_cast<IRoutingTable*>(getParentModule()->getSubmodule("routingTable"));
		myAddr=routingTable->getRouterId();
		std::cout << "SEARCH: My (" << myAddr << ") position: (" << getXPos() << "," << getYPos() << ")" << endl;

		/*
		 * fine out src and destination from .ini   //todo: I am not sure the correctness.
		 */
		IRoutingTable* srcRoutingTable=check_and_cast<IRoutingTable*>(getParentModule()->getParentModule()->getModuleByRelativePath("fixhost[40]")->getSubmodule("routingTable"));
		srcAddr = srcRoutingTable->getRouterId();

        IRoutingTable* dstRoutingTable=check_and_cast<IRoutingTable*>(getParentModule()->getParentModule()->getModuleByRelativePath("fixhost[12]")->getSubmodule("routingTable"));
        dstAddr = dstRoutingTable->getRouterId();
        dstPos.x =posTable[dstAddr].x;
        dstPos.y = posTable[dstAddr].y;

        par("IPstring").setStringValue(myAddr.str()); //"IPstring" is the current IP

//        dstPos(posTable[dstAddr].x, posTable[dstAddr].y);
//		IPv4Address dstAddr = getParentModule()->getParentModule()->getModuleByRelativePath(".udpApp[12]")->getFullPath();


	      /*  int numNode=getParentModule()->getParentModule()->par("numFixHosts").longValue();
	        int srcid=getParentModule()->getParentModule()->par("srcid").longValue();
	        int destid=getParentModule()->getParentModule()->par("destid").longValue();
	        std::cout<< "SEARCH: "<<getParentModule()->getFullPath().c_str()<<endl;
	        std::cout<< "SEARCH: "<<srcid<<";"<<destid<<endl;
	        if (srcid==getParentModule()->getIndex())
	        {
	            std::cout<< "SEARCH: "<<getParentModule()->getParentModule()->getModuleByRelativePath(".udpApp[0]")->getFullPath();
	           //getParentModule()->getSubmodule("udpApp[0]")->par("startTime").setLongValue(7100);


	            cTopology* topo=new cTopology;
	            topo->extractByParameter("IPstring");
	            std::cout<< "SEARCH: "<< topo->getNode(destid)->getModule()->getFullPath()<<endl;
	        }*/

		/*
		 * PU
		 */
        PUStartSignal=registerSignal("puStartSignal");
        //FIXME only two PUModule is subscribed
        int PUno=getParentModule()->getParentModule()->par("numPU");
        std::cout<< "SEARCH: "<<"No of PU: "<<PUno<<endl;
        for(int i=0;i<PUno;i++)
        {   std::string puname="pu[";
        std::stringstream ss;
        ss << i;
        std::string stringi = ss.str();
        puname.append(stringi);
        puname.append("]");
        //  std::cout<< "SEARCH: "<<myaddr<<", ini, current PU: "<<getParentModule()->getParentModule()->getModuleByRelativePath(puname.c_str())->getFullPath()<<endl;
        PrimaryUser* PUModule;
        PUModule=check_and_cast<PrimaryUser*>(getParentModule()->getParentModule()->getModuleByRelativePath(puname.c_str()));
        subscribe(PUStartSignal,PUModule);
       // std::cout<< "SEARCH: "<<"subscribed"<<endl;
        }

        Radio * myRadio=check_and_cast<Radio*>(getParentModule()->getModuleByRelativePath(".wlan[0].radio"));

        PUlist::iterator pulistit;

        for (pulistit=myRadio->myRadioRef->influencePUlist.begin();pulistit!=myRadio->myRadioRef->influencePUlist.end();pulistit++)
        {
            DTMMatrix tranmatrix;
            tranmatrix.resize(2,2);
            tranmatrix(0,0)=pulistit->transitionM[0];
            tranmatrix(0,1)=1-pulistit->transitionM[0];
            tranmatrix(1,0)=1-pulistit->transitionM[1];
            tranmatrix(1,1)=pulistit->transitionM[1];

            PUMatrixPositionCH puMatrixPositionCh;
            puMatrixPositionCh.dtmmatrix=tranmatrix;
            puMatrixPositionCh.position=pulistit->puPosition;
            puMatrixPositionCh.channel=pulistit->channel;

            puList.push_back(puMatrixPositionCh);
            std::cout<< "SEARCH: "<<myAddr<<":: ini, time frame: "<<pulistit->timeframe<<endl;
            puTimeframe.insert(std::pair<Coord,double>(puMatrixPositionCh.position,pulistit->timeframe));
        }



		// Broadcast position information to neighbors:
		searNeighborInfo* bni=new searNeighborInfo();
		bni->setRouterAddress(myAddr);
		bni->setRouterXPos(getXPos()); //record the current position
		bni->setRouterYPos(getYPos());
		bni->setWorkingChannel(0);
		doLocalBroadcast(bni);
//        cMessage *beaconing = new cMessage("beaconing");
//        scheduleAt(0.85, beaconing);

		/*
		 * routing request on two channels sequentially, the source broadcast labels different routingRreqs.
		 */
		if (myAddr.equals(srcAddr))
            {
            cMessage *routingRreqCh0 = new cMessage("routingRreqCh0");
            scheduleAt(7095, routingRreqCh0);

#ifndef ONLY_USE_CHANNEL_0
            cMessage *routingRreqCh1 = new cMessage("routingRreqCh1");
            scheduleAt(7095, routingRreqCh1);
#endif
            }

		cMessage *PUstart = new cMessage("PUstart");
		scheduleAt(7090, PUstart);

		updateInterval = par("updateInterval");
	    }

    numNodes=this->getParentModule()->getParentModule()->par("numFixHosts");


}

void SEARCH::doLocalBroadcast(cPacket *pk)
    {
	IPv4Datagram* p=new IPv4Datagram();
	p->setSrcAddress(myAddr);
	p->setDestAddress(IPv4Address::ALLONES_ADDRESS); // Di: broadcast to all?
	p->setTimeToLive(1);
	p->setTransportProtocol(IP_PROT_MANET);
    p->setName("BNIPacket");
	IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
	ipControlInfo->setProtocol(IP_PROT_MANET);
	ipControlInfo->setSrcAddr(myAddr);
	ipControlInfo->setDestAddr(IPv4Address::ALLONES_ADDRESS);
	ipControlInfo->setTimeToLive(1);
	p->setControlInfo(ipControlInfo);
	p->encapsulate(pk); //pk, here is of searNeighborInfo, is encapsulated in a IPv4Datagram pointed by 'p'.
	float delay=exponential(10e-3);
	sendDelayed(p,delay,"to_ip"); //message 'p' is broadcasted, which contains the IP address of the sender, low tx power.
    }

void SEARCH::handleMessage(cMessage *msg) //class SIM_API cPacket : public cMessage
{
	if(searNeighborInfo* bni=dynamic_cast<searNeighborInfo*>(msg))
	    {
		const IPv4Address neighborAddr=bni->getRouterAddress();
//	    if(neighborAddr.getDByte(3)==2)
//	    {int stop2check=1;}
		/*
		 *  from myself
		 */
		if(neighborAddr == myAddr)
		    {
			ev << "SEARCH: Discarding neighbor info from myself" << endl;
			delete bni;
			return;
		    }

		nh_t::const_iterator it=neighborhood.find(neighborAddr);//      typedef std::tr1::unordered_map<IPv4Address,searNeighborInfo*,hashIPv4Address> nh_t;

        /*
         *  this neighbor is not in neighborhood yet
         */
        if(it==neighborhood.end())
            {
            neighborhood[neighborAddr]=bni;
//            std::cout<< "SEARCH: " << neighborhood;
            return;
            }

        /*
         *  if Entry exists and the searNeighborInfo* is the same, don't do anything, delete the bni msg
         */
        if(it!=neighborhood.end() && equal(*(*it).second,*bni))
            {
            std::cout<< "SEARCH: " << "BERGER: Entry already exists, discarding" << "\n";
            delete bni;
            return;
            }

        /*
         *  if Entry exists but the searNeighborInfo* is different from the coming bni, update
         */
        if(it!=neighborhood.end())
            {
            // delete old entry, insert new entry:
            delete (*it).second;
            neighborhood[neighborAddr]=bni;
            // display IP along the icon, fails
            if (ev.isGUI())
                {
                char ip[40];
                sprintf(ip, "ip: %s", myAddr.str().c_str());
                getDisplayString().setTagArg("t", 0, ip);
                }
            return;
            }
        return;
        }


    /*
     * src receives selfmsgs, to generate routing request
     */
    if (msg->isSelfMessage() && (!strcmp(msg->getName(), "routingRreqCh0")|| !strcmp(msg->getName(), "routingRreqCh1")))
        {
        /*
         * retransmit rreq after time of updateInterval
         */
        cMessage *routingRreqCh_newMsg = new cMessage(msg->getName());
        scheduleAt(simTime() + updateInterval, routingRreqCh_newMsg);
            /*
             * print out channel states of all secondary users, 0, 1 denotes PU's state
             */

            cTopology *topo=new cTopology;
            topo->extractByParameter("IPstring");
            for(int i=0; i<topo->getNumNodes(); i++)
                {
                std::string ipstring = topo->getNode(i)->getModule()->getAncestorPar("IPstring").info();
                Radio* radio=check_and_cast<Radio*>(topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("wlan[0].radio"));
                ChannelNumberState channelNumberState(radio->myRadioRef->channel, radio->myRadioRef->AllChannelState);
                int* channelState = channelNumberState.second;
#ifdef MULTI_CHA
                std::cout << ipstring << "current working channel: " << channelNumberState.first <<", the state of the two channels: "<< *channelState << ", " <<*(channelState+1) << "\n";
#endif
#ifndef MULTI_CHA
                std::cout << ipstring << "current working channel (index): " << channelNumberState.first <<", the state of channel: "<< radio->myRadioRef->channelState << "\n";
#endif
                }

        // for src node
        if((msg->isSelfMessage() && !strcmp(msg->getName(), "routingRreqCh0")))
        {  IamSrc=1;
            workingChannel = 0;
            std::cout << "receive routingRreqCh0 at " << simTime() << " s\n";
        }
        if((msg->isSelfMessage() && !strcmp(msg->getName(), "routingRreqCh1")))
        {  IamSrc=1;
        workingChannel = 1;
        std::cout << myAddr.getDByte(3) << " receives routingRreqCh1 at " << simTime() << "\n";
        }

        std::cout<< "SEARCH: " << myAddr.getDByte(3)<< " starts to find path on channel " << workingChannel << " to destination: " << dstPos.x << "," << dstPos.y << "\n";

        /*
         * find nextHop
         */
            focusOnChannel.clear();
            DP = checkFocusArea();
            chosenNodes.clear();
            deadEnds.clear();

        PathList pathlist; // for the following line
        nextForward = decideNextHop(pathlist);
        NextHop_ch[workingChannel] = nextForward;
        std::cout<< "SEARCH: "<< myAddr.getDByte(3) <<"'s nexthop on channel "<<workingChannel <<" is "<< nextForward.getDByte(3) << "\n";


        /*
         * generate rreq on src
         */
        SearRouteRequest* rreq = new SearRouteRequest();
        PathList currentPathList;
        PathList currentDPList;
       currentPathList.push_back(myAddr);
       if(DP)
           {currentDPList.push_back(myAddr);}
       rreq->setSrc(myAddr);
       rreq->setDst(dstAddr);
       rreq->setWorkingChannel(workingChannel);
       rreq->setDPList(currentDPList);
       rreq->setPathList(currentPathList);

#ifdef MULTI_CHA
       emit(Radio::ChannelDecisionSignal, nextForward.str().c_str());
#endif

       /*
        * send out the initial rreq
        */
        IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
        ipControlInfo->setNextHopAddr(nextForward);
        ipControlInfo->setProtocol(IP_PROT_VCap);
        ipControlInfo->setSrcAddr(rreq->getSrc()); //record the original src's address
        ipControlInfo->setDestAddr(dstAddr);
        ipControlInfo->setTimeToLive(1);

        //rreq is a packet, should be encapsulated in an IPv4Datagram
       IPv4Datagram * newdatagram= new IPv4Datagram();
       newdatagram->setSrcAddress(rreq->getSrc());
       newdatagram->setDestAddress(dstAddr);
       newdatagram->setTransportProtocol(IP_PROT_VCap);
       newdatagram->encapsulate(rreq);
       newdatagram->setControlInfo(ipControlInfo);
       char* rreqName;
       if(!workingChannel)
           {
               rreqName = "rreqmsg_ch0";
           }
       else
           {
               rreqName = "rreqmsg_ch1";
           }
       newdatagram->setName(rreqName);
       newdatagram->setTimeToLive(1);
       send(newdatagram, "to_ip");
       }


	/*
	 * Intermediate nodes, deal with rreq/UDP packets,
	 */
	 if(ControlManetRouting* control=dynamic_cast<ControlManetRouting*>(msg))
        {
        std::cout<< "SEARCH: " << myAddr.getDByte(3) << " receives message " <<control->getName() <<" at "<< simTime()<<"s, routing Option is " << control->getOptionCode() << "\n";

        if ((control->getOptionCode() == MANET_ROUTE_NOROUTE))//    MANET_ROUTE_NOROUTE = 2
            {
//            if(myAddr.getDByte(3)==14)
//                {
//                int im14=1;
//                }
            IPv4Datagram *datagram= dynamic_cast<IPv4Datagram*>(control->decapsulate());
            datagram->removeControlInfo();

            /*
             *   Is contained datagram rreq?
             */
            int receive_rreqmsg_test=0;
            std::string rreqName("rreqmsg_ch");
            std::string packetName = datagram->getName();
            if (!packetName.compare(0, 10, rreqName))
                {
                receive_rreqmsg_test=1;
                }
            if(receive_rreqmsg_test)
                {
                std::cout<< "SEARCH: " << myAddr.getDByte(3) << " gets " << datagram->getName() << " on channel " << workingChannel << " at "<< simTime() << "\n";
                SearRouteRequest* rreq = dynamic_cast<SearRouteRequest*>(datagram->decapsulate());

                /*
                 * Find nextHop to forward rreq
                 */
                if(myAddr.getDByte(3)!=numNodes) //current node is not dst. value of numNodes equals to the last bit of destination IP
                    {
//                    if(myAddr.getDByte(3)==8)
//                       {
//                       int stopat5=1;
//                       }
                    workingChannel =  rreq->getWorkingChannel();

                        focusOnChannel.clear();
                    DP = checkFocusArea();
                        chosenNodes.clear();
                        deadEnds.clear();
                    nextForward = decideNextHop(rreq->getPathList());
                    NextHop_ch[workingChannel] = nextForward;
//if(nextForward.equals(IPv4Address::UNSPECIFIED_ADDRESS))
//    {
//    int stophere =1;
//    return;
//    }
                    std::cout<< "SEARCH: "<< myAddr.getDByte(3) <<"'s next hop on channel " << workingChannel<< " is "<< nextForward.getDByte(3) << "\n";

//                    PathList currentPathList;
//                    PathList currentDPList;
//
//                    currentPathList = rreq->getPathList();
//                    currentPathList.push_back(myAddr);
                    rreq->getPathList().push_back(myAddr);

                    PathList middileList;
                    middileList=rreq->getDPList();
                    if(DP)
                    {
                        middileList.push_back(myAddr);
                    }
                    rreq->setDPList(middileList);
                    rreq->setSrc(myAddr);
                    rreq->setDst(dstAddr);
                    rreq->setWorkingChannel(workingChannel);
//                    rreq->setDPList(currentDPList);
//                    rreq->setPathList(currentPathList);

                    /*
                    * send out rreq
                    */
#ifdef MULTI_CHA
                    emit(Radio::ChannelDecisionSignal, nextForward.str().c_str());
#endif
                    IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
                    ipControlInfo->setNextHopAddr(nextForward);
                    ipControlInfo->setProtocol(IP_PROT_VCap);
                    ipControlInfo->setSrcAddr(rreq->getSrc()); //record the original src's address
                    ipControlInfo->setDestAddr(dstAddr);
                    ipControlInfo->setTimeToLive(1);

                    //rreq is a packet, should be encapsulated in an IPv4Datagram
                    IPv4Datagram * newdatagram= new IPv4Datagram();
                    newdatagram->setSrcAddress(rreq->getSrc());
                    newdatagram->setDestAddress(dstAddr);
                    newdatagram->setTransportProtocol(IP_PROT_VCap);
                    newdatagram->encapsulate(rreq);
                    newdatagram->setControlInfo(ipControlInfo);
                    char* rreqName;
                    if(!workingChannel)
                    {
                    rreqName = "rreqmsg_ch0";
                    }else
                    {
                    rreqName = "rreqmsg_ch1";
                    }
                    newdatagram->setName(rreqName);
                    newdatagram->setTimeToLive(1);
                    send(newdatagram, "to_ip");

                    std::cout<< "SEARCH: " << myAddr.getDByte(3) << " receives " << datagram->getName() << " on channel " << workingChannel << " at "<< simTime() << ", and will forward it to " << nextForward.getDByte(3)<< "\n";
                    }
                } //rreq


            else    //UDP, the next hop will be decided by the destination! TODO
                {
                std::cout<< "SEARCH: sent UPD packets to next hop: " << nextForward.getDByte(3) << " at time " << simTime() << "\n";
if(nextForward.equals(IPv4Address::UNSPECIFIED_ADDRESS))
    {
    int stophere =1;
    return;
    }

#ifdef MULTI_CHA
                emit(Radio::ChannelDecisionSignal, nextForward.str().c_str()); //NOTIFY radio.cc
#endif
                IPv4ControlInfo *controlInfo=new IPv4ControlInfo();
                controlInfo->setNextHopAddr(nextForward);
                controlInfo->setProtocol(IP_PROT_VCap);
                controlInfo->setSrcAddr(datagram->getSrcAddress());
                controlInfo->setDestAddr(datagram->getDestAddress());

                IPv4Datagram * newdatagram= datagram->dup();
                newdatagram->setControlInfo(controlInfo);
                newdatagram->setTransportProtocol(IP_PROT_VCap);

                send(newdatagram, "to_ip");

                std::cout<< "SEARCH: " << "nexthop is "<< nextForward.getDByte(3)<< ", Destination "<< dstAddr.getDByte(3)<<"'s location: " << posTable[dstAddr].x << "," << posTable[dstAddr].y << "\n";
                }
//                rt = RoutingTableAccess().get();
            }
        } //Intermediate nodes, deal with rreq/UDP packets

	 /*
	  *   receive rreq and UDP on destination,
	  *   count;
	  *   set the next hop for src and intermediate nodes
	  */
	 if(msgToRoute* msgFromIPv4=dynamic_cast<msgToRoute*>(msg))
	     {
//	     printAllNeighbors();
         IPv4Datagram *datagram= dynamic_cast<IPv4Datagram*>(msgFromIPv4->decapsulate());
         datagram->removeControlInfo();

	     if(SearRouteRequest* rreq = dynamic_cast<SearRouteRequest*>(datagram->decapsulate()))
	         {
	         int firstRreq=0;
	         int secondRreq=0;
	         PathList pathCh0;
	         PathList pathCh1;
	         PathList pathFinal;
	         std::cout << "The received rreq works on channel " << rreq->getWorkingChannel()<< " \n";
	         arrivedRreqrNum++;
	         if(!rreq->getWorkingChannel())  //rreq on channel 0 arrives
                 {
	             std::cout << "rreqmsg_ch0 reaches dst, PathList contains: " << rreq->getPathList();
	             std::cout << "DPList contains: " << rreq->getDPList() << "\n";
	             firstRreq = 1;
	             pathCh0 = rreq->getPathList();
                 }
#ifndef MULTI_CHA
	         lsit_numberHops.push_back(pathCh0.size());
#endif

#ifdef MULTI_CHA
	         else
	             {
                std::cout << "rreqmsg_ch1 reaches dst, PathList contains: " << rreq->getPathList();
                std::cout << "DPList contains: " << rreq->getDPList() << "\n";
                secondRreq = 1;
                pathCh1 = rreq->getPathList();
	             }
	         if(firstRreq && secondRreq) // receives two rreqs, which means paths are found on both channels.
	              {
	                 if(pathCh0.size() == pathCh1.size())
	                     {
	                     // leave this alone..nextForward is set to work on channel 1 (the last used channel)
	                     }
	                 else
	                     {
	                     pathFinal = pathCh0.size()<pathCh1.size()? pathCh0: pathCh1;
	                     }
	              }
	          if(firstRreq && !secondRreq) // rreq arrives on channel 0
	              {
	              pathFinal = pathCh0;
	              std::cout << "use channel 0" << "\n";
	              }
            if(!firstRreq && secondRreq) // rreq arrives on channel 1
                  {
                    pathFinal = pathCh1;
                    std::cout << "use channel 1" << "\n";
                  }
            lsit_numberHops.push_back(pathFinal.size());


            /*
             * pathFinal:
             * set the nextFoward according to pathFinal
             */
            cTopology *topo=new cTopology;
            topo->extractByParameter("IPstring");
            for(int i=0; i<topo->getNumNodes(); i++)
                {
                //+++ i->ip
                std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info();
                std::string newcurrentipstring;
                for(unsigned int j = 0; currentipstring[j] != '\0'; j++)
                    {
                    if(currentipstring[j]=='\"')
                        {
                        continue;
                        }
                    newcurrentipstring+=currentipstring[j];
                    }
                //    std::cout<<myaddr<<", handleMessage, new current ip as string  :"<<newcurrentipstring<<endl;
                IPv4Address currentip;
                currentip.set(newcurrentipstring.c_str());
                //+++ i->ip

                if(currentip == srcAddr)
                  {
                    SEARCH* SEARCHmodule =check_and_cast<SEARCH*>(topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("manetrouting"));
                    SEARCHmodule->nextForward = pathFinal.front();
                  }

                if(currentip == pathFinal.back())
                  {
                    SEARCH* SEARCHmodule =check_and_cast<SEARCH*>(topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("manetrouting"));
                    SEARCHmodule->nextForward = dstAddr;
                  }

                for(PathList::iterator it=pathFinal.begin(); it!=pathFinal.end(); it++)
                    {
                    if(currentip == *it && !(currentip == pathFinal.back()))
                      {
                        SEARCH* SEARCHmodule =check_and_cast<SEARCH*>(topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("manetrouting"));
                        it++;
                        SEARCHmodule->nextForward = *it;
                        it--;
                      }
                    }
                }
#endif
	         }

	     else
	         {
//	         std::cout << "see me " << datagram->getName()<<"\n";
	         arrivedUDPNum++;
	         }
	     }



    //start to send beacon:
    if ( msg->isSelfMessage() )
        {
        if(!strcmp(msg->getName(), "beaconing"))
            {
            ev << "It is time to update my neighborhood!" << endl;
            neighborhoodBackup.clear();

            searNeighborInfo* selfBni = new searNeighborInfo();
            selfBni->setRouterAddress(myAddr);
            selfBni->setRouterXPos(getXPos());
            selfBni->setRouterYPos(getYPos());
            doLocalBroadcast(selfBni);

            cMessage* beaconing = new cMessage("beaconing");
            scheduleAt(simTime()+ 0.5, beaconing);   // send beacon 1s later

            cMessage* updateNh = new cMessage("updateNh");
            scheduleAt(simTime()+ 0.1, updateNh);   // update neighborhood 0.1s later
            time_updateNh = simTime()+ 0.1;
            delete msg;
            return;
            }

        //PUs start working
        if(!strcmp(msg->getName(), "PUstart"))
            {
#ifdef PU_ON
            emit(SEARCH::PUStartSignal,1);
#endif
            }
        else
            {
            printf("%d's neighbors:\n", myAddr.getDByte(3));
            std::cout<< "SEARCH: my neighbors are: " << neighborhood;
//            neighborhood = neighborhoodBackup;
//            std::cout<< "SEARCH: " << neighborhood;

//            printf("%s has updated its neighborhood at %f\n\n", myAddr.str().c_str(), simTime().dbl());
            delete msg;
            return;
            }
        }
    }


/*
 *  find the next hop
 */
IPv4Address SEARCH::decideNextHop(PathList& pathlist)
    {
    IPv4Address nexthop;
    IPv4Address nexthop_SameWorkingChannel;
    double distance = INITIAL_DISTANCE;

//    if(myAddr.getDByte(3)==21)
//        {
//        int hi=1;
//        }

    nh_t::const_iterator it=neighborhood.find(dstAddr);
    if(it!=neighborhood.end())
        {
        nexthop = dstAddr;
        return nexthop;
        }// if dst is within its nh, then set dst as nexthop

    if (!focusOnChannel[workingChannel].first.size()) // no co-channel nodes in the focus area
        {
        std::cout<< "SEARCH: coCHnodesInFocus has no nodes, coCHnodesOutFocus has: " << focusOnChannel[workingChannel].second;
            //find the nexthop out of focus area
            for(PathList::const_iterator lIt=focusOnChannel[workingChannel].second.begin(); lIt!=focusOnChannel[workingChannel].second.end(); ++lIt)
            {
            Coord nbPos(neighborhood[*lIt]->getRouterXPos(), neighborhood[*lIt]->getRouterYPos());
            if(nbPos.distance(dstPos) < distance)
                {
                distance = nbPos.distance(dstPos); //new smaller distance
//                bool inList = InList(*lIt, pathlist);
                if(deadEnds.find(*lIt) == deadEnds.end() )//&& !inList)
                    {
                    nexthop_SameWorkingChannel = *lIt;
                    }//the chosen node is not dead end, at least now.
                }
            }
            if(chosenNodes.find(nexthop_SameWorkingChannel) == chosenNodes.end())
                {
                chosenNodes.insert(nexthop_SameWorkingChannel);
                }// This node is not chosen before
                else
                {
                deadEnds.insert(nexthop_SameWorkingChannel);
                }// has been chosen before, so put it in deadEnds

            //choose the node closest to dst.
            nexthop = nexthop_SameWorkingChannel;
        }//current node is DP
    else
        {
        //find the nexthop in focus area
        std::cout<< "SEARCH: the size of co-channel nodes in focus area is:"<< focusOnChannel[workingChannel].first.size()<<": "<<focusOnChannel[workingChannel].first<<"\n";
        for(PathList::const_iterator lIt=focusOnChannel[workingChannel].first.begin(); lIt!=focusOnChannel[workingChannel].first.end(); ++lIt)
            {
            Coord nbPos(neighborhood[*lIt]->getRouterXPos(), neighborhood[*lIt]->getRouterYPos());
            if(nbPos.distance(dstPos) < distance)
                {
                distance = nbPos.distance(dstPos); //new smaller distance
//                bool inList = InList(*lIt, pathlist);
                if(deadEnds.find(*lIt) == deadEnds.end())// && !inList)
                    {
                    // This node is not chosen before
                    nexthop_SameWorkingChannel = *lIt;
                    }//This node is not in deadEnds
                }
            }
        if(chosenNodes.find(nexthop_SameWorkingChannel)==chosenNodes.end())
            {
            chosenNodes.insert(nexthop_SameWorkingChannel);
            } // This node is not in chosenNodes
            else
            {
            deadEnds.insert(nexthop_SameWorkingChannel);
            } // has been chosen before, so put it in deadEnds
        nexthop =nexthop_SameWorkingChannel;
        }
//    chNextHoppair[workingChannel] = nexthop; // record the nexthop on each channel
    std::cout<< "next hop is: "<< nexthop.getDByte(3)<< "\n";
    return nexthop;
    }
/* deadEnds is not very efficient here, at least the 3rd transmission can avoid the deadend.*/



/*
 * check neighborhood, find the nodes in and out of focus area on the same channel
 */
bool SEARCH::checkFocusArea()
    {
    double maxAngleFocusRegion = PI/6.0; // 30°
    //       //which channel is being used?
//           emit(Radio::ChannelDecisionSignal, myAddr.str().c_str());
    //       Radio * myRadio=check_and_cast<Radio*>(getParentModule()->getModuleByRelativePath(".wlan[0].radio"));
    //       workingChannel = myRadio->myRadioRef->channel;
    std::cout<< "SEARCH: " << myAddr.getDByte(3) << "'s neighbors are: " << neighborhood <<"\n";
    for(nh_t::const_iterator nhIt=neighborhood.begin(); nhIt!=neighborhood.end(); ++nhIt)
        {
#ifdef MULTI_CHA
           ChannelNumberState neighborchannelstate = checkChannelwithIP(nhIt->first);//channel and channelstate
           /*
            * judge the available channels of this node
            */
           int *channelState;
           channelState = neighborchannelstate.second; // record states of all channels
           for(int i=0; i<= workingChannel-1; i++)
               {
               channelState++;
               }    // idea: increase pointer channelState
           int nhChannelOnrreq =*channelState; // the availability of the channel being used by rreq
           int nhCurrentWorkingChannel= neighborchannelstate.first; // the channel nh is using right now.
#endif

#ifndef MULTI_CHA
           ChannelNumberState_single neighborchannelstate = checkChannelwithIP(nhIt->first);//channel and channelstate
           /*
            * judge the available channels of this node
            */
           int nhChannelOnrreq =neighborchannelstate.second; // the availability of the channel being used by rreq
           int nhCurrentWorkingChannel= neighborchannelstate.first; // the channel nh is using right now.

#endif

           // if the channel being used by me is also available on neighbor, and neighbor is on the same side of dst.
           if (!nhChannelOnrreq && (nhIt->second->getRouterXPos()-getXPos())*(dstPos.x-getXPos())>=0)
           {
           /*
            * check whether is the neighbor in decision area. If the angle <  maxAngleFocusRegion, neighbor is in decision area.
            */
           double angleFocus;
           double angle1= atan((dstPos.y-getYPos()) / (dstPos.x-getXPos()));
           double angle2= atan((nhIt->second->getRouterYPos()-getYPos()) / (nhIt->second->getRouterXPos()-getXPos()));
           if(angle1*angle2 < 0) // neighbor and dst locate in different side of the horizontal line.
               {
               angleFocus = std::abs(angle1) + std::abs(angle2);
               }
           else
               angleFocus = std::abs(std::abs(angle1)- std::abs(angle2));

           if(angleFocus <maxAngleFocusRegion)
               {
               focusOnChannel[workingChannel].first.push_back(nhIt->first);
//               coCHnodesInFocus.push_back(nhIt->first);
               }
           else
               {
               focusOnChannel[workingChannel].second.push_back(nhIt->first);
               }
           }
        }
    std::cout<< "SEARCH: at " << simTime() << " channel "<< workingChannel << ": coCHnodesInFocus contains: " << focusOnChannel[workingChannel].first;
    std::cout<< "SEARCH: at " << simTime() << " channel "<< workingChannel << ": coCHnodesOutFocus contains: " << focusOnChannel[workingChannel].second <<"\n";
    if (!focusOnChannel[workingChannel].first.size())
        {DP =1;}
    else
    {DP =0;}
    return DP;
    }


/*
 * lin
 */
#ifdef MULTI_CHA
ChannelNumberState SEARCH::checkChannelwithIP(const IPv4Address& ip)
{
    cTopology *topo=new cTopology;
    topo->extractByParameter("IPstring");
std::cout << "Get channel info of node "<< ip.getDByte(3) << std::endl;
    for(int i=0;i<topo->getNumNodes();i++)
    {
        std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info(); //TODO:ask, "IPstring" looks static, why can it traversal all nodes?
        std::string newcurrentipstring;
        for(unsigned int j = 0; currentipstring[j] != '\0'; j++)
        {
            if(currentipstring[j]=='\"')
            {
                continue;
            }
            newcurrentipstring+=currentipstring[j];

        }
        //    std::cout<< "SEARCH: "<<myaddr<<", handleMessage, new current ip as string  :"<<newcurrentipstring<<endl;
        IPv4Address currentip;
        currentip.set(newcurrentipstring.c_str());

        //std::cout<< "SEARCH: "<<myaddr<<", VCap::checkChannelwithIP, currentip "<<currentip<<endl;
        // std::cout<< "SEARCH: "<<myaddr<<", VCap::checkChannelwithIP, ip.str().c_str(): "<<ip.str().c_str()<<", currentipchar.c_str(): "<<currentipchar.c_str()<<endl;
        // std::cout<< "SEARCH: "<<myaddr<<", VCap::checkChannelwithIP, ip.str()==currentipchar: "<<(ip.str()==currentipchar)<<endl;

        if (ip==currentip)
        {
            // std::cout<< "SEARCH: "<<myaddr<<", VCap::checkChannelwithIP, i: "<<i<<endl;
            //std::cout<< "SEARCH: "<<myaddr<<", VCap::checkChannelwithIP currentip: "<<currentip<<", path: "<<topo->getNode(i)->getModule()->getFullPath()<<endl;

            Radio* radio=check_and_cast<Radio*>(topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("wlan[0].radio"));

            ChannelNumberState channelNumberState(radio->myRadioRef->channel, radio->myRadioRef->AllChannelState);



//            ChannelNumberState channelNumberState(radio->myRadioRef->channel, radio->myRadioRef->channelState);

            return  channelNumberState;
        }
    }
    ChannelNumberState channelNumberState;
    return  channelNumberState;
}
#endif

#ifndef MULTI_CHA
ChannelNumberState_single SEARCH::checkChannelwithIP(const IPv4Address& ip)
{
    cTopology *topo=new cTopology;
    topo->extractByParameter("IPstring");
//    std::cout << "Get channel info of node "<< ip.getDByte(3) << std::endl;
    for(int i=0;i<topo->getNumNodes();i++)
    {
        std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info(); //TODO:ask, "IPstring" looks static, why can it traversal all nodes?
        std::string newcurrentipstring;
        for(unsigned int j = 0; currentipstring[j] != '\0'; j++)
        {
            if(currentipstring[j]=='\"')
            {
                continue;
            }
            newcurrentipstring+=currentipstring[j];

        }
        //    std::cout<< "SEARCH: "<<myaddr<<", handleMessage, new current ip as string  :"<<newcurrentipstring<<endl;
        IPv4Address currentip;
        currentip.set(newcurrentipstring.c_str());

        if (ip==currentip)
        {
         Radio* radio=check_and_cast<Radio*>(topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("wlan[0].radio"));

         ChannelNumberState_single channelNumberState(radio->myRadioRef->channel, radio->myRadioRef->channelState);

            return  channelNumberState;
        }
    }
    ChannelNumberState_single channelNumberState;
    return  channelNumberState;
}
#endif

void SEARCH::updateRoute(const IPv4Address& b, const IPv4Address& dst)
    {
    // remove the previous route:
    IPv4Route* previousRoute = routingTable -> findBestMatchingRoute(dst);
    routingTable -> removeRoute(previousRoute);
    // Add new routes:
    IPv4Route* pathToDst=new IPv4Route();
    pathToDst->setDestination(dst);
    pathToDst->setNetmask(IPv4Address("255.255.255.255"));
    pathToDst->setGateway(b);
    pathToDst->setInterface(routingTable->getInterfaceByAddress(myAddr));
    pathToDst->setSource(IPv4Route::MANET);
    pathToDst->setMetric(1);
    routingTable->addRoute(pathToDst);
    }


void SEARCH::positionUpdated(double x, double y){
	posTable[myAddr]=Coord(x,y);
    }

bool SEARCH::InList(const IPv4Address& addr, PathList& pathlist)
    {
    int times = 0;
    for (PathList::iterator it=pathlist.begin(); it!=pathlist.end(); it++)
        {
        if(it->getDByte(3) == addr.getDByte(3))
            {
            times++;
            }
        if(times ==2)
            {
                return true;
            }
        }
    return false;
    }

void SEARCH::printAllNeighbors(){
// traverse all fixhost module, print out their neighbors.

}

uint32_t SEARCH::getRoute(const Uint128&, std::vector<Uint128>&)
    {
	return 0;
    }

bool SEARCH::getNextHop(const Uint128&, Uint128&, int&, double&)
    {
	return false;
    }

void SEARCH::setRefreshRoute(const Uint128&, const Uint128&, bool)
    {
    }

bool SEARCH::isProactive()
    {
	return false;
    }

bool SEARCH::isOurType(cPacket*)
    {
	return false;
    }

bool SEARCH::getDestAddress(cPacket*, Uint128&)
{
	return false;
}

void SEARCH::finish()
    {
    //    int test = getParentModule()->getModuleByRelativePath();
    //    unsigned int totalNumberChangeGw2 =0;
    //    for (maptype_numUpdateLink_mobility::iterator It = numUpdateLink_mobility.begin(); It!=numUpdateLink_mobility.end(); ++It)
    //        {
    //        printf("The number of update of %d caused by mobility is %d\n", It->first.getDByte(3), It->second);
    //        totalNumberChangeGw2 += It->second;
    //        }
    //    printf("Total number of update caused by mobility is %d\n", totalNumberChangeGw2);

    int sumHopNum=0;
    int averageHopNum =0;
    if(lsit_numberHops.size())
        {
        for(Record_numHops::iterator it = lsit_numberHops.begin(); it != lsit_numberHops.end(); it++ )
            {
            sumHopNum += *it;
            }
        averageHopNum = sumHopNum/lsit_numberHops.size();
        }

    std::string resultFileName = par("resultFileName");
    resultFileName+="_twoChannel.csv";
    const char * resultFileNamechar = resultFileName.c_str();

    std::ofstream fileio;

    fileio.open (resultFileNamechar, std::ios::app);
//    int numForwarded = getParentModule()->getSubmodule("networkLayer")->getSubmodule("ip")->par("numForwarded_berger_ned");
//    int numUDPPassedUp;

//    // exclude the host nodes which don't have udp submodule
//    if (myAddr.getDByte(3)<3)
//        {
//        numUDPPassedUp = getParentModule()->getSubmodule("udp")->par("numPassedUp_berger_ned");
//        }
//    else
//        {
//        numUDPPassedUp = 0;
//        }
    //    int numForwarded = IPv4_berger->numForwarded_berger; // use the pointer to the whole submodule
      if (fileio.is_open() && myAddr.equals(dstAddr))
          {
          fileio << myAddr << ";" << updateInterval << ";" << arrivedRreqrNum <<  ";" << arrivedUDPNum << ";" << averageHopNum << "\n";
          fileio.flush();
          fileio.close();
          fileio <<std::endl;
          }

    }
