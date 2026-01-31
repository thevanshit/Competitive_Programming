#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;

    if (N >= K) {
        cout << 0 << '\n';
        return 0;
    }

    ll lo = 0, hi = 2e9, ans = 0;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;

        __int128 total =
            (__int128)(mid + 1) * N +
            (__int128)mid * (mid + 1) / 2;

        if (total >= K) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
