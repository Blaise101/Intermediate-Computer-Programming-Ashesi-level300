#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n;
  double pi;
  cout << "enter your N: ";
  cin >> n;
  for(int i = 0; i <= n; i++){
    pi += pow(-1, i)/((2*i) +1);
  }
  cout << "fido = " << pi*4;
  return 0;
}