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
Vector<T>::Vector()
{
  m_head = nullptr;
}

template <class T>
Vector<T>::~Vector() {}

template <class T>
Vector<T> *Vector<T>::operator=(Vector<T> *source)
{
  Vector<T> *copy;
  copy = source;
  return copy;
}

template <class T>
T Vector<T>::operator[](int indx)
{
  T index;
  Node<T> *current = m_head;
  for (int i = 0; i < indx; i++)
  {
    current = current->getNextNode();
  }
  index = current->getValue();
  return index;
}

template <class T>
void Vector<T>::Insert(T node_value)
{
  Node<T> *node = new Node<T>(node_value);
  if (m_head == NULL)
  {
    m_head = node;
  }
  else
  {
    Node<T> *current = m_head;
    for (int i = 0; i < Vector<T>::Size() - 2; i++)
    {
      current = current->getNextNode();
    }
    current->setNextNode(node);
  }
}

template <class T>
void Vector<T>::SortedInsert(T node_value)
{
  Node<T> *node = new Node<T>(node_value);
  if (m_head == NULL || m_head->getValue() >= node->getValue())
  {
    node->setNextNode(m_head);
    m_head = node;
  }
  else
  {
    Node<T> *current = m_head;
    while (current->getNextNode() != NULL && current->getNextNode()->getValue() < node->getValue())
    {
      current = current->getNextNode();
    }
    node->setNextNode(current->getNextNode());
    current->setNextNode(node);
  }
}

template <class T>
void Vector<T>::Remove(int indx)
{
  Node<T> *current = m_head;
  for (int i = 0; i < indx - 1; i++)
  {
    current = current->getNextNode();
  }
  Node<T> *tmp = current;
  current = current->getNextNode();
  tmp->setNextNode(current->getNextNode());
  delete current;
}

template <class T>
Vector<T> *Vector<T>::operator+(Vector<T> &source)
{
  Node<T> *current_first = this->m_head;
  Node<T> *current_source = source.m_head;
  float added_value;
  Vector<T> *added_vector = new Vector<T>();
  for (int i = 0; i < Vector<T>::Size() - 1; i++)
  {
    added_value = (current_first->getValue() + current_source->getValue());
    added_vector->Insert(added_value);
    current_first = current_first->getNextNode();
    current_source = current_source->getNextNode();
  }
  return added_vector;
}

template <class T>
Vector<T> *Vector<T>::operator*(Vector<T> &other)
{
  Node<T> *current_first = this->m_head;
  Node<T> *current_source = other.m_head;
  float mul_value;
  Vector<T> *mul_vector = new Vector<T>();
  for (int i = 0; i < Vector<T>::Size() - 1; i++)
  {
    mul_value = (current_first->getValue() * current_source->getValue());
    mul_vector->Insert(mul_value);
    current_first = current_first->getNextNode();
    current_source = current_source->getNextNode();
  }
  return mul_vector;
}

template <class T>
Vector<char> *Vector<T>::operator<(Vector<T> &other)
{
  Node<T> *current_first = this->m_head;
  Node<T> *current_source = other.m_head;
  char bool_value;
  Vector<char> *bool_vector = new Vector<char>();
  for (int i = 0; i < Vector<T>::Size() - 1; i++)
  {
    bool_value = 'F';
    if (current_first->getValue() < current_source->getValue())
      bool_value = 'T';
    bool_vector->Insert(bool_value);
    current_first = current_first->getNextNode();
    current_source = current_source->getNextNode();
  }
  return bool_vector;
}

template <class T>
Vector<char> *Vector<T>::operator==(Vector<T> &other) {
  Node<T> *current_first = this->m_head;
  Node<T> *current_source = other.m_head;
  char bool_value;
  Vector<char> *bool_vector = new Vector<char>();
  for (int i = 0; i < Vector<T>::Size() - 1; i++)
  {
    bool_value = 'F';
    if (current_first->getValue() == current_source->getValue())
      bool_value = 'T';
    bool_vector->Insert(bool_value);
    current_first = current_first->getNextNode();
    current_source = current_source->getNextNode();
  }
  return bool_vector;
}

template <class T>
int Vector<T>::Size()
{
  int size = 0;
  if (m_head != NULL)
  {
    Node<T> *current = m_head;
    size = 1;
    while (current != NULL)
    {
      size++;
      current = current->getNextNode();
    }
  }
  return size;
}

template <class T>
void Vector<T>::Display()
{
  Node<T> *current = m_head;
  while (current != NULL)
  {
    if (current->getNextNode() != NULL)
      cout << current->getValue() << ", ";
    else
      cout << current->getValue();
    current = current->getNextNode();
  }
}

template <class T>
float Vector<T>::Median() {}

template <class T>
float Vector<T>::Mean() {}

template <class T>
float Vector<T>::StDev() {}

#endif /* VECTOR_CPP */
