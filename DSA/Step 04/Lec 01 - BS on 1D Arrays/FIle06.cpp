#include <iostream>
#include <vector>
using namespace std;

int upperBound(const vector<int> &arr, int left, int right, int target) {
    int ans = -1;

    while (left <= right){
        int mid = left + (right - left);

        if (arr[mid] > target){
            ans = mid;
            right = mid - 1;
        }
        else { 
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 12, 15};
    int target = 11;
    int idx = upperBound(arr, 0, arr.size() - 1, target);
    if (idx != -1)
        cout << "Upper Bound Found at index " << idx << " (value: " << arr[idx] << ")" << endl;
    else
        cout << "Upper Bound Not found" << endl;
    return 0;
}
