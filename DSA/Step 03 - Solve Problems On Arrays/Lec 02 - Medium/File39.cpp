#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<vector <int>> &vec) {
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    
}

vector < vector<int>> RotateMatrixBy90(vector<vector <int>> &vec) {
    
    vector < vector <int>> ans(vec[0].size(),vector <int>(vec.size(),0));
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            ans[j][(vec.size()-1)-i] = vec[i][j];
        }
        
    }
    return ans;
}

int main() {
    vector< vector <int>> vec = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    vector <vector<int>> ans;
    ans = RotateMatrixBy90(vec);

    cout << "The (After rotating the Matrix by 90) in the Array is : " << endl;
    PrintTheArray(ans);
    return 0;
}