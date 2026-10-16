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
    string s;
    cin >> s;
    
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (char c : s) {
        if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }
    if(hasLower && hasUpper && hasDigit && hasSpecial && sz(s) == 10) {
        cout << "Strong" << "\n";
        return;
    }
    else {
        cout << "Weak" << "\n";
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}