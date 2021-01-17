
// Project 1 is the work of:
// Aarib Abdullah CPSC - 131 - 03 CWID:889889473
// Aatib Abdullah CPSC - 131 - 03 CWID:889500617

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Registrar.h"

using namespace std;

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void Registrar::readTextfile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string courseName;
		string cwid;
		char grade;
		while (myfile >> courseName >> cwid >> grade) {
			// cout << cwid << " " << grade << endl;
			addLine(courseName, cwid, grade);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}


// return Student object corresponding to a given CWID
// getStudent must throw an exception if cwid is invalid

Student& Registrar::getStudent(string cwid) const { // getStudent fucntion to return student
	// TO BE COMPLETED
	for (int b = 0; b < size; b++) {// this is while loop
		if (allstudents[b].id == cwid) {// this is if statement
			return allstudents[b];
		}
	} // end of for loop.... wait....... WHAT ..... this is the end of while loop
	throw exception("ERROR: CWID NOT REGISTERED!");
}

  // process a line from the text file
void Registrar::addLine(string courseName, string cwid, char graDE) {
	// TO BE COMPLETED
	string end = "cat";  // if assigned "kill" it will stop for-loop
	for (int i = 0; i < size; i++) {
		if (allstudents[i].id.empty() || allstudents[i].id == cwid) {/// if the element allstudent don't have id
			if (allstudents[i].id.empty()) { // checkes if the string is empty, if it is, then it is initialized
				allstudents[i].id = cwid;
				body_count++; /// change voo2
			}
			for (int j = 0; j < 50; j++) { // for loop for course and grade
				if (allstudents[i].coursename[j].empty()) { // check if it is empty
					allstudents[i].coursename[j] = courseName;
					allstudents[i].grade[j] = graDE;
					end = "kill"; 
					break;
				}
			}
			if (end == "kill")  // condition to kill for-loop
				break;  // to stop going through array
		}
	}
}

//DESTRUCTOR
Registrar::~Registrar() { // destructor used to deallocate memory
	delete[] allstudents;
	allstudents = NULL; //good programming practice
}

//CONSTRUCTOR
Registrar::Registrar() { // defalut constructor for allocating memory
	allstudents = new Student[size];
	body_count = 0;
}




//copy constructor
Registrar::Registrar(const Registrar& peer) { //copy constructor, copying from an old object(peer) and pasting it to new object
	size = peer.size;
	allstudents = new Student[size]; // allocating dynamica array again because we are dealing dynamic arrays
	for (int i = 0; i<peer.body_count; i++) { // for loop with the actual amount of students that was entered
		if (peer.allstudents[i].id.length() != 0)  // to check if id had nothing, used to copy from copied object
			allstudents[i].id = peer.allstudents[i].id;
		else
			break; // else it breaks
		for (int j = 0; j<50; j++) { // for loop for course and grade
			if (peer.allstudents[i].coursename[j].empty()) // if peer ran out of courses
				break;
			allstudents[i].grade[j] = peer.allstudents[i].grade[j]; // copying from object
			allstudents[i].coursename[j] = peer.allstudents[i].coursename[j]; 
		}
	}
}
// when and object use an equal operator, this gets called
Registrar& Registrar::operator=(const Registrar& peer) {// assignment operator
	if (this != &peer) { // preventing self assignment
		delete[] allstudents;
		
		allstudents = new Student[size]; // deallocating and allocating array
		for (int i = 0; i < peer.body_count; i++) { // repeating the same process as the copy constructor
			if (peer.allstudents[i].id.empty()) // just in case
				break;
			allstudents[i].id = peer.allstudents[i].id;
			for (int j = 0; j<50; j++) {
				if (peer.allstudents[i].coursename[j].empty())
					break;
				allstudents[i].grade[j] = peer.allstudents[i].grade[j];
				allstudents[i].coursename[j] = peer.allstudents[i].coursename[j];
			}
		}
	}
	return *this; // returning the this poiner that points to the object's memory, enables chained assignment
}
