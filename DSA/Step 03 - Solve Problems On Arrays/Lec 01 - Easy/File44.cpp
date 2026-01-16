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

int MaxOne(vector <int> &vec){

    unordered_map <int,int> HashArray;
    for (int i = 0; i < vec.size(); i++)
    {
        HashArray[vec[i]]++;
    }
    for (auto it : HashArray)
    {
        if (it.second == 1)
        {
            return it.first;
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