// Di: new class searRouteRequest extends the class IPv4Address and Coord.

cplusplus {{
#include "IPv4Address.h"
#include "Coord.h"
#include "searRouting.h"
#include <list>
}}

class noncobject IPv4Address;
class noncobject Coord;
class noncobject PathList;

packet SearRouteRequest
{
	IPv4Address src;
	IPv4Address dst;
	Coord srcPos;
	Coord dstPos;
	bool workingChannel; //0:ch0 or 1:ch1
	PathList pathList;
	PathList DPList;
}

