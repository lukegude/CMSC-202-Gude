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
    delete m_head;
    delete m_tail;
}

void DNA::InsertEnd(char data)
{
    Node *temp = new Node;
    temp->m_data = data;
    temp->m_next = NULL;
    if (m_head == NULL)
    {
        m_head = temp;
        m_tail = temp;
    }
    else
    {
        m_tail->m_next = temp;
        m_tail = m_tail->m_next;
    }
    m_size++;
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

    int evidence_size = evidence.GetSize();
    Node *temp, *current, *evidence_curr;
    evidence_curr = evidence.m_head;
    current = m_head;
    temp = current;
    while (temp != NULL)
    {
        current = temp;
        for (int i = 0; i < evidence_size; i++)
        {
            if (current->m_data == evidence_curr->m_data)
            {
                current = current->m_next;
                evidence_curr = evidence_curr->m_next;
            }
        }
        if (evidence_curr == NULL)
        {
            return true;
        }
        else
        {
            temp = temp->m_next;
            evidence_curr = evidence.m_head;
        }
    }
    return false;
}

char DNA::GetData(int nodeNum)
{
    Node *current;
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