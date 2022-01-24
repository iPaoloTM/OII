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

  int N; // numeri di casi test

  in >> N;

  vector<vector<int> > utility; //non lo so
  utility.resize(N);

  for (int i=0; i<N; i++) {
    int dim, types; // lunghezza stringa e tipo di parentesi
    in>>dim;
    in >> types;
    cout << dim << " " << types <<endl;
    utility[i].resize(dim+1);
    utility[i][0]=types; //facciamo che nella prima cella di ogni array c'è il numero di tipi di parentesi
    for (int j=1; j<=dim; j++) {
      in>>utility[i][j];
      cout << utility[i][j] << " ";
    }
    cout<<endl;
  }

  cout<<"-----------------"<<endl;

  for (int i=0; i<N; i++) {
    int dim=utility[i].size();
    vector<int> aperte;
    aperte.resize(dim);
    vector<int> chiuse;
    chiuse.resize(dim);

    for (int j=1; j<dim; j++) {
      if
      cout << utility[i][j] << " ";
    }
    cout<<endl;
  }

return 0;
}
