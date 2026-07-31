#include <iostream>

void counter() {
    static int count = 0;
    count++;

    std::cout << "Function called :- " << count << std::endl;
}

int main() {
    counter();
    counter();
    counter();
    counter();
    counter();
    counter();
    
    return 0;
}