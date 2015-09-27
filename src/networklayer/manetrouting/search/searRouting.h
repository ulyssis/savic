#pragma once
//#include "SEARCH_ROUTING.h"


// System includes:
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <map>
#include <list>
#include <set>
#include <algorithm>

// Omnet includes:
#include "omnetpp.h"

// INET includes:
#include "ManetRoutingBase.h"
#include "ChannelControl.h"
#include "IInterfaceTable.h"
#include "InterfaceTableAccess.h"
//#include "IPv4.h"

// SEARCH includes:

#include "searNeighborInfo.h"
#include "searNeighborInfo_m.h"
#include "searRouteRequest_m.h"
#include "PrimaryUser.h"
#include "../VCap/msgNeighborDisc_m.h"
#include "../VCap/msgToRoute_m.h"
#include "../VCap/puMode.h"




typedef std::tr1::unordered_map<IPv4Address, searNeighborInfo*, hashIPv4Address> nh_t;

//transitionM for all neighbors
typedef std::tr1::unordered_map<IPv4Address,double,hashIPv4Address> LinkMetricTable;
typedef std::tr1::unordered_map<Coord,double,hashCoord>PUPositionTimeframe;
// transition matrice of all the influencing PUs
typedef std::list<PUMatrixPositionCH>InfluencingPUlist;
typedef std::pair<int,int*>ChannelNumberState; // first is current working channel, second is array of channel availability
typedef std::pair<int,int>ChannelNumberState_single; // in single channel case
typedef std::map<int, double>ChannelCondition;
typedef std::list<IPv4Address> PathList;
typedef std::set<IPv4Address> recordNodes;
typedef std::pair<PathList, PathList> pairofLists;
typedef std::list<int> Record_numHops;


class SEARCH : public ManetRoutingBase
{
	int numInitStages() const  {return 5;}
    virtual void handleMessage(cMessage *msg);
    void initialize(int stage);
    virtual uint32_t getRoute(const Uint128&, std::vector<Uint128>&);
    virtual bool getNextHop(const Uint128&, Uint128&, int&, double&);
    virtual void setRefreshRoute(const Uint128&, const Uint128&, bool);
    virtual bool isProactive();
    virtual bool isOurType(cPacket*);
    virtual bool getDestAddress(cPacket*, Uint128&);
	void doLocalBroadcast(cPacket *pk);
	void doGlobalBroadcast(cPacket *pk);
	void finish();
	int dist2dst; //number of hops to destination

	protected:
		virtual void positionUpdated(double x,double y);

	private:
		typedef std::tr1::unordered_map<int, pairofLists> focusOnChannel_t; // workingChannel, coCHnodesInFocus, coCHnodesOutFocus
		typedef std::tr1::unordered_map<int, IPv4Address> NextHop_ch_t; // first, second corresponds to channels

		IRoutingTable* routingTable;
		IPv4Address myAddr;
        IRoutingTable *rt;
		nh_t neighborhood, neighborhoodBackup;
        simtime_t time_updateNh;

        bool DP; //decision point or not.
        int workingChannel; // only be 0 and 1 which represents the channel index!
        int hops2Dst; // number of hops to dst
//        PathList coCHnodesInFocus; //co-channel neighbors in focus area
//        PathList coCHnodesOutFocus; //co-channel neighbors out of focus area
        recordNodes chosenNodes;
        recordNodes deadEnds;
        bool IamSrc;
        focusOnChannel_t focusOnChannel; // the focus sets on channel
        NextHop_ch_t NextHop_ch; // record the next hop on each channel
        int numNodes;


		struct sdPairKey
		{
			const IPv4Address src;
			const IPv4Address dst;

			sdPairKey(const IPv4Address& src, const IPv4Address& dst) : src(src), dst(dst) {}

			bool operator==(const sdPairKey& other) const
			{
				return other.src==src && other.dst==dst;
			}
		};

		struct hashSdPairKey
		{
			size_t operator()(const sdPairKey& x) const
			{
				return x.src.getInt()*2+x.dst.getInt();
			}
		};

		struct sdPairValue
		{
			Coord srcPos;
			Coord dstPos;

			sdPairValue(Coord& srcPos, Coord& dstPos) : srcPos(srcPos),dstPos(dstPos) {}
			sdPairValue() {}
		};

		typedef std::tr1::unordered_map<sdPairKey,sdPairValue,hashSdPairKey> sdPairs_t;

		sdPairs_t sdPairs;

		struct NodeInfo
		{
			const IPv4Address ip;
			const double x;
			const double y;
			NodeInfo(const IPv4Address& ip,double x,double y) : ip(ip),x(x),y(y) {}
		};

		double calculateLocalLinkQuality(const NodeInfo& src, const NodeInfo& a, const NodeInfo& self, const NodeInfo& b, const NodeInfo& dst) const;

		friend std::ostream& operator<<(std::ostream& os, const SEARCH::NodeInfo& b);

		struct LLValue
		{
			IPv4Address a;
			IPv4Address b;
			double quality;

			LLValue(const IPv4Address& a,const IPv4Address& b,double quality) : a(a),b(b),quality(quality) {}
			LLValue() {quality=-1;}
		};

		typedef std::tr1::unordered_map<sdPairKey,LLValue,hashSdPairKey> ll_t;

		ll_t localLinks;

		void updateRoute(const IPv4Address& src);


	public:
		SEARCH();
        virtual ~SEARCH();

		typedef std::tr1::unordered_map<IPv4Address,Coord,hashIPv4Address> posTable_t;
		bool checkFocusArea();
		IPv4Address decideNextHop(PathList& pathlist);
		void updateRoute(const IPv4Address& b, const IPv4Address& dst);
		void updateLocalLinks(const IPv4Address& updatedNeighbor, double nbX, double nbY);
		void updateLocalLinks(const NodeInfo& src, const NodeInfo& dst);
		void updateLocalLinks();
		void setNextHop();
	    static simsignal_t PUStartSignal;
        InfluencingPUlist puList;
        PUPositionTimeframe puTimeframe;
        void printAllNeighbors();
        bool InList(const IPv4Address& addr, PathList& pathlist);
#ifdef MULTI_CHA
        ChannelNumberState checkChannelwithIP(const IPv4Address& ip);
#endif
#ifndef MULTI_CHA
        ChannelNumberState_single checkChannelwithIP(const IPv4Address& ip);
#endif
        IPv4Address nextForward; // next hop for UDP transmission



	private:
		static posTable_t posTable;

};

//std::ostream& operator<<(std::ostream& os, const IPv4Address& b)
//    {
//    os << b.ip << "(" << b.x << "," << b.y << ")";
//    return os;
//    }

inline std::ostream& operator<<(std::ostream& os, const SEARCH::NodeInfo& b)
    {
	os << b.ip << "(" << b.x << "," << b.y << ")";
	return os;
    }

inline std::ostream& operator<<(std::ostream& os, const nh_t& nh)
    {
    for (nh_t::const_iterator cIt = nh.begin(); cIt!= nh.end(); ++cIt)
        {
        os << cIt->first.getDByte(3) << " ";
        }
    os << endl;
    return os;
    }

inline std::ostream& operator<<(std::ostream& os, const PathList& PL)
    {
    for (PathList::const_iterator it=PL.begin(); it!=PL.end(); ++it)
        {
        os << (*it).getDByte(3) << " ";
        }
    os << endl;
    return os;
    }
