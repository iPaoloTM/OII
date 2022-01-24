#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100005
#define mod 1000000007
ll k;

vector<int>st1(4*MAXN);
vector<int>st3(4*MAXN);

void up(int i,int l,int r,int v,int pos){
    if(l==r){
        if(v>=k){
            st3[i]=0;
            st1[i]=v;
        }else{
            st3[i]=1;
            st1[i]=0;
        }
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)up(i*2+1,l,mid,v,pos);
    else up(i*2+2,mid+1,r,v,pos);
    st3[i]=st3[i*2+1]+st3[i*2+2];
    st1[i]=st1[i*2+1]+st1[i*2+2];
}

void get(int i,int l,int r,int ql,int qr,int s,ll &r1,ll &r3){
    if(l>=ql&&r<=qr){
        r1+=st1[i];
        r3+=st3[i];
        return;
    }
    if(l>qr||r<ql)return;
    int mid=(l+r)/2;
    get(i*2+1,l,mid,ql,qr,s,r1,r3);
    get(i*2+2,mid+1,r,ql,qr,s,r1,r3);
}
ll fxp(ll b,ll e){
    if(e==0)return 1;
    ll tmp=fxp(b,e/2);
    tmp=(tmp*tmp)%mod;
    if(e%2)tmp=(tmp*b)%mod;
    return tmp;
}
ll fact[2000004];
int main(){
    fact[0]=1;
    for(int i=1;i<2000004;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    int n,q;
    cin>>n>>q>>k;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        up(0,0,n-1,tmp,i);
    }
    while (q--) {
        int aa;
        cin>>aa;
        if(aa==2){

            int l,r,s;
            cin>>l>>r>>s;
            l--;
            r--;
            ll r1=0,r3=0;
            get(0,0,n-1,l,r,s,r1,r3);

            s-=r1;
            s-=k*r3;

            if(s<0){
                cout<<0<<"\n";
            }else{
                ll tmp=fact[s+r-l];
                ll tmp2=(fact[s]*fact[r-l])%mod;
                tmp=(tmp*fxp(tmp2,mod-2))%mod;
                cout<<tmp<<"\n";
            }
        }else{
            int a,b;
            cin>>a>>b;
            up(0,0,n-1,b,a-1);
        }
    }
}
