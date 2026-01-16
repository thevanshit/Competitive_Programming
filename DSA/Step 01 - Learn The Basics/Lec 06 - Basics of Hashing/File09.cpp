#include <iostream>
#include <vector>
using namespace std;

int QueryCheck (vector <int> &vec,int Query){

    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == Query)
        {
            count++;
        }
        
    }
    return count;
}

void PrintTheArray (vector <int> vec){

    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    cout << endl;
}

int main (){

    vector <int> vec;
    vec = {10,5,10,15,10,5};

    cout << "The Given Array is : " << endl;

    PrintTheArray(vec);

    int n;
    cout << "Enter the Query Number : ";
    cin >> n;

    while (n--){
        int Query;
        cout << "Enter the No. Whose frequency you have to found : ";
        cin >> Query;

        int CountQuery;
        CountQuery = QueryCheck(vec,Query);

        cout << "The Frequency of the number " << Query << " is : " << CountQuery << endl;
    }
}