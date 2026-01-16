#include <iostream>
#include <vector>
#include <map>
using namespace std;

void PrintTheArray(vector <int> vec){

    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    cout << endl;
}
int LongestSubArray(vector <int> &vec,int Key){

    int maxlen = 0;
    map <long long,int> HashMap;
    long long sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
        if (sum == Key)
        {
            maxlen = max(maxlen,i+1);
        }
        long long rem = sum - Key;
        if (HashMap.find(rem) != HashMap.end())
        {
            int len = i - HashMap[rem];
            maxlen = max(maxlen,len);
        }
        if (HashMap.find(sum) != HashMap.end())
        {
            HashMap[sum] = i;
        }
        
        
    }
    
    
    return maxlen;
}

int main (){


    vector <int> vec;
    vec = {1, 1, 0, 0, 2, 3, 3, 4, 5, 5, 4};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Key = 4;

    int Result;
    Result = LongestSubArray(vec,Key);

    cout << "The SubArray Containing Key as Sum from the array is : " << Result << endl;
}