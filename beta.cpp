#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  int N;

  in >> N;

  vector<int> id;
  id.resize(N);

  for (int i=0; i<N; i++) {
    in >> id[i];
  }

  sort(id.begin(), id.end());

  int dupplicato=0;
  int i=0;

  while (dupplicato!=2 && i<N) {
    //cout<<id[i]<<" "<<id[i+1]<<endl;
    if (id[i]==id[i+1]) {
        dupplicato++;
        //cout<<"dupplicato!"<<endl;
    }
    i++;
  }

  if (dupplicato >=2) {cout<<"YES"<<endl;} else {cout<<"NO"<<endl;}

  return 0;
}
