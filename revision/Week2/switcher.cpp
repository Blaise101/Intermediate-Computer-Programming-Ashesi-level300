#include <iostream>

using namespace std;

int main() {

  int x;
  cin >> x;
  switch(x){
    case (4):
      cout << x << " is greater than 4" << endl;
      break;
    case (5):
      cout << x << " is less than or equal to 4" << endl;
      break;
    default:
      cout << x << " is equal to " << x << endl;
      break;
  }

  return 0;
}