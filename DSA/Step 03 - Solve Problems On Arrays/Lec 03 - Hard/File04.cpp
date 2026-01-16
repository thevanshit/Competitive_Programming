#include <iostream>
#include <vector>
#include <set>
using namespace std;

void PrintTheVec(vector<int> &vec) {
    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

void PrintTheMatrix(vector<vector <int>> &vec) {
    for (int i = 0; i < vec.size(); i++)
    {
        for (auto it : vec[i]) {
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
                if (vec[i] + vec[j] + vec[k] == 0){
                    vector <int> temp = {vec[i],vec[j],vec[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
            
        }
        
    }
    
    
    return vector<vector<int>> (st.begin(),st.end());
}

int main() {
    vector<int> vec = {-1, 3, -2, 4, -2, -3, -2, 2, 0, 1};
    cout << "The Given Vector Array is : " << endl;
    PrintTheVec(vec);

    vector<vector <int>> res = PrintTheRow(vec);

    cout << "Elements triplets that sums up to (3) : " << endl;
    PrintTheMatrix(res);
    return 0;
}