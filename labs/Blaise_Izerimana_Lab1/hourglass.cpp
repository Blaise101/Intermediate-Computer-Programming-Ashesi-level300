#include <iostream>
using namespace std;

int main() {
  const int halfRows = 6;

  // First part
  for (int i = halfRows; i >= 1; i--) {
    for (int space = 0; space < halfRows - i; space++) {
      cout << " ";
    }
    
    for (int star = 0; star < i; star++) {
      cout << "* ";
    }
    
    cout << endl;
  }

  // Last part
  for (int i = 1; i <= halfRows; i++) {
    for (int space = 0; space < halfRows - i; space++) {
      cout << " ";
    }
    
    for (int star = 0; star < i; star++) {
      cout << "* ";
    }
    
    cout << endl;
  }

  return 0;
}