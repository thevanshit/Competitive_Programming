#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    long long k;
    cin >> n >> k;

    vector <long long> a(n);
    for(long long &x : a){
        cin >> x;
        x = x % k;
        if (!x) x = k; 
    }

    vector <long long> order(n);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](long long x, long long y){
        return a[x] > a[y];
    });

    for(auto &x : order) cout << x + 1 << " ";
    cout << "\n";
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