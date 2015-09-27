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

/*
 * PrimaryUser is the primary in the certain area ,
 * it controls the channel in a certain radio range
 * functions inherited from ChannelControl should be overload,
 * so that they worked only with in the given range
 * */

#include "puMode.h"


#ifdef PU_CHA

#ifndef PRIMARYUSER_H_
#define PRIMARYUSER_H_

#include "INETDefs.h"
#include "omnetpp.h"
#include "ChannelAccess.h"
#include "IMobility.h"
#include "VCap.h"


#include "Coord.h"
#define ON 1
#define OFF 0



class INET_API PrimaryUser: public cSimpleModule , public cListener{


  public:

    PrimaryUserRef puRef;


  private:
    cMessage* ONtimeout; //means: when time is out, the state is ON.
    cMessage* OFFtimeout; //means: when time is out, the state is OFF.
    cRNG * randomnumberger;

public:
    PrimaryUser();
    virtual ~PrimaryUser();
    void initialize(int stage);
    static IChannelControl * getGlobalChannelControl();
    void handleMessage(cMessage * msg);
    void receiveSignal (cComponent *source, simsignal_t signalID, long l);

#ifdef CTM
    SimTime getOnDuration();
    SimTime getOffDuration();
    int  ctm(int lastStatus);
#endif


    SimTime timeframe;
    int dtm (int lastStatus);
    void setChannel(int newchannel);

//protected:
  //  virtual void arrived(cMessage *msg, cGate *ongate, simtime_t t) = 0;

};

#endif
#endif /* PRIMARYUSER_H_ */

