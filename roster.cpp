#include <vector>
#include <string>
#include <sstream>
#include <iostream>
//  Included files
#include "roster.h"
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
//  The parseString() helper function should take a string that is delimited by commas, and return a vector
//  of all the tokens in the string.
std::vector<std::string> parseString(const std::string &line, const char delimit) {
    std::vector<std::string> returnVector;
    std::stringstream studentString(line);
    while (studentString.good()) {
        std::string subString;
        getline(studentString, subString, delimit);
        returnVector.push_back(subString);
    }
    return returnVector;
}
//  Constructors
Roster::Roster() {
    this->studentCapacity = 0;
    this->studentIndex = -1;
    //  Note: classRosterArray will point to an array of all the students.
    this->classRosterArray = nullptr;
}
Roster::Roster(int capacity) {
    this->studentCapacity = capacity;
    this->studentIndex = -1;
    this->classRosterArray = new Student*[capacity];
}
//  The add() member function should take a string of student data that is delimited by commas
//  (for an example of how the data should be formatted, see roster.h) and create a student object
//  of the appropriate class, with all of its data members set to their correct values. If the
//  student data that is entered is incorrect, or does not match the global STUDENT_COUNT number,
//  the program will let the user know and exit the program to avoid errors.
void Roster::add(std::string data) {
    if (this->studentIndex < this->studentCapacity) {
        this->studentIndex++; //  NOTE: This is an index and not a count of the number of students!
        int tempCoursesArray[Student::studentCoursesArraySize];
        std::vector<std::string> tempStringVector = parseString(data, ',');
        if (tempStringVector.at(8) == "NETWORK") {
            this->classRosterArray[studentIndex] = new NetworkStudent();
            this->classRosterArray[studentIndex]->setStudentProgram(NETWORKING);
        } else if (tempStringVector.at(8) == "SECURITY") {
            this->classRosterArray[studentIndex] = new SecurityStudent();
            this->classRosterArray[studentIndex]->setStudentProgram(SECURITY);
        } else if (tempStringVector.at(8) == "SOFTWARE") {
            this->classRosterArray[studentIndex] = new SoftwareStudent();
            this->classRosterArray[studentIndex]->setStudentProgram(SOFTWARE);
        } else {
            std::cerr << "[ERROR]: BAD STUDENT DATA! EXITING PROGRAM!" << std::endl;
            std::cout << "[NOTE]: INCORRECT DEGREE PROGRAM ENTERED." << std::endl;
            std::exit(-1);
        }
        this->classRosterArray[this->studentIndex]->setStudentID(tempStringVector.at(0));
        this->classRosterArray[this->studentIndex]->setStudentFirstName(tempStringVector.at(1));
        this->classRosterArray[this->studentIndex]->setStudentLastName(tempStringVector.at(2));
        this->classRosterArray[this->studentIndex]->setStudentEmail (tempStringVector.at(3));
        this->classRosterArray[this->studentIndex]->setStudentAge(std::stoi(tempStringVector.at(4)));
        for (int i = 0; i < Student::studentCoursesArraySize; i++) {
            tempCoursesArray[i] = std::stoi(tempStringVector.at(i + 5));
        }
        this->classRosterArray[this->studentIndex]->setStudentCourses(tempCoursesArray);
    } else {
        std::cerr << "[ERROR]: BAD STUDENT DATA! EXITING PROGRAM!";
        std::cout << "[NOTE]: NUMBER OF STUDENTS HAS EXCEEDED ROSTER CAPACITY." << std::endl;
        std::exit(-1);
    }
}
//  The printAll() member function should iterate through all of the students and call
//  their individual member print functions.
void Roster::printAllStudents() {
    for (int i = 0; i <= this->studentIndex; i++) {
        (this->classRosterArray)[i]->printStudent();
    }
}
//  The remove() member function should iterate through the classRosterArray array of students
//  remove (delete) a student from the roster's array of students. If no student matches the
//  given ID, a boolean value of false will be returned and the program will let the user know.
void Roster::remove(std::string id) {
    bool studentFound = false;
    for (int i = 0; i <= this->studentIndex; i++) {
        if (this->classRosterArray[i]->getStudentID() == id) {
            studentFound = true;
            delete this->classRosterArray[i];
            // Note: After the student is found and deleted, the remaining elements in the array are shifted down one
            //       index. Resulting in a smaller array and then decrementing the index by one.
            for (int j = i; j <= this->studentIndex - 1; j++) {
                this->classRosterArray[j] = this->classRosterArray[j + 1];
            }
            this->classRosterArray[this->studentIndex] = nullptr;
            this->studentIndex--;
        }
    }
    if (!studentFound) {
        std::cout << "STUDENT " << id << " WAS NOT FOUND!" << std::endl;
    }
}
//  The printAverageCourseHours() member function should take a student's id number and
//  print an average of the student's course hours. If the student does not exist, the
//  program will let the user know.
void Roster::printAverageCourseHours(std::string id) {
    bool studentFound = false;
    for (int i = 0; i <= this->studentIndex; ++i) {
        if (this->classRosterArray[i]->getStudentID() == id) {
            studentFound = true;
            int* courses = classRosterArray[i]->getStudentCourses();
            //  NOTE: The course values are convered to doubles for more accuracy in the average.
            std::cout << "STUDENT " << id << ": AVERAGE COURSE HOURS: " << static_cast<double>((courses[0] + courses[1] + courses[2])) / 3.0 << std::endl;
        }
    }
    if (!studentFound) {
        std::cout << "STUDENT " << id << " WAS NOT FOUND!" << std::endl;
    }
}
//  The printInvalidEmail() member function should iterate through all students and find
//  any invalid email accounts (having spaces), and print those to the screen. If no invalid
//  emails are found, the program will let the user know.
void Roster::printInvalidEmails() {
    bool studentFound = false;
    std::cout << "ALL INVALID EMAILS:" << std::endl;
    for (int i = 0; i <= this->studentIndex; i++) {
        std::string email = this->classRosterArray[i]->getStudentEmail();
        if (email.find (' ') != std::string::npos) {
            studentFound = true;
            std::cout << "STUDENT " << this->classRosterArray[i]->getStudentID() << ": " << email << std::endl;
        }
    }
    if (!studentFound) {
        std::cout << "NO INVALID STUDENT EMAILS FOUND! " << std::endl;
    }
}
//  The printByDegreeProgram() member function should iterate though the entire classRosterArray
//  array to print all students that match the enumeration value passed to the function. if no
//  matches are found, the program will let the user know.
void Roster::printByDegreeProgram(Degree program) {
    bool studentFound = false;
    std::cout << "ALL " << ARRAY_OF_PROGRAM_NAMES[program] << " STUDENTS:" << std::endl;
    for (int i = 0; i <= this->studentIndex; i++) {
        if (this->classRosterArray[i]->getStudentProgram() == program) {
            studentFound = true;
            this->classRosterArray[i]->printStudent();
        }
    }
    if (!studentFound) {
        std::cout << "NO " << ARRAY_OF_PROGRAM_NAMES[program] << " STUDENT FOUND!" << std::endl;
    }
}
//  Destructor
Roster::~Roster() {
    std::cout << "DELETING ENTIRE ROSTER..." << std::endl;
    for (int i = 0; i < this->studentCapacity; i++) {
        delete this->classRosterArray[i];
    }
}
//  Main function definition
int main() {
    Roster* roster = new Roster(NUM_STUDENTS);
    for (int i = 0; i < roster->studentCapacity; i++) {
        roster->add(studentData[i]);
    }
    std::cout << std::endl;
    roster->printAllStudents();
    std::cout << std::endl;
    roster->printInvalidEmails();
    std::cout << std::endl;
    for (int i = 0; i < roster->studentCapacity; i++) {
        roster->printAverageCourseHours(roster->classRosterArray[i]->getStudentID());
    }
    std::cout << std::endl;
    roster->printByDegreeProgram(SOFTWARE);
    std::cout << std::endl;
    roster->remove("A3");
    std::cout << std::endl;
    roster->remove("A3");
    std::cout << std::endl;
    delete roster;
    return 0;
}