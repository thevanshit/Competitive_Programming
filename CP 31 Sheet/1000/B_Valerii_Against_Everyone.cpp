#include <bits/stdc++.h>
using namespace std;



void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);

    for(long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(long long i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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