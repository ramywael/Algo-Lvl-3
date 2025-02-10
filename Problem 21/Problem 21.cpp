
/*
 Write A program to print a fibonacci series of 10
*/

#include <iostream>
using namespace std;


void WriteFibonacciByLoop(int length) {
    int firstVal=1;
    int secondVal=0;
    int febNumber=0;
    cout << "1"<<" ";
    for (int i = 2;i <=length;i++) {
        febNumber = firstVal + secondVal;
        cout << febNumber << " ";
        secondVal =firstVal  ;
        firstVal = febNumber;
       
    }
}



int main()
{
    WriteFibonacciByLoop(15);
    system("pause>0");
}

