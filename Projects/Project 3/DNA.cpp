#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "DNA.h"
using namespace std;

DNA::DNA()
{
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

DNA::DNA(string name)
{
    m_name = name;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

DNA::~DNA()
{
    while (m_head != NULL)
    {
        Node *temp = m_head->m_next; //sets the temp Node to the linked next node
        if (temp != NULL)
        {
            delete m_head; //deletes each node in the list
        }

        m_head = temp;
    }
    delete m_head;
    delete m_tail;
}

void DNA::InsertEnd(char data)
{
    Node *temp = new Node; //New node allocated
    temp->m_data = data;
    temp->m_next = NULL;
    if (m_head == NULL)
    {
        m_head = temp; //sets only one node in the list
        m_tail = temp;
    }
    else
    {
        m_tail->m_next = temp; //adds to the list
        m_tail = m_tail->m_next;
    }
    m_size++;       //increases the size of the DNA strand
    temp = nullptr; //sets temp memory to null
    delete temp;    //deallocates the memory
}

string DNA::GetName()
{
    return m_name;
}

int DNA::GetSize()
{
    return m_size;
}

bool DNA::CompareSequence(DNA &evidence)
{

    int evidence_size = evidence.GetSize(); //variable for size of the evidence strand for looping
    Node *temp;                             //temp node to hold the main position for Suspect DNA
    Node *current;                          //Node that iterates through the Suspect; if there is no match then the current is set to temp
    Node *evidence_curr;                    //Node that is checked with current while iterating through a match
    evidence_curr = evidence.m_head;
    current = m_head;
    temp = current;
    while (temp != NULL)
    {
        current = temp;
        for (int i = 0; i < evidence_size; i++) //iterates as long as the evidence strand
        {
            if (current != NULL)
            {
                if (current->m_data == evidence_curr->m_data)
                //if there is a match, it keeps iterating through the evidence and suspect simultaneously
                {
                    current = current->m_next;
                    evidence_curr = evidence_curr->m_next;
                }
            }
        }
        if (evidence_curr == NULL) //if the evidence reaches the end, there is a match
        {
            return true;
        }
        else //else, it goes to the next node in the Suspect and loops again
        {
            temp = temp->m_next;
            evidence_curr = evidence.m_head;
        }
    }
    return false; //if the evidence never reaches the end, then there is no match
}

void DNA::ReverseSequence()
{
    Node *current = m_head; //Start of the Strand
    Node *head = m_head;    //Constant for the start of the strand to set the tail
    Node *previous;         //To be set to the current node
    Node *next;             //Holds the next position
    previous = nullptr; 
    next = nullptr;    

    while (current != NULL)
    {
        next = current->m_next;
        current->m_next = previous;
        previous = current;
        current = next;
    }
    m_head = previous;
    m_tail = head;
}

char DNA::GetData(int nodeNum)
{
    Node *current; //Iterated Node
    current = m_head;
    for (int i = 0; i < nodeNum - 1; i++)
    {
        current = current->m_next;
    }
    return current->m_data;
}

ostream &operator<<(ostream &output, DNA &myDNA)
{
    output << myDNA.m_name << endl;
    Node *current = myDNA.m_head;
    while (current != NULL)
    {
        output << current->m_data << "->";
        current = current->m_next;
    }
    output << "END";
    return output;
}