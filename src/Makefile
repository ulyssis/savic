#
# OMNeT++/OMNEST Makefile for libinet
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -o inet -O out -pINET -Xapplications/voiptool -Xtransport/tcp_lwip -Xtransport/tcp_nsc -DWITH_TCP_COMMON -DWITH_TCP_INET -DWITH_IPv4 -DWITH_IPv6 -DWITH_xMIPv6 -DWITH_UDP -DWITH_RTP -DWITH_SCTP -DWITH_DHCP -DWITH_ETHERNET -DWITH_PPP -DWITH_EXT_IF -DWITH_MPLS -DWITH_OSPFv2 -DWITH_BGPv4 -DWITH_TRACI -DWITH_MANET
#

# Name of target to be created (-o option)
TARGET = libinet$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -IEigen \
    -IEigen/src \
    -IEigen/src/Cholesky \
    -IEigen/src/CholmodSupport \
    -IEigen/src/Core \
    -IEigen/src/Core/arch \
    -IEigen/src/Core/arch/AltiVec \
    -IEigen/src/Core/arch/Default \
    -IEigen/src/Core/arch/NEON \
    -IEigen/src/Core/arch/SSE \
    -IEigen/src/Core/products \
    -IEigen/src/Core/util \
    -IEigen/src/Eigen2Support \
    -IEigen/src/Eigen2Support/Geometry \
    -IEigen/src/Eigenvalues \
    -IEigen/src/Geometry \
    -IEigen/src/Geometry/arch \
    -IEigen/src/Householder \
    -IEigen/src/IterativeLinearSolvers \
    -IEigen/src/Jacobi \
    -IEigen/src/LU \
    -IEigen/src/LU/arch \
    -IEigen/src/OrderingMethods \
    -IEigen/src/PaStiXSupport \
    -IEigen/src/PardisoSupport \
    -IEigen/src/QR \
    -IEigen/src/SVD \
    -IEigen/src/SparseCholesky \
    -IEigen/src/SparseCore \
    -IEigen/src/StlSupport \
    -IEigen/src/SuperLUSupport \
    -IEigen/src/UmfPackSupport \
    -IEigen/src/misc \
    -IEigen/src/plugins \
    -Iapplications \
    -Iapplications/dhcp \
    -Iapplications/ethernet \
    -Iapplications/generic \
    -Iapplications/httptools \
    -Iapplications/pingapp \
    -Iapplications/rtpapp \
    -Iapplications/sctpapp \
    -Iapplications/tcpapp \
    -Iapplications/traci \
    -Iapplications/udpapp \
    -Ibase \
    -Ibattery \
    -Ibattery/models \
    -Ilinklayer \
    -Ilinklayer/contract \
    -Ilinklayer/ethernet \
    -Ilinklayer/ethernet/switch \
    -Ilinklayer/ext \
    -Ilinklayer/ieee80211 \
    -Ilinklayer/ieee80211/mac \
    -Ilinklayer/ieee80211/mgmt \
    -Ilinklayer/ieee80211/radio \
    -Ilinklayer/ieee80211/radio/errormodel \
    -Ilinklayer/ppp \
    -Ilinklayer/queue \
    -Ilinklayer/radio \
    -Ilinklayer/radio/propagation \
    -Imobility \
    -Imobility/models \
    -Inetworklayer \
    -Inetworklayer/arp \
    -Inetworklayer/autorouting \
    -Inetworklayer/autorouting/ipv4 \
    -Inetworklayer/autorouting/ipv6 \
    -Inetworklayer/bgpv4 \
    -Inetworklayer/bgpv4/BGPMessage \
    -Inetworklayer/common \
    -Inetworklayer/contract \
    -Inetworklayer/diffserv \
    -Inetworklayer/extras \
    -Inetworklayer/icmpv6 \
    -Inetworklayer/ipv4 \
    -Inetworklayer/ipv6 \
    -Inetworklayer/ipv6tunneling \
    -Inetworklayer/ldp \
    -Inetworklayer/manetrouting \
    -Inetworklayer/manetrouting/GPS \
    -Inetworklayer/manetrouting/VCap \
    -Inetworklayer/manetrouting/aodv \
    -Inetworklayer/manetrouting/aodv/aodv-uu \
    -Inetworklayer/manetrouting/base \
    -Inetworklayer/manetrouting/batman \
    -Inetworklayer/manetrouting/berger \
    -Inetworklayer/manetrouting/dsdv \
    -Inetworklayer/manetrouting/dsr \
    -Inetworklayer/manetrouting/dsr/dsr-uu \
    -Inetworklayer/manetrouting/dymo \
    -Inetworklayer/manetrouting/dymo/dymoum \
    -Inetworklayer/manetrouting/dymo_fau \
    -Inetworklayer/manetrouting/olsr \
    -Inetworklayer/manetrouting/search \
    -Inetworklayer/mpls \
    -Inetworklayer/ospfv2 \
    -Inetworklayer/ospfv2/interface \
    -Inetworklayer/ospfv2/messagehandler \
    -Inetworklayer/ospfv2/neighbor \
    -Inetworklayer/ospfv2/router \
    -Inetworklayer/rsvp_te \
    -Inetworklayer/ted \
    -Inetworklayer/xmipv6 \
    -Inodes \
    -Inodes/bgp \
    -Inodes/ethernet \
    -Inodes/httptools \
    -Inodes/inet \
    -Inodes/ipv6 \
    -Inodes/mpls \
    -Inodes/ospfv2 \
    -Inodes/wireless \
    -Inodes/xmipv6 \
    -Itransport \
    -Itransport/contract \
    -Itransport/rtp \
    -Itransport/rtp/profiles \
    -Itransport/rtp/profiles/avprofile \
    -Itransport/sctp \
    -Itransport/tcp \
    -Itransport/tcp/flavours \
    -Itransport/tcp/queues \
    -Itransport/tcp_common \
    -Itransport/udp \
    -Iutil \
    -Iutil/headerserializers \
    -Iutil/headerserializers/headers \
    -Iutil/headerserializers/ipv4 \
    -Iutil/headerserializers/ipv4/headers \
    -Iutil/headerserializers/sctp \
    -Iutil/headerserializers/sctp/headers \
    -Iutil/headerserializers/tcp \
    -Iutil/headerserializers/tcp/headers \
    -Iutil/headerserializers/udp \
    -Iutil/headerserializers/udp/headers \
    -Iworld \
    -Iworld/annotations \
    -Iworld/httptools \
    -Iworld/obstacles \
    -Iworld/powercontrol \
    -Iworld/radio \
    -Iworld/scenario \
    -Iworld/traci

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/applications/dhcp/DHCPClient.o \
    $O/applications/dhcp/DHCPServer.o \
    $O/applications/ethernet/EtherAppSrv.o \
    $O/applications/ethernet/EtherTrafGen.o \
    $O/applications/ethernet/EtherAppCli.o \
    $O/applications/generic/IPvXTrafSink.o \
    $O/applications/generic/IPvXTrafGen.o \
    $O/applications/httptools/HttpServerBase.o \
    $O/applications/httptools/HttpServerDirect.o \
    $O/applications/httptools/HttpBrowser.o \
    $O/applications/httptools/HttpBrowserDirect.o \
    $O/applications/httptools/HttpServerEvilA.o \
    $O/applications/httptools/HttpServerDirectEvilB.o \
    $O/applications/httptools/HttpUtils.o \
    $O/applications/httptools/HttpServer.o \
    $O/applications/httptools/HttpBrowserBase.o \
    $O/applications/httptools/HttpRandom.o \
    $O/applications/httptools/HttpNodeBase.o \
    $O/applications/httptools/HttpServerDirectEvilA.o \
    $O/applications/httptools/HttpServerEvilB.o \
    $O/applications/pingapp/PingTestApp.o \
    $O/applications/pingapp/PingApp.o \
    $O/applications/rtpapp/RTPApplication.o \
    $O/applications/sctpapp/SCTPPeer.o \
    $O/applications/sctpapp/SCTPClient.o \
    $O/applications/sctpapp/SCTPServer.o \
    $O/applications/tcpapp/TCPSessionApp.o \
    $O/applications/tcpapp/TCPSrvHostApp.o \
    $O/applications/tcpapp/TCPBasicClientApp.o \
    $O/applications/tcpapp/TCPGenericSrvApp.o \
    $O/applications/tcpapp/TelnetApp.o \
    $O/applications/tcpapp/TCPGenericCliAppBase.o \
    $O/applications/tcpapp/TCPGenericSrvThread.o \
    $O/applications/tcpapp/TCPSinkApp.o \
    $O/applications/tcpapp/TCPEchoApp.o \
    $O/applications/traci/TraCITestApp.o \
    $O/applications/traci/TraCIDemo.o \
    $O/applications/udpapp/UDPBasicApp.o \
    $O/applications/udpapp/UDPBasicBurst.o \
    $O/applications/udpapp/UDPSink.o \
    $O/applications/udpapp/UDPVideoStreamCli.o \
    $O/applications/udpapp/UDPEchoApp.o \
    $O/applications/udpapp/UDPVideoStreamSvr.o \
    $O/base/BasicModule.o \
    $O/base/ProtocolMap.o \
    $O/base/ByteArrayMessage.o \
    $O/base/UnimplementedModule.o \
    $O/base/NedFunctions.o \
    $O/base/PassiveQueueBase.o \
    $O/base/AbstractQueue.o \
    $O/base/ResultFilters.o \
    $O/base/WeightedTopology.o \
    $O/base/QueueWithQoS.o \
    $O/base/Join.o \
    $O/base/ModuleAccess.o \
    $O/base/erfc.o \
    $O/base/Topology.o \
    $O/base/NotifierConsts.o \
    $O/base/Coord.o \
    $O/base/Sink.o \
    $O/base/QueueBase.o \
    $O/base/NotificationBoard.o \
    $O/base/ByteArrayBuffer.o \
    $O/base/ReassemblyBuffer.o \
    $O/base/ByteArray.o \
    $O/battery/models/BasicBattery.o \
    $O/battery/models/InetSimpleBattery.o \
    $O/linklayer/contract/MACAddress.o \
    $O/linklayer/ethernet/EtherHub.o \
    $O/linklayer/ethernet/EtherMACFullDuplex.o \
    $O/linklayer/ethernet/EtherEncap.o \
    $O/linklayer/ethernet/EtherBus.o \
    $O/linklayer/ethernet/EtherMACBase.o \
    $O/linklayer/ethernet/EtherLLC.o \
    $O/linklayer/ethernet/EtherFrameClassifier.o \
    $O/linklayer/ethernet/EtherMAC.o \
    $O/linklayer/ethernet/switch/MACRelayUnitPP.o \
    $O/linklayer/ethernet/switch/MACRelayUnitNP.o \
    $O/linklayer/ethernet/switch/MACRelayUnitBase.o \
    $O/linklayer/ext/cSocketRTScheduler.o \
    $O/linklayer/ext/ExtInterface.o \
    $O/linklayer/ieee80211/mac/Ieee80211eClassifier.o \
    $O/linklayer/ieee80211/mac/Ieee80211Mac.o \
    $O/linklayer/ieee80211/mac/WifiMode.o \
    $O/linklayer/ieee80211/mac/WirelessMacBase.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211Etx.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAdhocWithEtx.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAPSimplified.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtBase.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAP.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtSTA.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtSTASimplified.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211AgentSTA.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.o \
    $O/linklayer/ieee80211/radio/Ieee80211RadioModel.o \
    $O/linklayer/ieee80211/radio/BerParseFile.o \
    $O/linklayer/ieee80211/radio/errormodel/yans-error-rate-model.o \
    $O/linklayer/ieee80211/radio/errormodel/nist-error-rate-model.o \
    $O/linklayer/ieee80211/radio/errormodel/dsss-error-rate-model.o \
    $O/linklayer/ppp/PPP.o \
    $O/linklayer/queue/AlgorithmicDropperBase.o \
    $O/linklayer/queue/SchedulerBase.o \
    $O/linklayer/queue/PriorityScheduler.o \
    $O/linklayer/queue/ThresholdDropper.o \
    $O/linklayer/queue/REDDropper.o \
    $O/linklayer/queue/WRRScheduler.o \
    $O/linklayer/queue/DropTailQueue.o \
    $O/linklayer/queue/FIFOQueue.o \
    $O/linklayer/radio/Modulation.o \
    $O/linklayer/radio/Radio.o \
    $O/linklayer/radio/GenericRadioModel.o \
    $O/linklayer/radio/propagation/NakagamiModel.o \
    $O/linklayer/radio/propagation/RiceModel.o \
    $O/linklayer/radio/propagation/LogNormalShadowingModel.o \
    $O/linklayer/radio/propagation/FreeSpaceModel.o \
    $O/linklayer/radio/propagation/TwoRayGroundModel.o \
    $O/linklayer/radio/propagation/RayleighModel.o \
    $O/mobility/models/LinearMobility.o \
    $O/mobility/models/TractorMobility.o \
    $O/mobility/models/MovingMobilityBase.o \
    $O/mobility/models/PostureTransition.o \
    $O/mobility/models/StaticGridMobility.o \
    $O/mobility/models/TurtleMobility.o \
    $O/mobility/models/ANSimMobility.o \
    $O/mobility/models/ConstSpeedMobility.o \
    $O/mobility/models/RectangleMobility.o \
    $O/mobility/models/Ns2MotionMobility.o \
    $O/mobility/models/MoBANCoordinator.o \
    $O/mobility/models/BonnMotionMobility.o \
    $O/mobility/models/LinearNodeDistributionMobility.o \
    $O/mobility/models/RandomWPMobility.o \
    $O/mobility/models/MobilityAccess.o \
    $O/mobility/models/ChiangMobility.o \
    $O/mobility/models/BonnMotionFileCache.o \
    $O/mobility/models/MassMobility.o \
    $O/mobility/models/StationaryMobility.o \
    $O/mobility/models/MobilityBase.o \
    $O/mobility/models/GaussMarkovMobility.o \
    $O/mobility/models/TraCIMobility.o \
    $O/mobility/models/Posture.o \
    $O/mobility/models/MoBANLocal.o \
    $O/mobility/models/LineSegmentsMobilityBase.o \
    $O/mobility/models/CircleMobility.o \
    $O/networklayer/arp/ARP.o \
    $O/networklayer/autorouting/ipv4/IPv4NetworkConfigurator.o \
    $O/networklayer/autorouting/ipv4/HostAutoConfigurator.o \
    $O/networklayer/autorouting/ipv4/FlatNetworkConfigurator.o \
    $O/networklayer/autorouting/ipv6/FlatNetworkConfigurator6.o \
    $O/networklayer/bgpv4/BGPRouting.o \
    $O/networklayer/bgpv4/BGPFSM.o \
    $O/networklayer/bgpv4/BGPSession.o \
    $O/networklayer/bgpv4/BGPMessage/BGPUpdate.o \
    $O/networklayer/common/InterfaceTable.o \
    $O/networklayer/common/InterfaceEntry.o \
    $O/networklayer/contract/IPv6ControlInfo.o \
    $O/networklayer/contract/IPv4Address.o \
    $O/networklayer/contract/IPvXAddressResolver.o \
    $O/networklayer/contract/IPvXAddress.o \
    $O/networklayer/contract/IPv4ControlInfo.o \
    $O/networklayer/contract/IPv6Address.o \
    $O/networklayer/diffserv/BehaviorAggregateClassifier.o \
    $O/networklayer/diffserv/TwoRateThreeColorMeter.o \
    $O/networklayer/diffserv/MultiFieldClassifier.o \
    $O/networklayer/diffserv/DiffservUtil.o \
    $O/networklayer/diffserv/TokenBucketMeter.o \
    $O/networklayer/diffserv/SingleRateThreeColorMeter.o \
    $O/networklayer/diffserv/DSCPMarker.o \
    $O/networklayer/extras/Dummy.o \
    $O/networklayer/extras/FailureManager.o \
    $O/networklayer/icmpv6/IPv6NeighbourCache.o \
    $O/networklayer/icmpv6/ICMPv6.o \
    $O/networklayer/icmpv6/IPv6NeighbourDiscovery.o \
    $O/networklayer/ipv4/NetworkInfo.o \
    $O/networklayer/ipv4/IPv4FragBuf.o \
    $O/networklayer/ipv4/IGMPv2.o \
    $O/networklayer/ipv4/ICMP.o \
    $O/networklayer/ipv4/ErrorHandling.o \
    $O/networklayer/ipv4/RoutingTable.o \
    $O/networklayer/ipv4/RoutingTableParser.o \
    $O/networklayer/ipv4/IPv4.o \
    $O/networklayer/ipv4/IPv4InterfaceData.o \
    $O/networklayer/ipv4/IPv4Route.o \
    $O/networklayer/ipv4/RoutingTableRecorder.o \
    $O/networklayer/ipv6/IPv6FragBuf.o \
    $O/networklayer/ipv6/IPv6InterfaceData.o \
    $O/networklayer/ipv6/IPv6.o \
    $O/networklayer/ipv6/IPv6Datagram.o \
    $O/networklayer/ipv6/IPv6ErrorHandling.o \
    $O/networklayer/ipv6/IPv6ExtensionHeaders.o \
    $O/networklayer/ipv6/RoutingTable6.o \
    $O/networklayer/ipv6tunneling/IPv6Tunneling.o \
    $O/networklayer/ldp/LDP.o \
    $O/networklayer/manetrouting/GPS/GPS.o \
    $O/networklayer/manetrouting/VCap/VNeighborTable.o \
    $O/networklayer/manetrouting/VCap/VCap.o \
    $O/networklayer/manetrouting/aodv/aodv_msg_struct_descriptor.o \
    $O/networklayer/manetrouting/aodv/aodv_uu_omnet.o \
    $O/networklayer/manetrouting/aodv/aodv_msg_struct.o \
    $O/networklayer/manetrouting/aodv/packet_queue_omnet.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/aodv_hello.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/debug_aodv.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/seek_list.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/aodv_socket.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/list.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/locality.o \
    $O/networklayer/manetrouting/aodv/aodv-uu/routing_table.o \
    $O/networklayer/manetrouting/base/ManetRoutingBase.o \
    $O/networklayer/manetrouting/batman/batmanHna.o \
    $O/networklayer/manetrouting/batman/BatmanMain.o \
    $O/networklayer/manetrouting/batman/BatmanData.o \
    $O/networklayer/manetrouting/berger/berger.o \
    $O/networklayer/manetrouting/berger/BergerNeighborInfo.o \
    $O/networklayer/manetrouting/dsdv/DSDV_2.o \
    $O/networklayer/manetrouting/dsr/dsr-pkt_omnet.o \
    $O/networklayer/manetrouting/dsr/dsr-uu-omnetpp.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/dsr-opt.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/path-cache.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/send-buf.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/dsr-io.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/dsr-ack.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/maint-buf.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/link-cache.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/dsr-srt.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/neigh.o \
    $O/networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.o \
    $O/networklayer/manetrouting/dymo/dymo_msg_struct.o \
    $O/networklayer/manetrouting/dymo/dymo_um_omnet.o \
    $O/networklayer/manetrouting/dymo/dymo_packet_queue_omnet.o \
    $O/networklayer/manetrouting/dymo/dymoum/rtable.o \
    $O/networklayer/manetrouting/dymo/dymoum/dymo_timeout.o \
    $O/networklayer/manetrouting/dymo/dymoum/dymo_re.o \
    $O/networklayer/manetrouting/dymo/dymoum/dymo_uerr.o \
    $O/networklayer/manetrouting/dymo/dymoum/icmp_socket.o \
    $O/networklayer/manetrouting/dymo/dymoum/dymo_rerr.o \
    $O/networklayer/manetrouting/dymo/dymoum/debug_dymo.o \
    $O/networklayer/manetrouting/dymo/dymoum/dymo_socket.o \
    $O/networklayer/manetrouting/dymo/dymoum/blacklist.o \
    $O/networklayer/manetrouting/dymo/dymoum/dymo_nb.o \
    $O/networklayer/manetrouting/dymo/dymoum/pending_rreq.o \
    $O/networklayer/manetrouting/dymo/dymoum/dymo_generic.o \
    $O/networklayer/manetrouting/dymo/dymoum/timer_queue.o \
    $O/networklayer/manetrouting/dymo/dymoum/dymo_hello.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_RoutingEntry.o \
    $O/networklayer/manetrouting/dymo_fau/InspectorHelpers.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_DataQueue.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_RoutingTable.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_TokenBucket.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_OutstandingRREQList.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_Timer.o \
    $O/networklayer/manetrouting/olsr/OLSR.o \
    $O/networklayer/manetrouting/olsr/OLSR_ETX.o \
    $O/networklayer/manetrouting/olsr/OLSR_ETX_dijkstra.o \
    $O/networklayer/manetrouting/olsr/OLSROPT.o \
    $O/networklayer/manetrouting/olsr/OLSR_ETX_state.o \
    $O/networklayer/manetrouting/olsr/OLSR_rtable.o \
    $O/networklayer/manetrouting/olsr/OLSR_state.o \
    $O/networklayer/manetrouting/search/searNeighborInfo.o \
    $O/networklayer/manetrouting/search/searRouting.o \
    $O/networklayer/mpls/MPLSPacket.o \
    $O/networklayer/mpls/MPLS.o \
    $O/networklayer/mpls/LIBTable.o \
    $O/networklayer/ospfv2/OSPFRouting.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateBackup.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceState.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateDown.o \
    $O/networklayer/ospfv2/interface/OSPFInterface.o \
    $O/networklayer/ospfv2/messagehandler/MessageHandler.o \
    $O/networklayer/ospfv2/messagehandler/HelloHandler.o \
    $O/networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.o \
    $O/networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.o \
    $O/networklayer/ospfv2/messagehandler/LinkStateRequestHandler.o \
    $O/networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborState.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateDown.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateInit.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateFull.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighbor.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.o \
    $O/networklayer/ospfv2/router/ASExternalLSA.o \
    $O/networklayer/ospfv2/router/OSPFArea.o \
    $O/networklayer/ospfv2/router/OSPFRoutingTableEntry.o \
    $O/networklayer/ospfv2/router/NetworkLSA.o \
    $O/networklayer/ospfv2/router/OSPFRouter.o \
    $O/networklayer/ospfv2/router/LSA.o \
    $O/networklayer/ospfv2/router/RouterLSA.o \
    $O/networklayer/ospfv2/router/SummaryLSA.o \
    $O/networklayer/rsvp_te/Utils.o \
    $O/networklayer/rsvp_te/RSVP.o \
    $O/networklayer/rsvp_te/SimpleClassifier.o \
    $O/networklayer/ted/LinkStateRouting.o \
    $O/networklayer/ted/TED.o \
    $O/networklayer/xmipv6/xMIPv6.o \
    $O/networklayer/xmipv6/BindingCache.o \
    $O/networklayer/xmipv6/MobilityHeader.o \
    $O/networklayer/xmipv6/BindingUpdateList.o \
    $O/transport/contract/UDPSocket.o \
    $O/transport/contract/SCTPSocket.o \
    $O/transport/contract/TCPSocket.o \
    $O/transport/contract/TCPSocketMap.o \
    $O/transport/rtp/RTPPacket.o \
    $O/transport/rtp/RTCP.o \
    $O/transport/rtp/RTPPayloadSender.o \
    $O/transport/rtp/RTPParticipantInfo.o \
    $O/transport/rtp/RTCPPacket.o \
    $O/transport/rtp/reports.o \
    $O/transport/rtp/RTPReceiverInfo.o \
    $O/transport/rtp/sdes.o \
    $O/transport/rtp/RTPProfile.o \
    $O/transport/rtp/RTPInnerPacket.o \
    $O/transport/rtp/RTPPayloadReceiver.o \
    $O/transport/rtp/RTPSenderInfo.o \
    $O/transport/rtp/RTP.o \
    $O/transport/rtp/profiles/avprofile/RTPAVProfilePayload32Sender.o \
    $O/transport/rtp/profiles/avprofile/RTPAVProfile.o \
    $O/transport/rtp/profiles/avprofile/RTPAVProfilePayload32Receiver.o \
    $O/transport/sctp/SCTPAlg.o \
    $O/transport/sctp/SCTP.o \
    $O/transport/sctp/SCTPAssociationUtil.o \
    $O/transport/sctp/SCTPReceiveStream.o \
    $O/transport/sctp/SCTPMessage.o \
    $O/transport/sctp/SCTPAssociationBase.o \
    $O/transport/sctp/SCTPAssociationEventProc.o \
    $O/transport/sctp/SCTPAssociationRcvMessage.o \
    $O/transport/sctp/SCTPSendStream.o \
    $O/transport/sctp/SCTPCCFunctions.o \
    $O/transport/sctp/SCTPQueue.o \
    $O/transport/sctp/SCTPSSFunctions.o \
    $O/transport/sctp/SCTPAssociationSendAll.o \
    $O/transport/tcp/TCPConnectionUtil.o \
    $O/transport/tcp/TCPSACKRexmitQueue.o \
    $O/transport/tcp/TCPConnectionBase.o \
    $O/transport/tcp/TCPConnectionEventProc.o \
    $O/transport/tcp/TCPConnectionSackUtil.o \
    $O/transport/tcp/TCPConnectionRcvSegment.o \
    $O/transport/tcp/TCP.o \
    $O/transport/tcp/flavours/DumbTCP.o \
    $O/transport/tcp/flavours/TCPBaseAlg.o \
    $O/transport/tcp/flavours/TCPReno.o \
    $O/transport/tcp/flavours/TCPNoCongestionControl.o \
    $O/transport/tcp/flavours/TCPTahoeRenoFamily.o \
    $O/transport/tcp/flavours/TCPTahoe.o \
    $O/transport/tcp/flavours/TCPNewReno.o \
    $O/transport/tcp/queues/TCPByteStreamRcvQueue.o \
    $O/transport/tcp/queues/TCPByteStreamSendQueue.o \
    $O/transport/tcp/queues/TCPMsgBasedRcvQueue.o \
    $O/transport/tcp/queues/TCPVirtualDataSendQueue.o \
    $O/transport/tcp/queues/TCPVirtualDataRcvQueue.o \
    $O/transport/tcp/queues/TCPMsgBasedSendQueue.o \
    $O/transport/tcp_common/TCPSegment.o \
    $O/transport/tcp_common/TCPSpoof.o \
    $O/transport/udp/UDP.o \
    $O/util/Delayer.o \
    $O/util/XMLUtils.o \
    $O/util/OrdinalBasedDuplicator.o \
    $O/util/MessageChecker.o \
    $O/util/PcapDump.o \
    $O/util/int128.o \
    $O/util/common.o \
    $O/util/ThruputMeteringChannel.o \
    $O/util/uint128.o \
    $O/util/PacketDump.o \
    $O/util/TCPDump.o \
    $O/util/PcapRecorder.o \
    $O/util/NetAnimTrace.o \
    $O/util/opp_utils.o \
    $O/util/OrdinalBasedDropper.o \
    $O/util/PatternMatcher.o \
    $O/util/ThruputMeter.o \
    $O/util/Macho.o \
    $O/util/headerserializers/TCPIPchecksum.o \
    $O/util/headerserializers/ipv4/ICMPSerializer.o \
    $O/util/headerserializers/ipv4/IGMPSerializer.o \
    $O/util/headerserializers/ipv4/IPv4Serializer.o \
    $O/util/headerserializers/sctp/SCTPSerializer.o \
    $O/util/headerserializers/tcp/TCPSerializer.o \
    $O/util/headerserializers/udp/UDPSerializer.o \
    $O/world/annotations/AnnotationDummy.o \
    $O/world/annotations/AnnotationManager.o \
    $O/world/httptools/HttpController.o \
    $O/world/obstacles/ObstacleControl.o \
    $O/world/obstacles/Obstacle.o \
    $O/world/powercontrol/PowerControlManager.o \
    $O/world/radio/PrimaryUserRef.o \
    $O/world/radio/PrimaryUser.o \
    $O/world/radio/ChannelAccess.o \
    $O/world/radio/ChannelControl.o \
    $O/world/scenario/ScenarioManager.o \
    $O/world/traci/TraCIScenarioManager.o \
    $O/world/traci/TraCIScenarioManagerLaunchd.o \
    $O/applications/dhcp/DHCP_m.o \
    $O/applications/ethernet/EtherApp_m.o \
    $O/applications/httptools/HttpEventMessages_m.o \
    $O/applications/httptools/HttpMessages_m.o \
    $O/applications/pingapp/PingPayload_m.o \
    $O/applications/tcpapp/GenericAppMsg_m.o \
    $O/base/ByteArrayMessage_m.o \
    $O/base/ByteArray_m.o \
    $O/linklayer/contract/PhyControlInfo_m.o \
    $O/linklayer/contract/Ieee802Ctrl_m.o \
    $O/linklayer/ethernet/EtherFrame_m.o \
    $O/linklayer/ext/ExtFrame_m.o \
    $O/linklayer/ieee80211/mac/Ieee80211Frame_m.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.o \
    $O/linklayer/ieee80211/mgmt/ETXPacket_m.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211Primitives_m.o \
    $O/linklayer/ppp/PPPFrame_m.o \
    $O/linklayer/radio/AirFrame_m.o \
    $O/linklayer/radio/Radio80211aControlInfo_m.o \
    $O/networklayer/arp/ARPPacket_m.o \
    $O/networklayer/bgpv4/BGPMessage/BGPKeepAlive_m.o \
    $O/networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.o \
    $O/networklayer/bgpv4/BGPMessage/BGPOpen_m.o \
    $O/networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.o \
    $O/networklayer/bgpv4/BGPMessage/BGPUpdate_m.o \
    $O/networklayer/bgpv4/BGPMessage/BGPHeader_m.o \
    $O/networklayer/contract/IPv4ControlInfo_m.o \
    $O/networklayer/contract/IPv6ControlInfo_m.o \
    $O/networklayer/contract/IPProtocolId_m.o \
    $O/networklayer/diffserv/DSCP_m.o \
    $O/networklayer/icmpv6/IPv6NDMessage_m.o \
    $O/networklayer/icmpv6/ICMPv6Message_m.o \
    $O/networklayer/ipv4/IGMPMessage_m.o \
    $O/networklayer/ipv4/IPv4Datagram_m.o \
    $O/networklayer/ipv4/ICMPMessage_m.o \
    $O/networklayer/ipv6/IPv6Datagram_m.o \
    $O/networklayer/ipv6/IPv6ExtensionHeaders_m.o \
    $O/networklayer/ldp/LDPPacket_m.o \
    $O/networklayer/manetrouting/GPS/msgRouting_m.o \
    $O/networklayer/manetrouting/GPS/msgNeighbor_m.o \
    $O/networklayer/manetrouting/VCap/msgToRoute_m.o \
    $O/networklayer/manetrouting/VCap/msgReq_m.o \
    $O/networklayer/manetrouting/VCap/msgNeighborDisc_m.o \
    $O/networklayer/manetrouting/VCap/msgW_m.o \
    $O/networklayer/manetrouting/base/ControlManetRouting_m.o \
    $O/networklayer/manetrouting/base/ControlInfoBreakLink_m.o \
    $O/networklayer/manetrouting/base/MeshControlInfo_m.o \
    $O/networklayer/manetrouting/batman/BatmanMsg_m.o \
    $O/networklayer/manetrouting/berger/BergerNeighborInfo_m.o \
    $O/networklayer/manetrouting/berger/BergerRouteRequest_m.o \
    $O/networklayer/manetrouting/dsdv/DSDVhello_m.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_UERR_m.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_RREQ_m.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_RM_m.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_RERR_m.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_Packet_m.o \
    $O/networklayer/manetrouting/dymo_fau/DYMO_RREP_m.o \
    $O/networklayer/manetrouting/olsr/OLSRpkt_m.o \
    $O/networklayer/manetrouting/search/searNeighborInfo_m.o \
    $O/networklayer/manetrouting/search/searRouteRequest_m.o \
    $O/networklayer/ospfv2/OSPFPacket_m.o \
    $O/networklayer/ospfv2/OSPFTimer_m.o \
    $O/networklayer/rsvp_te/IntServ_m.o \
    $O/networklayer/rsvp_te/RSVPPacket_m.o \
    $O/networklayer/rsvp_te/RSVPPathMsg_m.o \
    $O/networklayer/rsvp_te/SignallingMsg_m.o \
    $O/networklayer/rsvp_te/RSVPResvMsg_m.o \
    $O/networklayer/rsvp_te/RSVPHello_m.o \
    $O/networklayer/ted/LinkStatePacket_m.o \
    $O/networklayer/ted/TED_m.o \
    $O/networklayer/xmipv6/MobilityHeader_m.o \
    $O/transport/contract/TCPCommand_m.o \
    $O/transport/contract/SCTPCommand_m.o \
    $O/transport/contract/UDPControlInfo_m.o \
    $O/transport/rtp/RTPSenderControlMessage_m.o \
    $O/transport/rtp/RTPParticipantInfo_m.o \
    $O/transport/rtp/RTPInterfacePacket_m.o \
    $O/transport/rtp/RTCPPacket1_m.o \
    $O/transport/rtp/RTPInnerPacket_m.o \
    $O/transport/rtp/RTPSenderStatusMessage_m.o \
    $O/transport/rtp/RTPPacket_m.o \
    $O/transport/rtp/reports_m.o \
    $O/transport/rtp/RTCPPacket2_m.o \
    $O/transport/rtp/RTCPPacket3_m.o \
    $O/transport/rtp/profiles/avprofile/RTPMpegPacket_m.o \
    $O/transport/sctp/SCTPMessage_m.o \
    $O/transport/tcp_common/TCPSegment_m.o \
    $O/transport/udp/UDPPacket_m.o \
    $O/world/powercontrol/PowerControlMessages_m.o

