//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/search/searRouteRequest.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "searRouteRequest_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(SearRouteRequest);

SearRouteRequest::SearRouteRequest(const char *name, int kind) : cPacket(name,kind)
{
    this->workingChannel_var = 0;
}

SearRouteRequest::SearRouteRequest(const SearRouteRequest& other) : cPacket(other)
{
    copy(other);
}

SearRouteRequest::~SearRouteRequest()
{
}

SearRouteRequest& SearRouteRequest::operator=(const SearRouteRequest& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SearRouteRequest::copy(const SearRouteRequest& other)
{
    this->src_var = other.src_var;
    this->dst_var = other.dst_var;
    this->srcPos_var = other.srcPos_var;
    this->dstPos_var = other.dstPos_var;
    this->workingChannel_var = other.workingChannel_var;
    this->pathList_var = other.pathList_var;
    this->DPList_var = other.DPList_var;
}

void SearRouteRequest::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->src_var);
    doPacking(b,this->dst_var);
    doPacking(b,this->srcPos_var);
    doPacking(b,this->dstPos_var);
    doPacking(b,this->workingChannel_var);
    doPacking(b,this->pathList_var);
    doPacking(b,this->DPList_var);
}

void SearRouteRequest::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->dst_var);
    doUnpacking(b,this->srcPos_var);
    doUnpacking(b,this->dstPos_var);
    doUnpacking(b,this->workingChannel_var);
    doUnpacking(b,this->pathList_var);
    doUnpacking(b,this->DPList_var);
}

IPv4Address& SearRouteRequest::getSrc()
{
    return src_var;
}

void SearRouteRequest::setSrc(const IPv4Address& src)
{
    this->src_var = src;
}

IPv4Address& SearRouteRequest::getDst()
{
    return dst_var;
}

void SearRouteRequest::setDst(const IPv4Address& dst)
{
    this->dst_var = dst;
}

Coord& SearRouteRequest::getSrcPos()
{
    return srcPos_var;
}

void SearRouteRequest::setSrcPos(const Coord& srcPos)
{
    this->srcPos_var = srcPos;
}

Coord& SearRouteRequest::getDstPos()
{
    return dstPos_var;
}

void SearRouteRequest::setDstPos(const Coord& dstPos)
{
    this->dstPos_var = dstPos;
}

bool SearRouteRequest::getWorkingChannel() const
{
    return workingChannel_var;
}

void SearRouteRequest::setWorkingChannel(bool workingChannel)
{
    this->workingChannel_var = workingChannel;
}

PathList& SearRouteRequest::getPathList()
{
    return pathList_var;
}

void SearRouteRequest::setPathList(const PathList& pathList)
{
    this->pathList_var = pathList;
}

PathList& SearRouteRequest::getDPList()
{
    return DPList_var;
}

void SearRouteRequest::setDPList(const PathList& DPList)
{
    this->DPList_var = DPList;
}

class SearRouteRequestDescriptor : public cClassDescriptor
{
  public:
    SearRouteRequestDescriptor();
    virtual ~SearRouteRequestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SearRouteRequestDescriptor);

SearRouteRequestDescriptor::SearRouteRequestDescriptor() : cClassDescriptor("SearRouteRequest", "cPacket")
{
}

SearRouteRequestDescriptor::~SearRouteRequestDescriptor()
{
}

bool SearRouteRequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SearRouteRequest *>(obj)!=NULL;
}

const char *SearRouteRequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SearRouteRequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int SearRouteRequestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *SearRouteRequestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "src",
        "dst",
        "srcPos",
        "dstPos",
        "workingChannel",
        "pathList",
        "DPList",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int SearRouteRequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dst")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPos")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstPos")==0) return base+3;
    if (fieldName[0]=='w' && strcmp(fieldName, "workingChannel")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathList")==0) return base+5;
    if (fieldName[0]=='D' && strcmp(fieldName, "DPList")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SearRouteRequestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "IPv4Address",
        "Coord",
        "Coord",
        "bool",
        "PathList",
        "PathList",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *SearRouteRequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SearRouteRequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SearRouteRequest *pp = (SearRouteRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SearRouteRequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SearRouteRequest *pp = (SearRouteRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrc(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDst(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSrcPos(); return out.str();}
        case 3: {std::stringstream out; out << pp->getDstPos(); return out.str();}
        case 4: return bool2string(pp->getWorkingChannel());
        case 5: {std::stringstream out; out << pp->getPathList(); return out.str();}
        case 6: {std::stringstream out; out << pp->getDPList(); return out.str();}
        default: return "";
    }
}

bool SearRouteRequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SearRouteRequest *pp = (SearRouteRequest *)object; (void)pp;
    switch (field) {
        case 4: pp->setWorkingChannel(string2bool(value)); return true;
        default: return false;
    }
}

const char *SearRouteRequestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPv4Address",
        "IPv4Address",
        "Coord",
        "Coord",
        NULL,
        "PathList",
        "PathList",
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *SearRouteRequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SearRouteRequest *pp = (SearRouteRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrc()); break;
        case 1: return (void *)(&pp->getDst()); break;
        case 2: return (void *)(&pp->getSrcPos()); break;
        case 3: return (void *)(&pp->getDstPos()); break;
        case 5: return (void *)(&pp->getPathList()); break;
        case 6: return (void *)(&pp->getDPList()); break;
        default: return NULL;
    }
}


