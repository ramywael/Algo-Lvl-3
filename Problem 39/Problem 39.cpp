/*
 Write a program to Join vector of strings into a one string with
separators
*/

#include <iostream>
#include<string>
#include <iomanip>
#include<vector>
using namespace std;
string JoinVector(vector<string> &vString,string delimiter) {
	string vWord="";
	for (string &Word : vString) {
		vWord += Word + delimiter;
	}
	return vWord.substr(0,vWord.length()-delimiter.length());
}


int main()
{
	vector<string> vString = {"Mohamed","Ali","Ramy","Yehia","Hafez"};
	cout << "Vector after Join : \n";
	cout << JoinVector(vString,"###") << "\n";
	system("pause>0");


}

