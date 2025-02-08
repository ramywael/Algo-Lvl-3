

/*

Write a Program to fill a 3x3 matrix with random numbers and sum each Col

*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int GenerateRandomNumber(int From, int To) {
	int randNumber = rand() % (To - From + 1) + From;
	return randNumber;

}

void FillTwoDiminsionalAraay(int arr[3][3]) {

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			arr[i][j] = GenerateRandomNumber(1, 100);
		}
	}

}
void PrintAllElementsOfArray(int arr[3][3]) {
	cout << "The Following is 3x3 random matrix \n";
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cout << setw(3) << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

int SumCol(int arr[3][3], short rows, short cols) {
	int sum = 0;
	for (int j = 0;j < rows;j++) {
		sum += arr[j][cols];
	}
	return sum;
}


void PrintEachColSum(int arr[3][3], int rows, int cols) {
	cout << "\nThis is the following sum of each Col in the matrix \n";
	for (int i = 0;i < cols;i++) {
		cout << setw(3) << "Col  " << (i + 1) << " Sum = " << SumCol(arr, 3, i) << "\n";
	}
}
//void PrintRowsSumArray(int arr[3], short rows) {
//
//	for (int i = 0;i < rows;i++) {
//		cout << setw(3) << "Row  " << (i + 1) << " Sum = " << arr[i] << "\n";
//	}
//
//}
//
//void SumMatixRowsInArry(int oneDiaArr[3], int arr[3][3], int rows, int cols) {
//	cout << "\nThis is the following sum of each Row in the matrix \n";
//	for (int i = 0;i < rows;i++) {
//		oneDiaArr[i] = SumRow(arr, i, 3);
//	}
//}




int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3];
	int arrResultSum[3];
	FillTwoDiminsionalAraay(matrix);
	PrintAllElementsOfArray(matrix);
	PrintEachColSum(matrix,3,3);
	system("pause>0");
}
