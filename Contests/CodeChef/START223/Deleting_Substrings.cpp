#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

void solve() {
    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    vector<int> prev(N, INF), cur(N, INF);

    for (int i = 0; i < N; i++) {
        if (S[i] == T[0]) {
            prev[i] = (i > 0 ? 1 : 0);
        }
    }

    for (int j = 1; j < M; j++) {
        vector<int> prefixMin(N, INF);
        prefixMin[0] = prev[0];
        for (int i = 1; i < N; i++) {
            prefixMin[i] = min(prefixMin[i-1], prev[i]);
        }

        fill(cur.begin(), cur.end(), INF);

        for (int i = 0; i < N; i++) {
            if (S[i] != T[j]) continue;

            if (i > 0 && prev[i-1] < INF)
                cur[i] = min(cur[i], prev[i-1]);

            if (i > 1 && prefixMin[i-2] < INF)
                cur[i] = min(cur[i], prefixMin[i-2] + 1);
        }

        swap(prev, cur);
    }

    int ans = INF;
    for (int i = 0; i < N; i++) {
        if (prev[i] < INF) {
            int cost = prev[i];
            if (i < N - 1) cost++;
            ans = min(ans, cost);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
}
