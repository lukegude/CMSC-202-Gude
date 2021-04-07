#include "Vegetable.h"

Vegetable::Vegetable()
{
}

int Vegetable::Harvest() {
    return 1;
}

void Vegetable::Tick(bool flag)
{
    if (Vegetable::GetSize() < MAX_VEG_SIZE)
    Vegetable::SetSize(Vegetable::GetSize()+1);
    if (Vegetable::GetSize() == MAX_VEG_SIZE)
    Vegetable::SetIsHarvestable(true);

}

string Vegetable::GetType() {
    return "Vegetable";
}

ostream &Vegetable::operator<<(ostream & os){
    string harvestable;
    switch(Vegetable::GetIsHarvestable()){
        case 0:
            harvestable = "Not Harvestable";
            break;
        case 1:
            harvestable = "Harvestable";
            break;
    }
    os << Vegetable::GetType() << CONCAT << harvestable << CONCAT << Veg_Size[Vegetable::GetSize()];
    return os;
};