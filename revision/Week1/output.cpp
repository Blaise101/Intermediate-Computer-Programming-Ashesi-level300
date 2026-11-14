#include <iostream>
#include <iomanip>

using namespace std;

int main (){
  cout << 1 << setw(4) << 3 << endl;
  cout << 11 << setw(4) << setfill('%') << 3 << endl;
  cout << 11 << setfill('*') << 3 << endl;

  return 0;
}