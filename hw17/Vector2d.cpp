#include "Vector2d.h"
#include <iostream>

int Vector2d::activeInstancesCount = 0;

Vector2d::Vector2d() : m_x(0.0f), m_y(0.0f) {
    activeInstancesCount++;
}

Vector2d::Vector2d(float x, float y) : m_x(x), m_y(y) {
    activeInstancesCount++;
}

Vector2d::~Vector2d() {
    activeInstancesCount--;
}

Vector2d& Vector2d::operator=(const Vector2d& other) {
    if (this != &other) {
        m_x = other.m_x;
        m_y = other.m_y;
    }
    return *this;
}

Vector2d Vector2d::operator+(const Vector2d& other) const {
    return Vector2d(m_x + other.m_x, m_y + other.m_y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) const {
    return Vector2d(m_x - secondVector.m_x, m_y - secondVector.m_y);
}

float Vector2d::operator()() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

float& Vector2d::operator[](int i) {
    if (i == 0) {
        return m_x;
    } else if (i == 1) {
        return m_y;
    } else {
        return m_x;
    }
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.m_x + rightVector.m_x, leftVector.m_y + rightVector.m_y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.m_x - rightVector.m_x, leftVector.m_y - rightVector.m_y);
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vector) {
    os << "{" << vector.m_x << "; " << vector.m_y << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2d& vec) {
    is >> vec.m_x >> vec.m_y;
    return is;
}

float Vector2d::getX() const {
    return m_x;
}

float Vector2d::getY() const {
    return m_y;
}

void Vector2d::setX(float x) {
    m_x = x;
}

void Vector2d::setY(float y) {
    m_y = y;
}

void Vector2d::getInfo() const {
    std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
}

int Vector2d::getActiveInstancesCount() {
    return activeInstancesCount;
}