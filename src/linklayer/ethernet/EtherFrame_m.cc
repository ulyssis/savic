//
// Generated file, do not edit! Created by opp_msgc 4.3 from linklayer/ethernet/EtherFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "EtherFrame_m.h"

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




Register_Class(EtherTraffic);

EtherTraffic::EtherTraffic(const char *name, int kind) : cPacket(name,kind)
{
}

EtherTraffic::EtherTraffic(const EtherTraffic& other) : cPacket(other)
{
    copy(other);
}

EtherTraffic::~EtherTraffic()
{
}

EtherTraffic& EtherTraffic::operator=(const EtherTraffic& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void EtherTraffic::copy(const EtherTraffic& other)
{
}

void EtherTraffic::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void EtherTraffic::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class EtherTrafficDescriptor : public cClassDescriptor
{
  public:
    EtherTrafficDescriptor();
    virtual ~EtherTrafficDescriptor();

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

Register_ClassDescriptor(EtherTrafficDescriptor);

EtherTrafficDescriptor::EtherTrafficDescriptor() : cClassDescriptor("EtherTraffic", "cPacket")
{
}

EtherTrafficDescriptor::~EtherTrafficDescriptor()
{
}

bool EtherTrafficDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EtherTraffic *>(obj)!=NULL;
}

const char *EtherTrafficDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EtherTrafficDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int EtherTrafficDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *EtherTrafficDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int EtherTrafficDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EtherTrafficDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *EtherTrafficDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EtherTrafficDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EtherTraffic *pp = (EtherTraffic *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EtherTrafficDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EtherTraffic *pp = (EtherTraffic *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool EtherTrafficDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EtherTraffic *pp = (EtherTraffic *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *EtherTrafficDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *EtherTrafficDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EtherTraffic *pp = (EtherTraffic *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(EtherJam);

EtherJam::EtherJam(const char *name, int kind) : EtherTraffic(name,kind)
{
    this->abortedPkTreeID_var = 0;
}

EtherJam::EtherJam(const EtherJam& other) : EtherTraffic(other)
{
    copy(other);
}

EtherJam::~EtherJam()
{
}

EtherJam& EtherJam::operator=(const EtherJam& other)
{
    if (this==&other) return *this;
    EtherTraffic::operator=(other);
    copy(other);
    return *this;
}

void EtherJam::copy(const EtherJam& other)
{
    this->abortedPkTreeID_var = other.abortedPkTreeID_var;
}

void EtherJam::parsimPack(cCommBuffer *b)
{
    EtherTraffic::parsimPack(b);
    doPacking(b,this->abortedPkTreeID_var);
}

void EtherJam::parsimUnpack(cCommBuffer *b)
{
    EtherTraffic::parsimUnpack(b);
    doUnpacking(b,this->abortedPkTreeID_var);
}

long EtherJam::getAbortedPkTreeID() const
{
    return abortedPkTreeID_var;
}

void EtherJam::setAbortedPkTreeID(long abortedPkTreeID)
{
    this->abortedPkTreeID_var = abortedPkTreeID;
}

class EtherJamDescriptor : public cClassDescriptor
{
  public:
    EtherJamDescriptor();
    virtual ~EtherJamDescriptor();

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

Register_ClassDescriptor(EtherJamDescriptor);

EtherJamDescriptor::EtherJamDescriptor() : cClassDescriptor("EtherJam", "EtherTraffic")
{
}

EtherJamDescriptor::~EtherJamDescriptor()
{
}

bool EtherJamDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EtherJam *>(obj)!=NULL;
}

const char *EtherJamDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EtherJamDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int EtherJamDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *EtherJamDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "abortedPkTreeID",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int EtherJamDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "abortedPkTreeID")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EtherJamDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "long",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *EtherJamDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EtherJamDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EtherJam *pp = (EtherJam *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EtherJamDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EtherJam *pp = (EtherJam *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getAbortedPkTreeID());
        default: return "";
    }
}

bool EtherJamDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EtherJam *pp = (EtherJam *)object; (void)pp;
    switch (field) {
        case 0: pp->setAbortedPkTreeID(string2long(value)); return true;
        default: return false;
    }
}

const char *EtherJamDescriptor::getFieldStructName(void *object, int field) const
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

void *EtherJamDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EtherJam *pp = (EtherJam *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(EtherIFG);

EtherIFG::EtherIFG(const char *name, int kind) : EtherTraffic(name,kind)
{
    this->setBitLength(INTERFRAME_GAP_BITS);
}

EtherIFG::EtherIFG(const EtherIFG& other) : EtherTraffic(other)
{
    copy(other);
}

EtherIFG::~EtherIFG()
{
}

EtherIFG& EtherIFG::operator=(const EtherIFG& other)
{
    if (this==&other) return *this;
    EtherTraffic::operator=(other);
    copy(other);
    return *this;
}

void EtherIFG::copy(const EtherIFG& other)
{
}

void EtherIFG::parsimPack(cCommBuffer *b)
{
    EtherTraffic::parsimPack(b);
}

void EtherIFG::parsimUnpack(cCommBuffer *b)
{
    EtherTraffic::parsimUnpack(b);
}

class EtherIFGDescriptor : public cClassDescriptor
{
  public:
    EtherIFGDescriptor();
    virtual ~EtherIFGDescriptor();

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

Register_ClassDescriptor(EtherIFGDescriptor);

EtherIFGDescriptor::EtherIFGDescriptor() : cClassDescriptor("EtherIFG", "EtherTraffic")
{
}

EtherIFGDescriptor::~EtherIFGDescriptor()
{
}

bool EtherIFGDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EtherIFG *>(obj)!=NULL;
}

const char *EtherIFGDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EtherIFGDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int EtherIFGDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *EtherIFGDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int EtherIFGDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EtherIFGDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *EtherIFGDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EtherIFGDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EtherIFG *pp = (EtherIFG *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EtherIFGDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EtherIFG *pp = (EtherIFG *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool EtherIFGDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EtherIFG *pp = (EtherIFG *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *EtherIFGDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *EtherIFGDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EtherIFG *pp = (EtherIFG *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(EtherFrame);

EtherFrame::EtherFrame(const char *name, int kind) : EtherTraffic(name,kind)
{
    this->frameByteLength_var = 0;
}

EtherFrame::EtherFrame(const EtherFrame& other) : EtherTraffic(other)
{
    copy(other);
}

EtherFrame::~EtherFrame()
{
}

EtherFrame& EtherFrame::operator=(const EtherFrame& other)
{
    if (this==&other) return *this;
    EtherTraffic::operator=(other);
    copy(other);
    return *this;
}

void EtherFrame::copy(const EtherFrame& other)
{
    this->dest_var = other.dest_var;
    this->src_var = other.src_var;
    this->frameByteLength_var = other.frameByteLength_var;
}

void EtherFrame::parsimPack(cCommBuffer *b)
{
    EtherTraffic::parsimPack(b);
    doPacking(b,this->dest_var);
    doPacking(b,this->src_var);
    doPacking(b,this->frameByteLength_var);
}

void EtherFrame::parsimUnpack(cCommBuffer *b)
{
    EtherTraffic::parsimUnpack(b);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->frameByteLength_var);
}

MACAddress& EtherFrame::getDest()
{
    return dest_var;
}

void EtherFrame::setDest(const MACAddress& dest)
{
    this->dest_var = dest;
}

MACAddress& EtherFrame::getSrc()
{
    return src_var;
}

void EtherFrame::setSrc(const MACAddress& src)
{
    this->src_var = src;
}

int EtherFrame::getFrameByteLength() const
{
    return frameByteLength_var;
}

void EtherFrame::setFrameByteLength(int frameByteLength)
{
    this->frameByteLength_var = frameByteLength;
}

class EtherFrameDescriptor : public cClassDescriptor
{
  public:
    EtherFrameDescriptor();
    virtual ~EtherFrameDescriptor();

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

Register_ClassDescriptor(EtherFrameDescriptor);

EtherFrameDescriptor::EtherFrameDescriptor() : cClassDescriptor("EtherFrame", "EtherTraffic")
{
}

EtherFrameDescriptor::~EtherFrameDescriptor()
{
}

bool EtherFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EtherFrame *>(obj)!=NULL;
}

const char *EtherFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EtherFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int EtherFrameDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *EtherFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "dest",
        "src",
        "frameByteLength",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int EtherFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameByteLength")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EtherFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
        "MACAddress",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *EtherFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EtherFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrame *pp = (EtherFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EtherFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrame *pp = (EtherFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDest(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSrc(); return out.str();}
        case 2: return long2string(pp->getFrameByteLength());
        default: return "";
    }
}

bool EtherFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrame *pp = (EtherFrame *)object; (void)pp;
    switch (field) {
        case 2: pp->setFrameByteLength(string2long(value)); return true;
        default: return false;
    }
}

const char *EtherFrameDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "MACAddress",
        "MACAddress",
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *EtherFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrame *pp = (EtherFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDest()); break;
        case 1: return (void *)(&pp->getSrc()); break;
        default: return NULL;
    }
}

Register_Class(EthernetIIFrame);

EthernetIIFrame::EthernetIIFrame(const char *name, int kind) : EtherFrame(name,kind)
{
    this->etherType_var = 0;
}

EthernetIIFrame::EthernetIIFrame(const EthernetIIFrame& other) : EtherFrame(other)
{
    copy(other);
}

EthernetIIFrame::~EthernetIIFrame()
{
}

EthernetIIFrame& EthernetIIFrame::operator=(const EthernetIIFrame& other)
{
    if (this==&other) return *this;
    EtherFrame::operator=(other);
    copy(other);
    return *this;
}

void EthernetIIFrame::copy(const EthernetIIFrame& other)
{
    this->etherType_var = other.etherType_var;
}

void EthernetIIFrame::parsimPack(cCommBuffer *b)
{
    EtherFrame::parsimPack(b);
    doPacking(b,this->etherType_var);
}

void EthernetIIFrame::parsimUnpack(cCommBuffer *b)
{
    EtherFrame::parsimUnpack(b);
    doUnpacking(b,this->etherType_var);
}

int EthernetIIFrame::getEtherType() const
{
    return etherType_var;
}

void EthernetIIFrame::setEtherType(int etherType)
{
    this->etherType_var = etherType;
}

class EthernetIIFrameDescriptor : public cClassDescriptor
{
  public:
    EthernetIIFrameDescriptor();
    virtual ~EthernetIIFrameDescriptor();

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

Register_ClassDescriptor(EthernetIIFrameDescriptor);

EthernetIIFrameDescriptor::EthernetIIFrameDescriptor() : cClassDescriptor("EthernetIIFrame", "EtherFrame")
{
}

EthernetIIFrameDescriptor::~EthernetIIFrameDescriptor()
{
}

bool EthernetIIFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EthernetIIFrame *>(obj)!=NULL;
}

const char *EthernetIIFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EthernetIIFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int EthernetIIFrameDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *EthernetIIFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "etherType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int EthernetIIFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "etherType")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EthernetIIFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *EthernetIIFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "EtherType";
            return NULL;
        default: return NULL;
    }
}

int EthernetIIFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EthernetIIFrame *pp = (EthernetIIFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EthernetIIFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EthernetIIFrame *pp = (EthernetIIFrame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getEtherType());
        default: return "";
    }
}

