#include <stdio.h>
#include <fstream>

using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

    int G, P;
    in >> G;
    in >> P;
    P--;
    int gemme_toto = 1;
    int tot_gemme_toto = 0;

    while (G > 0) {
        G -= gemme_toto;
        if (G < 0) tot_gemme_toto += G;
        tot_gemme_toto += gemme_toto;
        G -= P;
        gemme_toto++;
    }
    out << tot_gemme_toto;
}
