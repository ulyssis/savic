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


#include "IPv4Datagram.h"
#include "IPv4ControlInfo.h"


#include "VCap.h"
#include "Radio.h"


Define_Module(VCap);

#ifdef PU_CHA
simsignal_t VCap::PUStartSignal = SIMSIGNAL_NULL;
#endif

VCap::VCap()
{
    // TODO Auto-generated constructor stub
}

VCap::~VCap()
{
    // TODO Auto-generated destructor stub
}



void VCap::initialize(int stage)
{

    if (stage==4){

        registerRoutingModule();
        registerPosition();
        routingTable=check_and_cast<IRoutingTable*>(getParentModule()->getSubmodule("routingTable"));
        myaddr=routingTable->getRouterId();
        par("IPstring").setStringValue(myaddr.str());
        geoX=getXPos();
        geoY=getYPos();

        numChannels=this->getParentModule()->getParentModule()->getModuleByRelativePath("channelControl")->par("numChannels");
     //   std::cout<<myaddr<<", ini, numchannels: "<<numChannels<<endl;
        isW=par("isW");
        isX=par("isX");
        isY=par("isY");
        isZ=par("isZ");
#ifdef     MORE_AHCHOR_6
        isX1=par("isX1");
        isX2=par("isX2");
#endif
        isDeadend=false;
        setW(INFINIYDIS);
        setX(INFINIYDIS);
        setY(INFINIYDIS);
        setZ(INFINIYDIS);
#ifdef     MORE_AHCHOR_6
        setX1(INFINIYDIS);
        setX2(INFINIYDIS);
#endif
        numforward=0;
        total=0;
        trueHit=0;
        falseHit=0;
        missed=0;
        notforme=0;
        numLoop=0;
        totalMSG=0;
        deadendmsg=0;
        selfmsg=0;
        controlmanetroutingcounter=0;
        hop=0;

        VCnum=INFINIYDIS;

        switchon=true;
        issrc=false;
        WATCH(trueHit);

        WATCH(issrc);
        WATCH(switchon);
        WATCH(VCnum);
        WATCH(totalMSG);
        neighborfinish=new cMessage();
        generateWfinish=new cMessage();
        checkWbegin=new cMessage();

        electXbegin=new cMessage();
        generateXfinish=new cMessage();
        checkXbegin=new cMessage();

        electYbegin=new cMessage();
        generateYfinish=new cMessage();
        checkYbegin=new cMessage();

        electZbegin=new cMessage();
        generateZfinish=new cMessage();
        checkZbegin=new cMessage();

#ifdef MORE_AHCHOR_6
        electX1begin=new cMessage();
        generateX1finish=new cMessage();
//        checkX1begin=new cMessage();

        electX2begin=new cMessage();
        generateX2finish=new cMessage();
//        checkX2begin=new cMessage();
#endif



        readyToRoute=new cMessage();
        globalTableFinished=new cMessage();
#ifdef CAVCAP
        calculategamma=new cMessage();
#endif
        std::string resultFileName=par("resultFileName");

#ifndef CAVCAP
        mode+="_VCAP";
#endif
#ifdef EWT
        mode+="_EWT";
#endif
#ifdef DTM
        mode+="_pi";
#endif
        std::string resultFileReachability=resultFileName+mode+"_numforward_localforward_trueHit_falseHit_missed_notforme_numLoop_deadendmsg_selfmsg_total.csv";
        const char * resultFileReachabilitychar=resultFileReachability.c_str();
        remove(resultFileReachabilitychar);
        //std::cout<<resultFileReachabilitychar<<endl;

        std::string resultFileVC=resultFileName+mode+"_W_X_Y_Z_geoX_geoY.csv";
        const char * resultFileVCchar=resultFileVC.c_str();
        remove(resultFileVCchar);
        //std::cout<<resultFileVCchar<<endl;

        std::string resultFilePU=resultFileName+mode+"_PUlist.csv";
        const char * resultFilePUchar=resultFilePU.c_str();
        remove(resultFilePUchar);

        std::string resultFileTime=resultFileName+mode+"_Alltime.csv";
               const char * resultFileTimechar=resultFileTime.c_str();
               remove(resultFileTimechar);


       std::string resultFile_delay=resultFileName+mode+"_delay_hops_path.csv";
         const char * resultFile_delaychar=resultFile_delay.c_str();
         remove(resultFile_delaychar);

         std::string resultFile_UDPpktRecord=resultFileName+mode+"_UDPpktRecord.csv";
           const char * resultFile_UDPpktRecordchar=resultFile_UDPpktRecord.c_str();
           remove(resultFile_UDPpktRecordchar);


//         std::string resultFile_numReceived=resultFileName+mode+"_numReceived.csv";
//               const char * resultFile_numReceivedchar=resultFile_numReceived.c_str();
//               remove(resultFile_numReceivedchar);

               std::string resultFile_Truehit=resultFileName+mode+"_Truehit.csv";
                     const char * resultFile_Truehitchar=resultFile_Truehit.c_str();
                     remove(resultFile_Truehitchar);

                     std::string resultFile_neighbourList=resultFileName+mode+"_neighbourList.csv";
                           const char * resultFile_neighbourListchar=resultFile_neighbourList.c_str();
                           remove(resultFile_neighbourListchar);

                           std::string resultFile_anchorList=resultFileName+mode+"_anchorList.csv";
                                 const char * resultFile_anchorListchar=resultFile_anchorList.c_str();
                                 remove(resultFile_anchorListchar);

#ifdef PU_CHA
        if(isW)
        {
            PUStartSignal=registerSignal("puStartSignal");
            //FIXME only two PUModule is subscribed
            int PUno=getParentModule()->getParentModule()->par("numPU");
            std::cout<<"No of PU: "<<PUno<<endl;
            for(int i=0;i<PUno;i++)
            {   std::string puname="pu[";
            std::stringstream ss;
            ss << i;
            std::string stringi = ss.str();
            puname.append(stringi);
            puname.append("]");
            //  std::cout<<myaddr<<", ini, current PU: "<<getParentModule()->getParentModule()->getModuleByRelativePath(puname.c_str())->getFullPath()<<endl;
            PrimaryUser* PUModule;
            PUModule=check_and_cast<PrimaryUser*>(getParentModule()->getParentModule()->getModuleByRelativePath(puname.c_str()));
            subscribe(PUStartSignal,PUModule);
           // std::cout<<"subscribed"<<endl;
            }
        }


        Radio * myRadio=check_and_cast<Radio*>(getParentModule()->getModuleByRelativePath(".wlan[0].radio"));

        PUlist::iterator pulistit;

        for (pulistit=myRadio->myRadioRef->influencePUlist.begin();pulistit!=myRadio->myRadioRef->influencePUlist.end();pulistit++)
        {
            DTMMatrix tranmatrix;
            tranmatrix.resize(2,2);
            tranmatrix(0,0)=pulistit->transitionM[0];
            tranmatrix(0,1)=1-pulistit->transitionM[0];
            tranmatrix(1,0)=1-pulistit->transitionM[1];
            tranmatrix(1,1)=pulistit->transitionM[1];

            PUMatrixPositionCH puMatrixPositionCh;
            puMatrixPositionCh.dtmmatrix=tranmatrix;
            puMatrixPositionCh.position=pulistit->puPosition;
            puMatrixPositionCh.channel=pulistit->channel;

            puList.push_back(puMatrixPositionCh);
            std::cout<<myaddr<<":: ini, time frame: "<<pulistit->timeframe<<endl;
            puTimeframe.insert(std::pair<Coord,double>(puMatrixPositionCh.position,pulistit->timeframe));
        }

#endif



        startTime=simTime();
        //  std::cout<< myaddr<<": intialize, startTime: "<<startTime<<endl;
        scheduleAt(startTime+NEIGHDISC_FINISH,neighborfinish);
#ifdef CAVCAP
        scheduleAt(startTime+NEIGHDISC_FINISH+5,calculategamma);
#endif
        scheduleAt(startTime+W_GENERATION_FINISH,generateWfinish);
        //scheduleAt(startTime+W_UPDATE_FINISH,checkWbegin);


        scheduleAt(startTime+X_ELECT,electXbegin);
        scheduleAt(startTime+X_GENERATION_FINISH,generateXfinish);
        //  scheduleAt(startTime+X_UPDATE_FINISH,checkXbegin);

        scheduleAt(startTime+Y_ELECT,electYbegin);
        scheduleAt(startTime+Y_GENERATION_FINISH,generateYfinish);
        //  scheduleAt(startTime+Y_UPDATE_FINISH,checkYbegin);

        scheduleAt(startTime+Z_ELECT,electZbegin);
        scheduleAt(startTime+Z_GENERATION_FINISH,generateZfinish);
           scheduleAt(startTime+Z_UPDATE_FINISH,checkZbegin);

#ifdef MORE_AHCHOR_6
        scheduleAt(startTime+X1_ELECT,electX1begin);
        scheduleAt(startTime+X1_GENERATION_FINISH,generateX1finish);

        scheduleAt(startTime+X2_ELECT,electX2begin);
        scheduleAt(startTime+X2_GENERATION_FINISH,generateX2finish);
#endif


        scheduleAt(startTime+GLOBALTABLE_FINISHED,globalTableFinished);
        scheduleAt(startTime+READY_TO_ROUTE,readyToRoute);



        msgNeighborDisc * neidiscmsg=new msgNeighborDisc();
        neidiscmsg->setSrcIP(myaddr);
        std::cout<<myaddr<< ", in initialize stage 4" << endl;
#ifdef PU_CHA
        /*
         * in initialization phase, ewt is obtained, but PUs are not active until PUstateChangedSignal is sent
         */
        getEWT(puList);
         par("ewt").setDoubleValue(ewt[0]);
//         double xxx =par("ewt").doubleValue();
#endif
#ifdef CAVCAP
        meanhop=0.0;

        //  puMatrixPositionCh={};
     //   getEWT(puList);
       // par("ewt").setDoubleValue(ewt[0]);
        //    std::cout<<myaddr<<", puMatrixPosition position x:"<<puMatrixPositionCh.position.x<<", position y: "<<puMatrixPositionCh.position.y<<endl;
        std::cout<<myaddr<<", VCap, initialize, getEWT finished: "<<endl;



        getTransitionM(puList);

        std::cout<<myaddr<<", VCap, initialize, ewt got from getEWT: "<<endl;

        neidiscmsg->setEwtArraySize(numChannels);
        neidiscmsg->setPioffArraySize(numChannels);
        neidiscmsg->setPuMatrixPositionChArraySize(numChannels);

        /*   cXMLElement ewtxml=new cXMLElement("ewt",this);
       // cXMLElement* ewtxml=par("ewt").xmlValue();
       // ewtxml->setNodeValue("ewt",numChannels);
        cXMLElement* pioffxml=par("pioff").xmlValue();
        pioffxml->setNodeValue("pioff",numChannels);
         */
        for(int i=0;i<numChannels;i++)
        {
            neidiscmsg->setEwt(i,ewt[i]);
            neidiscmsg->setPuMatrixPositionCh(i,puMatrixPositionCh[i]);
            neidiscmsg->setPioff(i,pioff[i]);

            std::ostringstream strindex;
            strindex << i;
            std::string stringindex = strindex.str();

            std::ostringstream strewt;
            strewt << ewt[i];
            std::string stringewt = strewt.str();

            std::ostringstream strpioff;
            strpioff << pioff[i];
            std::string stringpioff = strpioff.str();

            //      ewtxml->setAttribute(stringindex.c_str(),stringewt.c_str());
            //     pioffxml->setAttribute(stringindex.c_str(),stringpioff.c_str());
        }
        //    par("ewt").setXMLValue(ewtxml);
        //  par("pioff").setXMLValue(pioffxml);

        // std::cout<<myaddr<<", initialize, pioff:"<<pioff<<endl;



#endif
        //neighborDisc(neidiscmsg,HOP1_NEIGHBOR);//discover hop 1 neighbor

        broadcast(neidiscmsg);
    }

//    // tried to generate random destID and srcID only once,
//    if(myaddr.getDByte(3)==1){
//        int numNode=getParentModule()->getParentModule()->par("numFixHosts").longValue();
//
//        long a = rand() % 10;
//        long b = rand() % 10 + numNode -10;
//
//        // set the id of src
////        this->getParentModule()->getParentModule()->getParentModule()->par("a").setLongValue(a);
//        getParentModule()->getParentModule()->par("a").setLongValue(a);
//        // set the id of src
//        getParentModule()->getParentModule()->par("b").setLongValue(b);
//    }

}
#ifdef PU_CHA
void VCap::getEWT(InfluencingPUlist pulist)
{
    InfluencingPUlist::iterator pulistit;
    for(int i=0;i<10;i++)
    {
        if(i<numChannels)
        {
            ewt[i]=0.0;
            continue;
        }

        ewt[i]=10000.0;
    }


    for(pulistit=puList.begin();pulistit!=puList.end();pulistit++)
    {
        int currentchannel=pulistit->channel;
        std::cout<<myaddr<<" , getEWT() current channel: "<<currentchannel<<endl;
        DTMMatrix tm=(*pulistit).dtmmatrix;
        double ponon=tm(1,1);
        double ponoff=tm(1,0);
        PUPositionTimeframe::iterator timeframeit=puTimeframe.find((*pulistit).position);
        double currentewt=(timeframeit->second)*(ponon/ponoff);
       // double currentewt=(timeframeit->second)*(ponoff/((1.0-ponon)*(1.0-ponon)));
        // double currentewt=ponoff/((1.0-ponon)*(1.0-ponon));
        //   std::cout<<myaddr<<" , getEWT() currentewt: "<<currentewt<<endl;
        //     std::cout<<myaddr<<" , getEWT() ponoff/((1.0-ponon)*(1.0-ponon)): "<<ponoff/((1.0-ponon)*(1.0-ponon))<<endl;
        if (ewt[currentchannel]<=currentewt)
        {
            std::cout<<"in if, ewt[currentchannel]: "<<ewt[currentchannel]<<endl;
            ewt[currentchannel]=currentewt;
        }
    }
#ifdef MULTI_CHA
#ifdef EWT
    for(int i=0;i<10;i++)
    {
        channelCondition.insert(std::pair<int,double>(i,ewt[i]));
        std::cout<<myaddr<<" , getEWT, ewt[i]: "<<ewt[i]<<endl;
    }
    std::cout<<endl;
#endif
#endif


}

#endif
#ifdef CAVCAP
void VCap::displayPUlist(InfluencingPUlist list)
{    std::cout<<myaddr<<", VCap::displayPUlist"<<endl;
InfluencingPUlist::iterator listit;
for(listit=list.begin();listit!=list.end();listit++)
{
    std::cout<<myaddr<<", VCap::displayPUlist, transition Matrix: \n"<<(*listit).dtmmatrix<<endl;

}
std::cout<<endl;

}


//get transition matrix from the influencing PU


