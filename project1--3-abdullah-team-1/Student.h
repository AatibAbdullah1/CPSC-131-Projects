
// Project 1 is the work of:
// Aarib Abdullah CPSC - 131 - 03 CWID:889889473
// Aatib Abdullah CPSC - 131 - 03 CWID:889500617

#pragma once
#include <string>

using namespace std;

class Student {
public:
	Student(); // default constructor
	Student(const string &cwid); // constructor with parameter
	void addCourseGrade(const string &courseName, char grade); // add course name and grade to student's record
	double getGPA(); // calculate and return GPA
	void printTranscript(); // print transcript - see Student.cpp for the format
	string getCWID(); // return the CWID of this student
private:
	string id; // cwid
	string coursename[50]; // courses
	char grade[50]; // grades
	int courses_taken; // course taken
	friend class Registrar;// friend class         // any private member variables and methods go here
												   // TO BE COMPLETED

};
