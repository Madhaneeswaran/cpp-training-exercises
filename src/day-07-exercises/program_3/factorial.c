#include "factorial.h"

unsigned long long calculate_factorial(int n) {
    if (n < 0) return 0;
    
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}