#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

typedef long long ll;
int V[MAXN],S[MAXN];

int main(){

    ifstream in("input.txt");
    //cin.tie(0);
    int n;
    in>>n;

    for(int i=0;i<n;i++)cin>>V[i];
    for(int i=0;i<n;i++)cin>>S[i];

    int res=0;
    int supp=0;

    for(int i=0;i<n;i++){
        if(S[i]==0){
            supp=0;
            continue;
        }
        if(i==0 || S[i-1]==0 || V[i]>=V[i-1]){
            supp+=V[i];
        }else{
            supp=V[i];
        }
        res=max(res,supp);
    }
    out<<res<<endl;


}
