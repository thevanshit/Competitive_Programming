#include <bits/stdc++.h>
using namespace std;

bool canPaintK(vector<long long> sides, vector<long long> colors, int k) {
    sort(sides.rbegin(), sides.rend());
    sort(colors.rbegin(), colors.rend());

    for (int i = 0; i < k; i++) {
        bool painted = false;
        for (int j = 0; j < 3; j++) {
            if (colors[j] >= sides[i]) {
                colors[j] -= sides[i];
                painted = true;
                break;
            }
        }
        if (!painted) return false;
        sort(colors.rbegin(), colors.rend());
    }
    return true;
}

void solve() {
    long long L, W, R, G, B;
    cin >> L >> W >> R >> G >> B;

    vector<long long> sides = {L, L, W, W};
    vector<long long> colors = {R, G, B};

    if (canPaintK(sides, colors, 4))
        cout << 4 << '\n';
    else if (canPaintK(sides, colors, 3))
        cout << 5 << '\n';
    else
        cout << 6 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