// get the transition matrix of a node from influencing PU and a composed position of PUs
void VCap::getTransitionM(InfluencingPUlist puList)
{    DTMMatrix tm;
Coord composedPosition;
std::cout<<myaddr<<", getTransitionM, numChannels: "<<numChannels<<endl;

for(int i=0;i<10;i++)
{
    tm.resize(2,2);
    tm<<1,0,1,0;
    composedPosition.x=0;
    composedPosition.y=0;


    //PUMatrixPositionCH temp;
    puMatrixPositionCh[i].dtmmatrix=tm;
    puMatrixPositionCh[i].position=composedPosition;
    puMatrixPositionCh[i].channel=10000;
    //puMatrixPositionCh[i]=temp;
}


std::cout<<myaddr<<", getTransitionM, end of first loop numChannels: "<<VCap::numChannels<<endl;
for(int currentchannel=0;currentchannel<numChannels;currentchannel++)
{
    if (puList.empty())
    {
        pioff[currentchannel]=1.0;
        continue;
    }


    InfluencingPUlist PUonCurrentCH;

    for(InfluencingPUlist::iterator listchannelit=puList.begin();listchannelit!=puList.end();listchannelit++)
    {
        if((*listchannelit).channel==currentchannel)
        {
            PUonCurrentCH.push_back(*listchannelit);
        }
    }


    std::cout<<myaddr<<", getTransitionM, current channel: "<<currentchannel<<endl;


    InfluencingPUlist::iterator listit=PUonCurrentCH.begin();
    if(listit==PUonCurrentCH.end())
    {
        std::cout<<"VCap::getTransitionM, no PU on this channel \n"<<tm<<endl;
        continue;
    }

    tm=(*listit).dtmmatrix;

    composedPosition.x+=(*listit).position.x;
    composedPosition.y+=(*listit).position.y;

    std::cout<<"VCap::getTransitionM, composed position x :"<<(*listit).position.x<<endl;
    std::cout<<"VCap::getTransitionM, composed position x :"<<(*listit).position.y<<endl;


    int tmrowno;
    int tmcolno;
    for(listit++;listit!=PUonCurrentCH.end();listit++)
    {
        tmrowno=tm.rows();
        tmcolno=tm.cols();
        DTMMatrix newmatrix;
        newmatrix.resize(2*tmrowno,2*tmcolno);

        newmatrix.topLeftCorner(tmrowno,tmcolno)=(*listit).dtmmatrix(0,0)*tm;
        newmatrix.topRightCorner(tmrowno,tmcolno)=(*listit).dtmmatrix(0,1)*tm;
        newmatrix.bottomLeftCorner(tmrowno,tmcolno)=(*listit).dtmmatrix(1,0)*tm;
        newmatrix.bottomRightCorner(tmrowno,tmcolno)=(*listit).dtmmatrix(1,1)*tm;
        tm.resize(2*tmrowno,2*tmcolno);
        tm=newmatrix;


        composedPosition.x+=(*listit).position.x;
        composedPosition.y+=(*listit).position.y;
        //  std::cout<<myaddr<<", getTransitionM, composedPosition x, "<<composedPosition.x<<endl;
        // std::cout<<myaddr<<", getTransitionM, composedPosition y, "<<composedPosition.y<<endl;

    }
    composedPosition.x=composedPosition.x/puList.size();
    composedPosition.y=composedPosition.y/puList.size();
    //std::cout<<myaddr<<", getTransitionM, puList size, "<<puList.size()<<endl;
    // std::cout<<myaddr<<", getTransitionM, position y, "<<composedPosition.y<<endl;
    DTMMatrix newmatrix=tm;
    newmatrix.diagonal()=newmatrix.diagonal().array()-1;
    // std::cout<<myaddr<<", VCap::linkMetricCal, new matrix's diagonal after minus 1,\n"<<newmatrix.diagonal()<<endl;
    //  std::cout<<myaddr<<", VCap::linkMetricCal, new matrix after substracting diagonal:\n"<<newmatrix<<endl;
    int  rowno=newmatrix.rows();
    int colno=newmatrix.cols();
    DTMMatrix newnewmatrix;
    newnewmatrix.resize(rowno+1,colno);

    newnewmatrix.block(0,0,rowno,colno)=newmatrix.transpose();
    newnewmatrix.block(rowno,0,1,colno)=Eigen::MatrixXd::Ones(1,colno);
    // std::cout<<myaddr<<", VCap::linkMetricCal, display newnewmatrix:\n"<<newnewmatrix<<endl;

    Eigen::VectorXd rightsidevec=Eigen::VectorXd::Zero(newnewmatrix.rows(),1);
    rightsidevec.block(newnewmatrix.rows()-1,0,1,1)<<1;
    // std::cout<<myaddr<<", VCap::linkMetricCal, rightsidevec:\n"<< rightsidevec<<endl;
    Eigen::VectorXd pivec;
    pivec=newnewmatrix.colPivHouseholderQr().solve(rightsidevec);
    pioff[currentchannel]=pivec(0,0);
    std::cout<<myaddr<<", getTransitionM, currentchannel: "<<currentchannel<<", pioff[currentchannel]: "<< pioff[currentchannel]<<endl;
#ifdef MULTI_CHA
#ifdef DTM
    channelCondition.insert(std::pair<int,double>(currentchannel,pioff[currentchannel]));
#endif
#endif
    // std::cout<<"VCap::getTransitionM,pioff: "<<pioff<<endl;
    //std::cout<<myaddr<<"VCap::getTransitionM, end of a loop, tm= \n"<<tm<<endl;

    puMatrixPositionCh[currentchannel].dtmmatrix=tm;
    puMatrixPositionCh[currentchannel].position=composedPosition;
    //std::cout<<myaddr<<", getTransitionM, position x, "<<puMatrixPositionCh[currentchannel].position.x<<endl;
    //std::cout<<myaddr<<", getTransitionM, position y, "<<puMatrixPositionCh[currentchannel].position.y<<endl;
}

//std::cout<<myaddr<<", getTransitionM, end of function. numchannels: "<<numChannels<<endl;
}

bool VCap::equalMatrix(Eigen::MatrixXd tm1, Eigen::MatrixXd tm2)
{    if(tm1.rows()!=tm2.rows())
{
    return false;
}
if(tm1.cols()!=tm2.cols())
{
    return false;
}

int  rowno=tm1.rows();
int  colno=tm1.cols();
for(int i=0;i<rowno;i++)
{
    for(int j=0;j<colno;j++)
    {
        if(tm1(i,j)!=tm2(i,j))
        {
            return false;
        }
    }
}
return true;

}
//calculate dtm link metric, return composed pioff
double VCap::linkMetricCal(PUMatrixPositionCH pu1, PUMatrixPositionCH pu2)
{  DTMMatrix tm1=pu1.dtmmatrix;
DTMMatrix tm2=pu2.dtmmatrix;
Coord position1=pu1.position;
Coord position2=pu2.position;

DTMMatrix newmatrix(4,4);
int rowno;
int colno;

//  std::cout<<myaddr<<", VCap::linkMetricCal, tm1 and tm2 equality: "<<equalMatrix<<endl;

if (position1!=position2)
{  //std::cout<<myaddr<<", VCap::linkMetricCal, influenced by different PU"<<endl;
    if(tm1.rows()==2&&tm2.rows()!=2)//FIXME
    {
        rowno=tm2.rows();
        colno=tm2.cols();
        newmatrix.resize(2*rowno,2*colno);
        newmatrix.topLeftCorner(rowno,colno)=tm1(0,0)*tm2;
        newmatrix.topRightCorner(rowno,colno)=tm1(0,1)*tm2;
        newmatrix.bottomLeftCorner(rowno,colno)=tm1(1,0)*tm2;
        newmatrix.bottomRightCorner(rowno,colno)=tm1(1,1)*tm2;
    }
    else if(tm2.rows()==2)
    {
        rowno=tm1.rows();
        colno=tm1.cols();

        newmatrix.resize(2*rowno,2*colno);
        // std::cout<<myaddr<<", VCap::linkMetricCal, newmatrix row no, "<<newmatrix.rows()<<", newmatrix col no."<<newmatrix.cols()<<endl;
        newmatrix.topLeftCorner(rowno,colno)=tm2(0,0)*tm1;
        newmatrix.topRightCorner(rowno,colno)=tm2(0,1)*tm1;
        newmatrix.bottomLeftCorner(rowno,colno)=tm2(1,0)*tm1;
        newmatrix.bottomRightCorner(rowno,colno)=tm2(1,1)*tm1;
    }
    //std::cout<<myaddr<<", VCap::linkMetricCal, new matrix's diagonal:\n"<<newmatrix.diagonal()<<endl;
    newmatrix.diagonal()=newmatrix.diagonal().array()-1;
    // std::cout<<myaddr<<", VCap::linkMetricCal, new matrix's diagonal after minus 1,\n"<<newmatrix.diagonal()<<endl;
    //  std::cout<<myaddr<<", VCap::linkMetricCal, new matrix after substracting diagonal:\n"<<newmatrix<<endl;
    rowno=newmatrix.rows();
    colno=newmatrix.cols();
    DTMMatrix newnewmatrix;
    newnewmatrix.resize(rowno+1,colno);

    newnewmatrix.block(0,0,rowno,colno)=newmatrix.transpose();
    newnewmatrix.block(rowno,0,1,colno)=Eigen::MatrixXd::Ones(1,colno);
    // std::cout<<myaddr<<", VCap::linkMetricCal, display newnewmatrix:\n"<<newnewmatrix<<endl;

    Eigen::VectorXd rightsidevec=Eigen::VectorXd::Zero(newnewmatrix.rows(),1);
    rightsidevec.block(newnewmatrix.rows()-1,0,1,1)<<1;
    // std::cout<<myaddr<<", VCap::linkMetricCal, rightsidevec:\n"<< rightsidevec<<endl;
    Eigen::VectorXd pivec;
    pivec=newnewmatrix.colPivHouseholderQr().solve(rightsidevec);
    // std::cout<<myaddr<<", VCap::linkMetricCal, pivec pivec \n"<< pivec<<endl;
    return pivec(0,0);
}

else //influenced by the same PU
{   //std::cout<<myaddr<<", VCap::linkMetricCal, influenced by the same PU"<<endl;
    tm1.diagonal()=tm1.diagonal().array()-1;
    // std::cout<<myaddr<<", VCap::linkMetricCal, tm1's diagonal minus 1\n"<<tm1<<endl;
    rowno=tm1.rows();
    colno=tm1.cols();
    newmatrix.resize(rowno+1,colno);
    //std::cout<<myaddr<<", VCap::linkMetricCal, newmatrix row col no: "<<newmatrix.rows()<<", "<<newmatrix.cols()<<endl;

    newmatrix.block(0,0,rowno,colno)=tm1.transpose();
    newmatrix.block(rowno,0,1,colno)=Eigen::MatrixXd::Ones(1,colno);
    //   tm1.row(rowno-1)=Eigen::VectorXi::Ones(1,colno);
    //std::cout<<myaddr<<", VCap::linkMetricCal, new matrix transpose after adding one row:\n"<<newmatrix<<endl;

    Eigen::VectorXd rightsidevec=Eigen::VectorXd::Zero(rowno+1,1);
    rightsidevec.block(rowno,0,1,1)<<1;

    Eigen::VectorXd pivec;
    pivec=newmatrix.colPivHouseholderQr().solve(rightsidevec);
    // std::cout<<myaddr<<", VCap::linkMetricCal, pivec \n"<< pivec<<endl;
    return pivec(0,0);
}
return 0;
}


#endif

