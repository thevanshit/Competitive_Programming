#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<bool> isPrime;
void build_sieve(int maxv){
    isPrime.assign(maxv+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=maxv;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=maxv;j+=i)
                isPrime[j]=false;
        }
    }
}
struct Fenwick{
    int n;
    vector<ll> bit;
    Fenwick(int n):n(n),bit(n+1,0){}
    
    void add(int idx,ll val){
        for(++idx;idx<=n;idx+=idx&-idx)
            bit[idx]+=val;
    }
    ll sum(int idx){
        ll s=0;
        for(++idx;idx>0;idx-=idx&-idx)
            s+=bit[idx];
        return s;
    }
};

void solve(){
    int N;
    cin>>N;
    vector<int>A(N);
    int c1=0,c2=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==1) c1++;
        else c2++;
    }

    int r1=c1, r2=c2;
    ll cur_sum=0;
    vector<int>B;

    for(int i=0;i<N;i++){
        bool can1 = (r1>0);
        bool can2 = (r2>0);

        bool take1=false, take2=false;

        if(can1 && isPrime[cur_sum+1]) take1=true;
        if(can2 && isPrime[cur_sum+2]) take2=true;

        if(take1){
            B.push_back(1);
            cur_sum+=1;
            r1--;
        }
        else if(take2){
            B.push_back(2);
            cur_sum+=2;
            r2--;
        }
        else{
            if(r2>0){
                B.push_back(2);
                cur_sum+=2;
                r2--;
            }else{
                B.push_back(1);
                cur_sum+=1;
                r1--;
            }
        }
    }
    queue<int> pos1, pos2;
    for(int i=0;i<N;i++){
        if(A[i]==1) pos1.push(i);
        else pos2.push(i);
    }
    vector<int> idx_seq;
    for(int x : B){
        if(x==1){
            idx_seq.push_back(pos1.front());
            pos1.pop();
        }else{
            idx_seq.push_back(pos2.front());
            pos2.pop();
        }
    }
    Fenwick fw(N);
    ll inv=0;
    for(int i=N-1;i>=0;i--){
        inv += fw.sum(idx_seq[i]);
        fw.add(idx_seq[i],1);
    }

    cout<<inv<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_sieve(10000);

    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
