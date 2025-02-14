/*
 Write a program to read a string then print each Word in that string
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

void PrintEachWordInString(string str) {
	string delimiter = " ";
	int pos = 0;
	string sWord;
	cout << "\n\n Your String Words are :\n";
	while ((pos=str.find(delimiter)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != "") {
			cout << sWord << "\n";
		}
		str.erase(0,pos+delimiter.length());
	}
	if (str != "") {
		cout << str << "\n";
	}
}


int main()
{
	string str = ReadString();
	PrintEachWordInString(str);



	system("pause>0");


}

