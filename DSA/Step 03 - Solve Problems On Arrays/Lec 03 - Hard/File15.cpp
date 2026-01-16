#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void SwapIfGreater (vector<int> &arr1, vector<int> &arr2, int idx1, int idx2){
    if (arr1[idx1] > arr2[idx2]){
        swap(arr1[idx1],arr2[idx2]);
    }
}

void merge(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    int len = (n + m);
    int gap = ceil(float(len/2));

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len){
            // Arr1 and Arr2 : 
            if (left < n && right >= n){
                SwapIfGreater(arr1,arr2,left,right - n);
            }
            // Arr2 and Arr2 :
            else if (left >= n){
                SwapIfGreater(arr2,arr2,left - n,right - n);
            }
            // Arr1 and Arr1 : 
            else {
                SwapIfGreater(arr1,arr1,left,right);
            }
            left++; right++;
        }
        if (gap == 1) break;
        gap = ceil(float(gap/2));
    }
    
}

int main() {
    vector<int> arr1 = {1, 4, 7, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    merge(arr1, arr2, arr1.size(), arr2.size());

    cout << "Merged arrays:\n";
    for (int val : arr1) cout << val << " ";
    for (int val : arr2) cout << val << " ";

    return 0;
}