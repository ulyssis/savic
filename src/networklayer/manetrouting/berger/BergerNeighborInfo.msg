cplusplus {{
#include "IPv4Address.h"
}}

class noncobject IPv4Address;

packet BergerNeighborInfo
{
	IPv4Address routerAddress;
	double routerXPos;
	double routerYPos;
}

