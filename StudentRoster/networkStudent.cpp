/*
 * Language: C++
 * File:   networkStudent.cpp
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#include "student.h"
#include "networkStudent.h"
#include "degree.h"
using namespace std;

// Return student's degree as enum value
Degree networkStudent::GetDegreeProgram()
{
	return degree;
}

// Overload, returns string of student's degree program
string networkStudent::GetDegreeProgram(const Degree degree)
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

void networkStudent::Print()
{
	cout << "| " << GetStudentID() << "\t|"
		<< " First Name: | " << GetFirstName() << "\t|"
		<< " Last Name: | " << GetLastName() << "\t|"
		<< " Age: | " << GetAge() << "\t|"
		<< " DaysInCourse: | {" << GetDaysInCourse() << "}\t|"
		<< " Degree Program: | Network\t|\n";
	return;
}


// Default constructor
networkStudent::networkStudent()
{
}

// Constructor overload, initializes the degree data member
networkStudent::networkStudent(string studentID, string firstName, string lastName, string email, int age, int* daysInCourse, Degree netDegree) : Student(studentID, firstName, lastName, email, age, daysInCourse)
{
	cout << "Constructing networkStudent object . . .\n\n";
	degree = netDegree;
}

// Destructor
networkStudent::~networkStudent()
{
	cout << "Destructing networkStudent object . . .\n\n";
}
