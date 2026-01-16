#include <iostream>
#include <vector>
using namespace std;

void PrintTheVec(vector<int> &vec) {
    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

vector<int> PrintTheRow(vector<int> &vec) {
    vector<int> res;
    int n = vec.size();

    for (int i = 0; i < n; i++) {
        // Skip if already in result
        bool alreadyAdded = false;
        for (int x : res) {
            if (x == vec[i]) {
                alreadyAdded = true;
                break;
            }
        }
        if (alreadyAdded) continue;

        // Count occurrences
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (vec[i] == vec[j]) {
                count++;
            }
        }

        if (count > n / 3) {
            res.push_back(vec[i]);
        }
    }

    return res;
}

int main() {
    vector<int> vec = {1, 3, 1, 1, 3, 2, 2, 2};
    cout << "The Given Vector Array is : ";
    PrintTheVec(vec);

    vector<int> res = PrintTheRow(vec);

    cout << "Elements that appear more than n/3 times are : ";
    PrintTheVec(res);
    return 0;
}