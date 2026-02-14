#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

struct Piece {
    int id;
    ll h, w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll H, W;
    int N;
    if (!(cin >> H >> W >> N)) return 0;

    vector<ll> h(N), w(N);
    map<ll, vector<int>> by_h, by_w;

    for (int i = 0; i < N; ++i) {
        cin >> h[i] >> w[i];
        by_h[h[i]].push_back(i);
        by_w[w[i]].push_back(i);
    }

    vector<ll> ans_x(N), ans_y(N);
    vector<bool> used(N, false);

    ll cur_x = 1;
    ll cur_y = 1;
    ll cur_H = H;
    ll cur_W = W;

    for (int step = 0; step < N; ++step) {
        int picked_idx = -1;
        bool is_vertical = false;

        while (!by_h[cur_H].empty()) {
            int idx = by_h[cur_H].back();
            if (used[idx]) {
                by_h[cur_H].pop_back();
                continue;
            }
            picked_idx = idx;
            by_h[cur_H].pop_back();
            is_vertical = true;
            break;
        }

        if (picked_idx == -1) {
            while (!by_w[cur_W].empty()) {
                int idx = by_w[cur_W].back();
                if (used[idx]) {
                    by_w[cur_W].pop_back();
                    continue;
                }
                picked_idx = idx;
                by_w[cur_W].pop_back();
                is_vertical = false;
                break;
            }
        }

        used[picked_idx] = true;
        ans_x[picked_idx] = cur_x;
        ans_y[picked_idx] = cur_y;

        if (is_vertical) {
            cur_y += w[picked_idx];
            cur_W -= w[picked_idx];
        } else {
            cur_x += h[picked_idx];
            cur_H -= h[picked_idx];
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans_x[i] << " " << ans_y[i] << "\n";
    }
    return 0;
}