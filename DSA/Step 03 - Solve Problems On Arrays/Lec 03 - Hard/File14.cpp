#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m){
        if (arr1[left] > arr2[right]){
            swap (arr1[left],arr2[right]);
            left--;
            right++;
        }
        else break;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
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