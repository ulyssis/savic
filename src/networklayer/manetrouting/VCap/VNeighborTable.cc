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

#include "VNeighborTable.h"




VNeighborTable::VNeighborTable() {
    // TODO Auto-generated constructor stub

}

VNeighborTable::~VNeighborTable() {
    // TODO Auto-generated destructor stub
}
 void VNeighborTable::addEntry(IPv4Address ip,int w,int x,int y,int z,int hop){
     VCoordHop vcp;
     vcp.push_back(w);vcp.push_back(x);
     vcp.push_back(y);vcp.push_back(z);
     neighborEntry.insert(std::pair<IPv4Address,std::vector<int,std::allocator<int> > >(ip,vcp));

 }
 void VNeighborTable::updateEntry(IPv4Address ip,int w,int x,int y,int z,int hop){
     NeighborEntry::iterator neit=neighborEntry.find(ip);

     neighborEntry.erase(neit);
     VNeighborTable::addEntry(ip,w,x,y,z,hop);
 }

 //if the ip is existed in the table
 bool VNeighborTable::isEntryExisted (IPv4Address ip){
     NeighborEntry::iterator neit=neighborEntry.find(ip);
     return neit!=neighborEntry.end();
 }
/*
VCoordHop  VNeighborTable::getNeighborEntry(IPv4Address ip){
    NeighborEntry::iterator neit=neighborEntry.find(ip);
    return neit->second;

}*/
bool VNeighborTable::equal(NeighborEntry a, NeighborEntry b){

   return a==b;

}


bool VNeighborTable::isUpdate(IPv4Address ip,int w,int x,int y,int z,int hop){
/*
   NeighborEntry::iterator neit=neighborEntry.find(ip);
   if (neit!=neighborEntry.end())
   {
       VCoordHop  vcp =getNeighborEntry(ip);
       return !( (vcp[0]==w) && (x==vcp[1]) && (y==vcp[2]) && (z=vcp[3]) && (hop==vcp[4]));

   }
   else return true;
   return true;
*/
    return false;
}
