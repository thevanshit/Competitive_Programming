#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void PrintTheVec(vector<int> &vec) {
    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

int GetCount(vector<int> &vec, int target) {

    int maxcount = 0;
    map <int,int> hashmap;
    int xr = 0;
    hashmap[xr]++;
    for (int i = 0; i < vec.size(); i++)
    {
        xr ^= vec[i];
        int x = xr ^ target;
        maxcount += hashmap[x];
        hashmap[xr]++;
    }
    
    return maxcount;
    
}

int main() {
    int target = 6;

    vector<int> vec = {4, 2, 2, 6, 4};
    cout << "The Given Vector Array is : " << endl;
    PrintTheVec(vec);

    int count = GetCount(vec,target);

    cout << "Get Count of the XOR of the target Given SubArrays : " << count << endl;
    return 0;
}