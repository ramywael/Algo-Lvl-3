// Algo-Lvl-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Write a Program to fill a 3x3 matrix with random numbers

#include <iostream>
using namespace std;

int GenerateRandomNumber(int To,int From) {
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
			cout << arr[i][j]<<"\t";
		}
		cout << "\n";
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3];
	FillTwoDiminsionalAraay(matrix);
	PrintAllElementsOfArray(matrix);
}
