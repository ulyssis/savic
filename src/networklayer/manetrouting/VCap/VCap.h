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

#ifndef VCAP_H_
#define VCAP_H_
#include "puMode.h"

#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <map>
#include <fstream>
#include <Eigen/Dense>
#include "omnetpp.h"
#include "ManetRoutingBase.h"
#include "InterfaceTableAccess.h"

#include "PrimaryUser.h"

#include "msgNeighborDisc_m.h"

#include "msgW_m.h"
#include "msgToRoute_m.h"
#include "msgReq_m.h"
#include "ControlManetRouting_m.h"




#define INFINIYDIS 1000000
#define SAMECH 1
#define DIFFCH 0

#define NEIGHDISC_FINISH 500// neighbor discovery finished, next step:w generation
#define W_GENERATION_FINISH 1000//w is generated, next step: update neighbor table
#define W_UPDATE_FINISH 1500 //update neighbor table finished for W, next step: check neighbor table and request again for missing entry

#define X_ELECT 2000// neighbortable updated, next step: elect anchors X
#define X_GENERATION_FINISH 2500// elect anchors X finished, next step:update neighbor table
#define X_UPDATE_FINISH  3000//update neighbor table finished for X, next step: check neighbor table and request again for missing entry

#define Y_ELECT 3500 //update neighbor table finished, next step: elect anchor Y
#define Y_GENERATION_FINISH 4000// elect anchors Y finished, next step: update neighbor table
#define Y_UPDATE_FINISH  4500//update neighbor table finished for Y, next step: check neighbor table and request again for missing entry

#define Z_ELECT 5000// update neighbor table finished, next step: elect Z
#define Z_GENERATION_FINISH 5500// elect anchor z finished, next step: update neighbortable
#define Z_UPDATE_FINISH  6000//update neighbor table finished for Z, next step: check neighbor table and request again for missing entry

#ifdef MORE_AHCHOR_6
    #define X1_ELECT 6100
    #define X1_GENERATION_FINISH 6200

    #define X2_ELECT 6300
    #define X2_GENERATION_FINISH 6400
#endif

#define GLOBALTABLE_FINISHED 6500
#define READY_TO_ROUTE 7000

typedef std::tr1::unordered_map<IPv4Address,VCoord,hashIPv4Address> NeighborTable;

//transitionM for all neighbors
typedef std::tr1::unordered_map<IPv4Address,double,hashIPv4Address> LinkMetricTable;
typedef std::tr1::unordered_map<Coord,double,hashCoord>PUPositionTimeframe;
// transition matrice of all the influencing PUs
typedef std::list<PUMatrixPositionCH>InfluencingPUlist;
typedef std::pair<int,int*>ChannelNumberState;
typedef std::map<int, double>ChannelCondition;



class VCap : public ManetRoutingBase{

public:
        int numInitStages() const  {return 5;}
        void initialize(int stage);


        void handleMessage(cMessage *msg);

        void handleWMsg(msgW *msg); // handle the anchor message in all phases. anchor message in different phase is treated differently.
        void handleNeighborDisc(msgNeighborDisc *msg);
        void handleToRouteMsg(msgToRoute * msg);
        void generateW();// generate W coordinate for all nodes
        // elect X Y Z
        void electX();
        void electY();
        void electZ();
#ifdef MORE_AHCHOR_6
        void electX1();
        void electX2();
#endif
        //virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj);
       // bool equal(const msgNeighborDisc& a, const msgNeighborDisc& b);
        //forward msg to all node in NeighborTable
        virtual void forward(cPacket *msg,NeighborTable);
        //forward msg to ip
        virtual void forward(cPacket *msg,IPv4Address ip);
#ifdef CAVCAP
        virtual void forward(msgW * msgw,LinkMetricTable);

#endif
        void neighborDisc();
        virtual void broadcast(cPacket * msg);
      //  virtual void broadcast(cPacket * msg,NeighborTable);
        bool XYRule(double x, double y);
        // return a table of neighbor for forwarding according to destination virtual coordinate destvc
        NeighborTable routeCal(VCoord destvc, DeadendList deadendlist,PathList pathlist);
        void getGlobalTable();
#ifdef CAVCAP
        void MeanhopCal();
#endif
        virtual uint32_t getRoute(const Uint128 &, std::vector<Uint128> &);

        virtual bool getNextHop(const Uint128 &, Uint128 &add, int &iface, double &cost);

        virtual void setRefreshRoute(const Uint128 &destination, const Uint128 & nextHop,bool isReverse);

        virtual bool isProactive() ;

        virtual bool isOurType(cPacket *);

        virtual bool getDestAddress(cPacket *, Uint128 &);


        double getW();
        double getX();
        double getY();
        double getZ();
        double getX1();
        double getX2();

