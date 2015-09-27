// System includes:

// Omnet includes:

// INET includes:
#include "Coord.h"
#include "IMobility.h"
#include "IPv4Datagram.h"
#include "IPv4ControlInfo.h"
#include "ControlManetRouting_m.h"

// Berger includes:
#include "berger.h"
#include "BergerRouteRequest_m.h"

Define_Module(BERGER);

BERGER::posTable_t BERGER::posTable;

void BERGER::initialize(int stage)
{
	if(stage==4)
	{
		registerRoutingModule();
		registerPosition(); // We register for position information, but unfortunately we will not get up-to-date information before the first update :(

		// Determine position and IP:
		routingTable=check_and_cast<IRoutingTable*>(getParentModule()->getSubmodule("routingTable"));
		myAddr=routingTable->getRouterId();
		ev << "BERGER: My (" << myAddr << ") position: (" << getXPos() << "," << getYPos() << ")" << endl;
		// Broadcast position information to neighbors:
		BergerNeighborInfo* bni=new BergerNeighborInfo();
		bni->setRouterAddress(myAddr);
		bni->setRouterXPos(getXPos());
		bni->setRouterYPos(getYPos());
		doLocalBroadcast(bni);
	}
}

void BERGER::doLocalBroadcast(cPacket *pk)
{
	IPv4Datagram* p=new IPv4Datagram();
	p->setSrcAddress(myAddr);
	p->setDestAddress(IPv4Address::ALLONES_ADDRESS);
	p->setTimeToLive(1);
	p->setTransportProtocol(IP_PROT_MANET);
	IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
	ipControlInfo->setProtocol(IP_PROT_MANET);
	ipControlInfo->setSrcAddr(myAddr);
	ipControlInfo->setDestAddr(IPv4Address::ALLONES_ADDRESS);
	ipControlInfo->setTimeToLive(1);
	p->setControlInfo(ipControlInfo);
	p->encapsulate(pk);
	float delay=exponential(10e-3);
	sendDelayed(p,delay,"to_ip");
}

void BERGER::doGlobalBroadcast(cPacket *pk)
{
	IPv4Datagram* p=new IPv4Datagram();
	p->setSrcAddress(myAddr);
	p->setDestAddress(IPv4Address::ALLONES_ADDRESS);
	p->setTimeToLive(1);
	p->setTransportProtocol(IP_PROT_MANET);
	IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
	ipControlInfo->setProtocol(IP_PROT_MANET);
	ipControlInfo->setSrcAddr(myAddr);
	ipControlInfo->setDestAddr(IPv4Address::ALLONES_ADDRESS);
	ipControlInfo->setTimeToLive(1);
	ipControlInfo->setTransmitterPower(20);
	p->setControlInfo(ipControlInfo);
	p->encapsulate(pk);
	float delay=exponential(10e-3);
	sendDelayed(p,delay,"to_ip");
}

