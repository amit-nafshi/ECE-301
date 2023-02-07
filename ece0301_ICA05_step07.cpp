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
void truthTab(ofstream &, bool, int);
bool and3in(bool, bool, bool);	
string oct2min(int);
string oct2max(int);
bool oct2min(bool, bool, bool, int);
bool oct2max(bool, bool, bool, int);
	
//Main function					
int main()
{ 
	// Open ifstream fie
	ifstream minFunc("Bool_func_3var.txt");
	int inFile;
	minFunc >> inFile;
	
	//Check inFile
	if (inFile < 0 || inFile > 7)			
	{
		cout << "ERROR! Invalid minterm index." << endl;
		return -1;
	}
	
	// Define ofstream to create output file
	ofstream boolFunc("Bool_func_3var_CSOP_CPOS.txt");
	
	// Intro Message
	boolFunc << "ECE 0301: Boolean Functions of 3 Variables." << endl;
	boolFunc << "Realization in Canonical Forms." << endl << endl;
	
	// Call Function
	string minTerm = oct2min(inFile);
	string maxTerm = oct2max(inFile);
		
	boolFunc << "m" << inFile << " = " << minTerm << endl << endl;
	truthTab(boolFunc, 0, inFile);
	boolFunc << endl << "M" << inFile << " = " << maxTerm << endl << endl;
	truthTab(boolFunc, 1, inFile);
	
	// Close ofstream
	boolFunc.close();											
	return 0;
}

// Set up 3-input OR gate function
bool or3in(bool x, bool y, bool z)
{
	bool orBool;
	
	if (x || y || z)
	{
		orBool = true;
	}
	else
	{
		orBool = false;
	}

	// Return output of OR gate
	return orBool;
}

// Create truth table function 
void truthTab(ofstream &boolFunc, bool orAnd, int tInt)
{
	if (orAnd == 0)
	{
		boolFunc << "Truth table for minterm " << tInt << endl << endl;
		boolFunc << "x\ty\tz\tf(x,y,z)" << endl;
		boolFunc << "--------------------------------" << endl;
		
		// Using for loop to print x, y, z, and f 
		for(int i=0;i<=7;i++)
		{
			bool x, y, z; // Declare in loop so it resets with every iteration 
			
			// Convert # of loop counter in octal to binary and assinging each value to xyz
			x = (i >> 2) % 2;
			y = (i >> 1) % 2;
			z = (i >> 0) % 2;

			// Print Results
			boolFunc << x << "\t" << y << "\t" << z << "\t" << oct2min(x, y, z, tInt) << endl;
		}
	}
	else if (orAnd == 1) 
	{
		boolFunc << "Truth table for maxterm " << tInt << endl << endl;
		boolFunc << "x\ty\tz\tf(x,y,z)" << endl;
		boolFunc << "--------------------------------" << endl;
		
		// Using for loop to print x, y, z, and f 
		for(int i=0;i<=7;i++)
		{
			bool x, y, z; // Declare in loop so it resets with every iteration 
			
			// Convert # of loop counter in octal to binary and assinging each value to xyz
			x = (i >> 2) % 2;
			y = (i >> 1) % 2;
			z = (i >> 0) % 2;
			
			// Print Results
			boolFunc << x << "\t" << y << "\t" << z << "\t" << oct2max(x, y, z, tInt) << endl;
		}
	}
}
 
// Set up 3-input AND gate function
bool and3in(bool x, bool y, bool z)
{
	bool andBool;
	
	// Checks if all the bools are true
	if (x && y && z)
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

// Octal-to-Minterm function
string oct2min(int octIn)
{
	string minVal, xS = "x", yS = "y", zS = "z"; 
	bool x, y, z;  		
	x = (octIn >> 2) % 2;
	if (x == 0)
	{
		xS += "'";
	}
	y = (octIn >> 1) % 2;
	if (y == 0)
	{
		yS += "'";
	}
	z = (octIn >> 0) % 2;
	if (z == 0)
	{
		zS += "'";
	}
	minVal = xS + yS + zS;
		
	return minVal;
}
// Octal-to-Maxterm function
string oct2max(int octIn)
{
	string maxVal, xS = "x", yS = "y", zS = "z";
	bool x, y, z;  		
	x = (octIn >> 2) % 2;
	if (x == 1)
	{
		xS += "'";
	}
	y = (octIn >> 1) % 2;
	if (y == 1)
	{
		yS += "'";
	}
	z = (octIn >> 0) % 2;
	if (z == 1)
	{
		zS += "'";
	}
	maxVal = xS + " + " + yS + " + " + zS;
		
	return maxVal;
}

//Overloaded minterm function
bool oct2min(bool x, bool y, bool z, int octIn)							
{	
	double bit1, bit2, bit3;
	
	
	bit1 = (octIn%2);	  // 000													
	bit2 = (octIn/2)%2;   //  00
	bit3 = (octIn/2/2)%2; //   0
	
	if (bit1 == 0)														
	{
		z = !z;
	}
	if (bit2 == 0)
	{
		y = !y;
	}
	if (bit3 == 0)
	{
		x = !x;
	}
	
	bool minOut = and3in(x, y, z);									
	return minOut;
}

// Overload maxterm
bool oct2max(bool x, bool y, bool z, int octIn)
{
	double bit1, bit2, bit3;
	
	bit1 = (octIn%2);	  // 000													
	bit2 = (octIn/2)%2;   //  00
	bit3 = (octIn/2/2)%2; //   0
	 
	if (bit1 == 1)														
	{
		z = !z;
	}
	if (bit2 == 1)
	{
		y = !y;
	}
	if (bit3 == 1)
	{
		x = !x;
	}

	bool maxOut = or3in(x, y, z);									
	return maxOut;
}
