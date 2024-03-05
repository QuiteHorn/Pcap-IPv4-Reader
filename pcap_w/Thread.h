#pragma once

#include <pcap/pcap.h>
#include <string>

class Thread {
private:
    std::string ip_src, ip_dst;
    u_short sport, dport;

public:
    Thread(std::string ip_src, std::string ip_dst, u_short sport, u_short dport);

    bool operator==(Thread a) const;

    std::string get_stream_string();
};