void BERGER::handleMessage(cMessage *msg)
{
	if(BergerNeighborInfo* bni=dynamic_cast<BergerNeighborInfo*>(msg))
	{
		const IPv4Address neighborAddr=bni->getRouterAddress();
		//printf("Berger: %s received message (%s,%f,%f)\n", myAddr.str().c_str(), neighborAddr.str().c_str(), bni->getRouterXPos(), bni->getRouterYPos());

		// from myself
		if(neighborAddr==myAddr)
		{
			ev << "BERGER: Discarding neighbor info from myself" << endl;
			delete bni;
			return;
		}

		nh_t::const_iterator it=neighborhood.find(neighborAddr);

		// Entry exists, no update:
		if(it!=neighborhood.end() && equal(*(*it).second,*bni))
		{
			ev << "BERGER: Entry already exists, discarding" << endl;
			delete bni;
			return;
		}

		// Entry exists, update:
		if(it!=neighborhood.end())
		{
			// delete old entry:
			delete (*it).second;
			// insert new entry:
			neighborhood[neighborAddr]=bni;
			// update local links:
			updateLocalLinks(neighborAddr,bni->getRouterXPos(),bni->getRouterYPos());
			return;
		}

		// Entry does not exist:
		neighborhood[neighborAddr]=bni;
		updateLocalLinks(neighborAddr,bni->getRouterXPos(),bni->getRouterYPos());
		return;
	}

	if(ControlManetRouting* control=dynamic_cast<ControlManetRouting*>(msg))
	{
		if (control->getOptionCode()==MANET_ROUTE_NOROUTE)
		{
			const IPv4Address src=control->getSrcAddress().toUint64()==IPv4Address::UNSPECIFIED_ADDRESS.getInt()?myAddr:IPv4Address(control->getSrcAddress().toUint64());
			const IPv4Address dst=IPv4Address(control->getDestAddress().toUint64());
			BergerRouteRequest* rreq=new BergerRouteRequest();
			rreq->setSrc(src);
			if(src==myAddr)
			{
				rreq->setSrcPos(Coord(getXPos(),getYPos()));
			}
			else
			{
				rreq->setSrcPos(Coord(posTable[src].x,posTable[src].y));
			}
			rreq->setDst(dst);
			rreq->setDstPos(Coord(posTable[dst].x,posTable[dst].y));
			ev << "BERGER: " << myAddr << ": sending rreq (" << rreq->getSrc() << "," << rreq->getDst() << ") at " << simTime() << "!" << endl;
			doGlobalBroadcast(rreq);
		}
		delete control;
		return;
	}

	if(BergerRouteRequest* rreq=dynamic_cast<BergerRouteRequest*>(msg))
	{
		ev << "BERGER: " << myAddr << ": got rreq (" << rreq->getSrc() << "," << rreq->getDst() << ") at " << simTime() << "!" << endl;
		const sdPairKey sdpk(rreq->getSrc(),rreq->getDst());
		const sdPairValue sdpv(rreq->getSrcPos(),rreq->getDstPos());
		sdPairs[sdpk]=sdpv;
		updateLocalLinks(BergerNodeInfo(rreq->getSrc(),rreq->getSrcPos().x,rreq->getSrcPos().y),
				         BergerNodeInfo(rreq->getDst(),rreq->getDstPos().x,rreq->getDstPos().y));
		delete rreq;
		return;
	}
}

void BERGER::positionUpdated(double x, double y)
{
	posTable[myAddr]=Coord(x,y);
}

void BERGER::updateLocalLinks(const IPv4Address& updatedNeighbor, double nbX, double nbY)
{
	ev << "BERGER: " << myAddr << " looks for better links through " << updatedNeighbor << endl;
	for(sdPairs_t::const_iterator sdPairsIt=sdPairs.begin();sdPairsIt!=sdPairs.end();++sdPairsIt)
	{
		double oldQuality=0;
		ll_t::const_iterator llIt=localLinks.find(sdPairsIt->first);
		if(llIt!=localLinks.end())
		{
			oldQuality=llIt->second.quality;
		}
		for(nh_t::const_iterator nhIt=neighborhood.begin();nhIt!=neighborhood.end();++nhIt)
		{
			const BergerNodeInfo src=BergerNodeInfo(sdPairsIt->first.src,sdPairsIt->second.srcPos.x,sdPairsIt->second.srcPos.y);
			const BergerNodeInfo dst=BergerNodeInfo(sdPairsIt->first.dst,sdPairsIt->second.dstPos.x,sdPairsIt->second.dstPos.y);
			const BergerNodeInfo oldNb=BergerNodeInfo(nhIt->second->getRouterAddress(),nhIt->second->getRouterXPos(),nhIt->second->getRouterYPos());
			const BergerNodeInfo newNb=BergerNodeInfo(updatedNeighbor, nbX, nbY);
			const BergerNodeInfo self=BergerNodeInfo(myAddr,getXPos(),getYPos());
			double newQuality=calculateLocalLinkQuality(src,oldNb,self,newNb,dst);
			if(newQuality>oldQuality)
			{
				ev << "BERGER: Updating local link: " << sdPairsIt->first.src << "<->" << nhIt->second->getRouterAddress() << "<->" << myAddr << "<->" << updatedNeighbor << "<->" << sdPairsIt->first.dst << endl;
				updateRoute(sdPairsIt->first.src,nhIt->second->getRouterAddress(),updatedNeighbor,sdPairsIt->first.dst,newQuality);
				oldQuality=newQuality;
			}
			newQuality=calculateLocalLinkQuality(src,newNb,self,oldNb,dst);
			if(newQuality>oldQuality)
			{
				ev << "BERGER: Updating local link: " << sdPairsIt->first.src << "<->" << updatedNeighbor << "<->" << myAddr << "<->" << nhIt->second->getRouterAddress() << "<->" << sdPairsIt->first.dst << endl;
				updateRoute(sdPairsIt->first.src,updatedNeighbor,nhIt->second->getRouterAddress(),sdPairsIt->first.dst,newQuality);
				oldQuality=newQuality;
			}
		}
	}
}

