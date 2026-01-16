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

void LinearSearch(vector <int> &vec,int Key){

    int count = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == Key){
            cout << "Element has Found In the Array : " << i << endl;
            count++;
            break;
        }
        
    }
    if (count == -1)
    cout << "Element has NOT Found In the Array : " << count << endl;
}

int main (){

    int Key;
    cout << "Enter the value of the key : ";
    cin >> Key;

    vector <int> vec;
    vec = {1, 3, 5, 8, 9, 4, 10};
    PrintTheArray(vec);

    LinearSearch(vec,Key);
}