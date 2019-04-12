#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Employee.h"

using namespace std;

/*
    Problem - Create a program that keeps track of employee information
    Employee Data - Id, last name, first name, birth date, gender, start date, salary
    Conditions - Data must be stored in a class with get/set methods. Company won't have more than
    100 employees
    Constructors - construct an object, takes only employee ID, takes all information
    File requirements - check if file Employee.txt exists (create file if it doesn't)
    Menu - enter new employee information, display all employee information in alphabetical order by last name,
    look up an employee by ID, remove an employee and save all data to Employee.txt and exit
    Author - Aashish Sharma
    Date - 3/25/2019
    netID - axs170083
    class - CS1337.009
*/
bool filecheck(string filename) // check if file exists
{
    ifstream inputFile;
    inputFile.open(filename); // open file
    if(inputFile) // there is a file
    {
        inputFile.close();
        return true; // file exists
    }
    else // there isn't a file
    {
        inputFile.close();
        return false; // file doesnt exist
    }
}

void readFile(string filename, Employee* p, int &counter)
{
    ifstream inputFile;
    inputFile.open(filename);

    string id; // employee id
    string startdate; // employee start date 
    string lastname; // employee last name
    string firstname; // employee first name
    string birthday; // employee birthday
    double salary; // employee salary
    char gender; // employee gender

    int i = 0;
    Employee *tempEmployee = new Employee;
    while(inputFile >> id >> lastname >> firstname >> birthday >> gender >> startdate >> salary) // go through file and set values to temp object
    {
        tempEmployee->setId(id);
        tempEmployee->setLastname(lastname);
        tempEmployee->setFirstname(firstname);
        tempEmployee->setBirthday(birthday);
        tempEmployee->setGender(gender);
        tempEmployee->setStartdate(startdate);
        tempEmployee->setSalary(salary);
        p[i] = *tempEmployee; // set temp object into the array
        counter++;
        i++;
    }
    //cout << p[i].getId();
    delete tempEmployee; // delete the temp object
    inputFile.close();
}

void output(Employee* p, int counter)
{
    cout << left << "ID" << setw(5) << right << "Last Name" << setw(10) << "First Name" << setw(10) << "Birthday" << setw(10) << "Gender " << "Start Date" << setw(10) << "Salary" << setw(10) << endl; // print a heading for output
    for(int i = 0; i < counter; i++) // print all user information
    {
        cout << left << p[i].getId() << setw(10) << " " << p[i].getLastname() << setw(10) << " " << p[i].getFirstname() << setw(10) << " " << p[i].getBirthday() << setw(10) << " " << p[i].getGender() << setw(10) << " " << p[i].getStartdate() << setw(10)  << " " << p[i].getSalary() << setw(10) << endl;
    }
}

int menu(string filename, Employee* p, int counter) // displays menu to user
{
    int choice = 0;
    cout << "1. Enter new employee information" << endl;
    cout << "2. Display all employee information in alphabetical order by last name" << endl;
    cout << "3. Look up an employee by ID" << endl;
    cout << "4. Remove an employee" << endl;
    cout << "5, Save all data to Employee.txt and exit" << endl;
    cin >> choice;
    return choice;
}

void newemployee(Employee* p, int &counter) // enters new employee information
{
    string id;
    bool unique = true; // variable stores if user entered id already exists
    do
    {
        cout << "Enter new employee ID: ";
        cin >> id;
        for(int i = 0; i < counter; i++) // loop through array to determine if ID is unique
        {
            if(p[i].getId() == id)
            {
                cout << "ID is already taken, try again" << endl; // inform user of similar id
                unique = false;
            }
        }
    } while (!unique);
    // Request rest of information from user
    string lastname; // employee last name
    string firstname; // employee first name
    string birthday; // employee birthday
    char gender; // employee gender
    string startdate; // employee start date 
    double salary; // employee salary
    double input = false;
    do
    {
        cout << " lastname, firstname, birthday(MM/DD/YYYY), gender(M or F), Enter startdate(MM/DD/YYYY), and salary(no commas, enter floa!) - eve&&thing seperated by one space" << endl;
        cin >> lastname >> firstname >> birthday >> gender >> startdate >> salary; // get everything from user
        if(salary > 0.0) // input is valid
        {
            input = true;
        }
        else
        {
            cout << "invalid input, please re-enter" << endl;
        }
    } while (!input); // keeps asking for rest of information until it is valid
    // create new employee object
    Employee *tempEmployee = new Employee; // temp object to set everything
        tempEmployee->setId(id);
        tempEmployee->setLastname(lastname);
        tempEmployee->setFirstname(firstname);
        tempEmployee->setBirthday(birthday);
        tempEmployee->setGender(gender);
        tempEmployee->setStartdate(startdate);
        tempEmployee->setSalary(salary);
        p[counter] = *tempEmployee; // put the temp object into the array
    counter++;
    delete tempEmployee; // delete the temp object
}

