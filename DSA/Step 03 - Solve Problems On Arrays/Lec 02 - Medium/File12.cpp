#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray (vector <int> &vec){
    for(auto It : vec){
        cout << It << " ";
    }
    cout << endl;
}
void merge(vector<int>& arr, int left, int mid, int right) {
    // Sizes of two subarrays to merge
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temp arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr
    int i = 0, j = 0, k = left;  // Initial indexes

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Copy remaining elements of L[] (if any)
    while (i < n1) arr[k++] = L[i++];

    // Copy remaining elements of R[] (if any)
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;  // Base case: 1 element

    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

int main()
{
    vector <int> vec;
    vec = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    mergeSort(vec,0,vec.size()-1);

    cout << "The (after sorting) the given Vector Array is : " << endl;
    PrintTheArray(vec);
    return 0;
}
