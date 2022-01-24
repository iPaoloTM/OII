#include <bits/stdc++.h>
using namespace std;
#define MAXN 250005
#define mod 1000000007
typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>tmp;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(tmp.size()>0&&tmp.back()==a){
            tmp.pop_back();
        }else{
            tmp.push_back(a);
        }
    }
    if(tmp.size()==0)cout<<1<<"\n";
    else cout<<0<<"\n";
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        solve();
    }

}
