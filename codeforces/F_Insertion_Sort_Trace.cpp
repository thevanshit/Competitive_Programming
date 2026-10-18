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
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        int sh = 0;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            sh++;
        }
        a[j + 1] = key;
        cout << "Pass " << i << ": ";
        for (int k = 0; k < n; k++) {
            if (k > 0) cout << " ";
            cout << a[k];
        }
        cout << " , ";
        for (int k = 0; k <= i; k++) {
            if (k > 0) cout << " ";
            cout << a[k];
        }
        cout << " |";
        if (i + 1 < n) cout << " ";
        for (int k = i + 1; k < n; k++) {
            if (k > i + 1) cout << " ";
            cout << a[k];
        }
        cout << " , shifts = " << sh << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}