
#pragma once

#include <pcap/pcap.h>

#define SIZE_ETHERNET 14
#define ETHER_ADDR_LEN  6

typedef uint32_t u_int32_t;

std::string int_ip_to_str(unsigned int ip)
{
    return std::to_string(ip & 0xff) + "." + std::to_string((ip >> 8) & 0xff) + "." + std::to_string((ip >> 16) & 0xff) + "." + std::to_string(ip >> 24);
}

struct ethernet_packet {
    u_char ether_dhost[ETHER_ADDR_LEN];
    u_char ether_shost[ETHER_ADDR_LEN];
    u_short ether_type;
};

struct ip_packet {
    u_char ip_vhl;
    u_char ip_tos;
    u_short ip_len;
    u_short ip_id;
    u_short ip_off;
#define IP_RF 0x8000        
#define IP_DF 0x4000        
#define IP_MF 0x2000        
#define IP_OFFMASK 0x1fff   
    u_char ip_ttl;
    u_char ip_p;
    u_short ip_sum;
    struct in_addr ip_src;
    struct in_addr ip_dst;

};
#define IP_HL(ip)       (((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)        (((ip)->ip_vhl) >> 4)

struct protocol_packet {
    u_short th_sport;
    u_short th_dport;
    u_int32_t th_seq;
    u_int32_t th_ack;
};