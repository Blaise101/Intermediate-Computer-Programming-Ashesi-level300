#include<iostream>
#include<cmath>
using namespace std;
int main(){
  double a, b, c, x1, x2;
  cout << "Enter the value of a: ";
  cin >> a;
  cout << "Enter the value of b: ";
  cin >> b;
  cout << "Enter the value of c: ";
  cin >> c;
  x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
  x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
  cout << "The roots are: " << x1 << " and " << x2 << endl;
}