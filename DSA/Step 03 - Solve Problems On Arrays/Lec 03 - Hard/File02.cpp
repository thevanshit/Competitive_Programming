#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void PrintTheVec(vector<int> &vec) {
    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

vector<int> PrintTheRow(vector<int> &vec) {
    vector<int> res;
    int n = vec.size();

    unordered_map <int,int> hashmap;

    int min = n/3;
    for (auto it : vec)
    {
        hashmap[it]++;

        if (hashmap[it] > min){
            res.push_back(it);
        }
        if (res.size() == min){
        break;
    }
    }
    return res;
}

int main() {
    vector<int> vec = {1, 3, 1, 1, 3, 3, 2, 2};
    cout << "The Given Vector Array is : ";
    PrintTheVec(vec);

    vector<int> res = PrintTheRow(vec);

    cout << "Elements that appear more than n/3 times are : ";
    PrintTheVec(res);
    return 0;
}