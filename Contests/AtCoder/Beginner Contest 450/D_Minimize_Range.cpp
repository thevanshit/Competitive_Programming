#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n, k;
    cin >> n >> k;
    vector <long long> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> r(n);
    for (long long i = 0; i < n; i++) {
        r[i] = a[i] % k;
    }
    sort(r.begin(), r.end());
    vector<long long> extended(2 * n);
    for (long long i = 0; i < n; i++) {
        extended[i] = r[i];
        extended[i + n] = r[i] + k;
    }
    long long ans = LLONG_MAX;
    for (long long i = 0; i < n; i++) {
        ans = min(ans, extended[i + n - 1] - extended[i]);
    }
    cout << ans << "\n";
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}