#include <iostream>
//  Include files
#include "securityStudent.h"
//  Constructors
SecurityStudent::SecurityStudent() {
    setStudentProgram (SECURITY);
}
SecurityStudent::SecurityStudent(std::string id, std::string first, std::string last, std::string email, int age, int* courses, Degree program) {
    setStudentProgram (SECURITY);
}
//  Getters
Degree SecurityStudent::getStudentProgram() {
    return SECURITY;
}
//  Setters
void SecurityStudent::setStudentProgram(Degree program) {
    this->studentProgram = SECURITY;
}
//  Helpers
//  Note: CLion is telling me that this printStudent() function will recurse infinitely when called.
//        I see no reason why that is, it is obviously calling the superclass' printStudent function.
void SecurityStudent::printStudent() {
    this->Student::printStudent ();
    std::cout << std::left << '\t' << ARRAY_OF_PROGRAM_NAMES[this->studentProgram] << std::endl;
}
//  Destructor
//SecurityStudent::~SecurityStudent() {
//    Student::~Student ();
//}