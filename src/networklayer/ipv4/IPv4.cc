//
// Copyright (C) 2004 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//


#include <stdlib.h>
#include <string.h>

#include "IPv4.h"

#include "ARPPacket_m.h"
#include "ICMPMessage_m.h"
#include "InterfaceTableAccess.h"
#include "IPv4ControlInfo.h"
#include "IPv4Datagram.h"
#include "IPv4InterfaceData.h"
#include "IRoutingTable.h"
#include "Radio80211aControlInfo_m.h"

Define_Module(IPv4);
Register_Class(IPv4Datagram);

int receive_rreqmsg_test;

void IPv4::initialize()
{
    QueueBase::initialize();

    ift = InterfaceTableAccess().get();
    rt = RoutingTableAccess().get();

    queueOutGate = gate("queueOut");

    defaultTimeToLive = par("timeToLive");
    defaultMCTimeToLive = par("multicastTimeToLive");
    fragmentTimeoutTime = par("fragmentTimeout");
    forceBroadcast = par("forceBroadcast");
    mapping.parseProtocolMapping(par("protocolMapping"));

    curFragmentId = 0;
    lastCheckTime = 0;
    fragbuf.init(icmpAccess.get());

    numMulticast = numLocalDeliver = numDropped = numUnroutable = numForwarded =VCaplocalforward= 0;

    WATCH(numMulticast);
    WATCH(numLocalDeliver);
    WATCH(numDropped);
    WATCH(numUnroutable);
    WATCH(numForwarded);
    WATCH(VCaplocalforward);
    // by default no MANET routing
    manetRouting = false;

#ifdef WITH_MANET
    // test for the presence of MANET routing
    // check if there is a protocol -> gate mapping
    int gateindex = mapping.getOutputGateForProtocol(IP_PROT_MANET);
    if (gateSize("transportOut")-1<gateindex)
        return;

    // check if that gate is connected at all
    cGate *manetgate = gate("transportOut", gateindex)->getPathEndGate();
    if (manetgate==NULL)
        return;

    cModule *destmod = manetgate->getOwnerModule();
    if (destmod==NULL)
        return;

    // manet routing will be turned on ONLY for routing protocols which has the @reactive property set
    // this prevents performance loss with other protocols that use pro active routing and do not need
    // assistance from the IPv4 component
    cProperties *props = destmod->getProperties();
    manetRouting = props && props->getAsBool("reactive");
  //  std::cout<<"IPv4::initialize: manetrouting: "<<manetRouting<<endl;
#endif
}

void IPv4::updateDisplayString()
{
    char buf[80] = "";
    if (numForwarded>0) sprintf(buf+strlen(buf), "fwd:%d ", numForwarded);
    if (numLocalDeliver>0) sprintf(buf+strlen(buf), "up:%d ", numLocalDeliver);
    if (numMulticast>0) sprintf(buf+strlen(buf), "mcast:%d ", numMulticast);
    if (numDropped>0) sprintf(buf+strlen(buf), "DROP:%d ", numDropped);
    if (numUnroutable>0) sprintf(buf+strlen(buf), "UNROUTABLE:%d ", numUnroutable);
    getDisplayString().setTagArg("t", 0, buf);
}

void IPv4::endService(cPacket *msg)
{  // std::cout<<"IPv4 endservice:"<<endl;
    if (msg->getArrivalGate()->isName("transportIn"))
    {
        handleMessageFromHL( msg );
    }
    else if (dynamic_cast<ARPPacket *>(msg))
    {
        // dispatch ARP packets to ARP
        handleARP((ARPPacket *)msg);
    }
    else
    {
//        Radio80211aControlInfo * cinfo = check_and_cast< Radio80211aControlInfo *>(msg);
//        std::cout<<"IPv4 cinfo inbuffer:"<<cinfo->getInbuffer()<<endl;
        IPv4Datagram *dgram = check_and_cast<IPv4Datagram *>(msg);
        InterfaceEntry *fromIE = getSourceInterfaceFrom(dgram);
        handlePacketFromNetwork(dgram, fromIE);
    }

    if (ev.isGUI())
        updateDisplayString();
}

InterfaceEntry *IPv4::getSourceInterfaceFrom(cPacket *msg)
{
    cGate *g = msg->getArrivalGate();
    return g ? ift->getInterfaceByNetworkLayerGateIndex(g->getIndex()) : NULL;
}

