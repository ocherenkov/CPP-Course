#include "DynamicIntArray.h"
#include <algorithm>

DynamicIntArray::DynamicIntArray() : m_size(0), m_array(nullptr) {}

DynamicIntArray::DynamicIntArray(std::size_t size) : m_size(size) {
    m_array = new int[size];
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : m_size(other.m_size) {
    m_array = new int[m_size];
    std::copy(other.m_array, other.m_array + m_size, m_array);
}

DynamicIntArray::~DynamicIntArray() {
    delete[] m_array;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    if (this != &other) {
        delete[] m_array;
        m_size = other.m_size;
        m_array = new int[m_size];
        std::copy(other.m_array, other.m_array + m_size, m_array);
    }
    return *this;
}

int& DynamicIntArray::operator[](std::size_t index) {
    return m_array[index];
}

void DynamicIntArray::setSize(const std::size_t newSize) {
    int* newArray = new int[newSize];
    std::size_t copySize = std::min(m_size, newSize);
    std::copy(m_array, m_array + copySize, newArray);
    delete[] m_array;
    m_array = newArray;
    m_size = newSize;
}

std::size_t DynamicIntArray::getSize() const {
    return m_size;
}

void DynamicIntArray::clear() {
    delete[] m_array;
    m_array = nullptr;
    m_size = 0;
}

void DynamicIntArray::push_back(int element) {
    std::size_t newSize = m_size + 1;
    int* newArray = new int[newSize];
    std::copy(m_array, m_array + m_size, newArray);
    newArray[m_size] = element;
    delete[] m_array;
    m_array = newArray;
    m_size = newSize;
}