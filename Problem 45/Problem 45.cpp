
/*
    Write a program to read bank client data record  and convert it to one line
*/

#include<iostream>
#include<string>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};

stClient ReadClientDate(string mssg) {
    stClient client;
    cout << mssg << "\n";

    cout << "\n\n Enter Your Accout Number ? ";
    cin >> client.AccountNumber;

    cout << "\n\n Enter Your PinCode ? ";
    cin >> client.PinCode;
    cin.ignore();

    cout << "\n\n Enter Your Name ? ";
    getline(cin, client.Name);

    cout << "\n\n Enter Your Phone ? ";
    cin >> client.Phone;

    cout << "\n\n Enter Your Balance ? ";
    cin >> client.AccountBalance;
    return client;
}

string ConvertRecordToClient(stClient client,string seprator) {
    string mergedContent;
    mergedContent = client.AccountNumber+ seprator+client.PinCode+seprator+client.Name+seprator+client.Phone +seprator+ to_string(client.AccountBalance);
    return mergedContent;
}
int main() {
    cout<<"\n\nClient Record For Saving Is \n\n"<< ConvertRecordToClient(ReadClientDate("Please Enter Your Client Date : "),"#//") << "\n";
   
    system("pause>0");
}