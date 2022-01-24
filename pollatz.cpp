#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int collatz(int num) {
  int steps=1;
  while (num != 1) {
    if (num%2==0) {
      num/=2;
    } else {
      num=3*num+1;
    }
    steps++;
  }
  return steps;
}

int pollatz(int num) {
  int steps=1;
  int upperbound=collatz(num);
  while (num != 1) {
    if  (steps<upperbound) {
      if (num%2==0) {
      num/=2;
    } else {
      num=5*num+1;
    }
    steps++;
  } else {
    return upperbound+1;
  }
  }
  return steps;
}

int main(void) {

  ifstream in("input.txt");
  ofstream out("output.txt");

  int start, end, temp, res=0;

  in >> start;
  in >> end;

  temp=start;

  while (temp<=end) {
    int p=pollatz(temp);
    int c=collatz(temp);

    if (p<c) {

      res++;
    } else {

    }
    temp++;
  }

  cout<<res<<endl;

  return 0;
}
