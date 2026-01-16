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

int FindTheMissingEle(vector <int> &vec){

    int XOR1 = 0;
    int XOR2 = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        XOR2 ^= vec[i];
        XOR1 ^= (i+1);
    }
    XOR1 ^= (vec.size()+1);
    
    
    return XOR1 ^ XOR2;
}

int main (){


    vector <int> vec;
    vec = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Result;
    Result = FindTheMissingEle(vec);

    cout << "The Missing Element from the array is : " << Result << endl;
}