#include <iostream>
using namespace std;

void Sum(int i,int sum){

    if (i < 1){
        cout << "The Value of Sum is : " << sum;
        return;
    }

    Sum(i-1,sum+i);
}

int main (){

    int num;
    num = 10;
    Sum(num,0);
    return 0;
}