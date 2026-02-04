#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long w, h;
    cin >> w >> h;
    vector <long long> x_0;
    vector <long long> x_idx;
    vector <long long> y_0;
    vector <long long> y_idx;
    vector <long long> k_ele;
    for(int i = 0; i < 4; i++){
        long long k;
        cin >> k;
        k_ele.push_back(k);
        if (i == 0){
            for(long long p = 0; p < k; p++){
                long long ele;
                cin >> ele;
                x_0.push_back(ele);
            }
        }
        if (i == 1){
            for(long long p = 0; p < k; p++){
                long long ele;
                cin >> ele;
                x_idx.push_back(ele);
            }
        }
        if (i == 2){
            for(long long p = 0; p < k; p++){
                long long ele;
                cin >> ele;
                y_0.push_back(ele);
            }
        }
        if (i == 3){
            for(long long p = 0; p < k; p++){
                long long ele;
                cin >> ele;
                y_idx.push_back(ele);
            }
        }
    }
    long long x_max = max((x_0[k_ele[0] - 1] - x_0[0]), (x_idx[k_ele[1] - 1] - x_idx[0]));
    long long y_max = max((y_0[k_ele[2] - 1] - y_0[0]), (y_idx[k_ele[3] - 1] - y_idx[0]));

    long long result = max(x_max * h, y_max * w);

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