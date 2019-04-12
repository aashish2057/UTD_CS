
#include "Employee.h" // employee header file

Employee::Employee(){};

Employee::Employee(string ID)
{
    id = ID;
}

Employee::Employee(string ID, string last, string first, string birth, char gen, string start, double sal)
{
    id = ID;
    lastname = last;
    firstname = first;
    birthday = birth;
    gender = gen;
    startdate = start;
    salary = sal;
}
// Set Functions
void Employee::setId(string ID)
{
    id = ID;
}

void Employee::setStartdate(string start)
{
    startdate = start;
}

void Employee::setLastname(string last)
{
    lastname = last;
}

void Employee::setFirstname(string first)
{
    firstname = first;
}

void Employee::setBirthday(string birth)
{
    birthday = birth;
}

void Employee::setSalary(double sal)
{
    salary = sal;
}

void Employee::setGender(char gen)
{
    gender = gen;
}

// Get Functions
string Employee::getId() const
{
    return id;
}

string Employee::getStartdate() const
{
    return startdate;
}

string Employee::getLastname() const
{
    return lastname;
}

string Employee::getFirstname() const
{
    return firstname;
}

string Employee::getBirthday() const
{
    return birthday;
}

double Employee::getSalary() const
{
    return salary;
}

char Employee::getGender() const
{
    return gender;
}