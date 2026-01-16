#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to calculate total hours needed at speed k
long long hoursToEatAll(const vector<int>& piles, int k) {
    long long hours = 0;
    for (int bananas : piles) {
        hours += static_cast<long long>(ceil(static_cast<double>(bananas) / k));
    }
    return hours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int maxpile = *max_element(piles.begin(), piles.end());
    int answer = maxpile;  // initialize with max speed in worst case

    for (int i = 1; i <= maxpile; i++) {   // start from 1, not 0
        long long required_time = hoursToEatAll(piles, i);
        if (required_time <= h) {
            answer = i;
            break;
        }
    }
    return answer;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = minEatingSpeed(piles, h);
    cout << "🍌 Minimum eating speed Koko needs: " << result << " bananas/hour" << endl;
    return 0;
}
