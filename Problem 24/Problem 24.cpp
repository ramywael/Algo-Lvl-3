/*
Write a program to read a string then uppear case the first letter
of each word in that string

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
int ConvertToUpper(char firstLetter) {
		return int(firstLetter-32);
 }

void isFirstLetter(string& str) {
	bool isFirst = true;
	int value = 0;
	for (int i = 0;i < str.size();i++) {
		if (str[i] != ' ' && isFirst) {
			value = ConvertToUpper(str[i]);
			str[i] = char(value);
		}
		isFirst = (str[i] == ' ' ? true : false);
	}
}
void PrintConverteddString(string str) {
	cout << str << "\n";
}

int main()
{
	string input = ReadString();
	isFirstLetter(input);
	PrintConverteddString(input);
}

