#include <iostream>

const unsigned int ROWS = 3;
const unsigned int COLUMNS = 3;

enum SortingDirection
{
    ByRows,
    ByColumns
};

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print2dArray(int arr[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//Sort in ascending way using the bubble sort algorithm
//Input:  5 1 9 7 3
//Output: 1 3 5 7 9
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    // idx of greater element
    int pointerIdx = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            pointerIdx++;

            // swap element at i with element at j
            std::swap(array[pointerIdx], array[j]);
        }
    }

    std::swap(array[pointerIdx + 1], array[high]);

    return (pointerIdx + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int partition_idx = partition(array, low, high);
        quickSort(array, low, partition_idx - 1);
        quickSort(array, partition_idx + 1, high);
    }
}

void quickSort2(int* arrayBeg, int* arrayEnd)
{
    const int size = arrayEnd - arrayBeg;
    quickSort(arrayBeg, 0, size - 1);
}

//Sort 2d array using any algorithm (custom quicksort, std::sort, implemented above Bubble Sort
// or using new implementation in-place)
//Input: ByRows
// 1, 5, 4
// 3, 8, 6
// 9, 5, 1
//Output:
// 1, 4, 5
// 3, 6, 8
// 1, 5, 9

//Input: ByColumns
// 1, 5, 4
// 3, 8, 6
// 9, 5, 1
//Output:
// 1, 5, 1
// 3, 5, 4
// 9, 8, 6

void sort(int arr[ROWS][COLUMNS], SortingDirection direction)
{
    if (direction == SortingDirection::ByRows) {
        for (int i = 0; i < ROWS; i++) {
            quickSort(arr[i], 0, COLUMNS - 1);
        }
    } else if (direction == SortingDirection::ByColumns) {
        for (int i = 0; i < COLUMNS; i++) {
            int column[COLUMNS];
            for (int j = 0; j < ROWS; j++) {
                column[j] = arr[j][i];
            }
            quickSort(column, 0, ROWS - 1);
            for (int j = 0; j < ROWS; j++) {
                arr[j][i] = column[j];
            }
        }
    }
}

void task1() {
    std::cout << std::endl << "[TASK 1]" << std::endl;
    const int size = 5;
    int arr[size] = {5, 1, 9, 7, 3};

    std::cout << "Input array:  ";
    printArray(arr, size);

    bubbleSort(arr, size);
    std::cout << "Output array: ";
    printArray(arr, size);
    std::cout << std::endl;
}

void task2() {
    std::cout << std::endl << "[TASK 2]" << std::endl;
    int arr_2d[ROWS][COLUMNS] = {
        {1, 5, 4},
        {3, 8, 6},
        {9, 5, 1}
    };
    std::cout << "Array:" << std::endl;
    print2dArray(arr_2d);

    sort(arr_2d, SortingDirection::ByRows);
    std::cout << "Sorted by rows:" << std::endl;
    print2dArray(arr_2d);

    sort(arr_2d, SortingDirection::ByColumns);
    std::cout << "Sorted by columns:" << std::endl;
    print2dArray(arr_2d);
    std::cout << std::endl;
}


int main() {
    // task1
    task1();

    // task2
    task2();

    return 0;
}