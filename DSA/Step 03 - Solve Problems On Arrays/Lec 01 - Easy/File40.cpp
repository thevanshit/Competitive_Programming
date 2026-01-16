#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintTheArray(vector <int> vec){

    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    cout << endl;
}

int MaxOne(vector <int> &vec){

    int maxi;
    maxi = 0;
    int count = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 1)
        {
            count++;
            maxi = max(maxi,count);
        }
        else{
            count = 0;
        }
    }
    
    
    
    return maxi;
}

int main (){


    vector <int> vec;
    vec = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Result;
    Result = MaxOne(vec);

    cout << "The Max Iteration of Element (1) from the array is : " << Result << endl;
}