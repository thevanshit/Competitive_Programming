#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

vector<int> SPF(MAX_N + 1, 1);

class Solution{
private:
    void sieve() {
        for (int i = 2; i <= MAX_N; i++) {
            if (SPF[i] == 1) {
                for (int j = i; j <= MAX_N; j += i) {
                    if (SPF[j]== 1) {
                        SPF[j] = i;
                    }
                }
            }
        }
        return;
    }
    vector<int> primeFact(int n) { 
        vector<int> ans;
        while (n != 1) {
            ans.push_back(SPF[n]);
            n = n / SPF[n];
        }
        return ans;
    } 
    
public:
    vector<vector<int>> primeFactors(vector<int>& queries){
        sieve();
        vector<vector<int>> ans;

        for(int i=0; i < queries.size(); i++) {
            ans.push_back(primeFact(queries[i]));
        }
        return ans;
    }
};

int main() {
    vector<int> queries = {7, 12, 9, 45, 32};

    Solution sol; 

    vector<vector<int>> ans = sol.primeFactors(queries);
    
    cout << "The prime factorization of all the numbers is: " << endl;
    for(int i=0; i < ans.size(); i++) {
        cout << "For " << queries[i] << ": "; 
        for(int j=0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}