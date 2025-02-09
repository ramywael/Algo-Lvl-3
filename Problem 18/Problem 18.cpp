/*
Write a Program to pritn the intersected numbers in two matrices
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int GenerateRandomNumber(int From, int To) {
	int randNumber = rand() % (To - From + 1) + From;
	return randNumber;

}
void PrintMatrix(int arr[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%0*d  ", 2, arr[i][j], setw(3));
		}
		cout << "\n\n";
	}
}
bool IsGivenNumberExists(int arr[3][3], short number, short rows, short cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] == number) {
				return true;
			}
		}
	}
	return false;
}
void ItrateInSecondMatrix(int arr1[3][3], int arr2[3][3], int rows, int cols) {
	int number;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			number = arr1[i][j];
			if (IsGivenNumberExists(arr2, number, 3, 3))
				cout << setw(3) << number << " ";
		}
	}
}
void FillMatrix(int arr[3][3], int rows, int cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			arr[i][j] = GenerateRandomNumber(1, 100);
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];
	int arr2[3][3];

	cout << "Matrix 1 : \n";
	FillMatrix(arr, 3, 3);
	PrintMatrix(arr);


	cout << "Matrix 2 : \n";
	FillMatrix(arr2, 3, 3);
	PrintMatrix(arr2);

	cout << "The Intersected Numbers are : \n";
	ItrateInSecondMatrix(arr,arr2,3,3);

	system("pause>0");
}