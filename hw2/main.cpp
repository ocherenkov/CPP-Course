#include <iostream>
#include <iomanip>

enum class WeekDay {
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7,
};

int main() {
    // task 1
    int first;
    int second;
    int temp;
    std::cout << "Enter first number: ";
    std::cin >> first;
    std::cout << "Enter second number: ";
    std::cin >> second;
    temp = first;
    first = second;
    second = temp;
    std::cout << "First: " << first << std::endl << "Second: " << second << std::endl;

    // task 2
    double newDouble = 123.456;
    std::cout << "Double value: " << newDouble << std::endl;

    int newInt = int(newDouble);
    std::cout << "Int value: " << newInt << std::endl;
    std::cout << std::setw(20) << std::right << std::setfill('$') << newDouble << std::endl;

    // task 3
    double newerDouble = 123.456789;
    std::cout << "newerDouble value: " << newerDouble << std::endl;
    std::cout << "Precision 2: " << std::fixed << std::setprecision(2) << newerDouble << std::endl;
    std::cout << "Precision 5: " << std::fixed << std::setprecision(5) << newerDouble << std::endl;
    std::cout << "Precision 10: " << std::fixed << std::setprecision(10) << newerDouble << std::endl;
    std::cout << "Standard notation: " << std::defaultfloat << newerDouble << std::endl;
    std::cout << "Scientific notation: " << std::scientific << newerDouble << std::endl;

    // task 4
    WeekDay Monday = WeekDay::Monday;
    std::cout << "Monday: " << int(Monday) << std::endl;
    WeekDay Tuesday = WeekDay::Tuesday;
    std::cout << "Tuesday: " << int(Tuesday) << std::endl;
    WeekDay Wednesday = WeekDay::Wednesday;
    std::cout << "Wednesday: " << int(Wednesday) << std::endl;
    WeekDay Thursday = WeekDay::Thursday;
    std::cout << "Thursday: " << int(Thursday) << std::endl;
    WeekDay Friday = WeekDay::Friday;
    std::cout << "Friday: " << int(Friday) << std::endl;
    WeekDay Saturday = WeekDay::Saturday;
    std::cout << "Monday: " << int(Saturday) << std::endl;
    WeekDay Sunday = WeekDay::Sunday;
    std::cout << "Sunday: " << int(Sunday) << std::endl;

    // task 5
    int newestInt;
    std::cout << "Enter number: ";
    std::cin >> newestInt;
    std::cout << "Bool: " << std::boolalpha << bool(newestInt) << std::endl;
}