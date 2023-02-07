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
void truthTab(ofstream &, int);
bool and3in(bool, bool, bool);	
string oct2min(int);
string oct2max(int);
bool oct2min(bool, bool, bool, int);
bool oct2max(bool, bool, bool, int);
string CSOP(int);														
bool CSOP(bool, bool, bool, int);	
string CPOS(int);							
bool CPOS(bool, bool, bool, int);			
	
//Main function					
int main()
{ 
	// Open ifstream fie
	ifstream minFunc("Bool_func_3var.txt");
	int inFile;
	minFunc >> inFile;
	
	// Define ofstream to create output file
	ofstream boolFunc("Bool_func_3var_CSOP_CPOS.txt");
	
	// Send CSOP form and value to output file
	boolFunc << "ECE 0301: Boolean Functions of 3 Variables." << endl;
	boolFunc << "Realization in Canonical Forms." << endl << endl;	
	truthTab(boolFunc, inFile);
	
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
void truthTab(ofstream &boolFunc, int tInt)
{
	boolFunc << "CSOP: f" << tInt << " = " << CSOP(tInt) << endl << endl;
	boolFunc << "Truth table for CSOP form of function " << tInt << "." << endl << endl;
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
		boolFunc << x << "\t" << y << "\t" << z << "\t" << CSOP(x, y, z, tInt) << endl;
	}
	boolFunc << endl;
	
	boolFunc << "CPOS: f" << tInt << " = " << CPOS(tInt) << endl << endl;
	boolFunc << "Truth table for CPOS form of function " << tInt << "." << endl << endl;
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
		boolFunc << x << "\t" << y << "\t" << z << "\t" << CPOS(x, y, z, tInt) << endl;
	}
	boolFunc << endl;
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

// CSOP Function
 string CSOP(int canOn)													
{	
	//Error check if between 0-255
	if (canOn < 0 || canOn > 255)										
	{
		cout << "ERROR! Function index out of range." << endl;
		EXIT_FAILURE; // **Alternative to return -1
	}
		
	int binNum[8];													
	string str = " + ";												
	int count = 0;	
	
	while (canOn > 0)														
	{
		binNum[count] = (canOn%2);
		canOn = canOn/2;
		count++;
	}
	
	string SOP;												
	
	for (int i = count -1; i > 0; i--)									
	{																	
		// Index checker
		if (binNum[i] == 1)
		{
			SOP += oct2min(7-i) + str;
			
		}
	}
	
	// Index checker
	if (binNum[0] == 1)												
	{
		SOP += oct2min(7);
	}
	
	return SOP;
}

bool CSOP(bool x, bool y, bool z, int can)
{
	//Error check
	if (can < 0 || can > 255)											
	{
		cout << "ERROR! Function index out of range." << endl;
		EXIT_FAILURE; 
	}
	
	//Initialize return bool
	bool returnVal = 0;												
	
	// Declare array that will hold 8-bit binary number 0-255
	int binNum[8];										
	string str = " + ";												
	int count = 0;	
	
	while (can > 0)														
	{
		binNum[count] = (can%2);
		can = can/2;
		count++;
	}
	
	string SOP;												
	
	for (int i = count -1; i > 0; i--)									
	{																	
		//Index checker
		if (binNum[i] == 1)
		{
			returnVal = (returnVal || oct2min(x, y, z, (7-i)));
		}
	}
	
	//Index checker 
	if (binNum[0] == 1)											
	{
		returnVal = (returnVal || oct2min(x, y, z, (7)));
	}
	
	return returnVal;
	
}

string CPOS(int num)
{
	//Error check
	if (num < 0 || num > 255)											
	{
		cout << "ERROR! Function index out of range." << endl;
		EXIT_FAILURE;
	}
	
	// 8 bit array 
	int binNum[8] = {0, 0, 0, 0, 0, 0, 0, 0};													
	string str1 = "(";
	string str2 = ")";													
	int count = 0;	
	
	while (num > 0)														
	{
		binNum[count] = (num%2);
		num = num/2;
		count++;
	}
	
	string POS;												
	
	for (int i = 7; i >= 0; i--)									
	{																	
		if (binNum[i] == 0)
		{
			POS += str1 + oct2max(i) + str2;
			
		}
	}
	
	return POS;
}

//CPOS function
bool CPOS(bool x, bool y, bool z, int num)
{
	//Error check
	if (num < 0 || num > 255)											
	{
		cout << "ERROR! Function index out of range." << endl;
		EXIT_FAILURE;
	}
	
	bool returnVal = 0;												
	
	int binNum[8];													
	string str1 = " + ";												
	int count = 0;	
	
	while (num > 0)														
	{
		binNum[count] = (num%2);
		num = num/2;
		count++;
	}

	
	for (int i = count -1; i >= 0; i--)									
	{																	
		if (binNum[i] == 1)
		{
			
			returnVal = (returnVal || oct2min(x, y, z, (7-i)));

		}
	}

	return returnVal;
	
}


