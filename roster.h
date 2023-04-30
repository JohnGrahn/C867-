#pragma once
#include "student.h"
#include "degree.h"

class Roster {

public:
	int LastStudent; /*Last Student in Array*/
	int StudentCount;/*Roster size*/
	Student** ClassRosterArray; /*Pointer Array*/


	Roster();/*Default Constructor*/
	Roster(int StudentCount); /*Full Constructor */
	~Roster();/*DeConstructor*/

	void parse(string data);
	void add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, DegreeProgram degreeProgram);
	void remove(string StudentID);
	void printAll();
	void printAverageDaysInCourse(string StudentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	DegreeProgram transmute(string DegreeString);

};
