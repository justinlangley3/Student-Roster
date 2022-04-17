/*
 * Language: C++
 * File:   softwareStudent.cpp
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#include "student.h"
#include "softwareStudent.h"
#include "degree.h"
using namespace std;

// Return student's degree as enum value
Degree softwareStudent::GetDegreeProgram()
{
	return degree;
}

// Overload, returns string of student's degree program
string softwareStudent::GetDegreeProgram(const Degree degree)
{
	string retString = "";

	switch (this->degree)
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

void softwareStudent::Print()
{
	cout << "| " << GetStudentID() << "\t|"
		<< " First Name: | " << GetFirstName() << "\t|"
		<< " Last Name: | " << GetLastName() << "\t|"
		<< " Age: | " << GetAge() << "\t|"
		<< " DaysInCourse: | {" << GetDaysInCourse() << "}\t|"
		<< " Degree Program: | Software\t|\n";
	return;
}


// Default Constructor
softwareStudent::softwareStudent()
{
}

// Constructor overload, initializes the degree data member
softwareStudent::softwareStudent(string studentID, string firstName, string lastName, string email, int age, int* daysInCourse, Degree softDegree) : Student(studentID, firstName, lastName, email, age, daysInCourse)
{
	cout << "Constructing softwareStudent object . . .\n\n";
	degree = softDegree;
}

// Destructor
softwareStudent::~softwareStudent()
{
	cout << "Destructing softwareStudent object . . .\n\n";
}
