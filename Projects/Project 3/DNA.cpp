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
    Node *tmp = new Node;
    tmp->m_data = data;
    tmp->m_next = NULL;
    if (m_head == NULL)
    {
        m_head = tmp;
        m_tail = tmp;
    }
    else
    {
        m_tail->m_next = tmp;
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