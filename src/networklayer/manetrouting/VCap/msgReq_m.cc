//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/VCap/msgReq.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "msgReq_m.h"

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




Register_Class(msgReq);

msgReq::msgReq(const char *name, int kind) : cPacket(name,kind)
{
}

msgReq::msgReq(const msgReq& other) : cPacket(other)
{
    copy(other);
}

msgReq::~msgReq()
{
}

msgReq& msgReq::operator=(const msgReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void msgReq::copy(const msgReq& other)
{
    this->srcIP_var = other.srcIP_var;
    this->destIP_var = other.destIP_var;
}

void msgReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->srcIP_var);
    doPacking(b,this->destIP_var);
}

void msgReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcIP_var);
    doUnpacking(b,this->destIP_var);
}

IPv4Address& msgReq::getSrcIP()
{
    return srcIP_var;
}

void msgReq::setSrcIP(const IPv4Address& srcIP)
{
    this->srcIP_var = srcIP;
}

IPv4Address& msgReq::getDestIP()
{
    return destIP_var;
}

void msgReq::setDestIP(const IPv4Address& destIP)
{
    this->destIP_var = destIP;
}

class msgReqDescriptor : public cClassDescriptor
{
  public:
    msgReqDescriptor();
    virtual ~msgReqDescriptor();

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

Register_ClassDescriptor(msgReqDescriptor);

msgReqDescriptor::msgReqDescriptor() : cClassDescriptor("msgReq", "cPacket")
{
}

msgReqDescriptor::~msgReqDescriptor()
{
}

bool msgReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<msgReq *>(obj)!=NULL;
}

const char *msgReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int msgReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int msgReqDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *msgReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcIP",
        "destIP",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int msgReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIP")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIP")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *msgReqDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *msgReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int msgReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    msgReq *pp = (msgReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string msgReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    msgReq *pp = (msgReq *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcIP(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDestIP(); return out.str();}
        default: return "";
    }
}

bool msgReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    msgReq *pp = (msgReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *msgReqDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *msgReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    msgReq *pp = (msgReq *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcIP()); break;
        case 1: return (void *)(&pp->getDestIP()); break;
        default: return NULL;
    }
}


