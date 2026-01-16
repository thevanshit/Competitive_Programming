#include<iostream>
using namespace std;

void print(int i,int n){
   
    if (i > n) return;
    cout << "Saturo Gojo" << endl;

    print(i+1,n);

}

int main(){
    int num;
    cout << "Enter the Num : ";
    cin >> num;

    print(1,num);

  return 0;
}