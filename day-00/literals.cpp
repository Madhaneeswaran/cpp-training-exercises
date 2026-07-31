#include <iostream>

#define LENGTH 10
#define width 5
#define NEWLINE '\n'

int main() {
    int area;

    area = LENGTH * width;

    std::cout << area << NEWLINE << std::endl;

    return 0;
}