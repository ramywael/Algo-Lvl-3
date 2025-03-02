
/*
    Write a program to convert line data to record and print it
*/

#include<iostream>
#include<string>
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

vector<string> SplitString(string str,string sperator="#//#") {
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = str.find(sperator)) != std::string::npos) {
        sWord = str.substr(0,pos);
        if (sWord != "") {
            vString.push_back(sWord);
       }
        str.erase(0, pos + sperator.length());
    }
    if (str != "") {
        vString.push_back(str);
    }
    return vString;
}

stClient ConvertLineToRecord(vector<string> &vString) {
    stClient client;
    client.AccountNumber = vString[0];
    client.PinCode = vString[1];
    client.Name = vString[2];
    client.Phone = vString[3];
    client.AccountBalance = stod(vString[4]);

    return client;

 }
void PrintClientRecord(stClient client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << client.AccountNumber;
    cout << "\nPin Code : " << client.PinCode;
    cout << "\nName : " << client.Name;
    cout << "\nPhone : " << client.Phone;
    cout << "\nAccount Balance: " << client.AccountBalance;
}
int main() {

    string stLine = "A150#//#1234#//#Mohammed Abu- Hadhoud#//#079999#//#5270.000000";

    cout << "\n\nLine Record is : \n\n"<<stLine;

    vector<string> vString = SplitString(stLine);
    stClient client = ConvertLineToRecord(vString);
    PrintClientRecord(client);
    system("pause>0");
}