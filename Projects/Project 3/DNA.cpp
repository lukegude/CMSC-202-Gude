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
    Node *new_node, *temp;
    m_size++;
    if (new_node == nullptr)
    {
        m_head = temp;
        temp->m_next = nullptr;
        return;
    }
    while (new_node->m_next != NULL)
    {
        new_node = new_node->m_next;
    }
    temp->m_next = NULL;
    new_node->m_next = temp;
}

string DNA::GetName()
{
    return m_name;
}

int DNA::GetSize(){
    return m_size;
}