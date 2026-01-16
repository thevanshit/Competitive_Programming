#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

int FindLongestSequence(vector<int> &vec) {
    
    int longest = 1;
    unordered_set <int> st;

    for (int i = 0; i < vec.size(); i++)
    {
        st.insert(vec[i]);
    }

    for(auto it : st){
        if (st.find(it - 1) == st.end()){
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end()){
                count++;
                x++;
            }
            longest = max (longest,count);
        }
    }
    return longest;
    
}

int main() {
    vector<int> vec = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    int LongSequence;
    LongSequence = FindLongestSequence(vec);

    cout << "The Longest Sequence in the Array is : " << LongSequence << endl;;
    return 0;
}