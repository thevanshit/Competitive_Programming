#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    unordered_map <char, int> freq;
    for(char ch : s){
        freq[ch]++;
    }
    int odd_freq = 0;
    for(auto &p : freq){
        if (p.second % 2 == 1){
            odd_freq++;
        }
    }

    if (odd_freq <= k + 1){
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}