#include "roster.h"
#include <iostream>
#include <iomanip>





int main() {

	cout << "WGU C867 Scripting and Programming - Applications" <<endl;
	cout <<"Language used C++" <<endl;
	cout <<"Student ID #000961901" <<endl;
	cout <<"John Grahn" <<endl;
	cout << endl;


	const int StudentNum = 5;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,John,Grahn,johngrahn@wgu.edu,23,30,30,30,SOFTWARE"
	};

	Roster* classRoster = new Roster(StudentNum);

	for (int i = 0; i < StudentNum; i++) {
		classRoster->parse(studentData[i]);

	}

	cout << "Students have been added" << endl;



		/*Pseudo Code*/
	classRoster->printAll();
	classRoster->printInvalidEmails();



	for (int i = 0; i < classRoster->StudentCount; i++) {

		classRoster->printAverageDaysInCourse(classRoster->ClassRosterArray[i]->getStudentID());

	}

	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");

	return 0;
}


