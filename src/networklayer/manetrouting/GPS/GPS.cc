
#include "IMobility.h"
#include "IPv4Datagram.h"
#include "IPv4ControlInfo.h"

#include "GPS.h";
//#define NODE1000
#define NODE160
Define_Module(GPS);



void GPS::initialize(int stage){

    if(stage==4)
        {
            registerRoutingModule();
            registerPosition(); // We register for position information, but unfortunately we will not get up-to-date information before the first update :(

            // Determine position and IP:
            routingTable=check_and_cast<IRoutingTable*>(getParentModule()->getSubmodule("routingTable"));
            myaddr=routingTable->getRouterId();
            X=UNKNOWNPOS;
            Y=UNKNOWNPOS;
            X=getXPos();
            Y=getYPos();

            myposition.X=X;
            myposition.Y=Y;

           // std::cout<<myaddr<<", initialize,my position: "<<getXPos()<<","<<getYPos()<<endl;
            trueHit=0;
            falseHit=0;
            missed=0;

            notforme=0;
            notformer=0;
            numforward=0;
            numLoop=0;
            total=0;
            reachability=UNKNOWNPOS;
            deadendmsg=0;

            WATCH(reachability);
            WATCH(numforward);

             positionFinished=new cMessage();

            globalTableFinished=new cMessage();
            readyToRoute=new cMessage();
            readyToRoutesec=new cMessage();
            startTime=simTime();
      //       std::cout<< myaddr<<": intialize, startTime: "<<startTime<<endl;

             scheduleAt(startTime+POSITION_FINISHED,positionFinished);
            scheduleAt(startTime+GLOBALTABLE_FINISHED,globalTableFinished);
            scheduleAt(startTime+READYTOROUTE,readyToRoute);

             par("IPstring").setStringValue(myaddr.str());
             par("X").setLongValue(X);
             par("Y").setLongValue(Y);

             std::string resultFileName=par("resultFileName");
             resultFileName+="_numforward_trueHit_deadendmsg_numLoop_notforme_notformer_total.csv";
             const char * resultFileNamechar=resultFileName.c_str();
             std::remove(resultFileNamechar);

             std::string resultFileName1=par("resultFileName");
            resultFileName1+="_neighborNo.csv";
            const char * resultFileNamechar1=resultFileName1.c_str();
            std::remove(resultFileNamechar1);


            msgNeighbor * neighbordisc=new msgNeighbor;
            neighbordisc->setSrcIP(myaddr);
            neighbordisc->setX(X);
            neighbordisc->setY(Y);
            broadcast(neighbordisc);

            numNodes=this->getParentModule()->getParentModule()->par("numFixHosts");
        }

}
void GPS::handleMessage(cMessage *msg){

   // std::cout<< myaddr<<": handleMessage" << endl;
    if( msgNeighbor* neidisc=dynamic_cast<msgNeighbor*>(msg)){
           std::cout<< myaddr<<": handleMessage, receive neighbordisc msg" << endl;

           handleNeighborDisc(neidisc);


           return ;
       }

    if(msg==positionFinished){
     //  std::cout<<myaddr<<", handleMessage,positionFinished msg, then update neighbor table"<<endl;
         updateNeighborTable();
        //  getGlobalTable();
      // neighborDisc();
         delete msg;
         return ;

    }

    //           resultFileName+="_neighborNo.csv";
    if(msg==globalTableFinished){
      //  std::cout<<myaddr<<", handleMessage,globalTableFinished msg, write to neighborTable.txt, then get global table"<<endl;

//           std::string resultFileName=par("resultFileName");
//           resultFileName+="_neighborNo.csv";
//          const char * resultFileNamechar=resultFileName.c_str();
//           std::ofstream fileio (resultFileNamechar,std::ios::app);
//
//
//          if (fileio.is_open())
//            {
//
//          //    std::cout << myaddr<<";"<<neighborTable.size()<<endl;
//
//              //std::cout << myaddr<<": resultFileNamechar: "<<resultFileNamechar<<endl;
//
//               fileio<< myaddr<<";"<<neighborTable.size()<<endl;
//
//
//               fileio.flush();
//               fileio.close();
//            }
//          else std::cout <<myaddr<< ", handleMessage, Unable to open file"<<endl;

        getGlobalTable();
        delete msg;
        return ;
    }

    /*
     * receive self message readyToRoute, create a msgRouting message and send it.
     */
    if (msg==readyToRoute){
       // std::cout<<myaddr<<", handleMessage,readyToRoute msg"<<endl;

        if(myaddr.getDByte(3)==1){
                IPv4Address srcip;
                srcip.set(145,236,0,1);

                      //  std::cout<<myaddr<<": handleMessage, readyToRoute msg, forward at time: "<<simTime()<<endl;

        #ifdef NODE160
                  int  randnum1;
                  IPv4Address destip;
                  NeighborTable::iterator glit;

                  std::cout << "send out 10 msgRouting msgs" <<endl;
                  int i=0;
                  while (i<=9){

        //             randnum1=rand()% 10 +1;
                     IPv4Address destip;
                     /*
                      * find 10 random destinations which are from from src
                      */
        //             destip.set(145,236,0,randnum1);
                     destip.set(145,236,0, numNodes);

                     glit= globalTable.find(destip);

                     if(glit==globalTable.end()){
                         continue;
                     }
                     msgRouting * msg=new msgRouting();
                     msg->setDestIP(glit->first);
                     msg->setDestPosition(glit->second);
                     msg->setSrcIP(myaddr);

                     pathTable pt;
                     pt.push_back(myaddr);
                     msg->setPath(pt);
                 //    std::cout<<myaddr<<": handleMessage, globalTableFinished msg, destIP: "<<msg->getDestIP()<<", in round: "<<i<<endl;
                     forward(msg,routeCal(glit->second));
                     numforward ++;
                     i++;
                  }
        }
    }

#endif


    /*
     * receive msgRouting message
     */
    if( msgRouting* msgrouting=dynamic_cast<msgRouting*>(msg)){
//        if(myaddr.getDByte(3)==3){
//            int stop=1;
//        }
//        if(myaddr.getDByte(3)==1){
//            int stop=1;
//        }
        std::cout << myaddr << "receives msgrouting message" << endl;
              handleRoutingmsg(msgrouting);
              return ;
      }
    else {
        std::cout<<myaddr<<", handleMessage,unknown msg, drop "<<endl;
        delete msg;
        return ;
    }
}


 void GPS::handleRoutingmsg(msgRouting * msg){
    // std::cout<<myaddr<<": handleRoutingmsg, "<<simTime()<<endl;
     total++;

        pathTable msgpath=msg->getPath();
        for(pathTable::iterator pathit=msgpath.begin();pathit!=msgpath.end();pathit++){
            if(*pathit==myaddr){
                  //std::cout<<myaddr<<": handleRoutingmsg, loop in msg, msg from ip:"<<msg->getSrcIP()<<endl;
                        //drop(msg);
                        numLoop++;
                       return;
                    }
        }
         Position destp=msg->getDestPosition();
         IPv4Address destip=msg->getDestIP();


      //   std::cout<<myaddr<<": handleRoutingmsg, dest ip:"<<destip<<endl;
      //   std::cout<<myaddr<<": handleRoutingmsg, src ip:"<<msg->getSrcIP()<<endl;

         if (destp==myposition){
             if(myaddr==destip){
                 trueHit++;

                // std::cout<<myaddr<<": handleRoutingmsg, true hit: "<<simTime()<<endl;
             }
             else{
                 falseHit++;
                 //longhistogram.collect(falseHit);
                 //outvector.record(falseHit);
                // std::cout<<myaddr<<": handleRoutingmsg, false hit: "<<simTime()<<endl;
             }
            delete msg;

         }
         else if (destp!=myposition){

             pathTable pt=msg->getPath();
             pt.push_back(myaddr);
             msg->setPath(pt);



             forward(msg,routeCal(destp));
             notformer++;
             if(myaddr==destip){
                       missed++;
                    //   longhistogram.collect(missed);
                    //   outvector.record(missed);
                  //     std::cout<<myaddr<<": handleRoutingmsg, missed: "<<simTime()<<endl;
                    }
             else{
                  notforme++;
             //     longhistogram.collect(notforme);
               //   outvector.record(notforme);

            //  std::cout<<myaddr<<": handleRoutingmsg, forwarded: "<<simTime()<<endl;

             }

         }
}

 void GPS::neighborDisc(){
     std::cout<<myaddr<<",neighborDisc,"<<endl;
     cTopology *topo=new cTopology;
   //   topo->extractByNedTypeName(cStringTokenizer("**.fixhost[*] **.router*").asVector());
     topo->extractByParameter("initialX");
   //  std::cout<<myaddr<<",neighborDisc, path of this node: "<<topo->getNode(1)->getModule()->getAncestorPar("initialX").info()<<endl;

     for (int i = 0; i < topo->getNumNodes(); i++) {

        double currentx;
        std::istringstream ssx(topo->getNode(i)->getModule()->getAncestorPar("initialX").info());
        ssx >> currentx;

        double currenty;
        std::istringstream ssy(topo->getNode(i)->getModule()->getAncestorPar("initialY").info());
        ssy >> currenty;
   //     std::cout<<"currentx: "<<currentx<<";"<<"currenty: "<<currenty<<endl;

        if((X-currentx)*(X-currentx)+(Y-currenty)*(Y-currenty)<=90000){
        }
     }


 }

