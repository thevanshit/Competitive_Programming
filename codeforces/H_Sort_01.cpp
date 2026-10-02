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

    int ze = 0, on = 0;
    vi a(n);
    for (int &x : a){
        cin >> x;
        if(x == 0) ze++;
        else on++;
    }
    for(int i = 0; i < ze; i++){
        cout << 0 << " ";
    }
    for(int i = 0; i < on; i++){
        if(i == on - 1) cout << 1;
        else cout << 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}