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
    set<vector<int>> st;

    for (int i = 0; i < vec.size(); i++) {
        set<int> hashset;  // reset for each i
        for (int j = i + 1; j < vec.size(); j++) {
            int third = -(vec[i] + vec[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {vec[i], vec[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(vec[j]);
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

int main() {
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    cout << "The Given Vector Array is : " << endl;
    PrintTheVec(vec);

    vector<vector <int>> res = PrintTheRow(vec);

    cout << "Triplets that sum up to 0 are : " << endl;
    PrintTheMatrix(res);
    return 0;
}