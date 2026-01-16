#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

int NoOfSubarraySum(vector<int> &vec, int target) {
    
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < vec.size(); j++)
        {
            sum += vec[j];
            if (sum == target){
                count++;
            }
        }
        
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