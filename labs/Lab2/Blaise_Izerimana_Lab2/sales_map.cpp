#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
  const int sales_persons = 4;
  const int products = 5;

  map<int, map<int, double>> sales;

  int salesperson, product;
  double amount;

  cout << "Enter salesperson, product, and amount (0 to finish):" << endl;

  while (cin >> salesperson && salesperson != 0) {
    cin >> product >> amount;
    sales[product][salesperson] += amount;
  }

  cout << fixed << setprecision(2);
  cout << endl << "Sales Summary" << endl;
  cout << setw(10) << "Product";

  for (int s = 1; s <= sales_persons; s++) cout << setw(12) << "Sales " + to_string(s);

  cout << setw(12) << "Total" << endl;

  map<int, double> columnTotals;

  for (int p = 1; p <= products; p++) {
    double rowTotal = 0;
    cout << setw(10) << p;

    for (int s = 1; s <= sales_persons; s++) {
      double value = 0;
      auto productIt = sales.find(p);
      if (productIt != sales.end()) {
        auto salespersonIt = productIt->second.find(s);
        if (salespersonIt != productIt->second.end()){
          value = salespersonIt->second;
        }
      }

      cout << setw(12) << value;
      rowTotal += value;
      columnTotals[s] += value;
    }

    cout << setw(12) << rowTotal << endl;
  }

  double grandTotal = 0;
  cout << setw(10) << "Total";
  for (int s = 1; s <= sales_persons; s++) {
    cout << setw(12) << columnTotals[s];
    grandTotal += columnTotals[s];
  }
  cout << setw(12) << grandTotal << endl;

  return 0;
}