void VCap::handleMessage(cMessage *msg)
{
//    if(myaddr.getDByte(3)==2 && simTime() > 7100){
//                   int node3rd =1;
//               }
     std::cout<< "Node: "<<myaddr<<": handleMessage, switch on" << endl;

    totalMSG++;
    if(switchon){
        // std::cout<< myaddr<<": handleMessage, switch on" << endl;
    }
    else{
        //  std::cout<< myaddr<<": handleMessage, switch off" << endl;
        return;
    }




    if(msg==neighborfinish)
    {

        // std::cout<<myaddr<<": handleMessage, received self msg, neighbor disc finished at time: "<<simTime()<<endl;
        //displayNeighborTable();

        std::string resultFileName=par("resultFileName");

        /*
         * output number of neighbours, and neighbor list
         */
        std::string neighbourList=resultFileName+mode+"_neighbourList.csv";
        const char * neighbourListchar = neighbourList.c_str();
        std::ofstream fileio_1(neighbourListchar,std::ios::app);
        if (fileio_1.is_open()){
            fileio_1<<myaddr<<";" << neighborTable.size() << ";";
            for(NeighborTable::iterator it=neighborTable.begin(); it!=neighborTable.end();it++){
                fileio_1<< it->first << ";" ;
            }
            fileio_1 << endl;


            fileio_1.flush();
            fileio_1.close();
        }



#ifdef PU_CHA


        std::string resultFilePU=resultFileName+mode+"_PUlist.csv";
        const char * resultFilePUchar=resultFilePU.c_str();
        // std::cout<<"resultFilePUchar"<<resultFilePUchar<<endl;
        std::ofstream fileio (resultFilePUchar,std::ios::app);
        if (fileio.is_open())
        {   InfluencingPUlist::iterator puit;
        for (puit=puList.begin();puit!=puList.end();puit++)
        {
            DTMMatrix matrix=(*puit).dtmmatrix;
            (*puit).position;
            double currentOFFOFF=matrix(0,0);
            double currentONON=matrix(1,1);
#ifdef PU_CHA
#ifndef EWT
            fileio<< myaddr<<";"<<currentOFFOFF<<";"<<currentONON<<";"<< (*puit).position.x<<";"<< (*puit).position.y<<endl;
#endif

#ifdef EWT
            fileio<< myaddr<<";"<<currentOFFOFF<<";"<<currentONON<<";"<< (*puit).position.x<<";"<< (*puit).position.y<<";"<<ewt<<endl;
            // std::cout<<myaddr<<"; PUlist: "<<currentOFFOFF<<";"<<currentONON<<endl;
#endif
#endif

        }

        fileio.flush();
        fileio.close();
        }

#endif

#ifdef CAVCAP

        MeanhopCal();
        par("meanhop").setDoubleValue(meanhop);
#endif

#ifndef CAVCAP
        generateW();
#endif
        delete msg;
        return;
    }

#ifdef CAVCAP
    if (msg==calculategamma)
    {
        cTopology *topo=new cTopology;
        topo->extractByParameter("IPstring");
        double accmeanhop=0.0;
        for (int i = 0; i < topo->getNumNodes(); i++)
        {
            accmeanhop+=topo->getNode(i)->getModule()->getAncestorPar("meanhop").doubleValue();
            //std::cout<<myaddr<<"accmeanhop in loop: "<<accmeanhop<<endl;
        }
        gamma=accmeanhop/topo->getNumNodes();
        std::cout<<myaddr<<", gamma: "<<gamma<<endl;
        /*  PUPositionTimeframe::iterator puPTit;
        double maxTimeframe=0.0;
        for(puPTit=puTimeframe.begin();puPTit!=puTimeframe.end();puPTit++)
        {
           if( puPTit->second>maxTimeframe;
        }*/
        displayLinkMetricTable(linkMetricTable);
        generateW();
        delete msg;
        return;
    }
#endif

    if (msg==generateWfinish)
    {
        //displayNeighborTable();
        // std::cout<<myaddr<<": handleMessage, received self msg, W generation finished at time: "<<simTime()<<endl;
        if(W==INFINIYDIS){
            switchon=false;
            return;
        }

        //std::cout<<myaddr<<"accmeanhop: "<<accmeanhop<<endl;
        updateNeighborTable();
        delete msg;
        return;
    }



    /*
     * checkNeighborTable:
     * the following chunk is unuseful, it disables anchor message to broadcast if its neighbor has gotten a anchor message
     *
     */

    if(msg==checkWbegin)
    {
        //  std::cout<<myaddr<<": handleMessage, checkWbegin msg, at time:"<<simTime()<<endl;
        checkNeighborTable(PHASE_W);
        delete msg;
        return;
    }
    if(msg==checkXbegin)
    {
        //  std::cout<<myaddr<<": handleMessage, checkXbegin msg, at time:"<<simTime()<<endl;
        checkNeighborTable(PHASE_X);
        delete msg;
        return;
    }
    if(msg==checkYbegin)
    {
        //  std::cout<<myaddr<<": handleMessage, checkYbegin msg, at time:"<<simTime()<<endl;
        checkNeighborTable(PHASE_Y);
        delete msg;
        return;
    }
    if(msg==checkZbegin)
    {
        //  std::cout<<myaddr<<": handleMessage, checkZbegin msg, at time:"<<simTime()<<endl;
        checkNeighborTable(PHASE_Z);
        delete msg;
        return;
    }


    if(msg==electXbegin)
    {
        // updateNeighborTable();
        //   std::cout<<myaddr<<": handleMessage, received self msg, begin to elect X at time: "<<simTime()<<endl;

        electX();
        delete msg;
        return;
    }
    if (msg==generateXfinish)
    {
        //displayNeighborTable();
        //   std::cout<<myaddr<<": handleMessage, received self msg, X generation finished at time: "<<simTime()<<endl;
        updateNeighborTable();
        delete msg;
        return;
    }
    if(msg==electYbegin)
    {


        //   std::cout<<myaddr<<": handleMessage, received self msg, begin to elect Y at time: "<<simTime()<<endl;
        electY();
        delete msg;
        return;
    }
    if (msg==generateYfinish)
    {

        //  std::cout<<myaddr<<": handleMessage, received self msg, Y generation finished at time: "<<simTime()<<endl;
        updateNeighborTable();
#ifndef MORE_AHCHOR_6

#ifdef CAVCAP
        cTopology *topo=new cTopology;
        topo->extractByParameter("IPstring");
        double yofanchorx;
        double xofanchory;


        for (int i = 0; i < topo->getNumNodes(); i++)
        {

            double currentx;
            std::istringstream ssx(topo->getNode(i)->getModule()->getAncestorPar("X").info());
            ssx >> currentx;

            double currenty;
            std::istringstream ssy(topo->getNode(i)->getModule()->getAncestorPar("Y").info());
            ssy >> currenty;

            // std::cout<<myaddr<<"XYRule: current i: "<<i<<", currentx :"<<currentx<<", currenty: "<<currenty<<endl;

            if (currentx==0.0)
            {
                yofanchorx=currenty;
                //std::cout<<myaddr<<"electZbegin: y of anchor x: "<<yofanchorx<<endl;

            }
            if(currenty==0.0)
            {
                xofanchory=currentx;
                //std::cout<<myaddr<<"electZbegin: x of anchor y: "<<xofanchory<<endl;
            }
        }
        // std::cout<<myaddr<<"electZbegin: x of anchor y: "<<xofanchory<<", y of anchor x: "<<yofanchorx<<", distance"<<(X-xofanchory/2)*(X-xofanchory/2)+(Y-yofanchorx)*(Y-yofanchorx)<<endl;
        Z=(X-xofanchory/2)*(X-xofanchory/2)+(Y-yofanchorx)*(Y-yofanchorx);
        par("Z").setDoubleValue(Z);
#endif

#endif //MORE_AHCHOR_6
        delete msg;
        return;
    }

    if(msg==electZbegin)
    {

        //    std::cout<<myaddr<<": handleMessage, received self msg, begin to elect Y at time: "<<simTime()<<endl;
        electZ();
        delete msg;
        return;
    }
    if (msg==generateZfinish)
    {

        //  std::cout<<myaddr<<": handleMessage, received self msg, Z generation finished at time: "<<simTime()<<endl;
        updateNeighborTable();
        delete msg;
        //after VC generated communication switch to another channel which is influenced by PU

        return;
    }


#ifdef MORE_AHCHOR_6
    if(msg==electX1begin)
    {

        //    std::cout<<myaddr<<": handleMessage, received self msg, begin to elect Y at time: "<<simTime()<<endl;
        electX1();
        delete msg;
        return;
    }
    if (msg==generateX1finish)
    {

        //  std::cout<<myaddr<<": handleMessage, received self msg, Z generation finished at time: "<<simTime()<<endl;
        updateNeighborTable();
        delete msg;
        //after VC generated communication switch to another channel which is influenced by PU

        return;
    }


    if(msg==electX2begin)
    {

        //    std::cout<<myaddr<<": handleMessage, received self msg, begin to elect Y at time: "<<simTime()<<endl;
        electX2();
        delete msg;
        return;
    }
    if (msg==generateX2finish)
    {

        //  std::cout<<myaddr<<": handleMessage, received self msg, Z generation finished at time: "<<simTime()<<endl;
        updateNeighborTable();
        delete msg;
        //after VC generated communication switch to another channel which is influenced by PU

        return;
    }
#endif



    if(msg==globalTableFinished)
    {

        // std::cout<<myaddr<<": handleMessage, globalTableFinished msg at time: "<<simTime()<<endl;
        getGlobalTable();
        // displayNeighborTable(neighborTable);

        delete msg;
        return ;

    }
    if(msg==readyToRoute)
    {
        //std::cout<<myaddr<<": handleMessage, readyToRoute msg at time: "<<simTime()<<endl;
        VCnum=globalTable.size();
/*#ifdef MULTI_CHA
        if(W<X)
        {
            std::cout<<myaddr<<", handleMessage, submodule path: "<<getParentModule()->getModuleByRelativePath("wlan[0].radio")->getFullPath()<<endl;
            Radio* radio=check_and_cast<Radio*>(getParentModule()->getModuleByRelativePath("wlan[0].radio"));
            std::cout<<myaddr<<", handleMessage, current channel: "<<radio->myRadioRef->channel<<endl;
            radio->switchToNewChannel();
            std::cout<<myaddr<<", handleMessage, new channel: "<<radio->myRadioRef->channel<<endl;
        }
#endif*/

#ifdef PU_ON
        if(isW)
        {
            // std::cout<<myaddr<<"::handleMessage, after globalTableFinished, PUstartSignal emit"<<endl;
            emit(PUStartSignal,1);
        }
#endif

        std::string resultFileName=par("resultFileName");
        resultFileName+=mode;
        resultFileName+="_W_X_Y_Z_geoX_geoY.csv";
        const char * resultFileNamechar=resultFileName.c_str();
        //  std::cout<<"resultFileNamechar"<<resultFileNamechar<<endl;
        std::ofstream fileio (resultFileNamechar,std::ios::app);
        if (fileio.is_open())
        {
#ifndef MORE_AHCHOR_6
            fileio<< myaddr<<";"<<W<<";"<<X<<";"<<Y<<";"<<Z<<";"<<geoX<<";"<<geoY<<endl;
#endif
#ifdef MORE_AHCHOR_6
            fileio<< myaddr<<";"<<W<<";"<<X<<";"<<Y<<";"<<Z<<";"<<X1<<";"<<X2<<";"<<geoX<<";"<<geoY<<endl;
#endif


            fileio.flush();
            fileio.close();
        }

      /*  int numNode=getParentModule()->getParentModule()->par("numFixHosts").longValue();
        int srcid=getParentModule()->getParentModule()->par("srcid").longValue();
        int destid=getParentModule()->getParentModule()->par("destid").longValue();
        std::cout<<getParentModule()->getFullPath().c_str()<<endl;
        std::cout<<srcid<<";"<<destid<<endl;
        if (srcid==getParentModule()->getIndex())
        {
            std::cout<<getParentModule()->getParentModule()->getModuleByRelativePath(".udpApp[0]")->getFullPath();
           //getParentModule()->getSubmodule("udpApp[0]")->par("startTime").setLongValue(7100);


            cTopology* topo=new cTopology;
            topo->extractByParameter("IPstring");
            std::cout<< topo->getNode(destid)->getModule()->getFullPath()<<endl;

        }*/


            delete msg;
        return ;
    }

    if(ControlManetRouting * controlmanetrouting=dynamic_cast<ControlManetRouting*>(msg))
        {
        controlmanetroutingcounter++;

        if(myaddr.getDByte(3)==3 && simTime() > 7100){
                       int stop1052 =1;
                       std::cout<<myaddr <<": VCap:: controlmanetrouting->getOptionCode() is " << controlmanetrouting->getOptionCode()<<endl;
                   }

        if(controlmanetrouting->getOptionCode()==MANET_ROUTE_NOROUTE)
            {
            numforward++;
            par("hop").setLongValue(1);
            IPv4Datagram *datagram= dynamic_cast<IPv4Datagram*>(controlmanetrouting->decapsulate());
        std::cout<<"VCap::handleMessage, " << myaddr<< " receives msg with " << controlmanetrouting->getOptionCode() << " at " << simTime() <<endl;


//            /*
//             * record the time stamp before being sent from src
//             */
//            if(myaddr.getDByte(3)==1 && simTime() > 7100){
//                datagram->setTimestamp(simTime());
//            }
//            else if(myaddr.getDByte(3)!=1 && simTime() > 7100){
//                int stophere =1;
//                std::cout << "VCap:: " << myaddr.getDByte(3) << "receives controlmanetrouting " << "for datagram " <<datagram->getName()<<"\n";
//            }

            NeighborTable::iterator globaltableit=globalTable.find(datagram->getDestAddress());
            NeighborTable iptable=routeCal(globaltableit->second, datagram->getDeadendList(),datagram->getPathList());

            if (isDeadend)
            {
               DeadendList deadendlist=datagram->getDeadendList();
               deadendlist.push_back(myaddr);
               datagram->setDeadendList(deadendlist);
            }
             PathList pathlist=datagram->getPathList();

 //test
 if(myaddr.getDByte(3)==3)
 {
     int stop1=1;
 }
            pathlist.push_back(myaddr);
            std::cout << "VCap:: " << myaddr.getDByte(3) << " receives controlmanetrouting (MANET_ROUTE_NOROUTE)" << "for datagram " <<datagram->getName()<<"\n";

            datagram->setPathList(pathlist);

            datagram->removeControlInfo();
//if(myaddr.getDByte(3)==1)
//{
//int check =0;
//}
//if(myaddr.getDByte(3)==2)
//{
//int check2 =0;
//}
//if(myaddr.getDByte(3)==3)
//{
//int check3 =0;
//}

            for (NeighborTable::iterator neiit=iptable.begin();neiit!=iptable.end();neiit++)
            {
                IPv4ControlInfo *controlInfo=new IPv4ControlInfo();
                controlInfo->setNextHopAddr(neiit->first);
                par("nextHopAddrInt").setLongValue(neiit->first.getDByte(3));
                std::cout<<"nextHopAddrInt is "<< neiit->first.getDByte(3) <<endl;

        #ifdef MULTI_CHA
                //   LinkMetricTable::iterator linkmetricit=linkMetricTable.find(neiit->first);
             //   std::cout<<myaddr<<", emit channeldecisionsignal"<<endl;


                emit(Radio::ChannelDecisionSignal,neiit->first.str().c_str());//which channel neighbor is on to ChannelAccess
        #endif
                controlInfo->setProtocol(IP_PROT_VCap);
                controlInfo->setSrcAddr(datagram->getSrcAddress());
                controlInfo->setDestAddr(datagram->getDestAddress());

                IPv4Datagram * newdatagram= datagram->dup();
                newdatagram->setControlInfo(controlInfo);
                newdatagram->setTransportProtocol(IP_PROT_VCap);

                newdatagram->setNumAccessedNodes(datagram->getNumAccessedNodes()+1);

               // std::cout<<myaddr<<": handleMessage, ControlManetRouting msg received, send datagram to ip: "<<controlInfo->getNextHopAddr()<<endl;
                send(newdatagram, "to_ip");

                //    std::cout<<myaddr<<": handleMessage, ControlManetRouting msg received, nexthopip: "<<testcontrolInfo->getNextHopAddr()<<endl;
            }
            }
        delete msg;

        return ;

        }

    if(msgReq * msgreq=dynamic_cast<msgReq*>(msg))
    {

        // std::cout<< myaddr<<": handleMessage, msgReq "<<endl;
        if(msgreq->getDestIP()==myaddr){
            msgNeighborDisc* neighborupdate=new msgNeighborDisc;
            neighborupdate->setSrcIP(myaddr);


            neighborupdate->setW(W);
            neighborupdate->setX(X);

            neighborupdate->setY(Y);
            neighborupdate->setZ(Z);

#ifdef MORE_AHCHOR_6
            neighborupdate->setX1(X1);
            neighborupdate->setX2(X2);
#endif

            //       std::cout<< myaddr<<": handleMessage, msgReq for me.  set msgNeighborDisc W, "<<neighborupdate->getW()<<", forwarded to ip:"<<msgreq->getSrcIP()<<" at time:"<<simTime()<<endl ;
            forward(neighborupdate, msgreq->getSrcIP());
            delete msgreq;
            return;
        }
        else
        { // std::cout<< myaddr<<": updateNeighborTable, msgReq not for me. "<<endl;
            delete msgreq;
            return;
        }
        return;

    }

    // msgToRoute packet encapsulates one UDP packet.
    // This chunk is excuted for the dst node!!!!!!
    if(msgToRoute * msgtoroute=dynamic_cast<msgToRoute*>(msg))
    {
        if(myaddr.getDByte(3)==3){
int node2 =1;
        }

            std::cout<<myaddr <<", VCap:: msgtoroute " << msgtoroute->getName() << " at " << simTime() <<endl;

        std::cout<<myaddr<<": handleMessage, msgToRoute msg at time: "<<simTime()<<endl;
        handleToRouteMsg(msgtoroute);
        return;
    }
    if( msgNeighborDisc* neidisc=dynamic_cast<msgNeighborDisc*>(msg)){
        // std::cout<< myaddr<<": handleMessage, receive neighbor disc msg" << endl;
        handleNeighborDisc(neidisc);
        return ;
    }

    if(msgW* msgw=dynamic_cast<msgW*>(msg)){
        msgw->removeControlInfo();
        //  std::cout<< myaddr<<": handleMessage, not self msg, receive W  msg" <<msgw<< endl;
        handleWMsg(msgw);
        return;
    }


    else
    {
        //  std::cout<< myaddr<<": handleMessage, unknown msg kind: "<<msg<<", drop at time: "<<simTime()<<endl ;
        delete msg;
        return ;
    }
}


