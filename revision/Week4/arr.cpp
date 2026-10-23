#include <iostream> 
using namespace std;
int main(){
  int myList[5] = {0, 4, 8, 12, 16};
  int yourList[5];
  yourList = myList;
  for(int num : yourList){
    cout << num;
  }
  return 0;
}