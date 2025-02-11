/*
Write a program to read a string then upper case all letters, then
lower all letters,and print them
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

string ConvertToUpperString(string str) {
	for (int i = 0;i < str.size();i++) {
		
			str[i] = toupper(str[i]);
		
	}
	return str;
}

string ConvertToLowerString(string str) {
	for (int i = 0;i < str.size();i++) {
		
			str[i] = tolower(str[i]);
		
	}
	return str;

}
void PrintConverteddString(string str) {
	cout << str << "\n";
}

int main()
{
	string input = ReadString();
	cout << "String after upper : \n";
	
	PrintConverteddString(ConvertToUpperString(input));

	cout << "\nString after lower : \n";
	
	PrintConverteddString(ConvertToLowerString(input));
}

