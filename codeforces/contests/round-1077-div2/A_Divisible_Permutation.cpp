#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> p(n + 1, -1);
    set<int> unused;
    for (int i = 1; i <= n; i++) unused.insert(i);

    p[n] = 1;
    unused.erase(1);

    for (int i = n - 1; i >= 1; i--) {
        bool found = false;
        for (int x : unused) {
            if (abs(x - p[i + 1]) % i == 0) {
                p[i] = x;
                found = true;
                unused.erase(x);
                break;
            }
        }

        if (!found){}
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}