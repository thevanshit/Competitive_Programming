#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    long long x;

    cin >> n >> x;

    long long min = 0;
    long long max = 0;
    vector <long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++){
        max += ceil((a[i] * 1.0) / x);
        min += a[i];
    }
    min = ceil((min * 1.0) / x);

    cout << min << " " << max << endl;
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