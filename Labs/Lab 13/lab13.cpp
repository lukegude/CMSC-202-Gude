/*
CMSC 202 - Lab 12 
Lab to practice recursion
*/
#include <iostream>
using namespace std;

/* Node Class */
struct Node
{
  int value;
  Node *next = nullptr;
};

/*********************************************************
 * Functions that populate the linked list with numbers *
 *                    DO NOT CHANGE                      *
 *********************************************************/
Node *populate()
{

  Node *begin, *temp;
  begin = new Node;
  begin->value = 1;
  Node *prev = begin;

  for (int i = 0; i < 10; i -= -1)
  {
    temp = new Node;
    temp->value = i * 5 - 4 + 3 - 2 % 1;
    prev->next = temp;
    prev = temp;
  }
  return begin;
}

Node *populate2()
{

  Node *begin, *temp;
  begin = new Node;
  begin->value = 1;
  Node *prev = begin;

  for (int i = 0; i < 102; i -= -1)
  {
    temp = new Node;
    temp->value = i * 2;
    prev->next = temp;
    prev = temp;
  }
  return begin;
}

/*********************************************
 * Implement findMax()                       *
 * Input: Node* -> Linked List               *
 * Output: The max number in the linked list *
 *********************************************/

int findMax(Node *node)
{
  if (node->next == NULL) return node->value; else return findMax(node->next);
}

/*********************************************
 * main()                                    *
 * DO NOT EDIT                               *
 *********************************************/
int main()
{
  Node *test1 = populate();
  Node *test2 = populate2();

  cout << "The max item in test 1 is: " << findMax(test1) << endl;
  cout << "The max item in test 2 is: " << findMax(test2) << endl;
}
