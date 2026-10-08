#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
  const int sales_persons = 4;
  const int products = 5;

  vector<vector<double>> sales(products, vector<double>(sales_persons, 0));

  int salesperson, product;
  double amount;

  cout << "Enter salesperson, product, and amount (0 to finish):" << endl;

  while (cin >> salesperson && salesperson != 0) {
    cin >> product >> amount;
    sales[product - 1][salesperson - 1] += amount;
  }

  cout << fixed << setprecision(2);
  cout << endl << "Sales Summary" << endl;
  cout << setw(10) << "Product";

  for (int s = 1; s <= sales_persons; ++s) cout << setw(12) << "Sales " + to_string(s);

  cout << setw(12) << "Total" << endl;

  vector<double> columnTotals(sales_persons, 0);

  for (int p = 0; p < products; ++p) {
    double rowTotal = 0;
    cout << setw(10) << p + 1;

    for (int s = 0; s < sales_persons; ++s) {
      cout << setw(12) << sales[p][s];
      rowTotal += sales[p][s];
      columnTotals[s] += sales[p][s];
    }

    cout << setw(12) << rowTotal << endl;
  }

  double grandTotal = 0;
  cout << setw(10) << "Total";
  for (int s = 0; s < sales_persons; ++s) {
    cout << setw(12) << columnTotals[s];
    grandTotal += columnTotals[s];
  }
  cout << setw(12) << grandTotal << endl;

  return 0;
}
