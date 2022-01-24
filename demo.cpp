#include <iostream>
#include <fstream>

using namespace std;

int main() {

  int array[10]={5, 6, 3, 2, ,1 ,66, 77, 8, 9, 10}
  int temp=-1;


  for (int i=0; i < 9; i++) {
      for (int j=0; j< 9; j++) {
        if (array[i]+array[j]>temp) {
          temp=array[i]+array[j];
        }
      }
  }




return 0;
}
