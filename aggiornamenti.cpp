#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int N;
vector<int> A;
vector<int> B;

long long aggiorna(int N, vector<int> A, vector<int> B) {
  int res=0;
  int cond=true;
  int round=1;

  while (cond) {
    cond = false;
    for (int i=0; i<N-1;i++) {
      if (A[i]+B[i] <= A[i+1]) {
        cout<<"Updating Program "<<i<<"..."<<endl;
        A[i]+=B[i];
        cond=true;
        res++;
        cout<<"res = "<<res<<endl;
      }
    }
    cout<<"Round "<<round<<" completed"<<endl;
    round++;
  }

  return res;
}

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  in>>N;

  A.resize(N);
  B.resize(N);

  for (int i=0; i<N; i++) {
    in>>A[i];
    cout<<A[i]<<" ";
  }
  cout<<endl;

  for (int i=0; i<N; i++) {
    in>>B[i];
    cout<<B[i]<<" ";
  }
  cout<<endl;

  cout<< aggiorna(N, A, B) << endl;

  return 0;
}
