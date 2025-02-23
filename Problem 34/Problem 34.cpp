/*
 Write a program to read a string then print all vowels in that string
( Vowels are a,e,i,o,u ) otheer wise they lower or upper
*/

#include <iostream>
#include<string>
#include <iomanip>
using namespace std;

string ReadString() {
	string inputString;
	cout << "Please Enter Your String ? : \n";
	getline(cin, inputString);
	return inputString;

}


bool isVowel(char arr[5], char specificCharacter) {
	specificCharacter = tolower(specificCharacter);
	for (int i = 0;i < 5;i++) {
		if (arr[i] == specificCharacter)
			return true;
	}
	return false;
}

void PrintVowelsOnString(char arr[5], string str) {
	for (int i = 0;i < str.size();i++) {
		if (isVowel(arr, str[i])) {
			cout << setw(3) << str[i];
		}
	}
}

int main()
{
	string str = ReadString();
	char arr[5] = { 'a','e','i','o','u' };

	cout << "Vowels In String are :";
	PrintVowelsOnString(arr, str);



	system("pause>0");


}

