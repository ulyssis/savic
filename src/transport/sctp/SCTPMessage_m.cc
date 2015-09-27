//
// Generated file, do not edit! Created by opp_msgc 4.3 from transport/sctp/SCTPMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "SCTPMessage_m.h"

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




Register_Class(SCTPSimpleMessage);

SCTPSimpleMessage::SCTPSimpleMessage(const char *name, int kind) : cPacket(name,kind)
{
    this->dataLen_var = 0;
    data_arraysize = 0;
    this->data_var = 0;
    this->creationTime_var = 0;
    this->encaps_var = false;
}

SCTPSimpleMessage::SCTPSimpleMessage(const SCTPSimpleMessage& other) : cPacket(other)
{
    data_arraysize = 0;
    this->data_var = 0;
    copy(other);
}

SCTPSimpleMessage::~SCTPSimpleMessage()
{
    delete [] data_var;
}

SCTPSimpleMessage& SCTPSimpleMessage::operator=(const SCTPSimpleMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPSimpleMessage::copy(const SCTPSimpleMessage& other)
{
    this->dataLen_var = other.dataLen_var;
    delete [] this->data_var;
    this->data_var = (other.data_arraysize==0) ? NULL : new char[other.data_arraysize];
    data_arraysize = other.data_arraysize;
    for (unsigned int i=0; i<data_arraysize; i++)
        this->data_var[i] = other.data_var[i];
    this->creationTime_var = other.creationTime_var;
    this->encaps_var = other.encaps_var;
}

void SCTPSimpleMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->dataLen_var);
    b->pack(data_arraysize);
    doPacking(b,this->data_var,data_arraysize);
    doPacking(b,this->creationTime_var);
    doPacking(b,this->encaps_var);
}

void SCTPSimpleMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->dataLen_var);
    delete [] this->data_var;
    b->unpack(data_arraysize);
    if (data_arraysize==0) {
        this->data_var = 0;
    } else {
        this->data_var = new char[data_arraysize];
        doUnpacking(b,this->data_var,data_arraysize);
    }
    doUnpacking(b,this->creationTime_var);
    doUnpacking(b,this->encaps_var);
}

uint32 SCTPSimpleMessage::getDataLen() const
{
    return dataLen_var;
}

void SCTPSimpleMessage::setDataLen(uint32 dataLen)
{
    this->dataLen_var = dataLen;
}

void SCTPSimpleMessage::setDataArraySize(unsigned int size)
{
    char *data_var2 = (size==0) ? NULL : new char[size];
    unsigned int sz = data_arraysize < size ? data_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        data_var2[i] = this->data_var[i];
    for (unsigned int i=sz; i<size; i++)
        data_var2[i] = 0;
    data_arraysize = size;
    delete [] this->data_var;
    this->data_var = data_var2;
}

unsigned int SCTPSimpleMessage::getDataArraySize() const
{
    return data_arraysize;
}

char SCTPSimpleMessage::getData(unsigned int k) const
{
    if (k>=data_arraysize) throw cRuntimeError("Array of size %d indexed by %d", data_arraysize, k);
    return data_var[k];
}

void SCTPSimpleMessage::setData(unsigned int k, char data)
{
    if (k>=data_arraysize) throw cRuntimeError("Array of size %d indexed by %d", data_arraysize, k);
    this->data_var[k] = data;
}

simtime_t SCTPSimpleMessage::getCreationTime() const
{
    return creationTime_var;
}

void SCTPSimpleMessage::setCreationTime(simtime_t creationTime)
{
    this->creationTime_var = creationTime;
}

bool SCTPSimpleMessage::getEncaps() const
{
    return encaps_var;
}

void SCTPSimpleMessage::setEncaps(bool encaps)
{
    this->encaps_var = encaps;
}

class SCTPSimpleMessageDescriptor : public cClassDescriptor
{
  public:
    SCTPSimpleMessageDescriptor();
    virtual ~SCTPSimpleMessageDescriptor();

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

Register_ClassDescriptor(SCTPSimpleMessageDescriptor);

SCTPSimpleMessageDescriptor::SCTPSimpleMessageDescriptor() : cClassDescriptor("SCTPSimpleMessage", "cPacket")
{
}

SCTPSimpleMessageDescriptor::~SCTPSimpleMessageDescriptor()
{
}

bool SCTPSimpleMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPSimpleMessage *>(obj)!=NULL;
}

const char *SCTPSimpleMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPSimpleMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int SCTPSimpleMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *SCTPSimpleMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "dataLen",
        "data",
        "creationTime",
        "encaps",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int SCTPSimpleMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataLen")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "encaps")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPSimpleMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "char",
        "simtime_t",
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPSimpleMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPSimpleMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        case 1: return pp->getDataArraySize();
        default: return 0;
    }
}

std::string SCTPSimpleMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getDataLen());
        case 1: return long2string(pp->getData(i));
        case 2: return double2string(pp->getCreationTime());
        case 3: return bool2string(pp->getEncaps());
        default: return "";
    }
}

bool SCTPSimpleMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setDataLen(string2ulong(value)); return true;
        case 1: pp->setData(i,string2long(value)); return true;
        case 2: pp->setCreationTime(string2double(value)); return true;
        case 3: pp->setEncaps(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPSimpleMessageDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *SCTPSimpleMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

SCTPMessage_Base::SCTPMessage_Base(const char *name, int kind) : cPacket(name,kind)
{
    this->srcPort_var = 0;
    this->destPort_var = 0;
    this->tag_var = 0;
    this->checksumOk_var = 0;
}

SCTPMessage_Base::SCTPMessage_Base(const SCTPMessage_Base& other) : cPacket(other)
{
    copy(other);
}

SCTPMessage_Base::~SCTPMessage_Base()
{
}

SCTPMessage_Base& SCTPMessage_Base::operator=(const SCTPMessage_Base& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPMessage_Base::copy(const SCTPMessage_Base& other)
{
    this->srcPort_var = other.srcPort_var;
    this->destPort_var = other.destPort_var;
    this->tag_var = other.tag_var;
    this->checksumOk_var = other.checksumOk_var;
}

void SCTPMessage_Base::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->srcPort_var);
    doPacking(b,this->destPort_var);
    doPacking(b,this->tag_var);
    doPacking(b,this->checksumOk_var);
    // field chunks is abstract -- please do packing in customized class
}

void SCTPMessage_Base::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcPort_var);
    doUnpacking(b,this->destPort_var);
    doUnpacking(b,this->tag_var);
    doUnpacking(b,this->checksumOk_var);
    // field chunks is abstract -- please do unpacking in customized class
}

uint16 SCTPMessage_Base::getSrcPort() const
{
    return srcPort_var;
}

void SCTPMessage_Base::setSrcPort(uint16 srcPort)
{
    this->srcPort_var = srcPort;
}

uint16 SCTPMessage_Base::getDestPort() const
{
    return destPort_var;
}

void SCTPMessage_Base::setDestPort(uint16 destPort)
{
    this->destPort_var = destPort;
}

uint32 SCTPMessage_Base::getTag() const
{
    return tag_var;
}

void SCTPMessage_Base::setTag(uint32 tag)
{
    this->tag_var = tag;
}

bool SCTPMessage_Base::getChecksumOk() const
{
    return checksumOk_var;
}

void SCTPMessage_Base::setChecksumOk(bool checksumOk)
{
    this->checksumOk_var = checksumOk;
}

class SCTPMessageDescriptor : public cClassDescriptor
{
  public:
    SCTPMessageDescriptor();
    virtual ~SCTPMessageDescriptor();

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

Register_ClassDescriptor(SCTPMessageDescriptor);

SCTPMessageDescriptor::SCTPMessageDescriptor() : cClassDescriptor("SCTPMessage", "cPacket")
{
}

SCTPMessageDescriptor::~SCTPMessageDescriptor()
{
}

bool SCTPMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPMessage_Base *>(obj)!=NULL;
}

const char *SCTPMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int SCTPMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *SCTPMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcPort",
        "destPort",
        "tag",
        "checksumOk",
        "chunks",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int SCTPMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPort")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tag")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksumOk")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunks")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
        "uint16",
        "uint32",
        "bool",
        "cPacketPtr",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        case 4: return pp->getChunksArraySize();
        default: return 0;
    }
}

std::string SCTPMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSrcPort());
        case 1: return ulong2string(pp->getDestPort());
        case 2: return ulong2string(pp->getTag());
        case 3: return bool2string(pp->getChecksumOk());
        case 4: {std::stringstream out; out << pp->getChunks(i); return out.str();}
        default: return "";
    }
}

bool SCTPMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcPort(string2ulong(value)); return true;
        case 1: pp->setDestPort(string2ulong(value)); return true;
        case 2: pp->setTag(string2ulong(value)); return true;
        case 3: pp->setChecksumOk(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPMessageDescriptor::getFieldStructName(void *object, int field) const
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
        "cPacketPtr",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *SCTPMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getChunks(i)); break;
        default: return NULL;
    }
}

Register_Class(SCTPChunk);

SCTPChunk::SCTPChunk(const char *name, int kind) : cPacket(name,kind)
{
    this->chunkType_var = 0;
}

SCTPChunk::SCTPChunk(const SCTPChunk& other) : cPacket(other)
{
    copy(other);
}

SCTPChunk::~SCTPChunk()
{
}

SCTPChunk& SCTPChunk::operator=(const SCTPChunk& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPChunk::copy(const SCTPChunk& other)
{
    this->chunkType_var = other.chunkType_var;
}

void SCTPChunk::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->chunkType_var);
}

void SCTPChunk::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->chunkType_var);
}

uint8 SCTPChunk::getChunkType() const
{
    return chunkType_var;
}

void SCTPChunk::setChunkType(uint8 chunkType)
{
    this->chunkType_var = chunkType;
}

class SCTPChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPChunkDescriptor();
    virtual ~SCTPChunkDescriptor();

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

Register_ClassDescriptor(SCTPChunkDescriptor);

SCTPChunkDescriptor::SCTPChunkDescriptor() : cClassDescriptor("SCTPChunk", "cPacket")
{
}

SCTPChunkDescriptor::~SCTPChunkDescriptor()
{
}

bool SCTPChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPChunk *>(obj)!=NULL;
}

const char *SCTPChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "false";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int SCTPChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *SCTPChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "chunkType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int SCTPChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunkType")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getChunkType());
        default: return "";
    }
}

bool SCTPChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setChunkType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPChunkDescriptor::getFieldStructName(void *object, int field) const
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

void *SCTPChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPInitChunk);

SCTPInitChunk::SCTPInitChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->initTag_var = 0;
    this->a_rwnd_var = 0;
    this->noOutStreams_var = 0;
    this->noInStreams_var = 0;
    this->initTSN_var = 0;
    this->forwardTsn_var = 0;
    addresses_arraysize = 0;
    this->addresses_var = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters_var = 0;
}

SCTPInitChunk::SCTPInitChunk(const SCTPInitChunk& other) : SCTPChunk(other)
{
    addresses_arraysize = 0;
    this->addresses_var = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters_var = 0;
    copy(other);
}

SCTPInitChunk::~SCTPInitChunk()
{
    delete [] addresses_var;
    delete [] unrecognizedParameters_var;
}

SCTPInitChunk& SCTPInitChunk::operator=(const SCTPInitChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPInitChunk::copy(const SCTPInitChunk& other)
{
    this->initTag_var = other.initTag_var;
    this->a_rwnd_var = other.a_rwnd_var;
    this->noOutStreams_var = other.noOutStreams_var;
    this->noInStreams_var = other.noInStreams_var;
    this->initTSN_var = other.initTSN_var;
    this->forwardTsn_var = other.forwardTsn_var;
    delete [] this->addresses_var;
    this->addresses_var = (other.addresses_arraysize==0) ? NULL : new IPvXAddress[other.addresses_arraysize];
    addresses_arraysize = other.addresses_arraysize;
    for (unsigned int i=0; i<addresses_arraysize; i++)
        this->addresses_var[i] = other.addresses_var[i];
    delete [] this->unrecognizedParameters_var;
    this->unrecognizedParameters_var = (other.unrecognizedParameters_arraysize==0) ? NULL : new uint8[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (unsigned int i=0; i<unrecognizedParameters_arraysize; i++)
        this->unrecognizedParameters_var[i] = other.unrecognizedParameters_var[i];
}

void SCTPInitChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->initTag_var);
    doPacking(b,this->a_rwnd_var);
    doPacking(b,this->noOutStreams_var);
    doPacking(b,this->noInStreams_var);
    doPacking(b,this->initTSN_var);
    doPacking(b,this->forwardTsn_var);
    b->pack(addresses_arraysize);
    doPacking(b,this->addresses_var,addresses_arraysize);
    b->pack(unrecognizedParameters_arraysize);
    doPacking(b,this->unrecognizedParameters_var,unrecognizedParameters_arraysize);
}

void SCTPInitChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->initTag_var);
    doUnpacking(b,this->a_rwnd_var);
    doUnpacking(b,this->noOutStreams_var);
    doUnpacking(b,this->noInStreams_var);
    doUnpacking(b,this->initTSN_var);
    doUnpacking(b,this->forwardTsn_var);
    delete [] this->addresses_var;
    b->unpack(addresses_arraysize);
    if (addresses_arraysize==0) {
        this->addresses_var = 0;
    } else {
        this->addresses_var = new IPvXAddress[addresses_arraysize];
        doUnpacking(b,this->addresses_var,addresses_arraysize);
    }
    delete [] this->unrecognizedParameters_var;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize==0) {
        this->unrecognizedParameters_var = 0;
    } else {
        this->unrecognizedParameters_var = new uint8[unrecognizedParameters_arraysize];
        doUnpacking(b,this->unrecognizedParameters_var,unrecognizedParameters_arraysize);
    }
}

uint32 SCTPInitChunk::getInitTag() const
{
    return initTag_var;
}

void SCTPInitChunk::setInitTag(uint32 initTag)
{
    this->initTag_var = initTag;
}

uint32 SCTPInitChunk::getA_rwnd() const
{
    return a_rwnd_var;
}

void SCTPInitChunk::setA_rwnd(uint32 a_rwnd)
{
    this->a_rwnd_var = a_rwnd;
}

uint16 SCTPInitChunk::getNoOutStreams() const
{
    return noOutStreams_var;
}

void SCTPInitChunk::setNoOutStreams(uint16 noOutStreams)
{
    this->noOutStreams_var = noOutStreams;
}

uint16 SCTPInitChunk::getNoInStreams() const
{
    return noInStreams_var;
}

void SCTPInitChunk::setNoInStreams(uint16 noInStreams)
{
    this->noInStreams_var = noInStreams;
}

uint32 SCTPInitChunk::getInitTSN() const
{
    return initTSN_var;
}

void SCTPInitChunk::setInitTSN(uint32 initTSN)
{
    this->initTSN_var = initTSN;
}

bool SCTPInitChunk::getForwardTsn() const
{
    return forwardTsn_var;
}

void SCTPInitChunk::setForwardTsn(bool forwardTsn)
{
    this->forwardTsn_var = forwardTsn;
}

void SCTPInitChunk::setAddressesArraySize(unsigned int size)
{
    IPvXAddress *addresses_var2 = (size==0) ? NULL : new IPvXAddress[size];
    unsigned int sz = addresses_arraysize < size ? addresses_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        addresses_var2[i] = this->addresses_var[i];
    addresses_arraysize = size;
    delete [] this->addresses_var;
    this->addresses_var = addresses_var2;
}

unsigned int SCTPInitChunk::getAddressesArraySize() const
{
    return addresses_arraysize;
}

IPvXAddress& SCTPInitChunk::getAddresses(unsigned int k)
{
    if (k>=addresses_arraysize) throw cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    return addresses_var[k];
}

void SCTPInitChunk::setAddresses(unsigned int k, const IPvXAddress& addresses)
{
    if (k>=addresses_arraysize) throw cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    this->addresses_var[k] = addresses;
}

void SCTPInitChunk::setUnrecognizedParametersArraySize(unsigned int size)
{
    uint8 *unrecognizedParameters_var2 = (size==0) ? NULL : new uint8[size];
    unsigned int sz = unrecognizedParameters_arraysize < size ? unrecognizedParameters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unrecognizedParameters_var2[i] = this->unrecognizedParameters_var[i];
    for (unsigned int i=sz; i<size; i++)
        unrecognizedParameters_var2[i] = 0;
    unrecognizedParameters_arraysize = size;
    delete [] this->unrecognizedParameters_var;
    this->unrecognizedParameters_var = unrecognizedParameters_var2;
}

unsigned int SCTPInitChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8 SCTPInitChunk::getUnrecognizedParameters(unsigned int k) const
{
    if (k>=unrecognizedParameters_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    return unrecognizedParameters_var[k];
}

void SCTPInitChunk::setUnrecognizedParameters(unsigned int k, uint8 unrecognizedParameters)
{
    if (k>=unrecognizedParameters_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    this->unrecognizedParameters_var[k] = unrecognizedParameters;
}

class SCTPInitChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPInitChunkDescriptor();
    virtual ~SCTPInitChunkDescriptor();

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

Register_ClassDescriptor(SCTPInitChunkDescriptor);

SCTPInitChunkDescriptor::SCTPInitChunkDescriptor() : cClassDescriptor("SCTPInitChunk", "SCTPChunk")
{
}

SCTPInitChunkDescriptor::~SCTPInitChunkDescriptor()
{
}

bool SCTPInitChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPInitChunk *>(obj)!=NULL;
}

const char *SCTPInitChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPInitChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int SCTPInitChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *SCTPInitChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "initTag",
        "a_rwnd",
        "noOutStreams",
        "noInStreams",
        "initTSN",
        "forwardTsn",
        "addresses",
        "unrecognizedParameters",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int SCTPInitChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "initTag")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a_rwnd")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "noOutStreams")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "noInStreams")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "initTSN")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardTsn")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "addresses")==0) return base+6;
    if (fieldName[0]=='u' && strcmp(fieldName, "unrecognizedParameters")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPInitChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
        "uint16",
        "uint16",
        "uint32",
        "bool",
        "IPvXAddress",
        "uint8",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPInitChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPInitChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        case 6: return pp->getAddressesArraySize();
        case 7: return pp->getUnrecognizedParametersArraySize();
        default: return 0;
    }
}

std::string SCTPInitChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getInitTag());
        case 1: return ulong2string(pp->getA_rwnd());
        case 2: return ulong2string(pp->getNoOutStreams());
        case 3: return ulong2string(pp->getNoInStreams());
        case 4: return ulong2string(pp->getInitTSN());
        case 5: return bool2string(pp->getForwardTsn());
        case 6: {std::stringstream out; out << pp->getAddresses(i); return out.str();}
        case 7: return ulong2string(pp->getUnrecognizedParameters(i));
        default: return "";
    }
}

bool SCTPInitChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setInitTag(string2ulong(value)); return true;
        case 1: pp->setA_rwnd(string2ulong(value)); return true;
        case 2: pp->setNoOutStreams(string2ulong(value)); return true;
        case 3: pp->setNoInStreams(string2ulong(value)); return true;
        case 4: pp->setInitTSN(string2ulong(value)); return true;
        case 5: pp->setForwardTsn(string2bool(value)); return true;
        case 7: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPInitChunkDescriptor::getFieldStructName(void *object, int field) const
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
        "IPvXAddress",
        NULL,
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *SCTPInitChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getAddresses(i)); break;
        default: return NULL;
    }
}

Register_Class(SCTPInitAckChunk);

SCTPInitAckChunk::SCTPInitAckChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->initTag_var = 0;
    this->a_rwnd_var = 0;
    this->noOutStreams_var = 0;
    this->noInStreams_var = 0;
    this->initTSN_var = 0;
    this->forwardTsn_var = 0;
    addresses_arraysize = 0;
    this->addresses_var = 0;
    cookie_arraysize = 0;
    this->cookie_var = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters_var = 0;
}

SCTPInitAckChunk::SCTPInitAckChunk(const SCTPInitAckChunk& other) : SCTPChunk(other)
{
    addresses_arraysize = 0;
    this->addresses_var = 0;
    cookie_arraysize = 0;
    this->cookie_var = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters_var = 0;
    copy(other);
}

SCTPInitAckChunk::~SCTPInitAckChunk()
{
    delete [] addresses_var;
    delete [] cookie_var;
    delete [] unrecognizedParameters_var;
}

SCTPInitAckChunk& SCTPInitAckChunk::operator=(const SCTPInitAckChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPInitAckChunk::copy(const SCTPInitAckChunk& other)
{
    this->initTag_var = other.initTag_var;
    this->a_rwnd_var = other.a_rwnd_var;
    this->noOutStreams_var = other.noOutStreams_var;
    this->noInStreams_var = other.noInStreams_var;
    this->initTSN_var = other.initTSN_var;
    this->forwardTsn_var = other.forwardTsn_var;
    delete [] this->addresses_var;
    this->addresses_var = (other.addresses_arraysize==0) ? NULL : new IPvXAddress[other.addresses_arraysize];
    addresses_arraysize = other.addresses_arraysize;
    for (unsigned int i=0; i<addresses_arraysize; i++)
        this->addresses_var[i] = other.addresses_var[i];
    delete [] this->cookie_var;
    this->cookie_var = (other.cookie_arraysize==0) ? NULL : new char[other.cookie_arraysize];
    cookie_arraysize = other.cookie_arraysize;
    for (unsigned int i=0; i<cookie_arraysize; i++)
        this->cookie_var[i] = other.cookie_var[i];
    delete [] this->unrecognizedParameters_var;
    this->unrecognizedParameters_var = (other.unrecognizedParameters_arraysize==0) ? NULL : new uint8[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (unsigned int i=0; i<unrecognizedParameters_arraysize; i++)
        this->unrecognizedParameters_var[i] = other.unrecognizedParameters_var[i];
    this->stateCookie_var = other.stateCookie_var;
}

void SCTPInitAckChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->initTag_var);
    doPacking(b,this->a_rwnd_var);
    doPacking(b,this->noOutStreams_var);
    doPacking(b,this->noInStreams_var);
    doPacking(b,this->initTSN_var);
    doPacking(b,this->forwardTsn_var);
    b->pack(addresses_arraysize);
    doPacking(b,this->addresses_var,addresses_arraysize);
    b->pack(cookie_arraysize);
    doPacking(b,this->cookie_var,cookie_arraysize);
    b->pack(unrecognizedParameters_arraysize);
    doPacking(b,this->unrecognizedParameters_var,unrecognizedParameters_arraysize);
    doPacking(b,this->stateCookie_var);
}

void SCTPInitAckChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->initTag_var);
    doUnpacking(b,this->a_rwnd_var);
    doUnpacking(b,this->noOutStreams_var);
    doUnpacking(b,this->noInStreams_var);
    doUnpacking(b,this->initTSN_var);
    doUnpacking(b,this->forwardTsn_var);
    delete [] this->addresses_var;
    b->unpack(addresses_arraysize);
    if (addresses_arraysize==0) {
        this->addresses_var = 0;
    } else {
        this->addresses_var = new IPvXAddress[addresses_arraysize];
        doUnpacking(b,this->addresses_var,addresses_arraysize);
    }
    delete [] this->cookie_var;
    b->unpack(cookie_arraysize);
    if (cookie_arraysize==0) {
        this->cookie_var = 0;
    } else {
        this->cookie_var = new char[cookie_arraysize];
        doUnpacking(b,this->cookie_var,cookie_arraysize);
    }
    delete [] this->unrecognizedParameters_var;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize==0) {
        this->unrecognizedParameters_var = 0;
    } else {
        this->unrecognizedParameters_var = new uint8[unrecognizedParameters_arraysize];
        doUnpacking(b,this->unrecognizedParameters_var,unrecognizedParameters_arraysize);
    }
    doUnpacking(b,this->stateCookie_var);
}

uint32 SCTPInitAckChunk::getInitTag() const
{
    return initTag_var;
}

void SCTPInitAckChunk::setInitTag(uint32 initTag)
{
    this->initTag_var = initTag;
}

uint32 SCTPInitAckChunk::getA_rwnd() const
{
    return a_rwnd_var;
}

void SCTPInitAckChunk::setA_rwnd(uint32 a_rwnd)
{
    this->a_rwnd_var = a_rwnd;
}

uint16 SCTPInitAckChunk::getNoOutStreams() const
{
    return noOutStreams_var;
}

void SCTPInitAckChunk::setNoOutStreams(uint16 noOutStreams)
{
    this->noOutStreams_var = noOutStreams;
}

uint16 SCTPInitAckChunk::getNoInStreams() const
{
    return noInStreams_var;
}

void SCTPInitAckChunk::setNoInStreams(uint16 noInStreams)
{
    this->noInStreams_var = noInStreams;
}

uint32 SCTPInitAckChunk::getInitTSN() const
{
    return initTSN_var;
}

void SCTPInitAckChunk::setInitTSN(uint32 initTSN)
{
    this->initTSN_var = initTSN;
}

bool SCTPInitAckChunk::getForwardTsn() const
{
    return forwardTsn_var;
}

void SCTPInitAckChunk::setForwardTsn(bool forwardTsn)
{
    this->forwardTsn_var = forwardTsn;
}

