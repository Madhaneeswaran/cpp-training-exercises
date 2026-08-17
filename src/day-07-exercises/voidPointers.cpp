#include <iostream>

void performAddition(void* a, void* b, const char datatype) {
    switch (datatype) {
        case 'i': {
            int result = *(static_cast<int*>(a)) + *(static_cast<int*>(b));
            std::cout << "Addition of two integers: " << result << "\n";
            break;
        }
        case 'f': {
            float result = *(static_cast<float*>(a)) + *(static_cast<float*>(b));
            std::cout << "Addition of two floating numbers: " << result << "\n";
            break;
        }
        case 'd': {
            double result = *(static_cast<double*>(a)) + *(static_cast<double*>(b));
            std::cout << "Addition of two doubly digit numbers: " << result << "\n";
            break;
        }
        default: {
            std::cerr << "Unsupported data type :- " << datatype << "\n";
        }
    }
}

int main(){ 
    int a = 10, b = 20;
    performAddition(&a, &b, 'i');

    float c = 30.3f, d = 40.4f;
    performAddition(&c, &d, 'f');

    double e = 50.5, f = 60.6;
    performAddition(&e, &f, 'd');

    performAddition(&e, &f, 'r');

    return 0;
}