
/*
	Write a program to find client by 
	accountnumber and print it 
	to screen
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <iomanip>


using namespace std;

struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;

 };

string ReadUserInput() {
	string userInput;
	cout << "Please Enter Your Account Number ? :";
	getline(cin, userInput);
	return userInput;
}


vector<string> SplitString(string line, string sperator = "#//#") {
	vector<string> vString;
	short pos = 0;
	string sWord;
	while ((pos = line.find(sperator)) != std::string::npos) {
		sWord = line.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		line.erase(0, pos + sperator.length());
	}
	if (line != "") {
		vString.push_back(line);
	}
	return vString;
}


stClient ConvertLinetoRecord(string line) {
	stClient client;
	vector<string> vString = SplitString(line);
	client.AccountNumber = vString[0];
	client.PinCode = vString[1];
	client.Name = vString[2];
	client.Phone = vString[3];
	client.AccountBalance = stod(vString[4]);


	return client;

 }

vector<stClient> LoadDataFromFile(string FileName) {
	fstream MyFile;
	stClient client;
	vector<stClient> vClient;
	MyFile.open(FileName, ios::in); //read mode
	if (MyFile.is_open()) {
		string line;
		while (getline(MyFile, line)) {
			client = ConvertLinetoRecord(line);
			vClient.push_back(client);
		}
		MyFile.close();
	}
	return vClient;
}



void PrintClientRecord(vector<stClient>& vClients,string userInput) {
	bool isFound = false;
	for (stClient& client : vClients) {
		if (userInput == client.AccountNumber) {
			cout << "\n\nAccount Number : " << client.AccountNumber<<"\n";
			cout << "Pin Code : " << client.PinCode<<"\n";
			cout << "Name : " << client.Name<<"\n";
			cout << "Phone : " << client.Phone<<"\n";
			cout << "Balance : " << client.AccountBalance<<"\n";
			isFound = true;
			break;
		}
	}

	if (!isFound) {
		cout << "\n\nClient with account number (" << userInput << ") Not Found \n";
	}
}






int main() {
	vector<stClient> vClients = LoadDataFromFile("MyFile.txt");
	PrintClientRecord(vClients, ReadUserInput());
	system("pause>0");
}