#include "Streams.h"

void Streams::add_thread_info(Thread th, int bytes)
{
    if (total_data.count(th.get_stream_string()) == 0)
    {
        total_data.insert({ th.get_stream_string(), stream_data(1, bytes) });
    }
    else
    {
        total_data[th.get_stream_string()].first += 1;
        total_data[th.get_stream_string()].second += bytes;
    }
}

std::vector<std::string> Streams::get_keys()
{
    std::vector<std::string> keys;
    for (const auto& [k, v] : total_data) {
        keys.push_back(k);
    }
    return keys;
}

unsigned int Streams::get_packets_count(Thread th)
{
    return total_data[th.get_stream_string()].first;
}

unsigned int Streams::get_packets_count(std::string th)
{
    return total_data[th].first;
}

unsigned long Streams::get_bytes_transfered(Thread th)
{
    return total_data[th.get_stream_string()].second;
}

unsigned long Streams::get_bytes_transfered(std::string th)
{
    return total_data[th].second;
}