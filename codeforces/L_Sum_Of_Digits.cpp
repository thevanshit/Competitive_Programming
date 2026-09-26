#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve()
{
    ll n;
    cin >> n;

    ll s = 0;
    while (n > 0)
    {
        s += (n % 10);
        n /= 10;
    }
    cout << s << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}