void IPv4::handlePacketFromNetwork(IPv4Datagram *datagram, InterfaceEntry *fromIE)
{  // std::cout<<"IPv4::handlePacketFromNetwork"<<endl;
    ASSERT(datagram);
    ASSERT(fromIE);

//    if(rt->getRouterId().getDByte(3)==3)
//    {
//        int Iwant2see3 =1;
//    }
    if(rt->getRouterId().getDByte(3)==3)
    {
         std::cout<<"IPv4::handlePacketFromNetwork on Node " << rt->getRouterId().getDByte(3) <<endl;
    }

    //Di:
    std::string packetName = datagram->getName();
    std::string UDPName ("UDPBasicAppData");
    std::string rreqName ("rreqmsg_ch");
    if (!packetName.compare(0, 15, UDPName))
            {
        timeList timeList = datagram->getArrivalTimeList();
        timeList.push_back(datagram->getArrivalTime());
        datagram->setArrivalTimeList(timeList);
            }

    std::cout <<"IPv4::handlePacketFromNetwork, node " <<  rt->getRouterId().getDByte(3) << " receives " << packetName.c_str() <<"\n";

    // value of numFixnodes is the last bit of destination's IP
    int numFixnodes = getParentModule()->getParentModule()->getParentModule()->par("numFixHosts");
    if (!packetName.compare(0, 15, UDPName) && rt->getRouterId().getDByte(3)==numFixnodes)
        {
        int nodeIP=rt->getRouterId().getDByte(3);
//            sendToManet(datagram);

//        //get the index of datagram
//        char packetName[] = datagram->getName();
//        char index[2];
//        for(int i=0; i<2; i++){
//            index[i] = packetName[16+i];
//        }

//        simtime_t delay = simTime() - datagram->getTimestamp();
//                datagram->getArrivalTime();
        int numHops= datagram->getNumAccessedNodes();
        PathList list = datagram->getPathList();
        list.push_back(rt->getRouterId());
//        std::cout << "numHops="<< numHops << ", list.size()="<<list.size() <<std::endl;

        simtime_t delay = simTime() - datagram->getStartTime();
        timeList timeList = datagram->getArrivalTimeList();
        timeList.push_back(datagram->getArrivalTime());
        datagram->setArrivalTimeList(timeList);


        std::cout << getParentModule()->getName() << "," << getParentModule()->getParentModule()->getName() << "," << getParentModule()->getParentModule()->getParentModule()->getName() <<"\n";
    std::string mode = getParentModule()->getParentModule()->getParentModule()->par("mode");
        std::string resultFileName = getParentModule()->getParentModule()->getModuleByRelativePath("manetrouting")->getAncestorPar("resultFileName");
        resultFileName+=mode;
        resultFileName+="_delay_hops_path.csv";
        const char *resultFileNamechar=resultFileName.c_str();
        std::ofstream fileio (resultFileNamechar,std::ios::app);

        if(fileio.is_open()){
            fileio << datagram->getName() << " " << delay <<" " << simTime() << " " << datagram->getTimestamp() << " " << numHops <<" ";
//            fileio << delay <<" " << numHops <<" ";
            fileio << list.size() << " " << timeList.size() ;

//            std::cout << datagram->getName() << " " << delay <<" " << simTime() << " " << datagram->getTimestamp() << " " << numHops <<" "<<list.size()<<endl;

//            PathList::const_iterator i;
//                for( i = list.begin(); i != list.end(); ++i){
//                    fileio << *i << " ";
//                }
            timeList::const_iterator i;
                for( i = timeList.begin(); i != timeList.end(); ++i){
                    fileio << *i << " ";
                }


                fileio << endl;

            fileio.flush();
            fileio.close();
            }


        }

    //
    // "Prerouting"
    //

    // check for header biterror
    if (datagram->hasBitError())
    {
        // probability of bit error in header = size of header / size of total message
        // (ignore bit error if in payload)
        double relativeHeaderLength = datagram->getHeaderLength() / (double)datagram->getByteLength();
        if (dblrand() <= relativeHeaderLength)
        {
            EV << "bit error found, sending ICMP_PARAMETER_PROBLEM\n";
            std::cout << "bit error found, sending ICMP_PARAMETER_PROBLEM\n";
            icmpAccess.get()->sendErrorMessage(datagram, ICMP_PARAMETER_PROBLEM, 0);
            return;
        }
    }

    // remove control info, but keep the one on the last fragment of DSR and MANET datagrams
    int protocol = datagram->getTransportProtocol();
    bool isManetDatagram = protocol == IP_PROT_MANET || protocol == IP_PROT_DSR|| protocol ==IP_PROT_VCap;
    if (!isManetDatagram || datagram->getMoreFragments())


//        IPv4Address &nextAddr = datagram->removeControlInfo()      //Di TODO, find out the nexthop address

    if(receive_rreqmsg_test)
//        cObject *ptr= datagram->removeControlInfo();
//        //SearRouteRequest* rreq = datagram->decapsulate();
//        IPv4Address nextHopAddress= ptr->getNextHopAddr;

        delete datagram->removeControlInfo();

    // route packet
    IPv4Address &destAddr = datagram->getDestAddress();

    std::cout << "Routing datagram `" << datagram->getName() << "' with dest=" << destAddr << " at " << simTime() << "\n";
    std::cout << "IPv4:handlePacketFromNetwork "<<rt->getRouterId() <<" forwards '"<< datagram->getName() << "' with protocol :"<<protocol << " with destAddr=" << destAddr << "\n";
//            if(datagram->getDestAddress().getDByte(3)==2 && simTime() >7000)
//            {
//                int Iwant2see1 =1;
//            }
//            if(datagram->getDestAddress().getDByte(3)==4 && simTime() >7000)
//            {
//                int Iwant2see2 =1;
//            }
//            if(datagram->getName() == UDPName){
//                int Iwant2see3 =1;
//            }

    if (fromIE->isLoopback())
    {
       // std::cout << "IPv4::handlePacketFromNetwork,dest ie is loopback"<<endl;
        reassembleAndDeliver(datagram);
    }
    else if (destAddr.isMulticast())
    {
        // check for local delivery
        // Note: multicast routers will receive IGMP datagrams even if their interface is not joined to the group
        if (fromIE->ipv4Data()->isMemberOfMulticastGroup(destAddr) ||
                (rt->isMulticastForwardingEnabled() && datagram->getTransportProtocol() == IP_PROT_IGMP))
            reassembleAndDeliver(datagram->dup());

        // don't forward if IP forwarding is off, or if dest address is link-scope
        if (!rt->isIPForwardingEnabled() || destAddr.isLinkLocalMulticast())
            delete datagram;
        else if (datagram->getTimeToLive() == 0)
        {
            EV << "TTL reached 0, dropping datagram.\n";
           // std::cout << "TTL reached 0, dropping datagram.\n";
            delete datagram;
        }
        else
            forwardMulticastPacket(datagram, fromIE, -1);
    }
    else
    {
#ifdef WITH_MANET
        if (manetRouting)
        {
             sendRouteUpdateMessageToManet(datagram);
            // std::cout << "IPv4::handlePacketFromNetwork, sendRouteUpdateMessageToManet. "<<endl;
        }

#endif
        InterfaceEntry *broadcastIE = NULL;

        // check for local delivery; we must accept also packets coming from the interfaces that
        // do not yet have an IP address assigned. This happens during DHCP requests.
        if (rt->isLocalAddress(destAddr) || fromIE->ipv4Data()->getIPAddress().isUnspecified())
        {  // std::cout<<"reassembleAndDeliver"<<endl;
            reassembleAndDeliver(datagram);
        }
        else if (destAddr.isLimitedBroadcastAddress() || (broadcastIE=rt->findInterfaceByLocalBroadcastAddress(destAddr)))
        {
            // broadcast datagram on the target subnet if we are a router
            if (broadcastIE && fromIE != broadcastIE && rt->isIPForwardingEnabled())
                fragmentAndSend(datagram->dup(), broadcastIE, IPv4Address::ALLONES_ADDRESS, -1);
            //std::cout << "Broadcast received\n";
            std::cout << "Broadcast received\n";
            reassembleAndDeliver(datagram);
        }
        else if (!rt->isIPForwardingEnabled())
        {  // std::cout << "forwarding off, dropping packet\n";
            std::cout << "forwarding off, dropping packet\n";
            numDropped++;
            delete datagram;
        }
        else
        {
          routeUnicastPacket(datagram, NULL/*destIE*/, IPv4Address::UNSPECIFIED_ADDRESS, -1);
         //  std::cout<<"IPv4::handlePacketFromNetwork,routeUnicastPacket"<<endl;
        }

    }
}

