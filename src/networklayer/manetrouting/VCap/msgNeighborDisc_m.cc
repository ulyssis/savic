//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/manetrouting/VCap/msgNeighborDisc.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "msgNeighborDisc_m.h"

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




Register_Class(msgNeighborDisc);

msgNeighborDisc::msgNeighborDisc(const char *name, int kind) : cPacket(name,kind)
{
    this->W_var = 10000;
    this->X_var = 10000;
    this->Y_var = 10000;
    this->Z_var = 10000;
    this->X1_var = 10000;
    this->X2_var = 10000;
    puMatrixPositionCh_arraysize = 0;
    this->puMatrixPositionCh_var = 0;
    ewt_arraysize = 0;
    this->ewt_var = 0;
    pioff_arraysize = 0;
    this->pioff_var = 0;
}

msgNeighborDisc::msgNeighborDisc(const msgNeighborDisc& other) : cPacket(other)
{
    puMatrixPositionCh_arraysize = 0;
    this->puMatrixPositionCh_var = 0;
    ewt_arraysize = 0;
    this->ewt_var = 0;
    pioff_arraysize = 0;
    this->pioff_var = 0;
    copy(other);
}

msgNeighborDisc::~msgNeighborDisc()
{
    delete [] puMatrixPositionCh_var;
    delete [] ewt_var;
    delete [] pioff_var;
}

msgNeighborDisc& msgNeighborDisc::operator=(const msgNeighborDisc& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void msgNeighborDisc::copy(const msgNeighborDisc& other)
{
    this->srcIP_var = other.srcIP_var;
    this->W_var = other.W_var;
    this->X_var = other.X_var;
    this->Y_var = other.Y_var;
    this->Z_var = other.Z_var;
    this->X1_var = other.X1_var;
    this->X2_var = other.X2_var;
    delete [] this->puMatrixPositionCh_var;
    this->puMatrixPositionCh_var = (other.puMatrixPositionCh_arraysize==0) ? NULL : new PUMatrixPositionCH[other.puMatrixPositionCh_arraysize];
    puMatrixPositionCh_arraysize = other.puMatrixPositionCh_arraysize;
    for (unsigned int i=0; i<puMatrixPositionCh_arraysize; i++)
        this->puMatrixPositionCh_var[i] = other.puMatrixPositionCh_var[i];
    delete [] this->ewt_var;
    this->ewt_var = (other.ewt_arraysize==0) ? NULL : new double[other.ewt_arraysize];
    ewt_arraysize = other.ewt_arraysize;
    for (unsigned int i=0; i<ewt_arraysize; i++)
        this->ewt_var[i] = other.ewt_var[i];
    delete [] this->pioff_var;
    this->pioff_var = (other.pioff_arraysize==0) ? NULL : new double[other.pioff_arraysize];
    pioff_arraysize = other.pioff_arraysize;
    for (unsigned int i=0; i<pioff_arraysize; i++)
        this->pioff_var[i] = other.pioff_var[i];
}

void msgNeighborDisc::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->srcIP_var);
    doPacking(b,this->W_var);
    doPacking(b,this->X_var);
    doPacking(b,this->Y_var);
    doPacking(b,this->Z_var);
    doPacking(b,this->X1_var);
    doPacking(b,this->X2_var);
    b->pack(puMatrixPositionCh_arraysize);
    doPacking(b,this->puMatrixPositionCh_var,puMatrixPositionCh_arraysize);
    b->pack(ewt_arraysize);
    doPacking(b,this->ewt_var,ewt_arraysize);
    b->pack(pioff_arraysize);
    doPacking(b,this->pioff_var,pioff_arraysize);
}

void msgNeighborDisc::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcIP_var);
    doUnpacking(b,this->W_var);
    doUnpacking(b,this->X_var);
    doUnpacking(b,this->Y_var);
    doUnpacking(b,this->Z_var);
    doUnpacking(b,this->X1_var);
    doUnpacking(b,this->X2_var);
    delete [] this->puMatrixPositionCh_var;
    b->unpack(puMatrixPositionCh_arraysize);
    if (puMatrixPositionCh_arraysize==0) {
        this->puMatrixPositionCh_var = 0;
    } else {
        this->puMatrixPositionCh_var = new PUMatrixPositionCH[puMatrixPositionCh_arraysize];
        doUnpacking(b,this->puMatrixPositionCh_var,puMatrixPositionCh_arraysize);
    }
    delete [] this->ewt_var;
    b->unpack(ewt_arraysize);
    if (ewt_arraysize==0) {
        this->ewt_var = 0;
    } else {
        this->ewt_var = new double[ewt_arraysize];
        doUnpacking(b,this->ewt_var,ewt_arraysize);
    }
    delete [] this->pioff_var;
    b->unpack(pioff_arraysize);
    if (pioff_arraysize==0) {
        this->pioff_var = 0;
    } else {
        this->pioff_var = new double[pioff_arraysize];
        doUnpacking(b,this->pioff_var,pioff_arraysize);
    }
}

