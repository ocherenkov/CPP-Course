#include "Rectangle.h"

Rectangle::Rectangle() : m_length(0.0f), m_height(0.0f) {}
Rectangle::Rectangle(float length, float height) : m_length(length), m_height(height) {}

float Rectangle::getArea() {
    return m_length * m_height;
}

float Rectangle::getPerimeter() {
    return 2 * (m_length + m_height);
}