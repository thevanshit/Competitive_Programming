#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

void NextPermutation(vector<int> &vec) {
    
    next_permutation(vec.begin(),vec.end());

}

int main() {
    vector<int> vec = {2, 1, 5, 4, 3, 0, 0};

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    NextPermutation(vec);

    cout << "The Next Permutation is:\n";
    PrintTheArray(vec);
    return 0;
}