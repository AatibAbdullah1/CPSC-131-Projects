
// Project 1 is the work of:
// Aarib Abdullah CPSC - 131 - 03 CWID:889889473
// Aatib Abdullah CPSC - 131 - 03 CWID:889500617

#pragma once
#include <string>
#include <stdexcept>
#include "Student.h"

using namespace std;

class Registrar {
public:

	void readTextfile(string filename); // Load information from a text file with the given filename: THIS IS COMPLETE
	void addLine(string courseName, string cwid, char grade); // process a line from the text file
	Student& getStudent(string cwid) const; // return the Student object corresponding to a given CWID
											// getStudent must throw an exception if cwid is invalid
											// add constructors, destructors, assignment operators if needed
	Registrar(); // constuctor prototype
	~Registrar(); // destructor prototype

	Registrar(const Registrar& peer); // copy constructor
	Registrar& operator=(const Registrar& peer); // assignment operator

private:
	Student * allstudents; // allstudents dynamic array
	int size = 50000; // array element size
	int body_count; // keeps count of how many students in registrar object "allstudents"
						// Add private member variables for your class along with any 
						// other variables required to implement the public member functions
						// TO BE COMPLETED

};
