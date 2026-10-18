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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int midx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[midx]) {
                midx = j;
            }
        }
        swap(a[i], a[midx]);
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k];

            if (k < n - 1) {
                cout << " ";
            }
        }
        cout << " , min_selected = " << a[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}