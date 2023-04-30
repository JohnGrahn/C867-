#pragma once
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

class Student {

public:
	/* Array for holding number of classes always 3 */

	const static int ClassArraySize = 3;



private:
	/*Variables accessible only internally/ locally*/

	string StudentID;
	string FirstName;
	string LastName;
	string EmailAddress;
	int Age;
	int DaysInCourse[ClassArraySize];
	DegreeProgram degreeProgram;



public:
	/*Getters, setters, methods, and Constructors/ Deconstructors*/

	/*Constructors and Deconstuctors*/
	Student(); /*default*/
	Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse[], DegreeProgram degreeProgram);/*Full Contructor*/
	~Student();/*Deconstructor*/


	/*Getters i.e Accessors */
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();


	/*Mutators i.e Setters*/
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int Age);
	void setDaysInCourse(int classArraySize[]);
	void setDegreeProgram(DegreeProgram degreeProgram);


	/*Method*/

	
	void print(); /*Print() for student information*/

};