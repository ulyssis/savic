//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/GPS/msgRouting.msg.
//

#ifndef _MSGROUTING_M_H_
#define _MSGROUTING_M_H_

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
#include "IPv4Address.h"
#include "Position.h"
#include <vector>
typedef std::vector<IPv4Address> pathTable;
// }}



/**
 * Class generated from <tt>networklayer/manetrouting/GPS/msgRouting.msg</tt> by opp_msgc.
 * <pre>
 * packet msgRouting {
 *     IPv4Address srcIP;
 *     pathTable path;
 *     
 *     IPv4Address destIP;
 *     Position destPosition;
 *    
 *    
 *   
 * };
 * </pre>
 */
class INET_API msgRouting : public ::cPacket
{
  protected:
    IPv4Address srcIP_var;
    pathTable path_var;
    IPv4Address destIP_var;
    Position destPosition_var;

  private:
    void copy(const msgRouting& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const msgRouting&);

  public:
    msgRouting(const char *name=NULL, int kind=0);
    msgRouting(const msgRouting& other);
    virtual ~msgRouting();
    msgRouting& operator=(const msgRouting& other);
    virtual msgRouting *dup() const {return new msgRouting(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual IPv4Address& getSrcIP();
    virtual const IPv4Address& getSrcIP() const {return const_cast<msgRouting*>(this)->getSrcIP();}
    virtual void setSrcIP(const IPv4Address& srcIP);
    virtual pathTable& getPath();
    virtual const pathTable& getPath() const {return const_cast<msgRouting*>(this)->getPath();}
    virtual void setPath(const pathTable& path);
    virtual IPv4Address& getDestIP();
    virtual const IPv4Address& getDestIP() const {return const_cast<msgRouting*>(this)->getDestIP();}
    virtual void setDestIP(const IPv4Address& destIP);
    virtual Position& getDestPosition();
    virtual const Position& getDestPosition() const {return const_cast<msgRouting*>(this)->getDestPosition();}
    virtual void setDestPosition(const Position& destPosition);
};

inline void doPacking(cCommBuffer *b, msgRouting& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, msgRouting& obj) {obj.parsimUnpack(b);}


#endif // _MSGROUTING_M_H_
