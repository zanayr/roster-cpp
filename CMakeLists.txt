cmake_minimum_required(VERSION 3.12)
project(Task1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task1 Student.h Student.cpp Degree.h softwareStudent.h SoftwareStudent.cpp networkStudent.h networkStudent.cpp securityStudent.h securityStudent.cpp roster.h roster.cpp)