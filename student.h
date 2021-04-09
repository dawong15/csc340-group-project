#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class student{
    public:
        
        enum sex {F,M};

        //student constructor
        student();
        student(enum sex, int dalc, int walc, int g3);
        
        void setSex (sex studentSex);
        sex getSex() const;

        void setDalc(int newDalc);
        int getDalc() const;

        void setWalc(int newWalc);
        int getWalc() const;

        void setG3(int newG3);
        int getG3() const;

    private:
        sex studentSex;
        int dalc, walc, g3;

};
#endif