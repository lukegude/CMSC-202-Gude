#include "Tree.h"

Tree::Tree()
{
    m_age = 0;
}

Tree::~Tree()
{
    for (int i = 0; i < m_fruit.size(); i++)
    {
        delete m_fruit[i];
    }
}

void Tree::Tick(bool flag)
{
    if (Tree::GetSize() < 3)
    {
        if (m_age % 4 == 0)
        {
            Tree::SetSize(Tree::GetSize() + 1);
        }
    }
    else
    {
        if (m_age % 12 == 0)
        {
            m_fruit.push_back(new Fruit());
        }
    }
    if (m_age == 60)
    {
        Tree::SetIsHarvestable(true);
    }
    m_age++;
}

int Tree::Harvest()
{
    int fruit = m_fruit.size();
    for (int i = 0; i < m_fruit.size(); i++){
        delete m_fruit[i];
    }
    m_fruit.clear();
    return fruit;
}

string Tree::GetType()
{
    return "Tree";
}

ostream &Tree::operator<<(ostream &os)
{
    string harvestable;
    string fruiting;
    if (Tree::GetIsHarvestable())
    {
        harvestable = "Harvestable";
    }
    else
    {
        harvestable = "Not Harvestable";
    }
    if (m_age > 12)
    {
        fruiting = "Fruiting";
    }
    else
    {
        fruiting = "Not Fruiting";
    }
    os << Tree::GetType() << CONCAT << TREE_SIZE[Tree::GetSize()] << CONCAT << harvestable << CONCAT << fruiting << CONCAT << "Fruit Count: " << m_fruit.size();
    return os;
};