#include <iostream>
using namespace std;

int Sum(int n){

    if (n == 0){
        return 0;
    }

    return n + Sum(n-1);
}

int main (){

    int num;
    num = 10;
    int sum;
    sum = Sum(num);
    cout << "The Value of Sum is : " << sum;

    return 0;
}