#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

#define RED "\033[0;31m"
#define DF "\033[0m"

using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  int N, res;
  in>>N;

  vector<int> tempi;
  tempi.resize(N);

  for (int i=0; i<N; i++) {
    in >> tempi[i];
  }

  vector<int> DP;
  DP.resize(N);

  for (int i=1; i<N; i++) {
    DP[0]=tempi[0];
    if (DP[i-1]>tempi[i]) {
      DP[i]=tempi[i];
    } else {
      DP[i]=DP[0]+tempi[i];
    }
  }

  cout<<DP[N-1]<<endl;

return 0;
}