bool EthernetIIFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EthernetIIFrame *pp = (EthernetIIFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setEtherType(string2long(value)); return true;
        default: return false;
    }
}

const char *EthernetIIFrameDescriptor::getFieldStructName(void *object, int field) const
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

void *EthernetIIFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EthernetIIFrame *pp = (EthernetIIFrame *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(EtherFrameWithLLC);

EtherFrameWithLLC::EtherFrameWithLLC(const char *name, int kind) : EtherFrame(name,kind)
{
    this->dsap_var = 0;
    this->ssap_var = 0;
    this->control_var = 0;
}

EtherFrameWithLLC::EtherFrameWithLLC(const EtherFrameWithLLC& other) : EtherFrame(other)
{
    copy(other);
}

EtherFrameWithLLC::~EtherFrameWithLLC()
{
}

EtherFrameWithLLC& EtherFrameWithLLC::operator=(const EtherFrameWithLLC& other)
{
    if (this==&other) return *this;
    EtherFrame::operator=(other);
    copy(other);
    return *this;
}

void EtherFrameWithLLC::copy(const EtherFrameWithLLC& other)
{
    this->dsap_var = other.dsap_var;
    this->ssap_var = other.ssap_var;
    this->control_var = other.control_var;
}

void EtherFrameWithLLC::parsimPack(cCommBuffer *b)
{
    EtherFrame::parsimPack(b);
    doPacking(b,this->dsap_var);
    doPacking(b,this->ssap_var);
    doPacking(b,this->control_var);
}

void EtherFrameWithLLC::parsimUnpack(cCommBuffer *b)
{
    EtherFrame::parsimUnpack(b);
    doUnpacking(b,this->dsap_var);
    doUnpacking(b,this->ssap_var);
    doUnpacking(b,this->control_var);
}

int EtherFrameWithLLC::getDsap() const
{
    return dsap_var;
}

void EtherFrameWithLLC::setDsap(int dsap)
{
    this->dsap_var = dsap;
}

int EtherFrameWithLLC::getSsap() const
{
    return ssap_var;
}

void EtherFrameWithLLC::setSsap(int ssap)
{
    this->ssap_var = ssap;
}

int EtherFrameWithLLC::getControl() const
{
    return control_var;
}

void EtherFrameWithLLC::setControl(int control)
{
    this->control_var = control;
}

class EtherFrameWithLLCDescriptor : public cClassDescriptor
{
  public:
    EtherFrameWithLLCDescriptor();
    virtual ~EtherFrameWithLLCDescriptor();

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

Register_ClassDescriptor(EtherFrameWithLLCDescriptor);

EtherFrameWithLLCDescriptor::EtherFrameWithLLCDescriptor() : cClassDescriptor("EtherFrameWithLLC", "EtherFrame")
{
}

EtherFrameWithLLCDescriptor::~EtherFrameWithLLCDescriptor()
{
}

bool EtherFrameWithLLCDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EtherFrameWithLLC *>(obj)!=NULL;
}

const char *EtherFrameWithLLCDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EtherFrameWithLLCDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int EtherFrameWithLLCDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *EtherFrameWithLLCDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "dsap",
        "ssap",
        "control",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int EtherFrameWithLLCDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dsap")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssap")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "control")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EtherFrameWithLLCDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *EtherFrameWithLLCDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EtherFrameWithLLCDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrameWithLLC *pp = (EtherFrameWithLLC *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EtherFrameWithLLCDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrameWithLLC *pp = (EtherFrameWithLLC *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDsap());
        case 1: return long2string(pp->getSsap());
        case 2: return long2string(pp->getControl());
        default: return "";
    }
}

