#include <fstream>
#include <vector>
#include <iostream>

//Fa ancora 70/100 :()

using namespace std;

long long int enumera(int N, int M) {
    vector<long long int> array;
    array.resize(N+1);

    array[0]=-1;
    array[1]=0;

    for (int i=2; i<=N; i++) {
      for (int j=i-1; j>0; j--) {
      if (N<100) {
          array[i]+=((array[i-1]-array[j-1])%M+M)%M;
        } else {
            array[i]=((array[i]%M)+((array[i-1]-array[j-1])%M))%M;
        }
      }
    }



    return (array[N]%M+M)%M;
}


int main() {

    int N, M;

    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> N;
    in >> M;

    out << enumera(N,M);

    return 0;
}
