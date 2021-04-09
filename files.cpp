#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#include "files.h"

ifstream inFS;
void files::open_files(string file_name){
  
  cout << "Attempting to open file." << endl;
  inFS.open(file_name);
	if(!inFS.is_open()){
		cout << "File could not be opened." << endl;
  }
}

void files::close_files(string file_name){
  cout << "File closed." << endl;
	inFS.close();
}

void files::setFile_Name(string filename){
    file_name = filename;
}
string files::getFile_Name() const {
    return file_name;
}
