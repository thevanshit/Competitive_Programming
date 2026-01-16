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

    for (int i = 0; i < vec.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[i] == vec[j])
            {
                cnt++;
            }
        }
        if (cnt == 1){
            return vec[i];
            break;
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