void alphabetical(Employee* p , int counter) // print all information in alphabeticall order by last name
{
    bool bubble; // performs bubble sort
    Employee temp; // temp object for employee
    do
    {
        bubble = false;
        for(int i = 0; i < counter-1; i++)
        {
            if(p[i].getLastname() > p[i+1].getLastname()) // B > A in ASCII, thus B must move down
            {
                temp = p[i];
                p[i] = p[i+1];
                p[i+1] = temp;
                bubble = true;
            }
        }
    } while (bubble);
}

void lookup(Employee* p, int counter) // locates employee by ID and displays information
{
    string id;
    cout << "Enter employee ID: ";
    cin >> id;
    bool found = false;
    int i = 0;
    do
    {
        if(p[i].getId() == id) // id found
        {
            found = true; // id was found
            // print information
            cout << p[i].getId() << " " << p[i].getLastname() << " " << p[i].getFirstname() << " " << p[i].getBirthday() << " " << p[i].getGender() << " " << p[i].getStartdate() << " " << p[i].getSalary() << endl;
        }
        i++;
    } while (i<counter);
    if(found == false) // inform user of invalid id
    {
        cout << "Employee not found, please enter ID again" << endl;
    }
}

void del(Employee* p, int &counter) // deletes user from employee class
{
    string id;
    cout << "Enter ID, for employee that you want to remove: ";
    cin >> id;
    bool found = false;
    int i = 0;
    do
    {
        if(p[i].getId() == id) // id was found
        {
            found = true; // id was found
            // remove element
            for(; i < counter; i++)
            {
                p[i] = p[i+1];
            }
            counter--;
        }
        i++;
    } while (i < counter);
    if(found == false) // id wasn't found ask user to enter id again
    {
        cout << "Employee not found, please enter ID again" << endl;
    }
}

void save(string filename, Employee* p, int counter, bool fileexists) // saves all information into the file
{
    if(fileexists) // performs if file exists
    {
        ofstream outputFile;
        outputFile.open(filename); // creates output file
        int i = 0;
        while(i < counter) // prints all information
        {
            outputFile << p[i].getId() << " " << p[i].getLastname() << " " << p[i].getFirstname() << " " << p[i].getBirthday() << " " << p[i].getGender() << " " << p[i].getStartdate() << " " << p[i].getSalary() << endl;
            i++;
        }
        outputFile.close(); // closes file
    }
    else // file doesn't exist
    {
        ofstream outputFile(filename); // output file is create
        outputFile.open(filename);
        int i = 0;
        while(i < counter) // prints all information
        {
            outputFile << p[i].getId() << " " << p[i].getLastname() << " " << p[i].getFirstname() << " " << p[i].getBirthday() << " " << p[i].getGender() << " " << p[i].getStartdate() << " " << p[i].getSalary() << endl;
        }
        outputFile.close(); // close output file
    }
}

int main()
{
    string filename = "Employee.txt"; // name of file
    bool fileexist = false;
    const int numemployee = 100; // max number of employees is 100
    Employee employeearray[numemployee]; // create array of class
    Employee* p = new Employee[numemployee]; // pointer to array of class
    int counter = 0; // counter to determine the number of employees in file

    // check for file
    fileexist = filecheck(filename); // checks if file exists and return boolean
    if(fileexist) // File exists
    {
        readFile(filename, p, counter); // read data from the file
        //output(p, counter); //just used this to test if reading from file was working
    }
    // menu loop
    bool run = true;
    int choice = 0; // gets choice from user
    bool valid = false; // determines if choice is valid
    do
    {
        do
        {
            choice = menu(filename, p, counter); // gets choice from user
            if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
            {
                valid = true;
            }
            else
            {
                cout << "Entered invalid choice, please re-enter" << endl; // prompts user of error
            }   
        } while (!valid); // keeps asking user for menu choice until valid
        // Perform action based on user choice
        if(choice == 1) // User wants to enter new employee information
        {
            newemployee(p, counter);
        }
        if(choice == 2) // user wants to print all information in alphabeticall order by last name
        {
            alphabetical(p, counter); // alphabetical order by last name using bubble sort
            output(p, counter); // print sorted
        }
        if(choice == 3) // user wants to look up employee by ID
        {
            lookup(p, counter);
        }
        if(choice == 4) // users wants to remove employee
        {
            del(p, counter);
        }
        if(choice == 5) // user wants to save all data to employee.txt and exit
        {
            save(filename, p, counter, fileexist);
            run = false;
        }
    } while (run);
}