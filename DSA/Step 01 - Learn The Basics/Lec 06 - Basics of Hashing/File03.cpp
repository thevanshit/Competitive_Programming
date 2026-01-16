#include <iostream>
#include <vector>
using namespace std;

// Brute-force function to count frequency of a character in string
int QueryFind(const string &str, char query) {
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == query) {
            count++;
        }
    }
    return count;
}

// Function to print the frequency array
void PrintTheArray(const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    // Step 1: Given string
    string str = "abcdabefc";
    cout << "The Given String is:\n" << str << endl;

    // Step 2: List of characters to be queried
    vector<char> QueryVec = {'a', 'c', 'z'};

    // Step 3: Resultant frequency array
    vector<int> HashVec;

    // Step 4: Brute-force frequency computation for each query
    for (int i = 0; i < QueryVec.size(); i++) {
        char queryChar = QueryVec[i];
        int frequency = QueryFind(str, queryChar);
        HashVec.push_back(frequency);
    }

    // Step 5: Output the frequency array
    cout << "The Hash Array (Frequency of Queries) is:\n";
    PrintTheArray(HashVec);

    return 0;
}