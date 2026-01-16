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

    for (int i = 1; i <= vec.size() + 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j] == i){
                flag = true;
                break;
            }
        }
        if (flag == false){
            return i;
        }
    }
    return 0;
}

int main (){


    vector <int> vec;
    vec = {1, 2, 3, 4, 5, 7, 8};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Result;
    Result = FindTheMissingEle(vec);

    cout << "The Missing Element from the array is : " << Result << endl;
}