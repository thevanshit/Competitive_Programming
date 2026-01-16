#include <iostream>
using namespace std;

void printNumbers (int i){

    if (i < 1) return;
    cout << i << " ";
    printNumbers(i-1);
    
}

int main (){

    int num;
    cout << "Enter the Number : ";
    cin >> num;

    printNumbers(num);
}