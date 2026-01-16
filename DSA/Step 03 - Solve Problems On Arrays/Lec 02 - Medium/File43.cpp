#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

int NoOfSubarraySum(vector<int> &vec, int target) {
    
    int count = 0;
    int presum = 0;
    unordered_map <int,int> mpp;
    mpp[0] = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        presum += vec[i];
        int remove = presum - target;
        count += mpp[remove];
        mpp[presum] += 1;
    }
    
    
    return count;
}

int main() {
    vector<int> vec = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

    int target = 3;
    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    int Count;
    Count = NoOfSubarraySum(vec,target);

    cout << "The Subarray with sum (k) in the Array is : " << Count<< endl;;
    return 0;
}