void IPv4::handleARP(ARPPacket *msg)
{
    // FIXME hasBitError() check  missing!

    // delete old control info
    delete msg->removeControlInfo();

    // dispatch ARP packets to ARP and let it know the gate index it arrived on
    InterfaceEntry *fromIE = getSourceInterfaceFrom(msg);
    ASSERT(fromIE);

    IPv4RoutingDecision *routingDecision = new IPv4RoutingDecision();
    routingDecision->setInterfaceId(fromIE->getInterfaceId());
    msg->setControlInfo(routingDecision);

    send(msg, queueOutGate);
}

void IPv4::handleReceivedICMP(ICMPMessage *msg)
{
    switch (msg->getType())
    {
        case ICMP_REDIRECT: // TODO implement redirect handling
        case ICMP_DESTINATION_UNREACHABLE:
        case ICMP_TIME_EXCEEDED:
        case ICMP_PARAMETER_PROBLEM: {
            // ICMP errors are delivered to the appropriate higher layer protocol
            IPv4Datagram *bogusPacket = check_and_cast<IPv4Datagram *>(msg->getEncapsulatedPacket());
            int protocol = bogusPacket->getTransportProtocol();

            if(simTime()>7000)
            std::cout<<"IPv4::handleReceivedICMP. protocol: "<<protocol<<", srcIP: "<< bogusPacket->getSrcAddress()<<", destIP: "<<bogusPacket->getDestAddress()<<endl;
            int gateindex;
            if(protocol==IP_PROT_VCap)
            {
                 gateindex = mapping.getOutputGateForProtocol(IP_PROT_MANET);
            }
            else
            {
                 gateindex = mapping.getOutputGateForProtocol(protocol);
            }


            send(msg, "transportOut", gateindex);
            break;
        }
        default: {
            // all others are delivered to ICMP: ICMP_ECHO_REQUEST, ICMP_ECHO_REPLY,
            // ICMP_TIMESTAMP_REQUEST, ICMP_TIMESTAMP_REPLY, etc.
            int gateindex = mapping.getOutputGateForProtocol(IP_PROT_ICMP);
            send(msg, "transportOut", gateindex);
            break;
        }
    }
}

