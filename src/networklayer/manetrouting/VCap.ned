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

package inet.networklayer.manetrouting;

// numOfHosts: 10
// parametric: true
// static:     false

import inet.networklayer.manetrouting.base.BaseRouting;
import inet.networklayer.IManetRouting;


simple VCap extends BaseRouting like IManetRouting
{
    parameters:
        @class(VCap);
        @reactive;                            // IP module will send control messages when no route is present to the destination 
        bool PublicRoutingTables =default(false);
        bool isW=default(false);
        bool isX=default(false);
        bool isY=default(false);
        bool isZ=default(false);
        bool isX1=default(false);
        bool isX2=default(false);
        
        string IPstring=default("0.0.0.0");
        double W=default(10000);
        double X=default(10000);
        double Y=default(10000);
        double Z=default(10000);
		double X1=default(10000);
		double X2=default(10000);
		
        int VCaplocalforward=default(0);
      	double meanhop=default(1.0);
        string resultFileName=default("null");
//        int srcID=default(0);
//        int destID=default(0);
        string puposition=default("null");
//        double ewtinterval=default(3);
      	double ewt=default(1.0);
      	double pioff=default(1.0);
      	int hop=default(0);
      	int nextHopAddrInt=default(0);
    gates:
        input from_ip;
        output to_ip;
}