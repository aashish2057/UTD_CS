#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
    Problem - Sort using insertion sort algorithm
    Input - user entered file, keep asking for file until user enter *
    variable - statically-allocated one-dimensional array of double, len 100
    Insertion conditions - if empty number goes to first elements, if  not empty
    find two elements where top is small than bottom, then insert and move
    everything down, make sure to determine the count of elements of array
    Output - print the sorted list 
    Author - Aashish Sharma
    netID - axs170083
    Class - CS 1337.009
    Date Started - 2/27/19
*/

string input(string filename) // get file name from user
{
    cout << "Enter file name: ";
    cin >> filename;
    return filename;
}
bool readFile(string filename, double list[100], int &count) // read in data from file and determine number of elements to store in array

{
    ifstream inputFile;
    inputFile.open(filename); // open file
    int i = 0;

    int count = 0;
    while(inputFile >> list[i]) // store file values in array
    {
        i++;
        count++;
    }
    inputFile.close(); // close file
    return count;
}

void sort(double list[100], int count)
{
    // do something in here idk what though
    bool File = true;
    if(inputFile) // File opens successfull
    {
        while(inputFile >> list[i]) // store file values in array
        {
            i++;
            count++; // keep track of number of elements in file
        }
    }
    else // files doesn't open successfully
    {
        cout << "File not Found" << endl;
        File = false;
    }
    inputFile.close(); // close file
    return File;
}

void sort(double list[100], int count) // performs insertion sort on list array
{ 
    for (int i = 1; i < count; i++) // go through the loop
    { 
        int j = list[i]; // j become first value
        int k = i-1; // k will be one value above j
        while (k >= 0 && list[k] > j) // when k is greater than 0 and the value at k is greater than j
        {
            list[k+1] = list[k]; // move the k value down as it is higher than the one below
            k = k-1; 
        } 
        list[k+1] = j; // move the lower value above the higher value
    }
}

void print(double list[100], int count) // print sorted list
{
    cout << "Sorted Array" << endl;
    for(int i = 0; i < count; i++) // print all values of sorted array
    {
        cout << list[i] << endl; 
    }
}

int main()
{
    double list[100]; 
    bool valid = true;
    int count = 0;
    string filename;

    bool File = true;
    int count = 0;
    string filename; 


    while(valid)
    {
        filename = input(filename); // get file name from user
        if(filename.at(0) == '*') // user enters * to end program
        {
            valid = false; // exit program
        }
        else
        {
            count = readFile(filename, list); // read in value from file
            sort(list, count);
            for(int i = 0; i < count; i++)
            {
                cout << list[i] << endl;
            }
        }
            File = readFile(filename, list, count); // read in value from file
            if(File) // if file is valid sort and print
            {
                sort(list, count); // perform insertion sort on the array
                print(list, count); // print sorted array
            } 
    } 
}