bool EtherFrameWithLLCDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrameWithLLC *pp = (EtherFrameWithLLC *)object; (void)pp;
    switch (field) {
        case 0: pp->setDsap(string2long(value)); return true;
        case 1: pp->setSsap(string2long(value)); return true;
        case 2: pp->setControl(string2long(value)); return true;
        default: return false;
    }
}

const char *EtherFrameWithLLCDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *EtherFrameWithLLCDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrameWithLLC *pp = (EtherFrameWithLLC *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(EtherFrameWithSNAP);

EtherFrameWithSNAP::EtherFrameWithSNAP(const char *name, int kind) : EtherFrameWithLLC(name,kind)
{
    this->setDsap(0xAA);
    this->setSsap(0xAA);
    this->setControl(0x03);

    this->orgCode_var = 0;
    this->localcode_var = 0;
}

EtherFrameWithSNAP::EtherFrameWithSNAP(const EtherFrameWithSNAP& other) : EtherFrameWithLLC(other)
{
    copy(other);
}

EtherFrameWithSNAP::~EtherFrameWithSNAP()
{
}

EtherFrameWithSNAP& EtherFrameWithSNAP::operator=(const EtherFrameWithSNAP& other)
{
    if (this==&other) return *this;
    EtherFrameWithLLC::operator=(other);
    copy(other);
    return *this;
}

void EtherFrameWithSNAP::copy(const EtherFrameWithSNAP& other)
{
    this->orgCode_var = other.orgCode_var;
    this->localcode_var = other.localcode_var;
}

void EtherFrameWithSNAP::parsimPack(cCommBuffer *b)
{
    EtherFrameWithLLC::parsimPack(b);
    doPacking(b,this->orgCode_var);
    doPacking(b,this->localcode_var);
}

void EtherFrameWithSNAP::parsimUnpack(cCommBuffer *b)
{
    EtherFrameWithLLC::parsimUnpack(b);
    doUnpacking(b,this->orgCode_var);
    doUnpacking(b,this->localcode_var);
}

int EtherFrameWithSNAP::getOrgCode() const
{
    return orgCode_var;
}

void EtherFrameWithSNAP::setOrgCode(int orgCode)
{
    this->orgCode_var = orgCode;
}

int EtherFrameWithSNAP::getLocalcode() const
{
    return localcode_var;
}

void EtherFrameWithSNAP::setLocalcode(int localcode)
{
    this->localcode_var = localcode;
}

class EtherFrameWithSNAPDescriptor : public cClassDescriptor
{
  public:
    EtherFrameWithSNAPDescriptor();
    virtual ~EtherFrameWithSNAPDescriptor();

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

Register_ClassDescriptor(EtherFrameWithSNAPDescriptor);

EtherFrameWithSNAPDescriptor::EtherFrameWithSNAPDescriptor() : cClassDescriptor("EtherFrameWithSNAP", "EtherFrameWithLLC")
{
}

EtherFrameWithSNAPDescriptor::~EtherFrameWithSNAPDescriptor()
{
}

bool EtherFrameWithSNAPDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EtherFrameWithSNAP *>(obj)!=NULL;
}

const char *EtherFrameWithSNAPDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EtherFrameWithSNAPDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int EtherFrameWithSNAPDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *EtherFrameWithSNAPDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "orgCode",
        "localcode",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int EtherFrameWithSNAPDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "orgCode")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localcode")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EtherFrameWithSNAPDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *EtherFrameWithSNAPDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EtherFrameWithSNAPDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrameWithSNAP *pp = (EtherFrameWithSNAP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EtherFrameWithSNAPDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrameWithSNAP *pp = (EtherFrameWithSNAP *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getOrgCode());
        case 1: return long2string(pp->getLocalcode());
        default: return "";
    }
}

bool EtherFrameWithSNAPDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrameWithSNAP *pp = (EtherFrameWithSNAP *)object; (void)pp;
    switch (field) {
        case 0: pp->setOrgCode(string2long(value)); return true;
        case 1: pp->setLocalcode(string2long(value)); return true;
        default: return false;
    }
}

const char *EtherFrameWithSNAPDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *EtherFrameWithSNAPDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EtherFrameWithSNAP *pp = (EtherFrameWithSNAP *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(EtherPauseFrame);

EtherPauseFrame::EtherPauseFrame(const char *name, int kind) : EtherFrame(name,kind)
{
    this->pauseTime_var = 0;
}

EtherPauseFrame::EtherPauseFrame(const EtherPauseFrame& other) : EtherFrame(other)
{
    copy(other);
}

EtherPauseFrame::~EtherPauseFrame()
{
}

EtherPauseFrame& EtherPauseFrame::operator=(const EtherPauseFrame& other)
{
    if (this==&other) return *this;
    EtherFrame::operator=(other);
    copy(other);
    return *this;
}

void EtherPauseFrame::copy(const EtherPauseFrame& other)
{
    this->pauseTime_var = other.pauseTime_var;
}

void EtherPauseFrame::parsimPack(cCommBuffer *b)
{
    EtherFrame::parsimPack(b);
    doPacking(b,this->pauseTime_var);
}

void EtherPauseFrame::parsimUnpack(cCommBuffer *b)
{
    EtherFrame::parsimUnpack(b);
    doUnpacking(b,this->pauseTime_var);
}

int EtherPauseFrame::getPauseTime() const
{
    return pauseTime_var;
}

void EtherPauseFrame::setPauseTime(int pauseTime)
{
    this->pauseTime_var = pauseTime;
}

class EtherPauseFrameDescriptor : public cClassDescriptor
{
  public:
    EtherPauseFrameDescriptor();
    virtual ~EtherPauseFrameDescriptor();

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

Register_ClassDescriptor(EtherPauseFrameDescriptor);

EtherPauseFrameDescriptor::EtherPauseFrameDescriptor() : cClassDescriptor("EtherPauseFrame", "EtherFrame")
{
}

EtherPauseFrameDescriptor::~EtherPauseFrameDescriptor()
{
}

bool EtherPauseFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EtherPauseFrame *>(obj)!=NULL;
}

const char *EtherPauseFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EtherPauseFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int EtherPauseFrameDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *EtherPauseFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pauseTime",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int EtherPauseFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pauseTime")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EtherPauseFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *EtherPauseFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EtherPauseFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EtherPauseFrame *pp = (EtherPauseFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EtherPauseFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EtherPauseFrame *pp = (EtherPauseFrame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPauseTime());
        default: return "";
    }
}

bool EtherPauseFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EtherPauseFrame *pp = (EtherPauseFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setPauseTime(string2long(value)); return true;
        default: return false;
    }
}

const char *EtherPauseFrameDescriptor::getFieldStructName(void *object, int field) const
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

void *EtherPauseFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EtherPauseFrame *pp = (EtherPauseFrame *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