void GPS::broadcast(cPacket *msg){
     IPv4Datagram *p= new IPv4Datagram();
           p->setSrcAddress(myaddr);
           p->setDestAddress(IPv4Address::ALLONES_ADDRESS);

           p->setTimeToLive(1);

           p->setTransportProtocol(IP_PROT_MANET);

           IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
           ipControlInfo->setProtocol(IP_PROT_MANET);
           ipControlInfo->setSrcAddr(myaddr);
           ipControlInfo->setDestAddr(IPv4Address::ALLONES_ADDRESS);
           ipControlInfo->setTimeToLive(1);

           p->setControlInfo(ipControlInfo);
           p->encapsulate(msg);
           float delay=exponential(1000e-3);

           sendDelayed(p,delay,"to_ip");


}
void GPS::handleNeighborDisc(msgNeighbor *msg){
    std::cout<< myaddr<<": handleNeighborDisc, from:"<<msg->getSrcIP()<<endl;
             const IPv4Address neighborAddr=msg->getSrcIP();

              Position position(msg->getX(),msg->getY());
                if(neighborAddr==myaddr)
                {

                 delete msg;
               //  std::cout<< myaddr<<": handleNeighborDisc"<<", msg ip:"<<neighborAddr<<",msg from my ip, drop msg, time: "<<simTime()<<endl;

                 return;
                 }

                else if (isEntryExisted(neighborAddr))// if it is in the hop 1 neighborhood
                {

               //     std::cout<< myaddr<<": handleNeighbor: no msg from myself, time: "<<simTime()<<endl;


                // Entry exists in hop 1 neighborhood, no update:
                   if(!isUpdate(neighborAddr,position)){

                    delete msg;

                //    std::cout<< myaddr<<": handleNeighborDisc"<<", msg ip:"<<neighborAddr<<", but no update, drop msg, time: "<<simTime()<<endl;

                    return;
                    }

                // Entry exists,  but need to be updated:
                    if(isUpdate(neighborAddr,position))
                    {
                    // delete old entry:
                 //    std::cout<< myaddr<<": handleNeighborDisc"<<", msg ip:"<<neighborAddr<<", update, time: "<<simTime()<<endl;
                     updateEntry(neighborAddr,position);
                     //displayNeighborTable();
                     delete msg;
                    return;
                     }
                // Entry does not exist:


              }

               else if (!isEntryExisted(neighborAddr))
               {
                  // std::cout<< myaddr<<": handleNeighborDisc"<<", msg ip:"<<neighborAddr<<", add new entry, X,Y:"<< position.X<<","<<position.Y<<", time: "<<simTime()<<endl;
                   addEntry(neighborAddr,position);
                   delete msg;
                   return;
                }



}
uint32_t GPS::getRoute(const Uint128 &, std::vector<Uint128> &){return 0;}

