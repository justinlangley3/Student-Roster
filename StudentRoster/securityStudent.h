/*
 * Language: C++
 * File:   securityStudent.h
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#ifndef __securityStudent_H
#define __securityStudent_H
#include "student.h"
#include "degree.h"
#include <iostream>

class securityStudent : public Student
{
public:
	/*
	 *	Virtual GetDegreeProgram() implementation
	 *	Checks the enumerator's value, and selects
	 *	the appropriate string to return
	 *
	 *	Prints error message if the student's degree
	 *	is stored incorrectly
	 */

	// Returns enum value of the student's degree program
	Degree GetDegreeProgram() override;
	// Overload returns string of the student's degree program
	string GetDegreeProgram(const Degree);

	// Virtual Print(), Prints all data for this student
	virtual void Print() override;

	// Default constructor
	securityStudent();

	// Constructor overload
	securityStudent(string, string, string, string, int, int*, Degree);

	// Destructor
	virtual ~securityStudent();

private:
	// Private data member(s)
	Degree degree;
};
#endif // __securityStudent_H
