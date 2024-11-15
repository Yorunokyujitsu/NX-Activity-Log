
#include <fstream>
#include <ctime>
#include "utils/Debug.hpp"

namespace Utils {
    std::mutex mutex;
    void write_log(const std::string& msg) {
#ifdef ENABLE_DEBUG
        std::time_t currentTime = std::time(nullptr);
        std::tm* time = std::localtime(&currentTime);
        char buffer[30];
        strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S] ", time);
        std::string timestamp(buffer);

        std::lock_guard<std::mutex> lock(Utils::mutex);
        std::ofstream file("/switch/NX-Activity-Log/debug.log", std::ios::app);
        if (file.is_open()) {
            file << timestamp + msg << std::endl;
        }
#endif
    }
};