#ifdef MULTI_CHA
ChannelNumberState VCap::checkChannelwithIP(IPv4Address ip)
{
    cTopology *topo=new cTopology;

    topo->extractByParameter("IPstring");

    for(int i=0;i<topo->getNumNodes();i++)
    {
        std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info();
        std::string newcurrentipstring;
        for(unsigned int j = 0; currentipstring[j] != '\0'; j++)
        {
            if(currentipstring[j]=='\"')
            {
                continue;
            }
            newcurrentipstring+=currentipstring[j];

        }
        //    std::cout<<myaddr<<", handleMessage, new current ip as string  :"<<newcurrentipstring<<endl;
        IPv4Address currentip;
        currentip.set(newcurrentipstring.c_str());


        //std::cout<<myaddr<<", VCap::checkChannelwithIP, currentip "<<currentip<<endl;
        // std::cout<<myaddr<<", VCap::checkChannelwithIP, ip.str().c_str(): "<<ip.str().c_str()<<", currentipchar.c_str(): "<<currentipchar.c_str()<<endl;
        // std::cout<<myaddr<<", VCap::checkChannelwithIP, ip.str()==currentipchar: "<<(ip.str()==currentipchar)<<endl;

        if (ip==currentip)
        {
            // std::cout<<myaddr<<", VCap::checkChannelwithIP, i: "<<i<<endl;
            //std::cout<<myaddr<<", VCap::checkChannelwithIP currentip: "<<currentip<<", path: "<<topo->getNode(i)->getModule()->getFullPath()<<endl;

            Radio* radio=check_and_cast<Radio*>(topo->getNode(i)->getModule()->getParentModule()->getModuleByRelativePath("wlan[0].radio"));
            ChannelNumberState channelNumberState(radio->myRadioRef->channel, radio->myRadioRef->AllChannelState);
            return  channelNumberState;

        }

    }
    ChannelNumberState channelNumberState;
    return  channelNumberState;

}

double VCap::findEWTwithIP(IPv4Address ip, int channelno)
{
    cTopology *topo=new cTopology;
    topo->extractByParameter("IPstring");
    for(int i=0;i<topo->getNumNodes();i++)
    {

        std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info();
        std::string newcurrentipstring;
        for(unsigned int j = 0; currentipstring[j] != '\0'; j++)
        {
            if(currentipstring[j]=='\"')
            {
                continue;
            }
            newcurrentipstring+=currentipstring[j];

        }
        //    std::cout<<myaddr<<", handleMessage, new current ip as string  :"<<newcurrentipstring<<endl;
        IPv4Address currentip;
        currentip.set(newcurrentipstring.c_str());
        if(ip==currentip)
        {
            VCap* vcap=check_and_cast<VCap*>(topo->getNode(i)->getModule());
            ChannelCondition::iterator channelconditionit=vcap->channelCondition.find(channelno);
            if(channelconditionit!=vcap->channelCondition.end())
            {

                return channelconditionit->second;
            }

        }

    }
    return 0.0;
}
double VCap::findPioffwithIP(IPv4Address ip, int channelno)
{
    cTopology *topo=new cTopology;
    topo->extractByParameter("IPstring");


    for(int i=0;i<topo->getNumNodes();i++)
    {
        std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info();
        std::string newcurrentipstring;
        for(unsigned int j = 0; currentipstring[j] != '\0'; j++)
        {
            if(currentipstring[j]=='\"')
            {
                continue;
            }
            newcurrentipstring+=currentipstring[j];

        }
        //    std::cout<<myaddr<<", handleMessage, new current ip as string  :"<<newcurrentipstring<<endl;
        IPv4Address currentip;
        currentip.set(newcurrentipstring.c_str());

        if(ip==currentip)
        {
            VCap* vcap=check_and_cast<VCap*>(topo->getNode(i)->getModule());
            ChannelCondition::iterator channelconditionit=vcap->channelCondition.find(channelno);
            if(channelconditionit!=vcap->channelCondition.end())
            {

                return channelconditionit->second;
            }

        }

    }
    return 1.0;
}



#endif
void VCap::handleToRouteMsg(msgToRoute * msg)
{  // std::cout<<myaddr<<": handleToRouteMsg,"<<endl;

    IPv4Datagram* datagram=dynamic_cast<IPv4Datagram*>(msg->decapsulate());
    IPv4Address destip=datagram->getDestAddress();
    total++;
    //std::cout<<myaddr<<": handleToRouteMsg, datagram dest"<<datagram->getDestAddress()<<", src: "<<datagram->getSrcAddress()<<endl;

    /*
     * judge whether is src
     */
//    if(msg->getPathList().front() == myaddr){
//        issrc =1;
//    }
        if(myaddr.getDByte(3) == 5){
            int node3 =1;
        }
    std::cout << "handleToRouteMsg: The first node in pathList is: "<< msg->getPathList().front() << "\n";
    std::cout << "handleToRouteMsg: Current node is: " << myaddr << "\n";
    if(destip == myaddr){
        int arrive =1;
    }

    NeighborTable::iterator globaltit=globalTable.find(destip);

    VCoord destvc=globaltit->second;

     std::cout<<"Node " <<myaddr.getDByte(3)<<": destvc.W="<< destvc.W <<", myvc.W=" << myvc.W <<endl;

    if(destvc.XYZequal(myvc))
    {
        if(destip==myaddr)
        {
            trueHit++;
            hop=1;
            par("hop").setLongValue(1);
            msg->encapsulate(datagram);
            send(msg, "to_ip");
            //msg->getTimestamp();
            //   std::cout<<myaddr<<": handleToRouteMsg, trueHit. msg id:"<<msg->getId()<<", at time"<<msg->getTimestamp()<<endl;
            finalPathList = datagram->getPathList();
        }
        else
        {
            falseHit++;

            //std::cout<<myaddr<<": handleToRouteMsg, falseHit."<<endl;
        }
    }
    // std::cout<<myaddr<<": handleToRouteMsg, datagram dest"<<datagram->getDestAddress()<<", src: "<<datagram->getSrcAddress()<<endl;
    if( !destvc.XYZequal(myvc))
        {
        std::cout<<myaddr<<": handleToRouteMsg, non equal vc"<<endl;
        if(destip==myaddr)
        {
            missed++; //ip is the diresed one, but vc is not.
            // std::cout<<myaddr<<": handleToRouteMsg, missed."<<endl;
        }
        else
        {
            notforme++;
            // std::cout<<myaddr<<": handleToRouteMsg, missed."<<endl;
        }
        datagram->removeControlInfo();

        NeighborTable iptable=routeCal(destvc,msg->getDeadendList(),msg->getPathList());
        //std::cout<<myaddr<<", handleToRouteMsg, msg deadendlist and pathlist:"<<endl;
        //displayDeadendList(msg->getDeadendList());
        //displayPathList(msg->getPathList());
        if(isDeadend)
        {
            DeadendList deadendlist=datagram->getDeadendList();
            deadendlist.push_back(myaddr);
            datagram->setDeadendList(deadendlist);
        }
        PathList pathlist=datagram->getPathList();

        //test
        if(myaddr.getDByte(3)==50)
        {
            int stop1=1;
        }
        pathlist.push_back(myaddr);
         std::cout<<"Node " << myaddr.getDByte(3)<<": destvc.w="<<destvc.W<<", myvc="<<myvc.W <<std::endl;



        datagram->setPathList(pathlist);

        for (NeighborTable::iterator neiit=iptable.begin();neiit!=iptable.end();neiit++)
        {
            IPv4ControlInfo *controlInfo=new IPv4ControlInfo();
            controlInfo->setNextHopAddr(neiit->first);
            controlInfo->setProtocol(IP_PROT_VCap);
            controlInfo->setSrcAddr(datagram->getSrcAddress());
            controlInfo->setDestAddr(datagram->getDestAddress());

            datagram->setControlInfo(controlInfo);
            datagram->setTransportProtocol(IP_PROT_VCap);

            datagram->setNumAccessedNodes(datagram->getNumAccessedNodes()+1);

            send(datagram, "to_ip");
             std::cout<<myaddr<<": handleToRouteMsg, send datagram to ip, next hop:"<<controlInfo->getNextHopAddr()<<endl;
        }

    }

}

