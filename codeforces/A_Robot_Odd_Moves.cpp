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
    int a, b;
    cin >> a >> b;

    if(b <= a && ((a ^ b) & 1) == 0){
        cout << a << '\n';
    }
    else if(b <= a + 1 && (((a + 1) ^ b) & 1) == 0){
        cout << a + 1 << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}