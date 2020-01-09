#pragma once
#include <string>
//  Included files
#include "degree.h"
#include "student.h"
//  SoftwareStudent class is derived from the Student class.
class SoftwareStudent : public Student {
public:
    //  Constructor
    SoftwareStudent();
    SoftwareStudent(std::string id, std::string first, std::string last, std::string email, int age, int* courses, Degree program);
    //  Getters
    //  Note: This getStudentProgram() will override the virtual member function in the parent class.
    Degree getStudentProgram() override;
    //  Setters
    //  Note: This setStudentProgram() will override the virtual member function in the parent class.
    void setStudentProgram(Degree program) override;
    //  Helpers
    //  Note: This printStudent() will override the virtual member function in the parent class.
    void printStudent() override;
    //  Note: Since no new fields were created by this subclass, no new definition for the destructor is needed. Only
    //        the superclass's destructor needs to be called.
    //  Destructor
    //~SoftwareStudent() override;
};