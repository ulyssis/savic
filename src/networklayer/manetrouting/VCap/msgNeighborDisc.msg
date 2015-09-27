//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

//
// TODO generated message class
//
cplusplus {{
#include <Eigen/Dense>
#include "Coord.h"
#include "IPv4Address.h"
#include "msgNeighborDisc.h"


}}

class noncobject IPv4Address;

class noncobject PUMatrixPositionCH;
class noncobject Coord;

packet msgNeighborDisc {
    
    IPv4Address srcIP;
    //srcW X Y Z
    double W=10000;
    double X=10000;
    double Y=10000;
    double Z=10000;
//MORE_AHCHOR_6
    double X1=10000;
 	double X2=10000;
//end
    PUMatrixPositionCH  puMatrixPositionCh [];



    double ewt [];
    double pioff [];
  
	
   // it is hop 1 neighbor or hop 2 neighbor
};
