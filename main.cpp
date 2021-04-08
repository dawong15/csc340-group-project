#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream inFSMath; //input file stream for the math class file
	ifstream inFSPor; //input file stream for the portuguese class file


	cout << "Attempting to open file 1 - student-mat.csv" << endl;

	inFSMath.open("student-mat.csv");
	if(!inFSMath.is_open()){
		cout << "student-mat.csv could not be opened." << endl;
	}

	cout << "Attempting to open file 2 - student-por.csv" << endl;
	inFSPor.open("student-por.csv");
	if(!inFSPor.is_open()){
		cout << "student-por.csv could not be opened." << endl;
	}

	//some kind of loop to iterate through one file, and append certain columns to a student(?)
	//object, store each one in a vector

	cout << "Closing files" << endl;
	inFSMath.close();
	inFSPor.close();

	return 0;
}
