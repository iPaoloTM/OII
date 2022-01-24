#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int main(void) {

    ifstream in("input.txt");
    ofstream out("output.txt");

    vector<int> arr;
    vector<double> tagli(15, 0);
    vector<int> res(15, 0);
    arr.resize(15);

    tagli[0] = 0.01;
    tagli[1] = 0.02;
    tagli[2] = 0.05;
    tagli[3] = 0.10;
    tagli[4] = 0.20;
    tagli[5] = 0.50;
    tagli[6] = 1.00;
    tagli[7] = 2.00;
    tagli[8] = 5.00;
    tagli[9] = 10.00;
    tagli[10] = 20.00;
    tagli[11] = 50.00;
    tagli[12] = 100.00;
    tagli[13] = 200.00;
    tagli[14] = 500.00;

    for(int i = 0; i < 15; i++) {
        in >> arr[i];
    }

    double total = 0.0;

    for(int i = 0; i < 15; i++) {
        total += arr[i] * tagli[i];
    }

    int i = 14;

    while(i >= 0) {
        double r = total/tagli[i];
        r = ceil(r*100000000.0)/100000000.0; //Precisione senza senso
        int p = int(r);
        double d = (total/tagli[i]) - (int)r;
        d = ceil(d*1000000.0)/1000000.0; //Precisione senza senso
        res[i] = p;
        total = d*tagli[i];
        i--;
    }

    for(auto iter: res) {
       out << iter << " ";
    }

    return 0;
}
