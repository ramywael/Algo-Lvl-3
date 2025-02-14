/*
 Write a program to read string and read a character then count
 the character in that string (Match case or not)
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

char InvertCharacter(char char1) {
	return islower(char1) ? toupper(char1) : tolower(char1);
}

short CountSpecificLetter(char specificLetter, string input,bool matchCase=true) {
	short count = 0;
	for (int i = 0;i < input.size();i++) {
		if (matchCase) {
			if (specificLetter == input[i]) {
				count++;
			}
		}
		else {
			if (toupper(input[i]) == toupper(specificLetter)) {
				count++;
			}
		}
	}
	return count;
}


int main()
{
	string input = ReadString();

	char character = ReadChar();

	cout << "Letter ' " << character << " ' Count = : " << CountSpecificLetter(character, input);
	cout << "\n\nLetter ' " << character << " ' \  ";
	cout << "Or '\  " << InvertCharacter(character) << " \'  Count =" << CountSpecificLetter(character, input,false);

	system("pause>0");


}

