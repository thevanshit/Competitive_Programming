#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n; 
    cin >> n;

    multiset <ll> s;

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;

        s.insert(x);

        if(sz(s) > 3){
            s.erase(s.begin());
        }

        if(i >= 2){
            cout << *s.begin() << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}