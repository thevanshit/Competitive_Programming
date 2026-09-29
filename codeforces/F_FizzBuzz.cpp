#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n; 
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 && i % 5 == 0) cout << "FizzBuzz\n";
        else if(i % 3 == 0) cout << "Fizz\n";
        else if(i % 5 == 0) cout << "Buzz\n";
        else cout << i << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}