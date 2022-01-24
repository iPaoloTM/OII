#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
int A[MAXN],B[MAXN];

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

    int n,t;
    in>>n>>t;
    for(int i=0;i<n;i++){
        in>>A[i]>>B[i];
    }
    for(int i=1;i<n;i++){
        if(A[i]-B[i-1]+24>=t){
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
