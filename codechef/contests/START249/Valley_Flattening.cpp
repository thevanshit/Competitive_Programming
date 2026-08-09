#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int N;
    cin >> N;
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    priority_queue<pair<long long, int>> pq;

    auto is_valley = [&](int i) {
        if (i <= 0 || i >= N - 1) return false;
        return A[i] < A[i - 1] && A[i] < A[i + 1];
    };

    for (int i = 1; i < N - 1; ++i) {
        if (is_valley(i)) {
            pq.push({A[i], i});
        }
    }

    while (!pq.empty()) {
        auto [val, i] = pq.top();
        pq.pop();

        if (A[i] != val || !is_valley(i)) {
            continue;
        }

        A[i - 1] = A[i];
        A[i + 1] = A[i];

        if (is_valley(i - 2)) {
            pq.push({A[i - 2], i - 2});
        }
        
        if (is_valley(i + 2)) {
            pq.push({A[i + 2], i + 2});
        }
    }
    
    long long min_sum = 0;
    for (int i = 0; i < N; ++i) {
        min_sum += A[i];
    }

    cout << min_sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}

