/*
Write a Program to check if the matrix is sparce or not
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void PrintMatrix(int arr[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%0*d  ", 2, arr[i][j], setw(3));
		}
		cout << "\n\n";
	}
}
short CountNumberInMatrix(int arr[3][3],short number, short rows, short cols) {
	short countofZero = 0;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] == number) {
				countofZero++;
			}
			
		}
	}
	return countofZero;
}

bool IsSparceMatrix(int arr[3][3], short rows, short cols) {
	short matrixSize = rows * cols;

		return(CountNumberInMatrix(arr, 0, 3, 3) > (matrixSize / 2));
}



int main() {
	srand((unsigned)time(NULL));

	int arr[3][3] = { {0,0,12},{0,0,1},{0,0,9} };
	//int arr[3][3] = { {10,0,12},{20,15,1},{0,0,9} };

	cout << "Matrix 1 : \n";
	PrintMatrix(arr);

	if (IsSparceMatrix(arr, 3, 3))
		cout << "Yes , It is sparce \n";
	else
		cout << "No : it is not sparce \n";


	system("pause>0");
}