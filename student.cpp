#include "student.h"
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>


/*Default Constructor*/
Student::Student() {

	this->StudentID = "";
	this->FirstName = "";
	this->LastName = "";
	this->EmailAddress = "";
	this->Age = -1;

	for (int i = 0; i < ClassArraySize; i++)
	{
	this->DaysInCourse[i] = 0;
	}

	this->degreeProgram = DegreeProgram::UNDECLARED;
		

}

Student::Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse[], DegreeProgram degreeProgram) {

	this->StudentID = StudentID;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->EmailAddress = EmailAddress;
	this->Age = Age;
	for (int i = 0; i < ClassArraySize; i++)
	{
		this->DaysInCourse[i] = DaysInCourse[i];
	}

	this->degreeProgram = degreeProgram;

}

Student::~Student(){} /*Deconstructor*/

/*Getters i.e Accessors */

string Student::getStudentID() {
	return	StudentID;

}

string Student::getFirstName() {
	return FirstName;
}

string Student::getLastName() {
	return LastName;
}

string Student::getEmailAddress() {
	return EmailAddress;
}

int Student::getAge() {
	return	Age;

}

int* Student::getDaysInCourse() {
	return DaysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

/*Mutators i.e Setters*/

void Student::setStudentID(string StudentID) {

	this->StudentID = StudentID;
}

void Student::setFirstName(string FirstName) {

	this->FirstName = FirstName;
}

void Student::setLastName(string LastName) {

	this->LastName = LastName;
}

void Student::setEmailAddress(string EmailAddress) {

	this->EmailAddress = EmailAddress;
}

void Student::setAge(int Age) {

	this->Age = Age;
}

void Student::setDaysInCourse(int DaysInCourse[]) {
	for (int i = 0; i < ClassArraySize; i++)
	{
		this->DaysInCourse[i] = DaysInCourse[i];
	}

}


void Student::setDegreeProgram(DegreeProgram degreeProgram) {

	this->degreeProgram = degreeProgram;
}


void Student::print() {

	cout << "Student ID: " << this->getStudentID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Email Address: " << this->getEmailAddress() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "Days in Course: " << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << "Degree Program: " << DegreeProgramStrings[this->getDegreeProgram()];
}