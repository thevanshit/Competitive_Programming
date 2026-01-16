#include <iostream>
using namespace std;

int fact(int n){

    if (n < 1){
        return 1;
    }

    return n * fact(n-1);
}

int main ()
{

    int num;
    num = 7;
    int factorial = fact(num);
    cout << "The factorial of the Given Number is : " << factorial;
    return 0;
}