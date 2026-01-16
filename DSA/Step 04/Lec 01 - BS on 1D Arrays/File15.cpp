#include <iostream>
#include <vector>
using namespace std;

int findMin(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return arr[left];
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element: " << findMin(arr) << endl;
    return 0;
}
