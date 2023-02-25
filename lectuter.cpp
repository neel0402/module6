#include <iostream>
#include <string>

class Lecture {
private:
    std::string lecturerName;
    std::string subjectName;
    std::string courseName;
    int numLectures;
public:
    void assignValues(std::string lecturerName, std::string subjectName, std::string courseName, int numLectures) {
        this->lecturerName = lecturerName;
        this->subjectName = subjectName;
        this->courseName = courseName;
        this->numLectures = numLectures;
    }
    void addLectureDetails() {
        std::cout << "Enter lecturer name: ";
        std::cin >> lecturerName;
        std::cout << "Enter subject name: ";
        std::cin >> subjectName;
        std::cout << "Enter course name: ";
        std::cin >> courseName;
        std::cout << "Enter number of lectures: ";
        std::cin >> numLectures;
    }
    void displayDetails() {
        std::cout << "Lecturer name: " << lecturerName << std::endl;
        std::cout << "Subject name: " << subjectName << std::endl;
        std::cout << "Course name: " << courseName << std::endl;
        std::cout << "Number of lectures: " << numLectures << std::endl;
    }
};

int main() {
    const int NUM_LECTURERS = 5;
    Lecture lectures[NUM_LECTURERS];

    for (int i = 0; i < NUM_LECTURERS; i++) {
        std::cout << "Enter details for lecturer #" << i + 1 << ":" << std::endl;
        std::string lecturerName, subjectName, courseName;
        int numLectures;
        std::cout << "Enter lecturer name: ";
        std::cin >> lecturerName;
        std::cout << "Enter subject name: ";
        std::cin >> subjectName;
        std::cout << "Enter course name: ";
        std::cin >> courseName;
        std::cout << "Enter number of lectures: ";
        std::cin >> numLectures;
        lectures[i].assignValues(lecturerName, subjectName, courseName, numLectures);
    }

    for (int i = 0; i < NUM_LECTURERS; i++) {
        std::cout << "Details for lecturer #" << i + 1 << ":" << std::endl;
        lectures[i].displayDetails();
        std::cout << std::endl;
    }

    return 0;
}
