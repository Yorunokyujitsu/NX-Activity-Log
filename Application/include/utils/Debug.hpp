#pragma once
#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <string>
#include <mutex>

//#define ENABLE_DEBUG

namespace Utils {
    extern std::mutex mutex;
    void write_log(const std::string& msg);
};

#endif
