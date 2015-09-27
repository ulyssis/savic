//
// Generated file, do not edit! Created by opp_msgc 4.3 from linklayer/radio/AirFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "AirFrame_m.h"

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




Register_Class(AirFrame);

AirFrame::AirFrame(const char *name, int kind) : cPacket(name,kind)
{
    this->pSend_var = 0;
    this->channelNumber_var = 0;
    this->duration_var = 0;
    this->bitrate_var = 0;
    this->snr_var = 0;
    this->lossRate_var = 0;
    this->powRec_var = 0;
    this->carrierFrequency_var = 0;
    this->bandwidth_var = 0;
    this->inbuffer_var = 0;
    this->phyTime_var = 0;
    this->accPhyTime_var = 0;
}

AirFrame::AirFrame(const AirFrame& other) : cPacket(other)
{
    copy(other);
}

AirFrame::~AirFrame()
{
}

AirFrame& AirFrame::operator=(const AirFrame& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void AirFrame::copy(const AirFrame& other)
{
    this->pSend_var = other.pSend_var;
    this->channelNumber_var = other.channelNumber_var;
    this->duration_var = other.duration_var;
    this->bitrate_var = other.bitrate_var;
    this->snr_var = other.snr_var;
    this->lossRate_var = other.lossRate_var;
    this->powRec_var = other.powRec_var;
    this->senderPos_var = other.senderPos_var;
    this->carrierFrequency_var = other.carrierFrequency_var;
    this->bandwidth_var = other.bandwidth_var;
    this->modulationType_var = other.modulationType_var;
    this->inbuffer_var = other.inbuffer_var;
    this->phyTime_var = other.phyTime_var;
    this->accPhyTime_var = other.accPhyTime_var;
}

void AirFrame::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->pSend_var);
    doPacking(b,this->channelNumber_var);
    doPacking(b,this->duration_var);
    doPacking(b,this->bitrate_var);
    doPacking(b,this->snr_var);
    doPacking(b,this->lossRate_var);
    doPacking(b,this->powRec_var);
    doPacking(b,this->senderPos_var);
    doPacking(b,this->carrierFrequency_var);
    doPacking(b,this->bandwidth_var);
    doPacking(b,this->modulationType_var);
    doPacking(b,this->inbuffer_var);
    doPacking(b,this->phyTime_var);
    doPacking(b,this->accPhyTime_var);
}

void AirFrame::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->pSend_var);
    doUnpacking(b,this->channelNumber_var);
    doUnpacking(b,this->duration_var);
    doUnpacking(b,this->bitrate_var);
    doUnpacking(b,this->snr_var);
    doUnpacking(b,this->lossRate_var);
    doUnpacking(b,this->powRec_var);
    doUnpacking(b,this->senderPos_var);
    doUnpacking(b,this->carrierFrequency_var);
    doUnpacking(b,this->bandwidth_var);
    doUnpacking(b,this->modulationType_var);
    doUnpacking(b,this->inbuffer_var);
    doUnpacking(b,this->phyTime_var);
    doUnpacking(b,this->accPhyTime_var);
}

double AirFrame::getPSend() const
{
    return pSend_var;
}

void AirFrame::setPSend(double pSend)
{
    this->pSend_var = pSend;
}

int AirFrame::getChannelNumber() const
{
    return channelNumber_var;
}

void AirFrame::setChannelNumber(int channelNumber)
{
    this->channelNumber_var = channelNumber;
}

simtime_t AirFrame::getDuration() const
{
    return duration_var;
}

void AirFrame::setDuration(simtime_t duration)
{
    this->duration_var = duration;
}

double AirFrame::getBitrate() const
{
    return bitrate_var;
}

void AirFrame::setBitrate(double bitrate)
{
    this->bitrate_var = bitrate;
}

double AirFrame::getSnr() const
{
    return snr_var;
}

void AirFrame::setSnr(double snr)
{
    this->snr_var = snr;
}

double AirFrame::getLossRate() const
{
    return lossRate_var;
}

void AirFrame::setLossRate(double lossRate)
{
    this->lossRate_var = lossRate;
}

double AirFrame::getPowRec() const
{
    return powRec_var;
}

void AirFrame::setPowRec(double powRec)
{
    this->powRec_var = powRec;
}

Coord& AirFrame::getSenderPos()
{
    return senderPos_var;
}

void AirFrame::setSenderPos(const Coord& senderPos)
{
    this->senderPos_var = senderPos;
}

double AirFrame::getCarrierFrequency() const
{
    return carrierFrequency_var;
}

void AirFrame::setCarrierFrequency(double carrierFrequency)
{
    this->carrierFrequency_var = carrierFrequency;
}

double AirFrame::getBandwidth() const
{
    return bandwidth_var;
}

void AirFrame::setBandwidth(double bandwidth)
{
    this->bandwidth_var = bandwidth;
}

