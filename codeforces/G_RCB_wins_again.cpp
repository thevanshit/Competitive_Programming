#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector <int>;
using vll = vector <long long>;
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

    vi a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i - 1];
    }

    int l = (n / 2) - 1, r = (n / 2);
    while(l >= 0 && r < n) {
        cout << a[l] << " " << a[r] << " ";
        l--;
        r++;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}