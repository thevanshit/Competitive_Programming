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
void MoveZero(vector <int> &vec) {
  
    int n = vec.size();

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (vec[i] != 0)
        {
            swap(vec[i],vec[j]);
            j++;
        }
        
    }
    if (j == n) {
        cout << "The array has no zeroes in it." << endl;
    }
    
}
int main() {
  
    vector <int> vec;
    vec = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    MoveZero(vec);

    cout << "After Moving Zeroes to end Given Vector Array is : " << endl;
    PrintTheArray(vec);
}