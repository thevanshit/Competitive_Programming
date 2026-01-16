#include <iostream>
#include <vector>
using namespace std;

void PrintTheVec (vector <int> &vec){

    for (auto it : vec)
    {
        cout << it << " ";
    }
    
}

void PrintTheMatrix (vector <vector<int>> &vec){

    for (int i = 0; i < vec.size(); i++)
    {
        for (auto it : vec[i])
        {
            cout << it << " ";
        }
        cout << endl;
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

vector <vector <int>> Pascaltriangle (int row){
    

    vector <vector <int>> res;
    for (int i = 1; i <= row; i++)
    {
        res.push_back(PrintTheRow(i));
    }
    
    return res;
}

int main() {

    int row = 6;
    vector <vector<int>> res;
    res = Pascaltriangle(row);

    cout << "The Particular combination row in the Pascal's Triangle is : " << endl;
    PrintTheMatrix(res);
    return 0;
}