#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

void ReverseTheArray(vector <int> &vec,int start,int end){

    while(start < end){
        swap(vec[start],vec[end]);
        start++;
        end--;
    }
}

void NextPermutation(vector<int> &vec) {
    
    int pivot = -1;
    for (int i = vec.size()-2; i >= 0; i--)
    {
        if (vec[i] < vec[i+1]){
            pivot = i;
            break;
        }
    }
    if (pivot == -1){
        ReverseTheArray(vec,0,vec.size()-1);
        return;
    }
    for (int i = vec.size()-1; i > pivot; i--)
    {
        if (vec[i] > vec[pivot]){
            swap(vec[i],vec[pivot]);
            break;
        }
    }
    ReverseTheArray(vec,pivot+1,vec.size()-1);
    
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