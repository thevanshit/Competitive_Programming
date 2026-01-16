#include <iostream>
using namespace std;

void printNumbers (int i,int num){

    if (i > num) return;

    printNumbers(i+1,num);
    cout << i << " ";
}

int main (){

    int num;
    cout << "Enter the Number : ";
    cin >> num;

    printNumbers(1,num);
}