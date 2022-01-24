#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  int dim=0;
  int temp=-2147483647;

  in >> dim;

  vector<int> array(dim,0);

  for (int i=0; i<dim; i++) {
    in >> array[i];
  }

  for (int j=0; j<dim; j++) {
    if (array[j]>temp) {temp=array[j];}
  }


  out << temp;


}
