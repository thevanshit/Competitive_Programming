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

int MaxOne(vector <int> &vec){

    int XOR;
    XOR = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        XOR ^= vec[i];
    }
    
    
    return XOR;
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