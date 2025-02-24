/*
Write A program to replace Words in string
*/

#include <iostream>
#include<string>
using namespace std;


string ReplaceWord(string word, string stringToReplace,string replaced) {
	int pos = 0;

	while ((pos = word.find(stringToReplace)) != std::string::npos) {
		word = word.replace(pos, stringToReplace.length(), replaced);
		pos = word.find(stringToReplace);
	}
	return word;
}

int main()
{
	string input = "Welcome to Egypt , Egypt is a nice place ";
	string stringToReplace = "Egypt";
	string replacedTo = "Mecca";
	cout << "\n\n Original String : " << input;

	cout <<"\n\n Replaced String : "  << ReplaceWord(input, stringToReplace, replacedTo);
	system("pause>0");
}
