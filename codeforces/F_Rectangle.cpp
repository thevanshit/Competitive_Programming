#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int l, b;
    cin >> l >> b;

    int a, p; 

    a = l * b;
    p = 2 * (l + b);

    cout << "Area = " << a << "\n";
    cout << "Perimeter = " << p << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}