bool GPS::getNextHop(const Uint128 &, Uint128 &add, int &iface, double &cost){return false;}

void GPS::setRefreshRoute(const Uint128 &destination, const Uint128 & nextHop,bool isReverse){}

bool GPS::isProactive() {return false;}

bool GPS::isOurType(cPacket *){return false;}

bool GPS::getDestAddress(cPacket *, Uint128 &){return false;}

void GPS::getGlobalTable(){
       cTopology *topo=new cTopology;
        //topo->extractByNedTypeName(cStringTokenizer("**.host[*] **.router*").asVector());
        topo->extractByParameter("IPstring");

        //std::cout<<myaddr<<", getGlobalTable,number of node: "<<topo->getNumNodes()<<endl;
   //     std::cout<<myaddr<<", getGlobalTable, path of this node: "<<topo->getNodeFor(getParentModule())->getModule()->getFullPath()<<endl;


        for (int i = 0; i < topo->getNumNodes(); i++) {
          //  std::cout<<myaddr<<", getGlobalTable, path of this node module: "<<topo->getNode(i)->getModule()->getFullPath()<<endl;
            std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info();
            std::string newcurrentipstring;
            for(unsigned int j = 0; currentipstring[j] != '\0'; j++){
               if(currentipstring[j]=='\"') {
                 continue;
               }
               newcurrentipstring+=currentipstring[j];

             }
              // std::cout<<myaddr<<", getGlobalTable, new current ip as string  :"<<newcurrentipstring<<endl;
               IPv4Address currentip;
               currentip.set(newcurrentipstring.c_str());
             //  std::cout<<myaddr<<", getGlobalTable, new current ip as IPv4Address :"<<currentip<<endl;
               if (myaddr==currentip) {
                 //  std::cout<<myaddr<<", getGlobalTable, in loop, current i:"<<i<<", current node is my node"<<endl;
                     continue; // skip ourselves

               }
               int currentx;
               std::istringstream ssx(topo->getNode(i)->getModule()->getAncestorPar("X").info());
               ssx >> currentx;

               int currenty;
               std::istringstream ssy(topo->getNode(i)->getModule()->getAncestorPar("Y").info());
               ssy >> currenty;

              // std::cout<<myaddr<<", getGlobalTable, ssx as string:"<<ssx<<endl;
             //  std::cout<<myaddr<<", getGlobalTable, ssy as string:"<<ssy<<endl;

              // std::cout<<myaddr<<", getGlobalTable, currentx as int:"<<currentx<<endl;
             //  std::cout<<myaddr<<", getGlobalTable, currenty as int:"<<currenty<<endl;

               Position currentposition;
               currentposition.X=currentx;
               currentposition.Y=currenty;
               globalTable.insert(std::pair<IPv4Address,Position>(currentip,currentposition));

        }

 }

