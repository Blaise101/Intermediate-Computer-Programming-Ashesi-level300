#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int sales_persons = 4;
  int products = 5;

  double sales[products][sales_persons] = {};

  int sales_person, product;
  double amount;

  cout << "Enter salesperson, product, and amount (0 to finish):\n";

  while(cin >> sales_person && sales_person != 0){
    cin >> product >> amount;
    sales[product - 1][sales_person - 1] += amount;
  }

  for (int s = 1; s <= sales_persons; s++) cout << setw(12) << "Sales " + to_string(s);

  cout << setw(12) << "Total" << endl;

  double columnTotals[sales_persons] = {};

  for (int p = 0; p < products; p++) {
    double rowTotal = 0;
    cout << setw(10) << p + 1;

    for (int s = 0; s < sales_persons; s++) {
      cout << setw(12) << sales[p][s];
      rowTotal += sales[p][s];
      columnTotals[s] += sales[p][s];
    }

    cout << setw(12) << rowTotal << endl;
  }

    double grandTotal = 0;
    cout << setw(10) << "Total";
    for (int s = 0; s < sales_persons; s++) {
      cout << setw(12) << columnTotals[s];
      grandTotal += columnTotals[s];
    }
    cout << setw(12) << grandTotal << endl;

  return 0;
}