using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <iomanip>

//student class
class Student
{
    private:
        char studentName[50];
        int rollNumber;
        int socialStudiesMarks;
        int statisticMarks;
        int mathsMarks;
        int englishMarks;
        int computerMarks;
        double studentPercentage;
        char studentGrade; 
        bool flag;
        void calculateGrade();
    public:
        void getData();
        void checkForDuplicationInFile();
        void showData();
        void tabularDisplay();
        int getStudentRollNumber();
        void showStudentRecord(int);
};

void Student::getData()
{
     flag = false;
     cout << "\n Enter the roll number of the student";
     cin >> rollNumber;
     //check the duplication
     checkForDuplicationInFile();
     //there is duplication
     if (flag == true)
     {
        cout << "Error duplicate record"<<endl;
        return; // function returns
     }
      cout << "Enter the name of the student : ";
      cin.ignore();
      cin.getline(studentName, 50);
      cout << "Enter the mark in SocialStudies out of 100 : ";
      cin >> socialStudiesMarks;      
      cout << "Enter the mark in Statistics out of 100 : ";
      cin >> statisticMarks;
      cout << "Enter the mark in Math out of 100";
      cin >> mathsMarks;
      cout << "Enter the mark in English out of 100";
      cin >> englishMarks;
      cout << "Enter the mark in Computer out of 100";
      cin >> computerMarks;
      calculateGrade();
      
     
}

void Student::checkForDuplicationInFile()
{
    //open file duplicationCheckingFile.txt
    //compare the roll no that user entered with all rollNumber in file
    //if found, mage flag True
    int currentRollNumber = 0;
    flag = false;
    //file open
    ifstream infile("DuplicateCheckingFile.txt");
    while (!infile.eof())
    {
        infile >> currentRollNumber;
        //true if they are a duplicatio data
        if (currentRollNumber == rollNumber)
        {
            flag = true;
        }
        
    }
    infile.close();
    //no duplication
    if (flag == false)
    {
        ofstream outfile("DuplicateCheckingFile.txt", ios::app);
        outfile <<"\n"<< rollNumber;
        outfile.close();
    }
    
    
}

void Student::calculateGrade()
{
    studentPercentage = (socialStudiesMarks+statisticMarks+mathsMarks+computerMarks+englishMarks)/5.0;
    if (studentPercentage >= 80)
    {
        studentGrade = 'A';
    }
    if (studentPercentage >= 70 && studentPercentage < 80)
    {
        studentGrade = 'B';
    }
    if (studentPercentage >= 60 && studentPercentage < 70)
    {
        studentGrade = 'C';
    }
    if (studentPercentage < 60)
    {
        studentGrade = 'D';
    }
    

}

void Student::showData()
{
    cout << "\n Roll Number of student = " << rollNumber;
    cout  << "\n Name of student = " << studentName; 
    cout  << "\n Mark of Social Studie = " << socialStudiesMarks;
    cout  << "\n Mark of statistic = " << statisticMarks;
    cout  << "\n Mark of Math = " << englishMarks;
    cout  << "\n Mark of English = " << computerMarks;
    cout  << "\n Percentage of student = " << studentPercentage;
    cout  << "\n Grade of student = " << studentGrade;


}

void Student::tabularDisplay()
{
         cout<<rollNumber<<setw(4)<<" "<<studentName<<setw(20-strlen(studentName))<<socialStudiesMarks<<setw(6)<<statisticMarks<<setw(6)<<mathsMarks<<setw(6)<<englishMarks<<setw(8)<<computerMarks<<setw(8)<<studentPercentage<<setw(8)<<studentGrade<<endl;    

}

int Student::getStudentRollNumber()
{
    return rollNumber;
}

void Student::showStudentRecord(int n )
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    //if the file doesn't open
    
}

void intro();
int main()
{
    system("CLS");
    system("color B1");
    char ch;
    Student stdObject;
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    intro();
    do
    {
        system("cls");
        intro();
        cout << "\n\n\n\t\t\t\tHome SCREEN\n\n\n";
        cout << "\n\n\t1. Result Calculation System";
        cout << "\n\n\t2. Student Database Management System";
        cout << "\n\n\t3. Exit";
        cout << "\n\n\n\n\n\tPlease Select Your Option (1-3)";
 
    } while(ch!='3');
    system("pause");// second last statement that stops the output screen till the user presses any key
    return 0;   // main ends here
}

void intro()
{
  cout<<"\n\n\n****  WELCOME TO STUDENT DATABASE MANAGEMENT AND RESULT CALCULATION SYSTEM  ****\n\n";
}