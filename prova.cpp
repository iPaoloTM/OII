#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        {return n;}
    else
      {
        return fib(n-1) + fib(n-2);
      }


}

int fact(int n) {
  if (n==1) {
    return 1;
  }
  else {
    cout<<n<<"*"<<n-1<<"="<<n*(n-1)<<endl;
    return n*fact(n-1);
  }

}

int main ()
{
    int n;
    cin>>n;
    cout << fib(n)<<endl;
    cout<<fact(n)<<endl;
    //getchar();
    return 0;
}
