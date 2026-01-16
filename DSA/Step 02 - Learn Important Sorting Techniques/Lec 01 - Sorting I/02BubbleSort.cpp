#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> vec) {
    for (auto Itr = vec.begin(); Itr < vec.end(); Itr++) {
        cout << *Itr << " ";
    }
    cout << endl;
}

void BubbleSort(vector<int> &vec) {
    for (int i = vec.size() - 1; i > 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> vec = {13, 46, 24, 52, 20, 9};

    cout << "Before Bubble Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);

    BubbleSort(vec);

    cout << "After Bubble Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);

    return 0;
}