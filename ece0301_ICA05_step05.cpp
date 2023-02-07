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
string oct2min(int);
string oct2max(int);

// Main function
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
		
	boolFunc << "m" << inFile << " = " << minTerm << endl;
	boolFunc << "M" << inFile << " = " << maxTerm;
	
	// Close ofstream
	boolFunc.close();
	
	// Return 0 to main function to end program
	return 0;
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





















