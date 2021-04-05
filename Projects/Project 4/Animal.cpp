#include "Animal.h"

Animal::Animal()
{
    m_name = "Chicken";
}

void Animal::Tick(bool IsHarvestable)
{
}

int Animal::Harvest()
{
}

string Animal::GetType()
{
    return m_name;
}

ostream &Animal::operator<<(ostream &os)
{
    os << "Animal" << CONCAT << Animal::GetType() << CONCAT << Animal::GetIsHarvestable() << CONCAT << Animal::GetSize() << "Fed" << endl;
    return os;
};
