// header file
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee // class that stores all employee data
{
    private:
        string id; // employee id 
        string lastname; // employee last name
        string firstname; // employee first name
        string birthday; // employee birthday
        char gender; // employee gender
        string startdate; // employee start date
        double salary; // employee salary
    public:
        Employee();
        Employee(string id);
        Employee(string id, string lastname, string firstname, string birthday, char gender, string startdate, double salary);
        void setId(string); // set employee id
        void setStartdate(string); // set employee start date
        void setLastname(string);  // set employee last name
        void setFirstname(string); // set employee first name
        void setBirthday(string); // set employee birthday
        void setSalary(double); // set employee salary
        void setGender(char); // set employee gender

        string getId() const; // set employee id
        string getStartdate() const; // get employee start date
        string getLastname() const;  // get employee last name
        string getFirstname() const; // get employee first name
        string getBirthday() const; // get employee birthday
        double getSalary() const; // get employee salary
        char getGender() const; // get employee gender    
};

#endif // EMPLOYEECLASS_H