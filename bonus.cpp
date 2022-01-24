#include <iostream>
#include <fstream>

using namespace std;

#define MAXN 100000

int main() {

  long long n, i, res=-1;
  long long S[MAXN], P[MAXN];

    ifstream in("input.txt");
    ofstream out("output.txt");

    in >>n;
    for(i=0; i<n; i++) {
        in >> S[i];
        in >> P[i];
    }

    long long N=0;
    long long D=0;

    for(int i=0; i<n; i++) {
      N+=S[i];
      D+=P[i];
    }

    long long tempS=0;
    long long tempP=1;

    for(int j=0; j<n; j++) {
      if((N-S[j])*tempP > tempS*(D-P[j])) {
        res=j;
        tempS=(N-S[j]);
        tempP=(D-P[j]);
      }
    }


    out << res << endl;
    return 0;
}
