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
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0){
            cnt0++;
        }
        else if (vec[i] == 1){
            cnt1++;
        }
        else {
            cnt2++;
        }
    }
    
    for (int i = 0; i < cnt0; i++)
    {
        vec[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
        vec[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < vec.size(); i++)
    {
        vec[i] = 2;
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
