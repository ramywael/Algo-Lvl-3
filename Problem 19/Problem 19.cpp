/*
Write a Program to pritn the Minimum and maximum numbers in Matrix
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

void FillMatrix(int arr[3][3], int rows, int cols) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			arr[i][j] = GenerateRandomNumber(1, 100);
		}
	}
}


short DetermineMax(int arr[3][3],int rows,int cols) {
	short max=arr[0][0];
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	return max;
}

short DetermineMin(int arr[3][3], int rows, int cols) {
	short min=arr[0][0];
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (min > arr[i][j]) {
				min = arr[i][j];
			}
		}
	}
	return min;
}

void PrintMinAndMax(short min,short max) {
	cout << setw(3) << "Min Number is : " << min << "\n\n";
	cout << setw(3) << "Max Number is : " << max << "\n";
}



int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];

	cout << "Matrix 1 : \n";
	FillMatrix(arr, 3, 3);
	PrintMatrix(arr);


	PrintMinAndMax(DetermineMin(arr, 3, 3),DetermineMax(arr,3,3));


	system("pause>0");
}