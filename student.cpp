#include <iostream>
#include <iomanip>
//  Included files
#include "student.h"
#include "degree.h"
//  Constructors
Student::Student(){
    this->studentID = "";
    this->studentFirstName = "";
    this->studentLastName = "";
    this->studentEmail = "";
    this->studentAge = 0;
    //  Note: Do not forget to destroy the studentCourses array in the ~Student() destructor.
    //        (This is because the actual data member only holds a pointer to the array)
    this->studentCourses = new int[studentCoursesArraySize];
    for (int i = 0; i < studentCoursesArraySize; ++i) {
        this->studentCourses[i] = 0;
    }
    //  Note: The studentProgram member data is set in the derived classes of Student.
}
Student::Student(std::string id, std::string first, std::string last, std::string email, int age, int courses[], Degree program) {
    this->studentID = id;
    this->studentFirstName = first;
    this->studentLastName = last;
    this->studentEmail = email;
    this->studentAge = age;
    this->studentCourses = new int[studentCoursesArraySize];
    // Populate course array.
    for (int i = 0; i < studentCoursesArraySize; ++i) {
        this->studentCourses[i] = courses[i];
    }
    //  Note: The studentProgram member data is set in the derived classes of Student.
}
//  Getters
//  Note: that they are forbidden from mutating their respective values.
//  Note: getStudentProgram is defined in the derived student classes.
std::string Student::getStudentID() const {
    return this->studentID;
}
std::string Student::getStudentFirstName() const {
    return this->studentFirstName;
}
std::string Student::getStudentLastName() const {
    return this->studentLastName;
}
std::string Student::getStudentEmail() const {
    return this->studentEmail;
}
int Student::getStudentAge() const {
    return this->studentAge;
}
int* Student::getStudentCourses() const {
    return this->studentCourses;
}
//  Setters
void Student::setStudentID(std::string id) {
    this->studentID = id;
}
void Student::setStudentFirstName(std::string first) {
    this->studentFirstName = first;
}
void Student::setStudentLastName(std::string last) {
    this->studentLastName = last;
}
void Student::setStudentEmail(std::string email) {
    this->studentEmail = email;
}
void Student::setStudentAge(int age) {
    this->studentAge = age;
}
void Student::setStudentCourses(int courses[]) {
    //  Note: Clear the old array of courses before a new array of courses in set to the data member.
    if (this->studentCourses != nullptr) {
        delete[] this->studentCourses;
        this->studentCourses = nullptr;
    }
    this->studentCourses = new int[studentCoursesArraySize];
    for (int i = 0; i < studentCoursesArraySize; ++i) {
        this->studentCourses[i] = courses[i];
    }
}
//  Helpers
void Student::printStudent() {
    std::cout << '\t' << this->getStudentID();
    std::cout << '\t' << this->getStudentFirstName();
    std::cout << '\t' << this->getStudentLastName();
    std::cout << '\t' << this->getStudentEmail();
    std::cout << '\t' << this->getStudentAge();
    for (int i = 0; i < studentCoursesArraySize; i++) {
        std::cout << '\t' << this->studentCourses[i];
    }
}
//  Destructor
//  Note: Don't forget to delete the studentCourses array!
Student::~Student() {
    std::cout << "DELETING STUDENT " << this->getStudentID() << "..." << std::endl;
    if (this->studentCourses != nullptr) {
        delete[] this->studentCourses;
        this->studentCourses = nullptr;
    }
}