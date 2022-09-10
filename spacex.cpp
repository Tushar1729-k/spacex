// sample C++ program
#include <iostream>
#include <string>
using namespace std;

int main() {
  string products[6] = {"[1] Rolex Watch", "[2] MacBook Pro", "[3] Men's Cufflinks",
              "[4] iPad Pro 11-in", "[5] Ladies Ring", "[6] Watch S4"};
  for (int i = 0; i < 6; i++)
    cout << products[i] + "\n";
  int itemNums[6] = {0, 0, 0, 0, 0, 0};
  cout << "Input the item numbers for the order, 0 to quit\n";
  int item;
  cin >> item;
  int i = 0;
  while (item != 0) {
    itemNums[i] = item;
    cin >> item;
  }
  for (i = 0; i < sizeof(itemNums)/sizeof(itemNums[0]); i++)
    std::cout << itemNums[i] << ' ';
  cout << "\n";
  return 0;
}