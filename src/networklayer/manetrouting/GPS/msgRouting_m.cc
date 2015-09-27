//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/GPS/msgRouting.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "msgRouting_m.h"

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




Register_Class(msgRouting);

msgRouting::msgRouting(const char *name, int kind) : cPacket(name,kind)
{
}

msgRouting::msgRouting(const msgRouting& other) : cPacket(other)
{
    copy(other);
}

msgRouting::~msgRouting()
{
}

msgRouting& msgRouting::operator=(const msgRouting& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void msgRouting::copy(const msgRouting& other)
{
    this->srcIP_var = other.srcIP_var;
    this->path_var = other.path_var;
    this->destIP_var = other.destIP_var;
    this->destPosition_var = other.destPosition_var;
}

void msgRouting::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->srcIP_var);
    doPacking(b,this->path_var);
    doPacking(b,this->destIP_var);
    doPacking(b,this->destPosition_var);
}

void msgRouting::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcIP_var);
    doUnpacking(b,this->path_var);
    doUnpacking(b,this->destIP_var);
    doUnpacking(b,this->destPosition_var);
}

IPv4Address& msgRouting::getSrcIP()
{
    return srcIP_var;
}

void msgRouting::setSrcIP(const IPv4Address& srcIP)
{
    this->srcIP_var = srcIP;
}

pathTable& msgRouting::getPath()
{
    return path_var;
}

void msgRouting::setPath(const pathTable& path)
{
    this->path_var = path;
}

IPv4Address& msgRouting::getDestIP()
{
    return destIP_var;
}

void msgRouting::setDestIP(const IPv4Address& destIP)
{
    this->destIP_var = destIP;
}

Position& msgRouting::getDestPosition()
{
    return destPosition_var;
}

void msgRouting::setDestPosition(const Position& destPosition)
{
    this->destPosition_var = destPosition;
}

class msgRoutingDescriptor : public cClassDescriptor
{
  public:
    msgRoutingDescriptor();
    virtual ~msgRoutingDescriptor();

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

Register_ClassDescriptor(msgRoutingDescriptor);

msgRoutingDescriptor::msgRoutingDescriptor() : cClassDescriptor("msgRouting", "cPacket")
{
}

msgRoutingDescriptor::~msgRoutingDescriptor()
{
}

bool msgRoutingDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<msgRouting *>(obj)!=NULL;
}

const char *msgRoutingDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int msgRoutingDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int msgRoutingDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *msgRoutingDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcIP",
        "path",
        "destIP",
        "destPosition",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int msgRoutingDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIP")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "path")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIP")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPosition")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *msgRoutingDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "pathTable",
        "IPv4Address",
        "Position",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *msgRoutingDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int msgRoutingDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    msgRouting *pp = (msgRouting *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string msgRoutingDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    msgRouting *pp = (msgRouting *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcIP(); return out.str();}
        case 1: {std::stringstream out; out << pp->getPath(); return out.str();}
        case 2: {std::stringstream out; out << pp->getDestIP(); return out.str();}
        case 3: {std::stringstream out; out << pp->getDestPosition(); return out.str();}
        default: return "";
    }
}

bool msgRoutingDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    msgRouting *pp = (msgRouting *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *msgRoutingDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPv4Address",
        "pathTable",
        "IPv4Address",
        "Position",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *msgRoutingDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    msgRouting *pp = (msgRouting *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcIP()); break;
        case 1: return (void *)(&pp->getPath()); break;
        case 2: return (void *)(&pp->getDestIP()); break;
        case 3: return (void *)(&pp->getDestPosition()); break;
        default: return NULL;
    }
}


