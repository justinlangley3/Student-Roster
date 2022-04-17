/*
 * Language: C++
 * File:   softwareStudent.h
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#ifndef __softwareStudent_H
#define __softwareStudent_H
#include "student.h"
#include "degree.h"
#include <iostream>

class softwareStudent : public Student
{
public:
	/*
	*	Virtual getDegreeProgram() implementation
	*	Checks the enumerator's value, and selects
	*	the appropriate string to return
	*
	*	Prints error message if the student's degree
	*	is stored incorrectly
	*/

	// Returns enum value of the student's degree program
	Degree GetDegreeProgram() override;
	// Overload, returns string of student's degree program
	string GetDegreeProgram(const Degree);

	// Virtual Print()
	virtual void Print() override;

	// Default constructor
	softwareStudent();
	// Constructor overload
	softwareStudent(string, string, string, string, int, int*, Degree);
	// Destructor
	virtual ~softwareStudent();

private:
	// Private data member(s)
	Degree degree;
};
#endif // __softwareStudent_H
