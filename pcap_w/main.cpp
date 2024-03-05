#include "pcap_w.h"

#include <iostream>
#include <format>
#include <winsock2.h>
#include <pcap/pcap.h>
#include <string>
#include <stdint.h>
#include <utility>
#include <map>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Thread.h"
#include "Streams.h"

#include "packets_def.h"

#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char* argv[])
{

    std::string file = argv[1];

    char errbuff[PCAP_ERRBUF_SIZE];

    pcap_t* pcap = pcap_open_offline(file.c_str(), errbuff);

    struct pcap_pkthdr* header;

    const u_char* packet;

    const struct ip_packet* ip;
    const struct protocol_packet* proto;

    u_int size_ip;

    Streams total_data;

    std::string sip_str, dip_str;

    unsigned int src_ip_addr, dst_ip_addr;

    while (int returnValue = pcap_next_ex(pcap, &header, &packet) >= 0)
    {
        ip = (struct ip_packet*)(packet + SIZE_ETHERNET);
        size_ip = IP_HL(ip) * 4;
        if (size_ip < 20) {
            continue;
        }
        proto = (struct protocol_packet*)(packet + SIZE_ETHERNET + size_ip);

        src_ip_addr = ip->ip_src.S_un.S_addr;
        dst_ip_addr = ip->ip_dst.S_un.S_addr;

        sip_str = int_ip_to_str(src_ip_addr);
        dip_str = int_ip_to_str(dst_ip_addr);

        Thread th(sip_str, dip_str, ntohs(proto->th_sport), ntohs(proto->th_dport));

        total_data.add_thread_info(th, header->len);
    }

    std::fstream fout;

    fout.open("data.csv", std::ios::app);

    std::vector<std::string> keys = total_data.get_keys();

    for (const auto& key : keys) {
        std::cout << "Unique Stream " << key << ' ' << total_data.get_bytes_transfered(key) << " bytes totally transfered" << std::endl;
        fout << key << ";" << total_data.get_packets_count(key) << ";" << total_data.get_bytes_transfered(key)
            << "\n";
    }

    std::cout << "Saved in data.csv";
    return 0;
}