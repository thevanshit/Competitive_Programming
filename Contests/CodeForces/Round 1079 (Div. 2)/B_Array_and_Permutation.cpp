#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;

    vector<long long> p(n), a(n);
    for(long long i = 0; i < n; i++) cin >> p[i];
    for(long long i = 0; i < n; i++) cin >> a[i];

    vector<long long> pos(n+1);
    for(long long i = 0; i < n; i++) {
        pos[p[i]] = i;
    }

    for(int i = 0; i < n-1; i++) {
        if(pos[a[i]] > pos[a[i+1]]) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
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