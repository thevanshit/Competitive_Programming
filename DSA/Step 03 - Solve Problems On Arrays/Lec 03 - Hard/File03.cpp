#include <iostream>
#include <vector>
#include <climits>
using namespace std;

namespace upstream {

    vector<int> findMajorityElements(const vector<int>& nums) {
        vector<int> res;
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // 1st pass: find potential candidates
        for (int num : nums) {
            if (el1 == num) cnt1++;
            else if (el2 == num) cnt2++;
            else if (cnt1 == 0) {
                el1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                el2 = num;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // 2nd pass: verify the counts
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == el1) cnt1++;
            if (num == el2) cnt2++; // allow el1 == el2 check to prevent skipping
        }

        int n = nums.size();
        if (cnt1 > n / 3) res.push_back(el1);
        if (el1 != el2 && cnt2 > n / 3) res.push_back(el2);

        return res;
    }

}

void PrintTheVec(const vector<int> &vec) {
    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 3, 1, 1, 3, 3, 2, 2};

    cout << "The Given Vector Array is : ";
    PrintTheVec(vec);

    vector<int> res = upstream::findMajorityElements(vec);

    cout << "Elements that appear more than n/3 times are : ";
    PrintTheVec(res);

    return 0;
}