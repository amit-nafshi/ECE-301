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
	else if (divC == "Wheatstone") //Wheatstone circuit
	{
		//Read variables from input file
		ifstream wheatVar("divider_wheatstone_circuits.txt");
		
		//Initialize read variables
		string wheety;
		double Vs, Is;
		int R1, R2, R3, R4, R5; 
		
		//Read file to variables
		wheatVar >> wheety;
		wheatVar >> Vs;
		wheatVar >> Is;
		wheatVar >> R1;
		wheatVar >> R2;
		wheatVar >> R3;
		wheatVar >> R4;
		wheatVar >> R5;
		
		//Close ifstream
		wheatVar.close();
				
		//Open txt file
		ofstream inWheat("divider_wheatstone_solutions.txt");
		
		//Print values to file
		inWheat << "ECE 0301: Circuit Solver for Voltage Divider" << endl
				<< "and Wheatstone bridge example circuits." << endl
		        << "-----" << endl 
				<< "Circuit #1 (Wheatstone Bridge)" << endl
				<< "---" << endl;
		inWheat << "Source voltage: Vs = " << Vs << " Volts." << endl;
		inWheat << "Source current: Is = " << Is << " Amperes." << endl;
		inWheat << "Resistor: R1 = " << R1 << " Ohms." << endl;
		inWheat << "Resistor: R2 = " << R2 << " Ohms." << endl;
		inWheat << "Resistor: R3 = " << R3 << " Ohms." << endl;
		inWheat << "Resistor: R4 = " << R4 << " Ohms." << endl;
		inWheat << "Resistor: R5 = " << R5 << " Ohms." << endl << endl;
		
		//Check conditions of R2 R3 and range of Vs - IsR4 and Vs - IsR5
		double cond1 = Vs - (Is*R4), cond2 = Vs + (Is*R5);
		
		if (R2 != 0 && R3 != 0 && (cond1 < -10e-13 || cond1 > 10e-13) && (cond2 < -10e-13 || cond2 > 10e-13))
		{
			//null
		}
		else	
		{
			cout << endl << "ERROR! Unstable floating-point division.";
			return -1;
		}
		
		
		//Computer V1-V5 and I1 to I5
		//Set up current and voltage variables
		double V1, V2, V3, V4, V5, I1, I2, I3, I4, I5;
		/* Set up KCL calculation variables following the equations in the sheet
		 * V1 + aV2 = b
		 * V1 + cV3 = d
		 *       V1 = eV2 + fV3
		 */ 
		double a = 1 + ((double) R4 / R2), b = Vs - (Is * (double) R4), c = 1 + ((double) R5 / R3), d = Vs + (Is * (double) R5), e = (double) R1 / R2, f = (double) R1 / R3;
		/* Continue setting up KCL variables using equations below
		 * (a+e/b)V2 + (f/b)V3 = 1
		 * (e/d)V2 + (c+f/d)V3 = 1
		 */	
		 double w = (a + e) / b, x = f / b, y = e / d, z = (c + f) / d;
		 /* After these calculations, we can derive V2 and V3
		  * V2 = (1-xV3)/w
		  * V3 = (y-w)/(xy - wz)
		  */
		V3 = (y - w) / ((x*y) - (w*z));
		V2 = (1 - (x*V3)) / w;
		// After aquiring V2 and V3, the rest of the calculations can be computed
		
		//Getting V1, V4, V5
		V1 = e*V2 + f*V3;
		V4 = Vs - V1 - V2;
		V5 = Vs - V1 - V3;
		
		//Calculate I1-I5
		I1 = V1 / R1;
		I2 = V2 / R2;
		I3 = V3 / R3;
		I4 = V4 / R4;
		I5 = V5 / R5;
		
		//Write results to file
		inWheat << "Resistor voltage: V1 = " << V1 << " Volts." << endl;
		inWheat << "Resistor current: I1 = " << I1 << " Amperes." << endl;
		inWheat << "Resistor voltage: V2 = " << V2 << " Volts." << endl;
		inWheat << "Resistor current: I2 = " << I2 << " Amperes." << endl;
		inWheat << "Resistor voltage: V3 = " << V3 << " Volts." << endl;
		inWheat << "Resistor current: I3 = " << I3 << " Amperes." << endl;
		inWheat << "Resistor voltage: V4 = " << V4 << " Volts." << endl;
		inWheat << "Resistor current: I4 = " << I4 << " Amperes." << endl;
		inWheat << "Resistor voltage: V5 = " << V5 << " Volts." << endl;
		inWheat << "Resistor current: I5 = " << I5 << " Amperes." << endl;
		
	}
	else
	{
		cout << endl << "ERROR! Invalid header.";
		return -1;
	}
	//Return 0 to main to end program
	return 0;
}
