#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
    if (arrSize <= 0) {
        return false;
    }

    sum = 0.0;
    for (int i = 0; i < arrSize; ++i) {
        sum += arr[i];
    }
    return true;
}

bool find(const int* arr, int size, int elem) {
    const int* last = arr + size;

    while (arr < last) {
        if (*arr == elem) {
            return true;
        }
        ++arr;
    }

    return false;
}

void task1() {
    std::cout << std::endl << "[TASK 1]" << std::endl;
    int x = 5, y = 10;
    std::cout << "Before swapping: x = " << x << ", y = " << y << std::endl;

    swap(x, y);
    std::cout << "Reference swapping: x = " << x << ", y = " << y << std::endl;

    swap(&x, &y);
    std::cout << "Pointer swapping: x = " << x << ", y = " << y << std::endl;
    std::cout << std::endl;
}

void task2() {
    std::cout << std::endl << "[TASK 2]" << std::endl;
    const int arrSize = 5;
    double arr[arrSize] = {1.3, 2.5, 3.5, 4, 5};
    double sum;

    if (!calculateSum(arr, arrSize, sum)) {
        std::cout << "Error." << std::endl;
    } else {
        std::cout << "Sum: " << sum << std::endl;
    }
    std::cout << std::endl;
}

void task3() {
    std::cout << std::endl << "[TASK 3]" << std::endl;
    const int size = 5;
    int arr[size] = {1, 3, 5, 10, 25};
    int elem = 3;

    if (find(arr, size, elem)) {
        std::cout << "Element "<< elem << " found in array." << std::endl;
    } else {
        std::cout << "Element not found in array." << std::endl;
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

    return 0;
}