#include <iostream>
#include <string>

#include "AgItem.h"
using namespace std;

AgItem::AgItem(){
    m_size = 0;
    m_isHarvestable = false;
    m_worth = BASE_WORTH;
};

AgItem::AgItem(int size, int worth, bool isHarvestable){
    m_size =size;
    m_isHarvestable = isHarvestable;
    m_worth = worth;
}

AgItem::~AgItem(){}

int AgItem::GetSize(){
    return m_size;
}

int AgItem::GetWorth(){
    return m_worth;
}

bool AgItem::GetIsHarvestable(){
    return m_isHarvestable;
}

void AgItem::SetSize(int size){
    m_size = size;
}

void AgItem::SetIsHarvestable(bool isAlive){
    m_isHarvestable = isAlive;
}

void AgItem::SetWorth(int worth){
    m_worth = worth;
}

ostream& AgItem::operator<<(ostream& os){}
