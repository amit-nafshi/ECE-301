// Amit Nafshi
// ECE 301
// Assignment 2


//Set up IO stream and other preprocessor functions
#include <iostream>
#include <cmath>
#include <string>

//Set up namespace
using namespace std;

//Main Function
int main()
{
	//1. Intro string
	cout << "ECE 0301 Propositional Logic Example" << endl;
	
	//2. Declare three T/F string variables
	string p1 = "P1: Pigs can fly.", p2 = "P2: Earth is flat.", p3 = "P3: The Moon is cheese.";
	
	//Display string
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	
	//3. Declare bool variables
	bool boo1, boo2, boo3;
	
	//Ask user for input	
	cout << "\nEnter P1 truth value: ";
	cin >> boo1;
	cout << "Enter P2 truth value: ";
	cin >> boo2;
	cout << "Enter P3 truth value: ";
	cin >> boo3; 
	
	//4. Display results 
	cout << "\nYou entered: P1 = " << boolalpha << boo1 << ", P2 = " << boolalpha << boo2 << ", P3 = " << boolalpha << boo3 << "." << endl;
	
	//5. Make truth table and P4 statement
	// "Pigs can fly, Earth is not flat, and the moon is cheese." <----- AND statement
	bool boo4;
	
	if (boo1 == true && boo2 == false && boo3 == true)
	{
		boo4 = true;
	}
	else
	{
		boo4 = false;
	}
	
 
	//6. Set up P5 
	
	bool boo5;
	// Pigs cannot fly, or Earth is flat, or the moon is cheese. <----- OR statement
	
	if (boo1 == false || boo2 == true || boo3 == true)
	{
		boo5 = true;
	}
	else
	{
		boo5 = false;
	}
	
	//Truth Table
	cout << "\nTruth Table:" << endl;
	cout << "Proposition\tTruth Value" << endl;
	cout << "-----------\t-----------" << endl;
	cout << "P1         \t" << boolalpha << boo1 << endl;
	cout << "P2         \t" << boolalpha << boo2 << endl;
	cout << "P3         \t" << boolalpha << boo3 << endl;
	cout << "P4         \t" << boolalpha << boo4 << endl;
	cout << "P5         \t" << boolalpha << boo5 << endl;
	
	
	//Return 0 to complete function
	return 0;
}
