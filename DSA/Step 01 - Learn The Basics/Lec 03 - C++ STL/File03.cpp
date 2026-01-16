#include <iostream>
#include <vector>
using namespace std;

int main (){

    vector <int> vec;
    vec = {1,2,3,4,5};
    vector <int> :: iterator Itr = vec.begin();
    Itr++;
    cout << *Itr << " ";

    Itr += 2;
    cout << *Itr << " ";

    cout << vec.back() << " ";

    return 0;
}