#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin >> s;

    long long n = s.size();

    char first = s[0];
    char last = s[n - 1];

    if (first == last) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}