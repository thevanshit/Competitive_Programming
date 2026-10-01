#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

void solve() {
    int n;
    cin >> n;

    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i] -= i;
    }

    sort(all(v));

    int mxfreq = 0;
    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && v[j] == v[i]) j++;
        mxfreq = max(mxfreq, j - i);
        i = j;
    }
    cout << n - mxfreq << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}