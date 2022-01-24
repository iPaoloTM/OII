#include <fstream>
#include <vector>
#include <algorithm>
//#include <iostream>

using namespace std;

int main(void) {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int dim1, dim2;
    in >> dim1 >> dim2;

    vector<int> first_dose;
    vector<int> second_dose;
    vector<int> fully_vax(dim2, 0);
    first_dose.resize(dim1);
    second_dose.resize(dim2);

    int n_vax = 0;

    for(int i = 0; i < dim1; i++) {
        in >> first_dose[i];
    }

    for(int i = 0; i < dim2; i++) {
        in >> second_dose[i];
    }

    sort(first_dose.begin(), first_dose.end());
    //sort(second_dose.begin(), second_dose.end());

    for(int i = 0; i < dim2; i++) {
        if(binary_search(first_dose.begin(), first_dose.end(), second_dose[i])) {
            n_vax++;
        }
    }

    out << n_vax << endl;

    return 0;
}
