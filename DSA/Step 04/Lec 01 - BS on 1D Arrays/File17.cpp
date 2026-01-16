#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(const vector<int>& arr) {
    if (arr.size() == 1){
        return arr[0];
    }
    else {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if(i == 0){
                if (arr[i] != arr[i+1]){
                    return arr[i];
                }
            }
            if(i == arr.size()-1){
                if (arr[i-1] != arr[i]){
                    return arr[i];
                }
            }
            else{
                if ((arr[i] != arr[i-1]) && (arr[i] != arr[i+1])){
                    return arr[i];
                }
            }
        }
        
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8}; // Single element is 2
    cout << "Single non-duplicate element is: " << singleNonDuplicate(arr) << endl;
    return 0;
}
