#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int i = 0;

    while (i < n) {
        long long mn = a[i], mx = a[i];
        int j = i + 1;

        while (j < n) {
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);

            if (mx - mn > k) {
                ans++;
                break; 
            }
            j++;
        }
        i = j + 1;
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