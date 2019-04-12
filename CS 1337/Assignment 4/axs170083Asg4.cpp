#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*
    Problem - Program that grades 3 exams for a class
    Input - File input, that contains Student ID - int
    Student name(John_Cole) - string, Grades on 3 tests - int
    conditions - dynamically allocate struct with student info,
    no class with more than 100 students.
    Process - Read all data, WHILE, compute average and store in struct
    Menu options -
        1. Print the list of information in order by name
        2. Print the list of information in order by average grade, highest first
        3. Look up studentID, if found show info for that student, if not show message
    Author - Aashish Sharma
    netID - axs170083
    Class - CS 1337.009
    Date Finished - 3/12/19
*/
string input(string &filename) // get user input
{
    cout << "Enter * to end program" << endl;
    cout << "Enter the file name: ";
    cin >> filename;
    return filename;
}

struct Student // Student Struct that contains all struct information
{
    int studentID;
    string studentName;
    double gradeaverage;
};

double average(int test1, int test2, int test3) // computes average of 3 test scores
{
    return (test1 + test2 + test3)/3.0;
}

bool readFile(string filename, Student* p, int &counter) // get StudentID, student name and grades
{
    ifstream inputFile;
    inputFile.open(filename); // open file
    int studentID;
    string studentName;
    int test1, test2, test3;
    double gradeaverage;
    bool file = true;
    if(inputFile) // if file is valid
    {
        // pointer array
        
        int i = 0;
        while(inputFile >> studentID >> studentName >> test1 >> test2 >> test3)
        {
            // computer test average
            gradeaverage = average(test1, test2, test3);
            // populate struct array
            p[i].studentID = studentID; // add student ID
            p[i].studentName = studentName; // add student name
            p[i].gradeaverage = gradeaverage; // add grade average
            i++;
            counter++; // increment counter to know number of filled structs
        }
    }
    else // file isn't valid
    {
        cout << "File is not valid" << endl;
        file = false;
    }
    inputFile.close(); // close input file
    return file;
}

int Menu(int choice) // print menu for user to choose from
{
    cout << "Enter 1 for Student information in order by name" << endl;
    cout << "Enter 2 for Student information in order by average grade, descending order" << endl;
    cout << "Enter 3 to look up by student ID" << endl;
    cout << "Enter 0 to end program" << endl;
    cin >> choice;
    return choice;
}

void sort(Student* p, int choice, int counter) // sort array based on user choice
{
    if(choice == 1) // sort by alphabetically by name
    {
        bool bubble;
        Student temp; // temporary struct
        do
        {
            bubble = false;
            for(int i = 0; i < counter-1; i++)
            {
                if(p[i].studentName > p[i+1].studentName)
                {
                    temp = p[i]; // set higher to temp
                    p[i] = p[i+1]; // move lower name up
                    p[i+1] = temp; // move higher down
                    bubble = true;
                }
            }
        } while (bubble);
    }
    if(choice == 2) // sort by average grades in descending order
    {
        bool bubble;
        Student temp; // temporary struct
        do
        {
            bubble = false;
            for(int i = 0; i < counter-1; i++)
            {
                if(p[i].gradeaverage < p[i+1].gradeaverage) // left value is less than right value
                {
                    temp = p[i]; // set lower to temp
                    p[i] = p[i+1]; // move higher to the right
                    p[i+1] = temp; // move lower to the left
                    bubble = true;
                }
            }
        } while (bubble);
    }
}


void output(Student* p, int counter) // print information in order by name
{
    cout << left << setw(5) << "ID " << setw(16) << " Student Name " << setw(7) << " Grade Average" << endl;
    for(int i = 0; i < counter; i++)
    {
        // prints averages with 2 decimal places, everything right justified, and names and grades in columns
        cout << p[i].studentID << " " << right << setw(15) << p[i].studentName << " " << fixed << setprecision(2) << setw(7) << p[i].gradeaverage << endl;
    }
}

void locate(Student* p, int counter) // locate student by ID and print information, menu choice 3
{
    int searchID;
    cout << "Enter student ID: ";
    cin >> searchID;
    bool found = false;
    for(int i = 0; i < counter; i++)
    {
        if(p[i].studentID == searchID) // if user entered id matches student id print information
        {
            found = true; // id found
            cout << "ID " << left << setw(15) << " Student Name " << setw(7) << " Grade Average" << endl;
            // prints search student's averages with 2 decimal places, everything right justified, and name and grade in columns
            cout << p[i].studentID << " " << right << setw(15) << p[i].studentName << " " << fixed << setprecision(2) << setw(7) << p[i].gradeaverage << endl;
        }
    }
    if(found == false) // if id is not found, show error message
    {
        cout << "Student not found" << endl;
    }
}

int main()
{
    bool valid = true;
    string filename = "";
    const int numStudent = 100;
    Student studentarray[numStudent]; // array of structs
    Student* p = new Student[numStudent];
    int counter = 0;
    int choice;
    bool file;
    while(!file) // keep asking user for file name until it is valid
    {
        input(filename); // get file name from user
        if(filename == "*") // user enters asterisk to exit program
        {
            file = false;
            break;
        }
        file = readFile(filename, p, counter); // read information from file and determine if file is valid
    }
    if(file) // if file opens successfully
    {
        while(valid)
        {
            choice = Menu(choice); // output array
            if(choice == 0) // user enters 0 in menu end program
            {
                valid = false;
            }
            else// continue with program
            {  
                if(choice == 3) // user wants to look for student by ID
                {
                    locate(p, counter); // locate and print student information
                }
                else
                {
                    sort(p, choice, counter); // send to grade sort 
                    output(p, counter); // output sorted struct
                }
                
            }
        }
    }   
}