#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
#include <thread>

namespace fs = std::filesystem;

// Limits
const uintmax_t FILE_SIZE_LIMIT = 2 * 1024 * 1024;  // 2 MB
const size_t TWENTY_MB = 20 * 1024 * 1024;          // 20 MB 
const fs::path LOGS_DIR = "logs";
const int FILES_TO_DELETE = 5;

// Structure to pair file path with its modification time
struct LogFileInfo {
    fs::path path;
    fs::file_time_type writeTime;
};

class FileRetentionLogger {
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
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                now.time_since_epoch()) % 1000;

            std::stringstream ss;
            // Format: YYYYMMDD_HHMMSS_mmm (e.g., 20260811_103745_123)
            ss << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S")
               << "_" << std::setfill('0') << std::setw(3) << ms.count();
            return ss.str();
        }

        uintmax_t calculateFolderSize() {
            uintmax_t totalSize = 0;
            try {
                if (!fs::exists(folderPath)) return 0;

                for (const auto& entry : fs::directory_iterator(folderPath)) {
                    if (fs::is_regular_file(entry.path())) {
                        uintmax_t size = fs::file_size(entry.path());
                        totalSize += size;
                    }
                }
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Filesystem error while calculating folder size: " << e.what() << '\n';
            }
            return totalSize;
        }

        void cleanOldestFiles() {
            try {
                std::vector<LogFileInfo> files;
    
                for (const auto& entry : fs::directory_iterator(folderPath)) {
                    if (fs::is_regular_file(entry.path()) && entry.path() != currentLogFile) {
                        files.push_back({entry.path(), fs::last_write_time(entry.path())});
                    }
                }
    
                std::sort(files.begin(), files.end(), [](const LogFileInfo& a, const LogFileInfo& b) {
                    return a.writeTime < b.writeTime;
                });
    
                for (const auto& file : files) {
                    if (calculateFolderSize() <= maxFolderSize) {
                        break; 
                    }
                    fs::remove(file.path);
                    std::cout << "Cleanup in progress. Removed old log file: " << file.path.filename() << '\n';
                }
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Filesystem error during cleanup: " << e.what() << '\n';
            }
        }

        void verifyLimitsAndRotate() {
            try {
                if (fs::exists(currentLogFile) && fs::file_size(currentLogFile) > FILE_SIZE_LIMIT) {
                    std::cout << "Active file size limit exceeded. Rotating logs... \n";
                    currentLogFile = folderPath / ("logs_" + getTimestamp() + ".txt");
                }

                if (calculateFolderSize() > maxFolderSize) {
                    cleanOldestFiles();
                }
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Error evaluating rotation constraints: " << e.what() << '\n';
            }
        }

    public:
        FileRetentionLogger(fs::path logsDir = LOGS_DIR, uintmax_t folderLimit = TWENTY_MB) : folderPath(logsDir), maxFolderSize(folderLimit) {}

        bool initialize() {
            try {
                fs::create_directories(folderPath);
                // Note: File is intentionally not generated on disk yet; it initializes on-demand when the first std::ofstream connection opens.
                currentLogFile = folderPath / ("logs_" + getTimestamp() + ".txt");
                return true;
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Error: " << e.what() << "\n";
                return false;
            }

        }

        void initiateLogging() {
            std::ofstream logFile(currentLogFile, std::ios::app);

            if (logFile.is_open()) {
                logFile << "Timestamp : " << getFormattedDateTime() << "\n";
                std::cout << "Logged time successfully \n";
            } else {
                std::cerr << "Failed to open or create the log target: " << currentLogFile << '\n';
            }

            verifyLimitsAndRotate();
        }
};

int main () {
    FileRetentionLogger logger(LOGS_DIR, TWENTY_MB);

    if (!logger.initialize()) {
        std::cerr << "Error creating folder ... \n";

        return 1;
    }

    std::cout << "Logger running. Press Ctrl+C to terminate the application safely.\n";

    while (true) {
        logger.initiateLogging();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
