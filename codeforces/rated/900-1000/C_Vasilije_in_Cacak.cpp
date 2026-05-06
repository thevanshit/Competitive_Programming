#include <bits/stdc++.h>
using namespace std;
 
 
void solve(){
    long long n;
    long long k;
    long long x;
    cin >> n >> k >> x;
 
    long long sum = k*(k + 1)/2;
    long long max_sum = (n*(n + 1)/2) - ((n - k) * (n - k + 1) / 2);
 
    if (x < sum || x > max_sum){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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