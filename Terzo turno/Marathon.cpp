#include <bits/stdc++.h>
using namespace std;
#define MAXN 250005
#define MAXM 250005
vector<vector<int> >adj(MAXN);
vector<int>heavy(MAXN);
vector<int>head(MAXN);
vector<int>Size(MAXN);
vector<int>parent(MAXN);
vector<int>pos(MAXN);
vector<int>depht(MAXN);
vector<int>st(4*MAXN);
int cur_pos=0;
vector<int>ar(MAXN);

int get_max(int i,int l,int r,int ql,int qr)
{
    if(l>=ql&&r<=qr)return st[i];
    if(l>qr||r<ql)return 0;
    int mid=(l+r)/2;
    return get_max(i*2+1,l,mid,ql,qr)+get_max(i*2+2,mid+1,r,ql,qr);
}
int n;
void dfs(int nodo,int p,int h)
{
    depht[nodo]=h;
    parent[nodo]=p;
    Size[nodo]=1;
    int pesante=-1,val=0;
    for(int x:adj[nodo])
    {
        if(x!=p)
        {
            dfs(x,nodo,h+1);
            Size[nodo]+=Size[x];
            if(Size[x]>val)
            {
                val=Size[x],pesante=x;
            }
        }
    }
    heavy[nodo]=pesante;
}
vector<int>vvv(MAXN);

void decompose(int nodo,int h){
    head[nodo]=h;
    ar[cur_pos]=0;
    pos[nodo]=cur_pos++;
    if(heavy[nodo]!=-1)decompose(heavy[nodo],h);
    for(int x:adj[nodo])
    {
        if(x!=parent[nodo]&&x!=heavy[nodo])
            decompose(x,x);
    }
}
int query(int a,int b){
    int ris=0;
    for(;head[a]!=head[b];b=parent[head[b]])
    {
        if(depht[head[a]]>depht[head[b]])swap(a,b);
        ris=ris+get_max(0,0,n-1,pos[head[b]],pos[b]);
    }
    if(pos[a]>pos[b])swap(a,b);
    ris=ris+get_max(0,0,n-1,pos[a]+1,pos[b]);
    return ris;
}
void update(int i,int l,int r,int poss){
    if(l==r){
        st[i]=1-st[i];
        ar[l]=1-ar[l];
        return;
    }
    int mid=(l+r)/2;
    if(poss<=mid)update(i*2+1,l,mid,poss);
    else update(i*2+2,mid+1,r,poss);
    st[i]=st[i*2+1]+st[i*2+2];
}
int main(){
  ifstream ("input.txt");
  ofstream out("output.txt");
    in>>n;
    int q;
    in>>q;
    for(int i=0;i<n-1;i++){
        int a,b;
        in>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int somma=0;
    dfs(1,1,0);
    decompose(1,1);
    while (q--) {
        int t1,t2,t3;
        in>>t1>>t2>>t3;
        if(t1==1){
            if(parent[t2]==t3)update(0,0,n-1,pos[t2]);
            else update(0,0,n-1,pos[t3]);
        }else{
            t2=(t2+somma)%n+1;
            t3=(t3+somma)%n+1;
            int tmp=query(t2,t3);
            if(tmp==0){
                somma++;
                out<<1<<endl;
            }else{
                out<<0<<endl;
            }
        }
    }
}
