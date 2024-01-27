#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    DynamicIntArray array1;
    DynamicIntArray array2;
    for (int i = 0; i < 10; i++) {
        int element = (i + 2) * 2;
        array1.push_back(element);
        std::cout << array1[i] << std::endl;
    }

    array2 = array1;
    array2.clear();

    std::cout << "Array1 size: " << array1.getSize() << std::endl;
    std::cout << "Array2 size: " << array2.getSize() << std::endl;
}