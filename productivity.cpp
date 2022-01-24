#include <fstream>
//#include <iostream>

using namespace std;

int main(void) {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int N,M,E;
    in >> N >> M >> E;

    int max = 0;

    for(int i = M; i <= N; i++) {
        if(E%i > max) {
            max = E%i;
        }
    }

    out << max << endl;

    return 0;
}