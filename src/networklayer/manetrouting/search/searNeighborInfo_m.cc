//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/search/searNeighborInfo.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "searNeighborInfo_m.h"

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




Register_Class(searNeighborInfo);

searNeighborInfo::searNeighborInfo(const char *name, int kind) : cPacket(name,kind)
{
    this->routerXPos_var = 0;
    this->routerYPos_var = 0;
    this->workingChannel_var = 0;
    this->dist2Dst_var = 0;
}

searNeighborInfo::searNeighborInfo(const searNeighborInfo& other) : cPacket(other)
{
    copy(other);
}

searNeighborInfo::~searNeighborInfo()
{
}

searNeighborInfo& searNeighborInfo::operator=(const searNeighborInfo& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void searNeighborInfo::copy(const searNeighborInfo& other)
{
    this->routerAddress_var = other.routerAddress_var;
    this->routerXPos_var = other.routerXPos_var;
    this->routerYPos_var = other.routerYPos_var;
    this->workingChannel_var = other.workingChannel_var;
    this->dist2Dst_var = other.dist2Dst_var;
}

void searNeighborInfo::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->routerAddress_var);
    doPacking(b,this->routerXPos_var);
    doPacking(b,this->routerYPos_var);
    doPacking(b,this->workingChannel_var);
    doPacking(b,this->dist2Dst_var);
}

void searNeighborInfo::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->routerAddress_var);
    doUnpacking(b,this->routerXPos_var);
    doUnpacking(b,this->routerYPos_var);
    doUnpacking(b,this->workingChannel_var);
    doUnpacking(b,this->dist2Dst_var);
}

IPv4Address& searNeighborInfo::getRouterAddress()
{
    return routerAddress_var;
}

void searNeighborInfo::setRouterAddress(const IPv4Address& routerAddress)
{
    this->routerAddress_var = routerAddress;
}

double searNeighborInfo::getRouterXPos() const
{
    return routerXPos_var;
}

void searNeighborInfo::setRouterXPos(double routerXPos)
{
    this->routerXPos_var = routerXPos;
}

double searNeighborInfo::getRouterYPos() const
{
    return routerYPos_var;
}

void searNeighborInfo::setRouterYPos(double routerYPos)
{
    this->routerYPos_var = routerYPos;
}

bool searNeighborInfo::getWorkingChannel() const
{
    return workingChannel_var;
}

void searNeighborInfo::setWorkingChannel(bool workingChannel)
{
    this->workingChannel_var = workingChannel;
}

int searNeighborInfo::getDist2Dst() const
{
    return dist2Dst_var;
}

void searNeighborInfo::setDist2Dst(int dist2Dst)
{
    this->dist2Dst_var = dist2Dst;
}

class searNeighborInfoDescriptor : public cClassDescriptor
{
  public:
    searNeighborInfoDescriptor();
    virtual ~searNeighborInfoDescriptor();

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

Register_ClassDescriptor(searNeighborInfoDescriptor);

searNeighborInfoDescriptor::searNeighborInfoDescriptor() : cClassDescriptor("searNeighborInfo", "cPacket")
{
}

searNeighborInfoDescriptor::~searNeighborInfoDescriptor()
{
}

bool searNeighborInfoDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<searNeighborInfo *>(obj)!=NULL;
}

const char *searNeighborInfoDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int searNeighborInfoDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int searNeighborInfoDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *searNeighborInfoDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "routerAddress",
        "routerXPos",
        "routerYPos",
        "workingChannel",
        "dist2Dst",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int searNeighborInfoDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerAddress")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerXPos")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerYPos")==0) return base+2;
    if (fieldName[0]=='w' && strcmp(fieldName, "workingChannel")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "dist2Dst")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *searNeighborInfoDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "double",
        "double",
        "bool",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *searNeighborInfoDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int searNeighborInfoDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    searNeighborInfo *pp = (searNeighborInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string searNeighborInfoDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    searNeighborInfo *pp = (searNeighborInfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRouterAddress(); return out.str();}
        case 1: return double2string(pp->getRouterXPos());
        case 2: return double2string(pp->getRouterYPos());
        case 3: return bool2string(pp->getWorkingChannel());
        case 4: return long2string(pp->getDist2Dst());
        default: return "";
    }
}

bool searNeighborInfoDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    searNeighborInfo *pp = (searNeighborInfo *)object; (void)pp;
    switch (field) {
        case 1: pp->setRouterXPos(string2double(value)); return true;
        case 2: pp->setRouterYPos(string2double(value)); return true;
        case 3: pp->setWorkingChannel(string2bool(value)); return true;
        case 4: pp->setDist2Dst(string2long(value)); return true;
        default: return false;
    }
}

const char *searNeighborInfoDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPv4Address",
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *searNeighborInfoDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    searNeighborInfo *pp = (searNeighborInfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRouterAddress()); break;
        default: return NULL;
    }
}


