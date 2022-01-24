#include <fstream>
#include <vector>
#include <algorithm>
//#include <iostream>

using namespace std;

int main(void) {

  ifstream in("input.txt");
  ofstream out("output.txt");

  int rows, temp=0;

  in >> rows;

  vector<int> array;
  array.resize(rows);

  for (int i=0; i<rows; i++) {
    in>>array[i];
  }

  for (int j=0; j<rows-1; j++) {
    if (abs(array[j]-array[j+1]) > temp) {temp=abs(array[j]-array[j+1]);}
  }

  out<<temp<<endl;

  return 0;
}
