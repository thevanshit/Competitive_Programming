#include <iostream>
#include <vector>
#include <map>
using namespace std;

void PrintTheArray (vector <int> &vec){
    for(auto It : vec){
        cout << It << " ";
    }
    cout << endl;
}

int MaximumElement(vector<int> &vec) {
    int n;
    n = vec.size();
    unordered_map <int,int> hashmap;
    for (int i = 0; i < n; i++)
    {
        hashmap[vec[i]]++;
    }
    for (auto Itr : hashmap){
        if (Itr.second > n/2){
            return Itr.first;
        }
    }
    return -1;
}

int main()
{
    vector <int> vec;
    vec = {2, 2, 3, 3, 1, 2, 2};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    MaximumElement(vec);

    int MaxiElement;
    MaxiElement = MaximumElement(vec);
    cout << "The Element Occuring More than N/2 the given Vector Array is : " << MaxiElement << endl;
    return 0;
}
