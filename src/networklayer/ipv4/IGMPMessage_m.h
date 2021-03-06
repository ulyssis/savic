//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/ipv4/IGMPMessage.msg.
//

#ifndef _IGMPMESSAGE_M_H_
#define _IGMPMESSAGE_M_H_

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
#include "IPv4Address.h"
// }}



/**
 * Enum generated from <tt>networklayer/ipv4/IGMPMessage.msg</tt> by opp_msgc.
 * <pre>
 * enum IGMPType
 * {
 *     IGMP_MEMBERSHIP_QUERY = 0x11;
 *     IGMPV1_MEMBERSHIP_REPORT = 0x12;
 *     IGMPV2_MEMBERSHIP_REPORT = 0x16;
 *     IGMPV2_LEAVE_GROUP = 0x17;
 * }
 * </pre>
 */
enum IGMPType {
    IGMP_MEMBERSHIP_QUERY = 0x11,
    IGMPV1_MEMBERSHIP_REPORT = 0x12,
    IGMPV2_MEMBERSHIP_REPORT = 0x16,
    IGMPV2_LEAVE_GROUP = 0x17
};

/**
 * Class generated from <tt>networklayer/ipv4/IGMPMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet IGMPMessage
 * {
 *     int type enum(IGMPType);
 *     int maxRespTime;
 *     IPv4Address groupAddress;
 * }
 * </pre>
 */
class INET_API IGMPMessage : public ::cPacket
{
  protected:
    int type_var;
    int maxRespTime_var;
    IPv4Address groupAddress_var;

  private:
    void copy(const IGMPMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IGMPMessage&);

  public:
    IGMPMessage(const char *name=NULL, int kind=0);
    IGMPMessage(const IGMPMessage& other);
    virtual ~IGMPMessage();
    IGMPMessage& operator=(const IGMPMessage& other);
    virtual IGMPMessage *dup() const {return new IGMPMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getType() const;
    virtual void setType(int type);
    virtual int getMaxRespTime() const;
    virtual void setMaxRespTime(int maxRespTime);
    virtual IPv4Address& getGroupAddress();
    virtual const IPv4Address& getGroupAddress() const {return const_cast<IGMPMessage*>(this)->getGroupAddress();}
    virtual void setGroupAddress(const IPv4Address& groupAddress);
};

inline void doPacking(cCommBuffer *b, IGMPMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IGMPMessage& obj) {obj.parsimUnpack(b);}


#endif // _IGMPMESSAGE_M_H_
