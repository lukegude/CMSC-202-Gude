#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "DNA.h"
using namespace std;

DNA::DNA(){
    m_head = nullptr;
    m_tail = nullptr;
}

DNA::DNA(string name){
    m_name = name;
    m_head = nullptr;
    m_tail = nullptr;
}

DNA::~DNA()
{
    delete m_head;
    delete m_tail;
}

void DNA::InsertEnd(char data){
    Node new_node;
    new_node.m_data = data;
    new_node.m_next = nullptr;
}

string DNA::GetName(){
    return m_name;
}