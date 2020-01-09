#pragma once
//  Included files
#include "degree.h"
//  Student class
class Student {
protected:
    std::string studentID;
    std::string studentFirstName;
    std::string studentLastName;
    std::string studentEmail;
    int studentAge;
    //  Note: The studentCourses member will be an array of three integers.
    int* studentCourses;
    //  Note: The studentProgram member should be an enumerated value. (See degree.h for more information)
    Degree studentProgram;
public:
    //  Note: The studentCourseArraySize is set to static to ensure that derived classes can access it.
    static const int studentCoursesArraySize = 3;
    //  Constructors
    Student();
    Student(std::string id, std::string first, std::string last, std::string email, int age, int courses[], Degree program);
    //  Getters
    //  Note: The getters are forbidden from mutating their respective values.
    std::string getStudentID() const;
    std::string getStudentFirstName() const;
    std::string getStudentLastName() const;
    std::string getStudentEmail() const;
    int getStudentAge() const;
    int* getStudentCourses() const;
    //  Note: The getStudentProgram is a virtual member function. This will be overridden in the subclasses
    //        derived from the Student class.
    virtual Degree getStudentProgram() = 0;
    //  Setters
    void setStudentID(std::string id);
    void setStudentFirstName(std::string first);
    void setStudentLastName(std::string last);
    void setStudentEmail(std::string email);
    void setStudentAge(int age);
    //  Note: Arrays passed to functions are automatically passed by reference.
    void setStudentCourses(int courses[]);
    virtual void setStudentProgram(Degree program) = 0;
    //  Helpers
    virtual void printStudent() = 0;
    //  Destructor
    virtual ~Student() = 0;
};