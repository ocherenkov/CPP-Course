#include <iostream>

class Vector2d {
public:
    Vector2d();
    Vector2d(float x, float y);

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

    void getInfo() const;
    static int getActiveInstancesCount();

private:
    float m_x;
    float m_y;
    static int activeInstancesCount;
};