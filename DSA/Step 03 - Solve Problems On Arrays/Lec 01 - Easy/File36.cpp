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

    vector <int> HashArray(vec.size() + 2,0);
    for (int i = 0; i < vec.size(); i++)
    {
        HashArray[vec[i]] = 1;
    }

    for (int i = 1; i < HashArray.size(); i++)
    {
        if(HashArray[i] == 0){
            return i;
        }
    }
    
    
    return 0;
}

int main (){


    vector <int> vec;
    vec = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Result;
    Result = FindTheMissingEle(vec);

    cout << "The Missing Element from the array is : " << Result << endl;
}