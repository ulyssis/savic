#
# OMNeT++/OMNEST Makefile for inet
#
# This file was generated with the command:
#  opp_makemake -f
#

# Name of target to be created (-o option)
TARGET = inet$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = ../../../out
PROJECTRELATIVE_PATH = /src/networklayer/ipv4
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/ErrorHandling.o \
    $O/ICMP.o \
    $O/IGMPv2.o \
    $O/IPv4.o \
    $O/IPv4FragBuf.o \
    $O/IPv4InterfaceData.o \
    $O/IPv4Route.o \
    $O/NetworkInfo.o \
    $O/RoutingTable.o \
    $O/RoutingTableParser.o \
    $O/RoutingTableRecorder.o \
    $O/ICMPMessage_m.o \
    $O/IGMPMessage_m.o \
    $O/IPv4Datagram_m.o

# Message files
MSGFILES = \
    ICMPMessage.msg \
    IGMPMessage.msg \
    IPv4Datagram.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f inet inet.exe libinet.so libinet.a libinet.dll libinet.dylib
	-rm -f ./*_m.cc ./*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/ErrorHandling.o: ErrorHandling.cc \
  ./ErrorHandling.h \
  ./ICMPMessage_m.h \
  ./ICMPMessage.h \
  ./IPv4Datagram.h \
  ./IPv4Datagram_m.h
$O/ICMP.o: ICMP.cc \
  ./RoutingTableAccess.h \
  ./ICMP.h \
  ./ICMPMessage_m.h \
  ./IRoutingTable.h \
  ./ICMPMessage.h \
  ./IPv4Datagram.h \
  ./IPv4Route.h \
  ./IPv4Datagram_m.h
$O/ICMPMessage_m.o: ICMPMessage_m.cc \
  ./ICMPMessage_m.h
$O/IGMPMessage_m.o: IGMPMessage_m.cc \
  ./IGMPMessage_m.h
$O/IGMPv2.o: IGMPv2.cc \
  ./RoutingTableAccess.h \
  ./IRoutingTable.h \
  ./IGMPv2.h \
  ./IPv4Route.h \
  ./IPv4InterfaceData.h \
  ./IGMPMessage_m.h
$O/IPv4.o: IPv4.cc \
  ./RoutingTableAccess.h \
  ./ICMP.h \
  ./IRoutingTable.h \
  ./ICMPMessage_m.h \
  ./ICMPMessage.h \
  ./IPv4FragBuf.h \
  ./IPv4Datagram.h \
  ./IPv4.h \
  ./IPv4Route.h \
  ./IPv4Datagram_m.h \
  ./IPv4InterfaceData.h \
  ./ICMPAccess.h
$O/IPv4Datagram_m.o: IPv4Datagram_m.cc \
  ./IPv4Datagram_m.h
$O/IPv4FragBuf.o: IPv4FragBuf.cc \
  ./RoutingTableAccess.h \
  ./ICMP.h \
  ./ICMPMessage_m.h \
  ./IRoutingTable.h \
  ./ICMPMessage.h \
  ./IPv4Datagram.h \
  ./IPv4FragBuf.h \
  ./IPv4Route.h \
  ./IPv4Datagram_m.h
$O/IPv4InterfaceData.o: IPv4InterfaceData.cc \
  ./IPv4InterfaceData.h
$O/IPv4Route.o: IPv4Route.cc \
  ./IRoutingTable.h \
  ./IPv4Route.h \
  ./IPv4InterfaceData.h
$O/NetworkInfo.o: NetworkInfo.cc \
  ./IRoutingTable.h \
  ./IPv4Route.h \
  ./NetworkInfo.h
$O/RoutingTable.o: RoutingTable.cc \
  ./IRoutingTable.h \
  ./IPv4Route.h \
  ./RoutingTable.h \
  ./IPv4InterfaceData.h \
  ./RoutingTableParser.h
$O/RoutingTableParser.o: RoutingTableParser.cc \
  ./IRoutingTable.h \
  ./RoutingTable.h \
  ./IPv4Route.h \
  ./IPv4InterfaceData.h \
  ./RoutingTableParser.h
$O/RoutingTableRecorder.o: RoutingTableRecorder.cc \
  ./IRoutingTable.h \
  ./RoutingTableRecorder.h \
  ./IPv4Route.h \
  ./IPv4InterfaceData.h
