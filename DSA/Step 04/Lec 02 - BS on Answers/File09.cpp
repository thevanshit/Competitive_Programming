#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate total hours needed at speed k
long long hoursToEatAll(const vector<int>& piles, int k) {
    long long hours = 0;
    for (auto banana : piles){
        hours += (banana + k - 1) / k;
    }
    return hours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long time = hoursToEatAll(piles, mid);

        if (time <= h){
            answer = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
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
