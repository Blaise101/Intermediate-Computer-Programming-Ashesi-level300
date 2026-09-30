#include <iostream>
#include <cmath>
using namespace std;

double mean(double scores[], int len){
  double sum = 0;
  for(int i = 0; i< len; i++){
    sum += scores[i];
  }
  return sum/len;
}

double stdev(double scores[], int len, double mean_val){
  mean_val = mean(scores, len);
  double sum = 0;
  for (int i = 0; i < len; i++){
    sum += pow((scores[i] - mean_val),2);
  }
  int n = len-1; 
  return sqrt(sum/n);
}

int main(){
  double scores[] = {12,32,45,10.3,34,23,43,23,64,93,46,54,23,56,63,23,45,32,12,45,76,43};
  cout << mean(scores, 22) << endl;
  cout << stdev(scores, 22, mean(scores, 22) ) << endl;
  return 0;
}