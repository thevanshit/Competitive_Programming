#include <iostream>
#include <vector>
using namespace std;

// Merge step - counts reverse pairs and merges the sorted subarrays
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;

    // Count reverse pairs
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)arr[i] > 2LL * arr[j])
            j++;
        count += (j - (mid + 1));
    }

    // Merge the two sorted subarrays
    vector<int> temp;
    int i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    // Copy merged elements back
    for (int k = left; k <= right; k++)
        arr[k] = temp[k - left];

    return count;
}

// Merge sort and count reverse pairs
int mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);
    return count;
}

int countReversePairs(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

// Example usage and test case
int main() {
    vector<int> arr = {2, 4, 3, 5, 1};
    cout << "Number of reverse pairs: " << countReversePairs(arr) << endl;
}
