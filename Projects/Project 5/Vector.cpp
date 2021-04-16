//
//  Vector.cpp
//  Project 5 - Templates
//
//  Created by Nathenael Dereb on 2/8/21.
//

#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
public:
  Node(T value)
  {
    m_value = value;
    next = nullptr;
  }

  Node(T value, Node *_next)
  {
    m_value = value;
    next = _next;
  }

  T getValue()
  {
    return m_value;
  }

  Node<T> *getNextNode()
  {
    return next;
  }

  void setNextNode(Node<T> *newNode)
  {
    next = newNode;
  }

private:
  T m_value;
  Node<T> *next;
};

template <class T>
class Vector
{
public:
  // Name: Default Constructor
  // Precondition: None (Must be templated)
  // Postcondition: Creates a vector using a linked list
  Vector();

  // Name: Destructor
  // Desc: Frees memory
  // Precondition: Existing Vector
  // Postcondition: Destructs existing Vector
  ~Vector();

  // Name: Copy Constructor
  // Desc: Copies an existing vector
  // Precondition: Existing Vector
  // Postcondition: Two identical vectors (in separate memory spaces)
  // Hint: Utilize overloaded [] operator
  Vector(Vector<T> const &source);

  // Name: Overloaded Assignment operator
  // Desc: Assingns a vector
  // Precondition: Existing Vector
  // Postcondition: Assigns a vector
  // Hint: Utilize overloaded [] operator
  Vector<T> *operator=(Vector<T> *source);

  // Name: Overloaded [] operator
  // Desc: to retrive use [indx]
  // Precondition: Existing Vector
  // Postcondition: Returns the value of the element at the given index
  T operator[](int indx);

  // Name: Insert
  // Desc: insert a node to the end of the vector
  // Precondition: Existing Vector
  // Postcondition: A vector with the newly added value
  void Insert(T);

  // Name: SortedInsert
  // Desc: Inserts a node into the vector at it's correct position (sorted ascendingly)
  // Precondition: Existing Vector
  // Postcondition: sorted vector (low to high)
  void SortedInsert(T);

  // Name: Remove
  // Desc: removes a node from the vector
  // Precondition: Existing Vector
  // Postcondition: A vector that holds the results of the vectors added
  void Remove(int indx);

  // Name: Overloaded + operator | Vector Addition
  // Desc: Adds two vectors and returns the result
  // Precondition: Existing Vector, vectors can be of different size
  // Postcondition: A vector that holds the results of the vectors added
  Vector<T> *operator+(Vector<T> &source);

  // Name: Overloaded * operator | Vector Multiplication
  // Desc: Multiplys two vectors and returns the result
  // Precondition: Existing Vector, vectors can be of different size
  // Postcondition: returns a vector that holds the results of the vectors multiplied
  Vector<T> *operator*(Vector<T> &other);

  // Name: Overloaded < operator | Vector Comparision
  // Desc: Compares two vectors [using the < operator] and returns the result
  // Precondition: Existing Vector -> vectors need to be of the same size
  // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
  Vector<char> *operator<(Vector<T> &other);

  // Name: Overloaded == operator | Vector Comparision
  // Desc: Compares two vectors [using the == operator] and returns the result
  // Precondition: Existing Vector, vectors need to be of the same size
  // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
  Vector<char> *operator==(Vector<T> &other);

  // Name: Size
  // Desc: number of nodes in Vector
  // Precondition: Existing Vector
  // Postcondition: returns the size of the vector
  int Size();

  // Name: Display
  // Desc: displays the contents of the vector
  // Precondition: Existing Vector
  // Postcondition: prints to console the contents of Vector
  void Display();

  // Name: median
  // Desc: Computes the median of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the median value
  float Median();

  // Name: Mean
  // Desc: Computes the mean of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the mean value
  float Mean();

  // Name: StDev
  // Desc: Computes the standard derivation of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the standard derivation
  float StDev();

private:
  Node<T> *m_head;
};

// **** Add class definition below ****

template <class T>
Vector<T>::Vector() {}

template <class T>
Vector<T>::~Vector() {}

template <class T>
Vector<T> *Vector<T>::operator=(Vector<T> *source) {}

template <class T>
T Vector<T>::operator[](int indx) {}

template <class T>
void Vector<T>::Insert(T node) {}

template <class T>
void Vector<T>::SortedInsert(T node) {}

template <class T>
void Vector<T>::Remove(int indx) {}

template <class T>
Vector<T> *Vector<T>::operator+(Vector<T> &source) {}

template <class T>
Vector<T> *Vector<T>::operator*(Vector<T> &other) {}

template <class T>
Vector<char> *Vector<T>::operator<(Vector<T> &other) {}

template <class T>
Vector<char> *Vector<T>::operator==(Vector<T> &other) {}

template <class T>
int Vector<T>::Size() {}

template <class T>
void Vector<T>::Display() {}

template <class T>
float Vector<T>::Median() {}

template <class T>
float Vector<T>::Mean() {}

template <class T>
float Vector<T>::StDev() {}

#endif /* VECTOR_CPP */
