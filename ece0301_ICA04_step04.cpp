// Amit Nafshi
// ECE 301
// ICA 04

//Preprocessor functions
#include <iostream>
#include <cmath> 
#include <fstream>
#include <string>
#include <iomanip>

//Set up namespace
using namespace std;

//Main function
int main()
{
	//2. Read txt file

	//Declare ifstream and input string
	ifstream checkIn("divider_wheatstone_circuits.txt"); //Opens input file
	string divC;
	
	checkIn >> divC;
	
	while (true)
	{
		//Checks if first line is valid
		if (divC == "Divider" || divC == "Wheatstone")
		{
			break;
		}
		else
		{
			cout << endl << "ERROR! Invalid header.";
			return -1;
		}
	}
	
	checkIn.close(); //Close ifstream
	
	//3. Set up variables in input file
	if (divC == "Divider") //Divider circuit
	{
		//Read variables from input file
		ifstream varsRead("divider_wheatstone_circuits.txt");
		
		//Initialize variables
		string divY;
		double Vs;
		int R1, R2;
		
		//Read variables from file
		varsRead >> divY;
		varsRead >> Vs;
		varsRead >> R1;
		varsRead >> R2;
		
		
		//Close varsRead
		varsRead.close();
		
		//Open txt file
		ofstream varsInDiv;
		varsInDiv.open("divider_wheatstone_solutions.txt");
		
		//Print values to file
		varsInDiv << "ECE 0301: Circuit Solver for Voltage Divider" << endl
				  << "and Wheatstone bridge example circuits." << endl
		          << "-----" << endl 
				  << "Circuit #1 (Voltage Divider)" << endl
				  << "---" << endl;
		varsInDiv << "Source voltage: Vs = " << Vs << " Volts." << endl;
		varsInDiv << "Resistor: R1 = " << R1 << " Ohms." << endl;
		varsInDiv << "Resistor: R2 = " << R2 << " Ohms." << endl << endl;
		
		//Set up amp variable 
		double iAmp = (Vs / (R1 + R2));
		
		                          //set precision for I after string
		varsInDiv << "Loop current: I = " << setw(3) << iAmp << " Amperes." << endl;
		varsInDiv << "Resistor voltage: V1 = " << setw(5) << iAmp * R1 << " Volts." << endl;
		varsInDiv << "Resistor voltage: V2 = " << setw(5) << iAmp * R2 << " Volts." << endl;
		
		//Close varsInDiv
		varsInDiv.close();
	}
	//Return 0 to main to end program
	return 0;
}
