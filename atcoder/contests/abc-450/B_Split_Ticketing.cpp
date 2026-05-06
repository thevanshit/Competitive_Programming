#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> C[i][j];
        }
    }

    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            for (int c = b + 1; c <= n; c++) {
                if (C[a][b] + C[b][c] < C[a][c]) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }

    cout << "No\n";
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}