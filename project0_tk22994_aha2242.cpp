/* 
// File Name: project0_tk22994_yyyyy.cpp
// Authors: Tushar Kohli, Abdallah Al-Sukhni
// Date: 10 Sep 2022
// Assignment Number 0
// CS 105C Spring 2022
// Instructor: Dr. Palacios

// SpaceX vending app offers high-end products on its menu to its customers
// on its future commercial flights */
#include <iostream>
#include <iomanip>
#include "project0_tk22994_aha2242.h"
using namespace std;

int main() {
  // log: worked on by Tushar and Abdallah
  char continueOrNo = 'N'; /* double variable to decide whether 
                           // the user wants to exit or continue the program */
  double totalSales = 0.0; /* char variable to keep track of the total sales
                           // throughout each time the user 
                           // continues the program */
  int freqArr[6] = {0, 0, 0, 0, 0, 0}; /* int array to keep track of
                                       // frequencies throughout each time
                                       // user contiunues program */
  string products[6] = {"Rolex Watch", "MacBook Pro", "Men's Cufflinks",
                        "iPad Pro 11-in", "Ladies Ring", "Watch S4"}; 
                        // string array to keep track of products
  double costs[6] = {1099.00, 1299.00, 499.00, 799.00, 999.00, 399.00}; 
                                // double array to keep track of product costs
  const double TAX = 0.0825; // constant double to represent tax
  
  do {
    menuShower(products, costs);
    int itemNums[6] = {0, 0, 0, 0, 0, 0}; // int array that keeps track
                                          // of amount of each item ordered
    double subtotal = takeOrderPreTax(itemNums, freqArr, costs); 
            // double variable to keep track of subtotal of items purchased
    double taxAmount = subtotal * TAX;  // double variable to keep track of 
                                        // tax after subtotal is 
                                        // multiplied by TAX constant
    double total = subtotal + taxAmount; // double variable to keep track 
                                         // of overall total of items
    totalSales += total;
    std::cout << "Subtotal...$ " << setw(7) << right << subtotal << endl;
    std::cout << "Tax........$ " << setw(7) << right << taxAmount << endl;
    std::cout << "Total......$ " << setw(7) << right << total << endl;
    std::cout << "\nPlease enter 'N' to take a new order and 'E' to exit: "; 
    cin >> continueOrNo;
  } while (continueOrNo == 'N');
  
  int mostFreqOrderedItemIndex = findMostFreqOrdered(freqArr); // variable used to 
                                            // find most frequent item ordered index
  // all arrays used are aligned so that each items number corresponds to 
  // its index in each array - 1
  std::cout << "*** End of Day:" << endl;
  std::cout << "Total sales: $" << totalSales << endl;
  std::cout << "Item ordered most often: " << products[mostFreqOrderedItemIndex] << " was purchased " << freqArr[mostFreqOrderedItemIndex] << " times." << endl;
  
  return 0;
}

/************************************************************
// Log: Worked on by Tushar
// menuShower: displays the menu (item number, description, price)
// products array of product information
// costs array of cost information
************************************************************/ 
void menuShower(string products[], double costs[]) {
  std::cout << setprecision(2) << fixed;
  for (int i = 0; i < 6; i++)
    cout << "[" << i+1 << "] " << setw(19) << left << products[i] << 
      left << "$" << setw(7) << left << costs[i] << "\n";
}

/************************************************************
// log: worked on by Abdallah 
// takeOrderPreTax: calculates the subtotal of all items purchased and recieves the user's purchases 
// int itemNums[]: int array that keeps track of amount of each item ordered 
// int freqArr[]: int array to keep track of frequencies throughout each time user contiunues program
// double costs[]: double array that keeps track of the cost of each item
// returns: double variable subtotal which is the subtotal of all items ordered before tax
************************************************************/
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

/************************************************************
// Log: worked on by Tushar
// findMostFreqOrdered: determines the product with the highest order count
// freqArr the array of player information
// size the number of products in the array
// returns: the product that customers ordered the most
************************************************************/ 
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