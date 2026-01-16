#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray (vector <int> &vec){
    for(auto It : vec){
        cout << It << " ";
    }
    cout << endl;
}

int MaximumSumSubarray(vector<int> &vec) {
    int maxsum = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < vec.size(); j++)
        {
            sum += vec[j];
            maxsum = max(maxsum,sum);
        }
        
    }
    
    
    return maxsum;
}

int main()
{
    vector <int> vec;
    vec = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    MaximumSumSubarray(vec);

    int MaxiSumSubArray;
    MaxiSumSubArray = MaximumSumSubarray(vec);
    cout << "The Maximum SubArray Sum in the given Vector Array is : " << MaxiSumSubArray << endl;
    return 0;
}
