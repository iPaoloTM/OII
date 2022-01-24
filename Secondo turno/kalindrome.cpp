#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    string s;
    in>>n>>s;
    for(int k=1;k<=n;k++){
        //comincio con n bucket di length=1
        if(n%k!=0)continue;
        //se length non è multiplo di k, non ptrò avere n/k bucket
        int ind1=0,ind2=n-k;
        //controllo il primo carattere della stringa
        // e il primo carattere dell'ultimo bucket lungo k
        bool ok=true;

        while (ind1<n) {
            for(int i=0;i<k;i++){
                if(s[ind1+i]!=s[ind2+i]){
                    //il carattere i-esimo dell'ind1-esimo bucket è diverso
                    //dal carattere i-esimo dell'ind2-esimo bucket
                    //(i sarò al massimo k-1 cosi controlliamo tutti i caratteri
                    //del bucket, partendo da k=1 andanso sù)
                    ok=false;
                    break;
                }
            }
            //avanzo ind1 di k (scorre in testa)
            ind1+=k;
            //diminuisco ind2 di k (scorro in coda)
            ind2-=k;
        }
        if(ok){
            cout<<k<<endl;
            break;
        }
    }
}
