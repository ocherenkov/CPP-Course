#include "Vector3d.h"

Vector3d::Vector3d() : Vector2d(), m_z(0.0f) {}

Vector3d::Vector3d(float x, float y, float z) : Vector2d(x, y), m_z(z) {}

Vector3d Vector3d::crossProduct(const Vector3d& other) const {
    float crossX = getY() * other.getZ() - getZ() * other.getY();
    float crossY = getZ() * other.getX() - getX() * other.getZ();
    float crossZ = getX() * other.getY() - getY() * other.getX();
    return Vector3d(crossX, crossY, crossZ);
}

float Vector3d::getZ() const {
    return m_z;
}

void Vector3d::setZ(float z) {
    m_z = z;
}