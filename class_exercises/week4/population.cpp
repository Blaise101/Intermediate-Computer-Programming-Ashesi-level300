#include <iostream> 

using namespace std;

void getFrequensices(const array<unsigned int, int N> responses){
  int frequencies[][] = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}};
  for int(i = 0; i < 5; i++){
    for (int j = 0; j < 20; j++){
      if(responses[j] == frequencies[i][0]){
        frequencies[i][1]++;
      }
    }
  }
  for int(i = 0; i < 5; i++){
    cout << frequencies[i][0] << " " << frequencies[i][1] << endl;
  }

  // return frecuencies;
}

int main(){

  array<unsigned int, 20> responses{1,2,4,5,4,2,5,3,4,3,4,3,2,5,5,2,5,5,1,5};

  frequencies(responses);


  return 0;
}