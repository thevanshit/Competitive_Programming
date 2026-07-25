#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    long long n; 
    cin >> n;
    cout << n << " ";
    while(n != 1){
        if (n % 2 == 0){
            n /= 2;
            cout << n << " ";
        }
        else{
            n *= 3;
            n++;
            cout << n << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}