/**********
* File: Book.h
* Intended for Lab 5: Classes
**********/

#ifndef BOOK_H //Header or Include Guards
#define BOOK_H //Header or Include Guards

#include <iostream>
#include <string>
using namespace std;

<<<<<<< HEAD
class Book
{
public:
  //Default constructor, already implemented.
  Book();

  //**Student Requirement**
  //Do the prototype for each of the functions described in the lab document

  //Returns name of the book
  string getName();

  //Sets name of the book
  void setName(string name);

  //Returns if book is hard cover or not
  bool isHardcover();

=======
class Book {
public:
  //Default constructor, already implemented.
  Book();
  
  //**Student Requirement**
  //Do the prototype for each of the functions described in the lab document
  
  //Returns name of the book
  string getName();
  
  //Sets name of the book
  void setName(string name);
  
  //Returns if book is hard cover or not
  bool isHardcover();
  
>>>>>>> 472530cd859bc92d532c5688f1e57555513dee88
  //Sets hard cover boolean
  void setHardcover(bool);

  //Returns the number of check-outs
  int getCheckouts();

<<<<<<< HEAD
  //Sets the number of check-outs
  void setCheckout(int checkout);

  //Outputs whether the book is hard cover or not
  void checkHardCover();

=======
  //Sets the number of check-outs 
  void setCheckout(int checkout);
  
  //Outputs whether the book is hard cover or not
  void checkHardCover();
  
>>>>>>> 472530cd859bc92d532c5688f1e57555513dee88
  //Adds one check-out to number of check-outs
  bool addCheckOut();

private:
  //**Student Requirement**
  //Create the member variables below as described in the lab document
<<<<<<< HEAD
  //name of book
  string m_bookName;
  //hard cover or not
  bool m_isHardCover;
  //number of check-outs
  int m_numCheckOuts;
=======
    //name of book
    string m_bookName;
    //hard cover or not
    bool m_isHardCover;
    //number of check-outs
    int m_numCheckOuts;
>>>>>>> 472530cd859bc92d532c5688f1e57555513dee88
};

#endif //End of Header Guard
