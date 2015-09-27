//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
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



#include "UDPSink.h"
#include "UDPControlInfo_m.h"

Define_Module(UDPSink);

simsignal_t UDPSink::rcvdPkSignal = SIMSIGNAL_NULL;


void UDPSink::initialize(int stage)
{

    if (stage == 0)
    {
        numReceived = 0;
        WATCH(numReceived);
        rcvdPkSignal = registerSignal("rcvdPk");
        duration=0;
        numBuffer=0;
        WATCH(duration);
        socket.setOutputGate(gate("udpOut"));

        int localPort = par("localPort");
        socket.bind(localPort);
    }
    else if (stage == 3)
    {
        socket.joinLocalMulticastGroups();
    }
}

void UDPSink::handleMessage(cMessage *msg)
{
  //  std::cout<<"UDPSink::handleMessage, mode: "<<mode<<endl;
    if (msg->getKind() == UDP_I_DATA)
    {
        // process incoming packet
        processPacket(PK(msg));
    }
    else if (msg->getKind() == UDP_I_ERROR)
    {
        EV << "Ignoring UDP error report\n";
        delete msg;
    }
    else
    {
        error("Unrecognized message (%s)%s", msg->getClassName(), msg->getName());
    }

    if (ev.isGUI())
    {
        char buf[32];
        sprintf(buf, "rcvd: %d pks", numReceived);
        getDisplayString().setTagArg("t", 0, buf);
    }
}

void UDPSink::finish()
{    cTopology *topo=new cTopology;
     topo->extractByParameter("IPstring");

//    std::cout<<"UDPSink finish:"<<getParentModule()->getModuleByRelativePath("manetrouting")->getAncestorPar("resultFileName").getFullName()<<endl;
    std::string resultFileName=getParentModule()->getModuleByRelativePath("manetrouting")->getAncestorPar("resultFileName");

    if(numReceived!=0)
    {
       duration=duration/numBuffer;
       par("duration").setDoubleValue(duration.dbl());
       std::cout<<"UDPSink::finish, average duration: "<<duration<<",numBuffer, "<<numBuffer<<endl;
    }
    std::string mode;
    #ifndef CAVCAP
            mode="_VCAP";
    #endif
    #ifdef EWT
            mode="_EWT";
    #endif
    #ifdef DTM
            mode="_pi";
    #endif


      double allAccPhyTime=0.0;
      int allSendup=0;
      int hop=0;
        for (int i = 0; i < topo->getNumNodes(); i++)
        {
         allAccPhyTime+=topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("wlan[0].radio")->par("AccPhyTime").doubleValue();
         allSendup+=topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("wlan[0].radio")->par("sendup").longValue();
           hop+=topo->getNode(i)->getModule()->par("hop").longValue();
        }
        std::string resultFileName1 = resultFileName + "_sojournTime.csv";
           const char *resultFileNameChar1 =     resultFileName1.c_str();
    std::ofstream fileio(resultFileNameChar1, std::ios::app);

    if (fileio.is_open())
    {
#ifdef CAVCAPBUFFER
    fileio<<resultFileName+mode+"_buffer"<<";"<<allAccPhyTime<<";"<<allSendup << allAccPhyTime/allSendup <<endl;
   // std::cout<<resultFileName+mode+"_buffer"<<";"<<duration<<endl;
#endif
#ifndef CAVCAPBUFFER
    fileio<<resultFileName+mode+"_nonbuffer"<<";"<<allAccPhyTime<<";"<<allSendup << allAccPhyTime/allSendup << endl;
   // std::cout<<resultFileName+mode+"_nobuffer"<<";"<<duration<<endl;
#endif

        fileio.flush();
        fileio.close();
     }


   std::string resultFileName2 = resultFileName + "UDPSink.cc_Hop.csv";
          const char *resultFileNameChar2 =     resultFileName2.c_str();
   std::ofstream fileio2(resultFileNameChar2, std::ios::app);
    hop++;
    if (fileio2.is_open())
       {
#ifdef CAVCAPBUFFER
       fileio2<<resultFileName+mode+"_buffer"<<";"<<hop<<endl;
      // std::cout<<resultFileName+mode+"_buffer"<<";"<<duration<<endl;
#endif
#ifndef CAVCAPBUFFER
       fileio2<<resultFileName+mode+"_buffer"<<";"<<hop<<endl;
      // std::cout<<resultFileName+mode+"_nobuffer"<<";"<<duration<<endl;
#endif

           fileio2.flush();
           fileio2.close();
        }

}

void UDPSink::processPacket(cPacket *pk)
{
    EV << "Received packet: " << UDPSocket::getReceivedPacketInfo(pk) << endl;
    //std::cout<<"UDPSink::processPacket, receive id: "<<pk->getId()<<", duration: "<<simTime()-pk->getTimestamp()<<endl;
   // pk->getSendingTime();
    ewt=getParentModule()->getSubmodule("manetrouting")->getAncestorPar("ewt").doubleValue();
   //std::cout<<"UDPSink::processPacket, simTime()-pk->getTimestamp(): "<<simTime()-pk->getTimestamp()<<endl;
    if((simTime()-pk->getTimestamp())>0.1)
    {
         duration += simTime()-pk->getTimestamp();
         numBuffer++;
    }


    emit(rcvdPkSignal, pk);
    delete pk;

    numReceived++;
}

