#include "BergerNeighborInfo.h"

bool equal(const BergerNeighborInfo& a, const BergerNeighborInfo& b)
{
	return a.getRouterAddress()==b.getRouterAddress()
		&& a.getRouterXPos()==b.getRouterXPos()
		&& a.getRouterYPos()==b.getRouterYPos();
}

