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
  
    cout << "Attempting to open " << file_name << "." << endl;
    inFS.open(file_name);

    // Test to see if the file could be opened or not.
	if(!inFS.is_open()){
		cout << file_name << " could not be opened." << endl;
    } 
      
    string readLine, ignore;
    getline(inFS, ignore); //ignore the first line of the file being read.
    getline(inFS, ignore); //ignore first line


    while(getline(inFS, readLine)){
        student tempStudent;
        string studentSex, medu, fedu, dalc, walc, g3;
        stringstream streamString (readLine);
    

        // Getting + setting studentSex from file
        getline(streamString, ignore, ','); //ignore school
        getline(streamString, studentSex, ',');
        

        // Depending on which char is read, set enum to F/M
        if(studentSex == "F"){     
            tempStudent.setSex(student::female);
        }
        else if(studentSex == "M"){
            tempStudent.setSex(student::male);      
        }
        /*
        else{
            cout << "Error. " << endl;
        }
        */
        // Columns to be ignored, age to pstatus
        for(int i = 0; i < 4; i++){  
            getline(streamString, ignore,',');
        }

        // Getting + setting mEducation from file
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

        // Getting + setting fEducation from file
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
        /*
        else{
            cout << "Error. " << endl;
        }
        */

        // Columns to be ignored, from Mjob to goout
        for(int i = 0; i < 18; i++){  
            getline(streamString, ignore,',');
        }
        
        // Getting + setting dalc from file
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
        /*
        else{
            cout << "Error. " << endl;
        }
        */

        // Getting + setting walc from file
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
        /*
        else{
            cout << "Error. " << endl;
        }
        */

        // Columns to be ignored, health to G2
        for(int i = 0; i < 4; i++){  
            getline(streamString, ignore,',');
        }
        
        // Set G3 according to the spreadsheet (0-20)
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
        /*
        else{
            cout << "Error." << endl;
        }
        */
        // Push student onto vector after iterating through columns
        totalStudents.push_back(tempStudent);
    }
}

void files::close_files(string file_name){
  cout << file_name << " is now closed." << endl;
	inFS.close();
}

void files::setFile_Name(string filename){
    file_name = filename;
}
string files::getFile_Name() const {
    return file_name;
}

