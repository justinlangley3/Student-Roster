/*
 * Language: C++
 * File:   roster.h
 *
 * Author: Justin Langley
 * Student ID: redacted
 *
 * Course: C867 - Programming & Scripting - Applications
 * Modified on July 8, 2019, 1:58 PM
 */

#ifndef __roster_H
#define __roster_H
#include "student.h"

class Roster
{
public:
	// Public Roster functions

	// Used for incrementing through classRosterArray
	int newIndex = 0;

	// Add new student to the classRosterArray
	void Add(string studentID, string firstName, string lastName,
		string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, Degree degree);

	// Remove a student from the classRosterArray
	void Remove(string);

	// Print all students in the classRosterArray
	void PrintAll();

	// Print days in course for a student by searching studentID
	void PrintAverageDaysInCourse(string);

	// Print all students with invalid emails
	void PrintInvalidEmails();

	// Print all students of a specific degree program
	void PrintByDegreeProgram(Degree);


	// Constructor
	Roster();

	// Destructor
	virtual ~Roster();


private: // Private data members


	// For creating array to hold student objects
	Student *classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

};
#endif // __roster_H
