#include <iostream>
#include <vector>
using namespace std;


int countReversePairs(vector<int>& arr) {
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            if (arr[i] > 2 * arr [j]){
                count++;
            }
        }
        
    }
    
    return count;
}

// Example usage and test case
int main() {
    vector<int> arr = {2, 4, 3, 5, 1};
    cout << "Number of reverse pairs: " << countReversePairs(arr) << endl;
}
