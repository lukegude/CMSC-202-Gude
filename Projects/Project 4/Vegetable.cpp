#include "Vegetable.h"

Vegetable::Vegetable()
{
}

int Vegetable::Harvest()
{
    return 1;
}

void Vegetable::Tick(bool flag)
{
    if (Vegetable::GetSize() < MAX_VEG_SIZE)
        Vegetable::SetSize(Vegetable::GetSize() + 1);
    if (Vegetable::GetSize() == MAX_VEG_SIZE)
        Vegetable::SetIsHarvestable(true);
}

string Vegetable::GetType()
{
    return "Vegetable";
}

ostream &Vegetable::operator<<(ostream &os)
{
    string harvestable;
    if (Vegetable::GetIsHarvestable())
    {
        harvestable = "Not Harvestable";
    }
    else
    {
        harvestable = "Harvestable";
    }

    os << Vegetable::GetType() << CONCAT << harvestable << CONCAT << Veg_Size[Vegetable::GetSize()];
    return os;
};