cplusplus {{
#include "IPv4Address.h"
#include "Coord.h"
}}

class noncobject IPv4Address;
class noncobject Coord;

packet BergerRouteRequest
{
	IPv4Address src;
	IPv4Address dst;
	Coord srcPos;
	Coord dstPos;
}

