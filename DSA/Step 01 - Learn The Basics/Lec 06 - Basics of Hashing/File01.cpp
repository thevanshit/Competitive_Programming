// Hashing....
// Query...
// Array... On Which Query has to be perform....
# include <iostream>
using namespace std;

void PrintTheArray (vector <int> &vec){

    for (auto val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}

int QueryFind(vector <int> &vec,int Query){

    int count = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == Query)
        {
            count += 1;
        }
        
    }
    return count;
}

int main (){

    vector <int> vec;
    vec = {1, 2, 1, 3, 2};

    cout << "The Given Array is : " << endl;

    PrintTheArray (vec);

    vector <int> QueryVec;
    QueryVec = {1, 3, 4, 2, 10};

    cout << "The Given Query Array is : " << endl;

    PrintTheArray (QueryVec);

    vector <int> HashVec;

    for (int i = 0; i < QueryVec.size(); i++)
    {
        int Element;
        Element = QueryFind(vec,QueryVec[i]);
        HashVec.push_back(Element);
    }
    
    cout << "The Hash Array of the Given Array is : " << endl;

    PrintTheArray(HashVec);
}