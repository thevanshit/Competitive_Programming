#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<bool> can(N + 2, false);
    can[1] = true;  

    int ans = 0;

    for (int x : A) {
        if (can[x]) {
            ans++;
            if (x + 1 <= N) {
                can[x + 1] = true;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
