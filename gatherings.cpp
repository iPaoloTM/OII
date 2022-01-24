#include <stdio.h>
#include <fstream>

using namespace std;


#define MAXN 100000

// input data


int main() {
  int N, D, i;
  int array[MAXN];
  //uncomment the following lines if you want to read/write from files
  ifstream in("input.txt");
  ofstream out("output.txt");

  in >> N;
  in >> D;

    for(i=0; i<N; i++) {in >> array[i];}

    // insert your code here
    long long answer = 0;
    int j=0;
    int k=1;
    int num=0;

    for(k=1; k<N; k++) {
      while(array[k]-array[j] >= D && j<k) {
        num--;
        j++;
      }
        num++;
        answer+=num;
    }

    out << answer; // print the result
    return 0;
}
