#include "Animal.h"

Animal::Animal()
{
    m_name = "Chicken";
}

void Animal::Tick(bool isFed)
{
    if (isFed)
    {
        if (Animal::GetSize() < ANIMAL_MAX_SIZE)
            Animal::SetSize(Animal::GetSize() + 1);
    }
    else if (m_IsHungry && !isFed)
    {
        Animal::SetIsHarvestable(true);
    }
    else if (!m_IsHungry && !isFed)
    {
        m_IsHungry = true;
    }
    if (Animal::GetSize() == ANIMAL_MAX_SIZE)
    {
        Animal::SetIsHarvestable(true);
    }
}

int Animal::Harvest()
{
    int money;
    money = Animal::GetWorth() * Animal::GetSize();
    return money;
}

string Animal::GetType()
{
    return "Animal";
}

ostream &Animal::operator<<(ostream &os)
{
    string harvestable;
    string fed;
    switch (Animal::GetIsHarvestable())
    {
    case 0:
        harvestable = "Not Harvestable";
        break;
    case 1:
        harvestable = "Harvestable";
        break;
    default:
        break;
    }

    switch (Animal::m_IsHungry)
    {
    case 1:
        fed = "Not Fed";
        break;
    case 0:
        fed = "Fed";
        break;
    default:
        break;
    }

    os << Animal::GetType() << CONCAT << Animal::m_name << CONCAT << harvestable << CONCAT << ANIMAL_SIZE[Animal::GetSize()] << CONCAT << fed;
    return os;
};
