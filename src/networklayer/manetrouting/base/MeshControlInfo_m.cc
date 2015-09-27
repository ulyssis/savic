//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/base/MeshControlInfo.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MeshControlInfo_m.h"

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




MeshControlInfo::MeshControlInfo() : Ieee802Ctrl()
{
    this->inputId_var = 0;
    this->previousFix_var = 0;
    vectorAddress_arraysize = 0;
    this->vectorAddress_var = 0;
}

MeshControlInfo::MeshControlInfo(const MeshControlInfo& other) : Ieee802Ctrl(other)
{
    vectorAddress_arraysize = 0;
    this->vectorAddress_var = 0;
    copy(other);
}

MeshControlInfo::~MeshControlInfo()
{
    delete [] vectorAddress_var;
}

MeshControlInfo& MeshControlInfo::operator=(const MeshControlInfo& other)
{
    if (this==&other) return *this;
    Ieee802Ctrl::operator=(other);
    copy(other);
    return *this;
}

void MeshControlInfo::copy(const MeshControlInfo& other)
{
    this->inputId_var = other.inputId_var;
    this->previousFix_var = other.previousFix_var;
    delete [] this->vectorAddress_var;
    this->vectorAddress_var = (other.vectorAddress_arraysize==0) ? NULL : new Uint128[other.vectorAddress_arraysize];
    vectorAddress_arraysize = other.vectorAddress_arraysize;
    for (unsigned int i=0; i<vectorAddress_arraysize; i++)
        this->vectorAddress_var[i] = other.vectorAddress_var[i];
}

void MeshControlInfo::parsimPack(cCommBuffer *b)
{
    doPacking(b,(Ieee802Ctrl&)*this);
    doPacking(b,this->inputId_var);
    doPacking(b,this->previousFix_var);
    b->pack(vectorAddress_arraysize);
    doPacking(b,this->vectorAddress_var,vectorAddress_arraysize);
}

void MeshControlInfo::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,(Ieee802Ctrl&)*this);
    doUnpacking(b,this->inputId_var);
    doUnpacking(b,this->previousFix_var);
    delete [] this->vectorAddress_var;
    b->unpack(vectorAddress_arraysize);
    if (vectorAddress_arraysize==0) {
        this->vectorAddress_var = 0;
    } else {
        this->vectorAddress_var = new Uint128[vectorAddress_arraysize];
        doUnpacking(b,this->vectorAddress_var,vectorAddress_arraysize);
    }
}

int MeshControlInfo::getInputId() const
{
    return inputId_var;
}

void MeshControlInfo::setInputId(int inputId)
{
    this->inputId_var = inputId;
}

bool MeshControlInfo::getPreviousFix() const
{
    return previousFix_var;
}

void MeshControlInfo::setPreviousFix(bool previousFix)
{
    this->previousFix_var = previousFix;
}

void MeshControlInfo::setVectorAddressArraySize(unsigned int size)
{
    Uint128 *vectorAddress_var2 = (size==0) ? NULL : new Uint128[size];
    unsigned int sz = vectorAddress_arraysize < size ? vectorAddress_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        vectorAddress_var2[i] = this->vectorAddress_var[i];
    vectorAddress_arraysize = size;
    delete [] this->vectorAddress_var;
    this->vectorAddress_var = vectorAddress_var2;
}

unsigned int MeshControlInfo::getVectorAddressArraySize() const
{
    return vectorAddress_arraysize;
}

Uint128& MeshControlInfo::getVectorAddress(unsigned int k)
{
    if (k>=vectorAddress_arraysize) throw cRuntimeError("Array of size %d indexed by %d", vectorAddress_arraysize, k);
    return vectorAddress_var[k];
}

void MeshControlInfo::setVectorAddress(unsigned int k, const Uint128& vectorAddress)
{
    if (k>=vectorAddress_arraysize) throw cRuntimeError("Array of size %d indexed by %d", vectorAddress_arraysize, k);
    this->vectorAddress_var[k] = vectorAddress;
}

class MeshControlInfoDescriptor : public cClassDescriptor
{
  public:
    MeshControlInfoDescriptor();
    virtual ~MeshControlInfoDescriptor();

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

Register_ClassDescriptor(MeshControlInfoDescriptor);

MeshControlInfoDescriptor::MeshControlInfoDescriptor() : cClassDescriptor("MeshControlInfo", "Ieee802Ctrl")
{
}

MeshControlInfoDescriptor::~MeshControlInfoDescriptor()
{
}

bool MeshControlInfoDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MeshControlInfo *>(obj)!=NULL;
}

const char *MeshControlInfoDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MeshControlInfoDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MeshControlInfoDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *MeshControlInfoDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "inputId",
        "previousFix",
        "vectorAddress",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int MeshControlInfoDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "inputId")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "previousFix")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "vectorAddress")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MeshControlInfoDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "Uint128",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *MeshControlInfoDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MeshControlInfoDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MeshControlInfo *pp = (MeshControlInfo *)object; (void)pp;
    switch (field) {
        case 2: return pp->getVectorAddressArraySize();
        default: return 0;
    }
}

std::string MeshControlInfoDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MeshControlInfo *pp = (MeshControlInfo *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInputId());
        case 1: return bool2string(pp->getPreviousFix());
        case 2: {std::stringstream out; out << pp->getVectorAddress(i); return out.str();}
        default: return "";
    }
}

bool MeshControlInfoDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MeshControlInfo *pp = (MeshControlInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setInputId(string2long(value)); return true;
        case 1: pp->setPreviousFix(string2bool(value)); return true;
        default: return false;
    }
}

const char *MeshControlInfoDescriptor::getFieldStructName(void *object, int field) const
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
        "Uint128",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *MeshControlInfoDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MeshControlInfo *pp = (MeshControlInfo *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getVectorAddress(i)); break;
        default: return NULL;
    }
}


