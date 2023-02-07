// Amit Nafshi
// In Class #1
// ECE 301 

//Prepping the program 
#include <iostream> 
#include <string>
using namespace std;

//Main Function
int main()
{
	//Step 1: Display introductory message
	cout << "ECE 0301 DC Resistive Circuit Simulation\n" 
	<< "Modeled after www.falstad.com/circuit/\n" 
	<< "Circuits -> Basics -> Ohm's Law\n";
	
	
	//Step 2: Declare Variables
	double Vs = 5.0, R1 = 100.0, R2 = 1000.0;
	
	//Display Vs
	cout << "Vs = " << Vs << " Volts\n";
	
	//Display R1 and R2
	cout << "R1 = " << R1 << " Ohms\n";
	cout << "R2 = " << R2 << " Ohms\n";
	
	
	//Step 3: Display Current and Power through each Resistor
	
	//initialize current and power variables
	double I1 = Vs / R1, I2 = Vs / R2, P1 = Vs * I1, P2 = Vs * I2;
	
	
	cout << "I1 = " << I1 << " Amperes\n";
	cout << "P1 = " << P1 << " Watts\n";
	cout << "I2 = " << I2 << " Amperes\n";
	cout << "P2 = " << P2 << " Watts\n";
	
	
	//Step 4: Total Energy Supplied
	double powTot = P1 + P2, e1 = powTot, e2 = powTot * 3600, e3 = powTot * 86400, e4 = powTot * 31536000; 
	
	
	cout << "Energy supplied in one second = " << e1 << " Joules\n";
	cout << "Energy supplied in one hour = " << e2 << " Joules\n"; 
	cout << "Energy supplied in one day = " << e3 << " Joules\n"; 
	cout << "Energy supplied in one year = " << e4 << " Joules\n";
	
	
	//Step 5: Calculating costs per kWh
	
	//Setting constant variable eCost to electricity cost
	const double eCost = 0.1;
	
	//Convert Energy in Joules to kWh
	double cost1 = (e1 / (3600 * 1000)) * eCost, cost2 = (e2 / (3600 * 1000)) * eCost, 
	cost3 = (e3 / (3600 * 1000)) * eCost, cost4 = (e4 / (3600 * 1000)) * eCost;
	
	//Display Costs
	cout << "Cost of supplying energy for one second at $0.10/kWh = $" << cost1 << "\n";
	cout << "Cost of supplying energy for one hour at $0.10/kWh = $" << cost2 << "\n";
	cout << "Cost of supplying energy for one day at $0.10/kWh = $" << cost3 << "\n";
	cout << "Cost of supplying energy for one year at $0.10/kWh = $" << cost4 << "\n";
	
	
	//Return 0 to complete and return main b/c it is an int
	return 0;
}
