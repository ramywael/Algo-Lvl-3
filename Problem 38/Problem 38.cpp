/*
Write a program to read a string then  trim left,trim right ,trim
*/

#include <iostream>
#include<string>
#include <iomanip>
#include<vector>
using namespace std;


string TrimLeft(string str) {
	for (int i = 0;i < str.length();i++) {
		if (str[i] != ' ') {
			return str.substr(i);
		}
	}
	return "";
}

string TrimRight(string str) {
	for (int i = str.length()-1;i >= 0;i--) {
		if (str[i] != ' ') {
			return str.substr(0, i+1);
		}
	}
	return "";
}

string Trim(string str) {
	return (TrimRight(TrimLeft(str)));
}

int main()
{
	string S1 = "         Mohammed Abu-Hahdoud               ";
	cout <<"String          ="<< S1 << "\n";

	cout << "\n\n Trim Left  =" << TrimLeft(S1) << "\n";
	cout << "\n\n Trim Right  =" << TrimRight(S1) << "\n";
	cout << "\n\n Trim   =" << Trim(S1);


	system("pause>0");


}

