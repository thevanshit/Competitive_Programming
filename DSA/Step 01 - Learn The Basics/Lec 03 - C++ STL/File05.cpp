#include <iostream>
#include <vector>
using namespace std;

int main (){

    vector <int> vec;
    vec = {1,2,3,4,5,6,7,8,9};
    
    vec.insert(vec.end(),10);
    vec.insert(vec.end()-1,2,9);
    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    
    return 0;
}