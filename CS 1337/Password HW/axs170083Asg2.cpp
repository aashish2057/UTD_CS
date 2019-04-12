#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*
    Problem - Program asks users for a string, validates it as a password
    based on certain conditions
    Output - notify user if string is valid or invalid password
    Boundary Conditions - String must be between [12,50] in length
    Password conditions - One upper case, one lower case, one digit(0-9),
    one special character (!@#$%^&()[],.:;)
    Author - Aashish Sharma
    netID - axs170083
    Class - CS 1337.009
    Date Started - 1/30/19
*/
string input(string Uinput) // takes input from user
{
    cout << "Enter a string: ";
    cin >> Uinput;
    return Uinput;
}

void output(int error) // informs user if string is valid password and informs any error messages
{
    if(error == 0) // error 0 is valid password
    {
        cout << "String is valid password" << endl;
    }
    if(error == 1) // error 1 is invalid length
    {
        cout << "String has invalid length" << endl;
    }
    if(error == 2) // error 2 is no upper case
    {
        cout << "String has no upper case characters" << endl;
    }
    if(error == 3)// error 3 is no lower case letters
    {
        cout << "String has no lower case characters" << endl;
    }
    if(error == 4) // error 4 is no digit (0-9)
    {
        cout << "String has no digit (0-9)" << endl;
    }
    if(error == 5) // error 5 is no special characters (!@#$%^&()[],.:;)
    {
        cout << "String has no special character (!@#$%^&()[],.:;)" << endl;
    }
    if(error == 6)
    {
        cout << "String contains an illegal character" << endl;
    }
}

bool length(string Uinput) // determines if string has valid length
{
    int error = 0;
    if(Uinput.length() >= 12 && Uinput.length() <= 50) // string must be between 12 and 50 characters inclusive
    {
        return true;
    }
    else
    {
        error = 1; // error 1 is length error
        output(error);
        return false; // false string length
    }
}

bool upper(string Uinput) // determines if string has at least one upper case letter
{
    int error = 2; // error 2 is no upper case letter
    bool valid = false;
    for(int i = 0; i < Uinput.length(); i++) // go through user input
    {
        if(isupper(Uinput[i]))
        {
            error = 10; // no error
            valid = true; // set valid as true
            break;
        }
    }
    output(error); // send error value to output function
    return valid;
}

bool lower(string Uinput) // determines if string has at least one lower case letter
{
    int error = 3; // error 3 is no lower case letter
    bool valid = false;
    for(int i = 0; i < Uinput.length(); i++) // go through user input
    {
        if(islower(Uinput[i]))
        {
            error = 10; // no error
            valid = true; // set valid as true
            break;
        }
    }
    output(error); // send error value to output function
    return valid;
}

bool digit(string Uinput) // determines if string has at least one digit (0-9)
{
    int error = 4; // error 4 is no digit
    bool valid = false;
    for(int i = 0; i < Uinput.length(); i++) // go through user input
    {
        if(isdigit(Uinput[i]))
        {
            error = 10; // no error
            valid = true; // set valid as true
            break;
        }
    }
    output(error); // send error value to output function
    return valid;
}

bool spec(string Uinput) // determines if string has at least one special character (!@#$%^&()[],.:;)
{
    int error = 5; // error 5 is no special character
    bool valid = false;
    char spec[]= {'#', '@', '$', '%', '^', '&', '(', ')', '[', ']', ',', '.', ':', ';',};
    for(int i = 0; i < Uinput.length(); i++) // go through user input
    {
        for(int x = 0; x < 14; x++) // go through array of special characters
        {
            if(Uinput[i] == spec[x]) // if there is a special character in the string
            {
                error = 10; // no error
                valid = true; // valid is true
                break;
            }
        }
    }
    output(error); // send error value to output function
    return valid;
}

void validate(string Uinput) // determines if string passes all password requirements
{
    bool valid = 0;
    int error = 10; // no current errors
    if(length(Uinput) && upper(Uinput) && lower(Uinput) && digit(Uinput) && spec(Uinput)) // if string passes all conditions, string is valid password
    {
        error = 0; // no errors
        output(error); // send error value to output function
    }
}

int main()
{
    string Uinput = "";
    bool valid = true;

    while(valid)
    {
        Uinput = input(Uinput); // get input from user
        if(Uinput == "*") // exit program is user enters *
        {
            valid = false;
        }
        else
        {
            validate(Uinput); // validate string
        }
    }
}
