#include <iostream>
using namespace std;

int factorial(int n){
  if(n == 0 || n == 1){
    return 1;
  }else if(n < 0){
    cout << "Invalid";
    return -1;
  }
  return n * factorial(n-1);
}

int combinatorics (int n, int r){
  return factorial(n) / (factorial(r) * factorial (n - r));
}

int permutation (int n, int r){
  return factorial(n) / factorial(n - r);
}

int main(){
  int n, r;
  cout << "N = " ;
  cin >> n;
  cout << "R = " ;
  cin >> r;
  if(n < r){
    cout << "Invalid Inputs";
    return -1;
  }
  cout << n << "!= " << factorial(n) << endl;
  cout << r << "!= " << factorial(r) << endl;
  cout << n << "P" << r << "=" << permutation(n, r) << endl;
  cout << n << "C" << r << "=" << combinatorics(n, r) << endl;
}