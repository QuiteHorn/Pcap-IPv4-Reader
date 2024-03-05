add_executable (pcap_w "pcap_w.cpp" "pcap_w.h" "packets_def.h" "Streams.cpp" "Streams.h" "Thread.cpp" "Thread.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET pcap_w PROPERTY CXX_STANDARD 20)
endif()


target_compile_definitions(pcap_w PRIVATE WPCAP HAVE_REMOTE BUILDING_SNIFFER_LIBRARY)
target_include_directories(pcap_w PRIVATE "../WpdPack/Include")
target_link_directories(pcap_w PRIVATE "../WpdPack/Lib/x64")
target_link_libraries(pcap_w PRIVATE wpcap ws2_32)