#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;

struct Tessera {
  int s,d;
};

vector<Tessera> t;
vector<Tessera> r;
vector<bool> used;
vector<Tessera> permutazione;

int length=0;

void findPermutation(int pos) {
  if (pos > length) {
    length=pos;
  }
  for (int i=0; i<N; i++) {
    if (pos==0 || (permutazione[pos-1].d == t[i].s && used[i]==false)) {
      permutazione[pos]=t[i];
      used[i]=true;
      findPermutation(pos+1);
      used[i]=false;
    }
    if (pos==0 || (permutazione[pos-1].d == r[i].s && used[i]==false)) {
      permutazione[pos]=r[i];
      used[i]=true;
      findPermutation(pos+1);
      used[i]=false;
    }
  }
}

int main() {

  t.resize(10);
  r.resize(10);
  used.resize(10);
  permutazione.resize(10);

    ifstream in("input.txt");
    ofstream out("output.txt");

    in>>N;

    for (int i=0; i<N; i++) {
      in >> t[i].s;
      in >> t[i].d;
      r[i].s = t[i].d;
      r[i].d = t[i].s;
    }

    for (int i=0; i<N; i++) {
      used[i] = false;
    }

    findPermutation(0);

    cout << length;

    return 0;
}
