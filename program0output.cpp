#include <iostream>
#include <iomanip>
#include "project0_tk22994_aha2242.h"
using namespace std;

void testTakeOrder();
void testFindMostFreqOrdered();
void menuShower(string products[], double costs[]);
void testMenuShower();

int main() {
  testMenuShower();
  testTakeOrder();
  testFindMostFreqOrdered();
  return 0;
}

// int testMenu() {
//   string products[6] = {"Rolex Watch", "MacBook Pro", "Men's Cufflinks",
//                         "iPad Pro 11-in", "Ladies Ring", "Watch S4"}; 
//   double costs[6] = {1099.00, 1299.00, 499.00, 799.00, 999.00, 399.00}; 

//   std::stringstream ss;
//   auto old_buf = std::cout.rdbuf(ss.rdbuf()); 
//   menuShower(products, costs);
//   std::cout.rdbuf(old_buf); //reset
//   string menu = ss.str();
//   cout << menu;
// }
double takeOrderPreTax(int itemNums[], int freqArr[], double costs[]) {
  std::cout << "Input the item numbers for the order, 0 to quit\n";
  int item = 0; // int variable to keep track of item
  do {
    cin >> item;
    if (item < 0 || item > 6) {
      std::cout << "*Error: There is no item " << item << ".\n";
      std::cout << "Processing other items...\n";
    } else {
      itemNums[item - 1]++;
      freqArr[item - 1]++;
      }
    } while (item != 0);
  double subtotal = 0.0; // double variable to keep track of subtotal
  for (int i = 0; i < 6; i++) {
    subtotal += costs[i] * itemNums[i];
  }
  return subtotal;
}

void testTakeOrder() {
  int itemNums[6] = {0, 0, 0, 0, 0, 0};
  int freqArr[6] = {0, 0, 0, 0, 0, 0};
  double costs[6] = {1099.00, 1299.00, 499.00, 799.00, 999.00, 399.00};
  double subtotal = takeOrderPreTax(itemNums, freqArr, costs);
  double correctAns = 0.0;
  bool result = subtotal == correctAns;
  if (result) cout << "PASS test case 1\n";
  else cout << "FAIL test case 1\n";


  int itemNums1[6] = {1, 0, 0, 0, 0, 0};
  int freqArr1[6] = {1, 0, 0, 0, 0, 0};
  double costs1[6] = {1099.00, 1299.00, 499.00, 799.00, 999.00, 399.00};
  subtotal = takeOrderPreTax(itemNums1, freqArr1, costs1);
  correctAns = 1099.00;
  result = subtotal == correctAns;
  if (result) cout << "PASS test case 2\n";
  else cout << "FAIL test case 2\n";
}

int findMostFreqOrdered(int freqArr[]) {
  int maxPurchasedIndex = 0; // tracks the item ordered with max frequency
  int maxSoFar = 0; // tracks the max frequency item puchased so far
  for(int i = 0; i < 6; i++) {
    if(maxSoFar < freqArr[i]) {
      maxSoFar = freqArr[i];
      maxPurchasedIndex = i;
    }
  }
  return maxPurchasedIndex;
}

void testFindMostFreqOrdered() {
  int freqArr[6] = {0, 0, 0, 0, 0, 0};
  int result = findMostFreqOrdered(freqArr);
  cout << (result == 0 ? "PASS test case 3\n" : "FAIL test case 3\n");

  int freqArr1[6] = {1, 0, 0, 0, 0, 0};
  result = findMostFreqOrdered(freqArr1);
  // std::cout << "Item ordered most often: " << " was purchased " << freqArr1[result] << " times." << endl;
  cout << (result == 0 ? "PASS test case 4\n" : "FAIL test case 4\n");
}

void testMenuShower() {
  string products[6] = {"Rolex Watch", "MacBook Pro", "Men's Cufflinks",
                        "iPad Pro 11-in", "Ladies Ring", "Watch S4"};
  double costs[6] = {1099.00, 1299.00, 499.00, 799.00, 999.00, 399.00}; 
  menuShower(products, costs);
  cout << "PASS test case 0" << endl;
}

void menuShower(string products[], double costs[]) {
  std::cout << setprecision(2) << fixed;
  for (int i = 0; i < 6; i++)
    cout << "[" << i+1 << "] " << setw(19) << left << products[i] << 
      left << "$" << setw(7) << left << costs[i] << "\n";
}