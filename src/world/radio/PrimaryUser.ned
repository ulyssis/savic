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
import inet.mobility.IMobility;
package inet.world.radio;
simple PrimaryUser{
	parameters:
	   
       double meanTimeON @unit("ms")=default(100ms);
       double meanTimeOFF @unit("ms")=default(100ms);  
     
       double positionX @unit("m")=default(0m);
       double positionY @unit("m")=default(0m);
      
       double puRange @unit("m")=default(100m);
       int Channel=default(0);
       string PUstatus @enum("ON","OFF")=default("OFF");
       double timeframe=default(0.1);
       double pONON=default(0);
       double pOFFOFF=default(1);
   //    string mobilityType = default("StationaryMobility");
        @display("i=misc/sun");
        @labels(node);
   
}