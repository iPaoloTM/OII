#include <bits/stdc++.h>
using namespace std;
#define MAXN 250005
#define mod 1000000007
typedef long long ll;
vector<ll>st(4*MAXN);
vector<ll>ar(MAXN);
void up(int i,int l,int r,int ql,int qr,ll b){
    if(l>=ql&&r<=qr){
        st[i]=max(st[i],b);
        return;
    }
    if(l>qr||r<ql)return;
    int mid=(l+r)/2;
    up(i*2+1,l,mid,ql,qr,max(b,st[i]));
    up(i*2+2,mid+1,r,ql,qr,max(b,st[i]));

}
int get(int i,int l,int r,int pos,ll massimo){
    st[i]=max(st[i],massimo);
    if(l==r){
        return st[i];
    }
    int mid=(l+r)/2;
    if(pos<=mid)return get(i*2+1,l,mid,pos,st[i]);
    else return get(i*2+2,mid+1,r,pos,st[i]);
}
void solve(){
  ifstream in("input.txt");
  ofstream out("output.txt");
    int n;
    in>>n;
    vector<ll>ar(n+1);
    for(int i=1;i<=n;i++)in>>ar[i];
    int q;
    in>>q;
    while (q--) {
        int a;
        in>>a;
        if(a==1){
            int x;
            in>>x;
            ll tmp=get(0,1,n,x,0);
            out<<max(ar[x],(tmp*x))%mod<<"\n";
        }else{
            int x,y,b,c;
            in>>x>>y>>b>>c;
            up(0,1,n,x,y,b);
        }
    }


}
int main(){
    int t=1;
    while (t--) {
        solve();
    }

}
