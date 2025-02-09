/*
Write a Program to compare two matrices and check if they are typical or not
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int GenerateRandomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
void FillMatrix(int arr[3][3], int rows, int cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			arr[i][j] = GenerateRandomNumber(1, 10);
		}
	}
}
bool AreEqualOrNot(int arr1[3][3], int arr2[3][3], int rows, int cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr1[i][j] != arr2[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void PrintEqualResult(bool result) {
	if (result)
		cout << "Yes : They Are Equal \n";
	else
		cout << "No : Matrices Are not equal \n";
}
void PrintMatrix(int arr[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%0*d  ", 2, arr[i][j], setw(3));
		}
		cout << "\n\n";
	}
}



int main() {
	srand((unsigned)time(NULL));

	int arr[3][3], arr2[3][3];
	FillMatrix(arr, 3, 3);
	FillMatrix(arr2, 3, 3);

	cout << "Matrix 1 : \n";
	PrintMatrix(arr);


	cout << "Matrix 2 : \n";
	PrintMatrix(arr2);


	PrintEqualResult(AreEqualOrNot(arr, arr2, 3, 3));
	system("pause>0");
}