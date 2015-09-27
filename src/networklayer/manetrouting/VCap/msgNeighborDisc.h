/*
 * msgNeighborDisc.h
 *
 *  Created on: Nov 28, 2012
 *      Author: lin
 */



typedef Eigen::Matrix<double,Eigen::Dynamic, Eigen::Dynamic> DTMMatrix;
struct hashIPv4Address
{
    size_t operator()(const IPv4Address& x) const
    {
        return x.getInt();
    }
};
struct hashCoord
{
    size_t operator()(const Coord& x) const
    {
            return x.x;
    }
};
class PUMatrixPositionCH
{

public:
    Coord position;// if composed, then the position will be the middle point
    DTMMatrix dtmmatrix;
    int channel;
    PUMatrixPositionCH () : position(0,0,0), channel (10000){};

};
