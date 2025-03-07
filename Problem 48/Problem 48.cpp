
/*
	Write a program to read clients file and show them on
	the screen as follows
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <iomanip>


using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;

};

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

void PrintClientRecord(stClient Client) {
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}



void PrintVectorData(vector<stClient> vClients) {
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << "(Client(s)).";
		cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (stClient client : vClients) {
		PrintClientRecord(client);
		cout << "\n";
	}

}



int main() {
	vector<stClient> vClients = LoadDataFromFile("MyFile.txt");
	PrintVectorData(vClients);
	system("pause>0");
}