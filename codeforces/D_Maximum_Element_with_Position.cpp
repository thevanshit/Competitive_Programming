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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = *max_element(all(a));
    for (int i = 0; i < n; i++) {
        if(a[i] == mx){
            cout << mx << " " << i + 1 << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}