/*
 * Language: C++
 * File:   networkStudent.h
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#ifndef __networkStudent_H
#define __networkStudent_H
#include "student.h"
#include "degree.h"
#include <iostream>

class networkStudent : public Student
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
	// Overload, returns string of student's degree program
	string GetDegreeProgram(const Degree);

	// Virtual Print(), prints all data for this student
	virtual void Print() override;

	// Default constructor
	networkStudent();
	// Constructor overload
	networkStudent(string, string, string, string, int, int*, Degree);
	// Destructor
	virtual ~networkStudent();

private:
	// Private data member(s)
	Degree degree;
};
#endif // __networkStudent_H
