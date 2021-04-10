#ifndef FILES_H
#define TEAM_PERSON_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include "student.h"

class files{
    public:
        static void open_files(string file_name, vector<student>& totalStudents);
        static void close_files(string file_name);
        void setFile_Name(string file_name);
        string getFile_Name() const;

    private:
        string file_name;
        
};
#endif