void SCTPInitAckChunk::setAddressesArraySize(unsigned int size)
{
    IPvXAddress *addresses_var2 = (size==0) ? NULL : new IPvXAddress[size];
    unsigned int sz = addresses_arraysize < size ? addresses_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        addresses_var2[i] = this->addresses_var[i];
    addresses_arraysize = size;
    delete [] this->addresses_var;
    this->addresses_var = addresses_var2;
}

unsigned int SCTPInitAckChunk::getAddressesArraySize() const
{
    return addresses_arraysize;
}

IPvXAddress& SCTPInitAckChunk::getAddresses(unsigned int k)
{
    if (k>=addresses_arraysize) throw cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    return addresses_var[k];
}

void SCTPInitAckChunk::setAddresses(unsigned int k, const IPvXAddress& addresses)
{
    if (k>=addresses_arraysize) throw cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    this->addresses_var[k] = addresses;
}

void SCTPInitAckChunk::setCookieArraySize(unsigned int size)
{
    char *cookie_var2 = (size==0) ? NULL : new char[size];
    unsigned int sz = cookie_arraysize < size ? cookie_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        cookie_var2[i] = this->cookie_var[i];
    for (unsigned int i=sz; i<size; i++)
        cookie_var2[i] = 0;
    cookie_arraysize = size;
    delete [] this->cookie_var;
    this->cookie_var = cookie_var2;
}

unsigned int SCTPInitAckChunk::getCookieArraySize() const
{
    return cookie_arraysize;
}

char SCTPInitAckChunk::getCookie(unsigned int k) const
{
    if (k>=cookie_arraysize) throw cRuntimeError("Array of size %d indexed by %d", cookie_arraysize, k);
    return cookie_var[k];
}

void SCTPInitAckChunk::setCookie(unsigned int k, char cookie)
{
    if (k>=cookie_arraysize) throw cRuntimeError("Array of size %d indexed by %d", cookie_arraysize, k);
    this->cookie_var[k] = cookie;
}

void SCTPInitAckChunk::setUnrecognizedParametersArraySize(unsigned int size)
{
    uint8 *unrecognizedParameters_var2 = (size==0) ? NULL : new uint8[size];
    unsigned int sz = unrecognizedParameters_arraysize < size ? unrecognizedParameters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unrecognizedParameters_var2[i] = this->unrecognizedParameters_var[i];
    for (unsigned int i=sz; i<size; i++)
        unrecognizedParameters_var2[i] = 0;
    unrecognizedParameters_arraysize = size;
    delete [] this->unrecognizedParameters_var;
    this->unrecognizedParameters_var = unrecognizedParameters_var2;
}

unsigned int SCTPInitAckChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8 SCTPInitAckChunk::getUnrecognizedParameters(unsigned int k) const
{
    if (k>=unrecognizedParameters_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    return unrecognizedParameters_var[k];
}

void SCTPInitAckChunk::setUnrecognizedParameters(unsigned int k, uint8 unrecognizedParameters)
{
    if (k>=unrecognizedParameters_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    this->unrecognizedParameters_var[k] = unrecognizedParameters;
}

cPacketPtr& SCTPInitAckChunk::getStateCookie()
{
    return stateCookie_var;
}

void SCTPInitAckChunk::setStateCookie(const cPacketPtr& stateCookie)
{
    this->stateCookie_var = stateCookie;
}

class SCTPInitAckChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPInitAckChunkDescriptor();
    virtual ~SCTPInitAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPInitAckChunkDescriptor);

SCTPInitAckChunkDescriptor::SCTPInitAckChunkDescriptor() : cClassDescriptor("SCTPInitAckChunk", "SCTPChunk")
{
}

SCTPInitAckChunkDescriptor::~SCTPInitAckChunkDescriptor()
{
}

bool SCTPInitAckChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPInitAckChunk *>(obj)!=NULL;
}

const char *SCTPInitAckChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPInitAckChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount(object) : 10;
}

unsigned int SCTPInitAckChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *SCTPInitAckChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "initTag",
        "a_rwnd",
        "noOutStreams",
        "noInStreams",
        "initTSN",
        "forwardTsn",
        "addresses",
        "cookie",
        "unrecognizedParameters",
        "stateCookie",
    };
    return (field>=0 && field<10) ? fieldNames[field] : NULL;
}

int SCTPInitAckChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "initTag")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a_rwnd")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "noOutStreams")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "noInStreams")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "initTSN")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardTsn")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "addresses")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "cookie")==0) return base+7;
    if (fieldName[0]=='u' && strcmp(fieldName, "unrecognizedParameters")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "stateCookie")==0) return base+9;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPInitAckChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
        "uint16",
        "uint16",
        "uint32",
        "bool",
        "IPvXAddress",
        "char",
        "uint8",
        "cPacketPtr",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPInitAckChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPInitAckChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        case 6: return pp->getAddressesArraySize();
        case 7: return pp->getCookieArraySize();
        case 8: return pp->getUnrecognizedParametersArraySize();
        default: return 0;
    }
}

std::string SCTPInitAckChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getInitTag());
        case 1: return ulong2string(pp->getA_rwnd());
        case 2: return ulong2string(pp->getNoOutStreams());
        case 3: return ulong2string(pp->getNoInStreams());
        case 4: return ulong2string(pp->getInitTSN());
        case 5: return bool2string(pp->getForwardTsn());
        case 6: {std::stringstream out; out << pp->getAddresses(i); return out.str();}
        case 7: return long2string(pp->getCookie(i));
        case 8: return ulong2string(pp->getUnrecognizedParameters(i));
        case 9: {std::stringstream out; out << pp->getStateCookie(); return out.str();}
        default: return "";
    }
}

bool SCTPInitAckChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setInitTag(string2ulong(value)); return true;
        case 1: pp->setA_rwnd(string2ulong(value)); return true;
        case 2: pp->setNoOutStreams(string2ulong(value)); return true;
        case 3: pp->setNoInStreams(string2ulong(value)); return true;
        case 4: pp->setInitTSN(string2ulong(value)); return true;
        case 5: pp->setForwardTsn(string2bool(value)); return true;
        case 7: pp->setCookie(i,string2long(value)); return true;
        case 8: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPInitAckChunkDescriptor::getFieldStructName(void *object, int field) const
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
        "IPvXAddress",
        NULL,
        NULL,
        "cPacketPtr",
    };
    return (field>=0 && field<10) ? fieldStructNames[field] : NULL;
}

void *SCTPInitAckChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getAddresses(i)); break;
        case 9: return (void *)(&pp->getStateCookie()); break;
        default: return NULL;
    }
}

Register_Class(SCTPCookieEchoChunk);

SCTPCookieEchoChunk::SCTPCookieEchoChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    cookie_arraysize = 0;
    this->cookie_var = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters_var = 0;
}

SCTPCookieEchoChunk::SCTPCookieEchoChunk(const SCTPCookieEchoChunk& other) : SCTPChunk(other)
{
    cookie_arraysize = 0;
    this->cookie_var = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters_var = 0;
    copy(other);
}

SCTPCookieEchoChunk::~SCTPCookieEchoChunk()
{
    delete [] cookie_var;
    delete [] unrecognizedParameters_var;
}

SCTPCookieEchoChunk& SCTPCookieEchoChunk::operator=(const SCTPCookieEchoChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPCookieEchoChunk::copy(const SCTPCookieEchoChunk& other)
{
    delete [] this->cookie_var;
    this->cookie_var = (other.cookie_arraysize==0) ? NULL : new char[other.cookie_arraysize];
    cookie_arraysize = other.cookie_arraysize;
    for (unsigned int i=0; i<cookie_arraysize; i++)
        this->cookie_var[i] = other.cookie_var[i];
    this->stateCookie_var = other.stateCookie_var;
    delete [] this->unrecognizedParameters_var;
    this->unrecognizedParameters_var = (other.unrecognizedParameters_arraysize==0) ? NULL : new uint8[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (unsigned int i=0; i<unrecognizedParameters_arraysize; i++)
        this->unrecognizedParameters_var[i] = other.unrecognizedParameters_var[i];
}

void SCTPCookieEchoChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    b->pack(cookie_arraysize);
    doPacking(b,this->cookie_var,cookie_arraysize);
    doPacking(b,this->stateCookie_var);
    b->pack(unrecognizedParameters_arraysize);
    doPacking(b,this->unrecognizedParameters_var,unrecognizedParameters_arraysize);
}

void SCTPCookieEchoChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    delete [] this->cookie_var;
    b->unpack(cookie_arraysize);
    if (cookie_arraysize==0) {
        this->cookie_var = 0;
    } else {
        this->cookie_var = new char[cookie_arraysize];
        doUnpacking(b,this->cookie_var,cookie_arraysize);
    }
    doUnpacking(b,this->stateCookie_var);
    delete [] this->unrecognizedParameters_var;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize==0) {
        this->unrecognizedParameters_var = 0;
    } else {
        this->unrecognizedParameters_var = new uint8[unrecognizedParameters_arraysize];
        doUnpacking(b,this->unrecognizedParameters_var,unrecognizedParameters_arraysize);
    }
}

void SCTPCookieEchoChunk::setCookieArraySize(unsigned int size)
{
    char *cookie_var2 = (size==0) ? NULL : new char[size];
    unsigned int sz = cookie_arraysize < size ? cookie_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        cookie_var2[i] = this->cookie_var[i];
    for (unsigned int i=sz; i<size; i++)
        cookie_var2[i] = 0;
    cookie_arraysize = size;
    delete [] this->cookie_var;
    this->cookie_var = cookie_var2;
}

unsigned int SCTPCookieEchoChunk::getCookieArraySize() const
{
    return cookie_arraysize;
}

char SCTPCookieEchoChunk::getCookie(unsigned int k) const
{
    if (k>=cookie_arraysize) throw cRuntimeError("Array of size %d indexed by %d", cookie_arraysize, k);
    return cookie_var[k];
}

void SCTPCookieEchoChunk::setCookie(unsigned int k, char cookie)
{
    if (k>=cookie_arraysize) throw cRuntimeError("Array of size %d indexed by %d", cookie_arraysize, k);
    this->cookie_var[k] = cookie;
}

cPacketPtr& SCTPCookieEchoChunk::getStateCookie()
{
    return stateCookie_var;
}

void SCTPCookieEchoChunk::setStateCookie(const cPacketPtr& stateCookie)
{
    this->stateCookie_var = stateCookie;
}

void SCTPCookieEchoChunk::setUnrecognizedParametersArraySize(unsigned int size)
{
    uint8 *unrecognizedParameters_var2 = (size==0) ? NULL : new uint8[size];
    unsigned int sz = unrecognizedParameters_arraysize < size ? unrecognizedParameters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unrecognizedParameters_var2[i] = this->unrecognizedParameters_var[i];
    for (unsigned int i=sz; i<size; i++)
        unrecognizedParameters_var2[i] = 0;
    unrecognizedParameters_arraysize = size;
    delete [] this->unrecognizedParameters_var;
    this->unrecognizedParameters_var = unrecognizedParameters_var2;
}

unsigned int SCTPCookieEchoChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8 SCTPCookieEchoChunk::getUnrecognizedParameters(unsigned int k) const
{
    if (k>=unrecognizedParameters_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    return unrecognizedParameters_var[k];
}

void SCTPCookieEchoChunk::setUnrecognizedParameters(unsigned int k, uint8 unrecognizedParameters)
{
    if (k>=unrecognizedParameters_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    this->unrecognizedParameters_var[k] = unrecognizedParameters;
}

class SCTPCookieEchoChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPCookieEchoChunkDescriptor();
    virtual ~SCTPCookieEchoChunkDescriptor();

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

Register_ClassDescriptor(SCTPCookieEchoChunkDescriptor);

SCTPCookieEchoChunkDescriptor::SCTPCookieEchoChunkDescriptor() : cClassDescriptor("SCTPCookieEchoChunk", "SCTPChunk")
{
}

SCTPCookieEchoChunkDescriptor::~SCTPCookieEchoChunkDescriptor()
{
}

bool SCTPCookieEchoChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPCookieEchoChunk *>(obj)!=NULL;
}

const char *SCTPCookieEchoChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPCookieEchoChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SCTPCookieEchoChunkDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SCTPCookieEchoChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "cookie",
        "stateCookie",
        "unrecognizedParameters",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SCTPCookieEchoChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cookie")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stateCookie")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "unrecognizedParameters")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPCookieEchoChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "cPacketPtr",
        "uint8",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPCookieEchoChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPCookieEchoChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case 0: return pp->getCookieArraySize();
        case 2: return pp->getUnrecognizedParametersArraySize();
        default: return 0;
    }
}

