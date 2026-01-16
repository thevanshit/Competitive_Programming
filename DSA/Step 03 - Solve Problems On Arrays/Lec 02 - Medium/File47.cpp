#include <iostream>
#include <vector>
using namespace std;

void PrintTheVec (vector <int> &vec){

    for (auto it : vec)
    {
        cout << it << " ";
    }
    
}

vector <int> PrintTheRow (int n){

    vector <int> res;

    int ans = 1;
    res.push_back(ans);
    for (int i = 1; i < n; i++)
    {
        ans *= (n - i);
        ans /= (i);
        res.push_back(ans);
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