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

int aggressiveCowsBruteForce(vector<int> stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int ans = 1;
    int maxDist = stalls.back() - stalls.front();
    for (int dist = 1; dist <= maxDist; dist++) {
        if (!canPlace(stalls, cows, dist)) {
            return dist - 1;
        } else {
            ans = dist;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << "Brute force: Maximum minimum distance = " << aggressiveCowsBruteForce(stalls, cows) << endl;
    return 0;
}
