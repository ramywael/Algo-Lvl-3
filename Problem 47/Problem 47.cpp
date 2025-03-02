
/*
    Write a program to ask you to enter clients and save them to file:
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};

stClient AddNewClient() {
    stClient client;
    cout << "\n\n Enter Your Accout Number ? ";
    getline(cin >> ws, client.AccountNumber);

    cout << "\n\n Enter Your PinCode ? ";

    getline(cin , client.PinCode);


    cout << "\n\n Enter Your Name ? ";
    getline(cin, client.Name);

    cout << "\n\n Enter Your Phone ? ";
    getline(cin, client.Phone);

    cout << "\n\n Enter Your Balance ? ";
    cin >> client.AccountBalance;

    return client;
}
string ConvertRecordToClient(stClient client, string seprator = "#//#") {
    string mergedContent;
    mergedContent = client.AccountNumber + seprator + client.PinCode + seprator + client.Name + seprator + client.Phone + seprator + to_string(client.AccountBalance);
    return mergedContent;
}

void StoreDateOnFile(string input) {
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << input << "\n";
        MyFile.close();
    }
}

void AddClients() {
    stClient client;
    char input = 'Y';
    do {
        system("cls");
        cout << "\n\nPlease Enter Your Account Data ? : \n\n";
        client = AddNewClient();
        StoreDateOnFile(ConvertRecordToClient(client));

        cout << "Client Added Successfully,Do you want to add more clients ? :";
        cin >> input;
    } while (toupper(input) == 'Y');
}







int main() {
    AddClients();
    system("pause>0");
}