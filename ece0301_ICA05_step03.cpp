// Amit Nafshi
// ECE 0301
// ICA 05

// Preprocessor functions
#include <iostream>
#include <cmath> 
#include <fstream>
#include <string>
#include <iomanip>

// Set up namespace
using namespace std;

//Declare Functions
bool or3in(bool, bool, bool);
void truthTab(ofstream &, bool);
bool and3in(bool, bool, bool);

// Main function
int main()
{
	// Define ofstream to create output file
	ofstream boolFunc("Bool_func_3var_CSOP_CPOS.txt");
	
	// Intro Message
	boolFunc << "ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms." << endl << endl;
	
	// Run OR gate function
	truthTab(boolFunc, 0);
	truthTab(boolFunc, 1);
	
	// Close ofstream
	boolFunc.close();
	
	// Return 0 to main function to end program
	return 0;
}


// Set up 3-input OR gate function
bool or3in(bool x, bool y, bool z)
{
	bool orBool;
	
	// Checks if all the bools are false
	if (x == false && y == false && z == false)
	{
		orBool = false;
	}
	else
	{
		orBool = true;
	}

	// Return output of OR gate
	return orBool;
}



// Create truth table function 
void truthTab(ofstream &boolFunc, bool orAnd)
{
	if (orAnd == 0)
	{
		boolFunc << "Truth table for OR gate." << endl << endl;
		boolFunc << "x\ty\tz\tf(x,y,z)" << endl;
		boolFunc << "--------------------------------" << endl;
		
		// Using for loop to print x, y, z, and f 
		for(int i=0;i<=7;i++)
		{
			bool x, y, z, f; // Declare in loop so it resets with every iteration 
			
			// Convert # of loop counter in octal to binary and assinging each value to xyz
			x = (i >> 2) % 2;
			y = (i >> 1) % 2;
			z = (i >> 0) % 2;
			// Input xyz to OR function to compute f for each iteration
			f = or3in(x, y, z);
			
			// Print Results
			boolFunc << x << "\t" << y << "\t" << z << "\t" << f << endl << endl;
		}
	}
	else if (orAnd == 1) 
	{
		boolFunc << "Truth table for AND gate." << endl << endl;
		boolFunc << "x\ty\tz\tf(x,y,z)" << endl;
		boolFunc << "--------------------------------" << endl;
		
		// Using for loop to print x, y, z, and f 
		for(int i=0;i<=7;i++)
		{
			bool x, y, z, f; // Declare in loop so it resets with every iteration 
			
			// Convert # of loop counter in octal to binary and assinging each value to xyz
			x = (i >> 2) % 2;
			y = (i >> 1) % 2;
			z = (i >> 0) % 2;
			// Input xyz to OR function to compute f for each iteration
			f = and3in(x, y, z);
			
			// Print Results
			boolFunc << x << "\t" << y << "\t" << z << "\t" << f << endl << endl;
		}
	}
}
 

// Set up 3-input AND gate function
bool and3in(bool x, bool y, bool z)
{
	bool andBool;
	
	// Checks if all the bools are true
	if (x == true && y == true && z == true)
	{
		andBool = true;
	}
	else
	{
		andBool = false;
	}

	// Return output of AND gate
	return andBool;
}








