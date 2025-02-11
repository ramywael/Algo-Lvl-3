// Problem 28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

string ReadString() {
	string inputString;
	cout << "Please Enter Your String ? : \n";
	getline(cin, inputString);
	return inputString;

}

char InvertCharacter(char letter) {
	return (isupper(letter) ? tolower(letter) : toupper(letter));
}

string InvertString(string input) {
	for (int i = 0;i < input.size();i++) {
		input[i]=InvertCharacter(input[i]);
	}
	return input;
}

void PrintInvertedString(string result) {
	cout << result << "\n";
}
int main()
{
	string input = ReadString();
	cout << "String After Inverting All letters Case : \n";
	PrintInvertedString(InvertString(input));

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
