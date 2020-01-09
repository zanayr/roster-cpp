#include <iostream>
//  Include files
#include "softwareStudent.h"
//  Constructors
SoftwareStudent::SoftwareStudent() {
    setStudentProgram (SOFTWARE);
}
SoftwareStudent::SoftwareStudent(std::string id, std::string first, std::string last, std::string email, int age, int* courses, Degree program) {
    setStudentProgram (SOFTWARE);
}
//  Getters
Degree SoftwareStudent::getStudentProgram() {
    return SOFTWARE;
}
//  Setters
void SoftwareStudent::setStudentProgram(Degree program) {
    this->studentProgram = SOFTWARE;
}
//  Helpers
//  Note: CLion is telling me that this printStudent() function will recurse infinitely when called.
//        I see no reason why that is, it is obviously calling the superclass' printStudent function.
void SoftwareStudent::printStudent() {
    this->Student::printStudent();
    std::cout << std::left << '\t' << ARRAY_OF_PROGRAM_NAMES[this->studentProgram] << std::endl;
}
//  Destructor
//SoftwareStudent::~SoftwareStudent() {
//    Student::~Student();
//}