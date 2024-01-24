#include <iostream>

int main() {
    // task 1
    int first, step, last;
    std::cout << "Enter first element of arithmetic progression: ";
    std::cin >> first;
    std::cout << "Enter step of arithmetic progression: ";
    std::cin >> step;
    std::cout << "Enter number of last element of arithmetic progression: ";
    std::cin >> last;

    if (last < 0) {
        std::cout << "Number of last element of arithmetic progression must be more than 0" << std::endl;
    } else {
        std::cout << "Elements of arithmetic progression: ";
        for (int i = 0; i < last; i++) {
            int element = first + i * step;
            if (i < last - 1) {
                std::cout << element << ", ";
            } else {
                std::cout << element << std::endl;
            }
        }
    }

    // task 2
    int fn, result;
    std::cout << "Enter number of element of Fibonacci sequence: ";
    std::cin >> fn;

    if (fn < 1) {
        std::cout << "The program only works for positive numbers" << std::endl;
    } else {
        int f1 = 1, f2 = 1;
        if (fn == 1 || fn == 2) {
            result = 1;
        } else {
            for (int i = 3; i <= fn; ++i) {
                result = f1 + f2;
                f1 = f2;
                f2 = result;
            }
        }
        std::cout << "F" << fn << " = " << result << std::endl;
    }

    // task 3
    int num;
    std::cout << "Enter a positive number: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Incorrect number entered" << std::endl;
    } else {
        long long factorial = 1;
        std::cout << "Factorial of number " << num << ": ";
        for (int i = 2; i <= num; ++i) {
            factorial *= i;
            if (i < num) {
                std::cout << i << " * ";
            } else {
                std::cout << i;
            }

        }
        std::cout << " = " << factorial << std::endl;
    }

    // task 4
    int size;
    std::cout << "Enter the shape size: ";
    std::cin >> size;

    std::cout << "a:" << std::endl;
    for (int i = size; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << "b:" << std::endl;
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << "с:" << std::endl;
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << "d:" << std::endl;
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j < i; ++j) {
            std::cout << " ";
        }
        for (int k = 1; k <= size; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << "e:" << std::endl;
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << ((i + j) % 2 == 0);
        }
        std::cout << std::endl;
    }

    // task 5
    char input;
    int sum = 0;

    while (true) {
        std::cout << "Enter a symbol: ";
        std::cin >> input;
        std::cout << "Sum: " << sum << std::endl;

        if (input == '.') {
            std::cout << "Finish." << std::endl;
            break;
        }

        if (islower(input)) {
            char upperCase = toupper(input);
            std::cout << "lower: " << input << " upper: " << upperCase << std::endl;
        } else if (isdigit(input)) {
            sum += (input - '0');
            std::cout << "Number: " << input << ". Sum: " << sum << std::endl;
        } else {
            std::cout << "This symbol is not processed by the program." << std::endl;
        }
    }

    return 0;
}