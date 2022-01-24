#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 40;

int res[MAX];
int fib[MAX];

void init() {

  fib[0]=1;
  fib[1]=1;

  for (int i=2; i<MAX; i++) {
    fib[i]=fib[i-1]+fib[i-2];
  }

}

int calc(int N) {

  int i = MAX-1;

  fill_n(res, MAX, 0);

  while (fib[i] > N) {i--;}

  cout<<"parto da "<<fib[i]<<endl;

  int length=i;

  while (N>0) {
    if (fib[i] <= N) {
      N -= fib[i];
      res[i]=1;
    }
    i--;
  }

  return length;
}

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  int N;

  init();

  in>>N;
  cout<<"leggo "<<N<<endl;

  int length=calc(N);

  for (int i=0; i<=length; i++) {
    out<<res[i];
  }

  out<<endl;

  return 0;
}