IPv4Address& msgNeighborDisc::getSrcIP()
{
    return srcIP_var;
}

void msgNeighborDisc::setSrcIP(const IPv4Address& srcIP)
{
    this->srcIP_var = srcIP;
}

double msgNeighborDisc::getW() const
{
    return W_var;
}

void msgNeighborDisc::setW(double W)
{
    this->W_var = W;
}

double msgNeighborDisc::getX() const
{
    return X_var;
}

void msgNeighborDisc::setX(double X)
{
    this->X_var = X;
}

double msgNeighborDisc::getY() const
{
    return Y_var;
}

void msgNeighborDisc::setY(double Y)
{
    this->Y_var = Y;
}

double msgNeighborDisc::getZ() const
{
    return Z_var;
}

void msgNeighborDisc::setZ(double Z)
{
    this->Z_var = Z;
}

double msgNeighborDisc::getX1() const
{
    return X1_var;
}

void msgNeighborDisc::setX1(double X1)
{
    this->X1_var = X1;
}

double msgNeighborDisc::getX2() const
{
    return X2_var;
}

void msgNeighborDisc::setX2(double X2)
{
    this->X2_var = X2;
}

void msgNeighborDisc::setPuMatrixPositionChArraySize(unsigned int size)
{
    PUMatrixPositionCH *puMatrixPositionCh_var2 = (size==0) ? NULL : new PUMatrixPositionCH[size];
    unsigned int sz = puMatrixPositionCh_arraysize < size ? puMatrixPositionCh_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        puMatrixPositionCh_var2[i] = this->puMatrixPositionCh_var[i];
    puMatrixPositionCh_arraysize = size;
    delete [] this->puMatrixPositionCh_var;
    this->puMatrixPositionCh_var = puMatrixPositionCh_var2;
}

unsigned int msgNeighborDisc::getPuMatrixPositionChArraySize() const
{
    return puMatrixPositionCh_arraysize;
}

PUMatrixPositionCH& msgNeighborDisc::getPuMatrixPositionCh(unsigned int k)
{
    if (k>=puMatrixPositionCh_arraysize) throw cRuntimeError("Array of size %d indexed by %d", puMatrixPositionCh_arraysize, k);
    return puMatrixPositionCh_var[k];
}

void msgNeighborDisc::setPuMatrixPositionCh(unsigned int k, const PUMatrixPositionCH& puMatrixPositionCh)
{
    if (k>=puMatrixPositionCh_arraysize) throw cRuntimeError("Array of size %d indexed by %d", puMatrixPositionCh_arraysize, k);
    this->puMatrixPositionCh_var[k] = puMatrixPositionCh;
}

void msgNeighborDisc::setEwtArraySize(unsigned int size)
{
    double *ewt_var2 = (size==0) ? NULL : new double[size];
    unsigned int sz = ewt_arraysize < size ? ewt_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        ewt_var2[i] = this->ewt_var[i];
    for (unsigned int i=sz; i<size; i++)
        ewt_var2[i] = 0;
    ewt_arraysize = size;
    delete [] this->ewt_var;
    this->ewt_var = ewt_var2;
}

unsigned int msgNeighborDisc::getEwtArraySize() const
{
    return ewt_arraysize;
}

double msgNeighborDisc::getEwt(unsigned int k) const
{
    if (k>=ewt_arraysize) throw cRuntimeError("Array of size %d indexed by %d", ewt_arraysize, k);
    return ewt_var[k];
}

void msgNeighborDisc::setEwt(unsigned int k, double ewt)
{
    if (k>=ewt_arraysize) throw cRuntimeError("Array of size %d indexed by %d", ewt_arraysize, k);
    this->ewt_var[k] = ewt;
}

void msgNeighborDisc::setPioffArraySize(unsigned int size)
{
    double *pioff_var2 = (size==0) ? NULL : new double[size];
    unsigned int sz = pioff_arraysize < size ? pioff_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        pioff_var2[i] = this->pioff_var[i];
    for (unsigned int i=sz; i<size; i++)
        pioff_var2[i] = 0;
    pioff_arraysize = size;
    delete [] this->pioff_var;
    this->pioff_var = pioff_var2;
}

unsigned int msgNeighborDisc::getPioffArraySize() const
{
    return pioff_arraysize;
}

