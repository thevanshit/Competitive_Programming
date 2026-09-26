#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << "Min = " << min(a, (min(b, c))) << "\n";
    cout << "Max = " << max(a, (max(b, c))) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}