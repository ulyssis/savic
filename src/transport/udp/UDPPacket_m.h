//
// Generated file, do not edit! Created by opp_msgc 4.3 from transport/udp/UDPPacket.msg.
//

#ifndef _UDPPACKET_M_H_
#define _UDPPACKET_M_H_

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
// }}



/**
 * Class generated from <tt>transport/udp/UDPPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet UDPPacket
 * {
 *     unsigned short sourcePort;
 *     unsigned short destinationPort;
 *     bool inbuffer;
 * }
 * </pre>
 */
class INET_API UDPPacket : public ::cPacket
{
  protected:
    unsigned short sourcePort_var;
    unsigned short destinationPort_var;
    bool inbuffer_var;

  private:
    void copy(const UDPPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const UDPPacket&);

  public:
    UDPPacket(const char *name=NULL, int kind=0);
    UDPPacket(const UDPPacket& other);
    virtual ~UDPPacket();
    UDPPacket& operator=(const UDPPacket& other);
    virtual UDPPacket *dup() const {return new UDPPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned short getSourcePort() const;
    virtual void setSourcePort(unsigned short sourcePort);
    virtual unsigned short getDestinationPort() const;
    virtual void setDestinationPort(unsigned short destinationPort);
    virtual bool getInbuffer() const;
    virtual void setInbuffer(bool inbuffer);
};

inline void doPacking(cCommBuffer *b, UDPPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, UDPPacket& obj) {obj.parsimUnpack(b);}


#endif // _UDPPACKET_M_H_
