#include <iostream>

const int ROWS = 3;
const int COLUMNS = 3;

enum SortingDirection { ascending, descending };

bool find(int arr_2d[ROWS][COLUMNS], int toFind) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (arr_2d[i][j] == toFind) {
                return true;
            }
        }
    }
    return false;
}

bool isSorted(const int* arr, int size, SortingDirection direction) {
    if (size <= 1) {
        return true;
    }

    if (direction == ascending) {
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
    } else if (direction == descending) {
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}

void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS]) {
    for (int col = COLUMNS - 1; col >= 0; --col) {
        if (col % 2 == 0) {
            for (int row = 0; row < ROWS; ++row) {
                std::cout << arr_2d[row][col] << " ";
            }
        } else {
            for (int row = 0; row < ROWS; ++row) {
                std::cout << arr_2d[row][col] << " ";
            }
        }
    }
    std::cout << std::endl;
}

void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS]) {
    for (int row = ROWS - 1; row >= 0; --row) {
        if (row % 2 == 0) {
            for (int col = 0; col < COLUMNS; ++col) {
                std::cout << arr_2d[row][col] << " ";
            }
        } else {
            for (int col = COLUMNS - 1; col >= 0; --col) {
                std::cout << arr_2d[row][col] << " ";
            }
        }
    }
    std::cout << std::endl;
}

void task1() {
    std::cout << std::endl << "[TASK 1]" << std::endl;
    int arr_2d[ROWS][COLUMNS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };
    int element = 5;

    if (find(arr_2d, element)) {
        std::cout << "Element " << element << " found in array." << std::endl;
    } else {
        std::cout << "Element "<< element << " not found in array." << std::endl;
    }
    std::cout << std::endl;
}

void task2() {
    std::cout << std::endl << "[TASK 2]" << std::endl;
    const int size = 5;
    int ascArray[size] = {1, 2, 3, 4, 5};
    int descArray[size] = {5, 4, 3, 2, 1};
    //int array[size] = {1, 4, 2, 5, 3};

    if (isSorted(ascArray, size, ascending)) {
        std::cout << "Array is sorted in ascending order." << std::endl;
    } else {
        std::cout << "Array is not sorted in ascending order." << std::endl;
    }

    if (isSorted(descArray, size, descending)) {
        std::cout << "Array is sorted in descending order." << std::endl;
    } else {
        std::cout << "Array is not sorted in descending order." << std::endl;
    }
    std::cout << std::endl;
}

void task3() {
    std::cout << std::endl << "[TASK 3]" << std::endl;
    int arr_2d[ROWS][COLUMNS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

    std::cout << "Raversing top down right left by columns:" << std::endl;
    traverseTopDownRightLeftByColumns(arr_2d);

    std::cout << "Raversing left right down top switching by rows:" << std::endl;
    traverseLeftRightDownTopSwitchingByRows(arr_2d);
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