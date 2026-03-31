#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    vector <long long> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    for (long long d = 1; d <= n; d++){
        if(n % d == 0){
            long long mx = -1e18;
            long long mn = 1e18;
            for(long long i = 0; i < n; i += d){
                long long sum = 0; 
                for(long long j = i; j < i + d; j++){
                    sum += a[j];
                }
                mx = max(mx, sum);
                mn = min(mn, sum);
            }
            ans = max(ans, mx - mn);
        }
    }
    cout << ans << "\n";
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