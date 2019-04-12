#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    Problem - write a program that multiplies two matrices and prints the
    resulting matrice
    Input - file called CS1Asg2Data.txt. The file will be in the form of two
    numbers, number of rows and columns, followed by matrix of m rows and n columns.
    All numbers seperated by space.
	Conditions - number of rows in matrix1 must be equal to number of columns in matrix 2 for multiplication
    Author - Aashish Sharma
    netID - axs170083
    Class - CS 1337.009
    Date Started - 2/11/19
*/

void printMatrix(int** mat, int rows, int columns) // print matrix 
{
	int** matrix = mat;
	for (int i = 0; i < rows; i++)
	{
		cout << "\t";
		for (int x = 0; x < columns; x++)
		{
			cout << matrix[i][x] << "\t";
		}
		cout << endl;
	}
}

bool matrixcheck(int rows1, int columns2) // determines if numbers of rows in the same as the number of columns in the other
{
	if (rows1 != columns2)
	{
		return false; // return false if columns not equal to rows
	}
	return true; // return true
}

void multiplication(int rows1, int columns1, int rows2, int columns2, int** matrix1, int** matrix2) // compute matrix multiplication
{
	int** matrix3 = new int*[rows1];
		for (int i = 0; i < rows2; i++) // loop to create 2d matrix thats dynamic
		{
			matrix3[i] = new int[columns2];
		}

		for (int i = 0; i < rows1; i++) // loop to initialize matrix
		{
			for (int j = 0; j < columns2; j++)
			{
				matrix3[i][j] = 0;
			}
		}
		for (int i = 0; i < rows1; i++) // loop for matrix multiplication
		{
			for (int j = 0; j < columns2; j++)
			{
				for (int x = 0; x < columns2; x++)
				{
					matrix3[i][j] += (matrix1[i][x] * matrix2[x][j]);
				}
			}
		}
		cout << "Multiplied Matrix" << endl;
		printMatrix(matrix3, rows1, columns2); // print the multiplied matrix	
}

void readFile(string Filename) // read input from file and constructs matrices
{
    ifstream inputFile;
    int rows1, rows2 = 0;
    int columns1, columns2 = 0;
    inputFile.open(Filename); // open files
    if(inputFile) // if file is opened successfully
    {
        inputFile >> rows1 >> columns1;
		int** matrix1;
		matrix1 = new int*[rows1];
		for (int i = 0; i < rows1; i++) // loop to create 2d matrix1 thats dynamic
		{
			matrix1[i] = new int[columns1];
		}

        for(int i = 0; i < rows1; i++) // input values into matrix1
        {
           for(int x = 0; x < columns1; x++)
            {
				inputFile >> matrix1[i][x];
            }
        }
		cout << "Matrix 1" << endl;
		printMatrix(matrix1, rows1, columns1); // call print function to print the first input matrix

		inputFile >> rows2 >> columns2;
		int** matrix2;
		matrix2 = new int*[rows2];
		for (int i = 0; i < rows2; i++) // loop to create 2d matrix2 thats dynamic
		{
			matrix2[i] = new int[columns2];
		}
			 
		for (int i = 0; i < rows2; i++) // input stuff into matrix2
		{
			for (int x = 0; x < columns2; x++) 
			{
				inputFile >> matrix2[i][x];
			}
		}
		cout << "Matrix 2" << endl;
		printMatrix(matrix2, rows2, columns2); // call print function to print the second input matrix

		if(matrixcheck(rows1, columns2)) // check if matrix has same rows and columns
		{
			multiplication(rows1, columns1, rows2, columns2, matrix1, matrix2); // if matrixes are valid compute the multiplication
		} 
		else // matrixes not valid
		{
			cout << "Number of Rows in first matrix is not equal to number of columns in second matrix" << endl; // inform user of error
		}
			
    }
    inputFile.close(); // closes input file
    //cout << rows << " " << columns << endl;
}

int main()
{
    string Filename = "CS1Asg2Data.txt"; // name of file
    readFile(Filename); // reads from file
}