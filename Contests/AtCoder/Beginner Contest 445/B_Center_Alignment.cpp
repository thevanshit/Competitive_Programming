#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;

    long long m = 0;
    vector <string> S(n);
    for(long long i = 0; i < n; i++){
        cin >> S[i];
        m = max(m, (long long)S[i].length());
    }
    for(long long i = 0; i < n; i++){
        long long k = (m - S[i].size()) / 2;
        long long k_temp = k;
        while(k_temp--){
            cout << ".";
        }
        cout << S[i];
        while(k--){
            cout << ".";
        }
        cout << "\n";
    }
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