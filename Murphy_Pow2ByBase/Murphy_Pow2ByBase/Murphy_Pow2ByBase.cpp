// This program demonstrates a function with a parameter.
//CPT-180
//Programmer: Zach Murphy on 4-5-2017
#include <iostream>
#include <math.h>
#include <cmath>
#include <conio.h>
using namespace std;

// Function Prototype
void PowerNumByBase(int);

int main()
{
	int base;
	cout << "****************************************************************************\n";
	cout << "\t\t\tPower to Self\n";
	cout << "This program will power a number to itself, based off your input.\n";
	cout << "If you enter five it will power five to the fith power. \n";
	cout << "****************************************************************************\n";
	cout << "Please enter a number to power to by its base: ";
	cin >> base;
	PowerNumByBase(base);  // Call PowerByNumBase function
	cout << endl;
	cout << "Press any key to exit...";
	_getch();
	return 0;
}

// PowerNumByBase function raises a number to its own power.

void PowerNumByBase(int num)
{
	int result = pow(num, num);
	cout << num << "Result: to the power of " << num << " is: " << result;
}