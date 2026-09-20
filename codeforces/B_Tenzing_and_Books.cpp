#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, x;
    int a[100000];
    cin >> n >> x;
    int s = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        for(int j = 0; j < n; j++){
            if((x | a[j]) != x){
                break;
            }
            s |= a[j];
        }
    }
    if(s == x){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}