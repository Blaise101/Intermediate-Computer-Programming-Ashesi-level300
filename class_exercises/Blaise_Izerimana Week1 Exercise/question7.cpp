#include<iostream>
#include<iomanip>

int main(){
  int d1, d2;
  double interestRate = 0.0152, interest, averageDailyBalance, netBalance, payment;
  
  std::cout<<"Enter the net balance shown in the bill: ";
  std::cin>>netBalance;
  std::cout<<"Enter the payment made: ";
  std::cin>>payment;
  std::cout<<"How many days in the billing cirlce: ";
  std::cin>>d1;
  std::cout<<"How many days is the payment made before the billing circle: ";
  std::cin>>d2;

  averageDailyBalance = (netBalance * d1 - payment *d2) / d1;
  interest = averageDailyBalance * interestRate;
  std::cout<<"The interest is: ";
  std::cout<<std::fixed<<std::setprecision(2)<<interest<<std::endl;


}