#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

vector<vector<int> >adj(MAXN);
vector<int>dist(MAXN,2e9);
vector<bool>vis(MAXN);
array<int,4>E[100005];

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
    int n,m,t;
    in>>n>>m>>t;
    for(int i=0;i<m;i++){
        int a,b,c,d;
        in>>a>>b>>c>>d;
        E[i]={a,b,c,d};
        adj[a].push_back(i);
    }

    priority_queue<pair<int,int> >coda;
    coda.push({0,0});

    dist[0]=0;
    while (!coda.empty()) {
      
        int nodo=coda.top().second;
        coda.pop();

        if(vis[nodo])continue;
        vis[nodo]=1;

        for(int x:adj[nodo]){
            if(E[x][3]==0 || dist[nodo]+E[x][2]<=t) {

                if(dist[nodo]+E[x][2] < dist[E[x][1]]) {

                    dist[E[x][1]] = dist[nodo]+E[x][2];
                    coda.push({-dist[E[x][1]],E[x][1]});
                }
            }
        }
    }
    if(dist[n-1]==2e9){
        cout<<-1<<endl;
    }else{
        cout<<dist[n-1]<<endl;
    }

}
