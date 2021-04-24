#include <iostream>
#include <string>
using namespace std;

//*********Write mySwap prototype here***********
template <class T>
void mySwap(T &first, T &second){
     T temp = first;
     first = second;
     second = temp;
}



//**********************************************

int main() {
  int x, y;
  string s1, s2;
  
  cout << "Enter 2 ints separated by spaces:" << endl;
  cin >> x >> y;

  cin.ignore(256, '\n');

  cout << "Enter string 1:" << endl;
  getline(cin, s1);

  cout << "Enter string 2:" << endl;
  getline(cin, s2);

  cout << "\nBefore mySwap:" << endl
       << "x: " << x << endl
       << "y: " << y << endl
       << "s1: " << s1 << endl
       << "s2: " << s2 << endl;

  mySwap(x, y);
  mySwap(s1, s2);

  cout << "\nAfter mySwap:" << endl
       << "x: " << x << endl
       << "y: " << y << endl
       << "s1: " << s1 << endl
       << "s2: " << s2 << endl;
  
  return 0;
}

//***********Write mySwap implementation here***************

