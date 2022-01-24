#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
typedef long long ll;

vector<pair<int,int> >v(MAXN);

string mat[]={"qwertyuiop","asdfghjkl","zxcvbnm"};

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

    int n;
    in>>n;
    string s;
    in>>s;
    for(int i=0;i<n;i++){
        for(auto x:mat){
            for(int j=0;j<(int)x.size();j++){
                if(x[j]==s[i]){
                    out<<x[j+1];
                }
            }
        }
    }
    out<<endl;
}