void IPv4::handleMessageFromHL(cPacket *msg)
{   //std::cout<<"IPv4::handleMessageFromHL"<<endl;

//    if(msg->getArrivalGate()->getIndex() == 7)
//    {
//        int helloe =1;
//
//    }


    if(rt->getRouterId().getDByte(3) ==2 && simTime() > 7100){
        int isNode2 =1;
    }

    // if no interface exists, do not send datagram
    if (ift->getNumInterfaces() == 0)
    {  // std::cout << "No interfaces exist, dropping packet\n";
        EV << "No interfaces exist, dropping packet\n";
        numDropped++;
        delete msg;
        return;
    }
   if(msgToRoute* msgtoroute=dynamic_cast<msgToRoute *>(msg))
   {
       if(rt->getRouterId().getDByte(3)==3){
     std::cout<<"IPv4::handleMessageFromHL, msgToRoute received on " << rt->getRouterId()  <<endl;
       }

     std::cout<<"IPv4::handleMessageFromHL, on Node "<< rt->getRouterId().getDByte(3)<<endl;;
     IPv4Datagram* datagram=dynamic_cast<IPv4Datagram*>(msgtoroute->decapsulate());
     IPv4ControlInfo* info=check_and_cast<IPv4ControlInfo*>(datagram->removeControlInfo());
     datagram->setControlInfo(info);
     // info->getSrcAddr();
  //   std::cout<<"IPv4::handleMessageFromHL, controlinfo src addr "<<info->getSrcAddr()<<endl;

     int gateindex = mapping.getOutputGateForProtocol(IP_PROT_UDP);
       if (gate("transportOut", gateindex)->isPathOK())
      {
           std::cout<<"IPv4::handleMessageFromHL, controlinfo classname "<<datagram->getControlInfo()->getClassName()<<endl;
          send(datagram, "transportOut", gateindex);
      }

      //send(currdatagram, "");
       return;

   }

// encapsulate and send
    IPv4Datagram *datagram = dynamic_cast<IPv4Datagram *>(msg);
    IPv4ControlInfo *controlInfo = NULL;
    //FIXME dubious code, remove? how can the HL tell IP whether it wants tunneling or forwarding?? --Andras
    if (datagram) // if HL sends an IPv4Datagram, route the packet
    {
        if(rt->getRouterId().getDByte(3)==1)
        {
        datagram->setStartTime(simTime());
        }
        //std::cout<<"IPv4::handleMessageFromHL, ipdatagram received"<<endl;
        // Dsr routing, Dsr is a HL protocol and send IPv4Datagram
        if (datagram->getTransportProtocol()==IP_PROT_DSR)
        {
            controlInfo = check_and_cast<IPv4ControlInfo*>(datagram->removeControlInfo());
           // std::cout<<"routing protocol is DSR."<<endl;
        }
        if(datagram->getTransportProtocol()==IP_PROT_VCap)
        {
            std::cout<<"IPv4::handleMessageFromHL, datagram->getTransportProtocol()==IP_PROT_VCap on " << rt->getRouterId()  <<endl;
            controlInfo = check_and_cast<IPv4ControlInfo*>(datagram->removeControlInfo());
            controlInfo->setInterfaceId(101);

          //  std::cout<<"routing protocol is VCap,controlInfor interfaceid: "<<controlInfo->getInterfaceId()<<endl;
        }
		else
		{   //controlInfo=new IPv4ControlInfo();
		    controlInfo=dynamic_cast<IPv4ControlInfo*>(datagram->removeControlInfo());
		   // controlInfo=dynamic_cast<IPv4ControlInfo*>(msg->removeControlInfo());

		   // std::cout<<"routing protocol isn't DSR."<<endl;
		   // std::cout<<"nexthopip: "<<controlInfo->getNextHopAddr()<<endl;
		}
    }
    else
    {
        // encapsulate
       // std::cout<<"IPv4::handleMessageFromHL, encapsulate"<<endl;
        controlInfo = check_and_cast<IPv4ControlInfo*>(msg->removeControlInfo());
        datagram = encapsulate(msg, controlInfo);
    }

    // extract requested interface and next hop
    InterfaceEntry *destIE = NULL;
    IPv4Address nextHopAddress = IPv4Address::UNSPECIFIED_ADDRESS;
    bool multicastLoop = true;
	double txp=-1;
    if (controlInfo!=NULL)
    {
        std::cout<<"IPv4::handleMessageFromHL, controlinfo interfaceid: "<<controlInfo->getInterfaceId()<<endl;

        destIE = ift->getInterfaceById(controlInfo->getInterfaceId());
        nextHopAddress = controlInfo->getNextHopAddr();
        multicastLoop = controlInfo->getMulticastLoop();
		txp = controlInfo->getTransmitterPower();
		//std::cout<<"IPv4::handleMessageFromHL, next hop addr: "<<nextHopAddress<<",txp: "<<txp<<", destIE: "<<destIE<<endl;
    }

    delete controlInfo;

    // send
    IPv4Address &destAddr = datagram->getDestAddress();

    //Di:
        std::string packetName = datagram->getName();
        std::string UDPName ("UDPBasicAppData");
        std::string rreqName ("rreqmsg_ch");
        if (!packetName.compare(0, 15, UDPName))
                {
                int receive_udp_test=1;
                }

    std::cout << "IPv4::handleMessageFromHL " << datagram->getSrcAddress() << " or " << rt->getRouterId() <<" sending datagram `" << datagram->getName() << "' with dest=" << destAddr << "\n";
//std::cout << this->getParentModule()->getParentModule()->getParentModule()->par("a").longValue() << " " << this->getParentModule()->getParentModule()->getParentModule()->par("b").longValue() << "\n";

    if (datagram->getDestAddress().isMulticast())
    {   //std::cout<<"IPv4::handleMessageFromHL: isMulticast"<<endl;
        destIE = determineOutgoingInterfaceForMulticastDatagram(datagram, destIE);

        // loop back a copy
        if (multicastLoop && (!destIE || !destIE->isLoopback()))
        {
            InterfaceEntry *loopbackIF = ift->getFirstLoopbackInterface();
            if (loopbackIF)
                fragmentAndSend(datagram->dup(), loopbackIF, destAddr, txp);
        }

        if (destIE)
        {
            numMulticast++;
            fragmentAndSend(datagram, destIE, destAddr, txp);
        }
        else
        {  //  std::cout << "No multicast interface, packet dropped\n";
            EV << "No multicast interface, packet dropped\n";
            numUnroutable++;
            delete datagram;
        }
    }
    else // unicast and broadcast
    {   // std::cout<<"IPv4::handleMessageFromHL: isUnicast"<<endl;
#ifdef WITH_MANET
        if (manetRouting)
        {
            std::cout<<"handleMessageFromHL: manetRouting: "<<manetRouting<<endl;
//            datagram->setStartTime(simTime());
            sendRouteUpdateMessageToManet(datagram);

        }

#endif
        // check for local delivery
        if (rt->isLocalAddress(destAddr))
        {
            EV << "local delivery\n";
          //  std::cout << "IPv4::local delivery\n";
            //getParentModule()->getParentModule()->getModuleByRelativePath("manetrouting")->set;
            if (destIE)
            {      EV << "datagram destination address is local, ignoring destination interface specified in the control info\n";
            //     std::cout << "datagram destination address is local, ignoring destination interface specified in the control info\n";
            }
            destIE = ift->getFirstLoopbackInterface();
            ASSERT(destIE);
            fragmentAndSend(datagram, destIE, destAddr, txp);
        }
        else if (destAddr.isLimitedBroadcastAddress() || rt->isLocalBroadcastAddress(destAddr))
        {  // std::cout<<"routeLocalBroadcastPacket, destIE:"<<destIE<<", nextHopAddress: "<<nextHopAddress<<", txp: "<<txp<<endl;
            routeLocalBroadcastPacket(datagram, destIE, txp);
        }
        else
        {
            routeUnicastPacket(datagram, destIE, nextHopAddress, txp);
            std::cout<<"IPv4::routeUnicastPacket, destIE:"<<destIE<<", nextHopAddress: "<<nextHopAddress<<", txp: "<<txp<<endl;
        }
    }
}

