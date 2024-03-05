#pragma once

#include "Thread.h"
#include <map>
#include <vector>

typedef std::pair<unsigned int, unsigned long> stream_data;

class Streams {
private:
    std::map<std::string, stream_data> total_data;

public:
    void add_thread_info(Thread th, int bytes);

    std::vector<std::string> get_keys();

    unsigned int get_packets_count(Thread th);
    unsigned int get_packets_count(std::string th);
    unsigned long get_bytes_transfered(Thread th);
    unsigned long get_bytes_transfered(std::string th);
};

