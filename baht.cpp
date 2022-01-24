#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {

  int P, N;
  int monete[10000];

  ifstream in("input.txt");
  ofstream out("output.txt");

  in>>P;

  for (int i=0; i<P; i++) {
    in>>N;
    int j;
    for (j=0; j<N; j++) {
      in >> monete[j];
    }
    sort(monete, monete+j);

    int quante=j;
    int somma=0;

    for (j=0; j<quante; j++) {
      if (monete[j] <= somma +1) {
        somma += monete[j];
      } else
        break;
    }
    out<<somma+1<<endl;
  }

  return 0;
}
