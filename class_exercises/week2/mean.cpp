#include <iostream>

using namespace std;

int main(){
  double sum = 0;
  int count = 0;
  int N;
  cout << "Enter the number of students: ";
  cin >> N;
  while(count < N){
    int score;
    cout << "Enter scores (0 - 100) for student " << count + 1 <<": ";
    cin >> score;
    if(score < 0 || score > 100){
      cout << "Score out of bound" << endl;
      continue;
    }
    sum += score;
    count++;
  }
  cout << "THe average is: " << sum/N << endl;

  // With centinel
  float score = 0;
  count = 0;
  sum = 0;
  while(score != -1){
    cout << "Enter scores (0 - 100) for student " << count + 1 <<"[use '-1' to stop]: ";
    cin >> score;
    if(score >= 0 && score <= 100){
      sum += score;
      count++;
    }else{
      cout << "Score out of bound" << endl;
    }
  }
  cout << "THe average is: " << sum/count << endl;

  return 0;
}