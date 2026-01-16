#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long N, A, B;
    cin >> N >> A >> B;

    vector <int> a(N);
    for(long long i = 0; i < N; i++){
        cin >> a[i];
    }

    bool Jacket_wearing = false;
    long long count = 0;
    for(long long i = 0; i < N; i++){
        if (a[i] < A) {
            if (!Jacket_wearing) {
                count++;
                Jacket_wearing = true;
            }
        } 
        else if (a[i] > B) {
            Jacket_wearing = false;
        }
    }

    cout << count << endl;
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