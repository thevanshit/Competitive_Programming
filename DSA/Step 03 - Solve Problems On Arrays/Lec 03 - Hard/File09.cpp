#include <iostream>
#include <vector>
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

    sort(vec.begin(), vec.end());
    vector <vector <int>> res;
    for (int i = 0; i < vec.size(); i++)
    {
       if (i > 0 && vec[i] == vec[i-1]) continue;
       for (int j = i+1; j < vec.size(); j++)
       {
            if (j != i+1 && vec[j] == vec[j-1]) continue;
            int k = j+1;
            int l = vec.size()-1;
            while (k < l){
                long long sum = vec[i];
                sum += vec[j];
                sum += vec[k];
                sum += vec[l];
                if ( sum == 0 ){
                    vector <int> temp = {vec[i], vec[j], vec[k], vec[l]};
                    res.push_back(temp);
                    k++;
                    l--;
                    while (k < l && vec[k] == vec[k-1]) k++;
                    while (k < l && vec[l] == vec[k+1]) l--;
                }
                else if (sum < 0){
                    k++;
                }
                else {
                    l--;
                }
            }
       }
       
    }

    return res;
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