#include <iostream>

int main(){
  
  int a, b;
  std::string greet;
  
  std::cout << "enter your way of greeting ";
  std::getline(std::cin, greet); // read the whole line

  std::cout << "enter a and b: ";
  std::cin >> a >> b ;

  std::cout << greet << "!" << std::endl;
  std::cout << a << " * " << b << " = " << a*b << std::endl;

  return 0;
}