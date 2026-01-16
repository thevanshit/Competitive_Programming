#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintTheVec(vector<vector<int>> &vec) {
    for (const auto &row : vec) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << " ";
    }
    cout << endl;
}

vector<vector<int>> GetOverlappedIntervals(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    if (intervals.empty()) return res;

    sort(intervals.begin(), intervals.end());

    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= res.back()[1]) {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }

    return res;
}

int main() {
    vector<vector<int>> vec = {
        {1, 3}, {2, 4}, {2, 6}, {8, 9},
        {8, 10}, {9, 11}, {15, 18}, {16, 17}
    };

    cout << "The Given Vector Array is : " << endl;
    PrintTheVec(vec);

    vector<vector<int>> OverlappedVec = GetOverlappedIntervals(vec);

    cout << "Overlapped Intervals : " << endl;
    PrintTheVec(OverlappedVec);

    return 0;
}