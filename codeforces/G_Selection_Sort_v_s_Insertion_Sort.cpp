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
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vi b = a;
    int sw = 0;
    for (int i = 0; i < n - 1; i++) {
        int midx = i;
        for (int j = i + 1; j < n; j++) {
            if (b[j] < b[midx]) {
                midx = j;
            }
        }

        if (midx != i) {
            swap(b[i], b[midx]);
            sw++;
        }
    }
    b = a;
    int sh = 0;
    for (int i = 1; i < n; i++) {
        int key = b[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            sh++;
            j--;
        }
        b[j + 1] = key;
    }
    if (sh < sw) {
        cout << "Insertion Sort\n";
    } else if (sw < sh) {
        cout << "Selection Sort\n";
    } else {
        cout << "Tie\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}