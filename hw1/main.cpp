#include <iostream>

int main() {
    std::cout << "I love C++!\n";

    int rows = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}