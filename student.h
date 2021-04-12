#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class student{
    public:
        
        enum sex {female, male};

        //student constructor
        student();
        // sex, workday alc. consum, weekend alc. consum, final grade, mother education, father education
        student(enum sex, int dalc, int walc, int g3, int mEducation, int fEducation);
        
        void setSex (sex newStudentSex);
        sex getSex() const;

        void setDalc(int newDalc);
        int getDalc() const;

        void setWalc(int newWalc);
        int getWalc() const;

        void setG3(int newG3);
        int getG3() const;

        void setmEducation(int newfEducation);
        int getmEducation() const;
        
        void setfEducation(int newfEducation);
        int getfEducation() const;

        void Print();

    private:
        sex studentSex;
        int dalc, walc, g3, mEducation, fEducation;

};
#endif