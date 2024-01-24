#include "CycleFunctions.h"
#include <iostream>

namespace CycleFunctions {
    int factorial(int n) {
        if (n < 0) {
            return 0;
        }
        int result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    void printNaturalNumbers(int count, SORT sort) {
        if (sort == SORT::DESC) {
            for (int i = count; i >= 1; i--) {
                std::cout << i << " ";
            }
        } else if (sort == SORT::ASC) {
            for (int i = 1; i <= count; i++) {
                std::cout << i << " ";
            }
        }
    }
}