void GPS::addEntry(IPv4Address ip,Position position){
    neighborTable.insert(std::pair<IPv4Address,Position>(ip,position));

         updateNeighborRoute(ip);
         //std::cout<<myaddr<<": addEntry,"<< ip<<", time: "<<simTime()<<endl;
}

void GPS::updateEntry(IPv4Address ip,Position position){
    NeighborTable::iterator neit=neighborTable.find(ip);

         neighborTable.erase(neit);
        neighborTable.insert(std::pair<IPv4Address,Position >(ip,position));

}//
bool GPS::isEntryExisted (IPv4Address ip){
  // std::cout<< myaddr<< ": isEntryExisted" << endl;
         NeighborTable::iterator neit=neighborTable.find(ip);
       //  bool b=neit!=neighborTable.end();
      //   std::cout<< myaddr<< ": isEntryExisted, boolean:" << b<< endl;
         return neit!=neighborTable.end();
}//if the ip is existed in the table

bool GPS::isUpdate(IPv4Address ip,Position position){
    NeighborTable::iterator neit=neighborTable.find(ip);
    if (neit!=neighborTable.end())
      {  // std::cout<<myaddr<<": isUpdate, found ip entry in neighbor table"<<endl;
          Position  newposition =neit->second;

      //    std::cout<<myaddr<<": isUpdate, X of old position: "<<position.X<<", X of new position: "<<newposition.X<<endl;
     //     std::cout<<myaddr<<": isUpdate, Y of old position: "<<position.Y<<", Y of new position: "<<newposition.Y<<endl;
     //     std::cout<<myaddr<<": isUpdate, return value:"<<!(newposition==position)<<endl;
          return !!(newposition==position);

      }
      else
          return true;
}

void GPS::updateNeighborRoute(const IPv4Address& dst){
           IPv4Route* pathToDst=new IPv4Route();
            pathToDst->setDestination(dst);
            pathToDst->setNetmask(IPv4Address("255.255.255.255"));
            pathToDst->setGateway(dst);
            pathToDst->setInterface(routingTable->getInterfaceByAddress(myaddr));
            pathToDst->setSource(IPv4Route::MANET);
            routingTable->addRoute(pathToDst);
}

void GPS::updateNeighborTable(){
    msgNeighbor* neighborupdate=new msgNeighbor;
           neighborupdate->setSrcIP(myaddr);


           neighborupdate->setX(X);

           neighborupdate->setY(Y);


         //  std::cout<< myaddr<<": updateNeighborTable, set msgNeighborDisc W, at time:"<<simTime()<<endl ;
       //    forward(neighborupdate, neighborTable);
           broadcast(neighborupdate);
}

void GPS::displayNeighborTable(NeighborTable table){
    for (NeighborTable::iterator it=table.begin(); it!=table.end();it++){
           Position p=it->second;

           std::cout<< myaddr<<": displayNeighborTable, my own position is: "<<X<<","<<Y<<", current entry in neighbor table: IP"<<it->first<<", X: "<<p.X<<", Y: "<<p.Y<<endl;

        }
        std::cout<<endl;
}


