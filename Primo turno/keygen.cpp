#include <bits/stdc++.h>
using namespace std;
string s;
void solve(){
    int n;
    cin>>n;
    cin>>s;
    vector<vector<short> >ar;
    vector<short>supp;
    for(int i=0;i<(int)s.size();i++){

        if(s[i]=='('||s[i]=='^'||s[i]=='&')continue;
        if(s[i]=='!'){
            i++;
            supp.push_back(-(s[i]-'a'+1));
        }else if(s[i]==')'){
            ar.push_back(supp);
            supp.clear();
        }else{
            supp.push_back(s[i]-'a'+1);
        }
    }
    int riss=0;
    for(int i=0;i<(1<<n);i++){
        bool ris;
        for(int j=0;j<(int)ar.size();j++){
            bool ok=true;
            for(short x:ar[j]){
                if(x>0){
                    if(!(i&(1<<(x-1)))){
                        ok=false;
                        break;
                    }
                }else{
                    if(i&(1<<(-x-1))){
                        ok=false;
                        break;
                    }
                }
            }
            if(j==0)ris=ok;
            else ris^=ok;
        }
        if(ris)riss++;

    }
    cout<<riss<<"\n";


}
int main(){
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}
