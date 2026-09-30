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

bool isprime(ll n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    if(isprime(n)) cout << "Prime\n";
    else cout << "Not Prime\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}