#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

int factorial (int num) {
    
    if (num == 1 || num == 0){
        return 1;
    }

    return num * factorial(num-1);
}
int combination (int n, int r){

    int ncr = factorial(n)/(factorial(r)*factorial(n-r));
    return ncr;
}

int main() {

    int row = 5;
    int col = 3;
    int nCr;
    nCr = combination(row-1,col-1);

    cout << "The Particular combination in the Pascal's Triangle is : " << nCr << endl;;
    return 0;
}