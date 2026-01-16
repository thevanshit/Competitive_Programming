#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;        // found, return index
        else if (arr[mid] < target)
            left = mid + 1;    // search right half
        else
            right = mid - 1;   // search left half
    }
    return -1; // not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 12, 15};
    int target = 12;
    int idx = binarySearch(arr, target);
    if (idx != -1)
        cout << "Found at index " << idx << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
