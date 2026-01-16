#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper to check if cows_with_distance(distance) is possible
bool canPlace(const vector<int>& stalls, int cows, int distance) {
    int count = 1;
    int last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= distance) {
            count++;
            last = stalls[i];
        }
        if (count == cows) return true;
    }
    return false;
}

int aggressiveCowsBinarySearch(vector<int> stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int left = 1;
    int right = stalls.back() - stalls.front();
    int ans = 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlace(stalls, cows, mid)) {
            ans = mid;     // update answer, try for bigger
            left = mid + 1;
        } else {
            right = mid - 1; // try smaller
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << "Binary search: Maximum minimum distance = " << aggressiveCowsBinarySearch(stalls, cows) << endl;
    return 0;
}
