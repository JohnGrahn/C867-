#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


Roster::Roster() {

	this->StudentCount = 0;
	this->LastStudent = -1;
	this->ClassRosterArray = nullptr;

}

Roster::Roster(int StudentCount) {

	this->StudentCount = StudentCount;
	this->LastStudent = -1;
	this->ClassRosterArray = new Student * [StudentCount];


}

Roster::~Roster() {
	for (int i = 0; i < StudentCount; i++)
	{
		delete this->ClassRosterArray[i];
	}
	delete this;

}

void Roster::parse(string Data) {
    vector<string> InfoHolder; 
    stringstream inputStream(Data);

    while (inputStream.good())  { 
        string Input;
        getline(inputStream, Input, ',');
        InfoHolder.push_back(Input);
    }
    add(InfoHolder.at(0),
        InfoHolder.at(1),
        InfoHolder.at(2), 
        InfoHolder.at(3),
        stoi(InfoHolder.at(4)), 
        stoi(InfoHolder.at(5)),
        stoi(InfoHolder.at(6)), 
        stoi(InfoHolder.at(7)),
        transmute(InfoHolder.at(8)) 
    );
}

DegreeProgram Roster::transmute(string DegreeString) {
    if (DegreeString == "SECURITY") return SECURITY;
    else if (DegreeString == "NETWORK") return NETWORK;
    else if (DegreeString == "SOFTWARE") return SOFTWARE;
    else return UNDECLARED;

}



void Roster::add(string StudentID, string FirstName, string LastName, string EmailAdddress, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, DegreeProgram degreeProgram) {

    if (LastStudent < StudentCount) {

        LastStudent++;
        this->ClassRosterArray[LastStudent] = new Student();
        this->ClassRosterArray[LastStudent]->setStudentID(StudentID);
        this->ClassRosterArray[LastStudent]->setFirstName(FirstName);
        this->ClassRosterArray[LastStudent]->setLastName(LastName);
        this->ClassRosterArray[LastStudent]->setEmailAddress(EmailAdddress);
        this->ClassRosterArray[LastStudent]->setAge(Age);
        int Days[3] = {DaysInCourse1, DaysInCourse2, DaysInCourse3};
        this->ClassRosterArray[LastStudent]->setDaysInCourse(Days);
        this->ClassRosterArray[LastStudent]->setDegreeProgram(degreeProgram);

    }

    else {
        cout << endl << "Roster has reached maximum capacity of students" << endl;

    }

}

void Roster::printAll() {

    cout << endl << "Viewing all students" << endl << endl;

    for (int i = 0; i <= this->LastStudent; i++) {
        
        (this->ClassRosterArray)[i]->print();
        cout << endl;
    }
    cout << endl;
}

void Roster::remove(string StudentID) {

    bool found = false;

    for (int i = 0; i <= LastStudent; i++) {

        if (this->ClassRosterArray[i]->getStudentID() == StudentID) {

            found = true;
            delete this->ClassRosterArray[i];
            this->ClassRosterArray[i] = this->ClassRosterArray[LastStudent];
            LastStudent--;

            cout << "Removed Student with ID: " << StudentID << endl;

        }

    }

    if (!found) {
        cout << "Student ID: " << StudentID << " not found" << endl;
    }


}

void Roster::printAverageDaysInCourse(string StudentID) {
     
    bool found = false;

    for (int i = 0; i <= LastStudent; i++) {

        if (this->ClassRosterArray[i]->getStudentID() == StudentID) {

            found = true;
            int* Days = this->ClassRosterArray[i]->getDaysInCourse();
            double AverageDays = static_cast<double>(Days[0] + Days[1] + Days[2]) / 3.0;

            cout << "Average of the days spent in each course for Student " << StudentID << " is: " << AverageDays <<  endl << endl;

        }

        
    }

    if (!found) {
        cout << "Student ID: " << StudentID << " not found" << endl;
    }

}


void Roster::printInvalidEmails()
{
    cout << endl << "Students in Roster with invalid Email addresses: " << endl << endl;

    bool found = false; 

    for (int i = 0; i <= LastStudent; i++) { 
        string Email = this->ClassRosterArray[i]->getEmailAddress();
        if (
            (Email.find('.') == string::npos) || 
            (Email.find('@') == string::npos) || 
            !(Email.find(' ') == string::npos)   
            )
        { 

            found = true;
            this->ClassRosterArray[i]->print();
            std::cout << std::endl;
        }
    }
    
    
    cout << endl;
    
    if (!found){

        cout << "No Invalid Email addresses were found" << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {


    cout << "Showing Students majoring in " << DegreeProgramStrings[degreeProgram]  << endl << endl;

    for (int i = 0; i <= LastStudent; i++) {

        if (this->ClassRosterArray[i]->getDegreeProgram() == degreeProgram) {
            
            this->ClassRosterArray[i]->print();

            cout << endl;
        }
    }
    cout << endl;
}