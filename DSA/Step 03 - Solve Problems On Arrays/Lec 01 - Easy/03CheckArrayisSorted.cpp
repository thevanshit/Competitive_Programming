#include <iostream>
#include <vector>
using namespace std;

void CheckArrayisSorted (vector <int> &vec){

    bool check = true;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i-1] > vec[i]){
            check = false;
            break;
        }
    }
    if (check == true)
    cout << "The Array is Sorted." << endl;
    if (check == false)
    cout << "The Array is NOT Sorted." << endl;
}


int main () {

    vector <int> vec;
    vec = {1, 4, 5, 3, 7, 7, 6};

    vector <int> vec_sorted;
    vec_sorted = {1, 3, 4, 5, 6, 7, 7};

    CheckArrayisSorted(vec);
    CheckArrayisSorted(vec_sorted);

    return 0;
}