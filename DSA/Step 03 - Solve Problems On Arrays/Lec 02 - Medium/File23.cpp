// Kadane 's Algorithm : 

#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray (vector <int> &vec){
    for(auto It : vec){
        cout << It << " ";
    }
    cout << endl;
}

vector <int> MaximumSumSubarray(vector<int> &vec) {
    int maxsum = INT_MIN;
    int sum = 0;
    int ansstart = -1;
    int ansend = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        int start;
        if (sum == 0){
            start = i;
        }
        sum += vec[i];
        if (sum > maxsum)
        {
            maxsum = sum;
            ansstart = start;
            ansend = i;
        }
        if (sum < 0){
            sum = 0;
        }
    }
    vector <int> result;
    for (int i = ansstart; i <= ansend; i++)
    {
        result.push_back(vec[i]);
    }
    
    
    return result;
}

int main()
{
    vector <int> vec;
    vec = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    MaximumSumSubarray(vec);

    vector <int> MaxiSumSubArray;
    MaxiSumSubArray = MaximumSumSubarray(vec);
    cout << "The Maximum SubArray sum in the given Vector Array is : " << endl;
    PrintTheArray(MaxiSumSubArray);
    return 0;
}
