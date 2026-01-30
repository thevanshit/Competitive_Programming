#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; 
    int k;
    cin >> n >> k;

    vector <int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if (k == 2){
        for (int i = n - 1; i >= 0; i--){
            if (a[i] % 2 == 0){
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
    }
    else if (k == 3){
        int cnt = 3;
        for (int i = n - 1; i >= 0; i--){
            if (a[i] % 3 == 0){
                cout << 0 << endl;
                return;
            }
            int factor = 3 - (a[i] % 3);
            cnt = min((factor % 3), cnt);
        }
        cout << cnt << endl;
    }
    else if (k == 4) {
        int cnt = 4;
        int cnt2 = 0;
        for (int x : a) {
            if (x % 4 == 0) {
                cout << 0 << endl;
                return;
            }
            if (x % 2 == 0) cnt2++;

            int factor = 4 - (x % 4);
            cnt = min((factor % 4), cnt);
        }

        if (cnt2 >= 2) cout << min(0, cnt) << endl;
        else if (cnt2 == 1) cout << min(1, cnt) << endl;
        else cout << min(2, cnt) << endl;
    }
    else if (k == 5){
        int cnt = 5;
        for (int i = n - 1; i >= 0; i--){
            if (a[i] % 5 == 0){
                cout << 0 << endl;
                return;
            }
            int factor = 5 - (a[i] % 5);
            cnt = min((factor % 5), cnt);
        }
        cout << cnt << endl;
    }
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