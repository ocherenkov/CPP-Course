#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>

template<typename T>
class DynamicArray
{
public:
    DynamicArray() : m_size(0), m_capacity(0), m_array(nullptr) {}

    DynamicArray(std::size_t size) : m_size(size), m_capacity(size), m_array(new T[size]) {
        std::fill_n(m_array, size, T());
    }

    DynamicArray(const DynamicArray& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_array(new T[other.m_capacity]) {
        std::copy(other.m_array, other.m_array + other.m_size, m_array);
    }

    ~DynamicArray() {
        delete[] m_array;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] m_array;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_array = new T[other.m_capacity];
            std::copy(other.m_array, other.m_array + other.m_size, m_array);
        }
        return *this;
    }

    T& operator[](std::size_t index) {
        return m_array[index];
    }

    void setSize(std::size_t newSize) {
        T* newArray = new T[newSize];
        std::copy(m_array, m_array + std::min(m_size, newSize), newArray);
        delete[] m_array;
        m_array = newArray;
        m_capacity = newSize;
        m_size = newSize;
    }

    std::size_t getSize() const {
        return m_size;
    }

    void clear() {
        delete[] m_array;
        m_array = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    void push_back(const T& element) {
        if (m_size == m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_array[m_size++] = element;
    }

    void pop_back() {
        if (m_size > 0) {
            m_size--;
        }
    }

    T back() const {
        if (m_size > 0) {
            return m_array[m_size - 1];
        }
    }

    void reserve(std::size_t reservedSpace) {
        if (reservedSpace > m_capacity) {
            T* newArray = new T[reservedSpace];
            std::copy(m_array, m_array + m_size, newArray);
            delete[] m_array;
            m_array = newArray;
            m_capacity = reservedSpace;
        }
    }

    std::size_t getCapacity() const {
        return m_capacity;
    }

    void shrinkToFit() {
        if (m_capacity > m_size) {
            T* newArray = new T[m_size];
            std::copy(m_array, m_array + m_size, newArray);
            delete[] m_array;
            m_array = newArray;
            m_capacity = m_size;
        }
    }

    bool operator==(const DynamicArray& other) const {
        if (m_size != other.m_size) {
            return false;
        }
        for (std::size_t i = 0; i < m_size; ++i) {
            if (m_array[i] != other.m_array[i]) {
                return false;
            }
        }
        return true;
    }

    void printArray() {
        for (std::size_t i = 0; i < m_size; ++i) {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    std::size_t m_size;
    std::size_t m_capacity;
    T* m_array;
};