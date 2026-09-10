#include<iostream>

int main(){
  double mass, density, volume;
  std::cout<< "Enter the mass in grams: ";
  std::cin >> mass;
  std::cout<< "Enter the density in grams per cubic centimeter: ";
  std::cin >> density;
  volume = mass / density;
  std::cout<< "The volume is " << volume << " cubic centimeters." << std::endl;
  return 0;
}