/* Choose the outgoing interface for the muticast datagram:
 *   1. use the interface specified by MULTICAST_IF socket option (received in the control info)
 *   2. lookup the destination address in the routing table
 *   3. if no route, choose the interface according to the source address
 *   4. or if the source address is unspecified, choose the first MULTICAST interface
 */
InterfaceEntry *IPv4::determineOutgoingInterfaceForMulticastDatagram(IPv4Datagram *datagram, InterfaceEntry *multicastIFOption)
{
    InterfaceEntry *ie = NULL;
    if (multicastIFOption)
    {
        ie = multicastIFOption;
        EV << "multicast packet routed by socket option via output interface " << ie->getName() << "\n";
       // std::cout << "multicast packet routed by socket option via output interface " << ie->getName() << "\n";
    }
    if (!ie)
    {
        IPv4Route *route = rt->findBestMatchingRoute(datagram->getDestAddress());
        if (route)
            ie = route->getInterface();
        if (ie)
            EV << "multicast packet routed by routing table via output interface " << ie->getName() << "\n";
    }
    if (!ie)
    {
        ie = rt->getInterfaceByAddress(datagram->getSrcAddress());
        if (ie)
            EV << "multicast packet routed by source address via output interface " << ie->getName() << "\n";
    }
    if (!ie)
    {
        ie = ift->getFirstMulticastInterface();
        if (ie)
            EV << "multicast packet routed via the first multicast interface " << ie->getName() << "\n";
    }
    return ie;
}


void IPv4::routeUnicastPacket(IPv4Datagram *datagram, InterfaceEntry *destIE, IPv4Address destNextHopAddr, double txp)
{
    IPv4Address destAddr = datagram->getDestAddress();
  /*  IPv4ControlInfo *controlInfo;
    controlInfo= check_and_cast<IPv4ControlInfo*>(datagram->getControlInfo());
*/
//    std::cout << "Routing datagram `" << datagram->getName() << "' with dest=" << destAddr << "\n ";
/*    if(controlInfo!=NULL){
         std::cout << "Routing datagram " << datagram->getName() << "' with dest=" << destAddr << ": protocol: "<<controlInfo->getProtocol();
    }
*/
    IPv4Address nextHopAddr;
    // if output port was explicitly requested, use that, otherwise use IPv4 routing
    if (destIE)
    {
        EV << "using manually specified output interface " << destIE->getName() << "\n";
       // std::cout << "using manually specified output interface " << destIE->getName() << "\n";
        // and nextHopAddr remains unspecified
        if (manetRouting && !destNextHopAddr.isUnspecified())
           nextHopAddr = destNextHopAddr;  // Manet DSR routing explicit route
        // special case ICMP reply
        else if (destIE->isBroadcast())
        {
            // if the interface is broadcast we must search the next hop
            const IPv4Route *re = rt->findBestMatchingRoute(destAddr);
            if (re && (re->getSource() != IPv4Route::MANET || re->getDestination()==destAddr) &&
                    re->getInterface() == destIE)
                nextHopAddr = re->getGateway();
        }
    }
    else
    {
        // use IPv4 routing (lookup in routing table)
        //    FIXME MANET routes should use 255.255.255.255 netmask,
        //          to eliminate the equality check below.
        const IPv4Route *re = rt->findBestMatchingRoute(destAddr);              // on the relay node which is immediately prior to the destination, re is not null.
      //  std::cout<<"look up routing table, use IPv4 routing"<<endl;
        if (re && (re->getSource() != IPv4Route::MANET || re->getDestination() == destAddr))
        {
            destIE = re->getInterface();
            nextHopAddr = re->getGateway();

            if(simTime()>7000)
            {
                VCaplocalforward++;
                cPar& cpar=getParentModule()->getParentModule()->getModuleByRelativePath("manetrouting")->getAncestorPar("VCaplocalforward");
                cpar.setLongValue(VCaplocalforward);

#ifdef MULTI_CHA
                emit(Radio::ChannelDecisionSignal,destAddr.str().c_str());
                //  std::cout<<"routeUnicast, emit "<<nextHopAddr<<endl;
#endif
            }


           // std::cout<<"routeUnicast, nexthopaddr: "<<nextHopAddr<<endl;
        }

    }

    if (!destIE) // no route found
    { // std::cout<<"no routes found"<<endl;
#ifdef WITH_MANET
            if (manetRouting)
            {
                  sendNoRouteMessageToManet(datagram);
                 // std::cout<<"manetrouting, sendNoRouteMessageToManet."<<endl;
            }

            else
            {
#endif
                EV << "unroutable, sending ICMP_DESTINATION_UNREACHABLE\n";
               std::cout << "unroutable, sending ICMP_DESTINATION_UNREACHABLE\n";
                numUnroutable++;
                icmpAccess.get()->sendErrorMessage(datagram, ICMP_DESTINATION_UNREACHABLE, 0);
#ifdef WITH_MANET
            }
#endif
    }
    else // fragment and send
    {
//        std::cout << "output interface is " << destIE->getName() << ", next-hop address: " << nextHopAddr << "\n";
      //  std::cout << "output interface is " << destIE->getName() << ", next-hop address: " << nextHopAddr << "\n";
        numForwarded++;

        fragmentAndSend(datagram, destIE, nextHopAddr, txp);
    }
}

