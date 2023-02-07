// Amit Nafshi
// ECE 0301
// ICA 06

// Preprocessor functions
#include <iostream>
#include <cmath> 
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

// Set up namespace
using namespace std;

// Declare constant DIM
const int DIM = 2;

// Declare Functions
int readN(ifstream &, double[][DIM], double[]);
void fileWrite(ofstream &, int, double[][DIM], double[], vector<double> &);
void fileWrite(ofstream &, int, double[][DIM]); // Overload
void matMult(double[][DIM], vector<double> &, vector<double> &);
void matCopy(double[][DIM], double[][DIM], int, int, int);
double det(double[][DIM], int);


//Main function					
int main()
{ 
	// Define ifstream and read file 
	ifstream axbRead("ECE0301_ICA06_Axeqb_problem.txt");
	
	// Define ofstream and open file
	ofstream axeqb("ECE0301_ICA06_Axeqb_solution.txt");
	
	// Declare N, and A and b
	int N;
	double A[DIM][DIM], B[DIM];
	
	// Read N
	N = nRead(axbRead, A, B);
	
	// Declare vector x and Ax, and num
	double num;
	vector<double> x;
	vector<double> Ax;
	
	// Send A and N to fileWrite
	fileWrite(axeqb, N, A);
		
	// Close ifstream
	axbRead.close();
	
	// Close ofstream
	axeqb.close();

	// Return 0 to main to end function
	return 0;
}

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
	int eqPos = nRead.find("=");
	string NStr = nRead.substr(eqPos + 1);
	N = stoi(NStr);
	
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
			axbRead >> A[i][j];
		}
	}

	// Error check line 4
	getline(axbRead, fillB);
	
	if (fillA.find(check4) != 0)
	{
		cout << "ERROR! Input file format error.";
		return -1;
	}
	
	// Fill array B
	for(int z=0;z<DIM;z++)
	{
		axbRead >> B[z];
	}

	// Return N to main
	return N;
}

// Matrix-vector multiplication function
void matMult(double A[][DIM], vector<double> &x, vector<double> &Ax)
{
	double sum;
	
	// Nested for loop to look through A and x
	 for (int i = 0; i < DIM; i++)
     {
        sum = 0;
        for (int j = 0; j < DIM; j++)
        {
            // Sums the products of columns A and rows x
            sum += A[i][j] * x[j];
        }
        Ax.push_back(sum);
        cout << Ax[i] << endl;
    }
	
}

// Function to write to sol'n file
void fileWrite(ofstream &axeqb, int N, double A[][DIM], double B[], vector<double> &x)
{
	// Output N value
    axeqb << "\nInput file: N = " << N << endl << endl;
	
	 // Print A to file 
    axeqb << "A =\n";
    for (int i=0;i<DIM;i++)
    {
        axeqb << "[ ";
        for (int j=0;j<DIM;j++)
        {
            axeqb << setw(10) << A[i][j];
        }
        axeqb << " ]\n";
    }

    // Print b array to file
    axeqb << "\nb = \n";
    for (int i = 0; i < DIM; i++)
    {
        axeqb << "[ " << setw(10) << B[i] << " ]\n";
    }

    // Declare vector Ax
    vector<double> Ax;
    
    // Call matMult function
    matMult(A, x, Ax);

    // Print out values for A, b, x, and Ax
    axeqb << endl << "A * x = b" << endl;

    for (int p=0;p<DIM;p++)
    {
        axeqb << "[ ";
        for (int k=0;k<DIM;k++)
        {
            axeqb << setw(10) << A[p][k];
        }
        if (p == (DIM/2) - 1 && (DIM%2 == 0))
        {
            axeqb << " ] * [ " << setw(10) << x[p] << " ] = [ " << setw(10) << Ax[p] << " ]" << endl;
        }
        else if (p == (DIM/2) && DIM%2 != 0)
        {
            axeqb << " ] * [ " << setw(10) << x[p] << " ] = [ " << setw(10) << Ax[p] << " ]" << endl;
        }
        else
        {
            axeqb << " ]   [ " << setw(10) << x[p] << " ]   [ " << setw(10) << Ax[p] << " ]" << endl;
        }
    }
}

void fileWrite(ofstream &axeqb, int n, double A[][DIM])
{
	// Printing out n x n matrix
    for (int i=0;i<n;i++)
    {
        axeqb << "[ ";
        for (int j=0;j<n;j++)
        {
            axeqb << setw(10) << A[i][j];
        }
        axeqb << " ]\n";
    }
}

// Array copier fuction
void matCopy(double[][DIM], double[][DIM], int, int, int)
{
	int X = 0, Y = 0;

    for (int x=0;x<n+1;x++)
    {
        // skips the entire row
        if (x == i)
        {
            continue;
        }
        Y = 0;
        for (int y=0;y<n+1;y++)
        {
            // skips the column
            if (y != j)
            {
                A_new[X][Y] = A[x][y];
                Y++;
            }
        }
        X++;
    }
}

// Recursive function that returns determinant of a square matrix
double det(double A[][DIM], int n)
{

    // Initalize determinant
    double det = 0;

    // Check if 1x1
    if (n == 1)
    {
        det = A[0][0];
    }

    // Check if 2x2
    if (n == 2)
    {
        det = (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
    }

    else
    {
        // Initializing sub matrix
        double subA[DIM][DIM];

        for (int j=0;j<n;j++)
        {
            matCopy(A, subA, 0, j, n);
            det += A[0][j]*(det(subA, n - 1) * pow(-1, j));
        }
    }

    return det;
}
