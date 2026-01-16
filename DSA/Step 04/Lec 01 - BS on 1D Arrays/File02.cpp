#include <iostream>
#include <vector>
using namespace std;

int BinarySearchRecursive(const vector <int> &arr,int left, int right, int target){

    if (left > right) return -1;
    int mid = left + (right - left) / 2;

    if (arr[mid] == target){
        return mid;
    }
    else if (arr[mid] < target){
        return BinarySearchRecursive(arr,mid+1,right,target);
    }
    else {
        return BinarySearchRecursive(arr,left,mid - 1,target);
    }
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    return BinarySearchRecursive(arr,left,right,target);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 12, 15};
    int target = 12;
    int idx = binarySearch(arr, target);
    if (idx != -1)
        cout << "Found at index " << idx << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
