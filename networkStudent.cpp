#include <iostream>
//  Include files
#include "networkStudent.h"
//  Constructors
NetworkStudent::NetworkStudent() {
    setStudentProgram (NETWORKING);
}
NetworkStudent::NetworkStudent(std::string id, std::string first, std::string last, std::string email, int age, int* courses, Degree program) {
    setStudentProgram (NETWORKING);
}
//  Getters
Degree NetworkStudent::getStudentProgram() {
    return NETWORKING;
}
//  Setters
void NetworkStudent::setStudentProgram(Degree program) {
    this->studentProgram = program;
}
//  Helpers
//  Note: CLion is telling me that this printStudent() function will recurse infinitely when called.
//        I see no reason why that is, it is obviously calling the superclass' printStudent function.
void NetworkStudent::printStudent() {
    this->Student::printStudent();
    std::cout << std::left << '\t' << ARRAY_OF_PROGRAM_NAMES[this->studentProgram] << std::endl;
}
//  Destructor
//NetworkStudent::~NetworkStudent() {
//    Student::~Student();
//}