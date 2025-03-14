// HW6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*
	Take user input for traffic accident statistics for four geographic regions(north, south, east and west), then display a menu that
	lets users see (safest region, least safe region, all regision)
*/
int getChoice() // display the menu of choices, gets user input and validates
{
	// display menu to user
	int menu = 0;
	cout << "\nMenu";
	cout << "----" << endl;
	cout << "1->Display safest region, 2->Display least safe region, 3->Display all" << endl;
	cin >> menu;

	// validate user input
	if (menu >= 1 && menu <= 3) // user input valid [1,3]
	{
		cout << "You entered " << menu << endl;
		return menu;
	}
	else // user input invalid ![1,3]
	{
		cout << "Invalid choice";
	}
	
}

int getAccidentTotal(string region) // display region name and gets user intput for region, returns accident total
{
	int Anorth = 0, Asouth = 0, Aeast = 0, Awest = 0;
	//take user input for accident totals in each region
	if (region == "north") // determines accident total for north region
	{
		cout << "Enter the accident total for the north region: ";
		cin >> Anorth;
		cout << "Accident total enetered for north region is " << Anorth << endl;
		return Anorth;
	}
	else if (region == "south") // determines accident total for south region
	{
		cout << "Enter the accident total for the south region: ";
		cin >> Asouth;
		cout << "Accident total enetered for south region is " << Asouth << endl;
		return Asouth;
	}
	else if (region == "east") // determines accident total for east region
	{
		cout << "Enter the accident total for the east region: ";
		cin >> Aeast;
		cout << "Accident total enetered for east region is " << Aeast << endl;
		return Aeast;
	}
	else // determines accident total for west region
	{
		cout << "Enter the accident total for the west region: ";
		cin >> Awest;
		cout << "Accident total enetered for west region is " << Awest << endl;
		return Awest;
	}
	
}
/*
void findSafest() // determines safest region and prints name of safest region
{

}

void LeastSafe() // determine the least safe region and prints name of least safest region
{

}

void displayAll() // display all region names and accident totals
{

}
*/
int main()
{
	int totalNorth = 0, totalSouth = 0, totalEast = 0, totalWest = 0; // variables for accident totals in each region
	int choice = 0; // variable for user choice
	totalNorth = getAccidentTotal("north"); // gets accident total for north
	totalSouth = getAccidentTotal("south"); // get accident total for south
	totalEast = getAccidentTotal("east"); // get accident total for east
	totalWest = getAccidentTotal("west"); // get accident toal for west

	// cout << totalNorth << totalSouth << totalEast << totalWest; debug code
	choice = getChoice(); // call getChoice function to get accident totals for each region

	/*if (choice == 1)
	{

	}
	else if (choice == 2)
	{

	}
	else if (choice == 3)
	{

	}
	*/
	cout << "Exiting";
}


