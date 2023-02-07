// Amit Nafshi
// ECE 301
// ICA 3

//Set up preprocessor statements
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

//Set up namespace
using namespace std;

//Main function
int main()
{
	//1. Intro Statement
	cout << "ECE 0301 – Vectors in R2 and Complex Numbers" << endl
		 << "Please enter two numbers, separated by a space," << endl
	     << "that will represent a vector or a complex number." << endl << endl;
	
	//2. Set up cin for the two input variables
	
	double num1, num2; //Initialize two variables
	
	cin >> num1 >> num2; //Read user input
	cout << fixed << setprecision(3); //Set decimal precision to fixed 3 
	cout << "You entered " << num1 << " and " << num2 << "." << endl; //Output input values
	
	//3. Ask for Cartesian or Polar
	
	string carPol; //Initialize input variable
	
	cout << endl << "Are these numbers in Cartesian (C) or polar (p) coordinates?" << endl
		 << "Please enter a single character as your choice." << endl; //Prompt user to choose c or p
		 
	cin >> carPol; //sets input to variable
	
	//Input Checker
	if (carPol == "C" || carPol == "c") //Check for Cartesian
	{
		cout << "You entered Cartesian coordinates." << endl;
		double rC, thetaC, xC = num1, yC = num2;
		
		//4. Cartesian to Polar converter
		rC = sqrt(pow(xC, 2) + pow(yC, 2)); // R = SQRT(X^2 + Y^2)
		
		if (xC >= 0)
		{
			thetaC = atan(yC / xC);
		}
		else if (xC < 0 && yC >= 0)
		{
			thetaC = atan(yC / xC) + M_PI; 
		}
		else
		{
			thetaC = atan(yC / xC) - M_PI;
		}
		cout << fixed << setprecision(3); 
		cout << "The equivalent polar coordinates are:" << endl
			 << "R = " << rC << ", theta = " << thetaC << endl;
		
		
	}
	else if (carPol == "P" || carPol == "p") //Check for polar
	{
		cout << "You entered polar coordinates." << endl;
		double xP, yP, rP = num1, thetaP = num2; 
		
		//4. Polar to Cartesian converter
		if (rP < 0) //Check if R is non negative
		{
			//Error message
			cout << "ERROR! Invalid selection, exiting.";
			//return -1 to main due to input error
			return -1;
		}
		else if (thetaP > M_PI && thetaP < (-1*M_PI)) //Check if theta is within range
		{
			//Error message
			cout << "ERROR! Invalid selection, exiting.";
			//return -1 to main due to input error
			return -1;
		}
		else
		{
			xP = rP * cos(thetaP); //Calculate x
			yP = rP * sin(thetaP); //Calculate y
			
			cout << fixed << setprecision(3); 
			cout << "The equivalent polar coordinates are:" << endl
			 << "x = " << xP << ", y = " << yP << endl;
		}
	}
	else 
	{
		//Error message
		cout << "ERROR! Invalid selection, exiting.";
		//return -1 to main due to input error
		return -1;
	}
	
	//PROMPT AGAIN 
	//6.
	cout << "Please enter another pair of numbers, separated by a" << endl
		 << "space, to represent a second vector or complex number." << endl << endl;
		 
	double num3, num4; //Initialize two variables
	
	cin >> num3 >> num4; //Read user input
	cout << fixed << setprecision(3); //Set decimal precision to fixed 3 
	cout << "You entered " << num3 << " and " << num4 << "." << endl; //Output input values
	
	//3. Ask for Cartesian or Polar
	
	string carPol2; //Initialize input variable
	
	cout << endl << "Are these numbers in Cartesian (C) or polar (p) coordinates?" << endl
		 << "Please enter a single character as your choice." << endl; //Prompt user to choose c or p
		 
	cin >> carPol2; //sets input to variable
	
	//Input Checker
	if (carPol2 == "C" || carPol2 == "c") //Check for Cartesian
	{
		cout << "You entered Cartesian coordinates." << endl;
		double rC2, thetaC2, xC2 = num3, yC2 = num4;
		
		//4. Cartesian to Polar converter
		rC2 = sqrt(pow(xC2, 2) + pow(yC2, 2)); // R = SQRT(X^2 + Y^2)
		
		if (xC2 >= 0)
		{
			thetaC2 = atan(yC2 / xC2);
		}
		else if (xC2 < 0 && yC2 >= 0)
		{
			thetaC2 = atan(yC2 / xC2) + M_PI; 
		}
		else
		{
			thetaC2 = atan(yC2 / xC2) - M_PI;
		}
		cout << fixed << setprecision(3); 
		cout << "The equivalent polar coordinates are:" << endl
			 << "R = " << rC2 << ", theta = " << thetaC2 << endl;
		
		
	}
	else if (carPol2 == "P" || carPol2 == "p") //Check for polar
	{
		cout << "You entered polar coordinates." << endl;
		double xP2, yP2, rP2 = num3, thetaP2 = num4; 
		
		//4. Polar to Cartesian converter
		if (rP2 < 0) //Check if R is non negative
		{
			//Error message
			cout << "ERROR! Invalid selection, exiting.";
			//return -1 to main due to input error
			return -1;
		}
		else if (thetaP2 > M_PI && thetaP2 < (-1*M_PI)) //Check if theta is within range
		{
			//Error message
			cout << "ERROR! Invalid selection, exiting.";
			//return -1 to main due to input error
			return -1;
		}
		else
		{
			xP2 = rP2 * cos(thetaP2); //Calculate x
			yP2 = rP2 * sin(thetaP2); //Calculate y
			
			cout << fixed << setprecision(3); 
			cout << "The equivalent polar coordinates are:" << endl
			 << "x = " << xP2 << ", y = " << yP2 << endl;
		}
	}
	else 
	{
		//Error message
		cout << "ERROR! Invalid selection, exiting.";
		//return -1 to main due to input error
		return -1;
	}
	
	//Return 0 to end Main
	return 0;
}
