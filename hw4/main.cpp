#include <iostream>

enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    // task 1
    int a, b, c, maxNum;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
    std::cout << "Enter third number: ";
    std::cin >> c;

    if (a > b) {
        maxNum = a;
    } else if (b > c) {
        maxNum = b;
    } else {
        maxNum = c;
    }

    std::cout << "Max number: " << maxNum << std::endl;

    // task 2
    int x, y;
    std::cout << "Enter first number: ";
    std::cin >> x;
    std::cout << "Enter second number: ";
    std::cin >> y;

    std::cout << "Min number: " << (x > y ? y : x) << std::endl;

    // task 3
    int number;
    std::cout << "Enter number: ";
    std::cin >> number;

    if (number % 5 == 0 && number % 11 == 0) {
        std::cout << "Number " << number << " is divisible by both 5 and 11." << std::endl;
    } else {
        std::cout << "Number " << number << " is not divisible by both 5 and 11." << std::endl;
    }

    // task 4
    int A, B, C;
    std::cout << "Enter first angles of triangle: ";
    std::cin >> A;
    std::cout << "Enter second angles of triangle: ";
    std::cin >> B;
    std::cout << "Enter third angles of triangle: ";
    std::cin >> C;

    if (A + B + C == 180) {
        std::cout << "These angles can form triangle." << std::endl;
    } else {
        std::cout << "These angles can not form triangle." << std::endl;
    }

    // task 5
    int monthNum;
    std::cout << "Enter number in range 1-12: ";
    std::cin >> monthNum;

    if (monthNum < 1 || monthNum > 12) {
        std::cout << "Error" << std::endl;
    } else {
        Month month = static_cast<Month>(monthNum);
        switch (month) {
            case Month::January:
                std::cout << "January" << std::endl;
                break;
            case Month::February:
                std::cout << "February" << std::endl;
                break;
            case Month::March:
                std::cout << "March" << std::endl;
                break;
            case Month::April:
                std::cout << "April" << std::endl;
                break;
            case Month::May:
                std::cout << "May" << std::endl;
                break;
            case Month::June:
                std::cout << "June" << std::endl;
                break;
            case Month::July:
                std::cout << "July" << std::endl;
                break;
            case Month::August:
                std::cout << "August" << std::endl;
                break;
            case Month::September:
                std::cout << "September" << std::endl;
                break;
            case Month::October:
                std::cout << "October" << std::endl;
                break;
            case Month::November:
                std::cout << "November" << std::endl;
                break;
            case Month::December:
                std::cout << "December" << std::endl;
                break;
        }
    }

    // task 6
    int numMonth;
    std::cout << "Enter number in range 1-12: ";
    std::cin >> numMonth;

    if (numMonth < 1 || numMonth > 12) {
        std::cout << "Error" << std::endl;
    } else {
        switch (numMonth) {
            case 1:
            case 2:
            case 12:
                std::cout << "Winter" << std::endl;
                break;
            case 3:
            case 4:
            case 5:
                std::cout << "Spring" << std::endl;
                break;
            case 6:
            case 7:
            case 8:
                std::cout << "Summer" << std::endl;
                break;
            case 9:
            case 10:
            case 11:
                std::cout << "Autumn" << std::endl;
                break;
        }
    }

    return 0;
}
