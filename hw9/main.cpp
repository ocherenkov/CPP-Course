#include <iostream>

void translateArray(int numbers[], int size) {
    for (int i = 0; i < size; ++i) {
        if (numbers[i] > 0) {
            numbers[i] *= 2;
            std::cout << numbers[i] << " ";
        } else {
            numbers[i] = 0;
            std::cout << numbers[i] << " ";
        }
    }
}

void toUppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

bool isPalindrom(const char str[]) {
    int length = std::strlen(str);

    for (int i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount) {
    vowelsCount = 0;
    consonantsCount = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        char currentChar = std::tolower(str[i]);

        if (std::isalpha(currentChar)) {
            if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' ||
                currentChar == 'o' || currentChar == 'u') {
                ++vowelsCount;
            } else {
                ++consonantsCount;
            }
        }
    }
}

bool isEqual(const char str1[], const char str2[]) {
    int i = 0;

    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

void task1() {
    const int size = 10;
    int numbers[size];

    std::cout << std::endl << "[TASK 1]" << std::endl;
    std::cout << "Enter 10 numbers for array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> numbers[i];
    }
    translateArray(numbers, size);
    std::cout << std::endl;
}

void task2() {
    const int size = 100;
    char str[size];
    std::cout << std::endl << "[TASK 2]" << std::endl;
    std::cout << "Enter string: ";
    std::cin >> str;

    toUppercase(str);
    std::cout << str << std::endl;
    std::cout << std::endl;
}

void task3() {
    const int size = 100;
    char str[size];
    std::cout << std::endl << "[TASK 3]" << std::endl;
    std::cout << "Enter string: ";
    std::cin >> str;

    std::cout << "Is " << str << " palindrome? - " << std::boolalpha << isPalindrom(str) << std::endl;
    std::cout << std::endl;
}


void task4() {
    const int size = 100;
    int vowelsCount, consonantsCount;
    char str[size];
    std::cout << std::endl << "[TASK 4]" << std::endl;
    std::cout << "Enter string: ";
    std::cin >> str;

    parseStringLetters(str, vowelsCount, consonantsCount);

    std::cout << "String: " << str << std::endl;
    std::cout << "String length: " << std::strlen(str) << std::endl;
    std::cout << "Vowels: " << vowelsCount << std::endl;
    std::cout << "Consonants: " << consonantsCount << std::endl;
    std::cout << std::endl;
}

void task5() {
    const int size = 100;
    char str1[size];
    char str2[size];
    std::cout << std::endl << "[TASK 5]" << std::endl;
    std::cout << "Enter first string: ";
    std::cin >> str1;

    std::cout << "Enter second string: ";
    std::cin >> str2;

    std::cout << "First string: " << str1 << std::endl << "Second string: " << str2 << std::endl;
    if (isEqual(str1, str2)) {
        std::cout << "Entered strings are equal.";
    } else {
        std::cout << "Entered strings are not equal.";
    }
    std::cout << std::endl;
}

int main() {
    // task1
    task1();

    // task2
    task2();

    // task3
    task3();

    // task4
    task4();

    // task5
    task5();

    return 0;
}