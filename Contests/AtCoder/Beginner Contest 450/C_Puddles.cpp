#include <bits/stdc++.h>
using namespace std;

int H, W;
vector <string> grid;
vector <vector <bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve(){
    cin >> H >> W;
    grid.resize(H);
    for(int i = 0; i < H; i++){
        cin >> grid[i];
    }
    visited.assign(H, vector <bool> (W, false));
    int cnt = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if (grid[i][j] == '.' && !visited[i][j]){
                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;

                bool touchesBorder = false;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    if (x == 0 || x == H-1 || y == 0 || y == W-1) {
                        touchesBorder = true;
                    }

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                            if (!visited[nx][ny] && grid[nx][ny] == '.') {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                if (!touchesBorder) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << "\n";
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}