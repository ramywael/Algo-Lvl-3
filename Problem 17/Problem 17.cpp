/*
Write a Program to check if a given number exists in matrix or not
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

short ReadPostiveNumber(string message) {
	short number;
	do {
		cout << message;
		cin >> number;
	} while (number < 0);
	return number;
}

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
	short count = 0;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] == number) {
				return true;
			}
		}
	}
	return false;
}
void FillMatrix(int arr[3][3], int rows, int cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			arr[i][j] = GenerateRandomNumber(1, 100);
		}
	}
}

void PrintExistsResult(bool result) {
	if (result)
		cout << "Yes it is there \n";
	else
		cout << "No, it isnot there \n";
}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];

	cout << "Matrix 1 : \n";
	FillMatrix(arr,3,3);
	PrintMatrix(arr);

	short number = ReadPostiveNumber("Please Enter The Number To look in the matrix ? : ");

	PrintExistsResult(IsGivenNumberExists(arr,number,3,3));
	system("pause>0");
}