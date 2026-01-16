#include <iostream>
#include <vector>
#include <set>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

set <int> FindLeaders(vector<int> &vec) {
    
    set <int> ans;
    int maxelement = INT_MIN;
    for (int i = vec.size()-1; i >= 0; i--)
    {
        if (vec[i] > maxelement){
            maxelement = vec[i];
            ans.insert(maxelement);
        }
    }
    
    return ans;
}

int main() {
    vector<int> vec = {10, 22, 12, 3, 0, 6};

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    set <int> leaders;
    leaders = FindLeaders(vec);

    cout << "The leaders of the Arrays are :\n";
    for (auto It : leaders){
        cout << It << " ";
    }
    cout << endl;
    return 0;
}