void IPv4::routeLocalBroadcastPacket(IPv4Datagram *datagram, InterfaceEntry *destIE, double txp)
{
    // The destination address is 255.255.255.255 or local subnet broadcast address.
    // We always use 255.255.255.255 as nextHopAddress, because it is recognized by ARP,
    // and mapped to the broadcast MAC address.
 //   std::cout<<"IPv4::routeLocalBroadcastPacket, destIE:"<<destIE<<", texp:"<<txp <<endl;
    if (destIE!=NULL)
    {
        fragmentAndSend(datagram, destIE, IPv4Address::ALLONES_ADDRESS, txp);
    }
    else if (forceBroadcast)
    {
        // forward to each interface including loopback
        for (int i = 0; i<ift->getNumInterfaces(); i++)
        {
            InterfaceEntry *ie = ift->getInterface(i);
            //std::cout<<"IPv4::routeLocalBroadcastPacket, current i: "<<i<<"interfaceentry path: "<<ie->getFullPath()<<endl;
            fragmentAndSend(datagram->dup(), ie, IPv4Address::ALLONES_ADDRESS, txp);
        }
        delete datagram;
    }
    else
    {
        numDropped++;
        delete datagram;
    }
}

InterfaceEntry *IPv4::getShortestPathInterfaceToSource(IPv4Datagram *datagram)
{
    return rt->getInterfaceForDestAddr(datagram->getSrcAddress());
}

void IPv4::forwardMulticastPacket(IPv4Datagram *datagram, InterfaceEntry *fromIE, double txp)
{
    ASSERT(fromIE);
    const IPv4Address &origin = datagram->getSrcAddress();
    const IPv4Address &destAddr = datagram->getDestAddress();
    ASSERT(destAddr.isMulticast());

    EV << "Forwarding multicast datagram `" << datagram->getName() << "' with dest=" << destAddr << "\n";

    numMulticast++;

    const IPv4MulticastRoute *route = rt->findBestMatchingMulticastRoute(origin, destAddr);
    if (!route)
    {
        EV << "No route, packet dropped.\n";
        numUnroutable++;
        delete datagram;
    }
    else if (route->getParent() && fromIE != route->getParent())
    {
        EV << "Did not arrive on parent interface, packet dropped.\n";
        numDropped++;
        delete datagram;
    }
    // backward compatible: no parent means shortest path interface to source (RPB routing)
    else if (!route->getParent() && fromIE != getShortestPathInterfaceToSource(datagram))
    {
        EV << "Did not arrive on shortest path, packet dropped.\n";
        numDropped++;
        delete datagram;
    }
    else
    {
        numForwarded++;
        // copy original datagram for multiple destinations
        const IPv4MulticastRoute::ChildInterfaceVector &children = route->getChildren();
        for (unsigned int i=0; i<children.size(); i++)
        {
            InterfaceEntry *destIE = children[i]->getInterface();
            if (destIE != fromIE)
            {
                int ttlThreshold = destIE->ipv4Data()->getMulticastTtlThreshold();
                if (datagram->getTimeToLive() <= ttlThreshold)
                    EV << "Not forwarding to " << destIE->getName() << " (ttl treshold reached)\n";
                else if (children[i]->isLeaf() && !destIE->ipv4Data()->hasMulticastListener(destAddr))
                    EV << "Not forwarding to " << destIE->getName() << " (no listeners)\n";
                else
                {
                    EV << "Forwarding to " << destIE->getName() << "\n";
                    fragmentAndSend(datagram->dup(), destIE, destAddr, txp);
                }
            }
        }
        // only copies sent, delete original datagram
        delete datagram;
    }
}

