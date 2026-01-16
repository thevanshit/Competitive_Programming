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
void PrintTheVec (vector <int> &vec){

    for (auto it : vec)
    {
        cout << it << " ";
    }
    
}

vector <int> PrintTheRow (int n){

    vector <int> res;
    for (int r = 1; r <= n; r++)
    {
        res.push_back(combination(n-1,r-1));
    }
    
    return res;
}

int main() {

    int row = 6;
    vector <int> res;
    res = PrintTheRow(row);

    cout << "The Particular combination row in the Pascal's Triangle is : " << endl;
    PrintTheVec(res);
    return 0;
}