/*
 Write a program to read a string then count all vowels in that string
( Vowels are a,e,i,o,u )
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


bool isVowel(char arr[5], char specificCharacter) {
	specificCharacter = tolower(specificCharacter);
	for (int i = 0;i < 5;i++) {
		if (arr[i] == specificCharacter)
			return true;
	}
	return false;
}

short CountVowelsOnString(char arr[5], string str) {
	short count=0;
	for (int i = 0;i < str.size();i++) {
		if (isVowel(arr, str[i])) {
			count++;
		}
	}
	return count;
}

int main()
{
	string str = ReadString();
	char arr[5] = { 'a','e','i','o','u' };

	short numberOfVowels = CountVowelsOnString(arr,str);

	cout << "\n\n Number Of Vowels is : " << numberOfVowels << "\n";


	system("pause>0");


}