        void setW(double);
        void setX(double);
        void setY(double);
        void setZ(double);
        void setX1(double);
        void setX2(double);

        VCoord getMyvc();
        IPv4Address getMyaddr();
        PathList finalPathList; //destination node's this value is used.

#ifdef CAVCAP
       void displayPUlist(InfluencingPUlist list);

      void getTransitionM(InfluencingPUlist pulist);// calculate transition Matrix from the influencing PU list

      double linkMetricCal(PUMatrixPositionCH pu1, PUMatrixPositionCH pu2);
      bool equalMatrix(Eigen::MatrixXd, Eigen::MatrixXd);


#endif

#ifdef PU_CHA
public:
      static simsignal_t PUStartSignal;
#endif
public: int numforward;
        int numChannels;
        int hop;
        int nextHopAddr; // the last bit of IP. this value is useful in ChannelControl.cc
private:
        IRoutingTable* routingTable;

        IPv4Address myaddr;
        VCoord myvc;
        std::string mode;
        bool isW, isX,isY,isZ;
#ifdef MORE_AHCHOR_6
        bool isX1, isX2;
#endif
        bool isDeadend;
        // the node's own coordinate
        double W,X,Y,Z;
#ifdef MORE_AHCHOR_6
        double X1,X2;
#endif


        double yofachorx,xofanchory;

        double geoX;
        double geoY;
        // srcWmax and IPmax are used to controlthe min src W and max ip received at a node in pahse_x _y and _z
        // same for srcXmax and gamma
        double srcWmax;
        IPv4Address IPmax;

        double srcXmax;
        double gamma;   // gamma is used to facilitate vc generation, but Im not sure in which part.
#ifdef CAVCAP
        double meanhop;
#endif
       //number of msgToRoute sent by each node
        int total;
        int trueHit;
        int falseHit;
        int missed;
        int notforme;
        int numLoop;
        int deadendmsg;
        int selfmsg;

        int controlmanetroutingcounter;
        int totalMSG;


#ifdef PU_CHA
public:
        InfluencingPUlist puList;
        double ewt[10];
        void getEWT(InfluencingPUlist pulist); //calculate EWT from mean time on and off

        SimTime ewtinterval;

#ifdef MULTI_CHA
        ChannelCondition channelCondition;
#endif
private:
        PUPositionTimeframe puTimeframe;
#endif



#ifdef CAVCAP

        LinkMetricTable linkMetricTable;
      //  DTMMatrix transitionMatrix;


public:


        PUMatrixPositionCH  puMatrixPositionCh[10];
        double pioff[10] ;

#endif

        int VCnum;

        bool issrc;

        bool switchon;
        cMessage * neighborfinish;
         cMessage * generateWfinish;
         cMessage * checkWbegin;

         cMessage * electXbegin;
         cMessage * generateXfinish;
         cMessage * checkXbegin;

         cMessage * electYbegin;
         cMessage * generateYfinish;
         cMessage * checkYbegin;

         cMessage * electZbegin;
         cMessage * generateZfinish;
         cMessage * checkZbegin;

#ifdef MORE_AHCHOR_6
         cMessage * electX1begin;
         cMessage * generateX1finish;

         cMessage * electX2begin;
         cMessage * generateX2finish;
#endif
         cMessage * readyToRoute;
         cMessage * globalTableFinished;
#ifdef CAVCAP
         cMessage* calculategamma;
#endif
         SimTime startTime;



        NeighborTable neighborTable;
        NeighborTable globalTable;

public:
        // process NeighborEntry
         void addEntry(IPv4Address ip,VCoord vc);
         void updateEntry(IPv4Address ip,VCoord vc);//
#ifdef CAVCAP
         void addLink(IPv4Address ip,msgNeighborDisc * msg);
         void displayLinkMetricTable(LinkMetricTable linkmetrictable);

#endif
         bool isEntryExisted (IPv4Address ip);//if the ip is existed in the table
         bool isUpdate(IPv4Address ip,VCoord vc);
         void updateNeighborRoute(const IPv4Address& dst);
#ifdef MULTI_CHA

         double findEWTwithIP(IPv4Address ip, int channelno);
         double findPioffwithIP(IPv4Address ip, int channelno);
         ChannelNumberState checkChannelwithIP(IPv4Address ip );
#endif


         void updateNeighborTable();

         void displayDeadendList(DeadendList deadendlist);
         bool isInDeadendList(IPv4Address ip, DeadendList deadendlist);

         void displayPathList(PathList pathlist);
         bool isInPathList(IPv4Address ip, PathList pathlist);

         void displayNeighborTable(NeighborTable);
         void checkNeighborTable(int );
         virtual void finish();

public:

         VCap();
        virtual ~VCap();




};

#endif /* VCAP_H_ */
