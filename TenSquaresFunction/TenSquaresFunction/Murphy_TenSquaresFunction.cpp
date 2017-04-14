// This program displays a list of numbers and
// their squares.
//Programmer: Zach Murphy on 4-13-2017
//CPT-180 C++ Programming
#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <ShlObj.h>
#include <string>
#include <iomanip>
#include <locale> // Allows commas to be inserter in numbers

using namespace std;

//global variables
int num, w1 = 8, w2 = 14;
int ctr = 1;

//function prototype
void tenSquares(int, string);
int main()
{
	// Allows commas to be inserter in numbers
	cout.imbue(locale(""));
	cout << fixed << setprecision(2) << '\n';

	// Gets the user's Documents folder patch
	char path[MAX_PATH];
	SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, 0, path);
	string mypath = path; //recast char array to string object
	string myfilename = "TenSquares.txt";
	string ofilename = mypath + "\\" + myfilename;

	//intro to user
	cout << "*****************************************************************************\n";
	cout << "Enter a number between 1 and 1,000 and I will\n";
	cout << "square it and create a table of ten rows of\n";
	cout << "squares, incrementing the base on each row.\n\n";

	// Get the beginning number to be squared from the user
	cout << "Enter the starting number to be squared: ";
	cin >> num;

	// Validate that it is between 1 and 100
	while (!(num >= 1 && num <= 1000))
	{
		cout << "\nERROR! You must enter a number between 1 and 1,000: ";
		cin >> num;
	}

	//pass input from user and file name/path to fucntion
	tenSquares(num, ofilename);
	
	cout << "\nData has been saved in " << ofilename << endl << endl; // Tell user file that data is saved in
	cout << "*****************************************************************************\n";
	cout << "\nPress any key to exit.";

	_getch();
	return 0;
}

/*
tenSquares Function:
takes a file path and number passed to it
then squares that number and ten after that
output is displayed to user
output is also sent to file per passed
*/
void tenSquares(int number, string fileName) {
	//open file
	ofstream outputfile;
	outputfile.open(fileName);

	//file output format
	//screen output format
	outputfile << left << "\n\n" << setw(w1) << "Number" << setw(w2) << "\tNumber Squared\n";
	outputfile << "---------------------------------\n";
	cout << left << "\n\n" << setw(w1) << "Number" << setw(w2) << "\tNumber Squared\n";
	cout << "---------------------------------\n";

	//squaring time with formating to both file and screen
	while (ctr <= 10)
	{
		cout << right << setw(w1) << number << "\t" << setw(w2) << (number * number) << endl;
		outputfile << right << setw(w1) << number << "\t" << setw(w2) << (number * number) << endl;
		ctr++;
		number++;
	}

	outputfile.close();  // Close the file

}