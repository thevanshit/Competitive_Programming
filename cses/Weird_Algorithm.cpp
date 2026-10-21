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
    ll n; cin >> n;
    while(true){
        cout << n << ' ';
        if(n == 1) break;
        if(n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}