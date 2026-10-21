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

struct BIT{
    int n;
    vi t;
    BIT(int n) : n(n), t(n + 1, 0){}
    void add(int i, int d){
        for(; i <= n; i += i & -i) t[i] += d;
    }
    int qry(int i){
        int s = 0; 
        for(; i > 0; i -= i & -i) s += t[i];
        return s;
    }
};

void solve() {
    int n; ll k;
    cin >> n >> k;
    vi p(n);
    for(int &x : p) cin >> x;
    if(k == 1){
        for(int i = 0; i < n; i++){
            if(p[i] != n - i){
                cout << -1 << '\n';
                return;
            }
        }
        cout << 0 << '\n';
        return;
    }
    BIT bit(n);
    ll an = 0, jmp = k - 1;
    for(int x : p){
        ll lx = bit.qry(x - 1);
        an += (lx + jmp - 1) / jmp;
        bit.add(x, 1);
    }
    cout << an << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}