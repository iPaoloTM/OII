#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

#define RED "\033[0;31m"
#define DF "\033[0m"

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
    cout<<array[i]<<" ";
  }

  sort(begin(array),end(array));

  cout<<"sorting..."<<endl;

  for (int i=0; i<N; i++) {
    cout<<array[i]<<" ";
  }
  cout<<endl;
  int res=1;

  for (int i=0; i<N-1; i++) {
    if (array[i]>=array[i+1]) {
      cout<<RED<<"WARNING:"<<DF<<array[i]<<">="<<array[i+1]<<endl;
      res=0;
      break;
    }
  }

  if (res)
    cout<<"Ok"<<endl;
  else
    cout<<"Impossible"<<endl;

return 0;
}
