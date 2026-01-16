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
    sort(vec.begin(),vec.end());
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
