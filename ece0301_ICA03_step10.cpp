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
	double rC, thetaC, xC = num1, yC = num2;
	double xP, yP, rP = num1, thetaP = num2;
	
	if (carPol == "C" || carPol == "c") //Check for Cartesian
	{
		cout << "You entered Cartesian coordinates." << endl;
		
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
	
//---------------------------------------------------------------------------------------------------
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
	
	
	double rC2, thetaC2, xC2 = num3, yC2 = num4;
	double xP2, yP2, rP2 = num3, thetaP2 = num4;
	//Input Checker
	if (carPol2 == "C" || carPol2 == "c") //Check for Cartesian
	{
		cout << "You entered Cartesian coordinates." << endl;
		
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
	
//---------------------------------------------------------------------------------------------------
	
	//7. 
	cout << endl << "Do the values you entered represent vectors (v) or complex numbers (c)?" << endl
	     << "Please enter a single character as your choice." << endl;
	
	string comVec;
	cin >> comVec; //Initialize and set input value
	
	//ERROR CHECK
	if (comVec == "V" || comVec == "v")
	{
		double v1, v2, v3, v4, v5, v6, v7, v8;
		
		if (carPol == "C" || carPol == "c") //Check for Cartesian
		{
			v1 = xC, v2 = yC, v3 = rC, v4 = thetaC;
			
			cout << fixed << setprecision(3);
			cout << endl << "Cartesian:       v1 = (" << v1 << ", " << v2 << ")" //Print results
			     << endl << "Polar:           v1 = (" << v3 << ", " << v4 << ")" << endl << endl;
		}
		else
		{
			v1 = xP, v2 = yP, v3 = rP, v4 = thetaP;
			
			cout << fixed << setprecision(3);
			cout << endl << "Cartesian:       v1 = (" << v1 << ", " << v2 << ")" //Print results
			     << endl << "Polar:           v1 = (" << v3 << ", " << v4 << ")" << endl << endl;
		}
		
		if (carPol2 == "C" || carPol2 == "c")
		{
			v5 = xC2, v6 = yC2, v7 = rC2, v8 = thetaC2;
			
			cout << fixed << setprecision(3);
			cout << "Cartesian:       v2 = (" << v5 << ", " << v6 << ")" << endl // Print results
				 << "Polar:           v2 = (" << v7 << ", " << v8 << endl << endl;
		}
		else
		{
			v5 = xP2, v6 = yP2, v7 = rP2, v8 = thetaP2;
			
			cout << fixed << setprecision(3);
			cout << "Cartesian:       v2 = (" << v5 << ", " << v6 << ")" << endl // Print results
				 << "Polar:           v2 = (" << v7 << ", " << v8 << ")" << endl << endl;
		}
		
		
		//9. sums and differences
		cout << "Which of the following vector sums or differences\nwould you like to compute?" << endl
			 << "(1) v1 + v2" << endl
			 << "(2) v1 - v2" << endl
			 << "(3) v2 - v1" << endl
			 << "(4) -v1 - v2" << endl << endl;
		
		
		//Set up switch case
		int sumIn1;
		cin >> sumIn1; 
		
		switch (sumIn1)
		{
			case 1:
				cout << fixed << setprecision(3);
				cout << "Sum, Cartesian: v_sum = (" << v1 + v5 << ", " << v2 + v6 << ")" << endl
				     << "Sum, Cartesian: v_sum = (" << v3 + v7 << ", " << v4 + v8 << ")";
				break;
				
			case 2:
				cout << fixed << setprecision(3);
				cout << "Sum, Cartesian: v_sum = (" << v1 - v5 << ", " << v2 - v6 << ")" << endl
				     << "Sum, Cartesian: v_sum = (" << v3 - v7 << ", " << v4 - v8 << ")";
				break;
				
			case 3:
				cout << fixed << setprecision(3);
				cout << "Sum, Cartesian: v_sum = (" << v5 - v1 << ", " << v6 - v2 << ")" << endl
				     << "Sum, Cartesian: v_sum = (" << v7 - v3 << ", " << v8 - v4 << ")";
				break;
				
			case 4:
				cout << fixed << setprecision(3);
				cout << "Sum, Cartesian: v_sum = (" << -v1 - v5 << ", " << -v2 - v6 << ")" << endl
				     << "Sum, Cartesian: v_sum = (" << -v3 - v7 << ", " << -v4 - v8 << ")";
				break;
				
			default:
				cout << "ERROR! Invalid selection, exiting."; //If user doesnt select a # 1-4 the code will be returned -1
				return -1;
		}
		
					 	
	}
	else if (comVec == "C" || comVec == "c")
	{
		double v1, v2, v3, v4, v5, v6, v7, v8;
		
		if (carPol == "C" || carPol == "c") //Check for Cartesian
		{
			v1 = xC, v2 = yC, v3 = rC, v4 = thetaC;
			
			if (v2 > 0)
			{
				cout << fixed << setprecision(3);
				cout << endl << "Cartesian:       z1 = " << v1 << " + j " << v2 // Print results
					 << endl << "Polar:           z1 = " << v3 << " exp(j " << v4 << ")" << endl << endl;
		    }
		    else
		    {
				cout << fixed << setprecision(3);
				cout << endl << "Cartesian:       z1 = " << v1 << " - j " << -v2 // Print results
					 << endl << "Polar:           z1 = " << v3 << " exp(j " << v4 << ")" << endl << endl;
			}
		}
		else
		{
			v1 = xP, v2 = yP, v3 = rP, v4 = thetaP;
			
			if (v2 > 0)
			{
				cout << fixed << setprecision(3);
				cout << endl << "Cartesian:       z1 = " << v1 << " + j " << v2 // Print results
					 << endl << "Polar:           z1 = " << v3 << " exp(j " << v4 << ")" << endl << endl;
			}
			else
			{
				cout << fixed << setprecision(3);
				cout << endl << "Cartesian:       z1 = " << v1 << " - j " << -v2 // Print results
					 << endl << "Polar:           z1 = " << v3 << " exp(j " << v4 << ")" << endl << endl;
			}
		}
		
		if (carPol2 == "C" || carPol2 == "c")
		{
			v5 = xC2, v6 = yC2, v7 = rC2, v8 = thetaC2;
			
			if (v6 > 0)
			{
				cout << fixed << setprecision(3);
				cout << "Cartesian:       z2 = " << v5 << " + j " << v6 << endl // Print results
					 << "Polar:           z2 = " << v7 << " exp(j " << v8 << ")" << endl << endl;
			}
			else
			{
				cout << fixed << setprecision(3);
				cout << "Cartesian:       z2 = " << v5 << " - j " << -v6 << endl // Print results
					 << "Polar:           z2 = " << v7 << " exp(j " << v8 << ")" << endl << endl;
			}
		}
		else
		{
			v5 = xP2, v6 = yP2, v7 = rP2, v8 = thetaP2;
			
			if (v6 > 0)
			{
				cout << fixed << setprecision(3);
				cout << "Cartesian:       z2 = " << v5 << " + j " << v6 << endl // Print results
					 << "Polar:           z2 = " << v7 << " exp(j " << v8 << ")" << endl << endl;
			}
			else
			{
				cout << fixed << setprecision(3);
				cout << "Cartesian:       z2 = " << v5 << " - j " << -v6 << endl // Print results
					 << "Polar:           z2 = " << v7 << " exp(j " << v8 << ")" << endl << endl;
			}
		}	
		
		//9. sums and differences
		cout << "Which of the following sums or differences\nwould you like to compute?" << endl
			 << "(1) v1 + v2" << endl
			 << "(2) v1 - v2" << endl
			 << "(3) v2 - v1" << endl
			 << "(4) -v1 - v2" << endl << endl;
		
		
		//Set up switch case
		int sumIn1;
		cin >> sumIn1; 
		
		switch (sumIn1)
		{
			case 1:
				cout << fixed << setprecision(3);
				cout << "Sum, Cartesian:	 z_sum = " << v1 + v5 << " + j " << v2 + v6 << endl;
				cout << "Sum, Polar:  z_sum = " << sqrt(pow(v1 + v5, 2) + pow(v2 + v6, 2)) << " exp(j " << atan2((v2 + v6), (v1 + v5)) << ")";
				break;
				
			case 2:
				cout << fixed << setprecision(3);
				cout << "Sum, Cartesian:	 z_sum = " << v1 - v5 << " + j " << v2 - v6 << endl;
				cout << "Sum, Polar:  z_sum = " << sqrt(pow(v1 - v5, 2) + pow(v2 - v6, 2)) << " exp(j " << atan2((v2 - v6), (v1 - v5)) << ")";
				break;
				
			case 3:
				cout << fixed << setprecision(3);
				cout << "Sum, Cartesian:	 z_sum = " << -v1 + v5 << " + j " << -v2 + v6 << endl;
				cout << "Sum, Polar:  z_sum = " << sqrt(pow(-v1 + v5, 2) + pow(-v2 + v6, 2)) << " exp(j " << atan2((-v2 + v6), (-v1 + v5)) << ")";
				break;
				
			case 4:
				cout << fixed << setprecision(3);
				cout << "Sum, Cartesian: z_sum = " << -v1 - v5 << " + j " << -v2 - v6 << endl;
				cout << "Sum, Polar:  z_sum = " << sqrt(pow(-v1 - v5, 2) + pow(-v2 - v6, 2)) << " exp(j " << atan2((-v2 - v6), (-v1 - v5)) << ")";
				break;
				
			default:
				cout << "ERROR! Invalid selection, exiting."; //If user doesnt select a # 1-4 the code will be returned -1
				return -1;
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

