//
// Generated file, do not edit! Created by opp_msgc 4.3 from applications/dhcp/DHCP.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DHCP_m.h"

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
    cEnum *e = cEnum::find("DHCP_OPCODE");
    if (!e) enums.getInstance()->add(e = new cEnum("DHCP_OPCODE"));
    e->insert(BOOTREQUEST, "BOOTREQUEST");
    e->insert(BOOTREPLY, "BOOTREPLY");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("DHCP_TYPE");
    if (!e) enums.getInstance()->add(e = new cEnum("DHCP_TYPE"));
    e->insert(DHCPDISCOVER, "DHCPDISCOVER");
    e->insert(DHCPOFFER, "DHCPOFFER");
    e->insert(DHCPREQUEST, "DHCPREQUEST");
    e->insert(DHCPDECLINE, "DHCPDECLINE");
    e->insert(DHCPACK, "DHCPACK");
    e->insert(DHCPNAK, "DHCPNAK");
    e->insert(DHCPRELEASE, "DHCPRELEASE");
    e->insert(DHCPINFORM, "DHCPINFORM");
    e->insert(DHCPFORCERENEW, "DHCPFORCERENEW");
    e->insert(DHCPLEASEQUERY, "DHCPLEASEQUERY");
    e->insert(DHCPLEASEUNASSIGNED, "DHCPLEASEUNASSIGNED");
    e->insert(DHCPLEASEUNKNOWN, "DHCPLEASEUNKNOWN");
    e->insert(DHCPLEASEACTIVE, "DHCPLEASEACTIVE");
);

Register_Class(DHCPMessage);

DHCPMessage::DHCPMessage(const char *name, int kind) : cPacket(name,kind)
{
    this->op_var = 0;
    this->htype_var = 0;
    this->hlen_var = 0;
    this->hops_var = 0;
    this->xid_var = 0;
    this->secs_var = 0;
    this->flags_var = 0;
    this->sname_var = 0;
    this->file_var = 0;
}

DHCPMessage::DHCPMessage(const DHCPMessage& other) : cPacket(other)
{
    copy(other);
}

DHCPMessage::~DHCPMessage()
{
}

DHCPMessage& DHCPMessage::operator=(const DHCPMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void DHCPMessage::copy(const DHCPMessage& other)
{
    this->op_var = other.op_var;
    this->htype_var = other.htype_var;
    this->hlen_var = other.hlen_var;
    this->hops_var = other.hops_var;
    this->xid_var = other.xid_var;
    this->secs_var = other.secs_var;
    this->flags_var = other.flags_var;
    this->ciaddr_var = other.ciaddr_var;
    this->yiaddr_var = other.yiaddr_var;
    this->giaddr_var = other.giaddr_var;
    this->chaddr_var = other.chaddr_var;
    this->sname_var = other.sname_var;
    this->file_var = other.file_var;
    this->options_var = other.options_var;
}

void DHCPMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->op_var);
    doPacking(b,this->htype_var);
    doPacking(b,this->hlen_var);
    doPacking(b,this->hops_var);
    doPacking(b,this->xid_var);
    doPacking(b,this->secs_var);
    doPacking(b,this->flags_var);
    doPacking(b,this->ciaddr_var);
    doPacking(b,this->yiaddr_var);
    doPacking(b,this->giaddr_var);
    doPacking(b,this->chaddr_var);
    doPacking(b,this->sname_var);
    doPacking(b,this->file_var);
    doPacking(b,this->options_var);
}

void DHCPMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->op_var);
    doUnpacking(b,this->htype_var);
    doUnpacking(b,this->hlen_var);
    doUnpacking(b,this->hops_var);
    doUnpacking(b,this->xid_var);
    doUnpacking(b,this->secs_var);
    doUnpacking(b,this->flags_var);
    doUnpacking(b,this->ciaddr_var);
    doUnpacking(b,this->yiaddr_var);
    doUnpacking(b,this->giaddr_var);
    doUnpacking(b,this->chaddr_var);
    doUnpacking(b,this->sname_var);
    doUnpacking(b,this->file_var);
    doUnpacking(b,this->options_var);
}

int DHCPMessage::getOp() const
{
    return op_var;
}

void DHCPMessage::setOp(int op)
{
    this->op_var = op;
}

int DHCPMessage::getHtype() const
{
    return htype_var;
}

void DHCPMessage::setHtype(int htype)
{
    this->htype_var = htype;
}

int DHCPMessage::getHlen() const
{
    return hlen_var;
}

void DHCPMessage::setHlen(int hlen)
{
    this->hlen_var = hlen;
}

int DHCPMessage::getHops() const
{
    return hops_var;
}

void DHCPMessage::setHops(int hops)
{
    this->hops_var = hops;
}

long DHCPMessage::getXid() const
{
    return xid_var;
}

void DHCPMessage::setXid(long xid)
{
    this->xid_var = xid;
}

int DHCPMessage::getSecs() const
{
    return secs_var;
}

void DHCPMessage::setSecs(int secs)
{
    this->secs_var = secs;
}

long DHCPMessage::getFlags() const
{
    return flags_var;
}

void DHCPMessage::setFlags(long flags)
{
    this->flags_var = flags;
}

