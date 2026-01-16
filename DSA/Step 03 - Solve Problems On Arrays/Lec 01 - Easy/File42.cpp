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

    int maxi = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        maxi = max(maxi,vec[i]);
    }
    vector <int> HashArray(maxi,0);
    for (int i = 0; i < vec.size(); i++)
    {
        HashArray[vec[i]]++;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (HashArray[vec[i]] == 1)
        {
            return vec[i];
        }
        
    }
    
    
    return -1;
}

int main (){


    vector <int> vec;
    vec = {1, 1, 0, 0, 2, 3, 3, 4, 5, 5, 4};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Result;
    Result = MaxOne(vec);

    cout << "The Element Occuring Once from the array is : " << Result << endl;
}