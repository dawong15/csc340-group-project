#include <iostream>
#include <string>

using namespace std;

#include "student.h"

student::student(){
    studentSex = female;
    dalc = -1;
    walc = -1;
    g3 = -1;
}

//sex, workday alc. consum, weekend alc. consum, final grade, mother education, father education
student::student(sex initStudentSex, int initDalc, int initWalc, int initG3, int initfEducation, int initmEducation){
    studentSex = initStudentSex;
    dalc = initDalc;
    walc = initWalc;
    g3 = initG3;
    fEducation = initfEducation;
    mEducation = initmEducation;
}
void student::setSex (sex studentSex){
  studentSex = studentSex;
}

student::sex student::getSex() const{
    return studentSex;
}

void student::setDalc(int newDalc){
    dalc = newDalc;
}
    
int student::getDalc() const{
    return dalc;
}
void student::setWalc(int newWalc){
    walc = newWalc;
}

void student::setG3(int newG3){
    g3 = newG3;
}
int student::getG3() const{
    return g3;
}