std::string SCTPCookieEchoChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCookie(i));
        case 1: {std::stringstream out; out << pp->getStateCookie(); return out.str();}
        case 2: return ulong2string(pp->getUnrecognizedParameters(i));
        default: return "";
    }
}

bool SCTPCookieEchoChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setCookie(i,string2long(value)); return true;
        case 2: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPCookieEchoChunkDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "cPacketPtr",
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *SCTPCookieEchoChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getStateCookie()); break;
        default: return NULL;
    }
}

Register_Class(SCTPCookie);

SCTPCookie::SCTPCookie(const char *name, int kind) : cPacket(name,kind)
{
    this->creationTime_var = 0;
    this->localTag_var = 0;
    this->peerTag_var = 0;
    localTieTag_arraysize = 0;
    this->localTieTag_var = 0;
    peerTieTag_arraysize = 0;
    this->peerTieTag_var = 0;
}

SCTPCookie::SCTPCookie(const SCTPCookie& other) : cPacket(other)
{
    localTieTag_arraysize = 0;
    this->localTieTag_var = 0;
    peerTieTag_arraysize = 0;
    this->peerTieTag_var = 0;
    copy(other);
}

SCTPCookie::~SCTPCookie()
{
    delete [] localTieTag_var;
    delete [] peerTieTag_var;
}

SCTPCookie& SCTPCookie::operator=(const SCTPCookie& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPCookie::copy(const SCTPCookie& other)
{
    this->creationTime_var = other.creationTime_var;
    this->localTag_var = other.localTag_var;
    this->peerTag_var = other.peerTag_var;
    delete [] this->localTieTag_var;
    this->localTieTag_var = (other.localTieTag_arraysize==0) ? NULL : new uint8[other.localTieTag_arraysize];
    localTieTag_arraysize = other.localTieTag_arraysize;
    for (unsigned int i=0; i<localTieTag_arraysize; i++)
        this->localTieTag_var[i] = other.localTieTag_var[i];
    delete [] this->peerTieTag_var;
    this->peerTieTag_var = (other.peerTieTag_arraysize==0) ? NULL : new uint8[other.peerTieTag_arraysize];
    peerTieTag_arraysize = other.peerTieTag_arraysize;
    for (unsigned int i=0; i<peerTieTag_arraysize; i++)
        this->peerTieTag_var[i] = other.peerTieTag_var[i];
}

void SCTPCookie::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->creationTime_var);
    doPacking(b,this->localTag_var);
    doPacking(b,this->peerTag_var);
    b->pack(localTieTag_arraysize);
    doPacking(b,this->localTieTag_var,localTieTag_arraysize);
    b->pack(peerTieTag_arraysize);
    doPacking(b,this->peerTieTag_var,peerTieTag_arraysize);
}

void SCTPCookie::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->creationTime_var);
    doUnpacking(b,this->localTag_var);
    doUnpacking(b,this->peerTag_var);
    delete [] this->localTieTag_var;
    b->unpack(localTieTag_arraysize);
    if (localTieTag_arraysize==0) {
        this->localTieTag_var = 0;
    } else {
        this->localTieTag_var = new uint8[localTieTag_arraysize];
        doUnpacking(b,this->localTieTag_var,localTieTag_arraysize);
    }
    delete [] this->peerTieTag_var;
    b->unpack(peerTieTag_arraysize);
    if (peerTieTag_arraysize==0) {
        this->peerTieTag_var = 0;
    } else {
        this->peerTieTag_var = new uint8[peerTieTag_arraysize];
        doUnpacking(b,this->peerTieTag_var,peerTieTag_arraysize);
    }
}

simtime_t SCTPCookie::getCreationTime() const
{
    return creationTime_var;
}

void SCTPCookie::setCreationTime(simtime_t creationTime)
{
    this->creationTime_var = creationTime;
}

uint32 SCTPCookie::getLocalTag() const
{
    return localTag_var;
}

void SCTPCookie::setLocalTag(uint32 localTag)
{
    this->localTag_var = localTag;
}

uint32 SCTPCookie::getPeerTag() const
{
    return peerTag_var;
}

void SCTPCookie::setPeerTag(uint32 peerTag)
{
    this->peerTag_var = peerTag;
}

void SCTPCookie::setLocalTieTagArraySize(unsigned int size)
{
    uint8 *localTieTag_var2 = (size==0) ? NULL : new uint8[size];
    unsigned int sz = localTieTag_arraysize < size ? localTieTag_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        localTieTag_var2[i] = this->localTieTag_var[i];
    for (unsigned int i=sz; i<size; i++)
        localTieTag_var2[i] = 0;
    localTieTag_arraysize = size;
    delete [] this->localTieTag_var;
    this->localTieTag_var = localTieTag_var2;
}

unsigned int SCTPCookie::getLocalTieTagArraySize() const
{
    return localTieTag_arraysize;
}

uint8 SCTPCookie::getLocalTieTag(unsigned int k) const
{
    if (k>=localTieTag_arraysize) throw cRuntimeError("Array of size %d indexed by %d", localTieTag_arraysize, k);
    return localTieTag_var[k];
}

void SCTPCookie::setLocalTieTag(unsigned int k, uint8 localTieTag)
{
    if (k>=localTieTag_arraysize) throw cRuntimeError("Array of size %d indexed by %d", localTieTag_arraysize, k);
    this->localTieTag_var[k] = localTieTag;
}

void SCTPCookie::setPeerTieTagArraySize(unsigned int size)
{
    uint8 *peerTieTag_var2 = (size==0) ? NULL : new uint8[size];
    unsigned int sz = peerTieTag_arraysize < size ? peerTieTag_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        peerTieTag_var2[i] = this->peerTieTag_var[i];
    for (unsigned int i=sz; i<size; i++)
        peerTieTag_var2[i] = 0;
    peerTieTag_arraysize = size;
    delete [] this->peerTieTag_var;
    this->peerTieTag_var = peerTieTag_var2;
}

unsigned int SCTPCookie::getPeerTieTagArraySize() const
{
    return peerTieTag_arraysize;
}

uint8 SCTPCookie::getPeerTieTag(unsigned int k) const
{
    if (k>=peerTieTag_arraysize) throw cRuntimeError("Array of size %d indexed by %d", peerTieTag_arraysize, k);
    return peerTieTag_var[k];
}

void SCTPCookie::setPeerTieTag(unsigned int k, uint8 peerTieTag)
{
    if (k>=peerTieTag_arraysize) throw cRuntimeError("Array of size %d indexed by %d", peerTieTag_arraysize, k);
    this->peerTieTag_var[k] = peerTieTag;
}

class SCTPCookieDescriptor : public cClassDescriptor
{
  public:
    SCTPCookieDescriptor();
    virtual ~SCTPCookieDescriptor();

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

Register_ClassDescriptor(SCTPCookieDescriptor);

SCTPCookieDescriptor::SCTPCookieDescriptor() : cClassDescriptor("SCTPCookie", "cPacket")
{
}

SCTPCookieDescriptor::~SCTPCookieDescriptor()
{
}

bool SCTPCookieDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPCookie *>(obj)!=NULL;
}

const char *SCTPCookieDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPCookieDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int SCTPCookieDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *SCTPCookieDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "creationTime",
        "localTag",
        "peerTag",
        "localTieTag",
        "peerTieTag",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int SCTPCookieDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localTag")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerTag")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "localTieTag")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerTieTag")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPCookieDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "uint32",
        "uint32",
        "uint8",
        "uint8",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPCookieDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPCookieDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        case 3: return pp->getLocalTieTagArraySize();
        case 4: return pp->getPeerTieTagArraySize();
        default: return 0;
    }
}

std::string SCTPCookieDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getCreationTime());
        case 1: return ulong2string(pp->getLocalTag());
        case 2: return ulong2string(pp->getPeerTag());
        case 3: return ulong2string(pp->getLocalTieTag(i));
        case 4: return ulong2string(pp->getPeerTieTag(i));
        default: return "";
    }
}

bool SCTPCookieDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        case 0: pp->setCreationTime(string2double(value)); return true;
        case 1: pp->setLocalTag(string2ulong(value)); return true;
        case 2: pp->setPeerTag(string2ulong(value)); return true;
        case 3: pp->setLocalTieTag(i,string2ulong(value)); return true;
        case 4: pp->setPeerTieTag(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPCookieDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *SCTPCookieDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPCookieAckChunk);

SCTPCookieAckChunk::SCTPCookieAckChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
}

SCTPCookieAckChunk::SCTPCookieAckChunk(const SCTPCookieAckChunk& other) : SCTPChunk(other)
{
    copy(other);
}

SCTPCookieAckChunk::~SCTPCookieAckChunk()
{
}

SCTPCookieAckChunk& SCTPCookieAckChunk::operator=(const SCTPCookieAckChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPCookieAckChunk::copy(const SCTPCookieAckChunk& other)
{
}

void SCTPCookieAckChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
}

void SCTPCookieAckChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
}

class SCTPCookieAckChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPCookieAckChunkDescriptor();
    virtual ~SCTPCookieAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPCookieAckChunkDescriptor);

SCTPCookieAckChunkDescriptor::SCTPCookieAckChunkDescriptor() : cClassDescriptor("SCTPCookieAckChunk", "SCTPChunk")
{
}

SCTPCookieAckChunkDescriptor::~SCTPCookieAckChunkDescriptor()
{
}

bool SCTPCookieAckChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPCookieAckChunk *>(obj)!=NULL;
}

const char *SCTPCookieAckChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPCookieAckChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int SCTPCookieAckChunkDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *SCTPCookieAckChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int SCTPCookieAckChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPCookieAckChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *SCTPCookieAckChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPCookieAckChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPCookieAckChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SCTPCookieAckChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SCTPCookieAckChunkDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *SCTPCookieAckChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPDataMsg);

SCTPDataMsg::SCTPDataMsg(const char *name, int kind) : cPacket(name,kind)
{
    this->eBit_var = 0;
    this->bBit_var = 0;
    this->enqueuingTime_var = 0;
    this->expiryTime_var = 0;
    this->ppid_var = 0;
    this->msgNum_var = 0;
    this->sid_var = 0;
    this->ordered_var = 0;
    this->booksize_var = 0;
    this->rtx_var = 0;
    this->fragment_var = 0;
}

SCTPDataMsg::SCTPDataMsg(const SCTPDataMsg& other) : cPacket(other)
{
    copy(other);
}

SCTPDataMsg::~SCTPDataMsg()
{
}

SCTPDataMsg& SCTPDataMsg::operator=(const SCTPDataMsg& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPDataMsg::copy(const SCTPDataMsg& other)
{
    this->eBit_var = other.eBit_var;
    this->bBit_var = other.bBit_var;
    this->enqueuingTime_var = other.enqueuingTime_var;
    this->expiryTime_var = other.expiryTime_var;
    this->ppid_var = other.ppid_var;
    this->initialDestination_var = other.initialDestination_var;
    this->msgNum_var = other.msgNum_var;
    this->sid_var = other.sid_var;
    this->ordered_var = other.ordered_var;
    this->booksize_var = other.booksize_var;
    this->rtx_var = other.rtx_var;
    this->fragment_var = other.fragment_var;
}

void SCTPDataMsg::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->eBit_var);
    doPacking(b,this->bBit_var);
    doPacking(b,this->enqueuingTime_var);
    doPacking(b,this->expiryTime_var);
    doPacking(b,this->ppid_var);
    doPacking(b,this->initialDestination_var);
    doPacking(b,this->msgNum_var);
    doPacking(b,this->sid_var);
    doPacking(b,this->ordered_var);
    doPacking(b,this->booksize_var);
    doPacking(b,this->rtx_var);
    doPacking(b,this->fragment_var);
}

void SCTPDataMsg::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->eBit_var);
    doUnpacking(b,this->bBit_var);
    doUnpacking(b,this->enqueuingTime_var);
    doUnpacking(b,this->expiryTime_var);
    doUnpacking(b,this->ppid_var);
    doUnpacking(b,this->initialDestination_var);
    doUnpacking(b,this->msgNum_var);
    doUnpacking(b,this->sid_var);
    doUnpacking(b,this->ordered_var);
    doUnpacking(b,this->booksize_var);
    doUnpacking(b,this->rtx_var);
    doUnpacking(b,this->fragment_var);
}

bool SCTPDataMsg::getEBit() const
{
    return eBit_var;
}

void SCTPDataMsg::setEBit(bool eBit)
{
    this->eBit_var = eBit;
}

bool SCTPDataMsg::getBBit() const
{
    return bBit_var;
}

void SCTPDataMsg::setBBit(bool bBit)
{
    this->bBit_var = bBit;
}

simtime_t SCTPDataMsg::getEnqueuingTime() const
{
    return enqueuingTime_var;
}

