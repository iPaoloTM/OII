#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<vector<int> >adj(MAXN);
vector<int>C(MAXN);
unordered_map<int,int>fareshi[MAXN];
int max_freq[MAXN];
int num_color[MAXN];
int ris=0;
void dfs(int nodo){
    int ma=nodo;
    for(int x:adj[nodo]){
        dfs(x);
        if(fareshi[x].size()>fareshi[ma].size())ma=x;
    }
    swap(fareshi[ma],fareshi[nodo]);
    max_freq[nodo]=max_freq[ma];
    num_color[nodo]=num_color[ma];
    for(int x:adj[nodo]){
        if(x==ma)continue;
        for(auto k:fareshi[x]){
            fareshi[nodo][k.first]+=k.second;
            if(fareshi[nodo][k.first]>max_freq[nodo]){
                max_freq[nodo]=fareshi[nodo][k.first];
                num_color[nodo]=1;
            }else if(fareshi[nodo][k.first]==max_freq[nodo]){
                num_color[nodo]++;
            }
        }
    }
    fareshi[nodo][C[nodo]]++;
    if(fareshi[nodo][C[nodo]]>max_freq[nodo]){
        max_freq[nodo]=fareshi[nodo][C[nodo]];
        num_color[nodo]=1;
    }else if(fareshi[nodo][C[nodo]]==max_freq[nodo]){
        num_color[nodo]++;
    }
    //cout<<nodo<<" "<<max_freq[nodo]<<" "<<num_color[nodo]<<endl;
    ris=max(ris,num_color[nodo]);


}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>C[i];
    for(int i=1;i<n;i++){
        int tmp;
        cin>>tmp;
        adj[tmp].push_back(i);
    }

    dfs(0);
    cout<<ris<<endl;

}
