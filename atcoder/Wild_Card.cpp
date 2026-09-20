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
    string s;
    string t;

    cin >> n >> s >> t;

    for(int i = 0; i < n; i++){
        if(t[i] != '*' && t[i] != s[i]){
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}