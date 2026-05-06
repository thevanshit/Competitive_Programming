#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    long long prefMax = LLONG_MIN;

    for (int i = 0; i < N; i++) {
        if (A[i] > B[i]) {
            cout << "No" << endl;
            return;
        }
        if (A[i] <= prefMax && B[i] != A[i]) {
            cout << "No" << endl;
            return;
        }
        prefMax = max(prefMax, A[i]);
    }

    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
