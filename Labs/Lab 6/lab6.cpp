//File: lab6.cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Candy.h"
using namespace std;

void fillVector(vector<Candy> &candyList)
{
  int amount;
  cout << "How many candy bars do you want to buy?: ";
  cin >> amount;
  for (int i = 0; i < amount; i++)
  {
    cin.clear();
    cin.ignore(256, '\n');
    string name;
    double price;
    int quantity;
    cout << "Candy Bar #" << i + 1 << " name: ";
    getline(cin, name);
    cout << "Candy Bar #" << i + 1 << " price: ";
    cin >> price;
    cout << "Candy Bar #" << i + 1 << " quantity: ";
    cin >> quantity;
    candyList.push_back(Candy(name, price, quantity));
  }
}

void printVectorWithoutIterator(vector<Candy> &candyList)
{
  cout << "Candy stats (without Iterator)" << endl;
  
  for (unsigned int i = 0; i < candyList.size(); i++)
  {
    double total = candyList[i].getPrice() * candyList[i].getQuantity();
    cout << "Candy " << i + 1 << " Name: " << candyList[i].getName() << endl;
    cout << "Price: " << candyList[i].getPrice() << endl;
    cout << "Quantity: " << candyList[i].getQuantity() << endl;
    cout << "Total Cost: ";
    cout << fixed << setprecision(2) << total << endl;

  }
}

void printVectorWithIterator(vector<Candy> &candyList)
{
//   cout << "Candy stats (with Iterator)" << endl;
//   for (vector<Candy>::iterator it = candyList.begin(); it != candyList.end(); ++it){
//     int quantity = (*it).getQuantity();
//     double total = ()

// cout << "Candy " << i + 1 << " Name: " << candyList[i].getName() << endl;
//     cout << "Price: " << candyList[i].getPrice() << endl;
//     cout << "Quantity: " << candyList[i].getQuantity() << endl;
//     cout << "Total Cost: ";
//     cout << fixed << setprecision(2) << total << endl;
//   }
  //We will be doing more with iterators during a later lab but if you are done with everything
  //else, please try to complete this function
}

int main()
{

  vector<Candy> candyList;

  fillVector(candyList);
  printVectorWithoutIterator(candyList);
  cout << endl;
  //  printVectorWithIterator(candyList); //If done with other functions, complete this one

  return 0;
}
