#include <iostream>
#include <vector>
using namespace std;

// Find lower bound: first index where arr[i] >= target
int lowerBound(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
}

// Find upper bound: first index where arr[i] > target
int upperBound(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) right = mid;
        else left = mid + 1;
    }
    return left;
}

pair<int, int> findFirstAndLastOccurrences(const vector<int>& arr, int target) {
    int n = (int)arr.size();
    int first = lowerBound(arr, target);
    if (first == n || arr[first] != target) {
        return {-1, -1};  // target not found
    }
    int last = upperBound(arr, target) - 1;
    return {first, last};
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 5, 6};
    int target = 2;
    auto res = findFirstAndLastOccurrences(arr, target);

    if (res.first != -1 && res.second != -1) {
        cout << "First occurrence of " << target << " at index: " << res.first << endl;
        cout << "Last occurrence of " << target << " at index: " << res.second << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }
    return 0;
}
