/*
 * msgNeighborDisc.h
 *
 *  Created on: Nov 28, 2012
 *      Author: lin
 */




struct hashIPv4Address
{
    size_t operator()(const IPv4Address& x) const
    {
        return x.getInt();
    }
};