void VCap::handleWMsg(msgW *msg){

    IPv4Address msgAddr=msg->getSrcIP();
    if (msgAddr==myaddr){
        delete msg;
        return;
    }
    pathTable pt=msg->getPath();

    pathTable::iterator pathIterator;
    // not in the path, then check the hop number of the msg, compare to the node's W
    for(pathIterator=pt.begin();pathIterator!=pt.end();pathIterator++){

        // if myaddr is already in the path table, drop the msg
        if(*pathIterator==myaddr){
            // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " this addr already in path: "<<*pathIterator<<endl ;
            // std::cout<<myaddr<<": handleWMsg, msg from ip:"<<msg->getSrcIP()<<endl;
            delete msg;

            return;
        }
    }

#ifndef MORE_AHCHOR_6
    if(msg->getPhase()==PHASE_W){

        //    std::cout<< myaddr<<": handleWMsg,phase w, simTime: "<< simTime()<< endl;
        // W is smaller or equal than the hop number of the message, no up date, drop the message
        if (W<=msg->getHop())//
        {
            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own w: "<<getW()<< " is smaller than the msg hop number :"<<msg->getHop()<<", drop, at time: "<<simTime()<<endl ;
            pathTable::iterator it;

            for (it=msg->getPath().begin();it!=msg->getPath().end();it++)
            {
                // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " msg path: "<<*it<<endl;
            }

            delete msg;
            return;
        }
        // W is larger than hop number of the message,
        //update the node's W and add my addr to msg path and forward it to hop 1 neighbor
        else if (getW()>msg->getHop())
        {
            double currenthp=msg->getHop();
            setW(currenthp);
            par("W").setDoubleValue(currenthp);
            myvc.W=W;
            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< ",currenthp: "<<currenthp<<endl ;
            // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own w is set to: "<<W<<endl ;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            //currenthp++;
            //msg->setHop(currenthp);
            forward(msg,linkMetricTable);
#endif

        }

    }

    if(msg->getPhase()==PHASE_X && isX){
        if(W<msg->getSrcW())
        {
            isX=false;
            srcWmax=msg->getSrcW();
            IPmax=msg->getSrcIP();
            double currenthp=msg->getHop();
            X=currenthp;

            par("X").setDoubleValue(X);
            myvc.X=X;

            pt.push_back(myaddr);
            msg->setPath(pt);

#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            forward(msg,linkMetricTable);
#endif
            return;

        }
        if (W==msg->getSrcW()&& myaddr<msg->getSrcIP())
        {
            isX=false;
            srcWmax=msg->getSrcW();
            IPmax=msg->getSrcIP();
            double currenthp=msg->getHop();
            X=currenthp;

            par("X").setDoubleValue(X);
            myvc.X=X;

            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            forward(msg,linkMetricTable);
#endif
            return;
        }
    }
    if(msg->getPhase()==PHASE_X && !isX)
    {    //std::cout<< myaddr<<": handleWMsg,phase x, simTime: "<< simTime()<< endl;
        //the msg with smaller src w will be considered, if equal src w, consider larger ip

        if (msg->getSrcW()>srcWmax)
        {
            //    std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " smaller srcW get, msg.srcW: "<<msg->getSrcW()<<" previous minimum srcW: "<<srcWmax<<", at time: "<<simTime()<<endl ;

            srcWmax=msg->getSrcW();
            IPmax=msg->getSrcIP();

            double currenthp=msg->getHop();
            X=currenthp;
            par("X").setDoubleValue(X);
            myvc.X=X;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            forward(msg,linkMetricTable);
#endif
            return;

        }
        else if (msg->getSrcW()<srcWmax)
        {

            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " larger srcW get, msg.srcW: "<<msg->getSrcW()<<" previous minimum srcW: "<<srcWmax<<", no update, at time: "<<simTime()<<endl ;
            // delete msg;
            return;
        }

        else if (msg->getSrcW()==srcWmax)
        {
            if (msg->getSrcIP()>IPmax)
            {
                //    std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " same srcW, larger srcIP get, msg.srcIP: "<<msg->getSrcIP()<<" previous max srcIP: "<<IPmax<<",update at time: "<<simTime()<<endl ;
                IPmax=msg->getSrcIP();

                double currenthp=msg->getHop();
                X=currenthp;
                par("X").setDoubleValue(X);
                myvc.X=X;
                pt.push_back(myaddr);
                msg->setPath(pt);
#ifndef CAVCAP
                currenthp++;
                msg->setHop(currenthp);
                broadcast(msg);
#endif
#ifdef CAVCAP
                forward(msg,linkMetricTable);
#endif
                return;
            }
            else if(msg->getSrcIP()<IPmax)
            {
                //   std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " same srcW, smaller srcIP get, msg.srcIP: "<<msg->getSrcIP()<<" previous max srcIP: "<<IPmax<<", no update, at time: "<<simTime()<<endl ;
                //delete msg;
                return ;
            }
            else if (msg->getSrcIP()==IPmax)
            {
                if(X>msg->getHop())
                {
                    double currenthp=msg->getHop();
                    X=currenthp;
                    par("X").setDoubleValue(X);
                    myvc.X=X;
                    pt.push_back(myaddr);
                    msg->setPath(pt);
#ifndef CAVCAP
                    currenthp++;
                    msg->setHop(currenthp);
                    broadcast(msg);
#endif
#ifdef CAVCAP
                    forward(msg,linkMetricTable);
#endif
                    return;
                }
                else
                {
                    //  delete msg;
                    return ;
                }

            }
        }
    }
    if(msg->getPhase()==PHASE_Y&&isY)
    {
        if (msg->getSrcX()>X)
        {
            isY=false;
            srcXmax=msg->getSrcX();
            IPmax=msg->getSrcIP();

            double currenthp=msg->getHop();
            Y=currenthp;
            par("Y").setDoubleValue(Y);
            myvc.Y=Y;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            forward(msg,linkMetricTable);
#endif
            return;
        }
        else if(msg->getSrcX()==X&&msg->getSrcIP()>myaddr)
        {
            isY=false;
            IPmax=msg->getSrcIP();

            double currenthp=msg->getHop();
            Y=currenthp;
            par("Y").setDoubleValue(Y);
            myvc.Y=Y;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            forward(msg,linkMetricTable);
#endif
            return;
        }

    }
    if(msg->getPhase()==PHASE_Y&&!isY){
        //    std::cout<< myaddr<<": handleWMsg,phase y, simTime: "<< simTime()<< endl;
        if(msg->getSrcX()<srcXmax){
            delete msg;
            //std::cout<<myaddr<<": handleWmsg,"<<", msg has smaller srcX, drop"<<endl;
            return ;
        }
        else if (msg->getSrcX()==srcXmax){
            if(IPmax>msg->getSrcIP()){
                delete msg;
                //std::cout<<myaddr<<": handleWmsg,"<<", same X, msg has smaller srcIP, drop"<<endl;
                return ;
            }
            else if(IPmax<msg->getSrcIP()){
                IPmax=msg->getSrcIP();

                double currenthp=msg->getHop();
                Y=currenthp;

                par("Y").setDoubleValue(Y);
                myvc.Y=Y;
                // std::cout<<myaddr<<": handleWmsg,same srcX. but largerIP:"<<msg->getSrcIP()<<",  Y: "<<Y<<endl;
                pt.push_back(myaddr);
                msg->setPath(pt);
#ifndef CAVCAP
                currenthp++;
                msg->setHop(currenthp);
                broadcast(msg);
#endif
#ifdef CAVCAP
                forward(msg,linkMetricTable);
#endif
                return;

            }
            else if (IPmax==msg->getSrcIP()){
                if (Y>msg->getHop()){
                    double currenthp=msg->getHop();
                    Y=currenthp;
                    par("Y").setDoubleValue(Y);
                    myvc.Y=Y;
                    //std::cout<<myaddr<<": handleWmsg, smaller Y arrives: "<<Y<<endl;
                    pt.push_back(myaddr);
                    msg->setPath(pt);
#ifndef CAVCAP
                    currenthp++;
                    msg->setHop(currenthp);
                    broadcast(msg);
#endif
#ifdef CAVCAP
                    forward(msg,linkMetricTable);
#endif
                    return;
                }
                else {
                    delete msg;
                    return;
                }


            }

        }
        else if (msg->getSrcX()>srcXmax){
            srcXmax=msg->getSrcX();
            IPmax=msg->getSrcIP();

            double currenthp=msg->getHop();
            Y=currenthp;
            par("Y").setDoubleValue(Y);
            myvc.Y=Y;
            // std::cout<<myaddr<<": handleWmsg, larger srcX, from IP:"<<msg->getSrcIP()<<", Y: "<<Y<<endl;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            forward(msg,linkMetricTable);
#endif
            return;
        }

    }
    if(msg->getPhase()==PHASE_Z&&isZ){
        if(myaddr<msg->getSrcIP()){
            isZ=false;
            IPmax=msg->getSrcIP();

            double currenthp=msg->getHop();
            Z=currenthp;
            par("Z").setDoubleValue(Z);
            myvc.Z=Z;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            forward(msg,linkMetricTable);
#endif
            return;
        }

    }
    if(msg->getPhase()==PHASE_Z&&!isZ){
        if(msg->getSrcIP()<IPmax){
            delete msg;
            return;
        }
        else if(msg->getSrcIP()==IPmax){
            if(Z>msg->getHop()){
                double currenthp=msg->getHop();
                Z=currenthp;
                par("Z").setDoubleValue(Z);
                myvc.Z=Z;
                pt.push_back(myaddr);
                msg->setPath(pt);
#ifndef CAVCAP
                currenthp++;
                msg->setHop(currenthp);
                broadcast(msg);
#endif
#ifdef CAVCAP
                forward(msg,linkMetricTable);
#endif
                return;
            }
            else {
                delete msg;
                return;
            }
        }
        else if(msg->getSrcIP()>IPmax){
            IPmax=msg->getSrcIP();

            double currenthp=msg->getHop();
            Z=currenthp;
            par("Z").setDoubleValue(Z);
            myvc.Z=Z;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            forward(msg,linkMetricTable);
#endif
            return;
        }
    }

#endif

#ifdef MORE_AHCHOR_6
    if(msg->getPhase()==PHASE_W){

        //    std::cout<< myaddr<<": handleWMsg,phase w, simTime: "<< simTime()<< endl;
        // W is smaller or equal than the hop number of the message, no up date, drop the message
        if (W <= msg->getHop())//
        {
//              std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own w: "<<getW()<< " is smaller than the msg hop number :"<<msg->getHop()<<", drop, at time: "<<simTime()<<endl ;
            pathTable::iterator it;

            for (it=msg->getPath().begin();it!=msg->getPath().end();it++)
            {
                // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " msg path: "<<*it<<endl;
            }

            delete msg;
            return;
        }
        // W is larger than hop number of the message,
        //update the node's W and add my addr to msg path and forward it to hop 1 neighbor
        else if (getW() > msg->getHop())
        {
            double currenthp=msg->getHop();
            setW(currenthp);
            par("W").setDoubleValue(currenthp);
            myvc.W=W;
            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< ",currenthp: "<<currenthp<<endl ;
//             std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own w is set to: "<<W<<endl ;
//             std::cout<< "*************************************************************"<<endl ;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            //currenthp++;
            //msg->setHop(currenthp);
            forward(msg,linkMetricTable);
#endif

        }
    }


    if(msg->getPhase()==PHASE_X){

        //    std::cout<< myaddr<<": handleWMsg,phase w, simTime: "<< simTime()<< endl;
        // W is smaller or equal than the hop number of the message, no up date, drop the message
        if (X <= msg->getHop())//
        {
//              std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own x: "<<getW()<< " is smaller than the msg hop number :"<<msg->getHop()<<", drop, at time: "<<simTime()<<endl ;
            pathTable::iterator it;

            for (it=msg->getPath().begin();it!=msg->getPath().end();it++)
            {
                // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " msg path: "<<*it<<endl;
            }

            delete msg;
            return;
        }
        // W is larger than hop number of the message,
        //update the node's W and add my addr to msg path and forward it to hop 1 neighbor
        else if (getX() > msg->getHop())
        {
            double currenthp=msg->getHop();
            setX(currenthp);
            par("X").setDoubleValue(currenthp);
            myvc.X=X;
            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< ",currenthp: "<<currenthp<<endl ;
//            std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own x is set to: "<<X<<endl ;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            //currenthp++;
            //msg->setHop(currenthp);
            forward(msg,linkMetricTable);
#endif
        }
    }
//TODO: record

    if(msg->getPhase()==PHASE_Y){

        //    std::cout<< myaddr<<": handleWMsg,phase w, simTime: "<< simTime()<< endl;
        // W is smaller or equal than the hop number of the message, no up date, drop the message
        if (Y <= msg->getHop())//
        {
//              std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own Y: "<<getW()<< " is smaller than the msg hop number :"<<msg->getHop()<<", drop, at time: "<<simTime()<<endl ;
            pathTable::iterator it;

            for (it=msg->getPath().begin();it!=msg->getPath().end();it++)
            {
                // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " msg path: "<<*it<<endl;
            }

            delete msg;
            return;
        }
        // W is larger than hop number of the message,
        //update the node's W and add my addr to msg path and forward it to hop 1 neighbor
        else if (getY() > msg->getHop())
        {
            double currenthp=msg->getHop();
            setY(currenthp);
            par("Y").setDoubleValue(currenthp);
            myvc.Y=Y;
            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< ",currenthp: "<<currenthp<<endl ;
//             std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own Y is set to: "<<W<<endl ;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            //currenthp++;
            //msg->setHop(currenthp);
            forward(msg,linkMetricTable);
#endif
        }
    }



    if(msg->getPhase()==PHASE_Z){

        //    std::cout<< myaddr<<": handleWMsg,phase w, simTime: "<< simTime()<< endl;
        // W is smaller or equal than the hop number of the message, no up date, drop the message
        if (Z <= msg->getHop())//
        {
//              std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own Z: "<<getW()<< " is smaller than the msg hop number :"<<msg->getHop()<<", drop, at time: "<<simTime()<<endl ;
            pathTable::iterator it;

            for (it=msg->getPath().begin();it!=msg->getPath().end();it++)
            {
                // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " msg path: "<<*it<<endl;
            }

            delete msg;
            return;
        }
        // W is larger than hop number of the message,
        //update the node's W and add my addr to msg path and forward it to hop 1 neighbor
        else if (getZ() > msg->getHop())
        {
            double currenthp=msg->getHop();
            setZ(currenthp);
            par("Z").setDoubleValue(currenthp);
            myvc.Z=Z;
            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< ",currenthp: "<<currenthp<<endl ;
//             std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own Z is set to: "<<W<<endl ;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            //currenthp++;
            //msg->setHop(currenthp);
            forward(msg,linkMetricTable);
#endif

        }
    }



    if(msg->getPhase()==PHASE_X1){

        //    std::cout<< myaddr<<": handleWMsg,phase w, simTime: "<< simTime()<< endl;
        // W is smaller or equal than the hop number of the message, no up date, drop the message
        if (X1 <= msg->getHop())//
        {
//              std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own X1: "<<getW()<< " is smaller than the msg hop number :"<<msg->getHop()<<", drop, at time: "<<simTime()<<endl ;
            pathTable::iterator it;

            for (it=msg->getPath().begin();it!=msg->getPath().end();it++)
            {
                // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " msg path: "<<*it<<endl;
            }

            delete msg;
            return;
        }
        // W is larger than hop number of the message,
        //update the node's W and add my addr to msg path and forward it to hop 1 neighbor
        else if (getX1() > msg->getHop())
        {
            double currenthp=msg->getHop();
            setX1(currenthp);
            par("X1").setDoubleValue(currenthp);
            myvc.X1=X1;
            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< ",currenthp: "<<currenthp<<endl ;
//             std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own X1 is set to: "<<W<<endl ;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            //currenthp++;
            //msg->setHop(currenthp);
            forward(msg,linkMetricTable);
#endif

        }
    }



    if(msg->getPhase()==PHASE_X2){

        //    std::cout<< myaddr<<": handleWMsg,phase w, simTime: "<< simTime()<< endl;
        // W is smaller or equal than the hop number of the message, no up date, drop the message
        if (X2<=msg->getHop())//
        {
//              std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own X2: "<<getW()<< " is smaller than the msg hop number :"<<msg->getHop()<<", drop, at time: "<<simTime()<<endl ;
            pathTable::iterator it;

            for (it=msg->getPath().begin();it!=msg->getPath().end();it++)
            {
                // std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " msg path: "<<*it<<endl;
            }

            delete msg;
            return;
        }
        // W is larger than hop number of the message,
        //update the node's W and add my addr to msg path and forward it to hop 1 neighbor
        else if (getX2() > msg->getHop())
        {
            double currenthp=msg->getHop();
            setX2(currenthp);
            par("X2").setDoubleValue(currenthp);
            myvc.X2=X2;
            //  std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< ",currenthp: "<<currenthp<<endl ;
//             std::cout<< myaddr<<": handleWMsg, in phase: "<< msg->getPhase()<< " my own X2 is set to: "<<W<<endl ;
            pt.push_back(myaddr);
            msg->setPath(pt);
#ifndef CAVCAP
            currenthp++;
            msg->setHop(currenthp);
            broadcast(msg);
#endif
#ifdef CAVCAP
            //currenthp++;
            //msg->setHop(currenthp);
            forward(msg,linkMetricTable);
#endif

        }
    }

#endif

}





void VCap::handleNeighborDisc(msgNeighborDisc *msg)
{
    // ev << "VCap::handleNeigborDisc()" <<  endl;
    // std::cout<< myaddr<<": handleNeighborDisc, from:"<<msg->getSrcIP()<<endl;
    const IPv4Address neighborAddr=msg->getSrcIP();

#ifndef MORE_AHCHOR_6
    VCoord vc(msg->getW(),msg->getX(),msg->getY(),msg->getZ());
#endif

    #ifdef MORE_AHCHOR_6
    VCoord vc(msg->getW(),msg->getX(),msg->getY(),msg->getZ(),msg->getX1(), msg->getX2());
#endif

    if(neighborAddr==myaddr)
    {
        delete msg;
        // std::cout<< myaddr<<": handleNeighborDisc"<<", msg ip:"<<neighborAddr<<",msg from my ip, drop msg, time: "<<simTime()<<endl;
        return;
    }

    else if (isEntryExisted(neighborAddr))// if it is in the hop 1 neighborhood
    {

        // std::cout<< myaddr<<": handleNeighborDisc: neighbor entry existed, time: "<<simTime()<<endl;


        // Entry exists in hop 1 neighborhood, no update:
        if(!isUpdate(neighborAddr,vc))
        {
            //ev << "VCap::handleNeighborDisc(), Entry already exists in hop1 neighbor table, discarding" << endl;
            delete msg;
            //   std::cout<< myaddr<<": handleNeighborDisc"<<", msg ip:"<<neighborAddr<<", but no update, drop msg, time: "<<simTime()<<endl;
            return;
        }

        // Entry exists,  but need to be updated:
        if(isUpdate(neighborAddr,vc))
        {
            // delete old entry:
            // std::cout<< myaddr<<": handleNeighborDisc"<<", msg ip:"<<neighborAddr<<", update, time: "<<simTime()<<endl;
            updateEntry(neighborAddr,vc);
            //displayNeighborTable();
            delete msg;
            return;
        }
        // Entry does not exist:


    }

    else if (!isEntryExisted(neighborAddr))
    {
        // std::cout<< myaddr<<": handleNeighborDisc"<<", msg ip:"<<neighborAddr<<", add new neighbor entry, W:"<< vc.W<<"time: "<<simTime()<<endl;
        addEntry(neighborAddr,vc);
        /*#ifdef MULTI_CHA
        addNeighborPUChannel(msg);
#endif*/
        //neighborPUChannel.insert(std::pair<IPv4Address, int*>(neighborAddr,msg->getMyPUChannel()));
#ifdef CAVCAP

        addLink(neighborAddr,msg);

#endif
        //if (simTime()>=startTime+WFINISHTIME){
        //   updateNeighborTable();
        //}
        delete msg;
        return;
    }
    //

}

