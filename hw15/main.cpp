#include <iostream>
#include <iomanip>
#include <algorithm>

const int NUM_MARKS = 4;
const int NUM_STUDENTS = 5;

struct Student {
    std::string name;
    int marks[NUM_MARKS];
};

// task a
double calculateAverage(const Student& student) {
    int sum = 0;
    for (int i = 0; i < NUM_MARKS; ++i) {
        sum += student.marks[i];
    }
    return static_cast<double>(sum) / NUM_MARKS;
}

// task c
bool compareStudents(const Student& a, const Student& b) {
    return calculateAverage(a) > calculateAverage(b);
}

// task d
Student* findTopStudent(Student students[], int size) {
    if (size == 0) {
        return nullptr;
    }

    Student* topStudent = &students[0];
    for (int i = 1; i < size; ++i) {
        if (calculateAverage(students[i]) > calculateAverage(*topStudent)) {
            topStudent = &students[i];
        }
    }

    return topStudent;
}

// task e
int countStudentsByAvgMarks(Student students[], int size, double minAvg) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (calculateAverage(students[i]) > minAvg) {
            ++count;
        }
    }
    return count;
}

int main() {
    // task b
    Student students[NUM_STUDENTS] = {
            {"Alice", {80, 85, 90, 95}},
            {"Bruno", {75, 78, 80, 82}},
            {"Carmilla", {60, 70, 80, 90}},
            {"Diggie", {65, 75, 85, 95}},
            {"Edith", {60, 63, 66, 69}}
    };
    std::cout << "Students:" << std::endl;
    std::cout << std::setw(15) << std::left << "Name";
    for (int i = 1; i <= NUM_MARKS; ++i) {
        std::cout << std::setw(8) << std::right << "Mark" << i;
    }
    std::cout << std::endl;

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        std::cout << std::setw(15) << std::left << students[i].name;
        for (int j = 0; j < NUM_MARKS; ++j) {
            std::cout << std::setw(9) << std::right << students[i].marks[j];
        }
        std::cout << std::endl;
    }

    std::sort(students, students + NUM_STUDENTS, compareStudents);
    std::cout << std::endl;
    std::cout << "Students sorted by average marks:" << std::endl;
    std::cout << std::setw(15) << std::left << "Name";
    for (int i = 1; i <= NUM_MARKS; ++i) {
        std::cout << std::setw(8) << std::right << "Mark" << i;
    }
    std::cout << std::setw(10) << std::right << "Average";
    std::cout << std::endl;

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        std::cout << std::setw(15) << std::left << students[i].name;
        for (int j = 0; j < NUM_MARKS; ++j) {
            std::cout << std::setw(9) << std::right << students[i].marks[j];
        }
        std::cout << std::setw(10) << std::right << calculateAverage(students[i]);
        std::cout << std::endl;
    }

    Student* topStudent = findTopStudent(students, NUM_STUDENTS);
    if (topStudent != nullptr) {
        std::cout << std::endl;
        std::cout << "Top Student: " << topStudent->name << ", average - "
                  << calculateAverage(*topStudent) << std::endl;
    }

    double minAvg = 75.0;
    int studentsCount = countStudentsByAvgMarks(students, NUM_STUDENTS, minAvg);
    std::cout << std::endl;
    std::cout << "Number of students with average marks > " << minAvg << ": " << studentsCount << std::endl;

    return 0;
}