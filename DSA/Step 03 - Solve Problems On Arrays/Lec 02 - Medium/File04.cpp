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

string GiveAns(vector <int> &vec,int Target){
    
    int left = 0;
    int right = vec.size()-1;
    sort(vec.begin(),vec.end());
    while(left < right){
        int sum = vec[left] + vec[right];
        if (sum == Target){
            return "YES";
        }
        else if (sum > Target)
        {
            right--;
        }
        else{
            left++;
        }
    }
    return "NO";
}

int main (){


    vector <int> vec;
    vec = {1, 4, 5, 8, 10, 7, 3, 12, 2, 9, 6};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    int Key = 12;

    string Result;
    Result = GiveAns(vec,Key);

    cout << "The Pairs of the Elements Suming up to the Target from the array exits ?  : " << Result << endl;
    
}