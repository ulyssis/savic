#include "searNeighborInfo.h"

bool equal(const searNeighborInfo& a, const searNeighborInfo& b)
{
	return a.getRouterAddress()==b.getRouterAddress()
		&& a.getRouterXPos()==b.getRouterXPos()
		&& a.getRouterYPos()==b.getRouterYPos()
		&& a.getWorkingChannel() == b.getWorkingChannel();
}

