#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int calcola(int a, int b) {
  int res=0;

  int temp1=24-a;
  res=temp1+b;

  return res;
}

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

    long N;
    int T;

    in >> N >> T;

    //cout<<"N: "<<N<<" e T:"<<T<<endl;

    vector<pair<int,int> > usage;
    usage.resize(N);

    for (int i=0; i<N; i++) {
      int a,b;
      in>>a>>b;
      usage[i] = make_pair(a,b);
      //cout<<usage[i].first<<" "<<usage[i].second<<endl;
    }
    int j=0;
    bool cond=true;
    while (calcola(usage[j].second,usage[j+1].first)<T && j<N-1) {
      //cout<<usage[j].second<<" "<<usage[j+1].first<<" quindi "<<calcola(usage[j].second,usage[j+1].first)<<endl;
    j++;
    }

    //cout<<j<<endl;

    if (calcola(usage[j].second,usage[j+1].first) < T) {cout<<calcola(usage[j].second,usage[j+1].first)<<endl;j=-1;}

    cout<<j<<endl;


    return 0;
}
