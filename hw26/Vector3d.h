#include "Vector2d.h"

class Vector3d : public Vector2d {
public:
    Vector3d();
    Vector3d(float x, float y, float z);

    Vector3d crossProduct(const Vector3d& other) const;

    float getZ() const;
    void setZ(float z);

private:
    float m_z;
};