#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int reduce(int& num, int& denom) {
  if (num <= 0 || denom <= 0) {
    return 0;
  }

  int commonFactor = gcd(num, denom);
  num /= commonFactor;
  denom /= commonFactor;

  return 1;
}

int main() {
  int m, n;
  bool inserting  = true;
  cout << "Start:" <<endl;
  while(inserting){
    string confirm;
    cout << "m= ";
    cin >> m;
    cout << "n= ";
    cin >> n;
    if (reduce(m, n)) cout << m << '/' << n << endl;
    else cout << "fraction error" << endl;
    cout << "Continue?[_anything_/no]: ";
    cin >> confirm;
    if(confirm != "no"){
      continue;
    }else{
      cout << "Loop stopped." << endl;
      break;
    }
  }

  return 0;
}