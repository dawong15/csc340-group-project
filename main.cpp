#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "files.h"
#include "student.h"

//void add_input_to_vector();
//int file_size();

int main() {
    //vector for totalStudents across two files
    vector<student> totalStudents(0);

    //variables + vectors related to finding correlation in problem 1
    double alcSum = 0.0;
    double alcSquaredSum =0.0;
    int g3Sum = 0;
    int g3SquaredSum = 0;
    float correlConstantF = 0.0;
    float correlConstantM = 0.0; 

    vector<student> totalFemaleStu(0);
    vector<student> totalMaleStu(0);

    //clear vectors just in case
    totalStudents.clear(); 
    totalFemaleStu.clear();
    totalMaleStu.clear();

    files::open_files("student-mat.csv",totalStudents);
    files::close_files("student-mat.csv");

    files::open_files("student-por.csv",totalStudents);
    files::close_files("student-por.csv");

    /*
    //FIXME: Get rid of later. tests the first 10 lines, and last 10 lines of student-mat.csv. tests to see if any items got added after the student-mat entries. Doesn't account for duplicate students between the two files
    cout << "Female sex is denoted by 0s, and male sex is denoted by 1s.";
    for(int i = 0; i < 10; i++){
        totalStudents.at(i).Print();
    }
    for (int i = 385; i < 395; i++){
        totalStudents.at(i).Print();
    }
    for(int i = 395; i < 405; i++){
        totalStudents.at(i).Print();
    }
    */

    //Depending on the student's sex, push_back into the corresponding student sex vector
    for(int i = 0; i < totalStudents.size(); i++){
        if(totalStudents.at(i).getSex() == 0){
            totalFemaleStu.push_back(totalStudents.at(i));
        }
        else{
            totalMaleStu.push_back(totalStudents.at(i));
        }
    }

    /* FIXME
    //tests to see if only female students are in this female vector (WORKS)
    for(int i = 0; i < totalFemaleStu.size(); i++){
        totalFemaleStu.at(i).Print();
    }
    */
    /*
    //tests to see if only male students are in this male vector (WORKS)
    for(int i = 0; i < totalMaleStu.size(); i++){
        totalMaleStu.at(i).Print();
    }
    */

    for (int i = 0; i < totalFemaleStu.size(); i++){
        alcSum = alcSum + (5/7)*totalFemaleStu.at(i).getDalc() + (2/7)*totalFemaleStu.at(i).getWalc();
    }


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





