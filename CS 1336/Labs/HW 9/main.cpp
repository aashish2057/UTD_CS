#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
    Purpose - Read file from user, and print highest values and lowest value in the file
    Author - Aashish Sharma
*/

bool highestFromFile(string Ifilename, double &val) // open file, read data and determine highest value
{
    double highest;
    ifstream inputFile;
    inputFile.open(Ifilename); // open user file

    if(inputFile) // if input file can be opened
    {
        while (inputFile >> val)
        {
            if (val > highest) // determines highest value in file
            {
                highest = val; // sets highest value in file
            }
        }
        val = highest; // set val to highest so that it is passed by reference
        inputFile.close(); // close file
        return true;
    }
    else // if input file cannot be opened
    {
        cout << "Could not open file" << endl; // prompt user of file error
        return false;
    }
}

bool lowestFromFile(string Ifilename, double &val)
{
    double lowest = 1000000.00; // set lowest to 1000000.00, so that val isnt compared with 0
    ifstream inputFile;
    inputFile.open(Ifilename); // open user file

    if(inputFile) // if input file can be opened
    {
        while (inputFile >> val)
        {
            if (val < lowest) // determines highest value in file
            {
                lowest = val; // sets highest value in file
            }
        }
        val = lowest; // set val to highest so that it is passed by reference
        inputFile.close(); // close file
        return true;
    }
    else // if input file cannot be opened
    {
        cout << "Could not open file" << endl; // prompt user of file error
        return false;
    }
}

int main()
{
    string Ifilename = "";
    double val = 0.0; // highest val variable
    cout << "Enter input file name: "; // prompt user for input file name
    cin >> Ifilename;

    if(highestFromFile(Ifilename, val) == true) // if file open is successful in function continue
    {
        cout << "Highest value is " << val << endl; // prompt user of highest val in file
        if(lowestFromFile(Ifilename, val) == true) // if file open is successful in function continue
        {
            cout << "Lowest value is " << val << endl; // prompt user of lowest val in file
        }
    }

}
