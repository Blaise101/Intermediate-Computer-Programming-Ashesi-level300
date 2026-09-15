#include <iostream>

using namespace std;

int main(){
  float num1, num2, result;
  char symbol;
  cout << "Enter first number: ";
  cin >> num1;
  cout << "Enter second number: ";
  cin >> num2;
  cout << "Which operation would you like to perform? (+, -, *, /): ";
  cin >> symbol;
  cout << symbol << endl;
  switch(symbol){
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if(num2 == 0){
        cout << "Denominator can't be ";
        return 0;
      }else{
        result = num1 / num2;
      }
      break;
    case '%':
      result = int(num1) % int(num2);
      break;
    default:
        cout << "Invalid symbol";
        return 0;
      break;
  }
  cout << num1 << " " << symbol << " " << num2 << " = " << result;
  return 0;
}