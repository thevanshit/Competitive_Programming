#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, -1, 1};
int dy[4] = {1, 1, -1, -1};
void solve(){
    long long a, b;
    cin >> a >> b;
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    set <pair<long long, long long>> st_k, st_q;
    for(int i = 0; i < 4; i++){
        st_k.insert({x1 + dx[i] * a, y1 + dy[i] * b});
        st_q.insert({x2 + dx[i] * a, y2 + dy[i] * b});
        st_k.insert({x1 + dx[i] * b, y1 + dy[i] * a});
        st_q.insert({x2 + dx[i] * b, y2 + dy[i] * a});
    }
    long long result = 0;
    for(auto &x : st_k){
        if (st_q.find(x) != st_q.end()){
            result++;
        }
    }

    cout << result << "\n";
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}