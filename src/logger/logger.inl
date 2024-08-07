#pragma once

#include <cstdio>
#include <memory>

namespace RVEmu {

template<typename... Args>
std::string Logger::formatString(const std::string& format, Args... args) {
    size_t size = std::snprintf(nullptr, 0, format.c_str(), args...) + 1;
    if (size <= 0) {
        throw std::runtime_error("Error during formatting.");
    }
    std::unique_ptr<char[]> buf(new char[size]);
    std::snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1);
}

}  // namespace RVEmu
