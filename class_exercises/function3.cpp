#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double pi = 3.14;
  double epslon = 0.00001;
  double s, x, m, f;
  cout << "Enter the value of x: ";
  cin >> x;
  cout << "Enter the value of m: ";
  cin >> m;
  cout << "Enter the value of s: ";
  cin >> s;

  f = (1/sqrt(2*pi*s))*pow(epslon,((-1/2)*pow(((x-m)/s),2)));
  cout << "The result is: " << f << endl;
}