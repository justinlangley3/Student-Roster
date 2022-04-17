/*
 * Language: C++
 * File:   student.h
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#ifndef __student_H
#define __student_H
#include "degree.h"
#include <string>
#include <array>
#include <iostream>
using namespace std;

class Student
{
public:
	// Public functions

	// Student Accessors (Getters)
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	string GetDaysInCourse();
	int GetDaysInCourse(int);

	// Student Mutators (Setters)
	void SetStudentID(string);
	void SetFirstName(string);
	void SetLastName(string);
	void SetEmail(string);
	void SetAge(int);
	void SetDaysInCourse(int, int);

	// NOT USED:	void SetDegree(string);

	// Implemented in Subclasses (softwareStudent, networkStudent, & securityStudent)
	virtual Degree GetDegreeProgram();
	// Implemented in Subclasses (softwareStudent, networkStudent, & securityStudent)
	virtual void Print();

	// Default constructor
	Student();
	// Constructor overload
	Student(string, string, string, string, int, int*);
	// Destructor, virtual allows use in subclasses
	virtual ~Student();


private:
	// Private data members

	string studentID, firstName, lastName, email;
	int age;
	int daysInCourse[3];

};
#endif // __student_H
