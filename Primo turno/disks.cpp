// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
	ifstream cin("input.txt");
	ofstream cout("output.txt");

    long long A, B, T;
    cin >> A >> B >> T;

    // insert your code here
    long long dT=0;

    T=T-24+B-A;


    long long g=T/24;
    long long r=T%24;
    dT=g*(B-A);
    T-=g*24;

    if(r>(B-A)){
    	dT+=(B-A);
	} else {
		dT+=r;
	}
  

    cout << dT << endl; // print the result

    return 0;
}
