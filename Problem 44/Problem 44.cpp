/*
Write A program to replace Words in string using custom function
*/

#include <iostream>
#include<string>
using namespace std;





string RemovePunctionFromString(string word) {
	string newString;
	for (int i = 0;i < word.length();i++) {
		if (!ispunct(word[i])) {
		  newString+=word[i];
		}
	}
	return newString;
}







int main()
{
	string input = "Welcome to Egypt , Egypt is a nice country; It's Amazing ";
	cout << "\n\n Original String :\n " << input;

	cout << "\n\n Punctions Removed : \n" << RemovePunctionFromString(input);



	
	system("pause>0");
}
