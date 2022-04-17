/*
 * Language: C++
 * File:   student.cpp
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

/*
 *  Begin Student Accessors (Getters)
 */
string Student::GetStudentID()
{
	// Return studentID
	return studentID;
}

string Student::GetFirstName()
{
	// Return firstName
	return firstName;
}

string Student::GetLastName()
{
	// Return lastName
	return lastName;
}

string Student::GetEmail()
{
	// Return email
	return email;
}

int Student::GetAge()
{
	// Return age
	return age;
}

// GetDaysInCourse(), this returns a string version of the array
string Student::GetDaysInCourse()
{
	string retString = "";
	for (int i = 0; i < 3; i++)
	{
		if (i < 2)
		{
			// Append first two values to the string, comma separated
			retString += to_string(daysInCourse[i]) + ", ";
		}
		else
		{
			// Append last value to the string
			retString += to_string(daysInCourse[i]);
		}
	}
	// Return a string of daysInCourse[]
	return retString;
}

// GetDaysInCourse overload, used for numerical return values
int Student::GetDaysInCourse(int i)
{
	return daysInCourse[i];
}
/*
 *  End Student Accessors (Getters)
 */


/*  
 *  Begin Student Mutators (Setters)
 */ 
void Student::SetStudentID(string s)
{
	// Set studentID
	studentID = s;
	return;
}

void Student::SetFirstName(string n)
{
	// Set firstname
	firstName = n;
	return;
}

void Student::SetLastName(string n)
{
	// Set Last Name
	lastName = n;
	return;
}

void Student::SetAge(int a)
{
	// Set age
	age = a;
	return;
}

void Student::SetDaysInCourse(int i, int d)
{
	if (i > 2)
	{
		// Error checking to prevent invalid access to array
		cout << "Error: invalid index for Student::daysInCourse, valid indices are [0-2]" << endl << endl;
	}
	else if (i < 0)
	{
		// Error checking to prevent negative index values
		cout << "Error: invalid index for Student::daysInCourse, index must be a positive integer" << endl << endl;
	}
	else
	{
		// Set index 'i' of daysInCourse[] equal to days 'd'
		daysInCourse[i] = d;
	}
	return;
}

void Student::SetEmail(string s)
{
	// Set email
	email = s;
	return;
}
/*
 *  End Student Mutators (Setters)
 */


/*
 *  Virtual Get Degree Program (this implementation is overridden by derived classes)
 */
Degree Student::GetDegreeProgram()
{
	// Return enumerated type, overridden in derived classes
	return Degree::SOFTWARE;
}

/*  NOT USED
 *	void Student::SetDegree(string degree)
 *	{
 *		// Set degree
 *		degree = degree;
 *	}
 */

// Virtual Print, overridden by derived classes
void Student::Print()
{

}


// Default constructor
Student::Student()
{
	studentID = "";
	firstName = "";
	lastName  = "";
	email     = "";
	age = 0;
	daysInCourse[0] = 0;
	daysInCourse[1] = 0;
	daysInCourse[2] = 0;
}

// Constructor overload, initialize data members
Student::Student(string sid, string sfn, string sln, string se, int sa, int* dic)
{
	cout << "Constructing student object . . .\n\n";

	studentID = sid;
	firstName = sfn;
	lastName = sln;
	email = se;
	age = sa;
	daysInCourse[0] = dic[0];
	daysInCourse[1] = dic[1];
	daysInCourse[2] = dic[2];
}

// Destructor
Student::~Student()
{
	cout << "Destructing student object . . .\n\n";
}
