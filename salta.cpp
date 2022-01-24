#include <fstream>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int main(void) {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;

    int v[N];

    for(int i=1; i<= N; i++){
      in >> v[i];
    }
  
    cout<<endl<<endl;
    int toccate = 0; //finchè non arrivo alla fine
    int I=1;//per scorrere il ciclo
    int nextSit;

    while(v[I]!=-1)
    {
      //cout<<I<<" - "<<v[I]<<endl;
      nextSit = ((I+v[I])%N)+1;
      //cout<<nextSit<<endl;
      v[I] = -1;
      I = nextSit;
      toccate++;  
    }
   
   out<<(N-toccate)<<endl;
    int count=0;
     for(int i=1; i<= N; i++){
      if (v[i]!=-1)
      out<<i<<" ";
     
    }
  

    in.close();
    out.close();
    return 0;
}
