#include <iostream>
#include "Vector2d.h"

int main() {
    // task 1
    Vector2d zeroVector;
    Vector2d firstVector(2, 2.5);
    Vector2d vec1(1.0, 2.0);
    Vector2d vec2(3.0, 4.0);

    std::cout << std::endl << "[TASK 1]" << std::endl;
    std::cout << "Vector1: " << zeroVector << std::endl;
    std::cout << "Vector2: " << firstVector << std::endl;
    std::cout << std::endl;

    // task 1.a
    zeroVector = firstVector;
    std::cout << std::endl << "[TASK 1.a]" << std::endl;
    std::cout << "Vector1 after assignment: " << zeroVector << std::endl;
    std::cout << std::endl;

    // task 1.b
    Vector2d sum = vec1.operator+(vec2);
    Vector2d diff = vec1.operator-(vec2);

    std::cout << std::endl << "[TASK 1.b]" << std::endl;
    std::cout << "Vector1: " << vec1 << std::endl;
    std::cout << "Vector2: " << vec2 << std::endl;
    std::cout << "Sum of vectors: " << sum << std::endl;
    std::cout << "Diff of vectors: " << diff << std::endl;
    std::cout << std::endl;

    // task 1.с
    Vector2d fSum = operator+(vec1,vec2);
    Vector2d fDiff = operator-(vec2, vec1);

    std::cout << std::endl << "[TASK 1.c]" << std::endl;
    std::cout << "Vector1: " << vec1 << std::endl;
    std::cout << "Vector2: " << vec2 << std::endl;
    std::cout << "Friend | Sum of vectors: " << fSum << std::endl;
    std::cout << "Friend | Diff of vectors: " << fDiff << std::endl;
    std::cout << std::endl;

    // task 1.d
    std::cout << std::endl << "[TASK 1.d]" << std::endl;
    std::cout << "Vector: " << vec1 << std::endl;
    std::cout << "Length of vector: " << vec1() << std::endl;
    std::cout << std::endl;

    // task 1.e
    std::cout << std::endl << "[TASK 1.e]" << std::endl;
    std::cout << "Vector: " << vec1 << std::endl;
    std::cout << "x: " << vec1[0] << ", y: " << vec1[1] << std::endl;
    std::cout << std::endl;

    // task 1.f && 1.g
    std::cout << std::endl << "[TASK 1.f && 1.g]" << std::endl;
    Vector2d testVec;
    std::cout << "Enter first and second point of vector (separated by space): " << std::endl;
    std::cin >> testVec;
    std::cout << testVec << std::endl;
    std::cout << std::endl;

    // task 1.h
    std::cout << std::endl << "[TASK 1.h]" << std::endl;
    std::cout << "Active instances count: " << Vector2d::getActiveInstancesCount() << std::endl;
    std::cout << std::endl;

    return 0;
}