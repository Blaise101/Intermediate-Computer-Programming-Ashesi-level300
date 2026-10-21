#include <iostream>

using namespace std;

int main(){

  int a = 0;
  int b = 0;
  cout << 5.0/2.0 << " " << a++ << " " << ++b;
  cout << endl;
  cout << a << endl;
  // cout << 5.0/2.0 << " " << a++ << " " << ++b;

  int x = 10;
  int y = ++x;
  int r = 20;
  int s = r++;
  cout << "X=" << x << " and " << "Y= " << y << endl;
  cout << "R=" << r << " and " << "S= " << s << endl;

  for(int i=0; i<4; i++){
    cout << i;
  }
 
  return 0;
}