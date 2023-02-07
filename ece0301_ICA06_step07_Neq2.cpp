// Amit Nafshi
// ECE 0301
// ICA 06

// Preprocessor functions
#include <iostream>
#include <cmath> 
#include <fstream>
#include <string>
#include <iomanip>

// Set up namespace
using namespace std;

// Declare constant DIM
const int DIM = 2;

// Declare Functions
int readN(ifstream &, double[][DIM], double[]);
void fileWrite(ofstream &, int, double[][DIM], double[DIM]);

//Main function					
int main()
{ 
	int N;
	double A[DIM][DIM], B[DIM];
	
	// Define ifstream and read file 
	ifstream axbRead("ECE0301_ICA06_Axeqb_problem.txt");
	
	// Define ofstream and open file
	ofstream axeqb("ECE0301_ICA06_Axeqb_solution.txt");
	
	// Initialize 2D and 1D array
	// Call read N function
	N = readN(axbRead, A, B);
	fileWrite(axeqb, N, A, B);
	
	// Close ofstream
	axeqb.close();
	
	// Close ifstream
	axbRead.close();

	// Return 0 to main to end function
	return 0;
}

// Function to read N from file
// Function to read N from file
int readN(ifstream &axbRead, double A[][DIM], double B[])
{
	int N;
	string inLine, nRead, fillA, fillB;
	const string check1 = "ECE 0301: Ax = b Problem", check2 = "N = ", check3 = "A = ", check4 = "b = ";
	
	// Getline from file
	getline(axbRead, inLine);
	getline(axbRead, nRead);

	// Error check line 1
	if (inLine != check1)
	{
		cout << "ERROR! Input file format error.";
		return -1;
	}

	// Error check line 2
	if (nRead.find(check2) != 0)
	{
		cout << "ERROR! Input file format error.";
		return -1;
	}
	
	// Format string to int to return to function
	nRead = nRead.substr(4, nRead.find('\n'));
	N = stoi(nRead);
	
	// Error check value of N
	if (N != DIM)
	{
		cout << "ERROR! Dimension mismatch, N != DIM.";
		return -1;
	}
	
	//  Error check line 3
	getline(axbRead, fillA);
	
	if (fillA.find(check3) != 0)
	{
		cout << "ERROR! Input file format error.";
		return -1;
	}
		
	// Fill array A
	for(int i=0;i<DIM;i++)
	{
		for(int j=0;j<DIM;j++)
		{
			getline(axbRead, fillA);
			A[i][j] = stod(fillA);
		}
	}

	// Error check line 4
	getline(axbRead, fillB);
	
	if (fillB.find(check4) != 0)
	{
		cout << "ERROR! Input file format error.";
		return -1;
	}
	
	// Fill array B
	for(int z=0;z<DIM;z++)
	{
		getline(axbRead, fillB);
		B[z] = stod(fillB);
	}

	// Return N to main
	return N;
}

// Function to write to sol'n file
void fileWrite(ofstream &axeqb, int N, double A[DIM][DIM], double B[DIM])
{

	// Output header
    axeqb << "ECE 0301 - Matrix-Vector Computations,\n";
    axeqb << "Determinants and Cramer's Rule.\n";
    axeqb << "Global array dimension: DIM = " << DIM;

	// Output N value
    axeqb << "\nInput file: N = " << N;

	// output A matrix with proper formatting
    axeqb << "\n\nA = \n";
    for (int i=0;i<DIM;i++)
    {
        axeqb << "[ ";
        for (int j=0;j<DIM;j++)
        {
            axeqb << setw(10) << A[i][j];
        }
        axeqb << " ]\n";
    }

	// output b matrix with proper formatting
    axeqb << "\nb = \n";
    for (int r=0;r<DIM;r++)
    {
        axeqb << "[ " << setw(10) << B[r] << " ]\n";
    }
}
