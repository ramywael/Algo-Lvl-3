/*

Write a Program to fill two 3x3 matrix with random numbers
And Then Print the middle and middle col
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
			arr[i][j] = GenerateRandomNumber(1, 10);
		}
	}
}

void PrintMiddleRowOfMatrix(int arr[3][3],short rows ,short cols) {
	short middleRow = rows / 2;
	cout << "Middle Row Of Matrix 1 is : \n";
	for (short i = 0;i < cols;i++) {
		printf("%0*d  ", 2, arr[middleRow][i], setw(3));
	}
}

void PrintMiddleColOfMatrix(int arr[3][3], short rows, short cols) {
	short middleCol = cols / 2;
	cout << "\n\nMiddle Col Of Matrix 1 is : \n";
	for (short i = 0;i < rows;i++) {
		printf("%0*d  ", 2, arr[i][middleCol], setw(3));
	}
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
	FillTwoMatrix(arr, 3,3 );
	cout << "Matrix 1 : \n";
	PrintMatrix(arr);
	
	PrintMiddleRowOfMatrix(arr, 3, 3);

	PrintMiddleColOfMatrix(arr, 3, 3);
	system("pause>0");
}