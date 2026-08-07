#include <iostream>

void counter() {
    static int count = 0;
    ++count;

    std::cout << "Function called :- " << count << std::endl;
}

int main() {
    const int max_call = 5;

    for (int i = 0; i < max_call; i++) {
        counter();
    }
    
    return 0;
}