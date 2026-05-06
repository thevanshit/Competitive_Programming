#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long modpow(long long a,long long b){
    long long r=1;
    while(b){
        if(b&1) r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}

long long countBit(long long M,int b){
    long long cycle = 1LL<<(b+1);
    long long full = M / cycle;
    long long rem = M % cycle;

    long long res = full * (1LL<<b);
    res += max(0LL, rem - (1LL<<b) + 1);

    return res;
}

void solve(){
    long long N,M;
    cin>>N>>M;

    if(N==1){
        cout<<0<<"\n";
        return;
    }

    long long MN = modpow(M,N);
    long long MN1 = modpow(M,N-1);

    long long ans=0;

    for(int b=0;b<30;b++){
        long long cnt = countBit(M,b);

        long long sumcb = ((long long)N * cnt) % MOD * MN1 % MOD;

        long long total = (sumcb - MN + MOD) % MOD;

        long long contrib = ((1LL<<b)%MOD) * total % MOD;

        ans = (ans + contrib) % MOD;
    }

    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}