double msgNeighborDisc::getPioff(unsigned int k) const
{
    if (k>=pioff_arraysize) throw cRuntimeError("Array of size %d indexed by %d", pioff_arraysize, k);
    return pioff_var[k];
}

void msgNeighborDisc::setPioff(unsigned int k, double pioff)
{
    if (k>=pioff_arraysize) throw cRuntimeError("Array of size %d indexed by %d", pioff_arraysize, k);
    this->pioff_var[k] = pioff;
}

class msgNeighborDiscDescriptor : public cClassDescriptor
{
  public:
    msgNeighborDiscDescriptor();
    virtual ~msgNeighborDiscDescriptor();

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

Register_ClassDescriptor(msgNeighborDiscDescriptor);

msgNeighborDiscDescriptor::msgNeighborDiscDescriptor() : cClassDescriptor("msgNeighborDisc", "cPacket")
{
}

msgNeighborDiscDescriptor::~msgNeighborDiscDescriptor()
{
}

bool msgNeighborDiscDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<msgNeighborDisc *>(obj)!=NULL;
}

const char *msgNeighborDiscDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int msgNeighborDiscDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount(object) : 10;
}

unsigned int msgNeighborDiscDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *msgNeighborDiscDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcIP",
        "W",
        "X",
        "Y",
        "Z",
        "X1",
        "X2",
        "puMatrixPositionCh",
        "ewt",
        "pioff",
    };
    return (field>=0 && field<10) ? fieldNames[field] : NULL;
}

int msgNeighborDiscDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIP")==0) return base+0;
    if (fieldName[0]=='W' && strcmp(fieldName, "W")==0) return base+1;
    if (fieldName[0]=='X' && strcmp(fieldName, "X")==0) return base+2;
    if (fieldName[0]=='Y' && strcmp(fieldName, "Y")==0) return base+3;
    if (fieldName[0]=='Z' && strcmp(fieldName, "Z")==0) return base+4;
    if (fieldName[0]=='X' && strcmp(fieldName, "X1")==0) return base+5;
    if (fieldName[0]=='X' && strcmp(fieldName, "X2")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "puMatrixPositionCh")==0) return base+7;
    if (fieldName[0]=='e' && strcmp(fieldName, "ewt")==0) return base+8;
    if (fieldName[0]=='p' && strcmp(fieldName, "pioff")==0) return base+9;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *msgNeighborDiscDescriptor::getFieldTypeString(void *object, int field) const
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
        "double",
        "double",
        "double",
        "double",
        "PUMatrixPositionCH",
        "double",
        "double",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : NULL;
}

const char *msgNeighborDiscDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int msgNeighborDiscDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    msgNeighborDisc *pp = (msgNeighborDisc *)object; (void)pp;
    switch (field) {
        case 7: return pp->getPuMatrixPositionChArraySize();
        case 8: return pp->getEwtArraySize();
        case 9: return pp->getPioffArraySize();
        default: return 0;
    }
}

std::string msgNeighborDiscDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    msgNeighborDisc *pp = (msgNeighborDisc *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcIP(); return out.str();}
        case 1: return double2string(pp->getW());
        case 2: return double2string(pp->getX());
        case 3: return double2string(pp->getY());
        case 4: return double2string(pp->getZ());
        case 5: return double2string(pp->getX1());
        case 6: return double2string(pp->getX2());
        case 7: {std::stringstream out; out << pp->getPuMatrixPositionCh(i); return out.str();}
        case 8: return double2string(pp->getEwt(i));
        case 9: return double2string(pp->getPioff(i));
        default: return "";
    }
}

bool msgNeighborDiscDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    msgNeighborDisc *pp = (msgNeighborDisc *)object; (void)pp;
    switch (field) {
        case 1: pp->setW(string2double(value)); return true;
        case 2: pp->setX(string2double(value)); return true;
        case 3: pp->setY(string2double(value)); return true;
        case 4: pp->setZ(string2double(value)); return true;
        case 5: pp->setX1(string2double(value)); return true;
        case 6: pp->setX2(string2double(value)); return true;
        case 8: pp->setEwt(i,string2double(value)); return true;
        case 9: pp->setPioff(i,string2double(value)); return true;
        default: return false;
    }
}

const char *msgNeighborDiscDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        "PUMatrixPositionCH",
        NULL,
        NULL,
    };
    return (field>=0 && field<10) ? fieldStructNames[field] : NULL;
}

void *msgNeighborDiscDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    msgNeighborDisc *pp = (msgNeighborDisc *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcIP()); break;
        case 7: return (void *)(&pp->getPuMatrixPositionCh(i)); break;
        default: return NULL;
    }
}


