using namespace std;
#include <iostream>
#include <stdio.h>
#include <process.h>

int matrixA[3][3] = {//First matrix. Each process will only have part of this matrix to work with.
	{ 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 }
};

int matrixB[3][3] = {//Second matrix. Each process will multiply their A fragment with all of this.
	{ 7, 8, 9 },
	{ 4, 5, 6 },
	{ 1, 2, 3 }
};

int matrixC[3][3] = {//Holds the result of the multiplication.
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 }
};

//Need to put these in separate .exe files and call them using a spawn function. 
void multiply1()
{
	matrixC[0][0] = (matrixA[0][0] * matrixB[0][0]) + (matrixA[0][1] * matrixB[1][0]) + (matrixA[0][2] * matrixB[2][0]);
	matrixC[0][1] = (matrixA[0][0] * matrixB[0][1]) + (matrixA[0][1] * matrixB[1][1]) + (matrixA[0][2] * matrixB[2][1]);
	matrixC[0][2] = (matrixA[0][0] * matrixB[0][2]) + (matrixA[0][1] * matrixB[1][2]) + (matrixA[0][2] * matrixB[2][2]);
}

void multiply2()
{
	matrixC[1][0] = (matrixA[1][0] * matrixB[0][0]) + (matrixA[1][1] * matrixB[1][0]) + (matrixA[1][2] * matrixB[2][0]);
	matrixC[1][1] = (matrixA[1][0] * matrixB[0][1]) + (matrixA[1][1] * matrixB[1][1]) + (matrixA[1][2] * matrixB[2][1]);
	matrixC[1][2] = (matrixA[1][0] * matrixB[0][2]) + (matrixA[1][1] * matrixB[1][2]) + (matrixA[1][2] * matrixB[2][2]);
}

void multiply3()
{
	matrixC[2][0] = (matrixA[2][0] * matrixB[0][0]) + (matrixA[2][1] * matrixB[1][0]) + (matrixA[2][2] * matrixB[2][0]);
	matrixC[2][1] = (matrixA[2][0] * matrixB[0][1]) + (matrixA[2][1] * matrixB[1][1]) + (matrixA[2][2] * matrixB[2][1]);
	matrixC[2][2] = (matrixA[2][0] * matrixB[0][2]) + (matrixA[2][1] * matrixB[1][2]) + (matrixA[2][2] * matrixB[2][2]);
}

int main()
{
	//CreateProcess(0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //???

	multiply1();
	multiply2();
	multiply3();

	//
	//
	//Process-using version; open the separate .exe files from here using spawn functions.
	//
	//
	
	//Display result.
	cout << "Result: " << endl <<
		"{ " << matrixC[0][0] << ", " << matrixC[0][1] << ", " << matrixC[0][2] << " }," << endl <<
		"{ " << matrixC[1][0] << ", " << matrixC[1][1] << ", " << matrixC[1][2] << " }," << endl <<
		"{ " << matrixC[2][0] << ", " << matrixC[2][1] << ", " << matrixC[2][2] << " }" << endl << endl;
	//With the current matrices above, expected result is:
	//{	6,	9,	12	},
	//{ 42, 54, 66	},
	//{ 78, 99, 120 }

	system("PAUSE");
};