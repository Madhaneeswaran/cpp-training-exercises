#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

struct UserInput {
    int val;
    std::string operation;
};

std::mutex mtx;
std::condition_variable cv;
int result = 0;
std::vector<UserInput> buffer;
bool flag = false;

void producer() {
    int value;
    std::string operation;
    std::cout << "[INFO] Enter pairs of <value> <operation> (add/sub/mul/div), or 0 stop to finish:\n";

    while (std::cin >> value >> operation) {
        std::lock_guard<std::mutex> lockGuard(mtx);

        buffer.push_back({value, operation});

        std::cout << "[QUEUED] " << value << " " << operation << "\n";

        cv.notify_one();

        if (operation == "stop") {
            break;
        }
    }
    
    std::lock_guard<std::mutex> lockGuard(mtx);
    flag = true;
    cv.notify_all();
}

void consumer() {
    while(true) {
        std::unique_lock<std::mutex> uniqueLock(mtx);

        cv.wait(uniqueLock, [](){
            return buffer.size() > 0 || flag;
        });
    
        if (buffer.empty()) {
            break;
        }

        UserInput item = buffer[0];
    
        if (item.operation == "stop") {
            buffer.clear();
            std::cout << "[INFO] 'stop' received - queue flushed, shutting down.\n";
        } else {
            if (item.operation == "add") {
                result += item.val;
            } else if (item.operation == "sub") {
                result -= item.val;
            } else if (item.operation == "mul") {
                result *= item.val;
            } else if (item.operation == "div") {
                if (item.val != 0) {
                    result /= item.val;
                } else {
                    std::cerr << "[ERROR] Division by zero — skipping " << item.val << ".\n";
                }
            } else {
                std::cerr << "[ERROR] Unrecognized operation \"" << item.operation << "\" — skipping.\n";
            }

            buffer.erase(buffer.begin());
        }

        if (flag) {
            break;
        }

        std::cout << "[RESULT] " << item.operation << " " << item.val << " -> result = " << result << "\n";    
        uniqueLock.unlock();
        cv.notify_one();
    }
}

int main() {
    std::thread produce(producer);
    std::thread consume(consumer);

    produce.join();
    consume.join();

    return 0;
}