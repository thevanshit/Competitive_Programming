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
    char c;
    cin >> c;
    if (islower(c)) {
        cout << "Lowercase\n";
    } 
    else if (isupper(c)) {
        cout << "Uppercase\n";
    } 
    else if (isdigit(c)) {
        cout << "Digit\n";
    } 
    else {
        cout << "Special\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}