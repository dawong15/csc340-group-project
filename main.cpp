#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "files.h"
#include "student.h"

void add_input_to_vector();

int main() {
    
    files::open_files("student-mat.csv");
    files::open_files("student-por.csv");

    vector<student> totalStudents(0);
    totalStudents.clear(); //Clear vector
    
    //read file 1, push students onto a vector
    
    //read file 2, push students onto the same vector

    files::close_files("student-mat.csv");
    files::close_files("student-por.csv");

	return 0;
}


