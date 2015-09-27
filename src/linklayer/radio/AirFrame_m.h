//
// Generated file, do not edit! Created by opp_msgc 4.3 from linklayer/radio/AirFrame.msg.
//

#ifndef _AIRFRAME_M_H_
#define _AIRFRAME_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0403
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API 
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API 
#  endif
#endif

// cplusplus {{
#include "INETDefs.h"
#include "Coord.h"
#include "ModulationType.h"
// }}



/**
 * Class generated from <tt>linklayer/radio/AirFrame.msg</tt> by opp_msgc.
 * <pre>
 * packet AirFrame
 * {
 *     double pSend; 
 *     int channelNumber; 
 *     simtime_t duration; 
 *     double bitrate;
 *     double snr;
 *     double lossRate;
 *     double powRec; 
 *     Coord senderPos;
 *     
 *     double carrierFrequency; 
 *     double bandwidth;
 *     ModulationType modulationType;
 *     bool inbuffer;
 *     simtime_t phyTime;
 *     simtime_t accPhyTime;
 * }
 * </pre>
 */
class INET_API AirFrame : public ::cPacket
{
  protected:
    double pSend_var;
    int channelNumber_var;
    simtime_t duration_var;
    double bitrate_var;
    double snr_var;
    double lossRate_var;
    double powRec_var;
    Coord senderPos_var;
    double carrierFrequency_var;
    double bandwidth_var;
    ModulationType modulationType_var;
    bool inbuffer_var;
    simtime_t phyTime_var;
    simtime_t accPhyTime_var;

  private:
    void copy(const AirFrame& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AirFrame&);

  public:
    AirFrame(const char *name=NULL, int kind=0);
    AirFrame(const AirFrame& other);
    virtual ~AirFrame();
    AirFrame& operator=(const AirFrame& other);
    virtual AirFrame *dup() const {return new AirFrame(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual double getPSend() const;
    virtual void setPSend(double pSend);
    virtual int getChannelNumber() const;
    virtual void setChannelNumber(int channelNumber);
    virtual simtime_t getDuration() const;
    virtual void setDuration(simtime_t duration);
    virtual double getBitrate() const;
    virtual void setBitrate(double bitrate);
    virtual double getSnr() const;
    virtual void setSnr(double snr);
    virtual double getLossRate() const;
    virtual void setLossRate(double lossRate);
    virtual double getPowRec() const;
    virtual void setPowRec(double powRec);
    virtual Coord& getSenderPos();
    virtual const Coord& getSenderPos() const {return const_cast<AirFrame*>(this)->getSenderPos();}
    virtual void setSenderPos(const Coord& senderPos);
    virtual double getCarrierFrequency() const;
    virtual void setCarrierFrequency(double carrierFrequency);
    virtual double getBandwidth() const;
    virtual void setBandwidth(double bandwidth);
    virtual ModulationType& getModulationType();
    virtual const ModulationType& getModulationType() const {return const_cast<AirFrame*>(this)->getModulationType();}
    virtual void setModulationType(const ModulationType& modulationType);
    virtual bool getInbuffer() const;
    virtual void setInbuffer(bool inbuffer);
    virtual simtime_t getPhyTime() const;
    virtual void setPhyTime(simtime_t phyTime);
    virtual simtime_t getAccPhyTime() const;
    virtual void setAccPhyTime(simtime_t accPhyTime);
};

inline void doPacking(cCommBuffer *b, AirFrame& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, AirFrame& obj) {obj.parsimUnpack(b);}


#endif // _AIRFRAME_M_H_