void VCap::electX()
{
#ifndef MORE_AHCHOR_6
    // std::cout<<myaddr<<": electX," <<endl;
    NeighborTable::iterator neit;
    srcWmax=0;
    IPmax.set(IPv4Address::UNSPECIFIED);

    for(neit=neighborTable.begin();neit!=neighborTable.end();neit++)
    {
        VCoord vc=neit->second;
        //std::cout<<myaddr<<": electX,fabs(vc.W-W) :"<<fabs(vc.W-W)<<endl;
        if(fabs(vc.W-W)<1e-3){
            // std::cout<<myaddr<<": electX,fabs(vc.W-W) :"<<fabs(vc.W-W)<<endl;
            if(myaddr>neit->first){
                isX=true;
                // std::cout<<myaddr<<": electX, my W is equal to W in the neighborhood, my ip is larger, isX: "<<isX<<endl;
            }
            else if(myaddr<neit->first){
                isX=false;
                //  std::cout<<myaddr<<": electX, my W is equal to W in the neighborhood, my ip is smaller, isX: "<<isX<<endl;
                break;
            }


        }
        else if((vc.W-W)>1e-3){
            isX=false;
            //std::cout<<myaddr<<": electX, larger W in neighborhoodfound, isX: "<<isX<<endl;

            break;

        }

        else if((W-vc.W)>1e-3){
            isX=true;
            //std::cout<<myaddr<<": electX, my W is larger than W in the neighborhood, isX: "<<isX<<endl;
        }



    }
#endif

    //    std::cout<<myaddr<<": electX, end of the loop, isX: "<<isX<<", at time: "<<simTime()<<endl;
    if(isX){
        X=0;
        par("X").setDoubleValue(X);

        myvc.X=X;
        msgW * msgw=new msgW;


        pathTable* pt=new pathTable;
        pt->push_back(myaddr);
        msgw->setPath( *pt);

        msgw->setPhase(PHASE_X);
        msgw->setSrcIP(myaddr);
        msgw->setSrcW(W);
#ifndef CAVCAP
        msgw->setHop(1);
        broadcast(msgw);
#endif
#ifdef CAVCAP
        forward(msgw,linkMetricTable);
#endif

        // output the list of anchor X
        std::string resultFileName=par("resultFileName");
        resultFileName+=mode;
        resultFileName+="_anchorList.csv";
        const char * anchorListchar = resultFileName.c_str();
        std::ofstream fileio_1(anchorListchar,std::ios::app);
        if (fileio_1.is_open()){
            fileio_1 << "anchor X: "<< myaddr << "\n";
        }
        fileio_1.flush();
        fileio_1.close();

    }

}
void VCap::electY()
{
#ifndef MORE_AHCHOR_6
    //displayNeighborTable(neighborTable);
    //   std::cout<<myaddr<<": electY "<<endl;
    NeighborTable::iterator neit;
    srcXmax=0.0;

#ifndef CAVCAP
    gamma=1.0;
#endif

    IPmax.set(IPv4Address::UNSPECIFIED);
#ifdef DTM
    double newgamma=-log(gamma)+0.5*gamma;
#endif
#ifdef EWT
    double newgamma=gamma;
#endif
#ifndef CAVCAP
    double newgamma=gamma;
#endif
  //  std::cout<<myaddr<<": electY: newgamma: "<<newgamma<<endl;
    for(neit=neighborTable.begin();neit!=neighborTable.end();neit++){
        VCoord vc=neit->second;
        //  std::cout<<myaddr<<": electY, in loop, gamma: "<<gamma<<endl;
        if(W<=newgamma){
            isY=false;
            // std::cout<<myaddr<<": electY, my w is smaller than gamma, isY: "<<isY<<endl;

            break;
        }
        else {
            isY=true;
            //  std::cout<<myaddr<<": electY, else, isY: "<<isY<<endl;
        }
        if(vc.W>newgamma){

            if ((vc.X-X)>1e-3){
                isY=false;
                // std::cout<<myaddr<<": electY, vc.X-X: "<<vc.X-X<<endl;
                //  std::cout<<myaddr<<": electY, my x is smaller than x in the neighborhood, isY: "<<isY<<", my x, "<<X<<", neighbor x, "<<vc.X<<endl;
                break;
            }

            else if(fabs(X-vc.X)<=1e-3){
                // std::cout<<"fabs(vc.X-X): "<<fabs(X-vc.X)<<endl;
                if(myaddr>neit->first){
                    isY=true;
                    //    std::cout<<myaddr<<": electY, my x is equal to x in the neighborhood, my ip is larger, isY: "<<isY<<", neighbor ip: "<<neit->first<<", vc.X:"<<vc.X<<", my X: "<<X<<endl;
                }
                else if(myaddr<neit->first){
                    isY=false;
                    //   std::cout<<myaddr<<": electY, my X is equal to X in the neighborhood, my ip is smaller, isY: "<<isY<<" neighbor ip: "<<neit->first<<", vc.X:"<<vc.X<<", my X: "<<X<<endl;
                    break;
                }

            }
            else if((vc.X-X)<1e-3){
                isY=true;
                //std::cout<<myaddr<<": electY, my X is larger than X in the neighborhood, isY: "<<isY<<endl;

            }


        }




    }
#endif

    //    std::cout<<myaddr<<": electY, end of the loop, isY: "<<isY<<", at time: "<<simTime()<<endl;
    if(isY){
        Y=0;
        //   std::cout<<myaddr<<"::electY, isY. Y:"<<Y<<endl;
        par("Y").setDoubleValue(Y);
        //  par("xofanchory").setDoubleValue(X);
        myvc.Y=Y;
        msgW * msgw=new msgW;


        pathTable* pt=new pathTable;
        pt->push_back(myaddr);
        msgw->setPath( *pt);

        msgw->setPhase(PHASE_Y);
        msgw->setSrcIP(myaddr);
        msgw->setSrcX(X);

#ifndef CAVCAP
        msgw->setHop(1);
        broadcast(msgw);
#endif
#ifdef CAVCAP
        forward(msgw,linkMetricTable);
#endif

        // output the list of anchor Y
        std::string resultFileName =par("resultFileName").stdstringValue();
        resultFileName+=mode;
        resultFileName+="_anchorList.csv.csv";
                const char * anchorListchar = resultFileName.c_str();
                std::ofstream fileio_1(anchorListchar,std::ios::app);
                if (fileio_1.is_open()){
                    fileio_1 << "anchor Y: "<< myaddr << "\n";
                }
                fileio_1.flush();
                fileio_1.close();
    }


}
void VCap::electZ(){
#ifndef MORE_AHCHOR_6

    // std::cout<<myaddr<<": electZ "<<endl;
    //displayNeighborTable(neighborTable);
    NeighborTable::iterator neit;
    srcWmax=0.0;
    IPmax.set(IPv4Address::UNSPECIFIED);
#ifndef CAVCAP
    for(neit=neighborTable.begin();neit!=neighborTable.end();neit++){
        VCoord vc=neit->second;
#endif
        if(!XYRule(X,Y))
        {
            isZ=false;
            // std::cout<<myaddr<<": electZ, disobey the rule, isZ: "<<isZ<<endl;
#ifndef CAVCAP
            break;
#endif
        }
        else
        {   isZ=true;
        //std::cout<<myaddr<<": electZ, obey the rule, isZ: "<<isZ<<endl;
        }
#ifndef CAVCAP
        if(XYRule(X,Y)&&XYRule(vc.X,vc.Y))
        {
            // if(XYRule(vc.X,vc.Y))

            if (vc.W>W){
                isZ=false;
                break;
            }
            if(vc.W==W){
                if(myaddr>neit->first){
                    isZ=true;
                    //std::cout<<myaddr<<": electZ, my W is equal to W in the neighborhood, my ip is larger, isZ: "<<isZ<<endl;
                }
                else if(myaddr<neit->first){
                    isZ=false;
                    //std::cout<<myaddr<<": electZ, my W is equal to W in the neighborhood, my ip is smaller, isZ: "<<isZ<<endl;
                    break;
                }


            }
            else if(vc.W<W){
                isZ=true;
                //std::cout<<myaddr<<": electZ, my W is larger than W in the neighborhood, isZ: "<<isZ<<endl;
            }
        }

    }
#endif
    // std::cout<<myaddr<<": electZ, end of the loop, isZ: "<<isZ<<", at time: "<<simTime()<<endl;
#endif //MORE_AHCHOR_6

    if(isZ)
    {
        Z=0;
        par("Z").setDoubleValue(Z);
        myvc.Z=Z;
        msgW * msgw=new msgW;


        pathTable* pt=new pathTable;
        pt->push_back(myaddr);
        msgw->setPath( *pt);

        msgw->setPhase(PHASE_Z);
        msgw->setSrcIP(myaddr);
        msgw->setSrcW(W);
#ifndef CAVCAP
        msgw->setHop(1);
        broadcast(msgw);
#endif
#ifdef CAVCAP
        forward(msgw,linkMetricTable);
#endif

        // output the list of anchor Z
        std::string resultFileName =par("resultFileName").stdstringValue();
        resultFileName+=mode;
        resultFileName+="_anchorList.csv";
        const char * anchorListchar = resultFileName.c_str();
        std::ofstream fileio_1(anchorListchar,std::ios::app);
        if (fileio_1.is_open()){
            fileio_1 << "anchor Z: "<< myaddr << "\n";
        }
        fileio_1.flush();
        fileio_1.close();

    }
}

#ifdef MORE_AHCHOR_6

void VCap::electX1()
{
    //    std::cout<<myaddr<<": electX, end of the loop, isX: "<<isX<<", at time: "<<simTime()<<endl;
    if(isX1){
        X1=0;
        par("X1").setDoubleValue(X1);

        myvc.X1=X1;
        msgW * msgw=new msgW;


        pathTable* pt=new pathTable;
        pt->push_back(myaddr);
        msgw->setPath( *pt);

        msgw->setPhase(PHASE_X1);
        msgw->setSrcIP(myaddr);
        msgw->setSrcW(W);
#ifndef CAVCAP
        msgw->setHop(1);
        broadcast(msgw);
#endif
#ifdef CAVCAP
        forward(msgw,linkMetricTable);
#endif

        // output the list of anchor X
        std::string resultFileName =par("resultFileName").stdstringValue();
        resultFileName+=mode;
        resultFileName+="_anchorList.csv";
                const char * anchorListchar = resultFileName.c_str();
                std::ofstream fileio_1(anchorListchar,std::ios::app);
                if (fileio_1.is_open()){
                    fileio_1 << "anchor X1: "<< myaddr << "\n";
                }
                fileio_1.flush();
                fileio_1.close();

    }

}

void VCap::electX2()
{
    //    std::cout<<myaddr<<": electX, end of the loop, isX: "<<isX<<", at time: "<<simTime()<<endl;
    if(isX2){
        X2=0;
        par("X2").setDoubleValue(X1);

        myvc.X2=X2;
        msgW * msgw=new msgW;


        pathTable* pt=new pathTable;
        pt->push_back(myaddr);
        msgw->setPath( *pt);

        msgw->setPhase(PHASE_X2);
        msgw->setSrcIP(myaddr);
        msgw->setSrcW(W);
#ifndef CAVCAP
        msgw->setHop(1);
        broadcast(msgw);
#endif
#ifdef CAVCAP
        forward(msgw,linkMetricTable);
#endif

        // output the list of anchor X
        std::string resultFileName =par("resultFileName").stdstringValue();
        resultFileName+=mode;
        resultFileName+="_anchorList.csv";
                const char * anchorListchar = resultFileName.c_str();
                std::ofstream fileio_1(anchorListchar,std::ios::app);
                if (fileio_1.is_open()){
                    fileio_1 << "anchor X2: "<< myaddr << "\n";
                }
                fileio_1.flush();
                fileio_1.close();

    }

}
#endif



#ifdef CAVCAP
bool VCap::XYRule(double x, double y)
{
    cTopology *topo=new cTopology;
    topo->extractByParameter("IPstring");
    double minz= INFINIYDIS;
    for (int i = 0; i < topo->getNumNodes(); i++)
    {
        double currentz;
        std::istringstream ssz(topo->getNode(i)->getModule()->getAncestorPar("Z").info());
        ssz >> currentz;
        //  std::cout<<myaddr<<", XYRule, currentz: "<<currentz<<endl;
        if (minz>=currentz)
        {
            minz=currentz;
        }

    }
    //std::cout<<myaddr<<", XYRule, minz: "<<minz<<" my Z: "<<Z<<endl;
    if((Z-minz)<0.001){
        // std::cout<<myaddr<<", XYRule, my Z is smallest, Z: "<<Z<<endl;
        Z=INFINIYDIS;
        par("Z").setDoubleValue(INFINIYDIS);
        return true;
    }
    Z=INFINIYDIS;
    par("Z").setDoubleValue(INFINIYDIS);
    return false;
}

#endif

#ifndef CAVCAP

bool VCap::XYRule(double x, double y)
{
    return ((x-y)==1)||((x-y)==-1);
}
#endif
NeighborTable VCap::routeCal(VCoord destvc, DeadendList deadendlist, PathList pathlist)
{   //std::cout<<myaddr<<", routeCal, deadendlist, "<<endl;
    // displayDeadendList(deadendlist);
    isDeadend=false;
    //   std::cout<<myaddr<<", routeCal, isDeadend, "<<isDeadend<<endl;

    double mindis=INFINIYDIS;
    double d;
    NeighborTable mindisTable;
    VCoord currentvc;

    double mydis=(X-destvc.X)*(X-destvc.X)+(Y-destvc.Y)*(Y-destvc.Y)+(Z-destvc.Z)*(Z-destvc.Z)+(X1-destvc.X1)*(X1-destvc.X1) + (X2-destvc.X2)*(X2-destvc.X2);

    //  std::cout<<myaddr<<": routeCal,my distance to destination mindis: "<<mydis<<endl;

    for(NeighborTable::iterator neit=neighborTable.begin();neit!=neighborTable.end();neit++)
    {
//        if(isInDeadendList(neit->first,deadendlist)||isInPathList(neit->first,pathlist))//jump over the deadend neighbor and those in the path
//        {
//            // std::cout<<myaddr<<", routeCal, jump over deadend"<<endl;
//            continue;
//
//        }
        if(!isInDeadendList(neit->first, pathlist)) //true if i
            {
                // std::cout<<myaddr<<", routeCal, jump over deadend"<<endl;


            currentvc=neit->second;

    #ifndef MORE_AHCHOR_6 // 6 anchors
            d=(currentvc.X-destvc.X)*(currentvc.X-destvc.X)+(currentvc.Y-destvc.Y)*(currentvc.Y-destvc.Y)+(currentvc.Z-destvc.Z)*(currentvc.Z-destvc.Z);
    #endif

    #ifdef MORE_AHCHOR_6 // 6 anchors
            d=(currentvc.W-destvc.W)*(currentvc.W-destvc.W)+(currentvc.X-destvc.X)*(currentvc.X-destvc.X)+(currentvc.Y-destvc.Y)*(currentvc.Y-destvc.Y)+(currentvc.Z-destvc.Z)*(currentvc.Z-destvc.Z)+(currentvc.X1-destvc.X1)*(currentvc.X1-destvc.X1) + (currentvc.X2-destvc.X2)*(currentvc.X2-destvc.X2);

    #endif

            //  std::cout<<myaddr<<": routeCal, d:"<<d<<endl;
            if(d<mindis)
            {
                mindis=d;
                mindisTable.clear();
                mindisTable.insert(std::pair<IPv4Address,VCoord>(neit->first,currentvc));

            }
            else if(d==mindis)
            {
                NeighborTable::iterator neit2=mindisTable.begin();
                //   std::cout<<myaddr<<": routeCal, equal disance found."<<endl;
                if(neit2==mindisTable.end())
                {
    //                mindisTable.clear(); // Di adds this, so that mindisTable has only one entry
                    mindisTable.insert(std::pair<IPv4Address,VCoord>(neit->first,currentvc));
                    //  std::cout<<myaddr<<": routeCal, equal disance found. table is now empty, so insert"<<endl;
                }

            }
            else if(d>mindis)
            {
                if(!mindisTable.size()) // mindisTable.size()==0
                    mindisTable.insert(std::pair<IPv4Address,VCoord>(neit->first,currentvc));
                //  std::cout<<myaddr<<": routeCal, larger disance found. do nothing"<<endl;
            }
        }
    }

    if(mindis>=mydis)
    {
        deadendmsg++;
        isDeadend=true;
        //   std::cout<<myaddr<<", routeCal, isDeadend, "<<isDeadend<<endl;
    }
    //   displayNeighborTable(mindisTable);
    return mindisTable;

}
void VCap::forward(cPacket *msg, IPv4Address ip)
{
    IPv4Datagram *p= new IPv4Datagram();
    p->setSrcAddress(myaddr);
    p->setDestAddress(ip);
    //  std::cout<<myaddr<<": forward, the destination addr is set to :"<< ip<<endl;

    p->setTimeToLive(1);

    p->setTransportProtocol(IP_PROT_MANET);

    IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
    ipControlInfo->setProtocol(IP_PROT_MANET);
    ipControlInfo->setSrcAddr(myaddr);
    ipControlInfo->setTimeToLive(1);
    ipControlInfo->setDestAddr(ip);

    p->setControlInfo(ipControlInfo);


    p->encapsulate(msg);
    float delay=exponential(1000e-3);
    sendDelayed(p,delay,"to_ip");
    //  std::cout<<myaddr<<": forward, msg forwarded to "<<p->getDestAddress()<<endl;

}

