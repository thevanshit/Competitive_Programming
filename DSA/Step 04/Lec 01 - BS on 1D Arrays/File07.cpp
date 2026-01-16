#include <iostream>
#include <vector>
using namespace std;

int FindInsertIndex(const vector<int> &arr, int left, int right, int target) {
    int ans = -1;

    while (left <= right){
        int mid = left + (right - left);

        if (arr[mid] >= target){
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
    int idx = FindInsertIndex(arr, 0, arr.size() - 1, target);
    cout << "Index Where the Element should be inserted is : " << idx << " (value: " << target << ")" << endl;
    return 0;
}
