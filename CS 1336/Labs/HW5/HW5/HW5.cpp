// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

/*
	Program that takes user input for weight of a package and distance to ship and determines the charges
*/

using namespace std;

int main()
{
	// intialize variables
	int distance = 0, roundedMultiple = 0;
	double weight = 0.0, rate = 0.0, charge = 0.0;

	// get user input for weight
	cout << "Enter the weight of the package in kilograms (max 20kg): ";
	cin >> weight;
	cout << "Weight entered is " << weight << endl;

	// validate that user input for weight fits in the range (0,20]
	if (weight > 0 && weight <= 20)
	{
		// get user input for distance to be shipped
		cout << "Enter the distance to be shipped: (min 10 Mi, max 3000 Mi): ";
		cin >> distance;
		cout << "Distance entered is " << distance << endl;

		// validate if user input for distance fits in the range [10,3000]
		if (distance >= 10 && distance <= 3000)
		{
			// determine rounded multiple
			roundedMultiple = ((distance - 1) / 500) + 1;

			// determine shipping charge
			if (weight <= 2)
			{
				rate = 1.10;
				charge = roundedMultiple * rate;
			}
			else if (weight > 2 && weight <= 6)
			{
				rate = 2.20;
				charge = roundedMultiple * rate;
			}
			else if (weight > 6 && weight <= 10)
			{
				rate = 3.70;
				charge = roundedMultiple * rate;
			}
			else
			{
				rate = 4.80;
				charge = roundedMultiple * rate;
			}

			// output charge
			cout << "The shipping charge is $" << charge << endl;
		}

		else // display if distance is too short or too long
		{
			cout << "We do not ship less than 10 miles or more than 3000 miles." << endl;
		}
	}
	else
	{
		if (weight < 0) // display if weight is below 0 kg
		{
			cout << "Weight must be greater than zero." << endl;
		}
		else // display if weight is above 20kg
		{
			cout << "We do not ship packages of more than 20 kg." << endl;
		}
	}
	return 0;
}

