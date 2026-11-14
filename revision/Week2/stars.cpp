#include <iostream>

using namespace std;

void stars1(){
  for(int i = 0; i <= 5; i++){
    for(int j = 0; j <= i; j++ ){
      cout << "*";
    }
    for(int j = 5; j > i; j-- ){
      cout << " ";
    }
    cout << endl;
  }
  for(int i = 0; i <= 5; i++){
    for(int j = 5; j > i; j-- ){
      cout << "*";
    }
    for(int j = 0; j <= i; j++ ){
      cout << " ";
    }
    cout << endl;
  }
}

void stars2(){
  for(int i = 0; i <= 5; i++){
    for(int j = 5; j > i; j-- ){
      cout << " ";
    }
    for(int j = 0; j <= i; j++ ){
      cout << "*";
    }
    cout << endl;
  }
  for(int i = 0; i <= 5; i++){
    for(int j = 5; j > i; j-- ){
      cout << "*";
    }
    for(int j = 0; j <= i; j++ ){
      cout << " ";
    }
    cout << endl;
  }
}

void stars3(){
  for(int i=0; i<5; i++){
    for(int j=5; j>i; j--){
      cout << " ";
    }
    for(int k = 0; k<=i; k++){
      cout << "*";
    }
    for(int k = 0; k<i; k++){
      cout << "*";
    }
    cout << endl;
  }
  for(int i=0; i<=5; i++){
    for(int j=0; j<i; j++){
      cout << " ";
    }
    for(int k = 5; k>=i; k--){
      cout << "*";
    }
    for(int k = 5; k>i; k--){
      cout << "*";
    }
    cout << endl;
  }
}



int main(){

  cout << endl;
  stars1();
  stars2();
  stars3();

  return 0;
}