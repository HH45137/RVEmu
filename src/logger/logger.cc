#include "logger.h"

namespace RVEmu {

std::vector<std::ostream*> Logger::m_outputs;
std::mutex Logger::m_mutexLog;

Logger::Logger(const std::string& tag) 
    : m_tag(tag), m_level(Level::Debug) {
}

void Logger::setLevel(Level level) {
    m_level = level;
}

void Logger::addConsoleOutput() {
    std::lock_guard<std::mutex> lock(m_mutexLog);
    m_outputs.push_back(&std::cout);
}

void Logger::addFileOutput(const std::string& filename) {
    std::lock_guard<std::mutex> lock(m_mutexLog);
    static std::ofstream fileStream(filename, std::ios::app);
    if (fileStream.is_open()) {
        m_outputs.push_back(&fileStream);
    } else {
        throw std::runtime_error("Failed to open log file: " + filename);
    }
}

void Logger::logMessage(Level level, const std::string& message) {
    if (level < m_level) {
        return;
    }

    std::lock_guard<std::mutex> lock(m_mutexLog);
    std::string logEntry = "[" + getCurrentTime() + "] [" + levelToString(level) + "] [" + m_tag + "] " + message;

    for (auto* output : m_outputs) {
        *output << logEntry << std::endl;
    }
}

std::string Logger::getCurrentTime() const {
    auto now = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
    std::tm nowTm;
    localtime_r(&nowTime, &nowTm);
    char buffer[30];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &nowTm);
    return std::string(buffer);
}

std::string Logger::levelToString(Level level) const {
    switch (level) {
        case Level::Debug: return "DEBUG";
        case Level::Info: return "INFO";
        case Level::Warning: return "WARNING";
        case Level::Error: return "ERROR";
        case Level::Fatal: return "FATAL";
        default: return "UNKNOWN";
    }
}

}  // namespace RVEmu