void VCap::forward(cPacket *msg, NeighborTable neighborTable)
{
    int couter=0;

    for(NeighborTable::iterator neit=neighborTable.begin();neit!=neighborTable.end();neit++)
    {

        IPv4Datagram *p= new IPv4Datagram();
        p->setSrcAddress(myaddr);
        p->setDestAddress(neit->first);
        // std::cout<<myaddr<<": forward, the destination addr is set to :"<< neit->first<<endl;

        p->setTimeToLive(1);

        p->setTransportProtocol(IP_PROT_MANET);

        IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
        ipControlInfo->setProtocol(IP_PROT_MANET);
        ipControlInfo->setSrcAddr(myaddr);
        ipControlInfo->setTimeToLive(1);
        ipControlInfo->setDestAddr(neit->first);

        p->setControlInfo(ipControlInfo);
        //    std::cout<<myaddr<<": forward, couter: "<<couter<<endl;

        if (couter>=1)
        {
            cPacket * newmsg=msg->dup();
            p->encapsulate(newmsg);
            //    std::cout<<myaddr<<": forward, encapsulate duplicated msg "<<endl;
        }
        else
        {
            p->encapsulate(msg);
        }


        float delay=exponential(1000e-3);
        sendDelayed(p,delay,"to_ip");
        //std::cout<<myaddr<<": forward, true sending time: "<<simTime()<<endl;
        couter++;
    }


}
#ifdef CAVCAP

void VCap::forward(msgW *msgw, LinkMetricTable linkTable)
{
    //displayLinkMetricTable(linkMetricTable);

    for(LinkMetricTable::iterator linkit=linkTable.begin();linkit!=linkTable.end();linkit++)
    {

        // std::cout<<myaddr<<", VCap::forward to linkMetricTable, msgw.gethop: "<<msgw->getHop()<<endl;
        msgW * newmsgw=msgw->dup();
#ifdef DTM

        double currenthop=msgw->getHop()-log(linkit->second)+0.2*linkit->second;

 //  std::cout<<myaddr<<", VCap::forward to linkMetricTable,-log(linkit->second)+0.2*linkit->second: "<< -log(linkit->second)+0.2*linkit->second<<endl;
        newmsgw->setHop(currenthop);
        // if(msgw->getPhase()==PHASE_Y)
        // std::cout<<myaddr<<", VCap::forward to linkMetricTable, at phase Y, currenthop: "<<currenthop<<endl;
#endif
#ifdef EWT

      //  double currenthop=msgw->getHop()+linkit->second+gamma*0.2;
        double currenthop=msgw->getHop()+linkit->second+exp(-linkit->second);
        newmsgw->setHop(currenthop);
     //   std::cout<<myaddr<<", forward, linkit->second: "<<meanhop<<endl;
#endif
        IPv4Datagram * p= new IPv4Datagram();
        p->setSrcAddress(myaddr);
        p->setDestAddress(linkit->first);
        // std::cout<<myaddr<<": forward, the destination addr is set to :"<< neit->first<<endl;

        p->setTimeToLive(1);

        p->setTransportProtocol(IP_PROT_MANET);

        IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
        ipControlInfo->setProtocol(IP_PROT_MANET);
        ipControlInfo->setSrcAddr(myaddr);
        ipControlInfo->setTimeToLive(1);
        ipControlInfo->setDestAddr(linkit->first);

        p->setControlInfo(ipControlInfo);
        p->encapsulate(newmsgw);
        float delay=exponential(1000e-3);
        sendDelayed(p,delay,"to_ip");

    }
}
#endif

void VCap::broadcast(cPacket* msg){
    // std::cout<<myaddr<<"::broadcast one parameter, time: "<<simTime()<<endl;
    IPv4Datagram *p= new IPv4Datagram();
    p->setSrcAddress(myaddr);
    p->setDestAddress(IPv4Address::ALLONES_ADDRESS);

    p->setTimeToLive(1);

    p->setTransportProtocol(IP_PROT_MANET);

    IPv4ControlInfo *ipControlInfo = new IPv4ControlInfo();
    ipControlInfo->setProtocol(IP_PROT_MANET);
    ipControlInfo->setSrcAddr(myaddr);
    ipControlInfo->setDestAddr(IPv4Address::ALLONES_ADDRESS);
    ipControlInfo->setTimeToLive(1);

    p->setControlInfo(ipControlInfo);
    p->encapsulate(msg);
    float delay=exponential(1000e-3);

    sendDelayed(p,delay,"to_ip");
}

double VCap::getW(){return W;}

double VCap::getX(){return X;}
double VCap::getY(){return Y;}
double VCap::getZ(){return Z;}
#ifdef MORE_AHCHOR_6
double VCap::getX1(){return X1;}
double VCap::getX2(){return X2;}
#endif

void VCap::setW(double i){ this->W=i;}
void VCap::setX(double i){ this->X=i;}
void VCap::setY(double i){ this->Y=i;}
void VCap::setZ(double i){ this->Z=i;}
#ifdef MORE_AHCHOR_6
void VCap::setX1(double i){ this->X1=i;}
void VCap::setX2(double i){ this->X2=i;}
#endif
VCoord VCap::getMyvc(){
    return myvc;
}
IPv4Address VCap::getMyaddr(){
    return myaddr;
}

uint32_t VCap::getRoute(const Uint128 &, std::vector<Uint128> &){
    return 0;
}

bool VCap::getNextHop(const Uint128 &, Uint128 &add, int &iface, double &cost){
    return false;
}

void VCap::setRefreshRoute(const Uint128 &destination, const Uint128 & nextHop,bool isReverse){

}

bool VCap::isProactive() {
    return false;
}

bool VCap::isOurType(cPacket *){
    return false;
}

bool VCap::getDestAddress(cPacket *, Uint128 &){
    return false;
}
#ifdef CAVCAP

void VCap::MeanhopCal()
{
    double sum=0.0;
    double count=0.0;
    for(LinkMetricTable::iterator linkit=linkMetricTable.begin();linkit!=linkMetricTable.end();linkit++)
    {
        sum+=linkit->second;
        count++;


    }
    if(count!=0.0)
        meanhop=sum/count;

    //std::cout<<myaddr<<", MeanhopCal, meanhop: "<<meanhop<<endl;
}
#endif

void VCap::getGlobalTable()
{
    cTopology *topo=new cTopology;
    //topo->extractByNedTypeName(cStringTokenizer("**.host[*] **.router*").asVector());
    topo->extractByParameter("IPstring");

    //     std::cout<<myaddr<<", VCap::getGlobalTable(), topo get node no: "<<topo->getNumNodes()<<endl;

    for (int i = 0; i < topo->getNumNodes(); i++)
    {
        std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info();
        std::string newcurrentipstring;
        for(unsigned int j = 0; currentipstring[j] != '\0'; j++)
        {
            if(currentipstring[j]=='\"')
            {
                continue;
            }
            newcurrentipstring+=currentipstring[j];

        }
        //    std::cout<<myaddr<<", handleMessage, new current ip as string  :"<<newcurrentipstring<<endl;
        IPv4Address currentip;
        currentip.set(newcurrentipstring.c_str());
        //  std::cout<<myaddr<<", handleMessage, new current ip as IPv4Address :"<<currentip<<endl;

        double currentw;
        std::istringstream ssw(topo->getNode(i)->getModule()->getAncestorPar("W").info());
        ssw >> currentw;

        double currentx;
        std::istringstream ssx(topo->getNode(i)->getModule()->getAncestorPar("X").info());
        ssx >> currentx;

        double currenty;
        std::istringstream ssy(topo->getNode(i)->getModule()->getAncestorPar("Y").info());
        ssy >> currenty;

        double currentz;
        std::istringstream ssz(topo->getNode(i)->getModule()->getAncestorPar("Z").info());
        ssz >> currentz;

#ifdef MORE_AHCHOR_6
        double currentx1;
        std::istringstream ssx1(topo->getNode(i)->getModule()->getAncestorPar("X1").info());
        ssx1 >> currentx1;

        double currentx2;
        std::istringstream ssx2(topo->getNode(i)->getModule()->getAncestorPar("X2").info());
        ssx2 >> currentx2;
#endif


#ifndef CAVCAP
#ifndef MORE_AHCHOR_6
        if((currentw!=INFINIYDIS) && (currentx!=INFINIYDIS) && (currenty!=INFINIYDIS) && (currentz!=INFINIYDIS))
        {
            VCoord currentvc(currentw,currentx,currenty,currentz);
            globalTable.insert(std::pair<IPv4Address,VCoord>(currentip,currentvc));

        }
#endif

#ifdef MORE_AHCHOR_6
        if((currentw!=INFINIYDIS) && (currentx!=INFINIYDIS) && (currenty!=INFINIYDIS) && (currentz!=INFINIYDIS) && (currentx1!=INFINIYDIS) && (currentx2!=INFINIYDIS))
        {
            VCoord currentvc(currentw,currentx,currenty,currentz,currentx1,currentx2);
            globalTable.insert(std::pair<IPv4Address,VCoord>(currentip,currentvc));

        }
#endif
#endif

#ifdef CAVCAP
        // for the moment z vc is not considered
#ifndef MORE_AHCHOR_6
        if((currentw!=INFINIYDIS) && (currentx!=INFINIYDIS) && (currenty!=INFINIYDIS))
        {
            VCoord currentvc(currentw,currentx,currenty,currentz);
            globalTable.insert(std::pair<IPv4Address,VCoord>(currentip,currentvc));

        }
#endif
#ifdef MORE_AHCHOR_6
        if((currentw!=INFINIYDIS) && (currentx!=INFINIYDIS) && (currenty!=INFINIYDIS) && (currentz!=INFINIYDIS) && (currentx1!=INFINIYDIS) && (currentx2!=INFINIYDIS))
        {
            VCoord currentvc(currentw,currentx,currenty,currentz,currentx1,currentx2);
            globalTable.insert(std::pair<IPv4Address,VCoord>(currentip,currentvc));

        }
#endif

#endif

    }

}

void VCap::addEntry(IPv4Address ip,VCoord vc)
{
    //std::cout<<myaddr<<": addEntry, W:"<< vc.W <<", time: "<<simTime()<<endl;
    neighborTable.insert(std::pair<IPv4Address,VCoord>(ip,vc));
    updateNeighborRoute(ip);
    // std::cout<<myaddr<<": addEntry,"<< ip<<", time: "<<simTime()<<endl;

    //displayNeighborTable();
}

void VCap::updateEntry(IPv4Address ip,VCoord vc)
{
    NeighborTable::iterator neit=neighborTable.find(ip);

    neighborTable.erase(neit);
    VCap::neighborTable.insert(std::pair<IPv4Address,VCoord >(ip,vc));
}
#ifdef CAVCAP
#ifdef DTM
void VCap::addLink(IPv4Address ip,msgNeighborDisc * msg)
{   int puMPsize=msg->getPuMatrixPositionChArraySize();
   // std::cout<<myaddr<<", addLink, puMPsize: "<<puMPsize<<endl;
    double pioffarray [10];
    //std::cout<<myaddr<<", addLink, inserted in linkTable, pioff, "<<pioff<<endl;
    for(int i=0;i<puMPsize;i++)
    {
       // std::cout<<myaddr<<", addLink, msg->getPioff(i): "<<msg->getPioff(i)<<endl;
        if (abs(msg->getPuMatrixPositionCh(i).position.x-puMatrixPositionCh[i].position.x)<0.0001 && (msg->getPuMatrixPositionCh(i).position.y-puMatrixPositionCh[i].position.y)<0.0001)
        {

             pioffarray[i]=pioff[i]*(msg->getPioff(i));
        }
        else
        {
            pioffarray[i]=pioff[i]*(msg->getPioff(i));
        }
    }
    double multiplypioff=1.0;
   // double minpioff=10000.0;
    double sumpioff=0.0;
    for(int i=0;i<puMPsize;i++)
    {

        multiplypioff*=(1.0-pioffarray[i]);
        sumpioff+=pioffarray[i];
       /* if(minpioff>pioffarray[i])
        {
            minpioff=pioffarray[i];
        }*/
    }

    // std::cout<<myaddr<<", addLink, multiplypioff: "<<multiplypioff<<endl;
      //linkMetricTable.insert(std::pair<IPv4Address, double>(ip,multiplypioff));
   linkMetricTable.insert(std::pair<IPv4Address, double>(ip,1.0-multiplypioff));

}
#endif
#ifdef EWT
void VCap::addLink(IPv4Address ip,msgNeighborDisc * msg)
{   int puMPsize=msg->getPuMatrixPositionChArraySize();
    std::cout<<myaddr<<", addLink, puMPsize: "<<puMPsize<<endl;
    double ewtarray [10];
    for(int i=0;i<puMPsize;i++)
    {
        if (abs(msg->getPuMatrixPositionCh(i).position.x-puMatrixPositionCh[i].position.x)<0.0001 && (msg->getPuMatrixPositionCh(i).position.y-puMatrixPositionCh[i].position.y)<0.0001)
        {   //influenced by the same pu
            ewtarray[i]=msg->getEwt(i);
        // linkMetricTable.insert(std::pair<IPv4Address, double>(ip,ewt));
        //   std::cout<<myaddr<<", addLink influenced by same pu"<<", ewt: "<<ewt<<", with ip: "<<ip<<endl;
        }
        else
        {  // double pion=1.0-pioff;
        //  double mypion=1.0-VCap::pioff;
        //double linkmetric =(VCap::ewt+ewt)/2;
            ewtarray[i]= std::max(VCap::ewt[i],msg->getEwt(i));

        //double linkmetric= mypion*pion*std::max(ewt,VCap::ewt)+mypion*pioff*VCap::ewt+VCap::pioff*pion*ewt;
        // std::cout<<myaddr<<", addLink influenced by different pu"<<endl;
        //std::cout<<myaddr<<", received pion: "<<pion<<", my pion: "<<1-VCap::pioff<<", link metric: "<<linkmetric<<", my ewt: "<<VCap::ewt<<", received ewt:"<<ewt<<", with ip: "<<ip<<endl;

        // linkMetricTable.insert(std::pair<IPv4Address, double>(ip,linkmetric));
        }
        std::cout<<myaddr<<", addLink, ewtarray[i] "<<ewtarray[i]<<", i: "<<i<<endl;
    }
  //  double minewt=10000.0;

    double sumewt=0.0;
    for(int i=0;i<puMPsize;i++)
    {
        sumewt+=ewtarray[i];
     /*    if(ewtarray[i]<minewt)
        {
             minewt=ewtarray[i];
        }*/

    }
   // std::cout<<myaddr<<", addLink, minewt: "<<minewt<<endl;
    // linkMetricTable.insert(std::pair<IPv4Address, double>(ip,minewt));
    linkMetricTable.insert(std::pair<IPv4Address, double>(ip,sumewt));

}

