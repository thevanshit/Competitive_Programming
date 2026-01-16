#include <iostream>
#include <vector>
using namespace std;

int main (){

    vector <int> vec;
    vec = {1,2,3,4,5};
    
    for (vector <int> :: iterator Itr = vec.begin(); Itr != vec.end(); Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;

     
    for (auto Itr = vec.begin(); Itr != vec.end(); Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;

    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    cout << endl;

    vec.erase(vec.begin());
    vec.erase(vec.begin() + 1 , vec.end());
    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    
    return 0;
}