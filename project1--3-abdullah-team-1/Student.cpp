
// Project 1 is the work of:
// Aarib Abdullah CPSC - 131 - 03 CWID:889889473
// Aatib Abdullah CPSC - 131 - 03 CWID:889500617

#include "Student.h"

#include <iostream>


Student::Student() {
	// TO BE COMPLETED
	/*string xd;
	cout << "Enter CWID: ";
	cin >> xd;/// the reaons why we used cin is because we have no whitespace we entering
	id = xd;*/
}

Student::Student(const string &cwid) {
	// TO BE COMPLETED
	id = cwid;  // copies cwid to id
}

string Student::getCWID() {
	// TO BE COMPLETED
	return id; // returns CWID
}

void Student::addCourseGrade(const string &courseName, char grade12) {
	// TO BE COMPLETED
	for (int i = 0; i< 50; i++) {  /// since there is 50 elements
		if (coursename[i].length() == 0) { // if there is no courese
			coursename[i] = courseName; // course and grade is assigned to empty elemet
			grade[i] = grade12;
			break;
		}
	}

}



double Student::getGPA() {
	// TO BE COMPLETED
	// A = 4, B = 3, C = 2, D = 1, F = 0;
	// a temporary sum variable
	double GPA = 0.0, j = 0.0; // j is used for operation
	int i = 0; // iterator
	/// int sum = 0, gradenum[50];  /// gradenum - number grade: 4, 3, 2, 1
	for (i = 0; i<50; i++) {
		if (coursename[i].empty())
			break; // to prevent factoring in empty elements
		if (grade[i] == 'A') {
			GPA += 4.0;
			j += 1.0; // keeps count of how many classes got a grade
		}
		if (grade[i] == 'B') {
			GPA += 3.0;
			j += 1.0;
		}
		if (grade[i] == 'C') {
			GPA += 2.0;
			j += 1.0;
		}
		if (grade[i] == 'D') {
			GPA += 1.0;
			j += 1.0;
		}
		if (grade[i] == 'F') {
			GPA += 0.0;
			j += 1.0;
		}
	}
	GPA /= j; // makes GPA equal GPA divides by courses taken
	///for (i = 0; i < 50; i++)
	///       sum += gradenum[i];

	///  GPA = (double)sum / 50;
	// assuming gpa is (total number) / #coursestaken 

	///return sum;
	return GPA;
}

// print transcript in this (sample) format:
// TRANSCRIPT FOR CWID=279750343
// CS 121                C
// CS 253                B
// CS 131                B
// GPA = 2.6667
void Student::printTranscript() {
	// TO BE COMPLETED
	cout << "TRANSCRIPT FOR CWID=" << id << endl; // transcript
	for (int i = 0; i < 50; i++) {
		if (coursename[i].empty()) // if it is empty, it won't display
			break;
		else
			cout << coursename[i] << "               " << grade[i] << endl; // ouput
	}
	cout << "GPA = " << getGPA() << endl; // output GPA
}
