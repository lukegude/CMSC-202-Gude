/**************
 * File: lab5.cpp
 * The user creates this file to demonstrate use of a course.
 *************/

#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
  //**Student Requirement**
  //Part 1: Create 2 books by instantiating them
  Book book1;
  Book book2;
  //**Student Requirement**
  //Part 2: Set their values for book name, cover type, and amount of check-outs.
  book1.setName("Pride and Predudice");
  book1.setCheckout(0);
  book1.setHardcover(false);

  book2.setName("Cat in the Hat");
  book2.setCheckout(6);
  book2.setHardcover(true);

  //**Student Requirement**
  //Part 3: Output their information:  Name, cover type, and amount of check-outs
  cout << "Data of Book1:\n";
  cout << "Book Name: " << book1.getName() << endl;
  cout << "Number of Checkouts: " << book1.getCheckouts() << endl;
  cout << "Hardcover/Paperback: " << book1.isHardcover() << endl;

  cout << "Data of Book2:\n";
  cout << "Book Name: " << book2.getName() << endl;
  cout << "Number of Checkouts: " << book2.getCheckouts() << endl;
  cout << "Hardcover/Paperback: " << book2.isHardcover() << endl;

  //**Student Requirement**
  //Part 4: Call a custom function: Check if book is hard cover or not
  book1.checkHardCover();
  book2.checkHardCover();

  //**Student Requirement**
  //Part 5: Update data members with custom function: Add 1 check-out to the amount of check-outs
  //Display updated amount of check-outs
  book1.addCheckOut();
  book2.addCheckOut();

  return 0;
}
