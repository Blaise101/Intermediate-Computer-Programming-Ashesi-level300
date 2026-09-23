#include <iostream>
#include <cmath>
using namespace std;

double interest(double r, int m){
  return (r/100) / m;
}


double repay(double L, int m, int t, double r){
  double i = interest(r, m);
  return ((L*i)/(1 - pow((1+i),(-m*t)))) + L;
}

double unpaid(int k, double L, int m, int t, double r){
  double i = interest(r, m);
  return repay(L, m, t, r)*((1- pow((1+i),-(m*t - k)))/i);
}

int main(){
  double L, r;
  int m, t, k;
  cout << "Ammount = ";
  cin >> L;
  cout << "Rate/year(%) = ";
  cin >> r;
  cout  << "Number of payments = ";
  cin >> m;
  cout << "Time of loan(in Years) = ";
  cin >> t;
  cout << "You will pay back " << repay(L, m, t, r) << endl;
  cout << "Number of years not paid = ";
  cin >> k;
  cout << "Unpaid balance = " << unpaid(k, L, m, t, r) << endl;
  return 0;
}