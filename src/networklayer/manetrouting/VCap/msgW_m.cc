//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/VCap/msgW.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "msgW_m.h"

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




Register_Class(msgW);

msgW::msgW(const char *name, int kind) : cPacket(name,kind)
{
    this->phase_var = PHASE_NULL;
    this->srcW_var = 0;
    this->srcX_var = 0;
    this->hop_var = 0;
}

msgW::msgW(const msgW& other) : cPacket(other)
{
    copy(other);
}

msgW::~msgW()
{
}

msgW& msgW::operator=(const msgW& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void msgW::copy(const msgW& other)
{
    this->phase_var = other.phase_var;
    this->path_var = other.path_var;
    this->srcIP_var = other.srcIP_var;
    this->srcW_var = other.srcW_var;
    this->srcX_var = other.srcX_var;
    this->hop_var = other.hop_var;
}

void msgW::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->phase_var);
    doPacking(b,this->path_var);
    doPacking(b,this->srcIP_var);
    doPacking(b,this->srcW_var);
    doPacking(b,this->srcX_var);
    doPacking(b,this->hop_var);
}

void msgW::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->phase_var);
    doUnpacking(b,this->path_var);
    doUnpacking(b,this->srcIP_var);
    doUnpacking(b,this->srcW_var);
    doUnpacking(b,this->srcX_var);
    doUnpacking(b,this->hop_var);
}

int msgW::getPhase() const
{
    return phase_var;
}

void msgW::setPhase(int phase)
{
    this->phase_var = phase;
}

pathTable& msgW::getPath()
{
    return path_var;
}

void msgW::setPath(const pathTable& path)
{
    this->path_var = path;
}

IPv4Address& msgW::getSrcIP()
{
    return srcIP_var;
}

void msgW::setSrcIP(const IPv4Address& srcIP)
{
    this->srcIP_var = srcIP;
}

double msgW::getSrcW() const
{
    return srcW_var;
}

void msgW::setSrcW(double srcW)
{
    this->srcW_var = srcW;
}

double msgW::getSrcX() const
{
    return srcX_var;
}

void msgW::setSrcX(double srcX)
{
    this->srcX_var = srcX;
}

double msgW::getHop() const
{
    return hop_var;
}

void msgW::setHop(double hop)
{
    this->hop_var = hop;
}

class msgWDescriptor : public cClassDescriptor
{
  public:
    msgWDescriptor();
    virtual ~msgWDescriptor();

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

Register_ClassDescriptor(msgWDescriptor);

msgWDescriptor::msgWDescriptor() : cClassDescriptor("msgW", "cPacket")
{
}

msgWDescriptor::~msgWDescriptor()
{
}

bool msgWDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<msgW *>(obj)!=NULL;
}

const char *msgWDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int msgWDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int msgWDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *msgWDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "phase",
        "path",
        "srcIP",
        "srcW",
        "srcX",
        "hop",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int msgWDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "phase")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "path")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIP")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcW")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcX")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *msgWDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "pathTable",
        "IPv4Address",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *msgWDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int msgWDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    msgW *pp = (msgW *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string msgWDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    msgW *pp = (msgW *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPhase());
        case 1: {std::stringstream out; out << pp->getPath(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSrcIP(); return out.str();}
        case 3: return double2string(pp->getSrcW());
        case 4: return double2string(pp->getSrcX());
        case 5: return double2string(pp->getHop());
        default: return "";
    }
}

bool msgWDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    msgW *pp = (msgW *)object; (void)pp;
    switch (field) {
        case 0: pp->setPhase(string2long(value)); return true;
        case 3: pp->setSrcW(string2double(value)); return true;
        case 4: pp->setSrcX(string2double(value)); return true;
        case 5: pp->setHop(string2double(value)); return true;
        default: return false;
    }
}

const char *msgWDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "pathTable",
        "IPv4Address",
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *msgWDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    msgW *pp = (msgW *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getPath()); break;
        case 2: return (void *)(&pp->getSrcIP()); break;
        default: return NULL;
    }
}


