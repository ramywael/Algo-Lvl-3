

/*
  Write a program 
  to update client By AccountNumber
*/



#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include <iomanip>

using namespace std;

const string FileName = "MyFile.txt";


struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForUpdate = false;
};

vector<string> SplitString(string line, string sperator = "#//#") {
	short pos = 0;
	string sWord;
	vector<string> vString;
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

stClient ConvertLineToRecord(string line) {
	stClient client;
	vector<string> vString = SplitString(line);
	client.AccountNumber = vString[0];
	client.PinCode = vString[1];
	client.Name = vString[2];
	client.Phone = vString[3];
	client.AccountBalance = stod(vString[4]);

	return client;
}


vector<stClient> LoadDataFromFile() {
	fstream file;
	string line;
	stClient client;
	vector<stClient> vClients;
	file.open(FileName, ios::in);

	if (file.is_open()) {
		while (getline(file, line)) {
			client = ConvertLineToRecord(line);
			vClients.push_back(client);
		}
		file.close();
	}
	return vClients;
}
string ReadUserInput() {
	string userInput;
	cout << "\n\nPlease Enter Your Account Number ? ";
	cin >> userInput;
	return userInput;
}

void PrintClientCard(stClient client) {
	cout << "\n\nAccountNumber :" << client.AccountNumber << "\n";
	cout << "PinCode :" << client.PinCode << "\n";
	cout << "Name :" << client.Name << "\n";
	cout << "Phone :" << client.Phone << "\n";
	cout << "Account Balance :" << client.AccountBalance << "\n";

}

bool FindAccountNumber(vector<stClient>& vClients, string userInput, stClient& emptyClient) {
	for (stClient& client : vClients) {
		if (client.AccountNumber == userInput) {
			emptyClient = client;
			return true;
		}
	}
	return false;
}
bool MarkAccountByUpdate(vector<stClient>& vClients, string userInput) {
	for (stClient& client : vClients) {
		if (client.AccountNumber == userInput) {
			client.MarkForUpdate = true;
			return true;
		}
	}
	return false;
}

string ConvertLineToRecord(stClient client, string sperator = "#//#") {
	string stCompleteWord = client.AccountNumber + sperator
		+ client.PinCode + sperator
		+ client.Name + sperator
		+ client.Phone + sperator
		+ to_string(client.AccountBalance);
	return stCompleteWord;
}


vector<stClient> SaveDataToFile(string fileName, vector<stClient>& vClients) {
	fstream file;
	string dataLine;
	file.open(fileName, ios::out);
	if (file.is_open()) {
		for (stClient& client : vClients) {
				dataLine = ConvertLineToRecord(client);
				file << dataLine << "\n";
		}
		file.close();
	}
	return vClients;
}

void PrintUpdatedData(stClient & client) {
	cout << "Enter Pin Code : " ;
	getline(cin>>ws, client.PinCode);

	cout << "Enter Name : " ;
	getline(cin, client.Name);

	cout << "Enter Phone : " ;
	getline(cin, client.Phone);


	cout << "Enter Balance : ";
	cin >> client.AccountBalance;

}

vector<stClient> UpdateClient(vector<stClient>& vClients) {
	for (stClient& client : vClients) {
		if (client.MarkForUpdate == true) {
			PrintUpdatedData(client);
		}
	}
	return vClients;
}
bool UpdateAccountByAccountNumber(vector<stClient>& vClients, string userInput, stClient& client) {
	char userChoice = 'n';
	if (FindAccountNumber(vClients, userInput, client)) {
		PrintClientCard(client);
		cout << "\n\n Do You Want To Update This Account ? : ";
		cin >> userChoice;
		if (tolower(userChoice) == 'y') {


			MarkAccountByUpdate(vClients, userInput);
			UpdateClient(vClients);
			SaveDataToFile(FileName, vClients);

			vClients = LoadDataFromFile();
			cout << "\n\nAccount Updated Successfully \n";
			return true;
		}
	}
	else {
		cout << "\n\nCannot Find This Account Number (" << userInput << ") ";
		return false;
	}
}

int main() {
	stClient client;
	vector<stClient> vClients = LoadDataFromFile();
	string userInput = ReadUserInput();
	UpdateAccountByAccountNumber(vClients, userInput, client);

	system("pause > 0");
}