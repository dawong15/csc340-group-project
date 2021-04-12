#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

#include "files.h"
#include "student.h"

//void add_input_to_vector();
//int file_size();

int main() {
    // Vector for totalStudents across two files
    vector<student> totalStudents(0);

    // variables + vectors related to finding correlation in problem 1
    double alcSum = 0.0;
    double alcSquaredSum = 0.0;
    int g3Sum = 0;
    int g3SquaredSum = 0;
    double AlcTimesG3 = 0.0;
    double correlCoeffF = 0.0;
    double correlCoeffM = 0.0; 
    double correlTop = 0.0;
    double correlBottom = 0.0;

    vector<student> totalFemaleStu(0);
    vector<student> totalMaleStu(0);

    int nF = totalFemaleStu.size();
    int nM = totalMaleStu.size();


    // Variables related to finding correlation in problem 2
    int sumMandFedu = 0;
    int sumMandFeduSqr = 0;
    double EduTimesAlc = 0.0;
    double correlCoeffParents = 0.0;

    int numStudents = totalStudents.size();

    // Clear vectors just in case (similarly to lab 3, assume nothing c: )
    totalStudents.clear(); 
    totalFemaleStu.clear();
    totalMaleStu.clear();

    files::open_files("student-mat.csv",totalStudents);
    files::close_files("student-mat.csv");

    files::open_files("student-por.csv",totalStudents);
    files::close_files("student-por.csv");

    cout << endl;


    /*
        PROBLEM 1: Measuring the correlation between drinking habits and student success. In particular, whether or not alcohol affects males and females (from the both the Math and Portuguese class) differently in regards to school success (measured by final grades). 

    */
    cout << "PROBLEM 1: Measuring the correlation between drinking habits and student success. In particular, whether or not alcohol affects males and females (from the both the Math and Portuguese class) differently in regards to school success (measured by final grades). " << endl;
    
    // Depending on the student's sex, push_back into the corresponding student sex vector
    for(int i = 0; i < totalStudents.size(); i++){
        if(totalStudents.at(i).getSex() == 0){
            totalFemaleStu.push_back(totalStudents.at(i));
        }
        else{
            totalMaleStu.push_back(totalStudents.at(i));
        }
    }

    // Assign values associated with calculatiing the correlation coefficient for female students
    for (int i = 0; i < totalFemaleStu.size(); i++){
        alcSum = alcSum + ((5.0/7.0)*(double)totalFemaleStu.at(i).getDalc() + (2.0/7.0)*(double)totalFemaleStu.at(i).getWalc());
        alcSquaredSum = alcSquaredSum + pow((5.0/7.0)*(double)totalFemaleStu.at(i).getDalc() + (2.0/7.0)*(double)totalFemaleStu.at(i).getWalc(), 2.0);

        g3Sum = g3Sum + totalFemaleStu.at(i).getG3();
        g3SquaredSum = g3SquaredSum + pow(totalFemaleStu.at(i).getG3(), 2.0);
        
        AlcTimesG3 += ((5/7)*(double)totalFemaleStu.at(i).getDalc() + (2.0/7.0)*(double)totalFemaleStu.at(i).getWalc()) * (double)totalFemaleStu.at(i).getG3();

    }
    
    // Calculating the correlation coefficient for female students to their final grades
    correlTop = (nF * AlcTimesG3 - alcSum * (double)g3Sum);
    correlBottom =  sqrt( (nF * alcSquaredSum - pow(alcSum, 2.0)) * (nF * (double)g3SquaredSum - pow((double)g3Sum, 2.0)));
    correlCoeffF = correlTop / correlBottom;

    // Reset the values before calculating the correlation coefficient constant for mens
    alcSum = 0.0;
    alcSquaredSum = 0.0;
    g3Sum = 0;
    g3SquaredSum = 0;
    AlcTimesG3 = 0.0;
    correlTop = 0.0;
    correlBottom = 0.0;

    // Assign values associated with calculatiing the correlation coefficient for male students
    for (int i = 0; i < totalMaleStu.size(); i++){
        alcSum = alcSum + ((5.0/7.0)*totalMaleStu.at(i).getDalc() + (2.0/7.0)*totalMaleStu.at(i).getWalc());
        alcSquaredSum = alcSquaredSum + pow((5.0/7.0)*totalMaleStu.at(i).getDalc() + (2.0/7.0)*totalMaleStu.at(i).getWalc(), 2.0);

        g3Sum = g3Sum + totalMaleStu.at(i).getG3();
        g3SquaredSum = g3SquaredSum + pow(totalMaleStu.at(i).getG3(), 2.0);
        
        AlcTimesG3 += ((5/7)*totalMaleStu.at(i).getDalc() + (2.0/7.0)*totalMaleStu.at(i).getWalc()) * (double)totalMaleStu.at(i).getG3();

    }

    // Calculating the correlation coefficient for male students to their final grades
    correlTop = (nF * AlcTimesG3 - alcSum * (double)g3Sum);
    correlBottom =  sqrt( (nF * alcSquaredSum - pow(alcSum, 2.0)) * (nF * (double)g3SquaredSum - pow((double)g3Sum, 2.0)));
    correlCoeffM = correlTop / correlBottom;

    cout << "\n" << "Correlation coefficient for Female Students: " << correlCoeffF << endl << "Correlation coefficient for Male Students: " << correlCoeffM << "\n" << endl;

    // Interpret the correlation coefficients of the two student groups (female and male)

    if(correlCoeffF > correlCoeffM && fabs(correlCoeffF-correlCoeffM) > 0.01){
        cout << "Alcohol seems to affect male students and poorer performance in school more than female students." << endl;
    }
    else if(correlCoeffF < correlCoeffM && fabs(correlCoeffF-correlCoeffM) > 0.01){
        cout << "Alcohol seems to affect female students and poorer performance (final grade wise) in school more than male students." << endl;
    }
    else{
        cout << "Alcohol seems to affect female and male students similarly in terms of poorer performance in school. The increased presence of alcohol is correlated to poorer performance (final grade wise) in school. " << endl;
    }
    
    /*
        PROBLEM 2: Measuring the correlation in regards to educational background of the student's parents to a student's drinking habit.
    */

    cout << "\nPROBLEM 2: Measuring the correlation in regards to educational background of the student's parents to a student's drinking habit." << endl;

    // Reset the values before calculating the correlation coefficient constant related values for Problem 2 
    alcSum = 0.0;
    alcSquaredSum = 0.0;
    correlTop = 0.0;
    correlBottom = 0.0;

    // Assign values associated with calculatiing the correlation coefficient for alcohol consumption based on parent's education background
    for (int i = 0; i < totalStudents.size(); i++){
        sumMandFedu += totalStudents.at(i).getfEducation() + totalStudents.at(i).getmEducation();
        sumMandFeduSqr += pow((totalStudents.at(i).getfEducation() + totalStudents.at(i).getmEducation()), 2.0);

        alcSum = alcSum + ((5.0/7.0)*totalStudents.at(i).getDalc() + (2.0/7.0)*totalStudents.at(i).getWalc());
        alcSquaredSum = alcSquaredSum + pow((5.0/7.0)*totalStudents.at(i).getDalc() + (2.0/7.0)*totalStudents.at(i).getWalc(), 2.0);

        EduTimesAlc += ((5.0/7.0)*totalStudents.at(i).getDalc() + (2.0/7.0)*totalStudents.at(i).getWalc()) * (double)(totalStudents.at(i).getfEducation() + totalStudents.at(i).getmEducation());

    }


    // Calculating the correlation coefficient between educational background of parents to a student's alcohol habits
    correlTop = ((double)numStudents * EduTimesAlc - alcSum * (double)sumMandFedu);
    correlBottom =  sqrt( ((double)numStudents * alcSquaredSum - pow(alcSum, 2.0)) * ((double)numStudents * (double)sumMandFeduSqr - pow((double)sumMandFedu, 2.0)));
    correlCoeffParents = correlTop / correlBottom;

    cout << "\n" << "Correlation coefficient for Parents: " << correlCoeffParents << "\n" << endl;
    
    // Interpret the correlation coefficients between parental education background and student alcohol consumption
    if(correlCoeffParents > 0){
        cout << "Parental educational background is positively correlated with increased alcohol consumption. That is, a higher basis for parental educational background is correlated with increased alcohol consumption." << endl;
    }
    else if(correlCoeffParents < 0){
        cout << "Parental educational background is negatively correlated with increased alcohol consumption. That is, a higher basis for parental educational background is correlated with decreased alcohol consumption." << endl;
    }
    else{
        cout << "Parental educational background has little to no correlation with increased alcohol consumption. " << endl;
    }

    /*
        TESTING CODE:
        - used in various parts of the program to test inputs and outputs, now moved here for potential reuse.
    _____________________________________________________________________________________

    
    //Tests the first 10 lines, and last 10 lines of student-mat.csv. tests to see if any items got added after the student-mat entries. Doesn't account for duplicate students between the two files
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

    //Tests to see if male and female students were properly inputted into their respective vectors.
    for(int i = 0; i < totalFemaleStu.size(); i++){
        cout << totalFemaleStu.at(i).Print() << endl;
    }

    for(int i = 0; i < totalMaleStu.size(); i++){
        cout << totalMaleStu.at(i).Print() << endl;
    }

    // Testing values related to correlation coefficient values for parental educational background and student alcohol consumption
    cout << sumMandFedu << endl;
    cout << sumMandFeduSqr << endl;
    cout << alcSum << endl;
    cout << alcSquaredSum << endl;
    cout << EduTimesAlc << endl;
    */

    return 0;
}