NeighborTable GPS::routeCal(Position destp){
       int mindis=sqrt((X-destp.X)*(X-destp.X)+(Y-destp.Y)*(Y-destp.Y));
       int d=0;
       NeighborTable mindisTable;
       Position currentp;


       for(NeighborTable::iterator neit=neighborTable.begin();neit!=neighborTable.end();neit++){

           currentp=neit->second;
           d=sqrt((currentp.X-destp.X)*(currentp.X-destp.X)+(currentp.Y-destp.Y)*(currentp.Y-destp.Y));
         //  std::cout<<myaddr<<": routeCal, d:"<<d<<endl;

           if(d<mindis){
               mindis=d;
               mindisTable.clear();
               mindisTable.insert(std::pair<IPv4Address,Position>(neit->first,currentp));
              std::cout<<myaddr<<": routeCal, smaller disance found. forward to neighbor: "<<neit->first<<endl;
           }
           else if(d==mindis){
               NeighborTable::iterator neit2=mindisTable.begin();
                        //  std::cout<<myaddr<<": routeCal, equal disance found."<<endl;
                if(neit2==mindisTable.end()){
               mindisTable.insert(std::pair<IPv4Address,Position>(neit->first,currentp));
                      //     std::cout<<myaddr<<": routeCal, equal disance found. table is now empty, so insert"<<endl;
                          }

           }
           else if(d>mindis){
             // std::cout<<myaddr<<": routeCal, larger disance found. do nothing"<<endl;


           }


       }

       NeighborTable::iterator neit2=mindisTable.begin();
                              //  std::cout<<myaddr<<": routeCal, equal disance found."<<endl;
       if(neit2==mindisTable.end()){
           deadendmsg++;
      //     std::cout<<myaddr<<": routeCal, deadendmsg ++"<<endl;
       }

      // std::cout<<myaddr<<": routeCal,display mindisTable"<<endl;
      // displayNeighborTable(mindisTable);
       return mindisTable;


}
void GPS::forward(cPacket *msg,NeighborTable Table){
    int couter=0;

              for(NeighborTable::iterator neit=Table.begin();neit!=Table.end();neit++)
               {
                  IPv4Datagram *p= new IPv4Datagram();
                  p->setSrcAddress(myaddr);
                  p->setDestAddress(neit->first);
              //    std::cout<<myaddr<<": forward, the destination addr is set to :"<< neit->first<<endl;

                  p->setTimeToLive(1);


                  p->setTransportProtocol(IP_PROT_MANET);

                  IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
                  ipControlInfo->setProtocol(IP_PROT_MANET);
                  ipControlInfo->setSrcAddr(myaddr);
                  ipControlInfo->setTimeToLive(1);
                  ipControlInfo->setDestAddr(neit->first);

                  p->setControlInfo(ipControlInfo);
                 // std::cout<<myaddr<<": forward, couter: "<<couter<<endl;

                  if (couter>=1){
                  cPacket * newmsg=msg->dup();
                  p->encapsulate(newmsg);
               //   std::cout<<myaddr<<": forward, encapsulate duplicated msg "<<endl;
                  }
                  else{
                   p->encapsulate(msg);
                  }

                  float delay=exponential(1000e-3);
                  sendDelayed(p,delay,"to_ip");
                  std::cout<<myaddr<<": forward, msg forwarded to "<<p->getDestAddress()<<endl;
                  couter++;

               }
              if(couter==0){
                  delete msg;
              }
}

void GPS::finish(){
if(myaddr.getDByte(3)==numNodes){
    std::string resultFileName=par("resultFileName");
//          resultFileName+="_numforward_trueHit_deadendmsg_numLoop_notforme_notformer_total.csv";
         resultFileName+="_trueHit.csv";
          const char * resultFileNamechar=resultFileName.c_str();
          std::ofstream fileio (resultFileNamechar,std::ios::app);
          if (fileio.is_open())
         {
//            fileio<< myaddr<<";"<<numforward<<";"<<trueHit<<";"<<deadendmsg<<";"<<numLoop<<";"<<notforme<<";"<<notformer<<";"<<total<<endl;
          fileio<< trueHit<<endl;
            fileio.flush();
            fileio.close();
          }
}

  //  par("reachability").setLongValue(reachability);

//     displayNeighborTable(neighborTable);
   //  if (trueHit!=0||falseHit!=0||missed!=0||missed!=0||numforward!=0||notforme!=0){
  //    std::cout<<myaddr<<": finish, trueHit:"<<trueHit<<", falseHit:"<<falseHit<<", missed: "<<missed<<", notforme: "<<notforme<<", delete because of loop: "<<numLoop<<", total: "<<total<<", numForward:"<<numforward<<", reachability: "<<reachability<<endl;
     //    }
}