IPv4Address& DHCPMessage::getCiaddr()
{
    return ciaddr_var;
}

void DHCPMessage::setCiaddr(const IPv4Address& ciaddr)
{
    this->ciaddr_var = ciaddr;
}

IPv4Address& DHCPMessage::getYiaddr()
{
    return yiaddr_var;
}

void DHCPMessage::setYiaddr(const IPv4Address& yiaddr)
{
    this->yiaddr_var = yiaddr;
}

IPv4Address& DHCPMessage::getGiaddr()
{
    return giaddr_var;
}

void DHCPMessage::setGiaddr(const IPv4Address& giaddr)
{
    this->giaddr_var = giaddr;
}

MACAddress& DHCPMessage::getChaddr()
{
    return chaddr_var;
}

void DHCPMessage::setChaddr(const MACAddress& chaddr)
{
    this->chaddr_var = chaddr;
}

const char * DHCPMessage::getSname() const
{
    return sname_var.c_str();
}

void DHCPMessage::setSname(const char * sname)
{
    this->sname_var = sname;
}

const char * DHCPMessage::getFile() const
{
    return file_var.c_str();
}

void DHCPMessage::setFile(const char * file)
{
    this->file_var = file;
}

DHCPOption& DHCPMessage::getOptions()
{
    return options_var;
}

void DHCPMessage::setOptions(const DHCPOption& options)
{
    this->options_var = options;
}

class DHCPMessageDescriptor : public cClassDescriptor
{
  public:
    DHCPMessageDescriptor();
    virtual ~DHCPMessageDescriptor();

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

Register_ClassDescriptor(DHCPMessageDescriptor);

DHCPMessageDescriptor::DHCPMessageDescriptor() : cClassDescriptor("DHCPMessage", "cPacket")
{
}

DHCPMessageDescriptor::~DHCPMessageDescriptor()
{
}

bool DHCPMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DHCPMessage *>(obj)!=NULL;
}

const char *DHCPMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DHCPMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount(object) : 14;
}

unsigned int DHCPMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<14) ? fieldTypeFlags[field] : 0;
}

const char *DHCPMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "op",
        "htype",
        "hlen",
        "hops",
        "xid",
        "secs",
        "flags",
        "ciaddr",
        "yiaddr",
        "giaddr",
        "chaddr",
        "sname",
        "file",
        "options",
    };
    return (field>=0 && field<14) ? fieldNames[field] : NULL;
}

int DHCPMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "op")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "htype")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hlen")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hops")==0) return base+3;
    if (fieldName[0]=='x' && strcmp(fieldName, "xid")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "secs")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "flags")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "ciaddr")==0) return base+7;
    if (fieldName[0]=='y' && strcmp(fieldName, "yiaddr")==0) return base+8;
    if (fieldName[0]=='g' && strcmp(fieldName, "giaddr")==0) return base+9;
    if (fieldName[0]=='c' && strcmp(fieldName, "chaddr")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "sname")==0) return base+11;
    if (fieldName[0]=='f' && strcmp(fieldName, "file")==0) return base+12;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+13;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DHCPMessageDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "long",
        "int",
        "long",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "MACAddress",
        "string",
        "string",
        "DHCPOption",
    };
    return (field>=0 && field<14) ? fieldTypeStrings[field] : NULL;
}

const char *DHCPMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int DHCPMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DHCPMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getOp());
        case 1: return long2string(pp->getHtype());
        case 2: return long2string(pp->getHlen());
        case 3: return long2string(pp->getHops());
        case 4: return long2string(pp->getXid());
        case 5: return long2string(pp->getSecs());
        case 6: return long2string(pp->getFlags());
        case 7: {std::stringstream out; out << pp->getCiaddr(); return out.str();}
        case 8: {std::stringstream out; out << pp->getYiaddr(); return out.str();}
        case 9: {std::stringstream out; out << pp->getGiaddr(); return out.str();}
        case 10: {std::stringstream out; out << pp->getChaddr(); return out.str();}
        case 11: return oppstring2string(pp->getSname());
        case 12: return oppstring2string(pp->getFile());
        case 13: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool DHCPMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setOp(string2long(value)); return true;
        case 1: pp->setHtype(string2long(value)); return true;
        case 2: pp->setHlen(string2long(value)); return true;
        case 3: pp->setHops(string2long(value)); return true;
        case 4: pp->setXid(string2long(value)); return true;
        case 5: pp->setSecs(string2long(value)); return true;
        case 6: pp->setFlags(string2long(value)); return true;
        case 11: pp->setSname((value)); return true;
        case 12: pp->setFile((value)); return true;
        default: return false;
    }
}

const char *DHCPMessageDescriptor::getFieldStructName(void *object, int field) const
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
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "MACAddress",
        NULL,
        NULL,
        "DHCPOption",
    };
    return (field>=0 && field<14) ? fieldStructNames[field] : NULL;
}

void *DHCPMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getCiaddr()); break;
        case 8: return (void *)(&pp->getYiaddr()); break;
        case 9: return (void *)(&pp->getGiaddr()); break;
        case 10: return (void *)(&pp->getChaddr()); break;
        case 13: return (void *)(&pp->getOptions()); break;
        default: return NULL;
    }
}


