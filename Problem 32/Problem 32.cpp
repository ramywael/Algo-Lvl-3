/*
 Write a program to read a character the check if it is a vowel or not
( Vowels are a,e,i,o,u )
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

bool CheckVowel(char arr[5],char specificCharacter) {
	specificCharacter = tolower(specificCharacter);
	for (int i = 0;i < 5;i++) {
		if (arr[i] == specificCharacter)
			return true;
	}
	return false;
}


int main()
{
	char character = ReadChar();
	char arr[5] = { 'a','e','i','o','u' };

	if (CheckVowel(arr, character))
		cout << "Yes Letter \'" << character << "\' is Vowel" << "\n";
	else
		cout << "No, Letter \'" << character << "\' is not Vowel" << "\n";

	
	system("pause>0");


}

