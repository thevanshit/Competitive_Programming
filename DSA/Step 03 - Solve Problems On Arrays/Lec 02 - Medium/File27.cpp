#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

vector <int> AlternativeSort(vector<int> &vec) {
    
    vector <int> ans(vec.size(),0);

    int pos_index = 0;
    int neg_index = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > 0){
            ans[pos_index] = vec[i];
            pos_index += 2;
        }
        else {
            ans[neg_index] = vec[i];
            neg_index += 2;
        }
    }
    

    return ans;
}

int main() {
    vector<int> vec = {3, 1, -2, -5, 2, -4};

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    AlternativeSort(vec);

    vector <int> ans;
    ans = AlternativeSort(vec);
    cout << "The given Vector Array (After Alternative Sort) is:\n";
    PrintTheArray(ans);
    return 0;
}