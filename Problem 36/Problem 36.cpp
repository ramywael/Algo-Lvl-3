/*
 Write a program to read a string then count each Word in that string
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

short CountEachWordInString(string str) {
	string delimiter = " ";
	int pos = 0;
	string sWord;
	short count = 0;
	while ((pos = str.find(delimiter)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != "") {
			count++;
		}
		str.erase(0, pos + delimiter.length());
	}
	if (str != "") {
		count++;
	}
	return count;
}


int main()
{
	string str = ReadString();
    cout<<"\n\nThe number of words in your string is :"<< CountEachWordInString(str);



	system("pause>0");


}

