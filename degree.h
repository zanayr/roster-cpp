#pragma once
#include <string>

//  Define an enum that will hold integer values relating to the degree programs held by
//  students in the roster. Set the first value to start at 0.
enum Degree {NETWORKING = 0, SECURITY, SOFTWARE};

//  I have mapped the enum values to an array containing string values of the enum names
//  in order to make printing them out easier.
const std::string ARRAY_OF_PROGRAM_NAMES[] = {"NETWORKING", "SECURITY", "SOFTWARE"};