void SCTPDataMsg::setEnqueuingTime(simtime_t enqueuingTime)
{
    this->enqueuingTime_var = enqueuingTime;
}

simtime_t SCTPDataMsg::getExpiryTime() const
{
    return expiryTime_var;
}

void SCTPDataMsg::setExpiryTime(simtime_t expiryTime)
{
    this->expiryTime_var = expiryTime;
}

uint32 SCTPDataMsg::getPpid() const
{
    return ppid_var;
}

void SCTPDataMsg::setPpid(uint32 ppid)
{
    this->ppid_var = ppid;
}

IPvXAddress& SCTPDataMsg::getInitialDestination()
{
    return initialDestination_var;
}

void SCTPDataMsg::setInitialDestination(const IPvXAddress& initialDestination)
{
    this->initialDestination_var = initialDestination;
}

uint32 SCTPDataMsg::getMsgNum() const
{
    return msgNum_var;
}

void SCTPDataMsg::setMsgNum(uint32 msgNum)
{
    this->msgNum_var = msgNum;
}

uint16 SCTPDataMsg::getSid() const
{
    return sid_var;
}

void SCTPDataMsg::setSid(uint16 sid)
{
    this->sid_var = sid;
}

bool SCTPDataMsg::getOrdered() const
{
    return ordered_var;
}

void SCTPDataMsg::setOrdered(bool ordered)
{
    this->ordered_var = ordered;
}

uint32 SCTPDataMsg::getBooksize() const
{
    return booksize_var;
}

void SCTPDataMsg::setBooksize(uint32 booksize)
{
    this->booksize_var = booksize;
}

uint32 SCTPDataMsg::getRtx() const
{
    return rtx_var;
}

void SCTPDataMsg::setRtx(uint32 rtx)
{
    this->rtx_var = rtx;
}

bool SCTPDataMsg::getFragment() const
{
    return fragment_var;
}

void SCTPDataMsg::setFragment(bool fragment)
{
    this->fragment_var = fragment;
}

class SCTPDataMsgDescriptor : public cClassDescriptor
{
  public:
    SCTPDataMsgDescriptor();
    virtual ~SCTPDataMsgDescriptor();

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

Register_ClassDescriptor(SCTPDataMsgDescriptor);

SCTPDataMsgDescriptor::SCTPDataMsgDescriptor() : cClassDescriptor("SCTPDataMsg", "cPacket")
{
}

SCTPDataMsgDescriptor::~SCTPDataMsgDescriptor()
{
}

bool SCTPDataMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPDataMsg *>(obj)!=NULL;
}

const char *SCTPDataMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPDataMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount(object) : 12;
}

unsigned int SCTPDataMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *SCTPDataMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "eBit",
        "bBit",
        "enqueuingTime",
        "expiryTime",
        "ppid",
        "initialDestination",
        "msgNum",
        "sid",
        "ordered",
        "booksize",
        "rtx",
        "fragment",
    };
    return (field>=0 && field<12) ? fieldNames[field] : NULL;
}

int SCTPDataMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eBit")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bBit")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "enqueuingTime")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "expiryTime")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "ppid")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "initialDestination")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgNum")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sid")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "ordered")==0) return base+8;
    if (fieldName[0]=='b' && strcmp(fieldName, "booksize")==0) return base+9;
    if (fieldName[0]=='r' && strcmp(fieldName, "rtx")==0) return base+10;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragment")==0) return base+11;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPDataMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "simtime_t",
        "simtime_t",
        "uint32",
        "IPvXAddress",
        "uint32",
        "uint16",
        "bool",
        "uint32",
        "uint32",
        "bool",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPDataMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPDataMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPDataMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getEBit());
        case 1: return bool2string(pp->getBBit());
        case 2: return double2string(pp->getEnqueuingTime());
        case 3: return double2string(pp->getExpiryTime());
        case 4: return ulong2string(pp->getPpid());
        case 5: {std::stringstream out; out << pp->getInitialDestination(); return out.str();}
        case 6: return ulong2string(pp->getMsgNum());
        case 7: return ulong2string(pp->getSid());
        case 8: return bool2string(pp->getOrdered());
        case 9: return ulong2string(pp->getBooksize());
        case 10: return ulong2string(pp->getRtx());
        case 11: return bool2string(pp->getFragment());
        default: return "";
    }
}

bool SCTPDataMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setEBit(string2bool(value)); return true;
        case 1: pp->setBBit(string2bool(value)); return true;
        case 2: pp->setEnqueuingTime(string2double(value)); return true;
        case 3: pp->setExpiryTime(string2double(value)); return true;
        case 4: pp->setPpid(string2ulong(value)); return true;
        case 6: pp->setMsgNum(string2ulong(value)); return true;
        case 7: pp->setSid(string2ulong(value)); return true;
        case 8: pp->setOrdered(string2bool(value)); return true;
        case 9: pp->setBooksize(string2ulong(value)); return true;
        case 10: pp->setRtx(string2ulong(value)); return true;
        case 11: pp->setFragment(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPDataMsgDescriptor::getFieldStructName(void *object, int field) const
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
        "IPvXAddress",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<12) ? fieldStructNames[field] : NULL;
}

void *SCTPDataMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getInitialDestination()); break;
        default: return NULL;
    }
}

Register_Class(SCTPDataChunk);

SCTPDataChunk::SCTPDataChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->eBit_var = 0;
    this->bBit_var = 0;
    this->uBit_var = 0;
    this->tsn_var = 0;
    this->sid_var = 0;
    this->ssn_var = 0;
    this->ppid_var = 0;
    this->enqueuingTime_var = 0;
}

SCTPDataChunk::SCTPDataChunk(const SCTPDataChunk& other) : SCTPChunk(other)
{
    copy(other);
}

SCTPDataChunk::~SCTPDataChunk()
{
}

SCTPDataChunk& SCTPDataChunk::operator=(const SCTPDataChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPDataChunk::copy(const SCTPDataChunk& other)
{
    this->eBit_var = other.eBit_var;
    this->bBit_var = other.bBit_var;
    this->uBit_var = other.uBit_var;
    this->tsn_var = other.tsn_var;
    this->sid_var = other.sid_var;
    this->ssn_var = other.ssn_var;
    this->ppid_var = other.ppid_var;
    this->enqueuingTime_var = other.enqueuingTime_var;
}

void SCTPDataChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->eBit_var);
    doPacking(b,this->bBit_var);
    doPacking(b,this->uBit_var);
    doPacking(b,this->tsn_var);
    doPacking(b,this->sid_var);
    doPacking(b,this->ssn_var);
    doPacking(b,this->ppid_var);
    doPacking(b,this->enqueuingTime_var);
}

void SCTPDataChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->eBit_var);
    doUnpacking(b,this->bBit_var);
    doUnpacking(b,this->uBit_var);
    doUnpacking(b,this->tsn_var);
    doUnpacking(b,this->sid_var);
    doUnpacking(b,this->ssn_var);
    doUnpacking(b,this->ppid_var);
    doUnpacking(b,this->enqueuingTime_var);
}

bool SCTPDataChunk::getEBit() const
{
    return eBit_var;
}

void SCTPDataChunk::setEBit(bool eBit)
{
    this->eBit_var = eBit;
}

bool SCTPDataChunk::getBBit() const
{
    return bBit_var;
}

void SCTPDataChunk::setBBit(bool bBit)
{
    this->bBit_var = bBit;
}

bool SCTPDataChunk::getUBit() const
{
    return uBit_var;
}

void SCTPDataChunk::setUBit(bool uBit)
{
    this->uBit_var = uBit;
}

uint32 SCTPDataChunk::getTsn() const
{
    return tsn_var;
}

void SCTPDataChunk::setTsn(uint32 tsn)
{
    this->tsn_var = tsn;
}

uint16 SCTPDataChunk::getSid() const
{
    return sid_var;
}

void SCTPDataChunk::setSid(uint16 sid)
{
    this->sid_var = sid;
}

uint16 SCTPDataChunk::getSsn() const
{
    return ssn_var;
}

void SCTPDataChunk::setSsn(uint16 ssn)
{
    this->ssn_var = ssn;
}

uint32 SCTPDataChunk::getPpid() const
{
    return ppid_var;
}

void SCTPDataChunk::setPpid(uint32 ppid)
{
    this->ppid_var = ppid;
}

simtime_t SCTPDataChunk::getEnqueuingTime() const
{
    return enqueuingTime_var;
}

void SCTPDataChunk::setEnqueuingTime(simtime_t enqueuingTime)
{
    this->enqueuingTime_var = enqueuingTime;
}

class SCTPDataChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPDataChunkDescriptor();
    virtual ~SCTPDataChunkDescriptor();

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

Register_ClassDescriptor(SCTPDataChunkDescriptor);

SCTPDataChunkDescriptor::SCTPDataChunkDescriptor() : cClassDescriptor("SCTPDataChunk", "SCTPChunk")
{
}

SCTPDataChunkDescriptor::~SCTPDataChunkDescriptor()
{
}

bool SCTPDataChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPDataChunk *>(obj)!=NULL;
}

const char *SCTPDataChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPDataChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int SCTPDataChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *SCTPDataChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "eBit",
        "bBit",
        "uBit",
        "tsn",
        "sid",
        "ssn",
        "ppid",
        "enqueuingTime",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int SCTPDataChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eBit")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bBit")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "uBit")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "tsn")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "sid")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssn")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "ppid")==0) return base+6;
    if (fieldName[0]=='e' && strcmp(fieldName, "enqueuingTime")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPDataChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "uint32",
        "uint16",
        "uint16",
        "uint32",
        "simtime_t",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPDataChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPDataChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPDataChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getEBit());
        case 1: return bool2string(pp->getBBit());
        case 2: return bool2string(pp->getUBit());
        case 3: return ulong2string(pp->getTsn());
        case 4: return ulong2string(pp->getSid());
        case 5: return ulong2string(pp->getSsn());
        case 6: return ulong2string(pp->getPpid());
        case 7: return double2string(pp->getEnqueuingTime());
        default: return "";
    }
}

bool SCTPDataChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setEBit(string2bool(value)); return true;
        case 1: pp->setBBit(string2bool(value)); return true;
        case 2: pp->setUBit(string2bool(value)); return true;
        case 3: pp->setTsn(string2ulong(value)); return true;
        case 4: pp->setSid(string2ulong(value)); return true;
        case 5: pp->setSsn(string2ulong(value)); return true;
        case 6: pp->setPpid(string2ulong(value)); return true;
        case 7: pp->setEnqueuingTime(string2double(value)); return true;
        default: return false;
    }
}

const char *SCTPDataChunkDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *SCTPDataChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPForwardTsnChunk);

SCTPForwardTsnChunk::SCTPForwardTsnChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->newCumTsn_var = 0;
    sid_arraysize = 0;
    this->sid_var = 0;
    ssn_arraysize = 0;
    this->ssn_var = 0;
}

SCTPForwardTsnChunk::SCTPForwardTsnChunk(const SCTPForwardTsnChunk& other) : SCTPChunk(other)
{
    sid_arraysize = 0;
    this->sid_var = 0;
    ssn_arraysize = 0;
    this->ssn_var = 0;
    copy(other);
}

SCTPForwardTsnChunk::~SCTPForwardTsnChunk()
{
    delete [] sid_var;
    delete [] ssn_var;
}

SCTPForwardTsnChunk& SCTPForwardTsnChunk::operator=(const SCTPForwardTsnChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPForwardTsnChunk::copy(const SCTPForwardTsnChunk& other)
{
    this->newCumTsn_var = other.newCumTsn_var;
    delete [] this->sid_var;
    this->sid_var = (other.sid_arraysize==0) ? NULL : new uint16[other.sid_arraysize];
    sid_arraysize = other.sid_arraysize;
    for (unsigned int i=0; i<sid_arraysize; i++)
        this->sid_var[i] = other.sid_var[i];
    delete [] this->ssn_var;
    this->ssn_var = (other.ssn_arraysize==0) ? NULL : new short[other.ssn_arraysize];
    ssn_arraysize = other.ssn_arraysize;
    for (unsigned int i=0; i<ssn_arraysize; i++)
        this->ssn_var[i] = other.ssn_var[i];
}

void SCTPForwardTsnChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->newCumTsn_var);
    b->pack(sid_arraysize);
    doPacking(b,this->sid_var,sid_arraysize);
    b->pack(ssn_arraysize);
    doPacking(b,this->ssn_var,ssn_arraysize);
}

void SCTPForwardTsnChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->newCumTsn_var);
    delete [] this->sid_var;
    b->unpack(sid_arraysize);
    if (sid_arraysize==0) {
        this->sid_var = 0;
    } else {
        this->sid_var = new uint16[sid_arraysize];
        doUnpacking(b,this->sid_var,sid_arraysize);
    }
    delete [] this->ssn_var;
    b->unpack(ssn_arraysize);
    if (ssn_arraysize==0) {
        this->ssn_var = 0;
    } else {
        this->ssn_var = new short[ssn_arraysize];
        doUnpacking(b,this->ssn_var,ssn_arraysize);
    }
}

