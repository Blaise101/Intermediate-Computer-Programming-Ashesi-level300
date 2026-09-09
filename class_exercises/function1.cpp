#include<iostream>
#include<cmath>
using namespace std;
int main(){
  double x, f;
  cout << "Enter the value of x: ";
  cin >> x;
  double test = (sin(x)-pow(x,5))/(log(x)+(x/4));
  f = test >0 ? sqrt(test) : 0;
  cout << "The result is: " << f << endl;
}