/*

Write a Program to fill two 3x3 matrix with random numbers
And Then sum all numbers in the matrix
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int GenerateRandomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
void FillTwoMatrix(int arr[3][3], int rows, int cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			arr[i][j] = GenerateRandomNumber(1, 100);
		}
	}
}
int SumMatrix(int arr[3][3], int rows, int cols) {
	int sum = 0;
	for (int i = 0;i < rows;i++) {
		for (int j = 0; j < cols;j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

void PrintSumResult(int sum) {
	cout << "Sum of matrix1 is :" << sum << "\n";
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

	int arr[3][3];
	FillTwoMatrix(arr, 3, 3);
	cout << "Matrix 1 : \n";
	PrintMatrix(arr);
	PrintSumResult(SumMatrix(arr,3,3));
	system("pause>0");
}