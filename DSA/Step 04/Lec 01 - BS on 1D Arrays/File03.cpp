#include <iostream>
#include <vector>
using namespace std;

int lowerBoundRecursive(const vector<int> &arr, int left, int right, int target, int ans = -1) {
    if (left > right) 
        return ans;
    int mid = left + (right - left) / 2;

    if (arr[mid] >= target) {
        // Update answer and go left searching for earlier occurrence
        return lowerBoundRecursive(arr, left, mid - 1, target, mid);
    } else {
        // Go right as current not satisfying condition
        return lowerBoundRecursive(arr, mid + 1, right, target, ans);
    }
}

int lowerBound(const vector<int>& arr, int target) {
    return lowerBoundRecursive(arr, 0, arr.size() - 1, target);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 12, 15};
    int target = 11;
    int idx = lowerBound(arr, target);
    if (idx != -1)
        cout << "Lower Bound Found at index " << idx << endl;
    else
        cout << "Lower Bound Not found" << endl;
    return 0;
}
