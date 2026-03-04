#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> A(n+1), ans(n+1);

    for(int i = 1; i <= n; i++)
        cin >> A[i];

    long long shots = 0;

    for(int i = 1; i <= n; i++) {

        ans[i] = min(A[i], shots);

        if(shots < A[i])
            shots++;
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        solve();
}