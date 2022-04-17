/*
 * Language: C++
 * File:   roster.cpp
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

Roster::Roster()
{
	cout << "Constructing Roster . . .\n\n";
}

Roster::~Roster()
{
	cout << "Destructing Roster . . .\n\n";
}

// Add new student to the classRosterArray
void Roster::Add(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, Degree newDegree)
{
	int dic[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	if (newDegree == Degree::SOFTWARE)
	{
		classRosterArray[newIndex] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, dic, newDegree);
		newIndex++;
	}
	if (newDegree == Degree::NETWORK)
	{
		classRosterArray[newIndex] = new networkStudent(studentID, firstName, lastName, emailAddress, age, dic, newDegree);
		newIndex++;
	}
	if (newDegree == Degree::SECURITY)
	{
		classRosterArray[newIndex] = new securityStudent(studentID, firstName, lastName, emailAddress, age, dic, newDegree);
		newIndex++;
	}
}

// Print all students in the classRosterArray
void Roster::PrintAll()
{
	// Formatting		-tabular formatting of output, prints top border, and table header
	cout.width(138);
	cout.fill('-');
	cout << "\n";
	cout << "| Roster: ";
	cout.width(128);
	cout.fill(' ');
	cout << "|\n";
	cout.width(138);
	cout.fill('-');
	cout << "\n";
	// End Formatting

	for (int i = 0; i < 5; i++)
	{
		// Check that the index does not contain a null pointer,
		// necessary if objects have been previously deleted from an index
		if (classRosterArray[i] != nullptr)
		{
			// Print the Student Data at the valid index
			// Also, prints inner borders of table cells
			(*classRosterArray[i]).Print();
		}
	}

	// Formatting		-print bottom border of table
	cout.width(138);
	cout.fill('-');
	cout << "\n";
	cout << endl;
	// End Formatting
}

// Remove a student from the classRosterArray
void Roster::Remove(string studentID)
{
	bool removed = false;
	for (int i = 0; i < 5; i++)
	{
		// Check that the current index is not a null pointer,
		// and that it matches the studentID provided
		if ((classRosterArray[i] != nullptr) && (studentID == classRosterArray[i]->GetStudentID()))
		{
			cout << "Removing Student: " << studentID << " from the roster . . .\n\n";
			delete[] classRosterArray[i];	// Delete the object referenced by the pointer to avoid memory leaks
			classRosterArray[i] = nullptr;	// Change the index to a null pointer
			removed = true;					// Update the bool to true
		}
	}
	if (!removed) {
		// If the bool was not update to true, no student was removed, therefore not found
		cout << "Student with this ID: " << studentID << " was not found\n\n";
	}
}


// Print all students of a specific degree program
void Roster::PrintByDegreeProgram(Degree newDegree)
{
	string temp = "";

	// Used so we can print a string value of the enum
	switch (newDegree)
	{
	case Degree::SOFTWARE:
		temp = "Software";
		break;
	case Degree::NETWORK:
		temp = "Network";
		break;
	case Degree::SECURITY:
		temp = "Security";
		break;
	}

	// Formatting		-Create header, and top border
	cout.width(138);
	cout.fill('-');
	cout << "\n";
	cout << "| " << temp << " Student(s):";
	cout.width(124 - temp.length());
	cout.fill(' ');
	cout << "|\n";
	cout.width(138);
	cout.fill('-');
	cout << "\n";
	// End Formatting

	for (int i = 0; i < 5; i++)
	{
		if (newDegree == (*classRosterArray[i]).GetDegreeProgram())
		{
			// Print student data		-inner borders created inside of Print()
			(*classRosterArray[i]).Print();
		}
	}
	
	// Formatting		-Create bottom table border
	cout.width(139);
	cout.fill('-');
	cout << "\n\n";
	// End Formatting
}

// Print all invalid emails contained in classRosterArray
void Roster::PrintInvalidEmails()
{
	// Formatting		-create table header, and top border
	cout.width(138);
	cout.fill('-');
	cout << "\n" << "| Invalid E-mails:";
	cout.width(120);
	cout.fill(' ');
	cout << "|\n";
	cout.width(138);
	cout.fill('-');
	cout << "\n";
	// End Formatting

	/* Regular expression to check email pattern
	 * Pattern Format:
	 *		Local:	alphanumeric, underscores, and dots
	 *
	 *				@ symbol separator
	 *
	 *		Domain: alphanumeric only
	 *
	 *				. separator
	 *
	 *		TLD:	alphanumeric (2-4 chars in length)
	 */
	regex pattern("^[(_.a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z]{2,4}$");

	for (int i = 0; i < 5; i++)
	{
		// Retrieve student email
		string temp = (*classRosterArray[i]).GetEmail();

		// If the email does not match the pattern, print it out
		if (!regex_match(temp, pattern))
		{
			cout << "| Student [" << (*classRosterArray[i]).GetStudentID() << "] has invalid email: | " << temp;
			cout.width(102 - temp.length()); //	-Variable length fill for right border, subtracts email length from total line size
			cout.fill(' ');
			cout << "|\n";
		}
	}

	// Formatting		-Create bottom border
	cout.width(139);
	cout.fill('-');
	cout << "\n\n";
	// End Formatting
}

