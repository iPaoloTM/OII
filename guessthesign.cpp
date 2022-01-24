#include <iostream>
#include <fstream>

using namespace std;

char solve(long long A, long long B) {
  if (A==B && A>0) {
    return '+';
  } else if (A==B &A<0) {
    return '-';
  } else if (A>0 && B>0) {
    return '+';
  } else if (A<0 && B>0) {
    return '0';
  } else if (A<0 && B<0 && ((abs(A)%2!=0 && abs(B)%2!=0) || (abs(A)%2==0 && abs(B)%2==0))) {
    return '-';
  } else if (A<0 && B<0 && ((abs(A)%2!=0 && abs(B)%2==0) || (abs(A)%2==0 && abs(B)%2!=0))) {
    return '+';
  }


}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int T;

    in>>T;

    for (int i=0; i<T; i++) {
        long long A, B;
        in >> A;
        in >> B;
        out << solve(A, B) << endl;
    }

    return 0;
}
