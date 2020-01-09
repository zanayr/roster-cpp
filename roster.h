#pragma once
#include <string>
#include <iostream>
//  Included files
#include "student.h"

//  Set the global constant for the number of students.
//  NOTE: Do not forget to update this number if you add or remove student data from the studentData array.
const int NUM_STUDENTS = 5;

//  Create the array of student data that will be entered into the program.
//  All student data should be entered in the following format!
//  "[ID],[First],[Last],[Email],[Age],[Course1],[Course2],[Course3],[Program]"
//  NOTE: There are no spaces following the comma delimiter or in any of the individual data fields.
//  NOTE: If you add student with a different program name, don't forget to add the name to the
//        Degree enumeration and ARRAY_OF_PROGRAM_NAMES array of strings.
std::string studentData[NUM_STUDENTS] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ryan,Fickenscher,rficken@wgu.edu,31,15, 18, 13,SOFTWARE"
};

//  Declare Roster class.
//  NOTE: The classRosterArray will be a pointer to an array of pointers to student objects.
class Roster {
public:
    //  Public member data
    int studentIndex;
    int studentCapacity;
    Student** classRosterArray; // Pointer to an array of pointers
    //  Public Constructors
    Roster();
    Roster(int capacity); //  Overloaded constructor
    //  Public member functions
    void add(std::string data);
    void remove(std::string id);
    void printAllStudents();
    void printAverageCourseHours(std::string id);
    void printInvalidEmails();
    void printByDegreeProgram(Degree program);
    //  Public destructor
    ~Roster();
};