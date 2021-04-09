#include <iostream>
#include <fstream>

using namespace std;

#include "files.h"
#include "student.h"

int main() {
    files::open_files("student-mat.csv");
    files::open_files("student-por.csv");

    //read file 1, push students onto a vector

    //read file 2, push students onto the same vector
    
    files::close_files("student-mat.csv");
    files::close_files("student-por.csv");
	return 0;
}
