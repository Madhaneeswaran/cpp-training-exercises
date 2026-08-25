#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <mutex>

enum class LogLevel { INFO, WARNING, ERROR };

class EventLogger {
private:
    std::string baseFilePath;
    std::ofstream logFile;
    std::mutex logMutex;
    int fileIndex;
    const long MAX_FILE_SIZE = 1024 * 1024; // 1 MB

    void rotateLogIfNeeded();
    std::string getLevelString(LogLevel level);

public:
    EventLogger(const std::string& path = "ems_log");
    ~EventLogger();
    void log(LogLevel level, const std::string& message);
};

#endif