#include "Logger.hpp"
#include <iostream>

EventLogger::EventLogger(const std::string& path) : baseFilePath(path), fileIndex(0) {
    rotateLogIfNeeded();
}

EventLogger::~EventLogger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void EventLogger::rotateLogIfNeeded() {
    if (logFile.is_open()) {
        logFile.seekp(0, std::ios::end);
        if (logFile.tellp() < MAX_FILE_SIZE) {
            return;
        }
        logFile.close();
        fileIndex++;
    }
    
    std::string currentFile = baseFilePath + "_" + std::to_string(fileIndex) + ".log";
    logFile.open(currentFile, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << currentFile << "\n";
    }
}

std::string EventLogger::getLevelString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO: return "[INFO]";
        case LogLevel::WARNING: return "[WARNING]";
        case LogLevel::ERROR: return "[ERROR]";
        default: return "[UNKNOWN]";
    }
}

void EventLogger::log(LogLevel level, const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    rotateLogIfNeeded();
    
    if (logFile.is_open()) {
        logFile << getLevelString(level) << " " << message << "\n";
        logFile.flush();
    }
}