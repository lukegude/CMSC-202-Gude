#include "Book.h"

//Constructor -- Already Implemented
<<<<<<< HEAD
Book::Book()
{
=======
Book::Book() {
>>>>>>> 472530cd859bc92d532c5688f1e57555513dee88
  cout << "Creating a book..." << endl;
  m_bookName = "book";
  m_isHardCover = false;
  m_numCheckOuts = 0;
}

//Here is an example for a getter and a setter

<<<<<<< HEAD
int Book::getCheckouts()
{
  return m_numCheckOuts;
}

void Book::setCheckout(int numTimes)
{
  //If number of check-outs is greater than 6, set to 6.
  if (numTimes > 6)
  {
    m_numCheckOuts = 6;
  }
  else
  {
=======
int Book::getCheckouts() {
  return m_numCheckOuts;
}

void Book::setCheckout(int numTimes) {
  //If number of check-outs is greater than 6, set to 6.
  if (numTimes > 6){
    m_numCheckOuts = 6;
  } else {
>>>>>>> 472530cd859bc92d532c5688f1e57555513dee88
    m_numCheckOuts = numTimes;
  }
}

//**Student Requirement**
//Implement getters and setters for bookName and isHardCover here
<<<<<<< HEAD
void Book::setName(string name)
{
  m_bookName = name;
}
string Book::getName()
{
  return m_bookName;
}

bool Book::isHardcover()
{
  return m_isHardCover;
}
void Book::setHardcover(bool hardcover)
{
  m_isHardCover = hardcover;
}

//**Student Requirement**
//Custom Functions -- Implement checkHardCover and addCheckOut

void Book::checkHardCover()
{
  bool isHardcovered = Book::isHardcover();

  if (isHardcovered)
  {
    cout << m_bookName << " is hardcovered\n";
  }
  else
  {
    cout << m_bookName << " is a paperback book\n";
  }
}

bool Book::addCheckOut()
{
  int checkouts = Book::getCheckouts();
  if (checkouts >= 6)
  {
    cout << "This book has been checked out too many times already\n";
    return false;
  }
  else
  {
=======
void Book::setName(string name){
  m_bookName = name;
}
string Book::getName(){
  return m_bookName;
}

bool Book::isHardcover(){
  return m_isHardCover;
}
void Book::setHardcover(bool hardcover){
  m_isHardCover = hardcover;
}




//**Student Requirement**
//Custom Functions -- Implement checkHardCover and addCheckOut

void Book::checkHardCover(){
  bool isHardcovered = Book::isHardcover();
  
  

  if (isHardcovered){
    cout << m_bookName << " is hardcovered\n";
  }
  else{
    cout << m_bookName << " is a paperback book\n";
  }

}

bool Book::addCheckOut(){
  int checkouts = Book::getCheckouts();
  if (checkouts >= 6){
    cout << "This book has been checked out too many times already\n";
    return false;
  }
  else {
>>>>>>> 472530cd859bc92d532c5688f1e57555513dee88
    checkouts++;
    Book::setCheckout(checkouts);
    cout << "This book has been checked out\n";
    return true;
  }
  return true;
}
