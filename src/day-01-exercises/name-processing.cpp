#include <iostream>
#include <cstring>
#include <algorithm>

int getCStyleStringLength(const char* str) {
    int length;

    while (str[length] != '\0') {
        ++length;
    }

    return length;
}

int main() {
    int max_size = 100;

    char* username = new char[max_size];

    std::cout << "Enter your name :- ";
    std::cin.getline(username, max_size);

    size_t totalBytes = getCStyleStringLength(username);

    std::cout << totalBytes << " - number of bytes required to store your name! \n";

    std::sort(username, username + totalBytes);
    std::cout << "Sorted name:- " << username << '\n';

    delete[] username;
    username = nullptr;
}