uint32 SCTPForwardTsnChunk::getNewCumTsn() const
{
    return newCumTsn_var;
}

void SCTPForwardTsnChunk::setNewCumTsn(uint32 newCumTsn)
{
    this->newCumTsn_var = newCumTsn;
}

void SCTPForwardTsnChunk::setSidArraySize(unsigned int size)
{
    uint16 *sid_var2 = (size==0) ? NULL : new uint16[size];
    unsigned int sz = sid_arraysize < size ? sid_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sid_var2[i] = this->sid_var[i];
    for (unsigned int i=sz; i<size; i++)
        sid_var2[i] = 0;
    sid_arraysize = size;
    delete [] this->sid_var;
    this->sid_var = sid_var2;
}

unsigned int SCTPForwardTsnChunk::getSidArraySize() const
{
    return sid_arraysize;
}

uint16 SCTPForwardTsnChunk::getSid(unsigned int k) const
{
    if (k>=sid_arraysize) throw cRuntimeError("Array of size %d indexed by %d", sid_arraysize, k);
    return sid_var[k];
}

void SCTPForwardTsnChunk::setSid(unsigned int k, uint16 sid)
{
    if (k>=sid_arraysize) throw cRuntimeError("Array of size %d indexed by %d", sid_arraysize, k);
    this->sid_var[k] = sid;
}

void SCTPForwardTsnChunk::setSsnArraySize(unsigned int size)
{
    short *ssn_var2 = (size==0) ? NULL : new short[size];
    unsigned int sz = ssn_arraysize < size ? ssn_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        ssn_var2[i] = this->ssn_var[i];
    for (unsigned int i=sz; i<size; i++)
        ssn_var2[i] = 0;
    ssn_arraysize = size;
    delete [] this->ssn_var;
    this->ssn_var = ssn_var2;
}

unsigned int SCTPForwardTsnChunk::getSsnArraySize() const
{
    return ssn_arraysize;
}

short SCTPForwardTsnChunk::getSsn(unsigned int k) const
{
    if (k>=ssn_arraysize) throw cRuntimeError("Array of size %d indexed by %d", ssn_arraysize, k);
    return ssn_var[k];
}

void SCTPForwardTsnChunk::setSsn(unsigned int k, short ssn)
{
    if (k>=ssn_arraysize) throw cRuntimeError("Array of size %d indexed by %d", ssn_arraysize, k);
    this->ssn_var[k] = ssn;
}

class SCTPForwardTsnChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPForwardTsnChunkDescriptor();
    virtual ~SCTPForwardTsnChunkDescriptor();

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

Register_ClassDescriptor(SCTPForwardTsnChunkDescriptor);

SCTPForwardTsnChunkDescriptor::SCTPForwardTsnChunkDescriptor() : cClassDescriptor("SCTPForwardTsnChunk", "SCTPChunk")
{
}

SCTPForwardTsnChunkDescriptor::~SCTPForwardTsnChunkDescriptor()
{
}

bool SCTPForwardTsnChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPForwardTsnChunk *>(obj)!=NULL;
}

const char *SCTPForwardTsnChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPForwardTsnChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SCTPForwardTsnChunkDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SCTPForwardTsnChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "newCumTsn",
        "sid",
        "ssn",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SCTPForwardTsnChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "newCumTsn")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sid")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssn")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPForwardTsnChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint16",
        "short",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPForwardTsnChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPForwardTsnChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case 1: return pp->getSidArraySize();
        case 2: return pp->getSsnArraySize();
        default: return 0;
    }
}

std::string SCTPForwardTsnChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getNewCumTsn());
        case 1: return ulong2string(pp->getSid(i));
        case 2: return long2string(pp->getSsn(i));
        default: return "";
    }
}

bool SCTPForwardTsnChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setNewCumTsn(string2ulong(value)); return true;
        case 1: pp->setSid(i,string2ulong(value)); return true;
        case 2: pp->setSsn(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPForwardTsnChunkDescriptor::getFieldStructName(void *object, int field) const
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

void *SCTPForwardTsnChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPSackChunk);

SCTPSackChunk::SCTPSackChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->cumTsnAck_var = 0;
    this->a_rwnd_var = 0;
    this->numGaps_var = 0;
    this->numDupTsns_var = 0;
    gapStart_arraysize = 0;
    this->gapStart_var = 0;
    gapStop_arraysize = 0;
    this->gapStop_var = 0;
    dupTsns_arraysize = 0;
    this->dupTsns_var = 0;
    this->sackSeqNum_var = 0;
}

SCTPSackChunk::SCTPSackChunk(const SCTPSackChunk& other) : SCTPChunk(other)
{
    gapStart_arraysize = 0;
    this->gapStart_var = 0;
    gapStop_arraysize = 0;
    this->gapStop_var = 0;
    dupTsns_arraysize = 0;
    this->dupTsns_var = 0;
    copy(other);
}

SCTPSackChunk::~SCTPSackChunk()
{
    delete [] gapStart_var;
    delete [] gapStop_var;
    delete [] dupTsns_var;
}

SCTPSackChunk& SCTPSackChunk::operator=(const SCTPSackChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPSackChunk::copy(const SCTPSackChunk& other)
{
    this->cumTsnAck_var = other.cumTsnAck_var;
    this->a_rwnd_var = other.a_rwnd_var;
    this->numGaps_var = other.numGaps_var;
    this->numDupTsns_var = other.numDupTsns_var;
    delete [] this->gapStart_var;
    this->gapStart_var = (other.gapStart_arraysize==0) ? NULL : new uint32[other.gapStart_arraysize];
    gapStart_arraysize = other.gapStart_arraysize;
    for (unsigned int i=0; i<gapStart_arraysize; i++)
        this->gapStart_var[i] = other.gapStart_var[i];
    delete [] this->gapStop_var;
    this->gapStop_var = (other.gapStop_arraysize==0) ? NULL : new uint32[other.gapStop_arraysize];
    gapStop_arraysize = other.gapStop_arraysize;
    for (unsigned int i=0; i<gapStop_arraysize; i++)
        this->gapStop_var[i] = other.gapStop_var[i];
    delete [] this->dupTsns_var;
    this->dupTsns_var = (other.dupTsns_arraysize==0) ? NULL : new uint32[other.dupTsns_arraysize];
    dupTsns_arraysize = other.dupTsns_arraysize;
    for (unsigned int i=0; i<dupTsns_arraysize; i++)
        this->dupTsns_var[i] = other.dupTsns_var[i];
    this->sackSeqNum_var = other.sackSeqNum_var;
}

void SCTPSackChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->cumTsnAck_var);
    doPacking(b,this->a_rwnd_var);
    doPacking(b,this->numGaps_var);
    doPacking(b,this->numDupTsns_var);
    b->pack(gapStart_arraysize);
    doPacking(b,this->gapStart_var,gapStart_arraysize);
    b->pack(gapStop_arraysize);
    doPacking(b,this->gapStop_var,gapStop_arraysize);
    b->pack(dupTsns_arraysize);
    doPacking(b,this->dupTsns_var,dupTsns_arraysize);
    doPacking(b,this->sackSeqNum_var);
}

void SCTPSackChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->cumTsnAck_var);
    doUnpacking(b,this->a_rwnd_var);
    doUnpacking(b,this->numGaps_var);
    doUnpacking(b,this->numDupTsns_var);
    delete [] this->gapStart_var;
    b->unpack(gapStart_arraysize);
    if (gapStart_arraysize==0) {
        this->gapStart_var = 0;
    } else {
        this->gapStart_var = new uint32[gapStart_arraysize];
        doUnpacking(b,this->gapStart_var,gapStart_arraysize);
    }
    delete [] this->gapStop_var;
    b->unpack(gapStop_arraysize);
    if (gapStop_arraysize==0) {
        this->gapStop_var = 0;
    } else {
        this->gapStop_var = new uint32[gapStop_arraysize];
        doUnpacking(b,this->gapStop_var,gapStop_arraysize);
    }
    delete [] this->dupTsns_var;
    b->unpack(dupTsns_arraysize);
    if (dupTsns_arraysize==0) {
        this->dupTsns_var = 0;
    } else {
        this->dupTsns_var = new uint32[dupTsns_arraysize];
        doUnpacking(b,this->dupTsns_var,dupTsns_arraysize);
    }
    doUnpacking(b,this->sackSeqNum_var);
}

uint32 SCTPSackChunk::getCumTsnAck() const
{
    return cumTsnAck_var;
}

void SCTPSackChunk::setCumTsnAck(uint32 cumTsnAck)
{
    this->cumTsnAck_var = cumTsnAck;
}

uint32 SCTPSackChunk::getA_rwnd() const
{
    return a_rwnd_var;
}

void SCTPSackChunk::setA_rwnd(uint32 a_rwnd)
{
    this->a_rwnd_var = a_rwnd;
}

uint16 SCTPSackChunk::getNumGaps() const
{
    return numGaps_var;
}

void SCTPSackChunk::setNumGaps(uint16 numGaps)
{
    this->numGaps_var = numGaps;
}

uint16 SCTPSackChunk::getNumDupTsns() const
{
    return numDupTsns_var;
}

void SCTPSackChunk::setNumDupTsns(uint16 numDupTsns)
{
    this->numDupTsns_var = numDupTsns;
}

void SCTPSackChunk::setGapStartArraySize(unsigned int size)
{
    uint32 *gapStart_var2 = (size==0) ? NULL : new uint32[size];
    unsigned int sz = gapStart_arraysize < size ? gapStart_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        gapStart_var2[i] = this->gapStart_var[i];
    for (unsigned int i=sz; i<size; i++)
        gapStart_var2[i] = 0;
    gapStart_arraysize = size;
    delete [] this->gapStart_var;
    this->gapStart_var = gapStart_var2;
}

unsigned int SCTPSackChunk::getGapStartArraySize() const
{
    return gapStart_arraysize;
}

uint32 SCTPSackChunk::getGapStart(unsigned int k) const
{
    if (k>=gapStart_arraysize) throw cRuntimeError("Array of size %d indexed by %d", gapStart_arraysize, k);
    return gapStart_var[k];
}

void SCTPSackChunk::setGapStart(unsigned int k, uint32 gapStart)
{
    if (k>=gapStart_arraysize) throw cRuntimeError("Array of size %d indexed by %d", gapStart_arraysize, k);
    this->gapStart_var[k] = gapStart;
}

void SCTPSackChunk::setGapStopArraySize(unsigned int size)
{
    uint32 *gapStop_var2 = (size==0) ? NULL : new uint32[size];
    unsigned int sz = gapStop_arraysize < size ? gapStop_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        gapStop_var2[i] = this->gapStop_var[i];
    for (unsigned int i=sz; i<size; i++)
        gapStop_var2[i] = 0;
    gapStop_arraysize = size;
    delete [] this->gapStop_var;
    this->gapStop_var = gapStop_var2;
}

unsigned int SCTPSackChunk::getGapStopArraySize() const
{
    return gapStop_arraysize;
}

uint32 SCTPSackChunk::getGapStop(unsigned int k) const
{
    if (k>=gapStop_arraysize) throw cRuntimeError("Array of size %d indexed by %d", gapStop_arraysize, k);
    return gapStop_var[k];
}

void SCTPSackChunk::setGapStop(unsigned int k, uint32 gapStop)
{
    if (k>=gapStop_arraysize) throw cRuntimeError("Array of size %d indexed by %d", gapStop_arraysize, k);
    this->gapStop_var[k] = gapStop;
}

void SCTPSackChunk::setDupTsnsArraySize(unsigned int size)
{
    uint32 *dupTsns_var2 = (size==0) ? NULL : new uint32[size];
    unsigned int sz = dupTsns_arraysize < size ? dupTsns_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        dupTsns_var2[i] = this->dupTsns_var[i];
    for (unsigned int i=sz; i<size; i++)
        dupTsns_var2[i] = 0;
    dupTsns_arraysize = size;
    delete [] this->dupTsns_var;
    this->dupTsns_var = dupTsns_var2;
}

unsigned int SCTPSackChunk::getDupTsnsArraySize() const
{
    return dupTsns_arraysize;
}

uint32 SCTPSackChunk::getDupTsns(unsigned int k) const
{
    if (k>=dupTsns_arraysize) throw cRuntimeError("Array of size %d indexed by %d", dupTsns_arraysize, k);
    return dupTsns_var[k];
}

