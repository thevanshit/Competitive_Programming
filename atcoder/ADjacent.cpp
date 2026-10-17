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
    int ra = 0, ca = 0, rd = 0, cd = 0;
    for(int i = 0; i < 2; i++){
        string s; cin >> s;
        for(int j = 0; j < 2; j++){
            if(s[j] == 'A') ra = i, ca = j;
            if(s[j] == 'D') rd = i, cd = j;
        }
    }
    if(abs(ra - rd) + abs(ca - cd) == 1) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}