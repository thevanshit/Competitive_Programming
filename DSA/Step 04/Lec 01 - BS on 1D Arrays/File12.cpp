#include <iostream>
#include <vector>
using namespace std;

int searchRotatedSortedArray(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;

        // Check if left half is sorted
        if (arr[left] <= arr[mid]) {
            // Target is in left half
            if (target >= arr[left] && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Otherwise, right half must be sorted
        else {
            if (target > arr[mid] && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 7;
    int idx = searchRotatedSortedArray(arr, target);

    if (idx != -1)
        cout << "Element " << target << " found at index " << idx << endl;
    else
        cout << "Element " << target << " not found." << endl;
    return 0;
}
