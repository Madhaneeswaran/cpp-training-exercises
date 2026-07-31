#include <iostream>
#include <string>
#include <algorithm>

int numOfCharToStore(const std::string str) {
    return str.length();
}

void getSortedName(std::string& name) {
  std::sort(name.begin(), name.end());
}

int main() {
    std::string name;
    std::cout << "Enter your name :- ";
    std::getline(std::cin, name);

    std::cout << numOfCharToStore(name) << " - number of bytes required to store your name!" << std::endl;

    getSortedName(name);

    std::cout << "Sorted name:- " << name << '\n';
}