#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void PrintTheVec(vector<int> &vec) {
    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

void PrintTheMatrix(vector<vector <int>> &vec) {
    for (auto &row : vec) {
        for (auto it : row) {
            cout << it << " ";
        }
        cout << endl;
    }
}

vector<vector <int>> PrintTheRow(vector<int> &vec) {

    set <vector <int>> st;
    for (int i = 0; i < vec.size(); i++)
    {
       for (int j = i+1; j < vec.size(); j++)
        {
            for (int k = j+1; k < vec.size(); k++)
            {
                for (int l = k+1; l < vec.size(); l++)
                {
                    if (vec[i] + vec[j] + vec[k] + vec[l] == 0){
                    vector <int> temp = {vec[i],vec[j],vec[k],vec[l]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                }
            }
        }
    }

    return vector<vector <int>> (st.begin(),st.end());
}

int main() {
    vector<int> vec = {-1, 0, 1, 0, -2, 2};
    cout << "The Given Vector Array is : " << endl;
    PrintTheVec(vec);

    vector<vector <int>> res = PrintTheRow(vec);

    cout << "Ouadlets that sum up to 0 are : " << endl;
    PrintTheMatrix(res);
    return 0;
}