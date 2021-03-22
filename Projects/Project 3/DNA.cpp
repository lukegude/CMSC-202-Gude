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
    while (current != NULL){
        output << current->m_data << "->";
        current = current -> m_next;
    }
    output << "END";
    return output;
    // for(int i = 0; i< myDNA.GetSize(); i++){
    //     output << myDNA.GetData(i) << "->";
    // }

    
}