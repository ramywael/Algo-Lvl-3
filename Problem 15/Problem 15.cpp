/*
Write a Program to count give number
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

short ReadPostiveNumber(string message) {
	short number;
	do {
		cout << message << "\n";
		cin >> number;
	} while (number < 0);
	return number;
}
void PrintMatrix(int arr[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%0*d  ", 2, arr[i][j], setw(3));
		}
		cout << "\n\n";
	}
}
short CountNumber(int arr[3][3], short number, short rows, short cols) {
	short count = 0;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] == number) {
				count++;
			}
		}
	}
	return count;
}

void PrintCountResult(short number, short result) {
	cout << "Number " << number << " count in matrix is " << result << "\n";
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

	cout << "Matrix 1 : \n";
	PrintMatrix(arr);

	short number = ReadPostiveNumber("Enter The Number to count in the matrix ? : ");

	PrintCountResult(number, CountNumber(arr, number, 3, 3));
	system("pause>0");
}