#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to print the array
void PrintTheArray(const vector<int>& vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

vector<int> RemoveDuplicates(vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> result;

    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            result.push_back(num);
            seen.insert(num);
        }
    }

    return result;
}

int main() {
    vector<int> vec = {1, 1, 2, 2, 3, 3, 3, 4, 1, 2, 3};

    cout << "The Given Vector Array is: " << endl;
    PrintTheArray(vec);

    // Remove duplicates while keeping order
    vector<int> UniqueVec = RemoveDuplicates(vec);

    cout << "\nAfter Removing Duplicate Elements (Order Preserved):" << endl;
    PrintTheArray(UniqueVec);

    cout << "\nTotal Unique Elements: " << UniqueVec.size() << endl;

    return 0;
}