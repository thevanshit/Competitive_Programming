#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for(auto &x : a) cin >> x;

    int p = ((a[0] % 2) + 2) % 2;
    for(int i = 1; i < n; i++) {
        int q = ((a[i] % 2) + 2) % 2;
        if(q != p) {
            cout<<"No\n";
            return;
        }
    }

    if(n % 2 == 1) {
        cout<<"Yes\n";
        return;
    }

    long long alt = 0;
    for(int i=0;i<n;i++) {
        if(i%2==0) alt += a[i];
        else alt -= a[i];
    }

    if(((alt%2)+2)%2==0) cout<<"Yes\n";
    else cout<<"No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}
