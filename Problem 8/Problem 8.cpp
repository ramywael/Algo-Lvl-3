/*

Write a Program to fill two 3x3 matrix with random numbers
And Then Multiply them into 3rd matrix and print it

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int GenerateRandomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
 }
void FillTwoMatrix(int arr[3][3],int arr2[3][3],int rows,int cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			arr[i][j] = GenerateRandomNumber(1, 10);
			arr2[i][j] = GenerateRandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%0*d  ", 2, arr[i][j],setw(3));
		}
		cout << "\n\n";
	}
}

void MultiplyTwoMatrix(int arr[3][3],int arr2[3][3],int resArr[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			resArr[i][j] = arr[i][j] * arr2[i][j];
		}
	}
}
int main() {
	srand((unsigned)time(NULL));

	int arr[3][3], arr2[3][3], resArr[3][3];
	FillTwoMatrix(arr,arr2,3,3);
	cout << "Matrix 1 : \n";
	PrintMatrix(arr);

	cout << "Matrix 2 : \n";
	PrintMatrix(arr2);

	MultiplyTwoMatrix(arr,arr2,resArr);
	cout << "Result : \n";
	PrintMatrix(resArr);
	system("pause>0");
}