/*
Write A program to read string and then reverse its words
*/

#include <iostream>
#include<string>
#include<vector>
using namespace std;

string ReadString() {
	string inputString;
	cout << "Please Enter Your String ? : \n";
	getline(cin, inputString);
	return inputString;

}


vector<string> SplitString(string word,string delimter) {
	int pos = 0;
	string sWord;
	vector<string> splitVector;
	while ((pos = word.find(delimter)) != std::string::npos) {
		sWord = word.substr(0, pos);
		if (sWord != "") {
			splitVector.push_back(sWord);
		}
		word.erase(0, pos + delimter.length());
	}
	if (word != "") {
		splitVector.push_back(word);
	}
	return splitVector;
}

string ReverseString(string str) {
	vector<string> vString= SplitString(str, " ");
	string sWord = "";
	for (int i = vString.size() - 1; i >= 0;i--) {
		sWord += vString[i]+" ";
	 }
	sWord=sWord.substr(0,sWord.length()-1);
	return sWord;
}

int main()
{
	string input = ReadString();
	cout<< ReverseString(input);
	system("pause>0");
}
