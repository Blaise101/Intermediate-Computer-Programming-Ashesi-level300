#include <iostream>

using namespace std;

int main(){
  int i = 1;
  while(i <= 5){
    cout << "Hello" << endl;
    i++;
  }
  
  cout << endl;
  for(int j = 1; j <= 5; j++){
    cout << "Hello" << endl;
  }
  
  cout << endl;
  i = 1;
  do{
    cout << "Hello" << endl;
    i++;
  }while(i <= 5);

  return 0;
}