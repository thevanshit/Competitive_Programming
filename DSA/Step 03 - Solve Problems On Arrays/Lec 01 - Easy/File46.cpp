#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector <int> vec){

    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    cout << endl;
}
int LongestSubArray(vector <int> &vec,int Key){

    int len = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int sum;
        sum = 0;
        for (int j = i; j < vec.size(); j++)
        {
            sum += vec[j];
            if (sum == Key)
            {
                len = max(len,j-i+1);
            }
        }
    }
    return len;
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