#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}


int FindLongestSequence(vector<int> &vec) {
    
    sort (vec.begin(),vec.end());
    int longest = 1;
    int currcnt = 0;
    int lastnum = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == lastnum + 1){
            currcnt++;
            lastnum = vec[i];
        }
        else if (vec[i] != lastnum){
            currcnt = 1;
            lastnum = vec[i];
        }
        longest = max(longest,currcnt);
    }
    
    return longest;
}

int main() {
    vector<int> vec = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    int LongSequence;
    LongSequence = FindLongestSequence(vec);

    cout << "The Longest Sequence in the Array is : " << LongSequence << endl;;
    return 0;
}