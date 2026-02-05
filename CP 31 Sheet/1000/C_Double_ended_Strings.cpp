#include <bits/stdc++.h>
using namespace std;


void solve(){
    string a;
    string b;
    cin >> a >> b;
    long long a_size = a.size();
    long long b_size = b.size();
    long long ans = 0;
    for(long long len = 1; len <= min(a_size, b_size); len++){
        for(long long i = 0; i + len <= a_size; i++){
            for(long long j = 0; j + len <= b_size; j++){
                if (a.substr(i, len) == b.substr(j, len)){
                    ans = max(ans, len);
                }
            }
        }
    }
    cout << ((a_size + b_size) - (2 * ans)) << "\n";
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