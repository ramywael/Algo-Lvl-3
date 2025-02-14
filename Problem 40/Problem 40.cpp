/*
 Write a program to Join array of strings into a one string with
separators (overloading)
*/

#include <iostream>
#include<string>
#include <iomanip>
#include<vector>
using namespace std;
string JoinString(vector<string>& vString, string delimiter) {
	string vWord = "";
	for (string& Word : vString) {
		vWord += Word + delimiter;
	}
	return vWord.substr(0, vWord.length() - delimiter.length());
}
string JoinString(string arr[], int length, string delimiter) {
	string aWord = "";
	for (int i = 0;i < length;i++) {
		aWord += arr[i] + delimiter;
	}
	return aWord.substr(0,aWord.length()-delimiter.length());
}



int main()
{
	vector<string> vString = { "Mohamed","Ali","Ramy","Yehia","Hafez" };
	string arr[] = { "Mohamed","Ali","Ramy","Yehia","Hafez" };
	cout << "Vector after Join : \n";
	cout << JoinString(vString, "###") << "\n";

	cout << "Array after Join : \n";
	cout << JoinString(arr,5, "###") << "\n";

	system("pause>0");


}

