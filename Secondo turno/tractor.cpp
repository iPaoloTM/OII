#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
typedef long long ll;

vector<bool>vis(MAXN,0);
int migliore=2e9;
int n,k;
vector<int>percorso;
vector<int>best_path;
vector<int>st(4*MAXN);

void build(int i,int l,int r){
    if(l==r){
        st[i]=1;
        return;
    }
    int mid=(l+r)/2;
    build(i*2+1,l,mid);
    build(i*2+2,mid+1,r);
    st[i]=st[i*2+1]+st[i*2+2];
}

void update(int i,int l,int r,int pos,int val){
    if(l==r){
        st[i]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)update(i*2+1,l,mid,pos,val);
    else update(i*2+2,mid+1,r,pos,val);
    st[i]=st[i*2+1]+st[i*2+2];
}

int trova(int i,int l,int r,int ql,int qr,bool a){
    if(l>qr||r<ql)return -1;
    if(st[i]==0)return -1;
    if(l>=ql&&r<=qr){
        if(st[i]==0)return -1;
        if(a){
            while (l!=r) {
                if(st[i*2+1]>0)r=(l+r)/2,i=2*i+1;
                else l=(l+r)/2+1,i=2*i+2;
            }
        }else{
            while (l!=r) {
                if(st[i*2+2]>0)l=(l+r)/2+1,i=2*i+2;
                else r=(l+r)/2,i=2*i+1;
            }
        }
        return l;
    }
    int mid=(l+r)/2;
    if(a){
        int tmp=trova(i*2+1,l,mid,ql,qr,a);
        if(tmp==-1)tmp=trova(i*2+2,mid+1,r,ql,qr,a);
        return tmp;
    }else{
        int tmp=trova(i*2+2,mid+1,r,ql,qr,a);
        if(tmp==-1)tmp=trova(i*2+1,l,mid,ql,qr,a);
        return tmp;
    }
}

void ric(int pos,int costo,int visitati){
    if(costo>=migliore)return;
    //cout<<pos<<"\n";
    visitati++;
    update(0,0,n-1,pos,0);
    percorso.push_back(pos);
    if(visitati==n){
        best_path=percorso;
        migliore=costo;
        percorso.pop_back();
        visitati--;
        update(0,0,n-1,pos,1);
        return;
    }
    int supp1=pos+k;
    while (true) {
        if(migliore!=2e9)break;
        int prossimo=trova(0,0,n-1,supp1,n-1,1);
        //cout<<pos<<" "<<prossimo<<"\n";
        if(prossimo==-1)break;
        ric(prossimo,costo+abs(pos-prossimo),visitati);
        supp1=prossimo+1;
    }
    supp1=pos-k;
    while (true) {
        if(migliore!=2e9)break;
        int prossimo=trova(0,0,n-1,0,supp1,0);
        //cout<<pos<<" "<<prossimo<<"\n";
        if(prossimo==-1)break;
        ric(prossimo,costo+abs(pos-prossimo),visitati);
        supp1=prossimo-1;
    }

    update(0,0,n-1,pos,1);
    visitati--;
    percorso.pop_back();
}

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");

    in>>n>>k;

    build(0,0,n-1);
    ric(0,0,0);

    cout<<migliore<<endl;

    for(int x:best_path) cout<<x<<" ";
    cout<<endl;


}
