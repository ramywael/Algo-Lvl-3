/*
Write A program to replace Words in string using custom function
*/

#include <iostream>
#include<string>
#include<vector>
using namespace std;



vector<string> SplitString(string str,string delim) {
	int pos = 0;
	string sWord;
	vector<string> vString;
	while ((pos = str.find(delim)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if(sWord != "") {
			vString.push_back(sWord);
		}
		str.erase(0, pos + delim.length());
	}
	if (str != "") {
		vString.push_back(str);
	}
	return vString;
}

string LowerAllString(string input) {
	string convertedString = "";
	for (int i = 0;i < input.size();i++) {
		convertedString = tolower(input[i]);
	}
	return convertedString;

}

string JoinString(vector<string>& vString,string delim) {
	string S1;
	for (string& word : vString) {
		S1 += word + delim;
	}
	return S1.substr(0,S1.length()-delim.length());
}

string ReplaceWord(string str, string delim, string stringToReplace, string replcedTo, bool isMatchCase = true) {
	vector<string> vString = SplitString(str, delim);;
	for (string& word : vString) {
		if (isMatchCase) {
			if (word == stringToReplace) {
				word = replcedTo;
			}
		}
		else {
			if (LowerAllString(word) == LowerAllString(stringToReplace)) {
				word = replcedTo;
			}
		}
	}
	return JoinString(vString," ");
}




int main()
{
	string input = "Welcome to Egypt , Egypt is a nice place ";
	string stringToReplace = "Egypt";
	string replacedTo = "Mecca";
	cout << "\n\n Original String : " << input;

	cout << "\n\n Replaced String With Match Case : " <<ReplaceWord(input," ",stringToReplace,replacedTo);



	cout << "\n\n Original String : " << input;

	cout << "\n\n Replaced String Without Match Case : " << ReplaceWord(input, " ", stringToReplace, replacedTo,false);
	system("pause>0");
}
