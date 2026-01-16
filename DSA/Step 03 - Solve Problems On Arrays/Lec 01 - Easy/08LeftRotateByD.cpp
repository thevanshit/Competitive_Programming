#include<iostream>
using namespace std;


void PrintTheArray(vector <int> vec){
    for (auto Itr : vec){
        cout << Itr << " ";
    }
    cout << endl;
}


void LeftRotateByD(vector <int> &vec,int D)
{

    if (vec.size() == 0 || D == 0 || D % vec.size() == 0) return;
    
    D = D % vec.size(); // In case D > n

    reverse(vec.begin(),vec.begin()+D);
    reverse(vec.begin()+D,vec.end());
    reverse(vec.begin(),vec.end());
}

int main() {

    int D;
    D = 3;
    vector <int> vec;
    vec = {1,4,5,7,6,5,3};
    cout << "The Given Array is : " << endl;
    PrintTheArray(vec);
    LeftRotateByD(vec,D);

    cout << "The Given Array After Rotating is : " << endl;
    PrintTheArray(vec);

}
