#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define mod 1000000007
typedef long long ll;

vector<int>conta1(21,0);
vector<vector<int> >conta2(21,vector<int>(21,0));

vector<int>v(MAXN);

int calcola(){
    int ris=0;
    for(int i=0;i<=20;i++){
        int tmp=conta1[i];
        bool ok=false;
        for(int j=0;j<=20;j++){
            if(conta2[i][j]%2)ok=true;
        }
        if(!ok)tmp--;
        ris=max(ris,tmp);
    }
    return ris;
}

void aggiungi(int i) {
    for(int j=0;j<=20;j++) {
        if(v[i]&(1<<j)) {
            conta1[j]++;
            for(int k=0;k<=20;k++) {
                if(v[i]&(1<<k)) {
                    conta2[j][k]++;
                }
            }
        }
    }
}

void togli(int i) {
    for(int j=0;j<=20;j++) {
        if(v[i]&(1<<j)) {
            conta1[j]--;
            for(int k=0;k<=20;k++) {
                if(v[i]&(1<<k)) {
                    conta2[j][k]--;
                }
            }
        }
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n,q;
    in>>n>>q;
    for(int i=0;i<n;i++) {
          in>>v[i];
    }

    for(int i=0;i<n;i++){
        aggiungi(i);
    }

    out<<calcola()<<endl;

    while (q--) {
        int a,b;
        in>>a>>b;
        a--;
        togli(a);
        v[a]=b;
        aggiungi(a);
        out<<calcola()<<endl;
    }

}
