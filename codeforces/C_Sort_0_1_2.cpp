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
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 0) cnt0++;
        else if(x == 1) cnt1++;
        else cnt2++;
    }
    for(int i = 0; i < cnt2; i++) cout << 2 << " ";
    for(int i = 0; i < cnt1; i++) cout << 1 << " ";
    for(int i = 0; i < cnt0; i++) cout << 0 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}