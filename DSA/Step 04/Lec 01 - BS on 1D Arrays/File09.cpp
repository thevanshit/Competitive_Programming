#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of target
int findFirst(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            ans = mid;             // record potential answer
            right = mid - 1;       // try to find earlier occurrence on the left
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

// Function to find the last occurrence of target
int findLast(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            ans = mid;             // record potential answer
            left = mid + 1;        // try to find later occurrence on the right
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 5, 6};
    int target = 2;

    int first = findFirst(arr, target);
    int last = findLast(arr, target);

    if (first != -1 && last != -1) {
        cout << "First occurrence of " << target << " is at index: " << first << "\n";
        cout << "Last occurrence of " << target << " is at index: " << last << "\n";
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
