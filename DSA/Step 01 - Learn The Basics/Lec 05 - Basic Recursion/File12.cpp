#include <iostream>
using namespace std;

void fact(int i,int n,int factorial){

    if (i > n){
        cout << "The factorial of the Given Number is : " << factorial;
        return;
    }

    fact(i+1,n,factorial*i);

}

int main ()
{

    int num;
    num = 7;
    fact(1,num,1);
    return 0;
}