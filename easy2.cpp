#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  int dim=0;
  int temp=-1;

  in >> dim;


  vector<pair<int,int> > array;
  array.resize(dim);

  for (int i=0; i<dim; i++) {
      int a,b;
      in >> a;
      in >> b;
      array[i] = make_pair(a,b);

  }

  for (int j=0; j<dim; j++) {
    int sum = array[j].first + array[j].second;
    //cout << array[j].first << " " << array[j].second << endl;
    if (sum%2 ==0 && sum>temp) {temp=sum;}
  }


  out << temp;


}