void IPv4::reassembleAndDeliver(IPv4Datagram *datagram)
{
    EV << "Local delivery\n";

    if (datagram->getSrcAddress().isUnspecified())
        EV << "Received datagram '%s' without source address filled in" << datagram->getName() << "\n";

    // reassemble the packet (if fragmented)
    if (datagram->getFragmentOffset()!=0 || datagram->getMoreFragments())
    {
        EV << "Datagram fragment: offset=" << datagram->getFragmentOffset()
           << ", MORE=" << (datagram->getMoreFragments() ? "true" : "false") << ".\n";

        // erase timed out fragments in fragmentation buffer; check every 10 seconds max
        if (simTime() >= lastCheckTime + 10)
        {
            lastCheckTime = simTime();
            fragbuf.purgeStaleFragments(simTime()-fragmentTimeoutTime);
        }

        datagram = fragbuf.addFragment(datagram, simTime());
        if (!datagram)
        {
            EV << "No complete datagram yet.\n";
            return;
        }
        EV << "This fragment completes the datagram.\n";
    }

    // decapsulate and send on appropriate output gate
    int protocol = datagram->getTransportProtocol();

    if (protocol==IP_PROT_ICMP)
    {
        // incoming ICMP packets are handled specially
        handleReceivedICMP(check_and_cast<ICMPMessage *>(decapsulate(datagram)));
        numLocalDeliver++;
    }
    else if (protocol==IP_PROT_IP)
    {
        // tunnelled IP packets are handled separately
        send(decapsulate(datagram), "preRoutingOut");  //FIXME There is no "preRoutingOut" gate in the IPv4 module.
    }
    else if (protocol==IP_PROT_DSR)
    {
#ifdef WITH_MANET
        // If the protocol is Dsr Send directely the datagram to manet routing
        if (manetRouting)
            sendToManet(datagram);
#else
        throw cRuntimeError("DSR protocol packet received, but MANET routing support is not available.");
#endif
    }
    else if (protocol==IP_PROT_VCap)
    { // std::cout<<"datagram info: src addr:"<<datagram->getSrcAddress()<<", dest addr:"<<datagram->getDestAddress()<<", ttl:"<<datagram->getTimeToLive()<<", type of service:"<<datagram->getTypeOfService()<<endl;
       IPv4ControlInfo * controlInfo=new IPv4ControlInfo();
       controlInfo->setDestAddr(datagram->getDestAddress());
       controlInfo->setSrcAddr(datagram->getSrcAddress());
       //controlInfo->setInterfaceId(datagram->get)
       controlInfo->setTimeToLive(datagram->getTimeToLive());
     //  controlInfo->setTypeOfService(datagram->getTypeOfService());
       datagram->removeControlInfo();
       datagram->setControlInfo(controlInfo);
    //   std::cout<< "control info set"<<endl;
      msgToRoute* msg=new msgToRoute();
        std::cout<<"IPv4::reassembleAndDeliver, send msgToRoute on "<<rt->getRouterId() << " at "<<simTime()<<endl;
        msg->setDeadendList(datagram->getDeadendList());
        msg->setPathList(datagram->getPathList());
        msg->encapsulate(datagram);

        sendToManet(msg);

    }
    else
    {
        // JcM Fix: check if the transportOut port are connected, otherwise
        // discard the packet
        // if(simTime()>7000)
      //  std::cout<<"IPv4::reassembleAndDeliver, protocol in else, "<<protocol<<endl;
        int gateindex = mapping.getOutputGateForProtocol(protocol);

        if (gate("transportOut", gateindex)->isPathOK())
        {
            send(decapsulate(datagram), "transportOut", gateindex);
            numLocalDeliver++;
        }
        else
        {
            EV << "L3 Protocol not connected. discarding packet" << endl;
            std::cout << "L3 Protocol not connected. discarding packet" << endl;
            icmpAccess.get()->sendErrorMessage(datagram, ICMP_DESTINATION_UNREACHABLE, ICMP_DU_PROTOCOL_UNREACHABLE);
        }
    }
}

cPacket *IPv4::decapsulate(IPv4Datagram *datagram)
{
    // decapsulate transport packet
    InterfaceEntry *fromIE = getSourceInterfaceFrom(datagram);
    cPacket *packet = datagram->decapsulate();

    // create and fill in control info
    IPv4ControlInfo *controlInfo = new IPv4ControlInfo();
    controlInfo->setProtocol(datagram->getTransportProtocol());
    controlInfo->setSrcAddr(datagram->getSrcAddress());
    controlInfo->setDestAddr(datagram->getDestAddress());
    controlInfo->setTypeOfService(datagram->getTypeOfService());
    controlInfo->setInterfaceId(fromIE ? fromIE->getInterfaceId() : -1);
    controlInfo->setTimeToLive(datagram->getTimeToLive());

    // original IPv4 datagram might be needed in upper layers to send back ICMP error message
    controlInfo->setOrigDatagram(datagram);

    // attach control info
    packet->setControlInfo(controlInfo);

    return packet;
}

void IPv4::fragmentAndSend(IPv4Datagram *datagram, InterfaceEntry *ie, IPv4Address nextHopAddr, double txp)
{
    // fill in source address
    if (datagram->getSrcAddress().isUnspecified())
        datagram->setSrcAddress(ie->ipv4Data()->getIPAddress());

    // hop counter decrement; but not if it will be locally delivered
    if (!ie->isLoopback())
        datagram->setTimeToLive(datagram->getTimeToLive()-1);

    // hop counter check
    if (datagram->getTimeToLive() < 0)
    {
        // drop datagram, destruction responsibility in ICMP
        EV << "datagram TTL reached zero, sending ICMP_TIME_EXCEEDED\n";
        std::cout << "datagram TTL reached zero, sending ICMP_TIME_EXCEEDED\n";
        icmpAccess.get()->sendErrorMessage(datagram, ICMP_TIME_EXCEEDED, 0);
        numDropped++;
        return;
    }

    int mtu = ie->getMTU();

    // check if datagram does not require fragmentation
    if (datagram->getByteLength() <= mtu)
    {
        sendDatagramToOutput(datagram, ie, nextHopAddr, txp);
        return;
    }

    // if "don't fragment" bit is set, throw datagram away and send ICMP error message
    if (datagram->getDontFragment())
    {
        EV << "datagram larger than MTU and don't fragment bit set, sending ICMP_DESTINATION_UNREACHABLE\n";
        std::cout << "datagram larger than MTU and don't fragment bit set, sending ICMP_DESTINATION_UNREACHABLE\n";
        icmpAccess.get()->sendErrorMessage(datagram, ICMP_DESTINATION_UNREACHABLE,
                                                     ICMP_FRAGMENTATION_ERROR_CODE);
        numDropped++;
        return;
    }

    // optimization: do not fragment and reassemble on the loopback interface
    if (ie->isLoopback())
    {
        sendDatagramToOutput(datagram, ie, nextHopAddr, txp);
        return;
    }

    // FIXME some IP options should not be copied into each fragment, check their COPY bit
    int headerLength = datagram->getHeaderLength();
    int payloadLength = datagram->getByteLength() - headerLength;
    int fragmentLength = ((mtu - headerLength) / 8) * 8; // payload only (without header)
    int offsetBase = datagram->getFragmentOffset();

    int noOfFragments = (payloadLength + fragmentLength - 1)/ fragmentLength;
    EV << "Breaking datagram into " << noOfFragments << " fragments\n";

    // create and send fragments
    std::string fragMsgName = datagram->getName();
    fragMsgName += "-frag";

    for (int offset=0; offset < payloadLength; offset+=fragmentLength)
    {
        bool lastFragment = (offset+fragmentLength >= payloadLength);
        // length equal to fragmentLength, except for last fragment;
        int thisFragmentLength = lastFragment ? payloadLength - offset : fragmentLength;

        // FIXME is it ok that full encapsulated packet travels in every datagram fragment?
        // should better travel in the last fragment only. Cf. with reassembly code!
        IPv4Datagram *fragment = (IPv4Datagram *) datagram->dup();
        fragment->setName(fragMsgName.c_str());

        // "more fragments" bit is unchanged in the last fragment, otherwise true
        if (!lastFragment)
            fragment->setMoreFragments(true);

        fragment->setByteLength(headerLength + thisFragmentLength);
        fragment->setFragmentOffset(offsetBase + offset);

        sendDatagramToOutput(fragment, ie, nextHopAddr, txp);
    }

    delete datagram;
}

