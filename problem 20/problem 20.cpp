/*
Write a Program to Check it the matrix is palindrome or not
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void PrintMatrix(int arr[3][3]) {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%0*d  ", 2, arr[i][j], setw(3));
		}
		cout << "\n\n";
	}
}


bool IsPalindrome(int arr[3][3],short rows,short cols) {

	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols/2;j++) {
			if (arr[i][j] != arr[i][cols - j - 1]) {
				return false;
			}
		}
	}
	return true;

}




int main() {
	srand((unsigned)time(NULL));
	int arr[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	int arr2[3][3] = { {1,2,1},{5,5,5},{7,3,8} };


	cout << "Matrix 1 : \n";
	PrintMatrix(arr2);


	if (IsPalindrome(arr2, 3, 3))
		cout << "Yes ,Matrix is Palindrome \n";
	else
		cout << "No, Matrix is not palindrome \n";

	system("pause>0");
}