#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
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
    int l;
    for (int i = 1; i <= 2 * n - 1; i++) {
        int l;
        if (i <= n)
            l = i;
        else
            l = 2 * n - i;

        int sp = l - 1;
        int arr = 2 * l - 1;

        for (int j = 1; j <= sp; j++) {
            cout << " ";
        }

        for (int j = 1; j <= arr; j++) {
            if (j == 1 || j == arr) {
                cout << ">";
            } 
            else {
                cout << " ";
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}