#include <iostream>
#include <vector>
using namespace std;

pair<int, int> FindCeilAndFloor(const vector<int>& arr, int left, int right, int target) {
    int ceil = -1;
    int floor = -1;
    
    // Find Floor (largest element <= target)
    int l = left, r = right;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            floor = mid;
            break;
        }
        else if (arr[mid] < target) {
            floor = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    // Find Ceil (smallest element >= target)
    l = left, r = right;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            ceil = mid;
            break;
        }
        else if (arr[mid] < target) {
            l = mid + 1;
        }
        else {
            ceil = mid;
            r = mid - 1;
        }
    }

    return {ceil, floor};
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 12, 15};
    int target = 11;
    pair<int, int> idx = FindCeilAndFloor(arr, 0, arr.size() - 1, target);
    
    if (idx.first != -1)
        cout << "Ceil Value: " << arr[idx.first] << " (at index " << idx.first << ")" << endl;
    else
        cout << "Ceil value not found" << endl;

    if (idx.second != -1)
        cout << "Floor Value: " << arr[idx.second] << " (at index " << idx.second << ")" << endl;
    else
        cout << "Floor value not found" << endl;

    return 0;
}
