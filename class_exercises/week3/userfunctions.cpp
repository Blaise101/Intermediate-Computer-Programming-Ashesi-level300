#include <iostream>

using namespace std;

int sum(int num1, int num2){
  return num1 + num2;
}
int abs(int number){
  if(number < 0) number = -number;
  return number;
}

int main(){
 int mysum = sum(4, abs(-5));
 cout << mysum;
 return 0;
}