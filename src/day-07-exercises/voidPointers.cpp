#include <iostream>

enum class DataType {
    Int,
    Float,
    Double
}

void performAddition(void* a, void* b, DataType datatype) {
    switch (datatype) {
        case DataType::Int: {
            int result = *(static_cast<int*>(a)) + *(static_cast<int*>(b));
            std::cout << "Addition of two integers: " << result << "\n";
            break;
        }
        case DataType::Float: {
            float result = *(static_cast<float*>(a)) + *(static_cast<float*>(b));
            std::cout << "Addition of two floating numbers: " << result << "\n";
            break;
        }
        case DataType::Double: {
            double result = *(static_cast<double*>(a)) + *(static_cast<double*>(b));
            std::cout << "Addition of two double-precision numbers: " << result << "\n";
            break;
        }
        default: {
            std::cerr << "Unsupported data type :- " << datatype << "\n";
            break;
        }
    }
}

int main(){ 
    int a = 10, b = 20;
    performAddition(&a, &b, DataType::Int);

    float c = 30.3f, d = 40.4f;
    performAddition(&c, &d, DataType::Float);

    double e = 50.5, f = 60.6;
    performAddition(&e, &f, DataType::Double);

    return 0;
}