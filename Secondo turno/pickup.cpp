#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
typedef long long ll;
int main(){
    ll a,b,k;
    cin>>a>>b>>k;
    vector<int>ris;
    while (b>0) {
        ris.push_back(min(b,(ll)9));
        b-=9;
    }
    reverse(ris.begin(),ris.end());
    for(int x:ris)cout<<x;
    cout<<endl;

}
