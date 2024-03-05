#include "Thread.h"

Thread::Thread(std::string ip_src, std::string ip_dst, u_short sport, u_short dport)
    : ip_src(ip_src), ip_dst(ip_dst), sport(sport), dport(dport) {}

bool Thread::operator==(Thread a) const {
    if (a.ip_src == ip_src && a.ip_dst == ip_dst && a.sport == sport && a.dport == dport)
        return true;
    else
        return false;
}

std::string Thread::get_stream_string()
{
    return ip_src + "," + ip_dst + "," + std::to_string(sport) + "," + std::to_string(dport);
}