// Algo-Lvl-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Write a Program to fill a 3x3 matrix with random numbers and sum each row 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int GenerateRandomNumber(int To, int From) {
	int randNumber = rand() % (To - From + 1) + From;
	return randNumber;

}

void FillTwoDiminsionalAraay(int arr[3][3]) {

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			arr[i][j] = GenerateRandomNumber(100, 1);
		}
	}

}
void PrintAllElementsOfArray(int arr[3][3]) {
	cout << "The Following is 3x3 random matrix \n";
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cout <<setw(3)<< arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

int SumRow(int arr[3][3],short rows,short cols) {
	int sum = 0;
	for (int j = 0;j < cols;j++) {
		sum += arr[rows][j];
	}
	return sum;
}

void SumOfMatrix(int arr[3][3],int rows, int cols) {
	cout << "\nThis is the following sum of each Row in the matrix \n";
	for (int i = 0;i < rows;i++) {
		cout<<setw(3) << "Row  " << (i + 1) << " Sum = " << SumRow(arr,i,3) << "\n";
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3];
	FillTwoDiminsionalAraay(matrix);
	PrintAllElementsOfArray(matrix);
	SumOfMatrix(matrix,3,3);
}
