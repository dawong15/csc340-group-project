#ifndef FILES_H
#define TEAM_PERSON_H
#include <string>
using namespace std;

class files{
    public:
        static void open_files(string file_name);
        static void close_files(string file_name);
        void setFile_Name(string file_name);
        string getFile_Name() const;

    private:
        string file_name;
};
#endif