#include <fstream>
#include <vector>
//#include <iostream>

using namespace std;

int main(void) {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int N,M;
    in >> N >> M;

    double arr[M][N];

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            in >> arr[i][j];
        }
    }

    vector<double> mul;

    double total, sum;

    for(int i = 0; i < M; i++) {
        total = 1000000;
        sum = 0;
        for(int j = 0; j < N; j++) {
            sum += arr[i][j];
        }
        mul.push_back((double)1000000/sum);
    }

    int index = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            arr[i][j] *= mul[index];
        }
        index++;
    }

    vector<int> res(N,0);
    int ind = 0;

    for(int i = 0; i < N; i++) {
        double tot = 0.0;
        for(int j = 0; j < M; j++) {  
            tot += arr[j][i];
        }
        res[ind] = (int)tot/M;
        ind++;
    }

    for(auto iter: res) {
        out << iter << " ";
    }

    return 0;
}