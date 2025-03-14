// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*
	Program that takes input from user for 2 primary colors and displays the secondary color created by mixing the two primary colors
*/

int main()
{
	// constants for the possible colors
	const int RED = 1;
	const int BLUE = 2;
	const int YELLOW = 3;
	const int PURPLE = 4;
	const int ORANGE = 5;
	const int GREEN = 6;

	// variables for user input of 2 primary colors
	int color1 = 0, color2 = 0;
	int Scolor = 0; // variable for mixed color
	string c1, c2, Sc; // string for color1, color2 and secondary color

	// ask user for 2 primary color input
	cout << "Enter your two primary colors: 1 for red, 2 for blue and 3 for yellow: ";
	cin >> color1 >> color2;
	cout << "You entered " << color1 << ", " << color2 << endl;

	if ((color1 == RED || color1 == BLUE || color1 == YELLOW) && (color2 == RED || color2 == BLUE || color2 == YELLOW))
	{
		if (color1 != color2)
		{
			if ((color1 == RED || color2 == RED) && (color1 == RED || color2 == RED))
			{
				Scolor = 4;
			} // checks if secondary color is purple and set secondary color varaible to the correct numerical value (4)
			else if ((color1 == RED || color2 == RED) && (color1 == YELLOW || color2 == YELLOW))
			{
				Scolor = 5;
			} // checks if secondary color is orange and set secondary color varaible to the correct numerical value (5)
			else
			{
				Scolor = 6;
			} // if secondary color is not purple or orange sets secondary color variable to the numerical value of green (6)

			// if statements to assign values to c1
			if (color1 == 1)
				c1 = "red";
			else if (color1 == 2)
				c1 = "blue";
			else if (color1 == 3)
				c1 = "yellow";
			else
				cout << "Invalid";

			// if statements to assign value to c2
			if (color2 == 1)
				c2 = "red";
			else if (color2 == 2)
				c2 = "blue";
			else if (color2 == 3)
				c2 = "yellow";
			else
				cout << "Invalid";

			// if statements to assign value to Sc
			if (Scolor == 4)
				Sc = "purple";
			else if (Scolor == 5)
				Sc = "orange";
			else if (Scolor == 6)
				Sc = "green";
			else
				cout << "Invalid";

			// output entered colors and secondary color
			cout << "Primary colors are " << c1 << " and " << c2 << ", resulting secondary color is " << Sc << endl;

		} //check if the two colors inputed are different
		else cout << "Invalid colors";
	} // checks if user entered a primary color
	else
		cout << "Invalid colors" << endl;
	
	return 0;
}


