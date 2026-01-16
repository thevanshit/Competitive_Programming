#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    int gap = ceil((float)(n + m) / 2);

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < n + m) {
            int a, b;
            
            // i in arr1
            if (i < n) a = arr1[i];
            else a = arr2[i - n];

            // j in arr1 or arr2
            if (j < n) b = arr1[j];
            else b = arr2[j - n];

            if (a > b) {
                // Swap accordingly
                if (i < n && j < n)
                    swap(arr1[i], arr1[j]);
                else if (i < n && j >= n)
                    swap(arr1[i], arr2[j - n]);
                else
                    swap(arr2[i - n], arr2[j - n]);
            }

            i++; j++;
        }

        if (gap == 1) break;
        gap = ceil((float)gap / 2);
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