ModulationType& AirFrame::getModulationType()
{
    return modulationType_var;
}

void AirFrame::setModulationType(const ModulationType& modulationType)
{
    this->modulationType_var = modulationType;
}

bool AirFrame::getInbuffer() const
{
    return inbuffer_var;
}

void AirFrame::setInbuffer(bool inbuffer)
{
    this->inbuffer_var = inbuffer;
}

simtime_t AirFrame::getPhyTime() const
{
    return phyTime_var;
}

void AirFrame::setPhyTime(simtime_t phyTime)
{
    this->phyTime_var = phyTime;
}

simtime_t AirFrame::getAccPhyTime() const
{
    return accPhyTime_var;
}

void AirFrame::setAccPhyTime(simtime_t accPhyTime)
{
    this->accPhyTime_var = accPhyTime;
}

class AirFrameDescriptor : public cClassDescriptor
{
  public:
    AirFrameDescriptor();
    virtual ~AirFrameDescriptor();

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

Register_ClassDescriptor(AirFrameDescriptor);

AirFrameDescriptor::AirFrameDescriptor() : cClassDescriptor("AirFrame", "cPacket")
{
}

AirFrameDescriptor::~AirFrameDescriptor()
{
}

bool AirFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AirFrame *>(obj)!=NULL;
}

const char *AirFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AirFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount(object) : 14;
}

unsigned int AirFrameDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<14) ? fieldTypeFlags[field] : 0;
}

const char *AirFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pSend",
        "channelNumber",
        "duration",
        "bitrate",
        "snr",
        "lossRate",
        "powRec",
        "senderPos",
        "carrierFrequency",
        "bandwidth",
        "modulationType",
        "inbuffer",
        "phyTime",
        "accPhyTime",
    };
    return (field>=0 && field<14) ? fieldNames[field] : NULL;
}

int AirFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pSend")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelNumber")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitrate")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "snr")==0) return base+4;
    if (fieldName[0]=='l' && strcmp(fieldName, "lossRate")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "powRec")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderPos")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "carrierFrequency")==0) return base+8;
    if (fieldName[0]=='b' && strcmp(fieldName, "bandwidth")==0) return base+9;
    if (fieldName[0]=='m' && strcmp(fieldName, "modulationType")==0) return base+10;
    if (fieldName[0]=='i' && strcmp(fieldName, "inbuffer")==0) return base+11;
    if (fieldName[0]=='p' && strcmp(fieldName, "phyTime")==0) return base+12;
    if (fieldName[0]=='a' && strcmp(fieldName, "accPhyTime")==0) return base+13;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AirFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "int",
        "simtime_t",
        "double",
        "double",
        "double",
        "double",
        "Coord",
        "double",
        "double",
        "ModulationType",
        "bool",
        "simtime_t",
        "simtime_t",
    };
    return (field>=0 && field<14) ? fieldTypeStrings[field] : NULL;
}

const char *AirFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AirFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AirFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getPSend());
        case 1: return long2string(pp->getChannelNumber());
        case 2: return double2string(pp->getDuration());
        case 3: return double2string(pp->getBitrate());
        case 4: return double2string(pp->getSnr());
        case 5: return double2string(pp->getLossRate());
        case 6: return double2string(pp->getPowRec());
        case 7: {std::stringstream out; out << pp->getSenderPos(); return out.str();}
        case 8: return double2string(pp->getCarrierFrequency());
        case 9: return double2string(pp->getBandwidth());
        case 10: {std::stringstream out; out << pp->getModulationType(); return out.str();}
        case 11: return bool2string(pp->getInbuffer());
        case 12: return double2string(pp->getPhyTime());
        case 13: return double2string(pp->getAccPhyTime());
        default: return "";
    }
}

bool AirFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setPSend(string2double(value)); return true;
        case 1: pp->setChannelNumber(string2long(value)); return true;
        case 2: pp->setDuration(string2double(value)); return true;
        case 3: pp->setBitrate(string2double(value)); return true;
        case 4: pp->setSnr(string2double(value)); return true;
        case 5: pp->setLossRate(string2double(value)); return true;
        case 6: pp->setPowRec(string2double(value)); return true;
        case 8: pp->setCarrierFrequency(string2double(value)); return true;
        case 9: pp->setBandwidth(string2double(value)); return true;
        case 11: pp->setInbuffer(string2bool(value)); return true;
        case 12: pp->setPhyTime(string2double(value)); return true;
        case 13: pp->setAccPhyTime(string2double(value)); return true;
        default: return false;
    }
}

const char *AirFrameDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        NULL,
        NULL,
        "Coord",
        NULL,
        NULL,
        "ModulationType",
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<14) ? fieldStructNames[field] : NULL;
}

void *AirFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AirFrame *pp = (AirFrame *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getSenderPos()); break;
        case 10: return (void *)(&pp->getModulationType()); break;
        default: return NULL;
    }
}


