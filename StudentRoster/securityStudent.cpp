/*
 * Language: C++
 * File:   securityStudent.cpp
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#include "student.h"
#include "securityStudent.h"
#include "degree.h"
using namespace std;

// Return student's degree as enum value
Degree securityStudent::GetDegreeProgram()
{
	return degree;
}

// Overload, returns string of student's degree program
string securityStudent::GetDegreeProgram(const Degree degree)
{
	string retString = "";

	switch (degree)
	{
	case Degree::SOFTWARE:
		retString = "SOFTWARE";
		break;
	case Degree::SECURITY:
		retString = "SECURITY";
		break;
	case Degree::NETWORK:
		retString = "NETWORK";
		break;
	}
	return retString;
}

void securityStudent::Print()
{
	cout << "| " << GetStudentID() << "\t|"
		<< " First Name: | " << GetFirstName() << "\t|"
		<< " Last Name: | " << GetLastName() << "\t|"
		<< " Age: | " << GetAge() << "\t|"
		<< " DaysInCourse: | {" << GetDaysInCourse() << "}\t|"
		<< " Degree Program: | Security\t|\n";
	return;
}


// Default constructor
securityStudent::securityStudent()
{
}

// Constructor overload, initializes the degree data member
securityStudent::securityStudent(string studentID, string firstName, string lastName, string email, int age, int* daysInCourse, Degree secDegree) : Student(studentID, firstName, lastName, email, age, daysInCourse)
{
	cout << "Constructing securityStudent object . . .\n\n";
	degree = secDegree;
}

// Destructor
securityStudent::~securityStudent()
{
	cout << "Destructing securityStudent object . . .\n\n";
}
