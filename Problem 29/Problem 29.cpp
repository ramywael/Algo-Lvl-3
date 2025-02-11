/*
 Write a program to read string then count small/capital letters in the string
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

short CountCapitalLetters(string input) {
	short countCapital = 0;
	for (int i = 0;i < input.size();i++) {
		if (isupper(input[i]))
			countCapital++;
	}
	return countCapital;
}

short CountSmallLetters(string input) {
	short countSmall = 0;
	for (int i = 0;i < input.size();i++) {
		if (islower(input[i]))
			countSmall++;
	}
	return countSmall;
}


int main()
{
	string input = ReadString();

	cout << "String Length : = " << input.length();
	cout << "\n\nCapital Letters Count : =" << CountCapitalLetters(input);
	cout << "\n\nSmall Letters Count : =" << CountSmallLetters(input);

	system("pause>0");


}

