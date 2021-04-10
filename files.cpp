#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#include "files.h"

ifstream inFS;
void files::open_files(string file_name, vector<student>& totalStudents){
  
    cout << "Attempting to open file." << endl;
    inFS.open(file_name);

	if(!inFS.is_open()){
		cout << "File could not be opened." << endl;
    } 
      
    string readLine, ignore;
    getline(inFS, ignore); //ignore first line
    int total = 0; //FIXME, delete later

    while(getline(inFS, readLine)){
        student tempStudent;
        string studentSex, medu, fedu, dalc, walc, g3;
        stringstream streamString (readLine);
    

        //getting + setting studentSex from file
        getline(streamString, ignore, ','); //ignore school
        getline(streamString, studentSex, ','); 
        
        if(studentSex == "F"){     //depending on which char is read, set enum to F/M
            tempStudent.setSex(student::female);
        }
        else {
            tempStudent.setSex(student::male);
        }

        for(int i = 0; i < 4; i++){  //columns to be ignored, age to pstatus
            getline(streamString, ignore,',');
        }

        //getting + setting mEducation from file
        getline(streamString, medu, ',');
        if(medu.at(0) == '1'){
            tempStudent.setmEducation(1);
        }
        else if(medu.at(0) == '2'){
            tempStudent.setmEducation(2);
        }
        else if(medu.at(0) == '3'){
            tempStudent.setmEducation(3);
        }
        else if(medu.at(0) == '4'){
            tempStudent.setmEducation(4);
        }

        //getting + setting fEducation from file
        getline(streamString, fedu, ',');
        if(fedu.at(0) == '1'){
            tempStudent.setfEducation(1);
        }
        else if(fedu.at(0) == '2'){
            tempStudent.setfEducation(2);
        }
        else if(fedu.at(0) == '3'){
            tempStudent.setfEducation(3);
        }
        else if(fedu.at(0) == '4'){
            tempStudent.setfEducation(4);
        }

        for(int i = 0; i < 18; i++){  //columns to be ignored, from Mjob to goout
            getline(streamString, ignore,',');
        }
        
        //getting + setting dalc from file
        getline(streamString, dalc, ',');
        if (dalc.at(0) == '1'){
            tempStudent.setDalc(1);
        }
        else if(dalc.at(0) == '2'){
            tempStudent.setDalc(2);
        }
        else if(dalc.at(0) == '3'){
            tempStudent.setDalc(3);
        }
        else if(dalc.at(0) == '4'){
            tempStudent.setDalc(4);
        }
        else if(dalc.at(0) == '5'){
            tempStudent.setDalc(5);
        }

        //getting + setting walc from file
        getline(streamString, walc, ',');
        if (walc.at(0) == '1'){
            tempStudent.setWalc(1);
        }
        else if(walc.at(0) == '2'){
            tempStudent.setWalc(2);
        }
        else if(walc.at(0) == '3'){
            tempStudent.setWalc(3);
        }
        else if(walc.at(0) == '4'){
            tempStudent.setWalc(4);
        }
        else if(walc.at(0) == '5'){
            tempStudent.setWalc(5);
        }

        for(int i = 0; i < 4; i++){  //columns to be ignored, health to G2
            getline(streamString, ignore,',');
        }
        
        //set G3 according to the spreadsheet (0-20)
        getline(streamString, g3, ',');
        if(g3.at(0) == '0'){
            tempStudent.setG3(0);
        }
        else if(g3 == "1"){
            tempStudent.setG3(1);
        }
        else if(g3 == "2"){
            tempStudent.setG3(2);
        }
        else if(g3 == "3"){
            tempStudent.setG3(3);
        }
        else if(g3 == "4"){
            tempStudent.setG3(4);
        }
        else if(g3 == "5"){
            tempStudent.setG3(5);
        }
        else if(g3 == "6"){
            tempStudent.setG3(6);
        }
        else if(g3 == "7"){
            tempStudent.setG3(7);
        }
        else if(g3 == "8"){
            tempStudent.setG3(8);
        }
        else if(g3 == "9"){
            tempStudent.setG3(9);
        }
        else if(g3 == "10"){
            tempStudent.setG3(10);
        }
        else if(g3 == "11"){
            tempStudent.setG3(11);
        }
        else if(g3 == "12"){
            tempStudent.setG3(12);
        }
        else if(g3 == "13"){
            tempStudent.setG3(13);
        }
        else if(g3 == "14"){
            tempStudent.setG3(14);
        }
        else if(g3 == "15"){
            tempStudent.setG3(15);
        }
        else if(g3 == "16"){
            tempStudent.setG3(16);
        }
        else if(g3 == "17"){
            tempStudent.setG3(17);
        }
        else if(g3 == "18"){
            tempStudent.setG3(18);
        }
        else if(g3 == "19"){
            tempStudent.setG3(19);
        }
        else if(g3 == "20"){
            tempStudent.setG3(20);
        }
        else{
            cout << "Error." << endl;
        }
        
        //Push student onto vector after iterating through columns
        totalStudents.push_back(tempStudent);

        //FIXME: For testing, get rid of later
        total = total + 1;
    }
    //FIXME: For testing, get rid of later
    cout <<"Lines parsed through this file: " << total << endl;
    
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

