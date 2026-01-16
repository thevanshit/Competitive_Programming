#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray (vector <int> &vec){
    for(auto It : vec){
        cout << It << " ";
    }
    cout << endl;
}

void Sort0s1sAnd2s(vector<int> &vec) {
    // Dutch National Flag Algorithm : 

    int low = 0;
    int mid = 0;
    int high = vec.size()-1;

    while (mid <= high){

        if (vec[mid] == 0){
            swap(vec[mid],vec[low]);
            low++;
            mid++;
        }
        else if (vec[mid] == 1){
            mid++;
        }
        else {
            swap(vec[mid],vec[high]);
            high--;
        }
    }
}

int main()
{
    vector <int> vec;
    vec = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    Sort0s1sAnd2s(vec);

    cout << "The (after sorting) the given Vector Array is : " << endl;
    PrintTheArray(vec);
    return 0;
}
