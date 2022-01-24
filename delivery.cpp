//#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  int N;

  in>>N;

  vector<int> array;
  array.resize(N);

  for (int i=0; i<N; i++) {
    in>>array[i];
  }

  int res=array[0], times=0;


  for (int j=1; j<N; j++) {
    //cout<<array[j]<<"+"<<j<<" è minore di "<<res<<"?";

    if (array[j]+j<res) {
      //cout<<"Yes**********"<<endl;
      res=array[j]+j;
      times++;

    }

  }

  out<<res<<" "<<times;

  return 0;
}
