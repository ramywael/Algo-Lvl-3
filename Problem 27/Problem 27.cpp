/*
Write a program to read a character then invert its case
and print it
*/
#include <iostream>
#include<string>
using namespace std;

char ReadChar() {
	char inputChar;
	cout << "Please Enter Your a character ? : \n";
	cin >> inputChar;
	return inputChar;

}

char InvertCharacter(char input) {
	if (isupper(input)) {
		return tolower(input);
	}
	else
		return toupper(input);
}

void PrintCharacter(char result) {
	cout << result << "\n";
}
int main()
{
	char input = ReadChar();
	cout << "Char after inverting \n";
	PrintCharacter(InvertCharacter(input));
}

