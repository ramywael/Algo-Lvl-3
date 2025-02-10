/*
Write A program to read a string then print the first letter of each word in that string
*/

#include <iostream>
#include<string>
using namespace std;
string ReadString() {
	string inputString;
	cout << "Please Enter Your String ? : \n";
    getline(cin,inputString);
	return inputString;

}
void FirstLetter(string inputString) {
	bool isFirstLetter = true;
	for (int i = 0;i < inputString.size();i++) {
		if (inputString[i] != ' ' && isFirstLetter) {
			cout << inputString[i]<<"\n";
		}
		isFirstLetter = (inputString[i] == ' ' ? true :false);
	}
}


int main()
{
	string input = ReadString();
	FirstLetter(input);
}
