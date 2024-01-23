class Rectangle {
private:
    float m_length;
    float m_height;

public:
    Rectangle();
    Rectangle(float length, float height);

    float getArea();
    float getPerimeter();
};