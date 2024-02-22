#include <iostream>
#include "Vector2d.h"
#include "Vector3d.h"

int main() {
    // task 1
    Vector2d vector(1, 2, 4, 6);

    std::cout << std::endl << "[TASK 1.a]" << std::endl;
    std::cout << "Vector: (" << vector.getX() << ", " << vector.getY() << ")" << std::endl;
    std::cout << std::endl;

    Vector2d vector1(2.0f, 3.0f);
    Vector2d vector2(4.0f, 5.0f);

    std::cout << std::endl << "[TASK 1.b]" << std::endl;
    std::cout << "Vector1: (" << vector1.getX() << ", " << vector1.getY() << ")" << std::endl;
    std::cout << "Vector2: (" << vector2.getX() << ", " << vector2.getY() << ")" << std::endl;
    std::cout << "Scalar product of vector1 and vector2: " << vector1.dotProduct(vector2) << std::endl;
    std::cout << std::endl;

    Vector2d invertedVector = vector.negate();

    std::cout << std::endl << "[TASK 1.d]" << std::endl;
    std::cout << "Original vector: (" << vector.getX() << ", " << vector.getY() << ")" << std::endl;
    std::cout << "Inverted vector: (" << invertedVector.getX() << ", " << invertedVector.getY() << ")" << std::endl;
    std::cout << std::endl;

    VectorRelativeState relativeState = vector1.getRelativeState(vector2);

    std::cout << std::endl << "[TASK 1.e]" << std::endl;
    std::cout << "Vector1: (" << vector1.getX() << ", " << vector1.getY() << ")" << std::endl;
    std::cout << "Vector2: (" << vector2.getX() << ", " << vector2.getY() << ")" << std::endl;
    switch (relativeState) {
        case VectorRelativeState::Identical:
            std::cout << "Vectors are identical." << std::endl;
            break;
        case VectorRelativeState::CoDirected:
            std::cout << "Vectors are co-directed." << std::endl;
            break;
        case VectorRelativeState::OppositeDirected:
            std::cout << "Vectors are opposite-directed." << std::endl;
            break;
        case VectorRelativeState::AcuteAngle:
            std::cout << "Vectors form acute angle." << std::endl;
            break;
        case VectorRelativeState::ObtuseAngle:
            std::cout << "Vectors form obtuse angle." << std::endl;
            break;
        case VectorRelativeState::RightAngle:
            std::cout << "Vectors form right angle." << std::endl;
            break;
    }
    std::cout << std::endl;

    std::cout << std::endl << "[TASK 1.f]" << std::endl;
    std::cout << "Vector: (" << vector.getX() << ", " << vector.getY() << ")" << std::endl;
    vector.scale(2.0f, 3.0f);
    std::cout << "Scaled vector coordinates: (" << vector.getX() << ", " << vector.getY() << ")" << std::endl;
    std::cout << std::endl;

    Vector3d vector3(1.0f, 2.0f, 3.0f);
    Vector3d vector4(4.0f, 5.0f, 6.0f);

    Vector3d resultVector = vector3.crossProduct(vector4);
    std::cout << std::endl << "[TASK 1.c]" << std::endl;
    std::cout << "Vector3: (" << vector3.getX() << ", " << vector3.getY() << ", " << vector3.getZ() << ")" << std::endl;
    std::cout << "Vector4: (" << vector4.getX() << ", " << vector4.getY() << ", " << vector4.getZ() << ")" << std::endl;
    std::cout << "Cross product vector: (" << resultVector.getX() << ", " << resultVector.getY() << ", " << resultVector.getZ() << ")" << std::endl;
    std::cout << std::endl;

    return 0;
}