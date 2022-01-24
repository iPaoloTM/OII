#include <bits/stdc++.h>

using namespace std;

map<int,int>mappa;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in>>n;
    for(int i=0;i<n;i++){
        int tmp;
        in>>tmp;
        //ogni volta che inserisco un elemento N
        //lo inserisco in posizione mappa[N] e mi salvo quante volte lo incontro
        mappa[tmp]++;
    }
    int conta=0;

    for (int i=0; i<mappa.size(); i++)
    for(auto x:mappa){
        //conto quandi dupp ci sono
        if(x.second>1)conta++;
    }
    if(conta<=1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

}
