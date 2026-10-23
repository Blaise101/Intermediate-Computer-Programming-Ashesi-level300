#include <iostream>

using namespace std;

int abs(int x);

int main(){
  
  cout << abs(-7) << endl;

  return 0;
}

int abs(int x){
  if(x < 0) x*=-1;
  return x;
}