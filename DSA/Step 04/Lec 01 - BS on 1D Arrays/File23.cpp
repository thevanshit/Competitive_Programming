#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(const vector<int>& arr) {
    int n = arr.size();

    // Edge cases: only 1 element
    if (n == 1) return arr[0];

    // If first element is unique
    if (arr[0] != arr[1]) return arr[0];

    // If last element is unique
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    // Binary search between 1 and n - 2 (bounds safe for mid-1 & mid+1)
    int left = 1, right = n - 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If arr[mid] is the unique element
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        }

        // If mid is part of a pair starting at mid (even pattern)
        if (arr[mid] == arr[mid + 1]) {
            if (mid % 2 == 0) {
                left = mid + 2;
            } else {
                right = mid - 1;
            }
        }

        // If mid is part of a pair ending at mid
        else if (arr[mid] == arr[mid - 1]) {
            if (mid % 2 == 1) {
                left = mid + 1;
            } else {
                right = mid - 2;
            }
        }
    }

    return -1; // shouldn't happen if input is valid
}


int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8}; // Single element is 2
    cout << "Single non-duplicate element is: " << singleNonDuplicate(arr) << endl;
    return 0;
}
