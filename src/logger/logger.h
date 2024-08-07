#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <mutex>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <ctime>
#include <chrono>

namespace RVEmu {

class Logger {
public:
    enum class Level {
        Debug,
        Info,
        Warning,
        Error,
        Fatal
    };

    Logger(const std::string& tag);

    template<typename... Args>
    void log(Level level, const std::string& format, Args... args) {
        logMessage(level, formatString(format, args...));
    }

    template<typename... Args>
    void debug(const std::string& format, Args... args) {
        log(Level::Debug, format, args...);
    }

    template<typename... Args>
    void info(const std::string& format, Args... args) {
        log(Level::Info, format, args...);
    }

    template<typename... Args>
    void warning(const std::string& format, Args... args) {
        log(Level::Warning, format, args...);
    }

    template<typename... Args>
    void error(const std::string& format, Args... args) {
        log(Level::Error, format, args...);
    }

    template<typename... Args>
    void fatal(const std::string& format, Args... args) {
        log(Level::Fatal, format, args...);
    }

    void setLevel(Level level);

    static void addConsoleOutput();
    static void addFileOutput(const std::string& filename);

private:
    void logMessage(Level level, const std::string& message);
    std::string getCurrentTime() const;
    std::string levelToString(Level level) const;

    template<typename... Args>
    std::string formatString(const std::string& format, Args... args);

    std::string m_tag;
    Level m_level;
    static std::vector<std::ostream*> m_outputs;
    static std::mutex m_mutexLog;
};

}  // namespace RVEmu

#include "logger.inl"
