#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> vec) {
    for (auto Itr = vec.begin(); Itr < vec.end(); Itr++) {
        cout << *Itr << " ";
    }
    cout << endl;
}

void InsertionSort(vector<int> &vec) {
    
    for (int i = 1; i < vec.size(); i++) {
        
        int j = i;
        while (j>0 && vec[j-1] > vec[j]){
            swap(vec[j],vec[j-1]);
            j--;
        }
    }
}

int main() {
    vector<int> vec = {13, 46, 24, 52, 20, 9};

    cout << "Before Insertion Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);

    InsertionSort(vec);

    cout << "After Insertion Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);

    return 0;
}