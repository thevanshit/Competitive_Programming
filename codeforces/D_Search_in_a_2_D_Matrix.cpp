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
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int el;
            cin >> el;
            if(el == k){
                cout << "true" << '\n';
                return;
            }
        }
    }
    cout << "false" << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}