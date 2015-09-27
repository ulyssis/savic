//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/VCap/msgToRoute.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "msgToRoute_m.h"

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




Register_Class(msgToRoute);

msgToRoute::msgToRoute(const char *name, int kind) : cPacket(name,kind)
{
}

msgToRoute::msgToRoute(const msgToRoute& other) : cPacket(other)
{
    copy(other);
}

msgToRoute::~msgToRoute()
{
}

msgToRoute& msgToRoute::operator=(const msgToRoute& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void msgToRoute::copy(const msgToRoute& other)
{
    this->srcIP_var = other.srcIP_var;
    this->destIP_var = other.destIP_var;
    this->destVC_var = other.destVC_var;
    this->deadendList_var = other.deadendList_var;
    this->pathList_var = other.pathList_var;
}

void msgToRoute::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->srcIP_var);
    doPacking(b,this->destIP_var);
    doPacking(b,this->destVC_var);
    doPacking(b,this->deadendList_var);
    doPacking(b,this->pathList_var);
}

void msgToRoute::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcIP_var);
    doUnpacking(b,this->destIP_var);
    doUnpacking(b,this->destVC_var);
    doUnpacking(b,this->deadendList_var);
    doUnpacking(b,this->pathList_var);
}

IPv4Address& msgToRoute::getSrcIP()
{
    return srcIP_var;
}

void msgToRoute::setSrcIP(const IPv4Address& srcIP)
{
    this->srcIP_var = srcIP;
}

IPv4Address& msgToRoute::getDestIP()
{
    return destIP_var;
}

void msgToRoute::setDestIP(const IPv4Address& destIP)
{
    this->destIP_var = destIP;
}

VCoord& msgToRoute::getDestVC()
{
    return destVC_var;
}

void msgToRoute::setDestVC(const VCoord& destVC)
{
    this->destVC_var = destVC;
}

DeadendList& msgToRoute::getDeadendList()
{
    return deadendList_var;
}

void msgToRoute::setDeadendList(const DeadendList& deadendList)
{
    this->deadendList_var = deadendList;
}

PathList& msgToRoute::getPathList()
{
    return pathList_var;
}

void msgToRoute::setPathList(const PathList& pathList)
{
    this->pathList_var = pathList;
}

class msgToRouteDescriptor : public cClassDescriptor
{
  public:
    msgToRouteDescriptor();
    virtual ~msgToRouteDescriptor();

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

Register_ClassDescriptor(msgToRouteDescriptor);

msgToRouteDescriptor::msgToRouteDescriptor() : cClassDescriptor("msgToRoute", "cPacket")
{
}

msgToRouteDescriptor::~msgToRouteDescriptor()
{
}

bool msgToRouteDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<msgToRoute *>(obj)!=NULL;
}

const char *msgToRouteDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int msgToRouteDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int msgToRouteDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *msgToRouteDescriptor::getFieldName(void *object, int field) const
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
        "destVC",
        "deadendList",
        "pathList",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int msgToRouteDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIP")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIP")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destVC")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "deadendList")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathList")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *msgToRouteDescriptor::getFieldTypeString(void *object, int field) const
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
        "VCoord",
        "DeadendList",
        "PathList",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *msgToRouteDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int msgToRouteDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    msgToRoute *pp = (msgToRoute *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string msgToRouteDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    msgToRoute *pp = (msgToRoute *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcIP(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDestIP(); return out.str();}
        case 2: {std::stringstream out; out << pp->getDestVC(); return out.str();}
        case 3: {std::stringstream out; out << pp->getDeadendList(); return out.str();}
        case 4: {std::stringstream out; out << pp->getPathList(); return out.str();}
        default: return "";
    }
}

bool msgToRouteDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    msgToRoute *pp = (msgToRoute *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *msgToRouteDescriptor::getFieldStructName(void *object, int field) const
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
        "VCoord",
        "DeadendList",
        "PathList",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *msgToRouteDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    msgToRoute *pp = (msgToRoute *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcIP()); break;
        case 1: return (void *)(&pp->getDestIP()); break;
        case 2: return (void *)(&pp->getDestVC()); break;
        case 3: return (void *)(&pp->getDeadendList()); break;
        case 4: return (void *)(&pp->getPathList()); break;
        default: return NULL;
    }
}


