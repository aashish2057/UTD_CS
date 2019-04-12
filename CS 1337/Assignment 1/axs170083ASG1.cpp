#include <iostream>

using namespace std;

/*
    Problem - Design a program that takes in a number(n) greater than 1, and
    determines the sum of the series of the number(n) 
    (1/N + 2/N-1 + 3/N-2+ … +N/1).
    Output - Original Number and Sum of Series
    Boundary Conditions - if number(n) is 0 progarm stops, if number(n) is 
    equal to one or less than zero, give error message and request new number
    Other Requirements - Return to request another number
    Author - Aashish Sharma
    netID - axs170083
    Class - CS 1337.009
    Date - 1/23/19
*/
int input(int Uinput) // get input from user and store in input variable
{
    cout << "Enter input: ";
    cin >> Uinput;
    if(cin.fail()) // if input is non numeric (user enters a, or - etc) notify of error and request again
    {
        cout << "Entered non-numeric invalid input, run program again"; // user entered invalid input request new input
    }
    return Uinput;
}

void output(int Uinput, double sum) // display output to user
{
    
    if(Uinput == 1 || Uinput < 0) // inform the user of the invalid input and request new input
    {
            cout << "Input is equal to 1 or less than 0" << endl;
            input(Uinput);
    }
    if(Uinput > 1) // input is valid, display original number and sum
    {
        cout << "original number is: " << Uinput << endl;
        cout << "sum is: " << sum << endl;
    }
}

double findSum(int input, double sum) // compute the sum of the series
{
    double i = 1.0;
    while (input > 0)
    {
        sum += (i/input); // sum of series
        i++; // Increases numerator
        input--; // decrease denominator
    }
        input += (i-1); // Convert input back to original value
        output(input, sum); // give user input
        return sum;
}

int main() // make input and out and computation seperate functions, use is digit
{
    int Uinput = 1; // user input
    double sum = 0.0; // sum of series
    
    while(Uinput != 0) // Program terminates if input is equal to 0
    {
        Uinput = input(Uinput);
        if(Uinput == 1 || input < 0)
        {
            output(Uinput, sum); // return error message and ask user to re enter input
        }
        if(Uinput > 1) // Correct input
        {
            double sum = 0.0;
            sum = findSum(Uinput, sum); // find sum
        }
    }
    return 0;
}