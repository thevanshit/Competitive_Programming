#include <iostream>
using namespace std;

void printNumbers (int num){

    if (num == 0) return;
    cout << num << " ";

    printNumbers(num - 1);
}

int main (){

    int num;
    cout << "Enter the Number : ";
    cin >> num;

    printNumbers(num);
}