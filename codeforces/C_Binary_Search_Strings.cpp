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
    vector<string> a(n);
    for(auto &s : a) cin >> s;
    string x; cin >> x;
    int l = 0, r = n - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(a[m] == x){
            cout << "YES\n";
            return;
        }
        if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}