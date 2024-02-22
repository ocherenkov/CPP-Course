#pragma once
#include <iostream>

enum class VectorRelativeState {
    Identical,
    CoDirected,
    OppositeDirected,
    AcuteAngle,
    ObtuseAngle,
    RightAngle
};

class Vector2d {
public:
    Vector2d();
    Vector2d(float x, float y);
    // new
    Vector2d(float x0, float y0, float x1, float y1);
    // end new
    ~Vector2d();

    Vector2d& operator=(const Vector2d& other);
    Vector2d operator+(const Vector2d& secondVector) const;
    Vector2d operator-(const Vector2d& secondVector) const;
    float operator()() const;
    float& operator[](int i);

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector);
    friend std::istream& operator>>(std::istream& is, Vector2d& vector);


    float getX() const;
    float getY() const;

    void setX(float x);
    void setY(float y);

    void printInfo() const;
    static int getActiveInstancesCount();

    // new
    float dotProduct(const Vector2d& other) const;
    Vector2d negate() const;
    VectorRelativeState getRelativeState(const Vector2d& other) const;
    void scale(float factorX, float factorY);
    // end new


private:
    float m_x;
    float m_y;
    static int activeInstancesCount;
};