/*
 Write a program to read string and read a character then count
 the character in that string
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
char ReadChar() {
	char inputChar;
	cout << "Please Enter Your a character ? : \n";
	cin >> inputChar;
	return inputChar;

}

short CountSpecificLetter(char specificLetter,string input) {
	short count = 0;
	for (int i = 0;i < input.size();i++) {
		if (input[i] == specificLetter)
			count++;
	}
	return count;
}


int main()
{
	string input = ReadString();

	char character = ReadChar();

	cout << "Letter ' " << character << " ' Count = : " << CountSpecificLetter(character, input);

	system("pause>0");


}

