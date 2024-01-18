#include <iostream>
#include <iomanip>

int main() {
    // task 1
    int playingSec = 0;
    std::cout << "Enter sec: ";
    std::cin >> playingSec;

    int seconds = playingSec % 60;
    int minutes = (playingSec / 60) % 60;
    int hours = playingSec / 3600;

    std::cout << hours << " h. " << minutes << " min. " << seconds << " sec. " << std::endl;

    // task 2
    int a, b, c;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
    std::cout << "Enter third number: ";
    std::cin >> c;

    std::cout << "Sum: " << a << "+" << b << "+" << c << " = " << a + b + c << std::endl;
    std::cout << "Avg: (" << a << "+" << b << "+" << c << ") / 3 = " << (static_cast<double>(a) + b + c) / 3 << std::endl;

    std::cout << a << " > " << b << "? - " << std::boolalpha << (a > b) << std::endl;
    std::cout << a << " = " << b << "? - " << std::boolalpha << (a == b) << std::endl;
    std::cout << a << " < " << b << "? - " << std::boolalpha << (a < b) << std::endl;
    std::cout << b << " > " << c << "? - " << std::boolalpha << (b > c) << std::endl;
    std::cout << b << " = " << c << "? - " << std::boolalpha << (b == c) << std::endl;
    std::cout << b << " < " << c << "? - " << std::boolalpha << (b < c) << std::endl;

    // task 3
    int x, y;
    std::cout << "Enter first number: ";
    std::cin >> x;
    std::cout << "Enter second number: ";
    std::cin >> y;

    bool lessThan = x < y;
    bool equal = x == y;
    bool moreThan = x > y;
    bool lessOrEqual = x <= y;

    std::cout << "lessThan: " << std::boolalpha << lessThan << std::endl;
    std::cout << "equal: " << std::boolalpha << equal << std::endl;
    std::cout << "moreThan: " << std::boolalpha << moreThan << std::endl;
    std::cout << "lessOrEqual: " << std::boolalpha << lessOrEqual << std::endl;

    // task 4
    int width, height;
    std::cout << "Enter width of rectangle: ";
    std::cin >> width;
    std::cout << "Enter height of rectangle: ";
    std::cin >> height;

    std::cout << "Width: " << width << std::endl << "Height: " << height << std::endl;
    std::cout << "Area of rectangle: " << width << " * " << height << " = " << width * height << std::endl;
    std::cout << "Perimeter of rectangle: 2 * (" << width << " + " << height << ") = " << 2 * (width + height) << std::endl;

    // task 5
    int radius;
    const double PI = 3.14;
    std::cout << "Enter circle radius: ";
    std::cin >> radius;

    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Area of circle: 3.14 * " << radius << "^2 = " << PI * radius * radius << std::endl;
    std::cout << "Length of circle: 2 * 3.14 * " << radius << " = " << 2 * PI * radius << std::endl;

    return 0;
}