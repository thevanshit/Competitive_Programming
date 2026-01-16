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
    vector<vector <int>> res;

    sort(vec.begin(),vec.end());
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0 && vec[i] == vec[i-1]) continue;

        int j = i + 1;
        int k = vec.size()-1;

        while(j <= k){
            if (vec[i] + vec[j] + vec[k] == 0){
                res.push_back({vec[i], vec[j], vec[k]});
                j++;
                k--;
                while (j <= k && vec[j] == vec[j-1]) j++;
                while (j <= k && vec[k] == vec[k+1]) k--;
            }
            else if (vec[i] + vec[j] + vec[k] < 0){
                j++;
            }
            else if (vec[i] + vec[j] + vec[k] > 0){
                k--;
            }
        }
    }

    return res;
}

int main() {
    vector<int> vec = {-1, 0, 0, -1, 2, -1, 2, 0, 2};
    cout << "The Given Vector Array is : " << endl;
    PrintTheVec(vec);

    vector<vector <int>> res = PrintTheRow(vec);

    cout << "Triplets that sum up to 0 are : " << endl;
    PrintTheMatrix(res);
    return 0;
}