#include "PrimaryUserRef.h"
#ifdef PU_CHA
#ifdef PRIMARYUSERREF_H_
 PrimaryUserRef::PrimaryUserRef(){
     meantimeON=0;
     meantimeOFF=0;
     PUstatus=OFF;
     channel=1;
     puPosition.x=0;
     puPosition.y=0;
     puRange=0;
     transitionM[0]=0;
     transitionM[1]=1;
     transitionM[2]=0;
     transitionM[3]=1;
     timeframe=3;

 }
 PrimaryUserRef::~PrimaryUserRef(){}
int PrimaryUserRef::getOnOffStatus(){

    double probOFF=meantimeOFF/(meantimeON+meantimeOFF);
               int X=rand()%100+1;
               double threshold =99*probOFF+1;
               std::cout<<"PrimaryUserRef::getOnOffStatus, threshold: "<< threshold<< endl;
               if(X>threshold){
                   std::cout<<"PrimaryUserRef::getOnOffStatus, current pu status ON"<< endl;
                   return ON;
               }
               else
               {
                   std::cout<<"PrimaryUserRef::getOnOffStatus, current pu status OFF"<< endl;
                   return OFF;

               }

}

double PrimaryUserRef::getOnDuration()
{
    SIM_API double result=exponential(meantimeON,0);
    std::cout<<"PrimaryUserRef::getOnDuration, meantimeON: "<<meantimeON<<", duration in status ON: "<<result<<endl;
    return result;
}
double PrimaryUserRef::getOffDuration()
{
    SIM_API double result=exponential(meantimeOFF,0);
    std::cout<<"PrimaryUserRef::getOffDuration, meantimeOFF: "<<meantimeOFF<<", duration in status ON: "<<result<<endl;
    return result;
}





#endif
#endif

