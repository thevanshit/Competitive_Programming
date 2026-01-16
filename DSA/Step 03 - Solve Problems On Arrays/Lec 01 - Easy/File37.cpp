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

int FindTheMissingEle(vector <int> &vec){

    int sum = 0;
    int n = vec.size() + 1;
    int Cal_Sum = n*(n+1)/2;
    for (int i = 0; i < vec.size(); i++)
    {
        sum = sum + vec[i];
    }
    
    
    
    return Cal_Sum - sum;
}

int main (){


    vector <int> vec;
    vec = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Result;
    Result = FindTheMissingEle(vec);

    cout << "The Missing Element from the array is : " << Result << endl;
}