#include <iostream>
#include <vector>
#include <algorithm> // for min_element, max_element
using namespace std;

class Solution {
public:
    // Check if we can make m bouquets by day 'day' using bouquets of size k
    bool canMakeBouquet(const vector<int>& bloomDay, int day, int m, int k) {
        int flowers = 0;
        int noOfBouquets = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    noOfBouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return noOfBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (long long)bloomDay.size()) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquet(bloomDay, mid, m, k)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    int result = sol.minDays(bloomDay, m, k);

    if (result != -1)
        cout << "Minimum days to make " << m << " bouquets: " << result << endl;
    else
        cout << "Impossible to make " << m << " bouquets." << endl;

    return 0;
}
