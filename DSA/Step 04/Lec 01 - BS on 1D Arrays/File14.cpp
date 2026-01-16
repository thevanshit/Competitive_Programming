#include <iostream>
#include <vector>
using namespace std;

// Returns true if target is found, false otherwise
bool searchRotatedSortedArrayWithDuplicates(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return true;
        // Handle duplicates: shrink bounds
        if (arr[left] == arr[mid] && arr[mid] == arr[right]) {
            left++;
            right--;
        }
        // Left half sorted
        else if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Right half sorted
        else {
            if (arr[mid] < target && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    if (searchRotatedSortedArrayWithDuplicates(arr, target))
        cout << "Element " << target << " found in array." << endl;
    else
        cout << "Element " << target << " not found in array." << endl;
    return 0;
}