#endif
#endif
//if the ip is existed in the table
bool VCap::isEntryExisted (IPv4Address ip)
{
    //std::cout<< myaddr<< ": isEntryExisted" << endl;
    NeighborTable::iterator neit=neighborTable.find(ip);
    // bool b=neit!=neighborTable.end();
    //std::cout<< myaddr<< ": isEntryExisted, boolean:" << b<< endl;
    return neit!=neighborTable.end();
}
/*#ifdef MULTI_CHA
void VCap::addNeighborPUChannel(msgNeighborDisc* msg)
{
    int channellist[];
    for(int i=0;i<msg->getMyPUChannelArraySize();i++)
    {
      channellist[i]=msg->getMyPUChannel(i);
    }
    neighborPUChannel.insert(std::pair<IPv4Address,int*>(msg->getSrcIP(),channellist));

}
#endif*/
void VCap::updateNeighborRoute(const IPv4Address& dst)
{

    IPv4Route* pathToDst=new IPv4Route();
    pathToDst->setDestination(dst);
    pathToDst->setNetmask(IPv4Address("255.255.255.255"));
    pathToDst->setGateway(dst);
    pathToDst->setInterface(routingTable->getInterfaceByAddress(myaddr));
    pathToDst->setSource(IPv4Route::MANET);
    routingTable->addRoute(pathToDst);
}

bool VCap::isUpdate(IPv4Address ip,VCoord  newvc)
{
    //
    NeighborTable::iterator neit=neighborTable.find(ip);
    if (neit!=neighborTable.end())
    {   //std::cout<<myaddr<<": isUpdate, found ip entry in neighbor table"<<endl;
        VCoord  vc =neit->second;
        //std::cout<<myaddr<<": isUpdate, W of old vc: "<<vc.W<<", W of new vc: "<<newvc.W<<endl;
        //std::cout<<myaddr<<": isUpdate, X of old vc: "<<vc.X<<", W of new vc: "<<newvc.X<<endl;
        //std::cout<<myaddr<<": isUpdate, Y of old vc: "<<vc.Y<<", W of new vc: "<<newvc.Y<<endl;
        //std::cout<<myaddr<<": isUpdate, Z of old vc: "<<vc.Z<<", W of new vc: "<<newvc.Z<<endl;
        //std::cout<<myaddr<<": isUpdate, return value:"<<!(newvc==vc)<<endl;
        return !(newvc==vc);

    }
    else
        return true;

}
void VCap::finish()
{
    if(!switchon) return;
    //std::cout<<myaddr<<": finish"<<endl;
    // if (myaddr<=destip2 && myaddr>=destip){

    int localforward=par("VCaplocalforward");
    std::string resultFileName=par("resultFileName");
//    std::string srcdest=par("srcdest");
    std::string puposition=par("puposition");

    // std::cout<<myaddr<<",finish, controlmanetroutingcounter: "<<controlmanetroutingcounter<<", numforward: "<<numforward<<endl;

    if(trueHit!=0)
    {
        std::string resultFileName=par("resultFileName");
        resultFileName+=mode;
        resultFileName+="_Truehit.csv";
        const char * resultFileNamechar=resultFileName.c_str();
//        char * globalfilename="Truehit.csv";
        std::ofstream fileio (resultFileNamechar,std::ios::app);
        if (fileio.is_open())
        {
#ifdef CAVCAPBUFFER
            fileio<<resultFileName+"_buffer"+mode.c_str()<<";"<< trueHit<<endl;
#endif
#ifndef CAVCAPBUFFER
            fileio<<resultFileName+"_nobuffer"+mode.c_str()<<";"<< trueHit<<endl;
#endif
            fileio.flush();
            fileio.close();
        }


        // record the traversing route of packet
        // srcID, destID, num_of_received_packets, nodes_in_finalPathList ??
        resultFileName=par("resultFileName").stdstringValue();
        resultFileName+=mode;
           resultFileName+="_route.csv";
           resultFileNamechar=resultFileName.c_str();

           std::ofstream fileio3 (resultFileNamechar,std::ios::app);

           int a1=myaddr.getDByte(3);
           int a2=getParentModule()->getParentModule()->par("numFixHosts").longValue();
    //       int a2=getParentModule()->getParentModule()->par("b").longValue();

           fileio3<< 0 << ";" << a2 << ";" << trueHit << ";"<< finalPathList.size() << ";";
           PathList::iterator i;
           for(i=finalPathList.begin(); i!=finalPathList.end(); i++){
               fileio3 << i->str().c_str() << ";";
           }
           fileio3 << endl;

//           fileio3<< myaddr<<";"<< issrc << ";" <<numforward<<";"<<localforward<<";"<<trueHit<<";"<<falseHit<<";"<<missed<<";"<<notforme<<";"<<numLoop<<";"<<deadendmsg<<";"<<selfmsg<<";"<<total<<endl;
          // fileio2<<srcdest<<";"<<puposition<<";"<<(trueHit!=0)<<endl;
           fileio3.flush();
           fileio3.close();




    }





    // }

    //if (trueHit!=0||falseHit!=0||missed!=0||notforme!=0){
    //  displayNeighborTable(neighborTable);
#ifdef CAVCAP
    // displayLinkMetricTable(linkMetricTable);
#endif
    //displayLinkTable(linkTable);
    //   std::cout<<myaddr<<": finish, W: "<<W<<", X: "<<X<<", Y:"<<Y<<", Z:"<<Z<<endl;
    //  }
}

void VCap::displayNeighborTable(NeighborTable table)
{
    std::cout<< myaddr<<": displayNeighborTable"<<endl;
    for (NeighborTable::iterator it=table.begin(); it!=table.end();it++)
    {
        VCoord vcd=it->second;

        std::cout<< myaddr<<": displayNeighborTable, my own coord is: "<<getW()<<","<<getX()<<","<<getY()<<","<< getZ()<<", current entry in neighbor table: IP"<<it->first<<", W: "<<vcd.W<<", X: "<<vcd.X<<", Y: "<<vcd.Y<<", Z: "<<vcd.Z<<endl;
        //std::cout<< myaddr<<": displayNeighborTable, at time: "<<simTime()<<endl;
    }
    std::cout<<endl;
}
void VCap::displayDeadendList(DeadendList deadendlist)
{
    for(DeadendList::iterator listit=deadendlist.begin();listit!=deadendlist.end();listit++)
    {
        std::cout<<myaddr<<",displayDeadendList, "<<(*listit)<<endl;
    }
    std::cout<<endl;
}
bool VCap::isInDeadendList(IPv4Address ip, DeadendList deadendlist)
{
    for(DeadendList::iterator listit=deadendlist.begin();listit!=deadendlist.end();listit++)
    {
        if(ip==(*listit))
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}
bool VCap::isInPathList(IPv4Address ip, PathList pathlist)
{
    for(PathList::iterator listit=pathlist.begin();listit!=pathlist.end();listit++)
    {
        if(ip==(*listit))
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}
void VCap::displayPathList(PathList pathlist)
{ for(PathList::iterator listit=pathlist.begin();listit!=pathlist.end();listit++)
{
    std::cout<<myaddr<<",displayPathList, "<<(*listit)<<endl;
}
std::cout<<endl;
}
#ifdef CAVCAP
void VCap::displayLinkMetricTable(LinkMetricTable linkmetrictable)
{
    std::cout<<myaddr<<": displayLinkMetricTable"<<endl;
    for (LinkMetricTable::iterator it=linkmetrictable.begin();it!=linkmetrictable.end();it++)
    {
        double linkmetric=it->second;
        std::cout<< myaddr<<": displayLinkMetircTable, IP: "<<it->first<<", linkmetirc: "<<linkmetric<<endl;
    }
    std::cout<<endl;
}
#endif
// generate W coordination
void VCap::generateW(){

    if(isW){
        // std::cout<<myaddr<<": generateW, I am anchor W, isW: "<<isW<<", at time:"<<simTime()<<endl;
        setW(0);//base value of W is then 0
        par("W").setDoubleValue(0);
        myvc.W=0;
        msgW * msgw=new msgW();

        pathTable* pt=new pathTable;
        pathTable::iterator ptit=pt->begin();
        pt->insert(ptit,myaddr);
        msgw->setPath( *pt);

        msgw->setSrcIP(myaddr);
        msgw->setSrcW(getW());

        msgw->setPhase(PHASE_W);
#ifdef CAVCAP

        forward(msgw,linkMetricTable);
#ifdef EWT
        // msgw->setHop(ewt);
#endif

#ifdef CTM
        //  msgw->setHop(prob);
#endif

#endif//end of CAVCAP

#ifndef CAVCAP
        msgw->setHop(1);
        broadcast(msgw);
#endif

        // std::cout<<myaddr<<": generateW, msgW generated, msg kind: "<<msgw<<endl;

        // output the list of anchor W
        std::string resultFileName =par("resultFileName").stdstringValue();
        resultFileName+=mode;
        resultFileName+="_anchorList.csv";
        const char *anchorListchar=resultFileName.c_str();
        // std::cout<<"resultFileNamechar"<<resultFileNamechar<<endl;
        std::ofstream fileio_1 (anchorListchar,std::ios::app);
        if (fileio_1.is_open()){
            fileio_1 << "anchor W: "<< myaddr << "\n";
        }
        fileio_1.flush();
        fileio_1.close();


    }
    else if (!isW)
    {   //  std::cout<<myaddr<<": generateW, I am not anchor W, W: "<<W<<", at time:"<<simTime()<<endl;
        return;
    }

}
// update only one hop neighbor

// update the vc of neighbors stored in its neighborTable.
void VCap::updateNeighborTable()
{
    cTopology *topo=new cTopology;
    topo->extractByParameter("IPstring");
    for (int i = 0; i < topo->getNumNodes(); i++)
    {
        std::string currentipstring=topo->getNode(i)->getModule()->getAncestorPar("IPstring").info();
        std::string newcurrentipstring;
        for(unsigned int j = 0; currentipstring[j] != '\0'; j++)
        {
            if(currentipstring[j]=='\"')
            {
                continue;
            }
            newcurrentipstring+=currentipstring[j];

        }
        //    std::cout<<myaddr<<", handleMessage, new current ip as string  :"<<newcurrentipstring<<endl;
        IPv4Address currentip;
        currentip.set(newcurrentipstring.c_str());
        NeighborTable::iterator neiit=neighborTable.find(currentip);
        if(neiit!=neighborTable.end())
        {   //std::cout<<myaddr<<", updateNeighborTable, is my neigbor"<<endl;
            double currentw;
            std::istringstream ssw(topo->getNode(i)->getModule()->getAncestorPar("W").info());
            ssw >> currentw;

            double currentx;
            std::istringstream ssx(topo->getNode(i)->getModule()->getAncestorPar("X").info());
            ssx >> currentx;

            double currenty;
            std::istringstream ssy(topo->getNode(i)->getModule()->getAncestorPar("Y").info());
            ssy >> currenty;

            double currentz;
            std::istringstream ssz(topo->getNode(i)->getModule()->getAncestorPar("Z").info());
            ssz >> currentz;

#ifdef MORE_AHCHOR_6
            double currentx1;
            std::istringstream ssx1(topo->getNode(i)->getModule()->getAncestorPar("X1").info());
            ssx1 >> currentx1;

            double currentx2;
            std::istringstream ssx2(topo->getNode(i)->getModule()->getAncestorPar("X2").info());
            ssx2 >> currentx2;

            VCoord vc(currentw,currentx,currenty,currentz,currentx1,currentx2);
            neiit->second=vc;

#endif


#ifndef MORE_AHCHOR_6
            VCoord vc(currentw,currentx,currenty,currentz);
            neiit->second=vc;
#endif


        }
    }
}
/*
void VCap::updateNeighborTable(){
    msgNeighborDisc* neighborupdate=new msgNeighborDisc;
    neighborupdate->setSrcIP(myaddr);

    neighborupdate->setW(W);
    neighborupdate->setX(X);

    neighborupdate->setY(Y);
    neighborupdate->setZ(Z);
#ifdef CAVCAP
#ifdef DTM
    neighborupdate->setTransitionMatrix(transitionMatrix);
    neighborupdate->setPioff(pioff);
#endif
#endif
    broadcast(neighborupdate);
}*/
void VCap::checkNeighborTable(int i){
    for(NeighborTable::iterator it=neighborTable.begin(); it!=neighborTable.end();it++){
        VCoord vc=it->second;
        if(i==PHASE_W){
            if (vc.W==INFINIYDIS){
                //std::cout<<myaddr<<": handleMessage, checkWbegin msg,the missing entry has the ip addr: "<<it->first<<". at time:"<<simTime()<<endl;
                msgReq *msgreq=new msgReq();

                msgreq->setSrcIP(myaddr);
                msgreq->setDestIP(it->first);
                forward(msgreq,it->first);

            }
        }
        if(i==PHASE_X){
            if (vc.X==INFINIYDIS){
                //std::cout<<myaddr<<": handleMessage, checkXbegin msg,the missing entry has the ip addr: "<<it->first<<". at time:"<<simTime()<<endl;
                msgReq *msgreq=new msgReq();

                msgreq->setSrcIP(myaddr);
                msgreq->setDestIP(it->first);
                forward(msgreq,it->first);

            }
        }
        if(i==PHASE_Y){
            if (vc.Y==INFINIYDIS){
                //std::cout<<myaddr<<": handleMessage, checkYbegin msg,the missing entry has the ip addr: "<<it->first<<". at time:"<<simTime()<<endl;
                msgReq *msgreq=new msgReq();

                msgreq->setSrcIP(myaddr);
                msgreq->setDestIP(it->first);
                forward(msgreq,it->first);

            }
        }
        if(i==PHASE_Z){
            if (vc.Z==INFINIYDIS){
                //std::cout<<myaddr<<": handleMessage, checkZbegin msg,the missing entry has the ip addr: "<<it->first<<". at time:"<<simTime()<<endl;
                msgReq *msgreq=new msgReq();

                msgreq->setSrcIP(myaddr);
                msgreq->setDestIP(it->first);
                forward(msgreq,it->first);

            }
        }

    }

    return;

}
