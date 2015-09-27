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

#ifndef VNEIGHBORTABLE_H_
#define VNEIGHBORTABLE_H_

#include "IMobility.h"
#include "IPv4Datagram.h"
#include "IPv4ControlInfo.h"
#include "RoutingTable.h"

typedef std::vector<int> VCoordHop;// coordinate WXYZ and the hop of neighbor
typedef std::map<IPv4Address,VCoordHop> NeighborEntry ;

class VNeighborTable {
public:
    VNeighborTable();

    virtual ~VNeighborTable();

protected :
    //basic negihbor entry




       // in hop1 neighborhood or in hop2 neighborhood

     // for categroy entries into hop 1 and hop 2 neighbors

      int neighborhood12;
      NeighborEntry neighborEntry;



public:

     // process NeighborEntry
     void addEntry(IPv4Address ip,int w,int x,int y,int z,int hop);
     void updateEntry(IPv4Address ip,int w,int x,int y,int z,int hop);//
     bool isEntryExisted (IPv4Address);//if the ip is existed in the table

     //VCoordHop  getNeighborEntry(IPv4Address);//
     bool equal(NeighborEntry,NeighborEntry);
     bool isUpdate(IPv4Address,int,int,int,int,int);


};

#endif /* VNEIGHBORTABLE_H_ */
