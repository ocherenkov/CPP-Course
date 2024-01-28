#include <iostream>
#include "DynamicArray.h"

int main() {
    DynamicArray<int> m_container;
    m_container.reserve(4);
    m_container.push_back(25);
    m_container.push_back(30);
    m_container.push_back(10);
    m_container.push_back(39);

    std::cout << "Array: ";
    m_container.printArray();
    std::cout << "Array size: " << m_container.getSize() << ", capacity: " << m_container.getCapacity() << std::endl;
    m_container.push_back(55);
    std::cout << "Array after added new element: ";
    m_container.printArray();
    std::cout << "Array size: " << m_container.getSize() << ", capacity: " << m_container.getCapacity() << std::endl;
    std::cout << "Last element of array: " << m_container.back() << std::endl;
    m_container.pop_back();
    std::cout << "Last element of array after pop: " << m_container.back() << std::endl;
    m_container.shrinkToFit();
    std::cout << "After shrink array size: " << m_container.getSize() << ", capacity: " << m_container.getCapacity() << std::endl;
    std::cout << std::endl;

    DynamicArray<double> m_container1;
    m_container1.reserve(4);
    m_container1.push_back(2.5);
    m_container1.push_back(3.1);
    m_container1.push_back(1.3);
    m_container1.push_back(3.9);
    std::cout << "Array double: ";
    m_container1.printArray();
    std::cout << std::endl;

    DynamicArray<int> m_container2;
    m_container2 = m_container;
    std::cout << "arr1: ";
    m_container.printArray();
    std::cout << "arr2: ";
    m_container2.printArray();
    std::cout << "is arr2 equal to arr1? " << std::boolalpha << m_container2.operator==(m_container) << std::endl;
    std::cout << std::endl;

    m_container2.pop_back();
    std::cout << "arr1: ";
    m_container.printArray();
    std::cout << "arr2: ";
    m_container2.printArray();
    std::cout << "is arr1 equal to arr2? " << std::boolalpha << m_container.operator==(m_container2) << std::endl;
    return 0;
}