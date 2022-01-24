#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
typedef long long ll;

vector<pair<int,int> >v(MAXN);

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

    int n;
    in>>n;
    for(int i=0;i<n;i++){
        in>>v[i].first>>v[i].second;
    }

    for(int i=1;i<n;i++){

        if(v[i].first>v[i-1].second || v[i].second<v[i-1].first) {
            out<<"NO"<<endl;
            return 0;
        }
    }
    
    out<<"YES"<<endl;
}
