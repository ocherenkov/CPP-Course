#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void printStringVector(const std::vector<std::string>& vector) {
    for (const std::string& str : vector) {
        std::cout << str << std::endl;
    }
    std::cout << std::endl;
}

void printIntVector(const std::vector<int>& vector) {
    for (const int& i : vector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

bool compareByLength(const std::string& first, const std::string& second) {
    return first.length() < second.length();
}

class LengthComparator {
public:
    bool operator()(const std::string& first, const std::string& second) const {
        return first.length() < second.length();
    }
};

auto compareByLengthLambda = [](const std::string& first, const std::string& second) {
    return first.length() < second.length();
};

int countDivisibleBy(const std::vector<int>& vec, int number) {
    return std::count_if(vec.begin(), vec.end(), [number](int x) { return x % number == 0; });
}

void task1(std::vector<std::string> vector) {
    std::cout << std::endl << "[TASK 1.a]" << std::endl;
    std::cout << "Original vector:" << std::endl;
    printStringVector(vector);
    std::sort(vector.begin(), vector.end(), compareByLength);
    std::cout << "Sorted vector:" << std::endl;
    printStringVector(vector);
    std::cout << std::endl;
}

void task2(std::vector<std::string> vector) {
    std::cout << std::endl << "[TASK 1.b]" << std::endl;
    std::cout << "Original vector:" << std::endl;
    printStringVector(vector);
    std::sort(vector.begin(), vector.end(), LengthComparator());
    std::cout << "Sorted vector:" << std::endl;
    printStringVector(vector);
    std::cout << std::endl;
}

void task3(std::vector<std::string> vector) {
    std::cout << std::endl << "[TASK 1.с]" << std::endl;
    std::cout << "Original vector:" << std::endl;
    printStringVector(vector);
    std::sort(vector.begin(), vector.end(), compareByLengthLambda);
    std::cout << "Sorted vector:" << std::endl;
    printStringVector(vector);
    std::cout << std::endl;
}

void task4() {
    std::vector<int> intContainer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int divisible = 4;
    int result = countDivisibleBy(intContainer, divisible);

    std::cout << std::endl << "[TASK 2]" << std::endl;
    std::cout << "Vector: ";
    printIntVector(intContainer);
    std::cout << "Count divisible by - " << divisible << ": " << result << std::endl;
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> stringContainer = {
            "abcdef",
            "abc",
            "ab",
            "abcd",
            "abcde",
    };

    // task 1.a
    task1(stringContainer);

    // task 1.b
    task2(stringContainer);

    // task 1.c
    task3(stringContainer);

    // task 2
    task4();

    return 0;
}