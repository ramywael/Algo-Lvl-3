
/*
	Write a program to delete client by
	accountnumber
*/

//#include<iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include <iomanip>
//
//
//using namespace std;
//
//struct stClient {
//	string AccountNumber;
//	string PinCode;
//	string Name;
//	string Phone;
//	double AccountBalance;
//	bool MarkForDelete = false;
//
//};
//
//string ReadUserInput() {
//	string userInput;
//	cout << "Please Enter Your Account Number ? :";
//	getline(cin, userInput);
//	return userInput;
//}
//
//
//vector<string> SplitString(string line, string sperator = "#//#") {
//	vector<string> vString;
//	short pos = 0;
//	string sWord;
//	while ((pos = line.find(sperator)) != std::string::npos) {
//		sWord = line.substr(0, pos);
//		if (sWord != "") {
//			vString.push_back(sWord);
//		}
//		line.erase(0, pos + sperator.length());
//	}
//	if (line != "") {
//		vString.push_back(line);
//	}
//	return vString;
//}
//
//
//stClient ConvertLinetoRecord(string line) {
//	stClient client;
//	vector<string> vString = SplitString(line);
//	client.AccountNumber = vString[0];
//	client.PinCode = vString[1];
//	client.Name = vString[2];
//	client.Phone = vString[3];
//	client.AccountBalance = stod(vString[4]);
//
//
//	return client;
//
//}
//
//vector<stClient> LoadDataFromFile(string FileName) {
//	fstream MyFile;
//	stClient client;
//	vector<stClient> vClient;
//	MyFile.open(FileName, ios::in); //read mode
//	if (MyFile.is_open()) {
//		string line;
//		while (getline(MyFile, line)) {
//			client = ConvertLinetoRecord(line);
//			vClient.push_back(client);
//		}
//		MyFile.close();
//	}
//	return vClient;
//}
//
//void PrintClientCard(stClient client) {
//	cout << "\n\nAccount Number : " << client.AccountNumber << "\n";
//	cout << "Pin Code : " << client.PinCode << "\n";
//	cout << "Name : " << client.Name << "\n";
//	cout << "Phone : " << client.Phone << "\n";
//	cout << "Balance : " << client.AccountBalance << "\n";
//}
//bool MarkClientForDeleteByAccountNumber(vector<stClient>& vClients, string AccountNumber) {
//
//	for (stClient& client : vClients) {
//		if (client.AccountNumber == AccountNumber) {
//			client.MarkForDelete = true;
//			return true;
//		 }
//	}
//	return false;
//}
//
//string ConvertLineToRecord(stClient client,string sperator="#//#") {
//	string stClientRecord = client.AccountNumber + sperator
//		+ client.PinCode + sperator
//		+ client.Name + sperator
//		+ client.Phone + sperator
//		+ to_string(client.AccountBalance) + sperator;
//	return stClientRecord;
//}
//
//void SaveDataToFile(vector<stClient> vClients) {
//	fstream file;
//	string dataLine;
//	file.open("MyFile.txt", ios::out);
//	if (file.is_open()) {
//		for (stClient client : vClients) {
//			if (client.MarkForDelete == false) {
//				dataLine = ConvertLineToRecord(client);
//				file << dataLine << "\n";
//			}
//		}
//		file.close();
//	}
//}
//
//bool FindClient(vector<stClient>& vClients, string userInput, stClient& emptyClient) {
//	for (stClient& client : vClients) {
//		if (userInput == client.AccountNumber) {
//			emptyClient = client;
//			return true;
//		}
//	}
//	return false;
//}
//bool DeleteClientByAccountNumber(string userInput,vector<stClient>& vClients,stClient client) {
//	char userAnswer = 'N';
//	if (FindClient(vClients, userInput, client)) {
//		PrintClientCard(client);
//		cout << "Are you sure to delete this account ? :";
//		cin >> userAnswer;
//		if (tolower(userAnswer) == 'y') {
//			MarkClientForDeleteByAccountNumber(vClients,userInput);
//			SaveDataToFile(vClients);
//			vClients = LoadDataFromFile("MyFile.txt");
//			cout << "Client Removed Successfully \n";
//			return true;
//		}
//	}
//	else {
//		cout << "\n\nClient with account number (" << userInput << ") Not Found \n";
//		return false;
//	}
//}
//
//
//
//
//
//
//
//
//int main() {
//	stClient client;
//	vector<stClient> vClients = LoadDataFromFile("MyFile.txt");
//	string userInput = ReadUserInput();
//	DeleteClientByAccountNumber(userInput,vClients,client);
//	
//
//	system("pause>0");
//}


#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

const string FileName = "MyFile.txt";


struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

vector<string> SplitString(string line,string sperator="#//#") {
	short pos = 0;
	string sWord;
	vector<string> vString;
	while ((pos = line.find(sperator)) != std::string::npos) {
		sWord = line.substr(0,pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		line.erase(0,pos+sperator.length());
	}

	if (line != "") {
		vString.push_back(sWord);
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
	file.open(FileName,ios::in);

	if (file.is_open()) {
		while (getline(file,line)) {
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

bool FindAccountNumber(vector<stClient>& vClients,string userInput,stClient& emptyClient) {
	for (stClient& client : vClients) {
		if (client.AccountNumber==userInput) {
			emptyClient = client;
			return true;
		}
	}
	return false;
}
bool MarkAccountByDekete(vector<stClient>& vClients,string userInput) {
	for (stClient &client : vClients) {
		if (client.AccountNumber==userInput) {
			client.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

string ConvertLineToRecord(stClient client,string sperator="#//#") {
	string stCompleteWord = client.AccountNumber + sperator
		+ client.PinCode + sperator
		+ client.Name + sperator
		+ client.Phone + sperator
		+ to_string(client.AccountBalance);
	return stCompleteWord;
}


vector<stClient> SaveDataToFile(string fileName,vector<stClient>& vClients) {
	fstream file;
	string dataLine;
	file.open(fileName, ios::out);
	if (file.is_open()) {
		for (stClient& client : vClients) {
			if (client.MarkForDelete == false) {
				dataLine = ConvertLineToRecord(client);
				file << dataLine << "\n";
			}
	  }
		file.close();
	}
	return vClients;
}

bool DeleteAccountByAccountNumber(vector<stClient>& vClients,string userInput,stClient & client) {
	char userChoice = 'n';
	if (FindAccountNumber(vClients, userInput, client)) {
		PrintClientCard(client);
		cout << "\n\n Do You Want To Delete This Account ? : ";
		cin >> userChoice;
		if (tolower(userChoice) == 'y') {
			MarkAccountByDekete(vClients,userInput);
			SaveDataToFile(FileName,vClients);

			vClients = LoadDataFromFile();
			cout << "\n\nAccount Removed Successfully \n";
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
	DeleteAccountByAccountNumber(vClients, userInput,client);

	system("pause > 0");
}