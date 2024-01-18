#include <iostream>

namespace RecursiveFunctions {
    int factorial(int n) {
        if (n < 0) {
            return 0;
        }
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * RecursiveFunctions::factorial(n - 1);
        }
    }

    void printNaturalNumbers(int count, int sort = 1) {
        if (sort == 1) {
            if (count > 0) {
                RecursiveFunctions::printNaturalNumbers(count - 1);
                std::cout << count << " ";
            }
        } else if (sort == 2) {
            if (count > 0) {
                std::cout << count << " ";
                RecursiveFunctions::printNaturalNumbers(count - 1, 2);
            }
        }
    }
}