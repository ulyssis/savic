//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/ospfv2/OSPFTimer.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "OSPFTimer_m.h"

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




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("OSPFTimerType");
    if (!e) enums.getInstance()->add(e = new cEnum("OSPFTimerType"));
    e->insert(INTERFACE_HELLO_TIMER, "INTERFACE_HELLO_TIMER");
    e->insert(INTERFACE_WAIT_TIMER, "INTERFACE_WAIT_TIMER");
    e->insert(INTERFACE_ACKNOWLEDGEMENT_TIMER, "INTERFACE_ACKNOWLEDGEMENT_TIMER");
    e->insert(NEIGHBOR_INACTIVITY_TIMER, "NEIGHBOR_INACTIVITY_TIMER");
    e->insert(NEIGHBOR_POLL_TIMER, "NEIGHBOR_POLL_TIMER");
    e->insert(NEIGHBOR_DD_RETRANSMISSION_TIMER, "NEIGHBOR_DD_RETRANSMISSION_TIMER");
    e->insert(NEIGHBOR_UPDATE_RETRANSMISSION_TIMER, "NEIGHBOR_UPDATE_RETRANSMISSION_TIMER");
    e->insert(NEIGHBOR_REQUEST_RETRANSMISSION_TIMER, "NEIGHBOR_REQUEST_RETRANSMISSION_TIMER");
    e->insert(DATABASE_AGE_TIMER, "DATABASE_AGE_TIMER");
);

Register_Class(OSPFTimer);

OSPFTimer::OSPFTimer(const char *name, int kind) : cMessage(name,kind)
{
    this->timerKind_var = INTERFACE_HELLO_TIMER;
}

OSPFTimer::OSPFTimer(const OSPFTimer& other) : cMessage(other)
{
    copy(other);
}

OSPFTimer::~OSPFTimer()
{
}

OSPFTimer& OSPFTimer::operator=(const OSPFTimer& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void OSPFTimer::copy(const OSPFTimer& other)
{
    this->timerKind_var = other.timerKind_var;
}

void OSPFTimer::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->timerKind_var);
}

void OSPFTimer::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->timerKind_var);
}

char OSPFTimer::getTimerKind() const
{
    return timerKind_var;
}

void OSPFTimer::setTimerKind(char timerKind)
{
    this->timerKind_var = timerKind;
}

class OSPFTimerDescriptor : public cClassDescriptor
{
  public:
    OSPFTimerDescriptor();
    virtual ~OSPFTimerDescriptor();

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

Register_ClassDescriptor(OSPFTimerDescriptor);

OSPFTimerDescriptor::OSPFTimerDescriptor() : cClassDescriptor("OSPFTimer", "cMessage")
{
}

OSPFTimerDescriptor::~OSPFTimerDescriptor()
{
}

bool OSPFTimerDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OSPFTimer *>(obj)!=NULL;
}

const char *OSPFTimerDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OSPFTimerDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int OSPFTimerDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFTimerDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "timerKind",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int OSPFTimerDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timerKind")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OSPFTimerDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "char",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *OSPFTimerDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "OSPFTimerType";
            return NULL;
        default: return NULL;
    }
}

int OSPFTimerDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OSPFTimer *pp = (OSPFTimer *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFTimerDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OSPFTimer *pp = (OSPFTimer *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTimerKind());
        default: return "";
    }
}

bool OSPFTimerDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OSPFTimer *pp = (OSPFTimer *)object; (void)pp;
    switch (field) {
        case 0: pp->setTimerKind(string2long(value)); return true;
        default: return false;
    }
}

const char *OSPFTimerDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *OSPFTimerDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OSPFTimer *pp = (OSPFTimer *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


