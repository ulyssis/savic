



#include <tr1/unordered_map>
#include <fstream>

// Omnet includes:
#include "omnetpp.h"
//inet include
#include "ManetRoutingBase.h"

#include "msgNeighbor.h"
#include "msgNeighbor_m.h"
#include "msgRouting_m.h"


#define UNKNOWNPOS 10000

#define POSITION_FINISHED 500
#define GLOBALTABLE_FINISHED 1500
#define READYTOROUTE 2000
#define READYTOROUTE_SEC 2500


typedef std::tr1::unordered_map<IPv4Address,Position,hashIPv4Address> NeighborTable ;

class GPS : public ManetRoutingBase
{
public:

    int numInitStages() const  {return 5;}
    void initialize(int stage);
    void handleMessage(cMessage *msg);

    void neighborDisc();
    void broadcast(cPacket* msg);
    void handleNeighborDisc(msgNeighbor *msg);
    void handleRoutingmsg(msgRouting * msg);
    virtual void forward(cPacket *msg,NeighborTable);
    NeighborTable routeCal(Position);

   // void send(IPv4Address destIP,Position destP);
    void getGlobalTable();
    virtual uint32_t getRoute(const Uint128 &, std::vector<Uint128> &);

           virtual bool getNextHop(const Uint128 &, Uint128 &add, int &iface, double &cost);

           virtual void setRefreshRoute(const Uint128 &destination, const Uint128 & nextHop,bool isReverse);

           virtual bool isProactive() ;

           virtual bool isOurType(cPacket *);

           virtual bool getDestAddress(cPacket *, Uint128 &);

private:
    IPv4Address myaddr;
    IRoutingTable* routingTable;
    Position myposition;
    int X;
    int Y;
    SimTime startTime;
    NeighborTable neighborTable;
    NeighborTable globalTable;
    int trueHit;
    int falseHit;
    int missed;
    int notforme;
    int notformer;
    int numforward;
    int numLoop;
    int total;
    int reachability;
     int neighborTableSize;

     int deadendmsg;
     int numNodes;


     cMessage * positionFinished;

    cMessage * globalTableFinished;
    cMessage * readyToRoute;
    cMessage * readyToRoutesec;




public:
        // process NeighborEntry
         void addEntry(IPv4Address ip,Position position);
         void updateEntry(IPv4Address ip,Position position);//
         bool isEntryExisted (IPv4Address ip);//if the ip is existed in the table
         bool isUpdate(IPv4Address ip,Position position);
         void updateNeighborRoute(const IPv4Address& dst);

         void updateNeighborTable();

         void displayNeighborTable(NeighborTable neighbortable);
         void finish();
};
