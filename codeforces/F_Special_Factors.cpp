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

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0 && (i % 10 == 2 || i % 10 == 7)){
            cout << i << " ";
            cnt++;
        }
    }
    if(cnt == 0) cout << -1;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}