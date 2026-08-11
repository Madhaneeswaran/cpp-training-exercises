#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

// Limits
const uintmax_t FILE_SIZE_LIMIT = 2 * 1024 * 1024;      // 2 MB
const size_t TWENTY_MB = 10 * FILE_SIZE_LIMIT;          // 20 MB 
const fs::path LOGS_DIR = "logs";
const int FILES_TO_DELETE = 3;

// Structure to pair file path with its modification time
struct LogFileInfo {
    fs::path path;
    fs::file_time_type writeTime;
};

class Logger {
    private:
        fs::path folderPath;
        uintmax_t maxFolderSize;
        fs::path currentLogFile;

        std::string getFormattedDateTime() const {
            auto now = std::chrono::system_clock::now();
            auto in_time_t = std::chrono::system_clock::to_time_t(now);
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                now.time_since_epoch()) % 1000;
            
            std::stringstream ss;
            // Format: YYYY-MM-DD HH:MM:SS.mmm (e.g., 2026-08-11 13:48:22.345)
            ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S")
            << "." << std::setfill('0') << std::setw(3) << ms.count();
            return ss.str();
        }

        std::string getTimestamp() {
            auto now = std::chrono::system_clock::now();
            auto in_time_t = std::chrono::system_clock::to_time_t(now);
            
            std::stringstream ss;
            // Format: YYYYMMDD_HHMMSS (e.g., 20260811_103745)
            ss << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S");
            return ss.str();
        }

        uintmax_t calculateFolderSize() {
            uintmax_t totalSize = 0;

            for (const auto& entry : fs::directory_iterator(LOGS_DIR)) {
                if (fs::is_regular_file(entry.path())) {
                    uintmax_t size = fs::file_size(entry.path());
                    totalSize += size;
                }
            }

            return totalSize;
        }

        void cleanOldestFiles() {
            std::vector<LogFileInfo> files;

            for (const auto& entry : fs::directory_iterator(LOGS_DIR)) {
                if (fs::is_regular_file(entry.path())) {
                    files.push_back({entry.path(), fs::last_write_time(entry.path())});
                }
            }

            std::sort(files.begin(), files.end(), [](const LogFileInfo& a, const LogFileInfo& b) {
                return a.writeTime < b.writeTime;
            });

            size_t filesToDelete = std::min(files.size(), static_cast<size_t>(FILES_TO_DELETE));
            for (size_t i = 0; i < filesToDelete; ++i) {
                if (files[i].path != currentLogFile) {
                    fs::remove(files[i].path);
                    std::cout << "Cleanup in progress, Removed: " << files[i].path.filename() <<'\n';
                }
            }

        }

        void cleanup() {
            if (fs::file_size(currentLogFile) > FILE_SIZE_LIMIT) {
                std::cout << "File size limit exceeded, Created a new file. \n";
                currentLogFile = folderPath / ("logs_" + getTimestamp() + ".txt");
            }

            uintmax_t currentSize = calculateFolderSize();
            if (currentSize > maxFolderSize) {
                cleanOldestFiles();
            }
        }

    public:
        Logger(fs::path logsDir = LOGS_DIR, uintmax_t folderLimit = TWENTY_MB) : folderPath(logsDir), maxFolderSize(folderLimit) {}

        bool buildFolder() {
            try {
                fs::create_directory(folderPath);
                currentLogFile = folderPath / ("logs_" + getTimestamp() + ".txt");
                return true;
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Error: " << e.what() << "\n";
                return false;
            }

        }

        void log() {
            try {
                std::ofstream logFile(currentLogFile, std::ios::app);

                if (logFile.is_open()) {
                    logFile << "Timestamp : " << getFormattedDateTime() << "\n";
                    std::cout << "Logged time successfully \n";
                    logFile.close();

                    cleanup();
                }
            } catch (const fs::filesystem_error& e) {
                std::cerr << "File system error: " << e.what() << "\n";
            }
        }
};

int main () {
    Logger loggerObj(LOGS_DIR, TWENTY_MB);

    if (!loggerObj.buildFolder()) {
        std::cerr << "Error running ... \n";

        return 1;
    }

    while (true) {
        loggerObj.log();
    }

    return 0;
}
