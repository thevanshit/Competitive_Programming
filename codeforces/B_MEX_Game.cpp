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
    cin >> n >> k;

    vi cnt(n + 1, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }

    int v = 0;
    while(cnt[v] >= 2 * k){
        v++;
    }

    if(cnt[v] == 2 * k - 1){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}