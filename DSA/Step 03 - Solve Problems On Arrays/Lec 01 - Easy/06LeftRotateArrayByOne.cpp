#include<iostream>
using namespace std;


void PrintTheArray(vector <int> vec){
    for (auto Itr : vec){
        cout << Itr << " ";
    }
    cout << endl;
}


void LeftRotateByOne(vector <int> &vec)
{
    int temp = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        vec[i-1] = vec[i];
    }
    vec[vec.size()-1] = temp;
    
}

int main() {

    vector <int> vec;
    vec = {1,4,5,7,6,5,3};
    cout << "The Given Array is : " << endl;
    PrintTheArray(vec);
    LeftRotateByOne(vec);

    cout << "The Given Array After Rotating is : " << endl;
    PrintTheArray(vec);

}
