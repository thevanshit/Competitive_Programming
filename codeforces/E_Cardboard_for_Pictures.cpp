#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    long long n, c; 
    cin >> n >> c;

    vi a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long l = 1;
    long long r = 1e9;
    
    while(l <= r){
        long long m = l + (r - l) / 2;
        long long sum = 0; 
        for(long long i = 0; i < n; i++){
            sum += (a[i] + 2 * m) * (a[i] + 2 * m);
            if(sum > c) break;
        }
        if(sum == c){
            cout << m << "\n";
            return;
        }
        if(sum > c){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    cin >> t;
    while (t--) solve();
}