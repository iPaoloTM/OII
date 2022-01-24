#include <fstream>
#include <vector>
//#include <iostream>

using namespace std;

int main(void) {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int dim;
    in >> dim;

    vector<int> array;
    array.resize(dim);

    for(int i = 0; i < dim; i++) {
        in >> array[i];
    }

    int sum = array[0];

    for(int i = 1; i < dim; i++) {
        if(array[i] == -1) {
            int tmp = array[i-1];
            array[i] = tmp;
        }

        sum += array[i];
    }

    out << sum << endl;

    return 0;
}