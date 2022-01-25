#include<bits/stdc++.h>

using namespace std;

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    unordered_map<int, int> visti;
    in>>n;
    int admin=-1;
    for(int a=0;a<n; a++){
        int tmp;
        in>>tmp;
        if(tmp!=admin){

            auto test = visti.find(tmp);
            visti.insert(make_pair(tmp, 0));
            if(test != visti.end()){
                if(admin==-1){
                    admin=tmp;
                    continue;
                }
                out<<"YES"<<endl;
                return 0;
            }
        }

    }
    out<<"NO"<<endl;
}
