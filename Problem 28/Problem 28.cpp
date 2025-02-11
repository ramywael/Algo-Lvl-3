/*
Write a program to invert a string

*/

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

