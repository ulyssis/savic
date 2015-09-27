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

cplusplus {{
#include "IPv4Address.h"
#include <vector>
typedef std::vector<IPv4Address> pathTable;
#define PHASE_NULL 0
#define PHASE_W 1
#define PHASE_X 2
#define PHASE_Y 3
#define PHASE_Z 4
#define PHASE_X1 5
#define PHASE_X2 6


}}

class noncobject IPv4Address;
class noncobject pathTable;

packet msgW {
   int phase=PHASE_NULL; 
   pathTable path;
   IPv4Address srcIP;
   double srcW; 
   double srcX;

   double hop=0;

   
  // bool isTimerCheck=false;
    
};
