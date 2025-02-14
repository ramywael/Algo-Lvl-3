/*
 Write a program to read a string then count each Word in that string
*/

#include <iostream>
#include<string>
#include <iomanip>
#include<vector>
using namespace std;

string ReadString() {
	string inputString;
	cout << "Please Enter Your String ? : \n";
	getline(cin, inputString);
	return inputString;

}

vector<string> CountEachWordInString(string str, string delimiter) {
	int pos = 0;
	string sWord;
	vector<string> splitVector;
	short count = 0;
	while ((pos = str.find(delimiter)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != "") {
			splitVector.push_back(sWord);
		}
		str.erase(0, pos + delimiter.length());
	}
	if (str != "") {
		splitVector.push_back(str);
	}
	return splitVector;
}

void PrintWachWordInVector(vector<string>& splitVector) {
	cout <<"Tokens :" << splitVector.size()<<"\n";
	for (string& word : splitVector) {
		cout << word << "\n";
	}
}

int main()
{
	string str = ReadString();
  vector<string> splitVeector=CountEachWordInString(str, " ");
  PrintWachWordInVector(splitVeector);

	system("pause>0");


}