IPv4Datagram *IPv4::encapsulate(cPacket *transportPacket, IPv4ControlInfo *controlInfo)
{
    IPv4Datagram *datagram = createIPv4Datagram(transportPacket->getName());
    datagram->setByteLength(IP_HEADER_BYTES);
    datagram->encapsulate(transportPacket);

    // set source and destination address
    IPv4Address dest = controlInfo->getDestAddr();
    datagram->setDestAddress(dest);

    IPv4Address src = controlInfo->getSrcAddr();

    // when source address was given, use it; otherwise it'll get the address
    // of the outgoing interface after routing
    if (!src.isUnspecified())
    {
        // if interface parameter does not match existing interface, do not send datagram
        if (rt->getInterfaceByAddress(src)==NULL)
            throw cRuntimeError("Wrong source address %s in (%s)%s: no interface with such address",
                      src.str().c_str(), transportPacket->getClassName(), transportPacket->getFullName());

        datagram->setSrcAddress(src);
    }

    // set other fields
    datagram->setTypeOfService(controlInfo->getTypeOfService());

    datagram->setIdentification(curFragmentId++);
    datagram->setMoreFragments(false);
    datagram->setDontFragment(controlInfo->getDontFragment());
    datagram->setFragmentOffset(0);

    short ttl;
    if (controlInfo->getTimeToLive() > 0)
        ttl = controlInfo->getTimeToLive();
    else if (datagram->getDestAddress().isLinkLocalMulticast())
        ttl = 1;
    else if (datagram->getDestAddress().isMulticast())
        ttl = defaultMCTimeToLive;
    else
        ttl = defaultTimeToLive;
    datagram->setTimeToLive(ttl);
    datagram->setTransportProtocol(controlInfo->getProtocol());

    // setting IPv4 options is currently not supported

    return datagram;
}

IPv4Datagram *IPv4::createIPv4Datagram(const char *name)
{
    return new IPv4Datagram(name);
}

void IPv4::sendDatagramToOutput(IPv4Datagram *datagram, InterfaceEntry *ie, IPv4Address nextHopAddr, double txp)
{
    if (ie->isLoopback())
    {
        // no interface module for loopback, forward packet internally
        // FIXME shouldn't be arrival(datagram) ?
        handlePacketFromNetwork(datagram, ie);
    //    std::cout<<"IPv4::sendDatagramToOutput, ie is loopback at simtime: "<<simTime()<<endl;
    }
    else
    {
        // send out datagram to ARP, with control info attached
        delete datagram->removeControlInfo();
        IPv4RoutingDecision *routingDecision = new IPv4RoutingDecision();
        routingDecision->setInterfaceId(ie->getInterfaceId());
        routingDecision->setNextHopAddr(nextHopAddr);
		routingDecision->setTransmitterPower(txp);
        datagram->setControlInfo(routingDecision);
        send(datagram, queueOutGate);
        std::cout<<"IPv4::sendDatagramToOutput, on Node" << rt->getRouterId() << ", ie is wlan, at simtime: "<<simTime() << ", next hop is: " << nextHopAddr.getDByte(3)<<endl;
    }
}

#ifdef WITH_MANET
void IPv4::sendRouteUpdateMessageToManet(IPv4Datagram *datagram)
{
    if (datagram->getTransportProtocol() != IP_PROT_DSR || datagram->getTransportProtocol() != IP_PROT_VCap) // Dsr don't use update code, the Dsr datagram is the update.
    {
        ControlManetRouting *control = new ControlManetRouting();
        control->setOptionCode(MANET_ROUTE_UPDATE);
        control->setSrcAddress(datagram->getSrcAddress().getInt());
        control->setDestAddress(datagram->getDestAddress().getInt());
        sendToManet(control);
    }
}

void IPv4::sendNoRouteMessageToManet(IPv4Datagram *datagram)
{
    if (datagram->getTransportProtocol()==IP_PROT_DSR)
    {
        sendToManet(datagram);
    }
    else
    {
        ControlManetRouting *control = new ControlManetRouting();
        control->setOptionCode(MANET_ROUTE_NOROUTE);
        control->setSrcAddress(datagram->getSrcAddress().getInt());
        control->setDestAddress(datagram->getDestAddress().getInt());
        control->encapsulate(datagram);
        std::cout<<"IPv4::sendNoRouteMessageToManet. on " << rt->getRouterId() << ", datagram dest:"<<datagram->getDestAddress()<<", src: "<<datagram->getSrcAddress()<<endl;
        sendToManet(control);
    }
}

void IPv4::sendToManet(cPacket *packet)
{
    ASSERT(manetRouting);

    int gateindex = mapping.getOutputGateForProtocol(IP_PROT_MANET);

    send(packet, "transportOut", gateindex);
}
#endif