void SCTPSackChunk::setDupTsns(unsigned int k, uint32 dupTsns)
{
    if (k>=dupTsns_arraysize) throw cRuntimeError("Array of size %d indexed by %d", dupTsns_arraysize, k);
    this->dupTsns_var[k] = dupTsns;
}

uint32 SCTPSackChunk::getSackSeqNum() const
{
    return sackSeqNum_var;
}

void SCTPSackChunk::setSackSeqNum(uint32 sackSeqNum)
{
    this->sackSeqNum_var = sackSeqNum;
}

class SCTPSackChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPSackChunkDescriptor();
    virtual ~SCTPSackChunkDescriptor();

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

Register_ClassDescriptor(SCTPSackChunkDescriptor);

SCTPSackChunkDescriptor::SCTPSackChunkDescriptor() : cClassDescriptor("SCTPSackChunk", "SCTPChunk")
{
}

SCTPSackChunkDescriptor::~SCTPSackChunkDescriptor()
{
}

bool SCTPSackChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPSackChunk *>(obj)!=NULL;
}

const char *SCTPSackChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPSackChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int SCTPSackChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *SCTPSackChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "cumTsnAck",
        "a_rwnd",
        "numGaps",
        "numDupTsns",
        "gapStart",
        "gapStop",
        "dupTsns",
        "sackSeqNum",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int SCTPSackChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cumTsnAck")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a_rwnd")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "numGaps")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numDupTsns")==0) return base+3;
    if (fieldName[0]=='g' && strcmp(fieldName, "gapStart")==0) return base+4;
    if (fieldName[0]=='g' && strcmp(fieldName, "gapStop")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "dupTsns")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sackSeqNum")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPSackChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
        "uint16",
        "uint16",
        "uint32",
        "uint32",
        "uint32",
        "uint32",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPSackChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPSackChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        case 4: return pp->getGapStartArraySize();
        case 5: return pp->getGapStopArraySize();
        case 6: return pp->getDupTsnsArraySize();
        default: return 0;
    }
}

std::string SCTPSackChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCumTsnAck());
        case 1: return ulong2string(pp->getA_rwnd());
        case 2: return ulong2string(pp->getNumGaps());
        case 3: return ulong2string(pp->getNumDupTsns());
        case 4: return ulong2string(pp->getGapStart(i));
        case 5: return ulong2string(pp->getGapStop(i));
        case 6: return ulong2string(pp->getDupTsns(i));
        case 7: return ulong2string(pp->getSackSeqNum());
        default: return "";
    }
}

bool SCTPSackChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setCumTsnAck(string2ulong(value)); return true;
        case 1: pp->setA_rwnd(string2ulong(value)); return true;
        case 2: pp->setNumGaps(string2ulong(value)); return true;
        case 3: pp->setNumDupTsns(string2ulong(value)); return true;
        case 4: pp->setGapStart(i,string2ulong(value)); return true;
        case 5: pp->setGapStop(i,string2ulong(value)); return true;
        case 6: pp->setDupTsns(i,string2ulong(value)); return true;
        case 7: pp->setSackSeqNum(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPSackChunkDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *SCTPSackChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPAbortChunk);

SCTPAbortChunk::SCTPAbortChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->T_Bit_var = 0;
}

SCTPAbortChunk::SCTPAbortChunk(const SCTPAbortChunk& other) : SCTPChunk(other)
{
    copy(other);
}

SCTPAbortChunk::~SCTPAbortChunk()
{
}

SCTPAbortChunk& SCTPAbortChunk::operator=(const SCTPAbortChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPAbortChunk::copy(const SCTPAbortChunk& other)
{
    this->T_Bit_var = other.T_Bit_var;
}

void SCTPAbortChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->T_Bit_var);
}

void SCTPAbortChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->T_Bit_var);
}

bool SCTPAbortChunk::getT_Bit() const
{
    return T_Bit_var;
}

void SCTPAbortChunk::setT_Bit(bool T_Bit)
{
    this->T_Bit_var = T_Bit;
}

class SCTPAbortChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPAbortChunkDescriptor();
    virtual ~SCTPAbortChunkDescriptor();

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

Register_ClassDescriptor(SCTPAbortChunkDescriptor);

SCTPAbortChunkDescriptor::SCTPAbortChunkDescriptor() : cClassDescriptor("SCTPAbortChunk", "SCTPChunk")
{
}

SCTPAbortChunkDescriptor::~SCTPAbortChunkDescriptor()
{
}

bool SCTPAbortChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPAbortChunk *>(obj)!=NULL;
}

const char *SCTPAbortChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPAbortChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int SCTPAbortChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *SCTPAbortChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "T_Bit",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int SCTPAbortChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='T' && strcmp(fieldName, "T_Bit")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPAbortChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPAbortChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPAbortChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPAbortChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getT_Bit());
        default: return "";
    }
}

bool SCTPAbortChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setT_Bit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPAbortChunkDescriptor::getFieldStructName(void *object, int field) const
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

void *SCTPAbortChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPHeartbeatChunk);

SCTPHeartbeatChunk::SCTPHeartbeatChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->timeField_var = 0;
    info_arraysize = 0;
    this->info_var = 0;
}

SCTPHeartbeatChunk::SCTPHeartbeatChunk(const SCTPHeartbeatChunk& other) : SCTPChunk(other)
{
    info_arraysize = 0;
    this->info_var = 0;
    copy(other);
}

SCTPHeartbeatChunk::~SCTPHeartbeatChunk()
{
    delete [] info_var;
}

SCTPHeartbeatChunk& SCTPHeartbeatChunk::operator=(const SCTPHeartbeatChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPHeartbeatChunk::copy(const SCTPHeartbeatChunk& other)
{
    this->remoteAddr_var = other.remoteAddr_var;
    this->timeField_var = other.timeField_var;
    delete [] this->info_var;
    this->info_var = (other.info_arraysize==0) ? NULL : new char[other.info_arraysize];
    info_arraysize = other.info_arraysize;
    for (unsigned int i=0; i<info_arraysize; i++)
        this->info_var[i] = other.info_var[i];
}

void SCTPHeartbeatChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->remoteAddr_var);
    doPacking(b,this->timeField_var);
    b->pack(info_arraysize);
    doPacking(b,this->info_var,info_arraysize);
}

void SCTPHeartbeatChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->remoteAddr_var);
    doUnpacking(b,this->timeField_var);
    delete [] this->info_var;
    b->unpack(info_arraysize);
    if (info_arraysize==0) {
        this->info_var = 0;
    } else {
        this->info_var = new char[info_arraysize];
        doUnpacking(b,this->info_var,info_arraysize);
    }
}

IPvXAddress& SCTPHeartbeatChunk::getRemoteAddr()
{
    return remoteAddr_var;
}

void SCTPHeartbeatChunk::setRemoteAddr(const IPvXAddress& remoteAddr)
{
    this->remoteAddr_var = remoteAddr;
}

simtime_t SCTPHeartbeatChunk::getTimeField() const
{
    return timeField_var;
}

void SCTPHeartbeatChunk::setTimeField(simtime_t timeField)
{
    this->timeField_var = timeField;
}

void SCTPHeartbeatChunk::setInfoArraySize(unsigned int size)
{
    char *info_var2 = (size==0) ? NULL : new char[size];
    unsigned int sz = info_arraysize < size ? info_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        info_var2[i] = this->info_var[i];
    for (unsigned int i=sz; i<size; i++)
        info_var2[i] = 0;
    info_arraysize = size;
    delete [] this->info_var;
    this->info_var = info_var2;
}

unsigned int SCTPHeartbeatChunk::getInfoArraySize() const
{
    return info_arraysize;
}

char SCTPHeartbeatChunk::getInfo(unsigned int k) const
{
    if (k>=info_arraysize) throw cRuntimeError("Array of size %d indexed by %d", info_arraysize, k);
    return info_var[k];
}

void SCTPHeartbeatChunk::setInfo(unsigned int k, char info)
{
    if (k>=info_arraysize) throw cRuntimeError("Array of size %d indexed by %d", info_arraysize, k);
    this->info_var[k] = info;
}

class SCTPHeartbeatChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPHeartbeatChunkDescriptor();
    virtual ~SCTPHeartbeatChunkDescriptor();

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

Register_ClassDescriptor(SCTPHeartbeatChunkDescriptor);

SCTPHeartbeatChunkDescriptor::SCTPHeartbeatChunkDescriptor() : cClassDescriptor("SCTPHeartbeatChunk", "SCTPChunk")
{
}

SCTPHeartbeatChunkDescriptor::~SCTPHeartbeatChunkDescriptor()
{
}

bool SCTPHeartbeatChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPHeartbeatChunk *>(obj)!=NULL;
}

const char *SCTPHeartbeatChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPHeartbeatChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SCTPHeartbeatChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SCTPHeartbeatChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "remoteAddr",
        "timeField",
        "info",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SCTPHeartbeatChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeField")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "info")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPHeartbeatChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPvXAddress",
        "simtime_t",
        "char",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPHeartbeatChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPHeartbeatChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case 2: return pp->getInfoArraySize();
        default: return 0;
    }
}

std::string SCTPHeartbeatChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 1: return double2string(pp->getTimeField());
        case 2: return long2string(pp->getInfo(i));
        default: return "";
    }
}

bool SCTPHeartbeatChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case 1: pp->setTimeField(string2double(value)); return true;
        case 2: pp->setInfo(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPHeartbeatChunkDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPvXAddress",
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *SCTPHeartbeatChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRemoteAddr()); break;
        default: return NULL;
    }
}

Register_Class(SCTPHeartbeatAckChunk);

SCTPHeartbeatAckChunk::SCTPHeartbeatAckChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->timeField_var = 0;
    info_arraysize = 0;
    this->info_var = 0;
}

SCTPHeartbeatAckChunk::SCTPHeartbeatAckChunk(const SCTPHeartbeatAckChunk& other) : SCTPChunk(other)
{
    info_arraysize = 0;
    this->info_var = 0;
    copy(other);
}

SCTPHeartbeatAckChunk::~SCTPHeartbeatAckChunk()
{
    delete [] info_var;
}

SCTPHeartbeatAckChunk& SCTPHeartbeatAckChunk::operator=(const SCTPHeartbeatAckChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPHeartbeatAckChunk::copy(const SCTPHeartbeatAckChunk& other)
{
    this->remoteAddr_var = other.remoteAddr_var;
    this->timeField_var = other.timeField_var;
    delete [] this->info_var;
    this->info_var = (other.info_arraysize==0) ? NULL : new char[other.info_arraysize];
    info_arraysize = other.info_arraysize;
    for (unsigned int i=0; i<info_arraysize; i++)
        this->info_var[i] = other.info_var[i];
}

void SCTPHeartbeatAckChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->remoteAddr_var);
    doPacking(b,this->timeField_var);
    b->pack(info_arraysize);
    doPacking(b,this->info_var,info_arraysize);
}

void SCTPHeartbeatAckChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->remoteAddr_var);
    doUnpacking(b,this->timeField_var);
    delete [] this->info_var;
    b->unpack(info_arraysize);
    if (info_arraysize==0) {
        this->info_var = 0;
    } else {
        this->info_var = new char[info_arraysize];
        doUnpacking(b,this->info_var,info_arraysize);
    }
}

IPvXAddress& SCTPHeartbeatAckChunk::getRemoteAddr()
{
    return remoteAddr_var;
}

void SCTPHeartbeatAckChunk::setRemoteAddr(const IPvXAddress& remoteAddr)
{
    this->remoteAddr_var = remoteAddr;
}

simtime_t SCTPHeartbeatAckChunk::getTimeField() const
{
    return timeField_var;
}

void SCTPHeartbeatAckChunk::setTimeField(simtime_t timeField)
{
    this->timeField_var = timeField;
}

void SCTPHeartbeatAckChunk::setInfoArraySize(unsigned int size)
{
    char *info_var2 = (size==0) ? NULL : new char[size];
    unsigned int sz = info_arraysize < size ? info_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        info_var2[i] = this->info_var[i];
    for (unsigned int i=sz; i<size; i++)
        info_var2[i] = 0;
    info_arraysize = size;
    delete [] this->info_var;
    this->info_var = info_var2;
}

unsigned int SCTPHeartbeatAckChunk::getInfoArraySize() const
{
    return info_arraysize;
}

char SCTPHeartbeatAckChunk::getInfo(unsigned int k) const
{
    if (k>=info_arraysize) throw cRuntimeError("Array of size %d indexed by %d", info_arraysize, k);
    return info_var[k];
}

void SCTPHeartbeatAckChunk::setInfo(unsigned int k, char info)
{
    if (k>=info_arraysize) throw cRuntimeError("Array of size %d indexed by %d", info_arraysize, k);
    this->info_var[k] = info;
}

class SCTPHeartbeatAckChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPHeartbeatAckChunkDescriptor();
    virtual ~SCTPHeartbeatAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPHeartbeatAckChunkDescriptor);

SCTPHeartbeatAckChunkDescriptor::SCTPHeartbeatAckChunkDescriptor() : cClassDescriptor("SCTPHeartbeatAckChunk", "SCTPChunk")
{
}

SCTPHeartbeatAckChunkDescriptor::~SCTPHeartbeatAckChunkDescriptor()
{
}

bool SCTPHeartbeatAckChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPHeartbeatAckChunk *>(obj)!=NULL;
}

const char *SCTPHeartbeatAckChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPHeartbeatAckChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SCTPHeartbeatAckChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SCTPHeartbeatAckChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "remoteAddr",
        "timeField",
        "info",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SCTPHeartbeatAckChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeField")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "info")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPHeartbeatAckChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPvXAddress",
        "simtime_t",
        "char",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPHeartbeatAckChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPHeartbeatAckChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case 2: return pp->getInfoArraySize();
        default: return 0;
    }
}

std::string SCTPHeartbeatAckChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 1: return double2string(pp->getTimeField());
        case 2: return long2string(pp->getInfo(i));
        default: return "";
    }
}

bool SCTPHeartbeatAckChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case 1: pp->setTimeField(string2double(value)); return true;
        case 2: pp->setInfo(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPHeartbeatAckChunkDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPvXAddress",
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *SCTPHeartbeatAckChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRemoteAddr()); break;
        default: return NULL;
    }
}

Register_Class(SCTPShutdownChunk);

SCTPShutdownChunk::SCTPShutdownChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->cumTsnAck_var = 0;
}

SCTPShutdownChunk::SCTPShutdownChunk(const SCTPShutdownChunk& other) : SCTPChunk(other)
{
    copy(other);
}

SCTPShutdownChunk::~SCTPShutdownChunk()
{
}

SCTPShutdownChunk& SCTPShutdownChunk::operator=(const SCTPShutdownChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPShutdownChunk::copy(const SCTPShutdownChunk& other)
{
    this->cumTsnAck_var = other.cumTsnAck_var;
}

void SCTPShutdownChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->cumTsnAck_var);
}

void SCTPShutdownChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->cumTsnAck_var);
}

uint32 SCTPShutdownChunk::getCumTsnAck() const
{
    return cumTsnAck_var;
}

void SCTPShutdownChunk::setCumTsnAck(uint32 cumTsnAck)
{
    this->cumTsnAck_var = cumTsnAck;
}

class SCTPShutdownChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPShutdownChunkDescriptor();
    virtual ~SCTPShutdownChunkDescriptor();

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

Register_ClassDescriptor(SCTPShutdownChunkDescriptor);

SCTPShutdownChunkDescriptor::SCTPShutdownChunkDescriptor() : cClassDescriptor("SCTPShutdownChunk", "SCTPChunk")
{
}

SCTPShutdownChunkDescriptor::~SCTPShutdownChunkDescriptor()
{
}

bool SCTPShutdownChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPShutdownChunk *>(obj)!=NULL;
}

const char *SCTPShutdownChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPShutdownChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int SCTPShutdownChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *SCTPShutdownChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "cumTsnAck",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int SCTPShutdownChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cumTsnAck")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPShutdownChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPShutdownChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPShutdownChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPShutdownChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCumTsnAck());
        default: return "";
    }
}

bool SCTPShutdownChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setCumTsnAck(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPShutdownChunkDescriptor::getFieldStructName(void *object, int field) const
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

void *SCTPShutdownChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPShutdownAckChunk);

SCTPShutdownAckChunk::SCTPShutdownAckChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
}

SCTPShutdownAckChunk::SCTPShutdownAckChunk(const SCTPShutdownAckChunk& other) : SCTPChunk(other)
{
    copy(other);
}

SCTPShutdownAckChunk::~SCTPShutdownAckChunk()
{
}

SCTPShutdownAckChunk& SCTPShutdownAckChunk::operator=(const SCTPShutdownAckChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPShutdownAckChunk::copy(const SCTPShutdownAckChunk& other)
{
}

void SCTPShutdownAckChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
}

void SCTPShutdownAckChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
}

class SCTPShutdownAckChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPShutdownAckChunkDescriptor();
    virtual ~SCTPShutdownAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPShutdownAckChunkDescriptor);

SCTPShutdownAckChunkDescriptor::SCTPShutdownAckChunkDescriptor() : cClassDescriptor("SCTPShutdownAckChunk", "SCTPChunk")
{
}

SCTPShutdownAckChunkDescriptor::~SCTPShutdownAckChunkDescriptor()
{
}

bool SCTPShutdownAckChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPShutdownAckChunk *>(obj)!=NULL;
}

const char *SCTPShutdownAckChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPShutdownAckChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int SCTPShutdownAckChunkDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *SCTPShutdownAckChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int SCTPShutdownAckChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPShutdownAckChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *SCTPShutdownAckChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPShutdownAckChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPShutdownAckChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SCTPShutdownAckChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SCTPShutdownAckChunkDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *SCTPShutdownAckChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SCTPShutdownCompleteChunk);

SCTPShutdownCompleteChunk::SCTPShutdownCompleteChunk(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->TBit_var = 0;
}

SCTPShutdownCompleteChunk::SCTPShutdownCompleteChunk(const SCTPShutdownCompleteChunk& other) : SCTPChunk(other)
{
    copy(other);
}

SCTPShutdownCompleteChunk::~SCTPShutdownCompleteChunk()
{
}

SCTPShutdownCompleteChunk& SCTPShutdownCompleteChunk::operator=(const SCTPShutdownCompleteChunk& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPShutdownCompleteChunk::copy(const SCTPShutdownCompleteChunk& other)
{
    this->TBit_var = other.TBit_var;
}

void SCTPShutdownCompleteChunk::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->TBit_var);
}

void SCTPShutdownCompleteChunk::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->TBit_var);
}

bool SCTPShutdownCompleteChunk::getTBit() const
{
    return TBit_var;
}

void SCTPShutdownCompleteChunk::setTBit(bool TBit)
{
    this->TBit_var = TBit;
}

class SCTPShutdownCompleteChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPShutdownCompleteChunkDescriptor();
    virtual ~SCTPShutdownCompleteChunkDescriptor();

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

Register_ClassDescriptor(SCTPShutdownCompleteChunkDescriptor);

SCTPShutdownCompleteChunkDescriptor::SCTPShutdownCompleteChunkDescriptor() : cClassDescriptor("SCTPShutdownCompleteChunk", "SCTPChunk")
{
}

SCTPShutdownCompleteChunkDescriptor::~SCTPShutdownCompleteChunkDescriptor()
{
}

bool SCTPShutdownCompleteChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPShutdownCompleteChunk *>(obj)!=NULL;
}

const char *SCTPShutdownCompleteChunkDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPShutdownCompleteChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int SCTPShutdownCompleteChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *SCTPShutdownCompleteChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "TBit",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int SCTPShutdownCompleteChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='T' && strcmp(fieldName, "TBit")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPShutdownCompleteChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPShutdownCompleteChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPShutdownCompleteChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPShutdownCompleteChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getTBit());
        default: return "";
    }
}

bool SCTPShutdownCompleteChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setTBit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPShutdownCompleteChunkDescriptor::getFieldStructName(void *object, int field) const
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

void *SCTPShutdownCompleteChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

SCTPErrorChunk_Base::SCTPErrorChunk_Base(const char *name, int kind) : SCTPChunk(name,kind)
{
    this->TBit_var = 0;
    this->MBit_var = 0;
}

SCTPErrorChunk_Base::SCTPErrorChunk_Base(const SCTPErrorChunk_Base& other) : SCTPChunk(other)
{
    copy(other);
}

SCTPErrorChunk_Base::~SCTPErrorChunk_Base()
{
}

SCTPErrorChunk_Base& SCTPErrorChunk_Base::operator=(const SCTPErrorChunk_Base& other)
{
    if (this==&other) return *this;
    SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPErrorChunk_Base::copy(const SCTPErrorChunk_Base& other)
{
    this->TBit_var = other.TBit_var;
    this->MBit_var = other.MBit_var;
}

void SCTPErrorChunk_Base::parsimPack(cCommBuffer *b)
{
    SCTPChunk::parsimPack(b);
    doPacking(b,this->TBit_var);
    doPacking(b,this->MBit_var);
    // field parameters is abstract -- please do packing in customized class
}

void SCTPErrorChunk_Base::parsimUnpack(cCommBuffer *b)
{
    SCTPChunk::parsimUnpack(b);
    doUnpacking(b,this->TBit_var);
    doUnpacking(b,this->MBit_var);
    // field parameters is abstract -- please do unpacking in customized class
}

bool SCTPErrorChunk_Base::getTBit() const
{
    return TBit_var;
}

void SCTPErrorChunk_Base::setTBit(bool TBit)
{
    this->TBit_var = TBit;
}

bool SCTPErrorChunk_Base::getMBit() const
{
    return MBit_var;
}

void SCTPErrorChunk_Base::setMBit(bool MBit)
{
    this->MBit_var = MBit;
}

class SCTPErrorChunkDescriptor : public cClassDescriptor
{
  public:
    SCTPErrorChunkDescriptor();
    virtual ~SCTPErrorChunkDescriptor();

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

Register_ClassDescriptor(SCTPErrorChunkDescriptor);

SCTPErrorChunkDescriptor::SCTPErrorChunkDescriptor() : cClassDescriptor("SCTPErrorChunk", "SCTPChunk")
{
}

SCTPErrorChunkDescriptor::~SCTPErrorChunkDescriptor()
{
}

bool SCTPErrorChunkDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPErrorChunk_Base *>(obj)!=NULL;
}

const char *SCTPErrorChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPErrorChunkDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SCTPErrorChunkDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *SCTPErrorChunkDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "TBit",
        "MBit",
        "parameters",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SCTPErrorChunkDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='T' && strcmp(fieldName, "TBit")==0) return base+0;
    if (fieldName[0]=='M' && strcmp(fieldName, "MBit")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameters")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPErrorChunkDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "cPacketPtr",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPErrorChunkDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPErrorChunkDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case 2: return pp->getParametersArraySize();
        default: return 0;
    }
}

std::string SCTPErrorChunkDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getTBit());
        case 1: return bool2string(pp->getMBit());
        case 2: {std::stringstream out; out << pp->getParameters(i); return out.str();}
        default: return "";
    }
}

bool SCTPErrorChunkDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setTBit(string2bool(value)); return true;
        case 1: pp->setMBit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPErrorChunkDescriptor::getFieldStructName(void *object, int field) const
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
        "cPacketPtr",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *SCTPErrorChunkDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getParameters(i)); break;
        default: return NULL;
    }
}

Register_Class(SCTPParameter);

SCTPParameter::SCTPParameter(const char *name, int kind) : cPacket(name,kind)
{
    this->parameterType_var = 0;
}

SCTPParameter::SCTPParameter(const SCTPParameter& other) : cPacket(other)
{
    copy(other);
}

SCTPParameter::~SCTPParameter()
{
}

SCTPParameter& SCTPParameter::operator=(const SCTPParameter& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPParameter::copy(const SCTPParameter& other)
{
    this->parameterType_var = other.parameterType_var;
}

void SCTPParameter::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->parameterType_var);
}

void SCTPParameter::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->parameterType_var);
}

uint16 SCTPParameter::getParameterType() const
{
    return parameterType_var;
}

void SCTPParameter::setParameterType(uint16 parameterType)
{
    this->parameterType_var = parameterType;
}

class SCTPParameterDescriptor : public cClassDescriptor
{
  public:
    SCTPParameterDescriptor();
    virtual ~SCTPParameterDescriptor();

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

Register_ClassDescriptor(SCTPParameterDescriptor);

SCTPParameterDescriptor::SCTPParameterDescriptor() : cClassDescriptor("SCTPParameter", "cPacket")
{
}

SCTPParameterDescriptor::~SCTPParameterDescriptor()
{
}

bool SCTPParameterDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SCTPParameter *>(obj)!=NULL;
}

const char *SCTPParameterDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SCTPParameterDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int SCTPParameterDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *SCTPParameterDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "parameterType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int SCTPParameterDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameterType")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SCTPParameterDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *SCTPParameterDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SCTPParameterDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SCTPParameterDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getParameterType());
        default: return "";
    }
}

bool SCTPParameterDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setParameterType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPParameterDescriptor::getFieldStructName(void *object, int field) const
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

void *SCTPParameterDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


