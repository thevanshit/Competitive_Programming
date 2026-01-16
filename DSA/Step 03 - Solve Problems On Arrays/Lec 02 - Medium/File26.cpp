#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

void AlternativeSort(vector<int> &vec) {
    
    vector <int> posvec;
    vector <int> negvec;
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i] > 0){
            posvec.push_back(vec[i]);
        }
        else if(vec[i] < 0){
            negvec.push_back(vec[i]);
        }
    }
    for (int i = 0; i < vec.size()/2; i++)
    {
        vec[2*i] = posvec[i];
        vec[2*i+1] = negvec[i];
    }
    
}

int main() {
    vector<int> vec = {3, 1, -2, -5, 2, -4};

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    AlternativeSort(vec);

    cout << "The given Vector Array (After Alternative Sort) is:\n";
    PrintTheArray(vec);
    return 0;
}