void Roster::PrintAverageDaysInCourse(string studentID)
{
	// Formatting		-create table header, and top border
	cout.width(138);
	cout.fill('-');
	cout << "\n" << "| Average days in each course:";
	cout.width(108);
	cout.fill(' ');
	cout << "|\n";
	cout.width(138);
	cout.fill('-');
	cout << "\n";
	// End Formatting
	
	for (int i = 0; i < 5; i++)
	{
		if ((*classRosterArray[i]).GetStudentID() == studentID)
		{
			// Stores average value
			int average = 0;

			for (int j = 0; j < 3; j++)
			{
				// Add values to average from the daysInCourse array
				average += (*classRosterArray[i]).GetDaysInCourse(j);
			}
			// Divide total by the size of daysInCourse array
			average = average / 3;

			// Print to screen
			cout << "| Student [" << studentID << "] average days in course: " << average;

			// Formatting		- Create inner borders
			long width = 132;
			width = width - average;
			cout.width(width); // variable length fill depending on length of numbers printed
			cout.fill(' ');
			cout << "|\n";
			// End Formatting
		}
	}

	// Formatting		-Create bottom border
	cout.width(139);
	cout.fill('-');
	cout << "\n\n";
	// End Formatting
}



int main(void) {
	cout << "C867: Scripting and Programming - Applications, C++,  Justin Langley,  Student ID: redacted\n\n";

	// Initial data table provided
	const string studentData[]
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Justin,Langley,redacted@wgu.edu,24,15,15,15,SOFTWARE"
	};

	// Create new Roster
	Roster classRoster;

	// Create new Degree
	Degree newDegree = Degree::SOFTWARE;

	// Extract student data from the table, and create new student objects
	for (int i = 0; i < 5; i++)
	{
		stringstream iss(studentData[i]);
		vector<string> newStudent;

		while (iss.good())
		{
			string substr;
			getline(iss, substr, ',');
			newStudent.push_back(substr);
		}
		if (newStudent[8] == "SOFTWARE")
		{
			newDegree = Degree::SOFTWARE;
		}
		else if (newStudent[8] == "NETWORK")
		{
			newDegree = Degree::NETWORK;
		}
		else
		{
			newDegree = Degree::SECURITY;
		}
		classRoster.Add(newStudent[0], newStudent[1], newStudent[2], newStudent[3],
			stoi(newStudent[4]), stoi(newStudent[5]),stoi(newStudent[6]), stoi(newStudent[7]), newDegree);
	}

	// Testing of all Roster functions
	classRoster.PrintAll();
	classRoster.PrintInvalidEmails();
	classRoster.PrintAverageDaysInCourse("A1");
	classRoster.PrintByDegreeProgram(Degree::SOFTWARE);
	classRoster.Remove("A3");
	classRoster.Remove("A3");
	cout << "Press Enter key to exit . . .\n";
	cin.get();
	return 0;
}
