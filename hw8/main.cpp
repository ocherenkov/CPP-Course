#include <iostream>
#include "CycleFunctions.h"
#include "RecursiveFunctions.h"

void countNumbers(int n) {
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < n; ++i) {
        int number;
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> number;

        if (number > 0) {
            positiveCount++;
        } else if (number < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }

    std::cout << "Positive: " << positiveCount << ", negative: " << negativeCount << ", zeroes: " << zeroCount << std::endl;
}

void task1() {
    int numCount;
    std::cout << std::endl << "[TASK 1]" << std::endl;

    std::cout << "Enter number of numbers: ";
    std::cin >> numCount;
    countNumbers(numCount);
}

void task2() {
    int number = 10;
    std::cout << std::endl << "[TASK 2]" << std::endl;
    std::cout << "[Cycle] Factorial of number " << number << " = " << CycleFunctions::factorial(number) << std::endl;
    std::cout << "[Recursive] Factorial of number " << number << " = " << RecursiveFunctions::factorial(number) << std::endl;
}

void task3() {
    int N = 6;
    std::cout << std::endl << "[TASK 3]" << std::endl;
    std::cout << "[Cycle] Natural number with desc sort: ";
    CycleFunctions::printNaturalNumbers(N, 2);
    std::cout << std::endl;

    std::cout << "[Cycle] Natural number with asc sort: ";
    CycleFunctions::printNaturalNumbers(N, 1);
    std::cout << std::endl;

    std::cout << "[Recursive] Natural number with desc sort: ";
    RecursiveFunctions::printNaturalNumbers(N, 2);
    std::cout << std::endl;

    std::cout << "[Recursive] Natural number with asc sort: ";
    RecursiveFunctions::printNaturalNumbers(N, 1);
    std::cout << std::endl;
}

int main() {
    // task 1
    task1();

    // task 2
    task2();

    // task 3
    task3();

    return 0;
}