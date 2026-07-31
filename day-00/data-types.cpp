#include <iostream>
// #include <string>
#include <vector>

// void printBankBalance(float balance) {
//     std::string rupee_symbol = "₹";

//     std::cout << "My current bank balance is " << rupee_symbol << " " << balance << std::endl;
// }

void printElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

int main() {
    int banks[] = {2,3,4,5,6,7};

    printElements(banks, 6);

    banks[4] = 40;

    printElements(banks, 6);

    return 0;
}