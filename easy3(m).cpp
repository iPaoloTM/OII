#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int dim;
    in >> dim;

    vector<int> array;
    array.resize(dim);

    for(int i = 0; i < dim; i++) {
        in >> array[i];
    }

    int maxP = 0, maxD = 0;
    int sumP = 0, sumD = 0;
    int maxPindex = -1, maxDindex = -1;
    int numP = 0, numD = 0;

    //Primo giro
    for(int i = 0; i < dim; i++) {
        if(array[i]%2==0) {
          numP++;
          if(array[i] > maxP) {
            maxP = array[i];
            maxPindex = i;
          }
        } else {
          numD++;
          if(array[i] > maxD) {
            maxD = array[i];
            maxDindex = i;
          }
        }
    }

    //Secondo giro
    for(int i = 0; i < dim; i++) {
        if(array[i]%2==0) {
          if (i != maxPindex && array[i] > sumP) {
            sumP = array[i];
          }
        } else {
          if (i != maxDindex && array[i] > sumD) {
            sumD = array[i];
          }
        }
    }

    cout << sumP << sumD << endl;

    sumP += maxP;
    sumD += maxD;

    cout << sumP << sumD << maxP << maxD << maxPindex << maxDindex << numP << numD << endl;

    //Stampa
    if(numP >= 2 && numD >= 2) {
      out << max(sumP, sumD) << endl;
    } else if (numP >= 2) {
      out << sumP << endl;
    } else if (numD >= 2) {
      out << sumD << endl;
    } else {
      out << -1 << endl;
    }

    return 0;
}
