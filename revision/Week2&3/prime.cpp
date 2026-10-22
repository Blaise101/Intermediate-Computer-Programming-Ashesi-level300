#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num){
  if(num < 2) return false;
  for(int i = 2; i < num/2; i++){
    if(num%2 == 0) return false;
  }
  return true;
}

bool isOdd(int num){
  if(num%2 != 0){
    return true;
  }
  return false;
}

// bool isEven(int num){
//   return num % 2 == 0;
// }

int main(){
  int num, ab;
  bool checking = true;
  do{
    cout << "enter a number to check (0 to stop): ";
    cin >> num;
    if(num == 0){
      cout << "Loop exited!";
      break;
    }
    ab = abs(num);
    if(isPrime(ab)){
      cout << ab << " is a prime number!" << endl;
    }else{
      cout << ab << " is not a prime number!" << endl;
    }
    if(isOdd(ab)){
      cout << ab << " is an odd number" << endl; 
    }else{
      cout << ab << " is an even number" << endl; 
    }
  }while(checking);
  return 0;
}



