/*
Write a Program to check if the matrix is identity or not
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
bool CheckScaler(int arr[3][3],int rows,int cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (i == j && arr[i][j] != 1) {
				return false;
			}
			if (i != j && arr[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	srand((unsigned)time(NULL));

	int arr[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

	cout << "Matrix 1 : \n";
	PrintMatrix(arr);


	if (CheckScaler(arr, 3, 3))
		cout << "YES : Matrix is Scaler \n";
	else
		cout << "No : Matrix is not Scaler \n";

	system("pause>0");
}