void BERGER::updateLocalLinks(const BergerNodeInfo& src, const BergerNodeInfo& dst)
{
	ev << "BERGER: " << myAddr << " looks for better links from " << src << " to " << dst << endl;
	double oldQuality=0;
	ll_t::const_iterator llIt=localLinks.find(sdPairKey(src.ip,dst.ip));
	if(llIt!=localLinks.end())
	{
		oldQuality=llIt->second.quality;
	}
	for(nh_t::const_iterator aIt=neighborhood.begin();aIt!=neighborhood.end();++aIt)
	{
		for(nh_t::const_iterator bIt=neighborhood.begin();bIt!=neighborhood.end();++bIt)
		{
			const BergerNodeInfo a=BergerNodeInfo(aIt->second->getRouterAddress(),aIt->second->getRouterXPos(),aIt->second->getRouterYPos());
			const BergerNodeInfo b=BergerNodeInfo(bIt->second->getRouterAddress(),bIt->second->getRouterXPos(),bIt->second->getRouterYPos());
			const BergerNodeInfo self=BergerNodeInfo(myAddr,getXPos(),getYPos());
			double newQuality=calculateLocalLinkQuality(src,a,self,b,dst);
			if(newQuality>oldQuality)
			{
				ev << "BERGER: Updating local link: " << src.ip << "<->" << aIt->second->getRouterAddress() << "<->" << myAddr << "<->" << bIt->second->getRouterAddress() << "<->" << dst.ip << endl;
				updateRoute(src.ip,aIt->second->getRouterAddress(),bIt->second->getRouterAddress(),dst.ip,newQuality);
				oldQuality=newQuality;
			}
		}
	}
}

void BERGER::updateRoute(const IPv4Address& src, const IPv4Address& a, const IPv4Address& b, const IPv4Address& dst, double quality)
{
	localLinks[sdPairKey(src,dst)]=LLValue(a,b,quality);

	// TODO: Remove old routes to src and dst

	// Add new routes:
	IPv4Route* pathToDst=new IPv4Route();
	pathToDst->setDestination(dst);
	pathToDst->setNetmask(IPv4Address("255.255.255.255"));
	pathToDst->setGateway(b);
	pathToDst->setInterface(routingTable->getInterfaceByAddress(myAddr));
	pathToDst->setSource(IPv4Route::MANET);
	pathToDst->setMetric(quality);
	routingTable->addRoute(pathToDst);

	IPv4Route* pathToSrc=new IPv4Route();
	pathToSrc->setDestination(src);
	pathToSrc->setNetmask(IPv4Address("255.255.255.255"));
	pathToSrc->setGateway(a);
	pathToSrc->setInterface(routingTable->getInterfaceByAddress(myAddr));
	pathToSrc->setSource(IPv4Route::MANET);
	pathToSrc->setMetric(quality);
	routingTable->addRoute(pathToSrc);
}

double BERGER::calculateLocalLinkQuality(const BergerNodeInfo& src, const BergerNodeInfo& a, const BergerNodeInfo& self, const BergerNodeInfo& b, const BergerNodeInfo& dst) const
{
	ev << "BERGER: Calculating quality for local link " << src << "<->" << a << "<->" << self << "<->" << b << "<->" << dst << endl;
	Coord srcC(src.x,src.y);
	Coord aC(a.x,a.y);
	Coord selfC(self.x,self.y);
	Coord bC(b.x,b.y);
	Coord dstC(dst.x,dst.y);
	double length=srcC.distance(aC)+aC.distance(selfC)+selfC.distance(bC)+bC.distance(dstC);
	ev << "BERGER: l=" << length << endl;
	return 1./length;
}

uint32_t BERGER::getRoute(const Uint128&, std::vector<Uint128>&)
{
	return 0;
}

bool BERGER::getNextHop(const Uint128&, Uint128&, int&, double&)
{
	return false;
}

void BERGER::setRefreshRoute(const Uint128&, const Uint128&, bool)
{
}

bool BERGER::isProactive()
{
	return false;
}

bool BERGER::isOurType(cPacket*)
{
	return false;
}

bool BERGER::getDestAddress(cPacket*, Uint128&)
{
	return false;
}


