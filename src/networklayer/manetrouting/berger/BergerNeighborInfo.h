#pragma once

#define BNI_INCLUDESAFE

#include "BergerNeighborInfo_m.h"

bool equal(const BergerNeighborInfo& a, const BergerNeighborInfo& b);

struct hashIPv4Address
{
	size_t operator()(const IPv4Address& x) const
	{
		return x.getInt();
	}
};

