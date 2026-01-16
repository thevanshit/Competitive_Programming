#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray (vector <int> &vec) {
    cout << "The Vector Array is : ";
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

void ReverseTheArray(vector <int> &vec, int start, int end) {
    // Base Case
    if (start >= end) {
        return;
    }

    // Swap the elements
    swap(vec[start], vec[end]);

    // Recursive call
    ReverseTheArray(vec, start + 1, end - 1);
}

int main () {
    vector <int> vec = {2, 4, 5, 6, 8, 5};
    int start = 0;
    int end = vec.size() - 1;

    ReverseTheArray(vec, start, end);

    PrintTheArray(vec);  // Output after reversing

    return 0;
}