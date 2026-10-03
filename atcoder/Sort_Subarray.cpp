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
    int n, k;
    if(!(cin >> n >> k)) return;

    vi a(n);
    for(int &x : a) cin >> x;

    vi s = a;
    sort(s.begin(), s.end());

    int l = 0;
    while(l < n && a[l] == s[l]) l++;

    if(l == n){
        cout << "Yes\n";
        return;
    }
    int r = n - 1;
    while(s[r] == a[r]) r--;

    if(r - l + 1 <= k) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}