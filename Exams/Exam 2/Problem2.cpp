/* Expected Output

20->15->10->5->END
20->15->END


Given the following information about a singly-linked list, you are going to write two functions. 
The first function (InsertAt) inserts a node at a specific location in the linked list. 
You are passing the node and the position (starting at 0) to InsertAt. 
The second function (PrintList) displays the content in the linked list. (don’t forget about the special cases!) 
There should be NO memory leaks after your code runs.

*/

#include <iostream>

using namespace std;

struct Node
{
    Node(int data)
    {
        m_data = data;
    }
    int m_data;
    Node *m_next;
};

class LinkedList
{
public:
    LinkedList()
    {
        m_head = nullptr;
        m_size = 0;
    }

    void InsertBegin(Node *myNode)
    {
        myNode->m_next = nullptr;
        if (m_head == nullptr)
        {
            m_head = myNode;
        }
        else
        {
            myNode->m_next = m_head;
            m_head = myNode;
        }
        m_size++;
    }

    //Write InsertAt
    void InsertAt(Node *myNode, int position){
        Node *current = m_head;
        Node *tmp;
        for (int i = 0; i < position - 1; i++){
            current = current->m_next;
        }
        tmp = current->m_next;
        current->m_next = myNode;
        current = current->m_next;
        current->m_next = tmp;
    }

    void DeleteEnd()
    {
        Node *cur = m_head;
        Node *prev = cur;
        if (m_head == nullptr)
        {
            cout << "LL Empty" << endl;
            return;
        }
        else if (cur->m_next == nullptr)
        {
            delete cur;
            m_head = nullptr;
        }
        else
        {
            while (cur->m_next != nullptr)
            {
                prev = cur;
                cur = cur->m_next;
            }
            prev->m_next = nullptr;
            delete cur;
        }
        m_size--;
    }

    //Write PrintList

    void PrintList(){
        Node *current = m_head;
        while (current != NULL){
            cout << current->m_data << "->";
            current = current->m_next;
        }
        cout << "END" << endl;
    }

private:
    Node *m_head; //Head of the linked list
    int m_size;   //Size of the linked list
};

int main()
{
    LinkedList list;
    Node *newNode1 = new Node(5);
    Node *newNode2 = new Node(10);
    Node *newNode3 = new Node(15);
    list.InsertBegin(newNode1);
    list.InsertBegin(newNode2);
    list.InsertBegin(newNode3);
    Node *newNode4 = new Node(20);
    list.InsertAt(newNode4, 0);
    list.PrintList(); //Should 20->15->10->5->END
    list.DeleteEnd();
    list.DeleteEnd();
    list.PrintList(); //Should output 15->END
    list.DeleteEnd();
    list.DeleteEnd();
    return 0;
}