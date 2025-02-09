// Algo-Lvl-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

Write a Program to fill a 3x3 matrix with ordered numbers
And Then Print the transpose matrix

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;




void FillTwoDiminsionalArray(int arr[3][3]) {
	short counter = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			counter++;
			arr[i][j] = counter;
		}
	}

}
void FillTwoDiminsionalArrayTranspose(int arr[3][3],int arrTranspose[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			arrTranspose[i][j] = arr[j][i];
		}
	}
}


	void PrintAllElementsOfArray(int arr[3][3]) {
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				cout << setw(3) << arr[i][j] << "\t";
			}
			cout << "\n";
		}
	}

int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3];
	int transposeMatrix[3][3];

	cout << "The Following is 3x3 ordered matrix \n";

	FillTwoDiminsionalArray(matrix);
	PrintAllElementsOfArray(matrix);
	cout << "\n\nThe Following is 3x3 Transpose matrix \n";

	FillTwoDiminsionalArrayTranspose(matrix,transposeMatrix);
	PrintAllElementsOfArray(transposeMatrix);
	system("pause>0");
}
