#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "files.h"
#include "student.h"

//void add_input_to_vector();
//int file_size();

int main() {
    vector<student> totalStudents(0);
    totalStudents.clear(); //clear vector just in case

    files::open_files("student-mat.csv",totalStudents);

    //FIXME: Get rid of later. tests the first 10 lines, and last 10 lines of student-mat.csv. WORKS
    for(int i = 0; i < 10; i++){
        totalStudents.at(i).Print();
    }
    for (int i = 385; i < 395; i++){
        totalStudents.at(i).Print();
    }
    
    files::open_files("student-por.csv",totalStudents);

    /* FIXME: Get rid of later. tests to see if any items got added after the student-mat entries. CURRENTLY BROKEN.
    for(int i = 395 ; i < 405; i++){
        totalStudents.at(i).Print();
    }
    */
    files::close_files("student-mat.csv");
    files::close_files("student-por.csv");

	return 0;
}
/* commented temporarily to test run
void add_input_to_vector(){
  
  string line;

  while (getline (inFS, line)){
    for (int i = 1; i < file_size(inFS); i++){

    }
  }

}

std::ifstream::pos_type file_size(const char* filename) {

  std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
  return in.tellg();
*/
  /*
  streampos begin, end;
  begin = inFS.tellg();
  inFS.seekg(0, ios::end);
  end = inFS.tellg();
  return (end-begin);
  }
  */





