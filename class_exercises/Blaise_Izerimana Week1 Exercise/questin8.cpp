/*Linda is starting a new cosmetic and clothing business and would like to make a net profit of approximately 10% after paying all the expenses, which include merchandise cost, store rent, employees’ salary, and electricity cost for the store. She would like to know how much the merchandise should be marked up so that after paying all the expenses at the end of the year she gets approximately 10% net profit on the merchandise cost. Note that after marking up the price of an item she would like to put the item on 15% sale. Write a C++ program that prompts Linda to enter the total cost of the merchandise, the salary of the employees (including her own salary), the yearly rent, and the estimated electricity cost. The program then outputs how much the merchandise should be marked up so that Linda gets the desired profit.*/

#include<iostream>

int main(){
  double costOfMerchandise, employeeSalaries, yearlyRent, estimatedElectricityCost;
  double totalExpenses, desiredProfit, netprofit, markupPercentage;

  std::cout << "what is the total cost of the merchandise: ";
  std::cin>> costOfMerchandise;
  std::cout<<"What is the total salary paid to the employees including your own salary: ";
  std::cin>> employeeSalaries;
  std::cout<< "what is the yearly rent:";
  std::cin>> yearlyRent;
  std::cout<< "what is the estimated electricity cost:";
  std::cin>> estimatedElectricityCost;

  totalExpenses = employeeSalaries + yearlyRent + estimatedElectricityCost;
  desiredProfit = 0.10 * costOfMerchandise;
  netprofit = desiredProfit - totalExpenses;
  markupPercentage = (netprofit / costOfMerchandise) * 100;

  std::cout << "The merchandise should be marked up by " << markupPercentage << "%." << std::endl;

}
