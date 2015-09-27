#include "puMode.h"

#ifdef PU_CHA
#ifndef PRIMARYUSERREF_H_
#define PRIMARYUSERREF_H_
#endif
#include "Coord.h"
#define ON 1
#define OFF 0

class PrimaryUserRef{
public:
  double meantimeON;
  double meantimeOFF;
  int PUstatus;

  Coord puPosition;
  double puRange;
  double transitionM[2];//[0] is pOFF and [1] is pONON
  double timeframe;

  int  channel;//index

public:
   PrimaryUserRef();
   virtual  ~PrimaryUserRef();
   int getOnOffStatus();

   double getOnDuration();
   double getOffDuration();

};
#endif
