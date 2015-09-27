//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/berger/BergerRouteRequest.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "BergerRouteRequest_m.h"

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




Register_Class(BergerRouteRequest);

BergerRouteRequest::BergerRouteRequest(const char *name, int kind) : cPacket(name,kind)
{
}

BergerRouteRequest::BergerRouteRequest(const BergerRouteRequest& other) : cPacket(other)
{
    copy(other);
}

BergerRouteRequest::~BergerRouteRequest()
{
}

BergerRouteRequest& BergerRouteRequest::operator=(const BergerRouteRequest& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void BergerRouteRequest::copy(const BergerRouteRequest& other)
{
    this->src_var = other.src_var;
    this->dst_var = other.dst_var;
    this->srcPos_var = other.srcPos_var;
    this->dstPos_var = other.dstPos_var;
}

void BergerRouteRequest::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->src_var);
    doPacking(b,this->dst_var);
    doPacking(b,this->srcPos_var);
    doPacking(b,this->dstPos_var);
}

void BergerRouteRequest::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->dst_var);
    doUnpacking(b,this->srcPos_var);
    doUnpacking(b,this->dstPos_var);
}

IPv4Address& BergerRouteRequest::getSrc()
{
    return src_var;
}

void BergerRouteRequest::setSrc(const IPv4Address& src)
{
    this->src_var = src;
}

IPv4Address& BergerRouteRequest::getDst()
{
    return dst_var;
}

void BergerRouteRequest::setDst(const IPv4Address& dst)
{
    this->dst_var = dst;
}

Coord& BergerRouteRequest::getSrcPos()
{
    return srcPos_var;
}

void BergerRouteRequest::setSrcPos(const Coord& srcPos)
{
    this->srcPos_var = srcPos;
}

Coord& BergerRouteRequest::getDstPos()
{
    return dstPos_var;
}

void BergerRouteRequest::setDstPos(const Coord& dstPos)
{
    this->dstPos_var = dstPos;
}

class BergerRouteRequestDescriptor : public cClassDescriptor
{
  public:
    BergerRouteRequestDescriptor();
    virtual ~BergerRouteRequestDescriptor();

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

Register_ClassDescriptor(BergerRouteRequestDescriptor);

BergerRouteRequestDescriptor::BergerRouteRequestDescriptor() : cClassDescriptor("BergerRouteRequest", "cPacket")
{
}

BergerRouteRequestDescriptor::~BergerRouteRequestDescriptor()
{
}

bool BergerRouteRequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BergerRouteRequest *>(obj)!=NULL;
}

const char *BergerRouteRequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BergerRouteRequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int BergerRouteRequestDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *BergerRouteRequestDescriptor::getFieldName(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int BergerRouteRequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dst")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPos")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstPos")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BergerRouteRequestDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *BergerRouteRequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BergerRouteRequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BergerRouteRequest *pp = (BergerRouteRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BergerRouteRequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BergerRouteRequest *pp = (BergerRouteRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrc(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDst(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSrcPos(); return out.str();}
        case 3: {std::stringstream out; out << pp->getDstPos(); return out.str();}
        default: return "";
    }
}

bool BergerRouteRequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BergerRouteRequest *pp = (BergerRouteRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BergerRouteRequestDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *BergerRouteRequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BergerRouteRequest *pp = (BergerRouteRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrc()); break;
        case 1: return (void *)(&pp->getDst()); break;
        case 2: return (void *)(&pp->getSrcPos()); break;
        case 3: return (void *)(&pp->getDstPos()); break;
        default: return NULL;
    }
}


