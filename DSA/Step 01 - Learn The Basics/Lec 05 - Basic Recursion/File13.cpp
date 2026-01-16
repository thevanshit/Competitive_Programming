#include <iostream>
using namespace std;

void fact(int n,int factorial){

    if (n < 1){
        cout << "The factorial of the Given Number is : " << factorial;
        return;
    }

    fact(n-1,factorial*n);

}

int main ()
{

    int num;
    num = 7;
    fact(num,1);
    return 0;
}