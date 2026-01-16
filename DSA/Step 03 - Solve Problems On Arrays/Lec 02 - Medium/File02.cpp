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

void PrintTheArrayPairs(vector<pair<int, int>> vec) {
    for (auto Itr : vec) {
        cout << "(" << Itr.first << ", " << Itr.second << ")" << endl;
    }
}

vector <pair <int,int>> GivePairs(vector <int> &vec,int Target){

    map <int,int> HashMap;
    vector <pair<int,int>> Result;

    for (int i = 0; i < vec.size(); i++)
    {
        int have = vec[i];
        int more = Target - have;
        if (HashMap.find(more) != HashMap.end())
        {
            Result.push_back({HashMap[more],i});
        }
        HashMap[have] = i;
    }
    
    
    return Result;
}

int main (){


    vector <int> vec;
    vec = {1, 4, 5, 8, 10, 7, 3, 12, 2, 9, 6};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Key = 12;

    vector <pair<int,int>> Result;
    Result = GivePairs(vec,Key);

    cout << "The Pairs of the Elements Suming up to the Target from the array is : " << endl;
    PrintTheArrayPairs(Result);
    
}