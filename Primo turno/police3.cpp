#include <bits/stdc++.h>
using namespace std;
#define MAXN 250005
#define mod 1000000007
typedef long long ll;

ll dp[MAXN][2];



int main(){
    int n;
    cin>>n;
    vector<int>ar(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    dp[0][0]=ar[0];
    dp[0][1]=0;
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+ar[i];
        dp[i][1]=dp[i-1][0];
    }
    cout<<min(dp[n-1][0],dp[n-1][1])<<"\n";

}
