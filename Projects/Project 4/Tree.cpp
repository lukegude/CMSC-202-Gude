#include "Tree.h"

Tree::Tree(){
    m_age = 0;
}

Tree::~Tree()
{}

void Tree::Tick(bool flag){}

int Tree::Harvest(){}

string Tree::GetType(){
    return "Tree";
}

ostream& Tree::operator<<(ostream& os){
    string harvestable;
    switch (Tree::GetIsHarvestable())
    {
    case 0:
        harvestable = "Not Harvestable";
        break;
    case 1:
        harvestable = "Harvestable";
        break;
    }
    os << Tree::GetType() << CONCAT << TREE_SIZE[Tree::GetSize()] << CONCAT << harvestable << CONCAT << "Not Fruiting" << CONCAT << "Fruit Count: " << m_fruit.size();
    return os;
};