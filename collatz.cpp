#include <fstream>
#include <vector>
#include <algorithm>
//#include <iostream>

using namespace std;

int main(void) {

  ifstream in("input.txt");
  ofstream out("output.txt");


  int num, res=1;

  in >> num;

  while (num != 1) {
    if (num%2==0) {
      num/=2;
    } else {
      num=3*num+1;
    }
    res++;
  }

  out<<res<<endl;

  return 0;
}
