#include <iostream>
#include <vector>
using namespace std;

int combination (int n, int r){

    int factorial = 1;
    for (int i = 0; i < r; i++)
    {
        factorial *= (n - i);
        factorial /= (i+1);
    }
    
    return factorial;
}

int main() {

    int row = 6;
    int col = 4;
    int nCr;
    nCr = combination(row-1,col-1);

    cout << "The Particular combination in the Pascal's Triangle is : " << nCr << endl;;
    return 0;
}