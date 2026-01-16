#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if we can make m bouquets by day 'day'
bool canMakeBouquets(const vector<int>& bloomDay, int day, int m, int k) {
    int bouquets = 0, flowers = 0;
    for (int bloom : bloomDay) {
        if (bloom <= day) {
            flowers++;
            // When we have enough flowers for one bouquet
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;  // reset sequence
        }
    }
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (m * k > n) return -1;  // impossible if not enough flowers

    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = *max_element(bloomDay.begin(), bloomDay.end());
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canMakeBouquets(bloomDay, mid, m, k)) {
            answer = mid;       // possible answer
            right = mid - 1;    // try for smaller day
        } else {
            left = mid + 1;     // need more days
        }
    }
    return answer;
}

int main() {
    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 3, k = 2; // No. of bouqets Needed And How many bouqets...

    int result = minDays(bloomDay, m, k);
    if (result != -1)
        cout << "Minimum days to make " << m << " bouquets: " << result << endl;
    else
        cout << "Impossible to make " << m << " bouquets." << endl;
    return 0;
}
