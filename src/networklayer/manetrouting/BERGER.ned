//
//   Copyright (C) 2009 by Alfonso Ariza
//   Malaga University 
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

import inet.networklayer.manetrouting.base.BaseRouting;
import inet.networklayer.IManetRouting;


// 
// Ad hoc On-Demand Distance Vector (AODV) Routing (rfc3561)
//
// Implementation is based on rfc3561 draft 13 and implements 
// all features defined in the rfc except noted below:
//
// NOTE:
//  - The initialization of the routing component is done in stage=4
//  - Message lengths are calculated assuming IPv4 addresses 
// 
simple BERGER extends BaseRouting like IManetRouting
{
    parameters:
        @class(BERGER);
        @reactive;                             // IP module will send control messages when no route is present to the destination 
        bool PublicRoutingTables =default(false);
    gates:
        input from_ip;
        output to_ip;
}

