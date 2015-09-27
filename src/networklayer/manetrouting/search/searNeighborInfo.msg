cplusplus {{
#include "IPv4Address.h"
}}

class noncobject IPv4Address;

packet searNeighborInfo
{
	IPv4Address routerAddress;
	double routerXPos;
	double routerYPos;
	bool workingChannel; // 0: working on ch0    1: working on ch1

	int dist2Dst;
}

