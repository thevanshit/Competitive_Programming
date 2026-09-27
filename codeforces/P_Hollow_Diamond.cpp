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
    int n;
    cin >> n;

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int st = i <= n ? i : 2 * n - i;
        int sp = n - st;

        for (int j = 1; j <= sp; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= st; j++)
        {
            if (j == st) cout << "*";
            else if (j == 1) cout << "* ";
            else cout << "  ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}