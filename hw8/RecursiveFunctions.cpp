#include "RecursiveFunctions.h"
#include <iostream>

namespace RecursiveFunctions {
    int factorial(int n) {
        if (n < 0) {
            return 0;
        }
        if (n <= 1) {
            return 1;
        } else {
            return n * RecursiveFunctions::factorial(n - 1);
        }
    }

    void printNaturalNumbers(int count, SORT sort) {
        if (sort == SORT::ASC) {
            if (count > 0) {
                RecursiveFunctions::printNaturalNumbers(count - 1);
                std::cout << count << " ";
            }
        } else if (sort == SORT::DESC) {
            if (count > 0) {
                std::cout << count << " ";
                RecursiveFunctions::printNaturalNumbers(count - 1, SORT::DESC);
            }
        }
    }
}