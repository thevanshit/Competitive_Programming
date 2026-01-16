#include <iostream>
using namespace std;

void printNumbers (int i){

    if (i < 1) return;

    printNumbers(i-1);
    cout << i << " ";
}

int main (){

    int num;
    cout << "Enter the Number : ";
    cin >> num;

    printNumbers(num);
}