# Message files
MSGFILES = \
    applications/dhcp/DHCP.msg \
    applications/ethernet/EtherApp.msg \
    applications/httptools/HttpEventMessages.msg \
    applications/httptools/HttpMessages.msg \
    applications/pingapp/PingPayload.msg \
    applications/tcpapp/GenericAppMsg.msg \
    base/ByteArrayMessage.msg \
    base/ByteArray.msg \
    linklayer/contract/PhyControlInfo.msg \
    linklayer/contract/Ieee802Ctrl.msg \
    linklayer/ethernet/EtherFrame.msg \
    linklayer/ext/ExtFrame.msg \
    linklayer/ieee80211/mac/Ieee80211Frame.msg \
    linklayer/ieee80211/mgmt/Ieee80211MgmtFrames.msg \
    linklayer/ieee80211/mgmt/ETXPacket.msg \
    linklayer/ieee80211/mgmt/Ieee80211Primitives.msg \
    linklayer/ppp/PPPFrame.msg \
    linklayer/radio/AirFrame.msg \
    linklayer/radio/Radio80211aControlInfo.msg \
    networklayer/arp/ARPPacket.msg \
    networklayer/bgpv4/BGPMessage/BGPKeepAlive.msg \
    networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes.msg \
    networklayer/bgpv4/BGPMessage/BGPOpen.msg \
    networklayer/bgpv4/BGPMessage/BGPASPathSegment.msg \
    networklayer/bgpv4/BGPMessage/BGPUpdate.msg \
    networklayer/bgpv4/BGPMessage/BGPHeader.msg \
    networklayer/contract/IPv4ControlInfo.msg \
    networklayer/contract/IPv6ControlInfo.msg \
    networklayer/contract/IPProtocolId.msg \
    networklayer/diffserv/DSCP.msg \
    networklayer/icmpv6/IPv6NDMessage.msg \
    networklayer/icmpv6/ICMPv6Message.msg \
    networklayer/ipv4/IGMPMessage.msg \
    networklayer/ipv4/IPv4Datagram.msg \
    networklayer/ipv4/ICMPMessage.msg \
    networklayer/ipv6/IPv6Datagram.msg \
    networklayer/ipv6/IPv6ExtensionHeaders.msg \
    networklayer/ldp/LDPPacket.msg \
    networklayer/manetrouting/GPS/msgRouting.msg \
    networklayer/manetrouting/GPS/msgNeighbor.msg \
    networklayer/manetrouting/VCap/msgToRoute.msg \
    networklayer/manetrouting/VCap/msgReq.msg \
    networklayer/manetrouting/VCap/msgNeighborDisc.msg \
    networklayer/manetrouting/VCap/msgW.msg \
    networklayer/manetrouting/base/ControlManetRouting.msg \
    networklayer/manetrouting/base/ControlInfoBreakLink.msg \
    networklayer/manetrouting/base/MeshControlInfo.msg \
    networklayer/manetrouting/batman/BatmanMsg.msg \
    networklayer/manetrouting/berger/BergerNeighborInfo.msg \
    networklayer/manetrouting/berger/BergerRouteRequest.msg \
    networklayer/manetrouting/dsdv/DSDVhello.msg \
    networklayer/manetrouting/dymo_fau/DYMO_UERR.msg \
    networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage.msg \
    networklayer/manetrouting/dymo_fau/DYMO_RREQ.msg \
    networklayer/manetrouting/dymo_fau/DYMO_RM.msg \
    networklayer/manetrouting/dymo_fau/DYMO_Timeout.msg \
    networklayer/manetrouting/dymo_fau/DYMO_RERR.msg \
    networklayer/manetrouting/dymo_fau/DYMO_Packet.msg \
    networklayer/manetrouting/dymo_fau/DYMO_RREP.msg \
    networklayer/manetrouting/olsr/OLSRpkt.msg \
    networklayer/manetrouting/search/searNeighborInfo.msg \
    networklayer/manetrouting/search/searRouteRequest.msg \
    networklayer/ospfv2/OSPFPacket.msg \
    networklayer/ospfv2/OSPFTimer.msg \
    networklayer/rsvp_te/IntServ.msg \
    networklayer/rsvp_te/RSVPPacket.msg \
    networklayer/rsvp_te/RSVPPathMsg.msg \
    networklayer/rsvp_te/SignallingMsg.msg \
    networklayer/rsvp_te/RSVPResvMsg.msg \
    networklayer/rsvp_te/RSVPHello.msg \
    networklayer/ted/LinkStatePacket.msg \
    networklayer/ted/TED.msg \
    networklayer/xmipv6/MobilityHeader.msg \
    transport/contract/TCPCommand.msg \
    transport/contract/SCTPCommand.msg \
    transport/contract/UDPControlInfo.msg \
    transport/rtp/RTPSenderControlMessage.msg \
    transport/rtp/RTPParticipantInfo.msg \
    transport/rtp/RTPInterfacePacket.msg \
    transport/rtp/RTCPPacket1.msg \
    transport/rtp/RTPInnerPacket.msg \
    transport/rtp/RTPSenderStatusMessage.msg \
    transport/rtp/RTPPacket.msg \
    transport/rtp/reports.msg \
    transport/rtp/RTCPPacket2.msg \
    transport/rtp/RTCPPacket3.msg \
    transport/rtp/profiles/avprofile/RTPMpegPacket.msg \
    transport/sctp/SCTPMessage.msg \
    transport/tcp_common/TCPSegment.msg \
    transport/udp/UDPPacket.msg \
    world/powercontrol/PowerControlMessages.msg

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
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) \
    -DWITH_TCP_COMMON \
    -DWITH_TCP_INET \
    -DWITH_IPv4 \
    -DWITH_IPv6 \
    -DWITH_xMIPv6 \
    -DWITH_UDP \
    -DWITH_RTP \
    -DWITH_SCTP \
    -DWITH_DHCP \
    -DWITH_ETHERNET \
    -DWITH_PPP \
    -DWITH_EXT_IF \
    -DWITH_MPLS \
    -DWITH_OSPFv2 \
    -DWITH_BGPv4 \
    -DWITH_TRACI \
    -DWITH_MANET \
    -DINET_EXPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH) -PINET_API

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
# inserted from file 'makefrag':
# if you want to use external interfaces with inet, you should install
# winpcap (on windows) or libpcap-dev (on linux) and re-run ./configure in
# the omnetpp root directory and comment out the following line:
#HAVE_PCAP=no

ifeq ($(HAVE_PCAP),yes)
  # link with PCAP libs too
  LIBS += $(PCAP_LIBS)
else
  # remove the HAVE_PCAP define if we do not need PCAP
  CFLAGS := $(filter-out -DHAVE_PCAP,$(CFLAGS))

endif

#
# TCP implementaion using the Network Simulation Cradle (TCP_NSC feature)
#
ifneq (,$(findstring -DWITH_TCP_NSC,$(COPTS)))
  NSC_VERSION= $(shell ls -d ../3rdparty/nsc* 2>/dev/null | sed 's/^.*-//')
  ifneq ($(NSC_VERSION),)
    CFLAGS += -I../3rdparty/nsc-$(NSC_VERSION)/sim -DHAVE_NSC
    LIBS += -Wl,-rpath,`abspath ../3rdparty/nsc-$(NSC_VERSION)`
  endif
endif

#
# pkg-config:
#
HAVE_PKGCFG := $(shell pkg-config --version 2>/dev/null)
ifeq ($(strip $(HAVE_PKGCFG)),)
  HAVE_PKGCFG := no
else
  HAVE_PKGCFG := yes
  PKGCFG := $(shell which pkg-config)
endif

#
# VoipTool feature:
#
ifneq (,$(findstring -DWITH_VOIPTOOL,$(COPTS)))
  ifeq ($(HAVE_PKGCFG), yes)
    HAVE_FFMPEG := $(shell $(PKGCFG) --exists libavcodec libavformat libavutil && echo yes || echo no)
    ifeq ($(HAVE_FFMPEG), yes)
      LIBS += $(shell $(PKGCFG) --libs libavcodec libavformat libavutil)
      CFLAGS += $(shell $(PKGCFG) --cflags libavcodec libavformat libavutil) -DHAVE_FFMPEG
    endif
  endif
endif

# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f inet inet.exe libinet.so libinet.a libinet.dll libinet.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f Eigen/*_m.cc Eigen/*_m.h
	$(Q)-rm -f Eigen/src/*_m.cc Eigen/src/*_m.h
	$(Q)-rm -f Eigen/src/Cholesky/*_m.cc Eigen/src/Cholesky/*_m.h
	$(Q)-rm -f Eigen/src/CholmodSupport/*_m.cc Eigen/src/CholmodSupport/*_m.h
	$(Q)-rm -f Eigen/src/Core/*_m.cc Eigen/src/Core/*_m.h
	$(Q)-rm -f Eigen/src/Core/arch/*_m.cc Eigen/src/Core/arch/*_m.h
	$(Q)-rm -f Eigen/src/Core/arch/AltiVec/*_m.cc Eigen/src/Core/arch/AltiVec/*_m.h
	$(Q)-rm -f Eigen/src/Core/arch/Default/*_m.cc Eigen/src/Core/arch/Default/*_m.h
	$(Q)-rm -f Eigen/src/Core/arch/NEON/*_m.cc Eigen/src/Core/arch/NEON/*_m.h
	$(Q)-rm -f Eigen/src/Core/arch/SSE/*_m.cc Eigen/src/Core/arch/SSE/*_m.h
	$(Q)-rm -f Eigen/src/Core/products/*_m.cc Eigen/src/Core/products/*_m.h
	$(Q)-rm -f Eigen/src/Core/util/*_m.cc Eigen/src/Core/util/*_m.h
	$(Q)-rm -f Eigen/src/Eigen2Support/*_m.cc Eigen/src/Eigen2Support/*_m.h
	$(Q)-rm -f Eigen/src/Eigen2Support/Geometry/*_m.cc Eigen/src/Eigen2Support/Geometry/*_m.h
	$(Q)-rm -f Eigen/src/Eigenvalues/*_m.cc Eigen/src/Eigenvalues/*_m.h
	$(Q)-rm -f Eigen/src/Geometry/*_m.cc Eigen/src/Geometry/*_m.h
	$(Q)-rm -f Eigen/src/Geometry/arch/*_m.cc Eigen/src/Geometry/arch/*_m.h
	$(Q)-rm -f Eigen/src/Householder/*_m.cc Eigen/src/Householder/*_m.h
	$(Q)-rm -f Eigen/src/IterativeLinearSolvers/*_m.cc Eigen/src/IterativeLinearSolvers/*_m.h
	$(Q)-rm -f Eigen/src/Jacobi/*_m.cc Eigen/src/Jacobi/*_m.h
	$(Q)-rm -f Eigen/src/LU/*_m.cc Eigen/src/LU/*_m.h
	$(Q)-rm -f Eigen/src/LU/arch/*_m.cc Eigen/src/LU/arch/*_m.h
	$(Q)-rm -f Eigen/src/OrderingMethods/*_m.cc Eigen/src/OrderingMethods/*_m.h
	$(Q)-rm -f Eigen/src/PaStiXSupport/*_m.cc Eigen/src/PaStiXSupport/*_m.h
	$(Q)-rm -f Eigen/src/PardisoSupport/*_m.cc Eigen/src/PardisoSupport/*_m.h
	$(Q)-rm -f Eigen/src/QR/*_m.cc Eigen/src/QR/*_m.h
	$(Q)-rm -f Eigen/src/SVD/*_m.cc Eigen/src/SVD/*_m.h
	$(Q)-rm -f Eigen/src/SparseCholesky/*_m.cc Eigen/src/SparseCholesky/*_m.h
	$(Q)-rm -f Eigen/src/SparseCore/*_m.cc Eigen/src/SparseCore/*_m.h
	$(Q)-rm -f Eigen/src/StlSupport/*_m.cc Eigen/src/StlSupport/*_m.h
	$(Q)-rm -f Eigen/src/SuperLUSupport/*_m.cc Eigen/src/SuperLUSupport/*_m.h
	$(Q)-rm -f Eigen/src/UmfPackSupport/*_m.cc Eigen/src/UmfPackSupport/*_m.h
	$(Q)-rm -f Eigen/src/misc/*_m.cc Eigen/src/misc/*_m.h
	$(Q)-rm -f Eigen/src/plugins/*_m.cc Eigen/src/plugins/*_m.h
	$(Q)-rm -f applications/*_m.cc applications/*_m.h
	$(Q)-rm -f applications/dhcp/*_m.cc applications/dhcp/*_m.h
	$(Q)-rm -f applications/ethernet/*_m.cc applications/ethernet/*_m.h
	$(Q)-rm -f applications/generic/*_m.cc applications/generic/*_m.h
	$(Q)-rm -f applications/httptools/*_m.cc applications/httptools/*_m.h
	$(Q)-rm -f applications/pingapp/*_m.cc applications/pingapp/*_m.h
	$(Q)-rm -f applications/rtpapp/*_m.cc applications/rtpapp/*_m.h
	$(Q)-rm -f applications/sctpapp/*_m.cc applications/sctpapp/*_m.h
	$(Q)-rm -f applications/tcpapp/*_m.cc applications/tcpapp/*_m.h
	$(Q)-rm -f applications/traci/*_m.cc applications/traci/*_m.h
	$(Q)-rm -f applications/udpapp/*_m.cc applications/udpapp/*_m.h
	$(Q)-rm -f base/*_m.cc base/*_m.h
	$(Q)-rm -f battery/*_m.cc battery/*_m.h
	$(Q)-rm -f battery/models/*_m.cc battery/models/*_m.h
	$(Q)-rm -f linklayer/*_m.cc linklayer/*_m.h
	$(Q)-rm -f linklayer/contract/*_m.cc linklayer/contract/*_m.h
	$(Q)-rm -f linklayer/ethernet/*_m.cc linklayer/ethernet/*_m.h
	$(Q)-rm -f linklayer/ethernet/switch/*_m.cc linklayer/ethernet/switch/*_m.h
	$(Q)-rm -f linklayer/ext/*_m.cc linklayer/ext/*_m.h
	$(Q)-rm -f linklayer/ieee80211/*_m.cc linklayer/ieee80211/*_m.h
	$(Q)-rm -f linklayer/ieee80211/mac/*_m.cc linklayer/ieee80211/mac/*_m.h
	$(Q)-rm -f linklayer/ieee80211/mgmt/*_m.cc linklayer/ieee80211/mgmt/*_m.h
	$(Q)-rm -f linklayer/ieee80211/radio/*_m.cc linklayer/ieee80211/radio/*_m.h
	$(Q)-rm -f linklayer/ieee80211/radio/errormodel/*_m.cc linklayer/ieee80211/radio/errormodel/*_m.h
	$(Q)-rm -f linklayer/ppp/*_m.cc linklayer/ppp/*_m.h
	$(Q)-rm -f linklayer/queue/*_m.cc linklayer/queue/*_m.h
	$(Q)-rm -f linklayer/radio/*_m.cc linklayer/radio/*_m.h
	$(Q)-rm -f linklayer/radio/propagation/*_m.cc linklayer/radio/propagation/*_m.h
	$(Q)-rm -f mobility/*_m.cc mobility/*_m.h
	$(Q)-rm -f mobility/models/*_m.cc mobility/models/*_m.h
	$(Q)-rm -f networklayer/*_m.cc networklayer/*_m.h
	$(Q)-rm -f networklayer/arp/*_m.cc networklayer/arp/*_m.h
	$(Q)-rm -f networklayer/autorouting/*_m.cc networklayer/autorouting/*_m.h
	$(Q)-rm -f networklayer/autorouting/ipv4/*_m.cc networklayer/autorouting/ipv4/*_m.h
	$(Q)-rm -f networklayer/autorouting/ipv6/*_m.cc networklayer/autorouting/ipv6/*_m.h
	$(Q)-rm -f networklayer/bgpv4/*_m.cc networklayer/bgpv4/*_m.h
	$(Q)-rm -f networklayer/bgpv4/BGPMessage/*_m.cc networklayer/bgpv4/BGPMessage/*_m.h
	$(Q)-rm -f networklayer/common/*_m.cc networklayer/common/*_m.h
	$(Q)-rm -f networklayer/contract/*_m.cc networklayer/contract/*_m.h
	$(Q)-rm -f networklayer/diffserv/*_m.cc networklayer/diffserv/*_m.h
	$(Q)-rm -f networklayer/extras/*_m.cc networklayer/extras/*_m.h
	$(Q)-rm -f networklayer/icmpv6/*_m.cc networklayer/icmpv6/*_m.h
	$(Q)-rm -f networklayer/ipv4/*_m.cc networklayer/ipv4/*_m.h
	$(Q)-rm -f networklayer/ipv6/*_m.cc networklayer/ipv6/*_m.h
	$(Q)-rm -f networklayer/ipv6tunneling/*_m.cc networklayer/ipv6tunneling/*_m.h
	$(Q)-rm -f networklayer/ldp/*_m.cc networklayer/ldp/*_m.h
	$(Q)-rm -f networklayer/manetrouting/*_m.cc networklayer/manetrouting/*_m.h
	$(Q)-rm -f networklayer/manetrouting/GPS/*_m.cc networklayer/manetrouting/GPS/*_m.h
	$(Q)-rm -f networklayer/manetrouting/VCap/*_m.cc networklayer/manetrouting/VCap/*_m.h
	$(Q)-rm -f networklayer/manetrouting/aodv/*_m.cc networklayer/manetrouting/aodv/*_m.h
	$(Q)-rm -f networklayer/manetrouting/aodv/aodv-uu/*_m.cc networklayer/manetrouting/aodv/aodv-uu/*_m.h
	$(Q)-rm -f networklayer/manetrouting/base/*_m.cc networklayer/manetrouting/base/*_m.h
	$(Q)-rm -f networklayer/manetrouting/batman/*_m.cc networklayer/manetrouting/batman/*_m.h
	$(Q)-rm -f networklayer/manetrouting/berger/*_m.cc networklayer/manetrouting/berger/*_m.h
	$(Q)-rm -f networklayer/manetrouting/dsdv/*_m.cc networklayer/manetrouting/dsdv/*_m.h
	$(Q)-rm -f networklayer/manetrouting/dsr/*_m.cc networklayer/manetrouting/dsr/*_m.h
	$(Q)-rm -f networklayer/manetrouting/dsr/dsr-uu/*_m.cc networklayer/manetrouting/dsr/dsr-uu/*_m.h
	$(Q)-rm -f networklayer/manetrouting/dymo/*_m.cc networklayer/manetrouting/dymo/*_m.h
	$(Q)-rm -f networklayer/manetrouting/dymo/dymoum/*_m.cc networklayer/manetrouting/dymo/dymoum/*_m.h
	$(Q)-rm -f networklayer/manetrouting/dymo_fau/*_m.cc networklayer/manetrouting/dymo_fau/*_m.h
	$(Q)-rm -f networklayer/manetrouting/olsr/*_m.cc networklayer/manetrouting/olsr/*_m.h
	$(Q)-rm -f networklayer/manetrouting/search/*_m.cc networklayer/manetrouting/search/*_m.h
	$(Q)-rm -f networklayer/mpls/*_m.cc networklayer/mpls/*_m.h
	$(Q)-rm -f networklayer/ospfv2/*_m.cc networklayer/ospfv2/*_m.h
	$(Q)-rm -f networklayer/ospfv2/interface/*_m.cc networklayer/ospfv2/interface/*_m.h
	$(Q)-rm -f networklayer/ospfv2/messagehandler/*_m.cc networklayer/ospfv2/messagehandler/*_m.h
	$(Q)-rm -f networklayer/ospfv2/neighbor/*_m.cc networklayer/ospfv2/neighbor/*_m.h
	$(Q)-rm -f networklayer/ospfv2/router/*_m.cc networklayer/ospfv2/router/*_m.h
	$(Q)-rm -f networklayer/rsvp_te/*_m.cc networklayer/rsvp_te/*_m.h
	$(Q)-rm -f networklayer/ted/*_m.cc networklayer/ted/*_m.h
	$(Q)-rm -f networklayer/xmipv6/*_m.cc networklayer/xmipv6/*_m.h
	$(Q)-rm -f nodes/*_m.cc nodes/*_m.h
	$(Q)-rm -f nodes/bgp/*_m.cc nodes/bgp/*_m.h
	$(Q)-rm -f nodes/ethernet/*_m.cc nodes/ethernet/*_m.h
	$(Q)-rm -f nodes/httptools/*_m.cc nodes/httptools/*_m.h
	$(Q)-rm -f nodes/inet/*_m.cc nodes/inet/*_m.h
	$(Q)-rm -f nodes/ipv6/*_m.cc nodes/ipv6/*_m.h
	$(Q)-rm -f nodes/mpls/*_m.cc nodes/mpls/*_m.h
	$(Q)-rm -f nodes/ospfv2/*_m.cc nodes/ospfv2/*_m.h
	$(Q)-rm -f nodes/wireless/*_m.cc nodes/wireless/*_m.h
	$(Q)-rm -f nodes/xmipv6/*_m.cc nodes/xmipv6/*_m.h
	$(Q)-rm -f transport/*_m.cc transport/*_m.h
	$(Q)-rm -f transport/contract/*_m.cc transport/contract/*_m.h
	$(Q)-rm -f transport/rtp/*_m.cc transport/rtp/*_m.h
	$(Q)-rm -f transport/rtp/profiles/*_m.cc transport/rtp/profiles/*_m.h
	$(Q)-rm -f transport/rtp/profiles/avprofile/*_m.cc transport/rtp/profiles/avprofile/*_m.h
	$(Q)-rm -f transport/sctp/*_m.cc transport/sctp/*_m.h
	$(Q)-rm -f transport/tcp/*_m.cc transport/tcp/*_m.h
	$(Q)-rm -f transport/tcp/flavours/*_m.cc transport/tcp/flavours/*_m.h
	$(Q)-rm -f transport/tcp/queues/*_m.cc transport/tcp/queues/*_m.h
	$(Q)-rm -f transport/tcp_common/*_m.cc transport/tcp_common/*_m.h
	$(Q)-rm -f transport/udp/*_m.cc transport/udp/*_m.h
	$(Q)-rm -f util/*_m.cc util/*_m.h
	$(Q)-rm -f util/headerserializers/*_m.cc util/headerserializers/*_m.h
	$(Q)-rm -f util/headerserializers/headers/*_m.cc util/headerserializers/headers/*_m.h
	$(Q)-rm -f util/headerserializers/ipv4/*_m.cc util/headerserializers/ipv4/*_m.h
	$(Q)-rm -f util/headerserializers/ipv4/headers/*_m.cc util/headerserializers/ipv4/headers/*_m.h
	$(Q)-rm -f util/headerserializers/sctp/*_m.cc util/headerserializers/sctp/*_m.h
	$(Q)-rm -f util/headerserializers/sctp/headers/*_m.cc util/headerserializers/sctp/headers/*_m.h
	$(Q)-rm -f util/headerserializers/tcp/*_m.cc util/headerserializers/tcp/*_m.h
	$(Q)-rm -f util/headerserializers/tcp/headers/*_m.cc util/headerserializers/tcp/headers/*_m.h
	$(Q)-rm -f util/headerserializers/udp/*_m.cc util/headerserializers/udp/*_m.h
	$(Q)-rm -f util/headerserializers/udp/headers/*_m.cc util/headerserializers/udp/headers/*_m.h
	$(Q)-rm -f world/*_m.cc world/*_m.h
	$(Q)-rm -f world/annotations/*_m.cc world/annotations/*_m.h
	$(Q)-rm -f world/httptools/*_m.cc world/httptools/*_m.h
	$(Q)-rm -f world/obstacles/*_m.cc world/obstacles/*_m.h
	$(Q)-rm -f world/powercontrol/*_m.cc world/powercontrol/*_m.h
	$(Q)-rm -f world/radio/*_m.cc world/radio/*_m.h
	$(Q)-rm -f world/scenario/*_m.cc world/scenario/*_m.h
	$(Q)-rm -f world/traci/*_m.cc world/traci/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc Eigen/*.cc Eigen/src/*.cc Eigen/src/Cholesky/*.cc Eigen/src/CholmodSupport/*.cc Eigen/src/Core/*.cc Eigen/src/Core/arch/*.cc Eigen/src/Core/arch/AltiVec/*.cc Eigen/src/Core/arch/Default/*.cc Eigen/src/Core/arch/NEON/*.cc Eigen/src/Core/arch/SSE/*.cc Eigen/src/Core/products/*.cc Eigen/src/Core/util/*.cc Eigen/src/Eigen2Support/*.cc Eigen/src/Eigen2Support/Geometry/*.cc Eigen/src/Eigenvalues/*.cc Eigen/src/Geometry/*.cc Eigen/src/Geometry/arch/*.cc Eigen/src/Householder/*.cc Eigen/src/IterativeLinearSolvers/*.cc Eigen/src/Jacobi/*.cc Eigen/src/LU/*.cc Eigen/src/LU/arch/*.cc Eigen/src/OrderingMethods/*.cc Eigen/src/PaStiXSupport/*.cc Eigen/src/PardisoSupport/*.cc Eigen/src/QR/*.cc Eigen/src/SVD/*.cc Eigen/src/SparseCholesky/*.cc Eigen/src/SparseCore/*.cc Eigen/src/StlSupport/*.cc Eigen/src/SuperLUSupport/*.cc Eigen/src/UmfPackSupport/*.cc Eigen/src/misc/*.cc Eigen/src/plugins/*.cc applications/*.cc applications/dhcp/*.cc applications/ethernet/*.cc applications/generic/*.cc applications/httptools/*.cc applications/pingapp/*.cc applications/rtpapp/*.cc applications/sctpapp/*.cc applications/tcpapp/*.cc applications/traci/*.cc applications/udpapp/*.cc base/*.cc battery/*.cc battery/models/*.cc linklayer/*.cc linklayer/contract/*.cc linklayer/ethernet/*.cc linklayer/ethernet/switch/*.cc linklayer/ext/*.cc linklayer/ieee80211/*.cc linklayer/ieee80211/mac/*.cc linklayer/ieee80211/mgmt/*.cc linklayer/ieee80211/radio/*.cc linklayer/ieee80211/radio/errormodel/*.cc linklayer/ppp/*.cc linklayer/queue/*.cc linklayer/radio/*.cc linklayer/radio/propagation/*.cc mobility/*.cc mobility/models/*.cc networklayer/*.cc networklayer/arp/*.cc networklayer/autorouting/*.cc networklayer/autorouting/ipv4/*.cc networklayer/autorouting/ipv6/*.cc networklayer/bgpv4/*.cc networklayer/bgpv4/BGPMessage/*.cc networklayer/common/*.cc networklayer/contract/*.cc networklayer/diffserv/*.cc networklayer/extras/*.cc networklayer/icmpv6/*.cc networklayer/ipv4/*.cc networklayer/ipv6/*.cc networklayer/ipv6tunneling/*.cc networklayer/ldp/*.cc networklayer/manetrouting/*.cc networklayer/manetrouting/GPS/*.cc networklayer/manetrouting/VCap/*.cc networklayer/manetrouting/aodv/*.cc networklayer/manetrouting/aodv/aodv-uu/*.cc networklayer/manetrouting/base/*.cc networklayer/manetrouting/batman/*.cc networklayer/manetrouting/berger/*.cc networklayer/manetrouting/dsdv/*.cc networklayer/manetrouting/dsr/*.cc networklayer/manetrouting/dsr/dsr-uu/*.cc networklayer/manetrouting/dymo/*.cc networklayer/manetrouting/dymo/dymoum/*.cc networklayer/manetrouting/dymo_fau/*.cc networklayer/manetrouting/olsr/*.cc networklayer/manetrouting/search/*.cc networklayer/mpls/*.cc networklayer/ospfv2/*.cc networklayer/ospfv2/interface/*.cc networklayer/ospfv2/messagehandler/*.cc networklayer/ospfv2/neighbor/*.cc networklayer/ospfv2/router/*.cc networklayer/rsvp_te/*.cc networklayer/ted/*.cc networklayer/xmipv6/*.cc nodes/*.cc nodes/bgp/*.cc nodes/ethernet/*.cc nodes/httptools/*.cc nodes/inet/*.cc nodes/ipv6/*.cc nodes/mpls/*.cc nodes/ospfv2/*.cc nodes/wireless/*.cc nodes/xmipv6/*.cc transport/*.cc transport/contract/*.cc transport/rtp/*.cc transport/rtp/profiles/*.cc transport/rtp/profiles/avprofile/*.cc transport/sctp/*.cc transport/tcp/*.cc transport/tcp/flavours/*.cc transport/tcp/queues/*.cc transport/tcp_common/*.cc transport/udp/*.cc util/*.cc util/headerserializers/*.cc util/headerserializers/headers/*.cc util/headerserializers/ipv4/*.cc util/headerserializers/ipv4/headers/*.cc util/headerserializers/sctp/*.cc util/headerserializers/sctp/headers/*.cc util/headerserializers/tcp/*.cc util/headerserializers/tcp/headers/*.cc util/headerserializers/udp/*.cc util/headerserializers/udp/headers/*.cc world/*.cc world/annotations/*.cc world/httptools/*.cc world/obstacles/*.cc world/powercontrol/*.cc world/radio/*.cc world/scenario/*.cc world/traci/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/applications/dhcp/DHCPClient.o: applications/dhcp/DHCPClient.cc \
	applications/dhcp/Byte.h \
	applications/dhcp/DHCPClient.h \
	applications/dhcp/DHCPLease.h \
	applications/dhcp/DHCPOptions.h \
	applications/dhcp/DHCP_m.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/applications/dhcp/DHCPServer.o: applications/dhcp/DHCPServer.cc \
	applications/dhcp/Byte.h \
	applications/dhcp/DHCPLease.h \
	applications/dhcp/DHCPOptions.h \
	applications/dhcp/DHCPServer.h \
	applications/dhcp/DHCP_m.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/applications/dhcp/DHCP_m.o: applications/dhcp/DHCP_m.cc \
	applications/dhcp/Byte.h \
	applications/dhcp/DHCPOptions.h \
	applications/dhcp/DHCP_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPv4Address.h
$O/applications/ethernet/EtherAppCli.o: applications/ethernet/EtherAppCli.cc \
	applications/ethernet/EtherAppCli.h \
	applications/ethernet/EtherApp_m.h \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h
$O/applications/ethernet/EtherAppSrv.o: applications/ethernet/EtherAppSrv.cc \
	applications/ethernet/EtherAppSrv.h \
	applications/ethernet/EtherApp_m.h \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h
$O/applications/ethernet/EtherApp_m.o: applications/ethernet/EtherApp_m.cc \
	applications/ethernet/EtherApp_m.h \
	base/INETDefs.h
$O/applications/ethernet/EtherTrafGen.o: applications/ethernet/EtherTrafGen.cc \
	applications/ethernet/EtherTrafGen.h \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h
$O/applications/generic/IPvXTrafGen.o: applications/generic/IPvXTrafGen.cc \
	applications/generic/IPvXTrafGen.h \
	applications/generic/IPvXTrafSink.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	util/uint128.h
$O/applications/generic/IPvXTrafSink.o: applications/generic/IPvXTrafSink.cc \
	applications/generic/IPvXTrafGen.h \
	applications/generic/IPvXTrafSink.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	util/uint128.h
$O/applications/httptools/HttpBrowser.o: applications/httptools/HttpBrowser.cc \
	applications/httptools/HttpBrowser.h \
	applications/httptools/HttpBrowserBase.h \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/uint128.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpBrowserBase.o: applications/httptools/HttpBrowserBase.cc \
	applications/httptools/HttpBrowserBase.h \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpBrowserDirect.o: applications/httptools/HttpBrowserDirect.cc \
	applications/httptools/HttpBrowserBase.h \
	applications/httptools/HttpBrowserDirect.h \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpServerBase.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpEventMessages_m.o: applications/httptools/HttpEventMessages_m.cc \
	applications/httptools/HttpEventMessages_m.h
$O/applications/httptools/HttpMessages_m.o: applications/httptools/HttpMessages_m.cc \
	applications/httptools/HttpMessages_m.h
$O/applications/httptools/HttpNodeBase.o: applications/httptools/HttpNodeBase.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpRandom.o: applications/httptools/HttpRandom.cc \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h
$O/applications/httptools/HttpServer.o: applications/httptools/HttpServer.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpServer.h \
	applications/httptools/HttpServerBase.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/uint128.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpServerBase.o: applications/httptools/HttpServerBase.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpServerBase.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpServerDirect.o: applications/httptools/HttpServerDirect.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpServerBase.h \
	applications/httptools/HttpServerDirect.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpServerDirectEvilA.o: applications/httptools/HttpServerDirectEvilA.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpServerBase.h \
	applications/httptools/HttpServerDirect.h \
	applications/httptools/HttpServerDirectEvilA.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpServerDirectEvilB.o: applications/httptools/HttpServerDirectEvilB.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpServerBase.h \
	applications/httptools/HttpServerDirect.h \
	applications/httptools/HttpServerDirectEvilB.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpServerEvilA.o: applications/httptools/HttpServerEvilA.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpServer.h \
	applications/httptools/HttpServerBase.h \
	applications/httptools/HttpServerEvilA.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/uint128.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpServerEvilB.o: applications/httptools/HttpServerEvilB.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpNodeBase.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpServer.h \
	applications/httptools/HttpServerBase.h \
	applications/httptools/HttpServerEvilB.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/uint128.h \
	world/httptools/HttpController.h
$O/applications/httptools/HttpUtils.o: applications/httptools/HttpUtils.cc \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpUtils.h
$O/applications/pingapp/PingApp.o: applications/pingapp/PingApp.cc \
	applications/pingapp/PingApp.h \
	applications/pingapp/PingPayload_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	util/uint128.h
$O/applications/pingapp/PingPayload_m.o: applications/pingapp/PingPayload_m.cc \
	applications/pingapp/PingPayload_m.h \
	base/INETDefs.h
$O/applications/pingapp/PingTestApp.o: applications/pingapp/PingTestApp.cc \
	applications/pingapp/PingPayload_m.h \
	applications/pingapp/PingTestApp.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	util/uint128.h
$O/applications/rtpapp/RTPApplication.o: applications/rtpapp/RTPApplication.cc \
	applications/rtpapp/RTPApplication.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/rtp/RTPInterfacePacket_m.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h \
	util/uint128.h
$O/applications/sctpapp/SCTPClient.o: applications/sctpapp/SCTPClient.cc \
	applications/sctpapp/SCTPClient.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/SCTPSocket.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/applications/sctpapp/SCTPPeer.o: applications/sctpapp/SCTPPeer.cc \
	applications/sctpapp/SCTPPeer.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/SCTPSocket.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/applications/sctpapp/SCTPServer.o: applications/sctpapp/SCTPServer.cc \
	applications/sctpapp/SCTPServer.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/SCTPSocket.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/applications/tcpapp/GenericAppMsg_m.o: applications/tcpapp/GenericAppMsg_m.cc \
	applications/tcpapp/GenericAppMsg_m.h \
	base/INETDefs.h
$O/applications/tcpapp/TCPBasicClientApp.o: applications/tcpapp/TCPBasicClientApp.cc \
	applications/tcpapp/TCPBasicClientApp.h \
	applications/tcpapp/TCPGenericCliAppBase.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	util/uint128.h
$O/applications/tcpapp/TCPEchoApp.o: applications/tcpapp/TCPEchoApp.cc \
	applications/tcpapp/TCPEchoApp.h \
	base/ByteArray.h \
	base/ByteArrayMessage.h \
	base/ByteArrayMessage_m.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	util/uint128.h
$O/applications/tcpapp/TCPGenericCliAppBase.o: applications/tcpapp/TCPGenericCliAppBase.cc \
	applications/tcpapp/GenericAppMsg_m.h \
	applications/tcpapp/TCPGenericCliAppBase.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	util/uint128.h
$O/applications/tcpapp/TCPGenericSrvApp.o: applications/tcpapp/TCPGenericSrvApp.cc \
	applications/tcpapp/GenericAppMsg_m.h \
	applications/tcpapp/TCPGenericSrvApp.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	util/uint128.h
$O/applications/tcpapp/TCPGenericSrvThread.o: applications/tcpapp/TCPGenericSrvThread.cc \
	applications/tcpapp/GenericAppMsg_m.h \
	applications/tcpapp/TCPGenericSrvThread.h \
	applications/tcpapp/TCPSrvHostApp.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/uint128.h
$O/applications/tcpapp/TCPSessionApp.o: applications/tcpapp/TCPSessionApp.cc \
	applications/tcpapp/GenericAppMsg_m.h \
	applications/tcpapp/TCPSessionApp.h \
	base/ByteArray.h \
	base/ByteArrayMessage.h \
	base/ByteArrayMessage_m.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	util/uint128.h
$O/applications/tcpapp/TCPSinkApp.o: applications/tcpapp/TCPSinkApp.cc \
	applications/tcpapp/TCPSinkApp.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	util/uint128.h
$O/applications/tcpapp/TCPSrvHostApp.o: applications/tcpapp/TCPSrvHostApp.cc \
	applications/tcpapp/TCPSrvHostApp.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/uint128.h
$O/applications/tcpapp/TelnetApp.o: applications/tcpapp/TelnetApp.cc \
	applications/tcpapp/TCPGenericCliAppBase.h \
	applications/tcpapp/TelnetApp.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	util/uint128.h
$O/applications/traci/TraCIDemo.o: applications/traci/TraCIDemo.cc \
	applications/traci/TraCIDemo.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/TraCIMobility.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	util/FWMath.h \
	util/uint128.h \
	world/traci/TraCIScenarioManager.h
$O/applications/traci/TraCITestApp.o: applications/traci/TraCITestApp.cc \
	applications/traci/TraCITestApp.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/TraCIMobility.h \
	util/FWMath.h \
	world/traci/TraCIScenarioManager.h
$O/applications/udpapp/UDPBasicApp.o: applications/udpapp/UDPBasicApp.cc \
	applications/udpapp/UDPBasicApp.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/applications/udpapp/UDPBasicBurst.o: applications/udpapp/UDPBasicBurst.cc \
	applications/udpapp/UDPBasicBurst.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/applications/udpapp/UDPEchoApp.o: applications/udpapp/UDPEchoApp.cc \
	applications/udpapp/UDPEchoApp.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/applications/udpapp/UDPSink.o: applications/udpapp/UDPSink.cc \
	applications/udpapp/UDPSink.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/manetrouting/VCap/puMode.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/applications/udpapp/UDPVideoStreamCli.o: applications/udpapp/UDPVideoStreamCli.cc \
	applications/udpapp/UDPVideoStreamCli.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/applications/udpapp/UDPVideoStreamSvr.o: applications/udpapp/UDPVideoStreamSvr.cc \
	applications/udpapp/UDPVideoStreamSvr.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/base/AbstractQueue.o: base/AbstractQueue.cc \
	base/AbstractQueue.h \
	base/INETDefs.h
$O/base/BasicModule.o: base/BasicModule.cc \
	base/BasicModule.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h
$O/base/ByteArray.o: base/ByteArray.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h
$O/base/ByteArrayBuffer.o: base/ByteArrayBuffer.cc \
	base/ByteArray.h \
	base/ByteArrayBuffer.h \
	base/ByteArray_m.h \
	base/INETDefs.h
$O/base/ByteArrayMessage.o: base/ByteArrayMessage.cc \
	base/ByteArray.h \
	base/ByteArrayMessage.h \
	base/ByteArrayMessage_m.h \
	base/ByteArray_m.h \
	base/INETDefs.h
$O/base/ByteArrayMessage_m.o: base/ByteArrayMessage_m.cc \
	base/ByteArray.h \
	base/ByteArrayMessage_m.h \
	base/ByteArray_m.h \
	base/INETDefs.h
$O/base/ByteArray_m.o: base/ByteArray_m.cc \
	base/ByteArray_m.h \
	base/INETDefs.h
$O/base/Coord.o: base/Coord.cc \
	base/Coord.h \
	base/INETDefs.h \
	util/FWMath.h
$O/base/Join.o: base/Join.cc \
	base/INETDefs.h
$O/base/ModuleAccess.o: base/ModuleAccess.cc \
	base/INETDefs.h \
	base/ModuleAccess.h
$O/base/NedFunctions.o: base/NedFunctions.cc \
	base/INETDefs.h
$O/base/NotificationBoard.o: base/NotificationBoard.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h
$O/base/NotifierConsts.o: base/NotifierConsts.cc \
	base/INETDefs.h \
	base/NotifierConsts.h
$O/base/PassiveQueueBase.o: base/PassiveQueueBase.cc \
	base/INETDefs.h \
	base/IPassiveQueue.h \
	base/PassiveQueueBase.h
$O/base/ProtocolMap.o: base/ProtocolMap.cc \
	base/INETDefs.h \
	base/ProtocolMap.h
$O/base/QueueBase.o: base/QueueBase.cc \
	base/AbstractQueue.h \
	base/INETDefs.h \
	base/QueueBase.h
$O/base/QueueWithQoS.o: base/QueueWithQoS.cc \
	base/AbstractQueue.h \
	base/EnqueueHook.h \
	base/INETDefs.h \
	base/QueueWithQoS.h
$O/base/ReassemblyBuffer.o: base/ReassemblyBuffer.cc \
	base/INETDefs.h \
	base/ReassemblyBuffer.h
$O/base/ResultFilters.o: base/ResultFilters.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/ResultFilters.h \
	mobility/IMobility.h \
	util/FWMath.h
$O/base/Sink.o: base/Sink.cc \
	base/INETDefs.h \
	base/Sink.h
$O/base/Topology.o: base/Topology.cc \
	base/INETDefs.h \
	base/Topology.h \
	util/PatternMatcher.h \
	util/stlutils.h
$O/base/UnimplementedModule.o: base/UnimplementedModule.cc \
	base/INETDefs.h \
	base/UnimplementedModule.h
$O/base/WeightedTopology.o: base/WeightedTopology.cc \
	base/INETDefs.h \
	base/WeightedTopology.h
$O/base/erfc.o: base/erfc.cc
$O/battery/models/BasicBattery.o: battery/models/BasicBattery.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	battery/models/BasicBattery.h
$O/battery/models/InetSimpleBattery.o: battery/models/InetSimpleBattery.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	battery/models/BasicBattery.h \
	battery/models/Energy.h \
	battery/models/InetSimpleBattery.h \
	linklayer/contract/RadioState.h
$O/linklayer/contract/Ieee802Ctrl_m.o: linklayer/contract/Ieee802Ctrl_m.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h
$O/linklayer/contract/MACAddress.o: linklayer/contract/MACAddress.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/InterfaceToken.h
$O/linklayer/contract/PhyControlInfo_m.o: linklayer/contract/PhyControlInfo_m.cc \
	base/INETDefs.h \
	linklayer/contract/PhyControlInfo_m.h
$O/linklayer/ethernet/EtherBus.o: linklayer/ethernet/EtherBus.cc \
	base/INETDefs.h \
	linklayer/ethernet/EtherBus.h
$O/linklayer/ethernet/EtherEncap.o: linklayer/ethernet/EtherEncap.cc \
	base/INETDefs.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherEncap.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/Ethernet.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h
$O/linklayer/ethernet/EtherFrameClassifier.o: linklayer/ethernet/EtherFrameClassifier.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrameClassifier.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/Ethernet.h
$O/linklayer/ethernet/EtherFrame_m.o: linklayer/ethernet/EtherFrame_m.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/Ethernet.h
$O/linklayer/ethernet/EtherHub.o: linklayer/ethernet/EtherHub.cc \
	base/INETDefs.h \
	linklayer/ethernet/EtherHub.h
$O/linklayer/ethernet/EtherLLC.o: linklayer/ethernet/EtherLLC.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/EtherLLC.h \
	linklayer/ethernet/Ethernet.h
$O/linklayer/ethernet/EtherMAC.o: linklayer/ethernet/EtherMAC.cc \
	base/INETDefs.h \
	base/IPassiveQueue.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/EtherMAC.h \
	linklayer/ethernet/EtherMACBase.h \
	linklayer/ethernet/Ethernet.h
$O/linklayer/ethernet/EtherMACBase.o: linklayer/ethernet/EtherMACBase.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/EtherMACBase.h \
	linklayer/ethernet/Ethernet.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	util/opp_utils.h
$O/linklayer/ethernet/EtherMACFullDuplex.o: linklayer/ethernet/EtherMACFullDuplex.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/EtherMACBase.h \
	linklayer/ethernet/EtherMACFullDuplex.h \
	linklayer/ethernet/Ethernet.h
$O/linklayer/ethernet/switch/MACRelayUnitBase.o: linklayer/ethernet/switch/MACRelayUnitBase.cc \
	base/INETDefs.h \
	base/IPassiveQueue.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/EtherMACBase.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/ethernet/switch/MACRelayUnitBase.h
$O/linklayer/ethernet/switch/MACRelayUnitNP.o: linklayer/ethernet/switch/MACRelayUnitNP.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/ethernet/switch/MACRelayUnitBase.h \
	linklayer/ethernet/switch/MACRelayUnitNP.h
$O/linklayer/ethernet/switch/MACRelayUnitPP.o: linklayer/ethernet/switch/MACRelayUnitPP.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/ethernet/switch/MACRelayUnitBase.h \
	linklayer/ethernet/switch/MACRelayUnitPP.h
$O/linklayer/ext/ExtFrame_m.o: linklayer/ext/ExtFrame_m.cc \
	linklayer/ext/ExtFrame_m.h
$O/linklayer/ext/ExtInterface.o: linklayer/ext/ExtInterface.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	linklayer/ext/ExtFrame_m.h \
	linklayer/ext/ExtInterface.h \
	linklayer/ext/cSocketRTScheduler.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/ipv4/IPv4Serializer.h \
	util/opp_utils.h
$O/linklayer/ext/cSocketRTScheduler.o: linklayer/ext/cSocketRTScheduler.cc \
	base/INETDefs.h \
	linklayer/ext/ExtFrame_m.h \
	linklayer/ext/cSocketRTScheduler.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/ethernet.h
$O/linklayer/ieee80211/mac/Ieee80211Frame_m.o: linklayer/ieee80211/mac/Ieee80211Frame_m.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h
$O/linklayer/ieee80211/mac/Ieee80211Mac.o: linklayer/ieee80211/mac/Ieee80211Mac.cc \
	base/Coord.h \
	base/FSMA.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/PhyControlInfo_m.h \
	linklayer/contract/RadioState.h \
	linklayer/ieee80211/mac/IQoSClassifier.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211DataRate.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mac/Ieee80211Mac.h \
	linklayer/ieee80211/mac/Ieee80211eClassifier.h \
	linklayer/ieee80211/mac/WifiMode.h \
	linklayer/ieee80211/mac/WirelessMacBase.h \
	linklayer/ieee80211/radio/WifiPreambleType.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio80211aControlInfo_m.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	util/FWMath.h
$O/linklayer/ieee80211/mac/Ieee80211eClassifier.o: linklayer/ieee80211/mac/Ieee80211eClassifier.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/IQoSClassifier.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mac/Ieee80211eClassifier.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/linklayer/ieee80211/mac/WifiMode.o: linklayer/ieee80211/mac/WifiMode.cc \
	base/INETDefs.h \
	linklayer/ieee80211/mac/Ieee80211DataRate.h \
	linklayer/ieee80211/mac/WifiMode.h \
	linklayer/ieee80211/radio/WifiPreambleType.h \
	linklayer/radio/ModulationType.h
$O/linklayer/ieee80211/mac/WirelessMacBase.o: linklayer/ieee80211/mac/WirelessMacBase.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/ieee80211/mac/WirelessMacBase.h
$O/linklayer/ieee80211/mgmt/ETXPacket_m.o: linklayer/ieee80211/mgmt/ETXPacket_m.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mgmt/ETXPacket_m.h
$O/linklayer/ieee80211/mgmt/Ieee80211AgentSTA.o: linklayer/ieee80211/mgmt/Ieee80211AgentSTA.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211AgentSTA.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	linklayer/ieee80211/mgmt/Ieee80211Primitives_m.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h
$O/linklayer/ieee80211/mgmt/Ieee80211Etx.o: linklayer/ieee80211/mgmt/Ieee80211Etx.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/ETXPacket_m.h \
	linklayer/ieee80211/mgmt/Ieee80211Etx.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio80211aControlInfo_m.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	util/uint128.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAP.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAP.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAP.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAPSimplified.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAPSimplified.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPSimplified.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAdhocWithEtx.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAdhocWithEtx.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/ETXPacket_m.h \
	linklayer/ieee80211/mgmt/Ieee80211Etx.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAdhocWithEtx.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	util/uint128.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtBase.o: linklayer/ieee80211/mgmt/Ieee80211MgmtBase.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.o: linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtSTA.o: linklayer/ieee80211/mgmt/Ieee80211MgmtSTA.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/PhyControlInfo_m.h \
	linklayer/contract/RadioState.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtSTA.h \
	linklayer/ieee80211/mgmt/Ieee80211Primitives_m.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio80211aControlInfo_m.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtSTASimplified.o: linklayer/ieee80211/mgmt/Ieee80211MgmtSTASimplified.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtSTASimplified.h
$O/linklayer/ieee80211/mgmt/Ieee80211Primitives_m.o: linklayer/ieee80211/mgmt/Ieee80211Primitives_m.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	linklayer/ieee80211/mgmt/Ieee80211Primitives_m.h
$O/linklayer/ieee80211/radio/BerParseFile.o: linklayer/ieee80211/radio/BerParseFile.cc \
	base/INETDefs.h \
	linklayer/ieee80211/radio/BerParseFile.h
$O/linklayer/ieee80211/radio/Ieee80211RadioModel.o: linklayer/ieee80211/radio/Ieee80211RadioModel.cc \
	base/Coord.h \
	base/INETDefs.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/WifiMode.h \
	linklayer/ieee80211/radio/BerParseFile.h \
	linklayer/ieee80211/radio/Ieee80211RadioModel.h \
	linklayer/ieee80211/radio/WifiPreambleType.h \
	linklayer/ieee80211/radio/errormodel/IErrorModel.h \
	linklayer/ieee80211/radio/errormodel/dsss-error-rate-model.h \
	linklayer/ieee80211/radio/errormodel/nist-error-rate-model.h \
	linklayer/ieee80211/radio/errormodel/yans-error-rate-model.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/SnrList.h \
	util/FWMath.h
$O/linklayer/ieee80211/radio/errormodel/dsss-error-rate-model.o: linklayer/ieee80211/radio/errormodel/dsss-error-rate-model.cc \
	base/INETDefs.h \
	linklayer/ieee80211/radio/errormodel/dsss-error-rate-model.h
$O/linklayer/ieee80211/radio/errormodel/nist-error-rate-model.o: linklayer/ieee80211/radio/errormodel/nist-error-rate-model.cc \
	base/INETDefs.h \
	linklayer/ieee80211/mac/WifiMode.h \
	linklayer/ieee80211/radio/WifiPreambleType.h \
	linklayer/ieee80211/radio/errormodel/IErrorModel.h \
	linklayer/ieee80211/radio/errormodel/dsss-error-rate-model.h \
	linklayer/ieee80211/radio/errormodel/nist-error-rate-model.h \
	linklayer/radio/ModulationType.h
$O/linklayer/ieee80211/radio/errormodel/yans-error-rate-model.o: linklayer/ieee80211/radio/errormodel/yans-error-rate-model.cc \
	base/INETDefs.h \
	linklayer/ieee80211/mac/WifiMode.h \
	linklayer/ieee80211/radio/WifiPreambleType.h \
	linklayer/ieee80211/radio/errormodel/IErrorModel.h \
	linklayer/ieee80211/radio/errormodel/dsss-error-rate-model.h \
	linklayer/ieee80211/radio/errormodel/yans-error-rate-model.h \
	linklayer/radio/ModulationType.h
$O/linklayer/ppp/PPP.o: linklayer/ppp/PPP.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/TxNotifDetails.h \
	linklayer/ppp/PPP.h \
	linklayer/ppp/PPPFrame_m.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	util/opp_utils.h
$O/linklayer/ppp/PPPFrame_m.o: linklayer/ppp/PPPFrame_m.cc \
	base/INETDefs.h \
	linklayer/ppp/PPPFrame_m.h
$O/linklayer/queue/AlgorithmicDropperBase.o: linklayer/queue/AlgorithmicDropperBase.cc \
	base/INETDefs.h \
	linklayer/queue/AlgorithmicDropperBase.h \
	linklayer/queue/IQueueAccess.h
$O/linklayer/queue/DropTailQueue.o: linklayer/queue/DropTailQueue.cc \
	base/INETDefs.h \
	base/IPassiveQueue.h \
	base/PassiveQueueBase.h \
	linklayer/queue/DropTailQueue.h
$O/linklayer/queue/FIFOQueue.o: linklayer/queue/FIFOQueue.cc \
	base/INETDefs.h \
	base/IPassiveQueue.h \
	base/PassiveQueueBase.h \
	linklayer/queue/FIFOQueue.h \
	linklayer/queue/IQueueAccess.h
$O/linklayer/queue/PriorityScheduler.o: linklayer/queue/PriorityScheduler.cc \
	base/INETDefs.h \
	base/IPassiveQueue.h \
	linklayer/queue/PriorityScheduler.h \
	linklayer/queue/SchedulerBase.h
$O/linklayer/queue/REDDropper.o: linklayer/queue/REDDropper.cc \
	base/INETDefs.h \
	linklayer/queue/AlgorithmicDropperBase.h \
	linklayer/queue/IQueueAccess.h \
	linklayer/queue/REDDropper.h \
	util/opp_utils.h
$O/linklayer/queue/SchedulerBase.o: linklayer/queue/SchedulerBase.cc \
	base/INETDefs.h \
	base/IPassiveQueue.h \
	linklayer/queue/SchedulerBase.h
$O/linklayer/queue/ThresholdDropper.o: linklayer/queue/ThresholdDropper.cc \
	base/INETDefs.h \
	linklayer/queue/AlgorithmicDropperBase.h \
	linklayer/queue/IQueueAccess.h \
	linklayer/queue/ThresholdDropper.h
$O/linklayer/queue/WRRScheduler.o: linklayer/queue/WRRScheduler.cc \
	base/INETDefs.h \
	base/IPassiveQueue.h \
	linklayer/queue/SchedulerBase.h \
	linklayer/queue/WRRScheduler.h \
	util/opp_utils.h
$O/linklayer/radio/AirFrame_m.o: linklayer/radio/AirFrame_m.cc \
	base/Coord.h \
	base/INETDefs.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/ModulationType.h \
	util/FWMath.h
$O/linklayer/radio/GenericRadioModel.o: linklayer/radio/GenericRadioModel.cc \
	base/Coord.h \
	base/INETDefs.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/GenericRadioModel.h \
	linklayer/radio/IModulation.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/Modulation.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/SnrList.h \
	util/FWMath.h
$O/linklayer/radio/Modulation.o: linklayer/radio/Modulation.cc \
	base/INETDefs.h \
	linklayer/radio/IModulation.h \
	linklayer/radio/Modulation.h
$O/linklayer/radio/Radio.o: linklayer/radio/Radio.cc \
	base/AbstractQueue.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	base/QueueBase.h \
	base/ReassemblyBuffer.h \
	battery/models/BasicBattery.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/PhyControlInfo_m.h \
	linklayer/contract/RadioState.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/Radio80211aControlInfo_m.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4FragBuf.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/linklayer/radio/Radio80211aControlInfo_m.o: linklayer/radio/Radio80211aControlInfo_m.cc \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio80211aControlInfo_m.h
$O/linklayer/radio/propagation/FreeSpaceModel.o: linklayer/radio/propagation/FreeSpaceModel.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	linklayer/radio/propagation/FreeSpaceModel.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/linklayer/radio/propagation/LogNormalShadowingModel.o: linklayer/radio/propagation/LogNormalShadowingModel.cc \
	base/INETDefs.h \
	linklayer/radio/propagation/FreeSpaceModel.h \
	linklayer/radio/propagation/IReceptionModel.h \
	linklayer/radio/propagation/LogNormalShadowingModel.h \
	util/FWMath.h
$O/linklayer/radio/propagation/NakagamiModel.o: linklayer/radio/propagation/NakagamiModel.cc \
	base/INETDefs.h \
	linklayer/radio/propagation/FreeSpaceModel.h \
	linklayer/radio/propagation/IReceptionModel.h \
	linklayer/radio/propagation/NakagamiModel.h \
	util/FWMath.h
$O/linklayer/radio/propagation/RayleighModel.o: linklayer/radio/propagation/RayleighModel.cc \
	base/INETDefs.h \
	linklayer/radio/propagation/FreeSpaceModel.h \
	linklayer/radio/propagation/IReceptionModel.h \
	linklayer/radio/propagation/RayleighModel.h \
	util/FWMath.h
$O/linklayer/radio/propagation/RiceModel.o: linklayer/radio/propagation/RiceModel.cc \
	base/INETDefs.h \
	linklayer/radio/propagation/FreeSpaceModel.h \
	linklayer/radio/propagation/IReceptionModel.h \
	linklayer/radio/propagation/RiceModel.h \
	util/FWMath.h
$O/linklayer/radio/propagation/TwoRayGroundModel.o: linklayer/radio/propagation/TwoRayGroundModel.cc \
	base/INETDefs.h \
	linklayer/radio/propagation/FreeSpaceModel.h \
	linklayer/radio/propagation/IReceptionModel.h \
	linklayer/radio/propagation/TwoRayGroundModel.h \
	util/FWMath.h
$O/mobility/models/ANSimMobility.o: mobility/models/ANSimMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/ANSimMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/BonnMotionFileCache.o: mobility/models/BonnMotionFileCache.cc \
	base/INETDefs.h \
	mobility/models/BonnMotionFileCache.h
$O/mobility/models/BonnMotionMobility.o: mobility/models/BonnMotionMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/BonnMotionFileCache.h \
	mobility/models/BonnMotionMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/ChiangMobility.o: mobility/models/ChiangMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/ChiangMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/CircleMobility.o: mobility/models/CircleMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/CircleMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/ConstSpeedMobility.o: mobility/models/ConstSpeedMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/ConstSpeedMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/GaussMarkovMobility.o: mobility/models/GaussMarkovMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/GaussMarkovMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/LineSegmentsMobilityBase.o: mobility/models/LineSegmentsMobilityBase.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/LinearMobility.o: mobility/models/LinearMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LinearMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/LinearNodeDistributionMobility.o: mobility/models/LinearNodeDistributionMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LinearNodeDistributionMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/StationaryMobility.h \
	util/FWMath.h
$O/mobility/models/MassMobility.o: mobility/models/MassMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MassMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/MoBANCoordinator.o: mobility/models/MoBANCoordinator.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MoBANCoordinator.h \
	mobility/models/MoBANLocal.h \
	mobility/models/MobilityAccess.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	mobility/models/Posture.h \
	mobility/models/PostureTransition.h \
	util/FWMath.h
$O/mobility/models/MoBANLocal.o: mobility/models/MoBANLocal.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MoBANCoordinator.h \
	mobility/models/MoBANLocal.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	mobility/models/Posture.h \
	mobility/models/PostureTransition.h \
	util/FWMath.h
$O/mobility/models/MobilityAccess.o: mobility/models/MobilityAccess.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	mobility/IMobility.h \
	mobility/models/MobilityAccess.h \
	util/FWMath.h
$O/mobility/models/MobilityBase.o: mobility/models/MobilityBase.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	util/FWMath.h
$O/mobility/models/MovingMobilityBase.o: mobility/models/MovingMobilityBase.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	util/FWMath.h
$O/mobility/models/Ns2MotionMobility.o: mobility/models/Ns2MotionMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	mobility/models/Ns2MotionMobility.h \
	util/FWMath.h
$O/mobility/models/Posture.o: mobility/models/Posture.cc \
	base/Coord.h \
	base/INETDefs.h \
	mobility/models/Posture.h \
	util/FWMath.h
$O/mobility/models/PostureTransition.o: mobility/models/PostureTransition.cc \
	base/Coord.h \
	base/INETDefs.h \
	mobility/models/PostureTransition.h \
	util/FWMath.h
$O/mobility/models/RandomWPMobility.o: mobility/models/RandomWPMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	mobility/models/RandomWPMobility.h \
	util/FWMath.h
$O/mobility/models/RectangleMobility.o: mobility/models/RectangleMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	mobility/models/RectangleMobility.h \
	util/FWMath.h
$O/mobility/models/StaticGridMobility.o: mobility/models/StaticGridMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/StaticGridMobility.h \
	mobility/models/StationaryMobility.h \
	util/FWMath.h
$O/mobility/models/StationaryMobility.o: mobility/models/StationaryMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/StationaryMobility.h \
	util/FWMath.h
$O/mobility/models/TraCIMobility.o: mobility/models/TraCIMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/TraCIMobility.h \
	util/FWMath.h \
	world/traci/TraCIScenarioManager.h
$O/mobility/models/TractorMobility.o: mobility/models/TractorMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	mobility/models/TractorMobility.h \
	util/FWMath.h
$O/mobility/models/TurtleMobility.o: mobility/models/TurtleMobility.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/LineSegmentsMobilityBase.h \
	mobility/models/MobilityBase.h \
	mobility/models/MovingMobilityBase.h \
	mobility/models/TurtleMobility.h \
	util/FWMath.h
$O/networklayer/arp/ARP.o: networklayer/arp/ARP.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/arp/ARPPacket_m.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h
$O/networklayer/arp/ARPPacket_m.o: networklayer/arp/ARPPacket_m.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARPPacket_m.h \
	networklayer/contract/IPv4Address.h
$O/networklayer/autorouting/ipv4/FlatNetworkConfigurator.o: networklayer/autorouting/ipv4/FlatNetworkConfigurator.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/autorouting/ipv4/FlatNetworkConfigurator.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	util/uint128.h
$O/networklayer/autorouting/ipv4/HostAutoConfigurator.o: networklayer/autorouting/ipv4/HostAutoConfigurator.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/autorouting/ipv4/HostAutoConfigurator.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	util/uint128.h
$O/networklayer/autorouting/ipv4/IPv4NetworkConfigurator.o: networklayer/autorouting/ipv4/IPv4NetworkConfigurator.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/Topology.h \
	linklayer/contract/MACAddress.h \
	networklayer/autorouting/ipv4/IPv4NetworkConfigurator.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	util/PatternMatcher.h \
	util/stlutils.h \
	util/uint128.h
$O/networklayer/autorouting/ipv6/FlatNetworkConfigurator6.o: networklayer/autorouting/ipv6/FlatNetworkConfigurator6.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/autorouting/ipv6/FlatNetworkConfigurator6.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/ipv6/RoutingTable6.h \
	util/uint128.h
$O/networklayer/bgpv4/BGPFSM.o: networklayer/bgpv4/BGPFSM.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/bgpv4/BGPCommon.h \
	networklayer/bgpv4/BGPFSM.h \
	networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.h \
	networklayer/bgpv4/BGPMessage/BGPHeader_m.h \
	networklayer/bgpv4/BGPMessage/BGPKeepAlive.h \
	networklayer/bgpv4/BGPMessage/BGPKeepAlive_m.h \
	networklayer/bgpv4/BGPMessage/BGPOpen.h \
	networklayer/bgpv4/BGPMessage/BGPOpen_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate.h \
	networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate_m.h \
	networklayer/bgpv4/BGPRouting.h \
	networklayer/bgpv4/BGPRoutingTableEntry.h \
	networklayer/bgpv4/BGPSession.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFRouting.h \
	networklayer/ospfv2/OSPFRoutingAccess.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/Macho.h \
	util/uint128.h
$O/networklayer/bgpv4/BGPRouting.o: networklayer/bgpv4/BGPRouting.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/bgpv4/BGPCommon.h \
	networklayer/bgpv4/BGPFSM.h \
	networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.h \
	networklayer/bgpv4/BGPMessage/BGPHeader_m.h \
	networklayer/bgpv4/BGPMessage/BGPKeepAlive.h \
	networklayer/bgpv4/BGPMessage/BGPKeepAlive_m.h \
	networklayer/bgpv4/BGPMessage/BGPOpen.h \
	networklayer/bgpv4/BGPMessage/BGPOpen_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate.h \
	networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate_m.h \
	networklayer/bgpv4/BGPRouting.h \
	networklayer/bgpv4/BGPRoutingTableEntry.h \
	networklayer/bgpv4/BGPSession.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFRouting.h \
	networklayer/ospfv2/OSPFRoutingAccess.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/Macho.h \
	util/uint128.h
$O/networklayer/bgpv4/BGPSession.o: networklayer/bgpv4/BGPSession.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/bgpv4/BGPCommon.h \
	networklayer/bgpv4/BGPFSM.h \
	networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.h \
	networklayer/bgpv4/BGPMessage/BGPHeader_m.h \
	networklayer/bgpv4/BGPMessage/BGPKeepAlive.h \
	networklayer/bgpv4/BGPMessage/BGPKeepAlive_m.h \
	networklayer/bgpv4/BGPMessage/BGPOpen.h \
	networklayer/bgpv4/BGPMessage/BGPOpen_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate.h \
	networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate_m.h \
	networklayer/bgpv4/BGPRouting.h \
	networklayer/bgpv4/BGPRoutingTableEntry.h \
	networklayer/bgpv4/BGPSession.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFRouting.h \
	networklayer/ospfv2/OSPFRoutingAccess.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/Macho.h \
	util/uint128.h
$O/networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.o: networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.cc \
	networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.h
$O/networklayer/bgpv4/BGPMessage/BGPHeader_m.o: networklayer/bgpv4/BGPMessage/BGPHeader_m.cc \
	networklayer/bgpv4/BGPMessage/BGPHeader_m.h
$O/networklayer/bgpv4/BGPMessage/BGPKeepAlive_m.o: networklayer/bgpv4/BGPMessage/BGPKeepAlive_m.cc \
	networklayer/bgpv4/BGPMessage/BGPHeader_m.h \
	networklayer/bgpv4/BGPMessage/BGPKeepAlive_m.h
$O/networklayer/bgpv4/BGPMessage/BGPOpen_m.o: networklayer/bgpv4/BGPMessage/BGPOpen_m.cc \
	base/INETDefs.h \
	networklayer/bgpv4/BGPMessage/BGPHeader_m.h \
	networklayer/bgpv4/BGPMessage/BGPOpen_m.h \
	networklayer/contract/IPv4Address.h
$O/networklayer/bgpv4/BGPMessage/BGPUpdate.o: networklayer/bgpv4/BGPMessage/BGPUpdate.cc \
	base/INETDefs.h \
	networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.h \
	networklayer/bgpv4/BGPMessage/BGPHeader_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate.h \
	networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate_m.h \
	networklayer/contract/IPv4Address.h
$O/networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.o: networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.cc \
	base/INETDefs.h \
	networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.h \
	networklayer/contract/IPv4Address.h
$O/networklayer/bgpv4/BGPMessage/BGPUpdate_m.o: networklayer/bgpv4/BGPMessage/BGPUpdate_m.cc \
	base/INETDefs.h \
	networklayer/bgpv4/BGPMessage/BGPASPathSegment_m.h \
	networklayer/bgpv4/BGPMessage/BGPHeader_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdatePathAttributes_m.h \
	networklayer/bgpv4/BGPMessage/BGPUpdate_m.h \
	networklayer/contract/IPv4Address.h
$O/networklayer/common/InterfaceEntry.o: networklayer/common/InterfaceEntry.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	util/uint128.h
$O/networklayer/common/InterfaceTable.o: networklayer/common/InterfaceTable.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	util/uint128.h
$O/networklayer/contract/IPProtocolId_m.o: networklayer/contract/IPProtocolId_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h
$O/networklayer/contract/IPv4Address.o: networklayer/contract/IPv4Address.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h
$O/networklayer/contract/IPv4ControlInfo.o: networklayer/contract/IPv4ControlInfo.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h
$O/networklayer/contract/IPv4ControlInfo_m.o: networklayer/contract/IPv4ControlInfo_m.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo_m.h
$O/networklayer/contract/IPv6Address.o: networklayer/contract/IPv6Address.cc \
	base/INETDefs.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv6Address.h \
	util/uint128.h
$O/networklayer/contract/IPv6ControlInfo.o: networklayer/contract/IPv6ControlInfo.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	util/uint128.h
$O/networklayer/contract/IPv6ControlInfo_m.o: networklayer/contract/IPv6ControlInfo_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	util/uint128.h
$O/networklayer/contract/IPvXAddress.o: networklayer/contract/IPvXAddress.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	util/uint128.h
$O/networklayer/contract/IPvXAddressResolver.o: networklayer/contract/IPvXAddressResolver.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/ipv6/RoutingTable6.h \
	util/uint128.h
$O/networklayer/diffserv/BehaviorAggregateClassifier.o: networklayer/diffserv/BehaviorAggregateClassifier.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/diffserv/BehaviorAggregateClassifier.h \
	networklayer/diffserv/DiffservUtil.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/diffserv/DSCPMarker.o: networklayer/diffserv/DSCPMarker.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/diffserv/DSCPMarker.h \
	networklayer/diffserv/DSCP_m.h \
	networklayer/diffserv/DiffservUtil.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	util/uint128.h
$O/networklayer/diffserv/DSCP_m.o: networklayer/diffserv/DSCP_m.cc \
	base/INETDefs.h \
	networklayer/diffserv/DSCP_m.h
$O/networklayer/diffserv/DiffservUtil.o: networklayer/diffserv/DiffservUtil.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/diffserv/DSCP_m.h \
	networklayer/diffserv/DiffservUtil.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	util/opp_utils.h \
	util/uint128.h
$O/networklayer/diffserv/MultiFieldClassifier.o: networklayer/diffserv/MultiFieldClassifier.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/diffserv/DiffservUtil.h \
	networklayer/diffserv/MultiFieldClassifier.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/diffserv/SingleRateThreeColorMeter.o: networklayer/diffserv/SingleRateThreeColorMeter.cc \
	base/INETDefs.h \
	networklayer/diffserv/DiffservUtil.h \
	networklayer/diffserv/SingleRateThreeColorMeter.h
$O/networklayer/diffserv/TokenBucketMeter.o: networklayer/diffserv/TokenBucketMeter.cc \
	base/INETDefs.h \
	networklayer/diffserv/DiffservUtil.h \
	networklayer/diffserv/TokenBucketMeter.h
$O/networklayer/diffserv/TwoRateThreeColorMeter.o: networklayer/diffserv/TwoRateThreeColorMeter.cc \
	base/INETDefs.h \
	networklayer/diffserv/DiffservUtil.h \
	networklayer/diffserv/TwoRateThreeColorMeter.h
$O/networklayer/extras/Dummy.o: networklayer/extras/Dummy.cc \
	base/INETDefs.h
$O/networklayer/extras/FailureManager.o: networklayer/extras/FailureManager.cc \
	base/INETDefs.h \
	base/IScriptable.h \
	networklayer/extras/FailureManager.h
$O/networklayer/icmpv6/ICMPv6.o: networklayer/icmpv6/ICMPv6.cc \
	applications/pingapp/PingPayload_m.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	util/uint128.h
$O/networklayer/icmpv6/ICMPv6Message_m.o: networklayer/icmpv6/ICMPv6Message_m.cc \
	base/INETDefs.h \
	networklayer/icmpv6/ICMPv6Message_m.h
$O/networklayer/icmpv6/IPv6NDMessage_m.o: networklayer/icmpv6/IPv6NDMessage_m.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/icmpv6/IPv6NDMessage_m.h \
	util/uint128.h
$O/networklayer/icmpv6/IPv6NeighbourCache.o: networklayer/icmpv6/IPv6NeighbourCache.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/icmpv6/IPv6NeighbourCache.h \
	util/uint128.h
$O/networklayer/icmpv6/IPv6NeighbourDiscovery.o: networklayer/icmpv6/IPv6NeighbourDiscovery.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/icmpv6/ICMPv6Access.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/icmpv6/IPv6NDMessage_m.h \
	networklayer/icmpv6/IPv6NeighbourCache.h \
	networklayer/icmpv6/IPv6NeighbourDiscovery.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/ipv6tunneling/IPv6Tunneling.h \
	networklayer/xmipv6/BindingUpdateList.h \
	networklayer/xmipv6/MobilityHeader.h \
	networklayer/xmipv6/MobilityHeader_m.h \
	networklayer/xmipv6/xMIPv6.h \
	networklayer/xmipv6/xMIPv6Access.h \
	util/uint128.h
$O/networklayer/ipv4/ErrorHandling.o: networklayer/ipv4/ErrorHandling.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/ErrorHandling.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h
$O/networklayer/ipv4/ICMP.o: networklayer/ipv4/ICMP.cc \
	applications/pingapp/PingPayload_m.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h
$O/networklayer/ipv4/ICMPMessage_m.o: networklayer/ipv4/ICMPMessage_m.cc \
	base/INETDefs.h \
	networklayer/ipv4/ICMPMessage_m.h
$O/networklayer/ipv4/IGMPMessage_m.o: networklayer/ipv4/IGMPMessage_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IGMPMessage_m.h
$O/networklayer/ipv4/IGMPv2.o: networklayer/ipv4/IGMPv2.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/IGMPMessage_m.h \
	networklayer/ipv4/IGMPv2.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h
$O/networklayer/ipv4/IPv4.o: networklayer/ipv4/IPv4.cc \
	base/AbstractQueue.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	base/QueueBase.h \
	base/ReassemblyBuffer.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/Radio80211aControlInfo_m.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/arp/ARPPacket_m.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4FragBuf.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/ipv4/IPv4Datagram_m.o: networklayer/ipv4/IPv4Datagram_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4Datagram_m.h
$O/networklayer/ipv4/IPv4FragBuf.o: networklayer/ipv4/IPv4FragBuf.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/ReassemblyBuffer.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4FragBuf.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h
$O/networklayer/ipv4/IPv4InterfaceData.o: networklayer/ipv4/IPv4InterfaceData.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4InterfaceData.h
$O/networklayer/ipv4/IPv4Route.o: networklayer/ipv4/IPv4Route.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h
$O/networklayer/ipv4/NetworkInfo.o: networklayer/ipv4/NetworkInfo.cc \
	base/INETDefs.h \
	base/IScriptable.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/NetworkInfo.h \
	util/uint128.h
$O/networklayer/ipv4/RoutingTable.o: networklayer/ipv4/RoutingTable.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableParser.h
$O/networklayer/ipv4/RoutingTableParser.o: networklayer/ipv4/RoutingTableParser.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableParser.h
$O/networklayer/ipv4/RoutingTableRecorder.o: networklayer/ipv4/RoutingTableRecorder.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableRecorder.h
$O/networklayer/ipv6/IPv6.o: networklayer/ipv6/IPv6.cc \
	base/AbstractQueue.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	base/QueueBase.h \
	base/ReassemblyBuffer.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/icmpv6/ICMPv6Access.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/icmpv6/IPv6NDMessage_m.h \
	networklayer/icmpv6/IPv6NeighbourCache.h \
	networklayer/icmpv6/IPv6NeighbourDiscovery.h \
	networklayer/icmpv6/IPv6NeighbourDiscoveryAccess.h \
	networklayer/ipv6/IPv6.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	networklayer/ipv6/IPv6FragBuf.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/ipv6tunneling/IPv6Tunneling.h \
	networklayer/ipv6tunneling/IPv6TunnelingAccess.h \
	networklayer/xmipv6/MobilityHeader.h \
	networklayer/xmipv6/MobilityHeader_m.h \
	util/uint128.h
$O/networklayer/ipv6/IPv6Datagram.o: networklayer/ipv6/IPv6Datagram.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	util/uint128.h
$O/networklayer/ipv6/IPv6Datagram_m.o: networklayer/ipv6/IPv6Datagram_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	util/uint128.h
$O/networklayer/ipv6/IPv6ErrorHandling.o: networklayer/ipv6/IPv6ErrorHandling.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ErrorHandling.h \
	util/uint128.h
$O/networklayer/ipv6/IPv6ExtensionHeaders.o: networklayer/ipv6/IPv6ExtensionHeaders.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	util/uint128.h
$O/networklayer/ipv6/IPv6ExtensionHeaders_m.o: networklayer/ipv6/IPv6ExtensionHeaders_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	util/uint128.h
$O/networklayer/ipv6/IPv6FragBuf.o: networklayer/ipv6/IPv6FragBuf.cc \
	base/INETDefs.h \
	base/ReassemblyBuffer.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	networklayer/ipv6/IPv6FragBuf.h \
	util/uint128.h
$O/networklayer/ipv6/IPv6InterfaceData.o: networklayer/ipv6/IPv6InterfaceData.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6/RoutingTable6Access.h \
	util/uint128.h
$O/networklayer/ipv6/RoutingTable6.o: networklayer/ipv6/RoutingTable6.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6tunneling/IPv6Tunneling.h \
	networklayer/ipv6tunneling/IPv6TunnelingAccess.h \
	util/opp_utils.h \
	util/uint128.h
$O/networklayer/ipv6tunneling/IPv6Tunneling.o: networklayer/ipv6tunneling/IPv6Tunneling.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/ipv6tunneling/IPv6Tunneling.h \
	networklayer/xmipv6/BindingUpdateList.h \
	networklayer/xmipv6/MobilityHeader.h \
	networklayer/xmipv6/MobilityHeader_m.h \
	networklayer/xmipv6/xMIPv6.h \
	networklayer/xmipv6/xMIPv6Access.h \
	util/uint128.h
$O/networklayer/ldp/LDP.o: networklayer/ldp/LDP.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ldp/LDP.h \
	networklayer/ldp/LDPPacket_m.h \
	networklayer/mpls/ConstType.h \
	networklayer/mpls/IClassifier.h \
	networklayer/mpls/LIBTable.h \
	networklayer/mpls/LIBTableAccess.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/ted/TED.h \
	networklayer/ted/TEDAccess.h \
	networklayer/ted/TED_m.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/ldp/LDPPacket_m.o: networklayer/ldp/LDPPacket_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ldp/LDPPacket_m.h
$O/networklayer/manetrouting/GPS/GPS.o: networklayer/manetrouting/GPS/GPS.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/GPS/GPS.h \
	networklayer/manetrouting/GPS/Position.h \
	networklayer/manetrouting/GPS/msgNeighbor.h \
	networklayer/manetrouting/GPS/msgNeighbor_m.h \
	networklayer/manetrouting/GPS/msgRouting_m.h \
	networklayer/manetrouting/VCap/Position.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/FWMath.h \
	util/uint128.h
$O/networklayer/manetrouting/GPS/msgNeighbor_m.o: networklayer/manetrouting/GPS/msgNeighbor_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/GPS/msgNeighbor_m.h
$O/networklayer/manetrouting/GPS/msgRouting_m.o: networklayer/manetrouting/GPS/msgRouting_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/GPS/Position.h \
	networklayer/manetrouting/GPS/msgRouting_m.h \
	networklayer/manetrouting/VCap/Position.h
$O/networklayer/manetrouting/VCap/VCap.o: networklayer/manetrouting/VCap/VCap.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/manetrouting/VCap/VNeighborTable.o: networklayer/manetrouting/VCap/VNeighborTable.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	linklayer/contract/MACAddress.h \
	mobility/IMobility.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/manetrouting/VCap/VNeighborTable.h \
	util/FWMath.h
$O/networklayer/manetrouting/VCap/msgNeighborDisc_m.o: networklayer/manetrouting/VCap/msgNeighborDisc_m.cc \
	base/Coord.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	util/FWMath.h
$O/networklayer/manetrouting/VCap/msgReq_m.o: networklayer/manetrouting/VCap/msgReq_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/VCap/msgReq_m.h
$O/networklayer/manetrouting/VCap/msgToRoute_m.o: networklayer/manetrouting/VCap/msgToRoute_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/puMode.h
$O/networklayer/manetrouting/VCap/msgW_m.o: networklayer/manetrouting/VCap/msgW_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/VCap/msgW_m.h
$O/networklayer/manetrouting/aodv/aodv_msg_struct.o: networklayer/manetrouting/aodv/aodv_msg_struct.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/base/compatibility.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv_msg_struct_descriptor.o: networklayer/manetrouting/aodv/aodv_msg_struct_descriptor.cc \
	base/INETDefs.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv_uu_omnet.o: networklayer/manetrouting/aodv/aodv_uu_omnet.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/packet_queue_omnet.o: networklayer/manetrouting/aodv/packet_queue_omnet.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/aodv_hello.o: networklayer/manetrouting/aodv/aodv-uu/aodv_hello.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.o: networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.o: networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.o: networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.o: networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/aodv_socket.o: networklayer/manetrouting/aodv/aodv-uu/aodv_socket.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.o: networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/debug_aodv.o: networklayer/manetrouting/aodv/aodv-uu/debug_aodv.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/list.o: networklayer/manetrouting/aodv/aodv-uu/list.cc \
	networklayer/manetrouting/aodv/aodv-uu/list.h
$O/networklayer/manetrouting/aodv/aodv-uu/locality.o: networklayer/manetrouting/aodv/aodv-uu/locality.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/routing_table.o: networklayer/manetrouting/aodv/aodv-uu/routing_table.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/seek_list.o: networklayer/manetrouting/aodv/aodv-uu/seek_list.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.o: networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_hello.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_neighbor.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rerr.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rrep.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_rreq.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_socket.h \
	networklayer/manetrouting/aodv/aodv-uu/aodv_timeout.h \
	networklayer/manetrouting/aodv/aodv-uu/debug_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/defs_aodv.h \
	networklayer/manetrouting/aodv/aodv-uu/list.h \
	networklayer/manetrouting/aodv/aodv-uu/locality.h \
	networklayer/manetrouting/aodv/aodv-uu/params.h \
	networklayer/manetrouting/aodv/aodv-uu/routing_table.h \
	networklayer/manetrouting/aodv/aodv-uu/seek_list.h \
	networklayer/manetrouting/aodv/aodv-uu/timer_queue_aodv.h \
	networklayer/manetrouting/aodv/aodv_msg_struct.h \
	networklayer/manetrouting/aodv/aodv_uu_omnet.h \
	networklayer/manetrouting/aodv/packet_queue_omnet.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	util/uint128.h
$O/networklayer/manetrouting/base/ControlInfoBreakLink_m.o: networklayer/manetrouting/base/ControlInfoBreakLink_m.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/manetrouting/base/ControlInfoBreakLink_m.h
$O/networklayer/manetrouting/base/ControlManetRouting_m.o: networklayer/manetrouting/base/ControlManetRouting_m.cc \
	base/INETDefs.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	util/uint128.h
$O/networklayer/manetrouting/base/ManetRoutingBase.o: networklayer/manetrouting/base/ManetRoutingBase.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IPassiveQueue.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/PassiveQueueBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAP.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlInfoBreakLink_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/FWMath.h \
	util/uint128.h
$O/networklayer/manetrouting/base/MeshControlInfo_m.o: networklayer/manetrouting/base/MeshControlInfo_m.cc \
	base/INETDefs.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/manetrouting/base/MeshControlInfo_m.h \
	util/uint128.h
$O/networklayer/manetrouting/batman/BatmanData.o: networklayer/manetrouting/batman/BatmanData.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/batman/BatmanData.h \
	networklayer/manetrouting/batman/BatmanMsg_m.h \
	networklayer/manetrouting/batman/batman.h \
	util/uint128.h
$O/networklayer/manetrouting/batman/BatmanMain.o: networklayer/manetrouting/batman/BatmanMain.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/batman/BatmanData.h \
	networklayer/manetrouting/batman/BatmanMsg_m.h \
	networklayer/manetrouting/batman/batman.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/manetrouting/batman/BatmanMsg_m.o: networklayer/manetrouting/batman/BatmanMsg_m.cc \
	base/INETDefs.h \
	networklayer/manetrouting/batman/BatmanMsg_m.h \
	util/uint128.h
$O/networklayer/manetrouting/batman/batmanHna.o: networklayer/manetrouting/batman/batmanHna.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/batman/BatmanData.h \
	networklayer/manetrouting/batman/BatmanMsg_m.h \
	networklayer/manetrouting/batman/batman.h \
	util/uint128.h
$O/networklayer/manetrouting/berger/BergerNeighborInfo.o: networklayer/manetrouting/berger/BergerNeighborInfo.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/berger/BergerNeighborInfo.h \
	networklayer/manetrouting/berger/BergerNeighborInfo_m.h
$O/networklayer/manetrouting/berger/BergerNeighborInfo_m.o: networklayer/manetrouting/berger/BergerNeighborInfo_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/berger/BergerNeighborInfo_m.h
$O/networklayer/manetrouting/berger/BergerRouteRequest_m.o: networklayer/manetrouting/berger/BergerRouteRequest_m.cc \
	base/Coord.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/berger/BergerRouteRequest_m.h \
	util/FWMath.h
$O/networklayer/manetrouting/berger/berger.o: networklayer/manetrouting/berger/berger.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/berger/BergerNeighborInfo.h \
	networklayer/manetrouting/berger/BergerNeighborInfo_m.h \
	networklayer/manetrouting/berger/BergerRouteRequest_m.h \
	networklayer/manetrouting/berger/berger.h \
	util/FWMath.h \
	util/uint128.h
$O/networklayer/manetrouting/dsdv/DSDV_2.o: networklayer/manetrouting/dsdv/DSDV_2.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/dsdv/DSDV_2.h \
	networklayer/manetrouting/dsdv/DSDVhello_m.h
$O/networklayer/manetrouting/dsdv/DSDVhello_m.o: networklayer/manetrouting/dsdv/DSDVhello_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/dsdv/DSDVhello_m.h
$O/networklayer/manetrouting/dsr/dsr-pkt_omnet.o: networklayer/manetrouting/dsr/dsr-pkt_omnet.cc \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h
$O/networklayer/manetrouting/dsr/dsr-uu-omnetpp.o: networklayer/manetrouting/dsr/dsr-uu-omnetpp.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/dsr-ack.o: networklayer/manetrouting/dsr/dsr-uu/dsr-ack.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/dsr-io.o: networklayer/manetrouting/dsr/dsr-uu/dsr-io.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rtc.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/dsr-opt.o: networklayer/manetrouting/dsr/dsr-uu/dsr-opt.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.o: networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.o: networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.o: networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.o: networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/dsr-srt.o: networklayer/manetrouting/dsr/dsr-uu/dsr-srt.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/link-cache.o: networklayer/manetrouting/dsr/dsr-uu/link-cache.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rtc.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/maint-buf.o: networklayer/manetrouting/dsr/dsr-uu/maint-buf.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/neigh.o: networklayer/manetrouting/dsr/dsr-uu/neigh.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/path-cache.o: networklayer/manetrouting/dsr/dsr-uu/path-cache.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rtc.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dsr/dsr-uu/send-buf.o: networklayer/manetrouting/dsr/dsr-uu/send-buf.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/compatibility_dsr.h \
	networklayer/manetrouting/dsr/dsr-pkt_omnet.h \
	networklayer/manetrouting/dsr/dsr-uu-omnetpp.h \
	networklayer/manetrouting/dsr/dsr-uu/debug_dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-ack.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-io.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-opt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-pkt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rerr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rrep.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-rreq.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr-srt.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr.h \
	networklayer/manetrouting/dsr/dsr-uu/dsr_list.h \
	networklayer/manetrouting/dsr/dsr-uu/link-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/maint-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/neigh.h \
	networklayer/manetrouting/dsr/dsr-uu/path-cache.h \
	networklayer/manetrouting/dsr/dsr-uu/send-buf.h \
	networklayer/manetrouting/dsr/dsr-uu/tbl.h \
	networklayer/manetrouting/dsr/dsr-uu/timer.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymo_msg_struct.o: networklayer/manetrouting/dymo/dymo_msg_struct.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymo_packet_queue_omnet.o: networklayer/manetrouting/dymo/dymo_packet_queue_omnet.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymo_um_omnet.o: networklayer/manetrouting/dymo/dymo_um_omnet.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/blacklist.o: networklayer/manetrouting/dymo/dymoum/blacklist.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/debug_dymo.o: networklayer/manetrouting/dymo/dymoum/debug_dymo.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/dymo_generic.o: networklayer/manetrouting/dymo/dymoum/dymo_generic.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/dymo_hello.o: networklayer/manetrouting/dymo/dymoum/dymo_hello.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/dymo_nb.o: networklayer/manetrouting/dymo/dymoum/dymo_nb.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/dymo_re.o: networklayer/manetrouting/dymo/dymoum/dymo_re.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/MeshControlInfo_m.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/dymo_rerr.o: networklayer/manetrouting/dymo/dymoum/dymo_rerr.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/dymo_socket.o: networklayer/manetrouting/dymo/dymoum/dymo_socket.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/dymo_timeout.o: networklayer/manetrouting/dymo/dymoum/dymo_timeout.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/dymo_uerr.o: networklayer/manetrouting/dymo/dymoum/dymo_uerr.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/icmp_socket.o: networklayer/manetrouting/dymo/dymoum/icmp_socket.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/pending_rreq.o: networklayer/manetrouting/dymo/dymoum/pending_rreq.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/rtable.o: networklayer/manetrouting/dymo/dymoum/rtable.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo/dymoum/timer_queue.o: networklayer/manetrouting/dymo/dymoum/timer_queue.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo/dymo_msg_struct.h \
	networklayer/manetrouting/dymo/dymo_packet_queue_omnet.h \
	networklayer/manetrouting/dymo/dymo_um_omnet.h \
	networklayer/manetrouting/dymo/dymoum/blacklist.h \
	networklayer/manetrouting/dymo/dymoum/debug_dymo.h \
	networklayer/manetrouting/dymo/dymoum/defs_dymo.h \
	networklayer/manetrouting/dymo/dymoum/dlist.h \
	networklayer/manetrouting/dymo/dymoum/dymo_generic.h \
	networklayer/manetrouting/dymo/dymoum/dymo_hello.h \
	networklayer/manetrouting/dymo/dymoum/dymo_nb.h \
	networklayer/manetrouting/dymo/dymoum/dymo_re.h \
	networklayer/manetrouting/dymo/dymoum/dymo_rerr.h \
	networklayer/manetrouting/dymo/dymoum/dymo_socket.h \
	networklayer/manetrouting/dymo/dymoum/dymo_timeout.h \
	networklayer/manetrouting/dymo/dymoum/dymo_uerr.h \
	networklayer/manetrouting/dymo/dymoum/icmp_socket.h \
	networklayer/manetrouting/dymo/dymoum/pending_rreq.h \
	networklayer/manetrouting/dymo/dymoum/rtable.h \
	networklayer/manetrouting/dymo/dymoum/timer_queue.h \
	util/uint128.h
$O/networklayer/manetrouting/dymo_fau/DYMO.o: networklayer/manetrouting/dymo_fau/DYMO.cc \
	base/AbstractQueue.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	base/QueueBase.h \
	base/ReassemblyBuffer.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4FragBuf.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo_fau/DYMO.h \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_DataQueue.h \
	networklayer/manetrouting/dymo_fau/DYMO_OutstandingRREQList.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Packet_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREP_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREQ_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RoutingEntry.h \
	networklayer/manetrouting/dymo_fau/DYMO_RoutingTable.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timer.h \
	networklayer/manetrouting/dymo_fau/DYMO_TokenBucket.h \
	networklayer/manetrouting/dymo_fau/DYMO_UERR_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/manetrouting/dymo_fau/DYMO_DataQueue.o: networklayer/manetrouting/dymo_fau/DYMO_DataQueue.cc \
	base/AbstractQueue.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	base/QueueBase.h \
	base/ReassemblyBuffer.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4FragBuf.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo_fau/DYMO_DataQueue.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/manetrouting/dymo_fau/DYMO_OutstandingRREQList.o: networklayer/manetrouting/dymo_fau/DYMO_OutstandingRREQList.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/dymo_fau/DYMO_OutstandingRREQList.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timer.h
$O/networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.o: networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.cc \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h
$O/networklayer/manetrouting/dymo_fau/DYMO_Packet_m.o: networklayer/manetrouting/dymo_fau/DYMO_Packet_m.cc \
	networklayer/manetrouting/dymo_fau/DYMO_Packet_m.h
$O/networklayer/manetrouting/dymo_fau/DYMO_RERR_m.o: networklayer/manetrouting/dymo_fau/DYMO_RERR_m.cc \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h
$O/networklayer/manetrouting/dymo_fau/DYMO_RM_m.o: networklayer/manetrouting/dymo_fau/DYMO_RM_m.cc \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h
$O/networklayer/manetrouting/dymo_fau/DYMO_RREP_m.o: networklayer/manetrouting/dymo_fau/DYMO_RREP_m.cc \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREP_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h
$O/networklayer/manetrouting/dymo_fau/DYMO_RREQ_m.o: networklayer/manetrouting/dymo_fau/DYMO_RREQ_m.cc \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREQ_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h
$O/networklayer/manetrouting/dymo_fau/DYMO_RoutingEntry.o: networklayer/manetrouting/dymo_fau/DYMO_RoutingEntry.cc \
	base/AbstractQueue.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	base/QueueBase.h \
	base/ReassemblyBuffer.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4FragBuf.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo_fau/DYMO.h \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_DataQueue.h \
	networklayer/manetrouting/dymo_fau/DYMO_OutstandingRREQList.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Packet_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREP_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREQ_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RoutingEntry.h \
	networklayer/manetrouting/dymo_fau/DYMO_RoutingTable.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timer.h \
	networklayer/manetrouting/dymo_fau/DYMO_TokenBucket.h \
	networklayer/manetrouting/dymo_fau/DYMO_UERR_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/manetrouting/dymo_fau/DYMO_RoutingTable.o: networklayer/manetrouting/dymo_fau/DYMO_RoutingTable.cc \
	base/AbstractQueue.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	base/QueueBase.h \
	base/ReassemblyBuffer.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4FragBuf.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo_fau/DYMO.h \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_DataQueue.h \
	networklayer/manetrouting/dymo_fau/DYMO_OutstandingRREQList.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Packet_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREP_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREQ_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RoutingEntry.h \
	networklayer/manetrouting/dymo_fau/DYMO_RoutingTable.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timer.h \
	networklayer/manetrouting/dymo_fau/DYMO_TokenBucket.h \
	networklayer/manetrouting/dymo_fau/DYMO_UERR_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.o: networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.cc \
	networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.h
$O/networklayer/manetrouting/dymo_fau/DYMO_Timer.o: networklayer/manetrouting/dymo_fau/DYMO_Timer.cc \
	base/INETDefs.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timer.h
$O/networklayer/manetrouting/dymo_fau/DYMO_TokenBucket.o: networklayer/manetrouting/dymo_fau/DYMO_TokenBucket.cc \
	base/AbstractQueue.h \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	base/ProtocolMap.h \
	base/QueueBase.h \
	base/ReassemblyBuffer.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4FragBuf.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_DataQueue.h \
	networklayer/manetrouting/dymo_fau/DYMO_OutstandingRREQList.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Packet_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREP_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RREQ_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RoutingEntry.h \
	networklayer/manetrouting/dymo_fau/DYMO_RoutingTable.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timeout_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_Timer.h \
	networklayer/manetrouting/dymo_fau/DYMO_TokenBucket.h \
	networklayer/manetrouting/dymo_fau/DYMO_UERR_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/manetrouting/dymo_fau/DYMO_UERR_m.o: networklayer/manetrouting/dymo_fau/DYMO_UERR_m.cc \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_UERR_m.h
$O/networklayer/manetrouting/dymo_fau/InspectorHelpers.o: networklayer/manetrouting/dymo_fau/InspectorHelpers.cc \
	base/INETDefs.h \
	networklayer/manetrouting/dymo_fau/DYMO_AddressBlock.h \
	networklayer/manetrouting/dymo_fau/DYMO_PacketBBMessage_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RERR_m.h \
	networklayer/manetrouting/dymo_fau/DYMO_RM_m.h \
	networklayer/manetrouting/dymo_fau/InspectorHelpers.h
$O/networklayer/manetrouting/olsr/OLSR.o: networklayer/manetrouting/olsr/OLSR.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/olsr/OLSR.h \
	networklayer/manetrouting/olsr/OLSR_ETX_parameter.h \
	networklayer/manetrouting/olsr/OLSR_repositories.h \
	networklayer/manetrouting/olsr/OLSR_rtable.h \
	networklayer/manetrouting/olsr/OLSR_state.h \
	networklayer/manetrouting/olsr/OLSRpkt_m.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/manetrouting/olsr/OLSROPT.o: networklayer/manetrouting/olsr/OLSROPT.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/olsr/OLSR.h \
	networklayer/manetrouting/olsr/OLSROPT.h \
	networklayer/manetrouting/olsr/OLSR_ETX_parameter.h \
	networklayer/manetrouting/olsr/OLSR_repositories.h \
	networklayer/manetrouting/olsr/OLSR_rtable.h \
	networklayer/manetrouting/olsr/OLSR_state.h \
	networklayer/manetrouting/olsr/OLSRpkt_m.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/manetrouting/olsr/OLSR_ETX.o: networklayer/manetrouting/olsr/OLSR_ETX.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/olsr/OLSR.h \
	networklayer/manetrouting/olsr/OLSR_ETX.h \
	networklayer/manetrouting/olsr/OLSR_ETX_dijkstra.h \
	networklayer/manetrouting/olsr/OLSR_ETX_parameter.h \
	networklayer/manetrouting/olsr/OLSR_ETX_repositories.h \
	networklayer/manetrouting/olsr/OLSR_ETX_state.h \
	networklayer/manetrouting/olsr/OLSR_repositories.h \
	networklayer/manetrouting/olsr/OLSR_rtable.h \
	networklayer/manetrouting/olsr/OLSR_state.h \
	networklayer/manetrouting/olsr/OLSRpkt_m.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/networklayer/manetrouting/olsr/OLSR_ETX_dijkstra.o: networklayer/manetrouting/olsr/OLSR_ETX_dijkstra.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/olsr/OLSR.h \
	networklayer/manetrouting/olsr/OLSR_ETX.h \
	networklayer/manetrouting/olsr/OLSR_ETX_dijkstra.h \
	networklayer/manetrouting/olsr/OLSR_ETX_parameter.h \
	networklayer/manetrouting/olsr/OLSR_ETX_repositories.h \
	networklayer/manetrouting/olsr/OLSR_ETX_state.h \
	networklayer/manetrouting/olsr/OLSR_repositories.h \
	networklayer/manetrouting/olsr/OLSR_rtable.h \
	networklayer/manetrouting/olsr/OLSR_state.h \
	networklayer/manetrouting/olsr/OLSRpkt_m.h \
	util/uint128.h
$O/networklayer/manetrouting/olsr/OLSR_ETX_state.o: networklayer/manetrouting/olsr/OLSR_ETX_state.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/olsr/OLSR.h \
	networklayer/manetrouting/olsr/OLSR_ETX.h \
	networklayer/manetrouting/olsr/OLSR_ETX_parameter.h \
	networklayer/manetrouting/olsr/OLSR_ETX_repositories.h \
	networklayer/manetrouting/olsr/OLSR_ETX_state.h \
	networklayer/manetrouting/olsr/OLSR_repositories.h \
	networklayer/manetrouting/olsr/OLSR_rtable.h \
	networklayer/manetrouting/olsr/OLSR_state.h \
	networklayer/manetrouting/olsr/OLSRpkt_m.h \
	util/uint128.h
$O/networklayer/manetrouting/olsr/OLSR_rtable.o: networklayer/manetrouting/olsr/OLSR_rtable.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/olsr/OLSR.h \
	networklayer/manetrouting/olsr/OLSR_ETX_parameter.h \
	networklayer/manetrouting/olsr/OLSR_repositories.h \
	networklayer/manetrouting/olsr/OLSR_rtable.h \
	networklayer/manetrouting/olsr/OLSR_state.h \
	networklayer/manetrouting/olsr/OLSRpkt_m.h \
	util/uint128.h
$O/networklayer/manetrouting/olsr/OLSR_state.o: networklayer/manetrouting/olsr/OLSR_state.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/olsr/OLSR.h \
	networklayer/manetrouting/olsr/OLSR_ETX_parameter.h \
	networklayer/manetrouting/olsr/OLSR_repositories.h \
	networklayer/manetrouting/olsr/OLSR_rtable.h \
	networklayer/manetrouting/olsr/OLSR_state.h \
	networklayer/manetrouting/olsr/OLSRpkt_m.h \
	util/uint128.h
$O/networklayer/manetrouting/olsr/OLSRpkt_m.o: networklayer/manetrouting/olsr/OLSRpkt_m.cc \
	base/INETDefs.h \
	networklayer/manetrouting/olsr/OLSR_ETX_parameter.h \
	networklayer/manetrouting/olsr/OLSRpkt_m.h \
	util/uint128.h
$O/networklayer/manetrouting/search/searNeighborInfo.o: networklayer/manetrouting/search/searNeighborInfo.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h
$O/networklayer/manetrouting/search/searNeighborInfo_m.o: networklayer/manetrouting/search/searNeighborInfo_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h
$O/networklayer/manetrouting/search/searRouteRequest_m.o: networklayer/manetrouting/search/searRouteRequest_m.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/manetrouting/search/searRouting.o: networklayer/manetrouting/search/searRouting.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/RadioState.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/INoiseGenerator.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/ModulationType.h \
	linklayer/radio/Radio.h \
	linklayer/radio/SnrList.h \
	linklayer/radio/propagation/IReceptionModel.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h \
	world/powercontrol/IPowerControl.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/networklayer/mpls/LIBTable.o: networklayer/mpls/LIBTable.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/mpls/ConstType.h \
	networklayer/mpls/LIBTable.h \
	util/XMLUtils.h
$O/networklayer/mpls/MPLS.o: networklayer/mpls/MPLS.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ldp/LDP.h \
	networklayer/ldp/LDPPacket_m.h \
	networklayer/mpls/ConstType.h \
	networklayer/mpls/IClassifier.h \
	networklayer/mpls/LIBTable.h \
	networklayer/mpls/LIBTableAccess.h \
	networklayer/mpls/MPLS.h \
	networklayer/mpls/MPLSPacket.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/Utils.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	transport/contract/UDPSocket.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/networklayer/mpls/MPLSPacket.o: networklayer/mpls/MPLSPacket.cc \
	base/INETDefs.h \
	networklayer/mpls/MPLSPacket.h
$O/networklayer/ospfv2/OSPFPacket_m.o: networklayer/ospfv2/OSPFPacket_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ospfv2/OSPFPacket_m.h
$O/networklayer/ospfv2/OSPFRouting.o: networklayer/ospfv2/OSPFRouting.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFRouting.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/PatternMatcher.h \
	util/XMLUtils.h \
	util/uint128.h
$O/networklayer/ospfv2/OSPFTimer_m.o: networklayer/ospfv2/OSPFTimer_m.cc \
	base/INETDefs.h \
	networklayer/ospfv2/OSPFTimer_m.h
$O/networklayer/ospfv2/interface/OSPFInterface.o: networklayer/ospfv2/interface/OSPFInterface.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/interface/OSPFInterfaceState.o: networklayer/ospfv2/interface/OSPFInterfaceState.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateBackup.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateBackup.o: networklayer/ospfv2/interface/OSPFInterfaceStateBackup.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateBackup.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.o: networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateDown.o: networklayer/ospfv2/interface/OSPFInterfaceStateDown.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.h \
	networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.o: networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.o: networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.o: networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.o: networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.o: networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/messagehandler/HelloHandler.o: networklayer/ospfv2/messagehandler/HelloHandler.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.o: networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/messagehandler/LinkStateRequestHandler.o: networklayer/ospfv2/messagehandler/LinkStateRequestHandler.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.o: networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/messagehandler/MessageHandler.o: networklayer/ospfv2/messagehandler/MessageHandler.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighbor.o: networklayer/ospfv2/neighbor/OSPFNeighbor.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborState.o: networklayer/ospfv2/neighbor/OSPFNeighborState.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.o: networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateDown.o: networklayer/ospfv2/neighbor/OSPFNeighborStateDown.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.o: networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateFull.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.o: networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateFull.o: networklayer/ospfv2/neighbor/OSPFNeighborStateFull.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateFull.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateInit.o: networklayer/ospfv2/neighbor/OSPFNeighborStateInit.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.o: networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateFull.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.o: networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/router/ASExternalLSA.o: networklayer/ospfv2/router/ASExternalLSA.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/router/LSA.o: networklayer/ospfv2/router/LSA.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/router/NetworkLSA.o: networklayer/ospfv2/router/NetworkLSA.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/router/OSPFArea.o: networklayer/ospfv2/router/OSPFArea.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/router/OSPFRouter.o: networklayer/ospfv2/router/OSPFRouter.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/router/OSPFRoutingTableEntry.o: networklayer/ospfv2/router/OSPFRoutingTableEntry.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/router/RouterLSA.o: networklayer/ospfv2/router/RouterLSA.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/ospfv2/router/SummaryLSA.o: networklayer/ospfv2/router/SummaryLSA.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	util/uint128.h
$O/networklayer/rsvp_te/IntServ_m.o: networklayer/rsvp_te/IntServ_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/rsvp_te/IntServ_m.h
$O/networklayer/rsvp_te/RSVP.o: networklayer/rsvp_te/RSVP.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IScriptable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/mpls/ConstType.h \
	networklayer/mpls/IClassifier.h \
	networklayer/mpls/LIBTable.h \
	networklayer/mpls/LIBTableAccess.h \
	networklayer/rsvp_te/IRSVPClassifier.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/RSVP.h \
	networklayer/rsvp_te/RSVPHelloMsg.h \
	networklayer/rsvp_te/RSVPHello_m.h \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/rsvp_te/RSVPPathMsg.h \
	networklayer/rsvp_te/RSVPPathMsg_m.h \
	networklayer/rsvp_te/RSVPResvMsg.h \
	networklayer/rsvp_te/RSVPResvMsg_m.h \
	networklayer/rsvp_te/SignallingMsg_m.h \
	networklayer/rsvp_te/Utils.h \
	networklayer/ted/TED.h \
	networklayer/ted/TEDAccess.h \
	networklayer/ted/TED_m.h \
	util/XMLUtils.h \
	util/common.h \
	util/uint128.h
$O/networklayer/rsvp_te/RSVPHello_m.o: networklayer/rsvp_te/RSVPHello_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/RSVPHello_m.h \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/rsvp_te/RSVPPacket_m.h
$O/networklayer/rsvp_te/RSVPPacket_m.o: networklayer/rsvp_te/RSVPPacket_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/RSVPPacket_m.h
$O/networklayer/rsvp_te/RSVPPathMsg_m.o: networklayer/rsvp_te/RSVPPathMsg_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/rsvp_te/RSVPPathMsg_m.h
$O/networklayer/rsvp_te/RSVPResvMsg_m.o: networklayer/rsvp_te/RSVPResvMsg_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/rsvp_te/RSVPResvMsg_m.h
$O/networklayer/rsvp_te/SignallingMsg_m.o: networklayer/rsvp_te/SignallingMsg_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/SignallingMsg_m.h
$O/networklayer/rsvp_te/SimpleClassifier.o: networklayer/rsvp_te/SimpleClassifier.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/IScriptable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/mpls/ConstType.h \
	networklayer/mpls/IClassifier.h \
	networklayer/mpls/LIBTable.h \
	networklayer/mpls/LIBTableAccess.h \
	networklayer/rsvp_te/IRSVPClassifier.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/RSVP.h \
	networklayer/rsvp_te/RSVPAccess.h \
	networklayer/rsvp_te/RSVPHelloMsg.h \
	networklayer/rsvp_te/RSVPHello_m.h \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/rsvp_te/RSVPPathMsg.h \
	networklayer/rsvp_te/RSVPPathMsg_m.h \
	networklayer/rsvp_te/RSVPResvMsg.h \
	networklayer/rsvp_te/RSVPResvMsg_m.h \
	networklayer/rsvp_te/SignallingMsg_m.h \
	networklayer/rsvp_te/SimpleClassifier.h \
	util/XMLUtils.h
$O/networklayer/rsvp_te/Utils.o: networklayer/rsvp_te/Utils.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/Utils.h
$O/networklayer/ted/LinkStatePacket_m.o: networklayer/ted/LinkStatePacket_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ted/LinkStatePacket_m.h \
	networklayer/ted/TED_m.h
$O/networklayer/ted/LinkStateRouting.o: networklayer/ted/LinkStateRouting.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/ted/LinkStatePacket_m.h \
	networklayer/ted/LinkStateRouting.h \
	networklayer/ted/TED.h \
	networklayer/ted/TEDAccess.h \
	networklayer/ted/TED_m.h
$O/networklayer/ted/TED.o: networklayer/ted/TED.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/ted/TED.h \
	networklayer/ted/TED_m.h
$O/networklayer/ted/TED_m.o: networklayer/ted/TED_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ted/TED_m.h
$O/networklayer/xmipv6/BindingCache.o: networklayer/xmipv6/BindingCache.cc \
	base/INETDefs.h \
	networklayer/contract/IPv6Address.h \
	networklayer/xmipv6/BindingCache.h \
	util/uint128.h
$O/networklayer/xmipv6/BindingUpdateList.o: networklayer/xmipv6/BindingUpdateList.cc \
	base/INETDefs.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/xmipv6/BindingUpdateList.h \
	util/uint128.h
$O/networklayer/xmipv6/MobilityHeader.o: networklayer/xmipv6/MobilityHeader.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	networklayer/xmipv6/MobilityHeader.h \
	networklayer/xmipv6/MobilityHeader_m.h \
	util/uint128.h
$O/networklayer/xmipv6/MobilityHeader_m.o: networklayer/xmipv6/MobilityHeader_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	networklayer/xmipv6/MobilityHeader_m.h \
	util/uint128.h
$O/networklayer/xmipv6/xMIPv6.o: networklayer/xmipv6/xMIPv6.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/icmpv6/IPv6NDMessage_m.h \
	networklayer/icmpv6/IPv6NeighbourCache.h \
	networklayer/icmpv6/IPv6NeighbourDiscovery.h \
	networklayer/icmpv6/IPv6NeighbourDiscoveryAccess.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6ExtensionHeaders.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/ipv6tunneling/IPv6Tunneling.h \
	networklayer/ipv6tunneling/IPv6TunnelingAccess.h \
	networklayer/xmipv6/BindingCache.h \
	networklayer/xmipv6/BindingCacheAccess.h \
	networklayer/xmipv6/BindingUpdateList.h \
	networklayer/xmipv6/BindingUpdateListAccess.h \
	networklayer/xmipv6/MobilityHeader.h \
	networklayer/xmipv6/MobilityHeader_m.h \
	networklayer/xmipv6/xMIPv6.h \
	util/uint128.h
$O/transport/contract/SCTPCommand_m.o: transport/contract/SCTPCommand_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	util/uint128.h
$O/transport/contract/SCTPSocket.o: transport/contract/SCTPSocket.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/SCTPSocket.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	util/uint128.h
$O/transport/contract/TCPCommand_m.o: transport/contract/TCPCommand_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	util/uint128.h
$O/transport/contract/TCPSocket.o: transport/contract/TCPSocket.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	util/uint128.h
$O/transport/contract/TCPSocketMap.o: transport/contract/TCPSocketMap.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPSocketMap.h \
	util/uint128.h
$O/transport/contract/UDPControlInfo_m.o: transport/contract/UDPControlInfo_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPControlInfo_m.h \
	util/uint128.h
$O/transport/contract/UDPSocket.o: transport/contract/UDPSocket.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	transport/contract/UDPControlInfo.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	util/uint128.h
$O/transport/rtp/RTCP.o: transport/rtp/RTCP.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	transport/rtp/RTCP.h \
	transport/rtp/RTCPPacket.h \
	transport/rtp/RTCPPacket1.h \
	transport/rtp/RTCPPacket1_m.h \
	transport/rtp/RTCPPacket2.h \
	transport/rtp/RTCPPacket2_m.h \
	transport/rtp/RTCPPacket3.h \
	transport/rtp/RTCPPacket3_m.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPInnerPacket_m.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPParticipantInfo.h \
	transport/rtp/RTPParticipantInfo_m.h \
	transport/rtp/RTPReceiverInfo.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderInfo.h \
	transport/rtp/RTPSenderStatusMessage_m.h \
	transport/rtp/reports.h \
	transport/rtp/reports_m.h \
	transport/rtp/sdes.h \
	util/uint128.h
$O/transport/rtp/RTCPPacket.o: transport/rtp/RTCPPacket.cc \
	base/INETDefs.h \
	transport/rtp/RTCPPacket.h \
	transport/rtp/RTCPPacket1.h \
	transport/rtp/RTCPPacket1_m.h \
	transport/rtp/RTCPPacket2.h \
	transport/rtp/RTCPPacket2_m.h \
	transport/rtp/RTCPPacket3.h \
	transport/rtp/RTCPPacket3_m.h \
	transport/rtp/reports.h \
	transport/rtp/reports_m.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTCPPacket1_m.o: transport/rtp/RTCPPacket1_m.cc \
	transport/rtp/RTCPPacket1_m.h
$O/transport/rtp/RTCPPacket2_m.o: transport/rtp/RTCPPacket2_m.cc \
	base/INETDefs.h \
	transport/rtp/RTCPPacket1.h \
	transport/rtp/RTCPPacket1_m.h \
	transport/rtp/RTCPPacket2_m.h \
	transport/rtp/reports.h \
	transport/rtp/reports_m.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTCPPacket3_m.o: transport/rtp/RTCPPacket3_m.cc \
	base/INETDefs.h \
	transport/rtp/RTCPPacket1.h \
	transport/rtp/RTCPPacket1_m.h \
	transport/rtp/RTCPPacket2.h \
	transport/rtp/RTCPPacket2_m.h \
	transport/rtp/RTCPPacket3_m.h \
	transport/rtp/reports.h \
	transport/rtp/reports_m.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTP.o: transport/rtp/RTP.cc \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	transport/rtp/RTP.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPInnerPacket_m.h \
	transport/rtp/RTPInterfacePacket_m.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPProfile.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h \
	util/uint128.h
$O/transport/rtp/RTPInnerPacket.o: transport/rtp/RTPInnerPacket.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPInnerPacket_m.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPInnerPacket_m.o: transport/rtp/RTPInnerPacket_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPInnerPacket_m.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPInterfacePacket_m.o: transport/rtp/RTPInterfacePacket_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPInterfacePacket_m.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPPacket.o: transport/rtp/RTPPacket.cc \
	base/INETDefs.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h
$O/transport/rtp/RTPPacket_m.o: transport/rtp/RTPPacket_m.cc \
	base/INETDefs.h \
	transport/rtp/RTPPacket_m.h
$O/transport/rtp/RTPParticipantInfo.o: transport/rtp/RTPParticipantInfo.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPParticipantInfo.h \
	transport/rtp/RTPParticipantInfo_m.h \
	transport/rtp/reports.h \
	transport/rtp/reports_m.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTPParticipantInfo_m.o: transport/rtp/RTPParticipantInfo_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPParticipantInfo_m.h
$O/transport/rtp/RTPPayloadReceiver.o: transport/rtp/RTPPayloadReceiver.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPInnerPacket_m.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPPayloadReceiver.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPPayloadSender.o: transport/rtp/RTPPayloadSender.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPInnerPacket_m.h \
	transport/rtp/RTPInterfacePacket_m.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPPayloadSender.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPProfile.o: transport/rtp/RTPProfile.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPInnerPacket_m.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPPayloadReceiver.h \
	transport/rtp/RTPPayloadSender.h \
	transport/rtp/RTPProfile.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPReceiverInfo.o: transport/rtp/RTPReceiverInfo.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPParticipantInfo.h \
	transport/rtp/RTPParticipantInfo_m.h \
	transport/rtp/RTPReceiverInfo.h \
	transport/rtp/reports.h \
	transport/rtp/reports_m.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTPSenderControlMessage_m.o: transport/rtp/RTPSenderControlMessage_m.cc \
	base/INETDefs.h \
	transport/rtp/RTPSenderControlMessage_m.h
$O/transport/rtp/RTPSenderInfo.o: transport/rtp/RTPSenderInfo.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPParticipantInfo.h \
	transport/rtp/RTPParticipantInfo_m.h \
	transport/rtp/RTPSenderInfo.h \
	transport/rtp/reports.h \
	transport/rtp/reports_m.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTPSenderStatusMessage_m.o: transport/rtp/RTPSenderStatusMessage_m.cc \
	base/INETDefs.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/reports.o: transport/rtp/reports.cc \
	transport/rtp/reports.h \
	transport/rtp/reports_m.h
$O/transport/rtp/reports_m.o: transport/rtp/reports_m.cc \
	transport/rtp/reports_m.h
$O/transport/rtp/sdes.o: transport/rtp/sdes.cc \
	base/INETDefs.h \
	transport/rtp/sdes.h
$O/transport/rtp/profiles/avprofile/RTPAVProfile.o: transport/rtp/profiles/avprofile/RTPAVProfile.cc \
	base/INETDefs.h \
	transport/rtp/RTPProfile.h \
	transport/rtp/profiles/avprofile/RTPAVProfile.h
$O/transport/rtp/profiles/avprofile/RTPAVProfilePayload32Receiver.o: transport/rtp/profiles/avprofile/RTPAVProfilePayload32Receiver.cc \
	base/INETDefs.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPPayloadReceiver.h \
	transport/rtp/profiles/avprofile/RTPAVProfilePayload32Receiver.h \
	transport/rtp/profiles/avprofile/RTPMpegPacket_m.h
$O/transport/rtp/profiles/avprofile/RTPAVProfilePayload32Sender.o: transport/rtp/profiles/avprofile/RTPAVProfilePayload32Sender.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPInnerPacket_m.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTPPacket_m.h \
	transport/rtp/RTPPayloadSender.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPSenderStatusMessage_m.h \
	transport/rtp/profiles/avprofile/RTPAVProfilePayload32Sender.h \
	transport/rtp/profiles/avprofile/RTPMpegPacket_m.h
$O/transport/rtp/profiles/avprofile/RTPMpegPacket_m.o: transport/rtp/profiles/avprofile/RTPMpegPacket_m.cc \
	transport/rtp/profiles/avprofile/RTPMpegPacket_m.h
$O/transport/sctp/SCTP.o: transport/sctp/SCTP.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPAlg.o: transport/sctp/SCTPAlg.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAlg.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPAssociationBase.o: transport/sctp/SCTPAssociationBase.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPAssociationEventProc.o: transport/sctp/SCTPAssociationEventProc.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPAssociationRcvMessage.o: transport/sctp/SCTPAssociationRcvMessage.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/common.h \
	util/uint128.h
$O/transport/sctp/SCTPAssociationSendAll.o: transport/sctp/SCTPAssociationSendAll.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPAssociationUtil.o: transport/sctp/SCTPAssociationUtil.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPCommand_m.h \
	transport/contract/UDPControlInfo_m.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/common.h \
	util/uint128.h
$O/transport/sctp/SCTPCCFunctions.o: transport/sctp/SCTPCCFunctions.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPMessage.o: transport/sctp/SCTPMessage.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPMessage_m.o: transport/sctp/SCTPMessage_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/sctp/SCTPMessage_m.h \
	util/uint128.h
$O/transport/sctp/SCTPQueue.o: transport/sctp/SCTPQueue.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPReceiveStream.o: transport/sctp/SCTPReceiveStream.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPSSFunctions.o: transport/sctp/SCTPSSFunctions.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/sctp/SCTPSendStream.o: transport/sctp/SCTPSendStream.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/uint128.h
$O/transport/tcp/TCP.o: transport/tcp/TCP.cc \
	base/ByteArray.h \
	base/ByteArrayBuffer.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/ipv4/ICMPMessage_m.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/queues/TCPByteStreamRcvQueue.h \
	transport/tcp/queues/TCPByteStreamSendQueue.h \
	transport/tcp/queues/TCPMsgBasedRcvQueue.h \
	transport/tcp/queues/TCPMsgBasedSendQueue.h \
	transport/tcp/queues/TCPVirtualDataRcvQueue.h \
	transport/tcp/queues/TCPVirtualDataSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/TCPConnectionBase.o: transport/tcp/TCPConnectionBase.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/TCPConnectionEventProc.o: transport/tcp/TCPConnectionEventProc.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/TCPConnectionRcvSegment.o: transport/tcp/TCPConnectionRcvSegment.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/TCPConnectionSackUtil.o: transport/tcp/TCPConnectionSackUtil.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/TCPConnectionUtil.o: transport/tcp/TCPConnectionUtil.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/TCPSACKRexmitQueue.o: transport/tcp/TCPSACKRexmitQueue.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/flavours/DumbTCP.o: transport/tcp/flavours/DumbTCP.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/flavours/DumbTCP.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/flavours/TCPBaseAlg.o: transport/tcp/flavours/TCPBaseAlg.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/flavours/TCPNewReno.o: transport/tcp/flavours/TCPNewReno.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	transport/tcp/flavours/TCPNewReno.h \
	transport/tcp/flavours/TCPTahoeRenoFamily.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/flavours/TCPNoCongestionControl.o: transport/tcp/flavours/TCPNoCongestionControl.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	transport/tcp/flavours/TCPNoCongestionControl.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/flavours/TCPReno.o: transport/tcp/flavours/TCPReno.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	transport/tcp/flavours/TCPReno.h \
	transport/tcp/flavours/TCPTahoeRenoFamily.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/flavours/TCPTahoe.o: transport/tcp/flavours/TCPTahoe.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	transport/tcp/flavours/TCPTahoe.h \
	transport/tcp/flavours/TCPTahoeRenoFamily.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/flavours/TCPTahoeRenoFamily.o: transport/tcp/flavours/TCPTahoeRenoFamily.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	transport/tcp/flavours/TCPTahoeRenoFamily.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/queues/TCPByteStreamRcvQueue.o: transport/tcp/queues/TCPByteStreamRcvQueue.cc \
	base/ByteArray.h \
	base/ByteArrayMessage.h \
	base/ByteArrayMessage_m.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/queues/TCPByteStreamRcvQueue.h \
	transport/tcp/queues/TCPVirtualDataRcvQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/queues/TCPByteStreamSendQueue.o: transport/tcp/queues/TCPByteStreamSendQueue.cc \
	base/ByteArray.h \
	base/ByteArrayBuffer.h \
	base/ByteArrayMessage.h \
	base/ByteArrayMessage_m.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/queues/TCPByteStreamSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/queues/TCPMsgBasedRcvQueue.o: transport/tcp/queues/TCPMsgBasedRcvQueue.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/queues/TCPMsgBasedRcvQueue.h \
	transport/tcp/queues/TCPVirtualDataRcvQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/queues/TCPMsgBasedSendQueue.o: transport/tcp/queues/TCPMsgBasedSendQueue.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/queues/TCPMsgBasedSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/queues/TCPVirtualDataRcvQueue.o: transport/tcp/queues/TCPVirtualDataRcvQueue.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPReceiveQueue.h \
	transport/tcp/queues/TCPVirtualDataRcvQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp/queues/TCPVirtualDataSendQueue.o: transport/tcp/queues/TCPVirtualDataSendQueue.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/queues/TCPVirtualDataSendQueue.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/uint128.h
$O/transport/tcp_common/TCPSegment.o: transport/tcp_common/TCPSegment.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h
$O/transport/tcp_common/TCPSegment_m.o: transport/tcp_common/TCPSegment_m.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	transport/tcp_common/TCPSegment_m.h
$O/transport/tcp_common/TCPSpoof.o: transport/tcp_common/TCPSpoof.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	transport/tcp_common/TCPSpoof.h \
	util/uint128.h
$O/transport/udp/UDP.o: transport/udp/UDP.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/icmpv6/ICMPv6Access.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	transport/contract/UDPControlInfo.h \
	transport/contract/UDPControlInfo_m.h \
	transport/udp/UDP.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/uint128.h
$O/transport/udp/UDPPacket_m.o: transport/udp/UDPPacket_m.cc \
	base/INETDefs.h \
	transport/udp/UDPPacket_m.h
$O/util/Delayer.o: util/Delayer.cc \
	base/INETDefs.h \
	util/Delayer.h
$O/util/Macho.o: util/Macho.cc \
	util/Macho.h
$O/util/MessageChecker.o: util/MessageChecker.cc \
	base/INETDefs.h \
	util/MessageChecker.h
$O/util/NetAnimTrace.o: util/NetAnimTrace.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	mobility/IMobility.h \
	util/FWMath.h \
	util/NetAnimTrace.h
$O/util/OrdinalBasedDropper.o: util/OrdinalBasedDropper.cc \
	base/INETDefs.h \
	util/OrdinalBasedDropper.h
$O/util/OrdinalBasedDuplicator.o: util/OrdinalBasedDuplicator.cc \
	base/INETDefs.h \
	util/OrdinalBasedDuplicator.h
$O/util/PacketDump.o: util/PacketDump.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	transport/udp/UDPPacket_m.h \
	util/PacketDump.h \
	util/uint128.h
$O/util/PatternMatcher.o: util/PatternMatcher.cc \
	base/INETDefs.h \
	util/PatternMatcher.h
$O/util/PcapDump.o: util/PcapDump.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	transport/udp/UDPPacket_m.h \
	util/PcapDump.h \
	util/headerserializers/ipv4/IPv4Serializer.h
$O/util/PcapRecorder.o: util/PcapRecorder.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	util/PacketDump.h \
	util/PcapDump.h \
	util/PcapRecorder.h
$O/util/TCPDump.o: util/TCPDump.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	util/PacketDump.h \
	util/PcapDump.h \
	util/TCPDump.h
$O/util/ThruputMeter.o: util/ThruputMeter.cc \
	base/INETDefs.h \
	util/ThruputMeter.h
$O/util/ThruputMeteringChannel.o: util/ThruputMeteringChannel.cc \
	base/INETDefs.h \
	util/ThruputMeteringChannel.h
$O/util/XMLUtils.o: util/XMLUtils.cc \
	base/INETDefs.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPvXAddressResolver.h \
	util/XMLUtils.h \
	util/uint128.h
$O/util/common.o: util/common.cc \
	base/INETDefs.h \
	util/common.h
$O/util/int128.o: util/int128.cc \
	base/INETDefs.h \
	util/int128.h
$O/util/opp_utils.o: util/opp_utils.cc \
	base/INETDefs.h \
	util/opp_utils.h
$O/util/uint128.o: util/uint128.cc \
	base/INETDefs.h \
	util/uint128.h
$O/util/headerserializers/TCPIPchecksum.o: util/headerserializers/TCPIPchecksum.cc \
	base/INETDefs.h \
	util/headerserializers/TCPIPchecksum.h
$O/util/headerserializers/ipv4/ICMPSerializer.o: util/headerserializers/ipv4/ICMPSerializer.cc \
	applications/pingapp/PingPayload_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	util/headerserializers/TCPIPchecksum.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/defs.h \
	util/headerserializers/headers/in.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/ipv4/ICMPSerializer.h \
	util/headerserializers/ipv4/IPv4Serializer.h \
	util/headerserializers/ipv4/headers/ip.h \
	util/headerserializers/ipv4/headers/ip_icmp.h
$O/util/headerserializers/ipv4/IGMPSerializer.o: util/headerserializers/ipv4/IGMPSerializer.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/ipv4/IGMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	util/headerserializers/TCPIPchecksum.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/defs.h \
	util/headerserializers/headers/in.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/ipv4/IGMPSerializer.h \
	util/headerserializers/ipv4/IPv4Serializer.h \
	util/headerserializers/ipv4/headers/igmp.h \
	util/headerserializers/ipv4/headers/ip.h
$O/util/headerserializers/ipv4/IPv4Serializer.o: util/headerserializers/ipv4/IPv4Serializer.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IGMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/headerserializers/TCPIPchecksum.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/defs.h \
	util/headerserializers/headers/in.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/ipv4/ICMPSerializer.h \
	util/headerserializers/ipv4/IGMPSerializer.h \
	util/headerserializers/ipv4/IPv4Serializer.h \
	util/headerserializers/ipv4/headers/ip.h \
	util/headerserializers/sctp/SCTPSerializer.h \
	util/headerserializers/tcp/TCPSerializer.h \
	util/headerserializers/tcp/headers/tcp.h \
	util/headerserializers/udp/UDPSerializer.h \
	util/uint128.h
$O/util/headerserializers/sctp/SCTPSerializer.o: util/headerserializers/sctp/SCTPSerializer.cc \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTable.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAssociation.h \
	transport/sctp/SCTPMessage.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/defs.h \
	util/headerserializers/headers/in.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/ipv4/headers/ip.h \
	util/headerserializers/sctp/SCTPSerializer.h \
	util/headerserializers/sctp/headers/sctp.h \
	util/uint128.h
$O/util/headerserializers/tcp/TCPSerializer.o: util/headerserializers/tcp/TCPSerializer.cc \
	base/ByteArray.h \
	base/ByteArray_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_common/TCPSegment.h \
	transport/tcp_common/TCPSegment_m.h \
	util/headerserializers/TCPIPchecksum.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/defs.h \
	util/headerserializers/headers/in.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/tcp/TCPSerializer.h \
	util/headerserializers/tcp/headers/tcp.h \
	util/uint128.h
$O/util/headerserializers/udp/UDPSerializer.o: util/headerserializers/udp/UDPSerializer.cc \
	base/INETDefs.h \
	transport/udp/UDPPacket.h \
	transport/udp/UDPPacket_m.h \
	util/headerserializers/TCPIPchecksum.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/defs.h \
	util/headerserializers/headers/in.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/udp/UDPSerializer.h \
	util/headerserializers/udp/headers/udp.h
$O/world/annotations/AnnotationDummy.o: world/annotations/AnnotationDummy.cc \
	base/INETDefs.h \
	world/annotations/AnnotationDummy.h
$O/world/annotations/AnnotationManager.o: world/annotations/AnnotationManager.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	util/FWMath.h \
	world/annotations/AnnotationManager.h
$O/world/httptools/HttpController.o: world/httptools/HttpController.cc \
	applications/httptools/HttpEventMessages_m.h \
	applications/httptools/HttpLogdefs.h \
	applications/httptools/HttpMessages_m.h \
	applications/httptools/HttpRandom.h \
	applications/httptools/HttpUtils.h \
	base/INETDefs.h \
	world/httptools/HttpController.h
$O/world/obstacles/Obstacle.o: world/obstacles/Obstacle.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	util/FWMath.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h
$O/world/obstacles/ObstacleControl.o: world/obstacles/ObstacleControl.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	util/FWMath.h \
	world/annotations/AnnotationManager.h \
	world/obstacles/Obstacle.h \
	world/obstacles/ObstacleControl.h
$O/world/powercontrol/PowerControlManager.o: world/powercontrol/PowerControlManager.cc \
	base/INETDefs.h \
	world/powercontrol/IPowerControl.h \
	world/powercontrol/PowerControlManager.h \
	world/powercontrol/PowerControlMessages_m.h
$O/world/powercontrol/PowerControlMessages_m.o: world/powercontrol/PowerControlMessages_m.cc \
	world/powercontrol/PowerControlMessages_m.h
$O/world/radio/ChannelAccess.o: world/radio/ChannelAccess.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/ModulationType.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	transport/udp/UDPPacket_m.h \
	util/FWMath.h \
	util/uint128.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/world/radio/ChannelControl.o: world/radio/ChannelControl.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/contract/MACAddress.h \
	linklayer/contract/PhyControlInfo_m.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/radio/AirFrame_m.h \
	linklayer/radio/ModulationType.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv4ControlInfo.h \
	networklayer/contract/IPv4ControlInfo_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/world/radio/PrimaryUser.o: world/radio/PrimaryUser.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	linklayer/contract/MACAddress.h \
	mobility/IMobility.h \
	networklayer/arp/ARP.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv4Address.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/ipv4/IPv4Datagram_m.h \
	networklayer/ipv4/IPv4Route.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/manetrouting/VCap/VCap.h \
	networklayer/manetrouting/VCap/VCoord.h \
	networklayer/manetrouting/VCap/msgNeighborDisc.h \
	networklayer/manetrouting/VCap/msgNeighborDisc_m.h \
	networklayer/manetrouting/VCap/msgReq_m.h \
	networklayer/manetrouting/VCap/msgToRoute_m.h \
	networklayer/manetrouting/VCap/msgW_m.h \
	networklayer/manetrouting/VCap/puMode.h \
	networklayer/manetrouting/base/ControlManetRouting_m.h \
	networklayer/manetrouting/base/ManetRoutingBase.h \
	networklayer/manetrouting/base/compatibility.h \
	networklayer/manetrouting/search/searNeighborInfo.h \
	networklayer/manetrouting/search/searNeighborInfo_m.h \
	networklayer/manetrouting/search/searRouteRequest_m.h \
	networklayer/manetrouting/search/searRouting.h \
	util/FWMath.h \
	util/uint128.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/PrimaryUser.h \
	world/radio/PrimaryUserRef.h
$O/world/radio/PrimaryUserRef.o: world/radio/PrimaryUserRef.cc \
	base/Coord.h \
	base/INETDefs.h \
	networklayer/manetrouting/VCap/puMode.h \
	util/FWMath.h \
	world/radio/PrimaryUserRef.h
$O/world/scenario/ScenarioManager.o: world/scenario/ScenarioManager.cc \
	base/INETDefs.h \
	base/IScriptable.h \
	world/scenario/ScenarioManager.h
$O/world/traci/TraCIScenarioManager.o: world/traci/TraCIScenarioManager.cc \
	base/BasicModule.h \
	base/Coord.h \
	base/INETDefs.h \
	base/INotifiable.h \
	base/ModuleAccess.h \
	base/NotificationBoard.h \
	base/NotifierConsts.h \
	mobility/IMobility.h \
	mobility/models/MobilityBase.h \
	mobility/models/TraCIMobility.h \
	util/FWMath.h \
	world/traci/TraCIConstants.h \
	world/traci/TraCIScenarioManager.h
$O/world/traci/TraCIScenarioManagerLaunchd.o: world/traci/TraCIScenarioManagerLaunchd.cc \
	base/Coord.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	util/FWMath.h \
	world/traci/TraCIConstants.h \
	world/traci/TraCIScenarioManager.h \
	world/traci/TraCIScenarioManagerLaunchd.h

