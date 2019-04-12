#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	Purpose - Read text file with student record and display netID, major and GPA
	Purpose(bonus) - Get additional student records from student, and determine number of CS students, and display highest GAP and lowest GPA students with netids
	Author - Aashish Sharma
*/

int populateArrays(string fileName, int netIDArray[], string majorArray[], double gpaArray[], int size, int &records) // fill arrays with record from student file
{
	int i = 0;
    records = 0;
	ifstream inputFile;
	inputFile.open(fileName); // open file

	if (inputFile) // parse through the input file
	{
	    while(records < size)
        {
            if (inputFile >> netIDArray[i] >> majorArray[i] >> gpaArray[i])
            {
                i++; // increase increment by 1
                records++; // increase record size by 1
            }
            else
            {
                break;
            }
        }

		inputFile.close(); // close file

	}
	else
	{
	    inputFile.close(); // close file
		return 1;
	}
	return 0;
}

int main()
{
    int size = 15;
    int record = 0;
	int netIDArray[15]; // net ID array
	string majorArray[15]; // major array
	double gpaArray[15]; // gpa array
	string fileName;
	int test = 0;// variable used to determine is file is valid

	cout << "Enter file name: "; // prompt user for file inpiut
	cin >> fileName;

	test = populateArrays(fileName, netIDArray, majorArray, gpaArray, size, record);
	if (test == 0) // file is valid
	{
        int printC = 0; // counter to print 3 records per line
        //display
        cout << "Number of records = " << record << endl;
        cout << "\n";
        cout << "******" << endl;
        cout << "Part 1" << endl;
        cout << "******" << endl;
        cout << "NetID array" << endl;
        cout << "-----------" << endl;
        for(int i = 0; i < record; i++)
        {
            if(printC < 3 && printC > 0) // add a comma after record if another record is going to follow it on the same line
            {
                cout << ", ";
            }
            if(printC == 3) // go to next line after 3 records have been displayed
            {
                cout << endl;
                printC = 0;
            }
            cout << "netIDArray[" << i << "] = " << netIDArray[i]; // print record
            printC++; // add one to print counter
        }

        printC = 0;
        cout << "\n";
        cout << "\n";
        cout << "Major array" << endl;
        cout << "-----------" << endl;
        for(int i = 0; i < record; i++)
        {
            if(printC < 3 && printC > 0) // add a comma after record if another record is going to follow it on the same line
            {
                cout << ", ";
            }
            if(printC == 3) // go to next line after 3 records have been displayed
            {
                cout << endl;
                printC = 0;
            }
            cout << "majorArray[" << i << "] = " << majorArray[i];
            printC++;
        }

        printC = 0;
        cout << "\n";
        cout << "\n";
        cout << "GPA array" << endl;
        cout << "---------" << endl;
        for(int i = 0; i < record; i++)
        {
            if(printC < 3 && printC > 0) // add a comma after record if another record is going to follow it on the same line
            {
                cout << ", ";
            }
            if(printC == 3) // go to next line after 3 records have been displayed
            {
                cout << endl;
                printC = 0;
            }
            cout << "gpaArray[" << i << "] = " << gpaArray[i];
            printC++;
        }
        // determine lowest gpa
        cout << "\n";
        cout << "\n";
        cout << "Lowest GPA" << endl;
        cout << "----------" << endl;
        double lowest;
        lowest = gpaArray[0]; // set lowest to first gpa value
        int Ltracker = 0;
        for(int i = 1; i < record; i++) // go through array
        {
            if(gpaArray[i] < lowest) // if the next gpa is lower than lowest
            {
                lowest = gpaArray[i]; // set lowest to that gpa value
            }
            if(gpaArray[i] == lowest) // once lowest is found keep track of location, in order to determine major and net id
            {
                Ltracker = i;
            }
        }
        cout << "NetID is " << netIDArray[Ltracker] << ", major is " << majorArray[Ltracker] << ", GPA = " << lowest << endl;
        // determine highest gpa
        cout << "\n";
        cout << "Highest GPA" << endl;
        cout << "-----------" << endl;
        // determine lowest GPA
        double highest;
        highest = gpaArray[0];
        int Htracker = 0;
        for(int i = 1; i < record; i++) // go through array
        {
            if(gpaArray[i] > highest) // if the next gpa is higher than highest
            {
                highest = gpaArray[i];// set highest to that gpa value
            }
            if(gpaArray[i] == highest) // once highest is found keep track of location, in order to determine major and net id
            {
                Htracker = i;
            }
        }
        cout << "NetID is " << netIDArray[Htracker] << ", major is " << majorArray[Htracker] << ", GPA = " << highest << endl;

        cout << "\n";
        cout << "Search on student's netID" << endl;
        cout << "-------------------------" << endl;
        int netID = 0;
        int choice = 1;

        while(choice != -1)
        {
            cout << "Input student's netID, -1 to quit: ";
            cin >> netID;
            int found = 0;
            if(netID == -1) // if user wants to quit
            {
                choice = netID;
            }
            else
            {
                int Ntracker = 0;
                for(int i = 0; i < record; i++) // go through array
                {
                    if(netIDArray[i] == netID) // add new net ids to array
                    {
                        Ntracker = i;
                        found = 1;
                    }
                }
                if(found == 1) // if netid is found
                {
                    cout << "NetID is " << netID << ", major is " << majorArray[Ntracker] << ", GPA = " << gpaArray[Ntracker] << endl; // display new array
                }
                else // if net is isnt found
                {
                    cout << "NetID not found" << endl; // tell user net id is invalid
                }

            }
        }

        // Bonus part I think this is right, zylabs for some reason is showing part 1 when checking for part 2 and counting it wrong
        cout << "******" << endl;
        cout << "Part 2" << endl;
        cout << "******" << endl;
        choice = 0;
        string major;
        double gpa;
        int i = record;
        while(choice != -1)
        {
            cout << "Enter netID, -1 if done: ";
            cin >> netID;
            if(netID == -1) // if user is done
            {
                choice = netID;
            }
            else
            {
                cout << "Enter major then GPA: "; // get gpa and major from user
                cin >> major >> gpa;
                netIDArray[i] = netID; // add new values
                majorArray[i] = major; // add new values
                gpaArray[i] = gpa; // add new values
                i++;
            }
            cout << endl;
        }

        cout << "\n";
        cout << "\n";
        cout << "--------------" << endl;
        cout << "Updated arrays" << endl;
        cout << "--------------" << endl;
        cout << "NetID array" << endl;
        cout << "-----------" << endl;
        printC = 0;
        for(int i = 0; i < 15; i++)
        {
            if(printC < 3 && printC > 0) // add a comma after record if another record is going to follow it on the same line
            {
                cout << ", ";
            }
            if(printC == 3) // go to next line after 3 records have been displayed
            {
                cout << endl;
                printC = 0;
            }
            cout << "netIDArray[" << i << "] = " << netIDArray[i]; // print record
            printC++; // add one to print counter
        }

        printC = 0;
        cout << "\n";
        cout << "\n";
        cout << "Major array" << endl;
        cout << "-----------" << endl;
        for(int i = 0; i < 15; i++)
        {
            if(printC < 3 && printC > 0) // add a comma after record if another record is going to follow it on the same line
            {
                cout << ", ";
            }
            if(printC == 3) // go to next line after 3 records have been displayed
            {
                cout << endl;
                printC = 0;
            }
            cout << "majorArray[" << i << "] = " << majorArray[i];
            printC++;
        }

        printC = 0;
        cout << "\n";
        cout << "\n";
        cout << "GPA array" << endl;
        cout << "---------" << endl;
        for(int i = 0; i < 15; i++)
        {
            if(printC < 3 && printC > 0) // add a comma after record if another record is going to follow it on the same line
            {
                cout << ", ";
            }
            if(printC == 3) // go to next line after 3 records have been displayed
            {
                cout << endl;
                printC = 0;
            }
            cout << "gpaArray[" << i << "] = " << gpaArray[i];
            printC++;
        }

        // CS statistics
        cout << "\n";
        cout << "CS statistics" << endl;
        cout << "-------------" << endl;
        int CScounter = 0;
        for(int i = 0; i < 15; i++)
        {
            if(majorArray[i] == "CS") // count number of cs students
            {
                CScounter++;
            }
        }
        cout << "There are " << CScounter << " CS students" << endl;
        cout << "\n";
        lowest = gpaArray[1];
        for(int i = 1; i < 15; i++)
        {
            if(majorArray[i] == "CS")
            {
                if(gpaArray[i] < lowest) // determnine lowest gpa of cs students
                {
                    lowest = gpaArray[i];
                }
                if(gpaArray[i] == lowest) // once lowest is found keep track of location for major and netid
                {
                    Ltracker = i;
                }
            }
        }
        //display lowest information to user
        cout << "Among all the CS students, the lowest GPA is " << lowest << endl;
        cout << "The CS student(s) with that GPA are: " << endl;
        cout << "NetID = " << netIDArray[Ltracker] << endl;
        cout << "\n";
        highest = gpaArray[1];
        for(int i = 1; i < 15; i++)
        {
            if(majorArray[i] == "CS")
            {
                if(gpaArray[i] > highest) // determine highest gpa for cs students
                {
                    highest = gpaArray[i];
                }
                if(gpaArray[i] == highest) // once highest is found keep track of location for major and netid
                {
                    Htracker = i;
                }
            }
        }
        // display highest information to user
        cout << "Among all the CS students, the highest GPA is " << highest << endl;
        cout << "The CS student(s) with that GPA are: " << endl;
        cout << "NetID = " << netIDArray[Htracker];

	}
	else // file couldnt be opened
	{
		cout << "Could not open file"; // notify user that file cannot be opened/
		exit(EXIT_FAILURE);
	}
	return 0;
}
