using namespace std;
#include<iostream>
#include<fstream>
#include<iomanip>
#include <stdio.h>
#include <string.h>

//student class
class Student
{
    private:
        char studentName[50];
        int rullNumber;
        int socialStudiesMarks;
        int statisticMarks;
        int mathsMarks;
        int englishMarks;
        int computerMarks;
        double studentPercentage;
        char studentGrade; 
        bool flag;
    public:
        void getData();
};

void Student::getData()
{
    //take the input from user
     
}

void intro();
int main()
{
    system("CLS");
    system("color B1");
    char ch;
    Student stdObject;
    cout.setf(ios::fixed|ios::showpoint);
    cout<<setprecision(2);
    intro();
    do
    {
        cout<<"\n\n\n\t\t\t\tHome SCREEN\n\n\n";
        cout<<"\n\n\t1. Result Calculation System";
        cout<<"\n\n\t2. Student Database Management System";
        cout<<"\n\n\t3. Exit";
        cout<<"\n\n\n\n\n\tPlease Select Your Option (1-3)";
 
    } while(ch!='3');
    system("pause");// second last statement that stops the output screen till the user presses any key
    return 0;   // main ends here
}

void intro()
{
  cout<<"\n\n\n****  WELCOME TO STUDENT DATABASE MANAGEMENT AND RESULT CALCULATION SYSTEM  ****\n\n";
}