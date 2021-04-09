#include "Bird.h"

Bird::Bird(string name, string color, int age, string species): Pet(color,name,age){
    setSpecies(species);
}

string Bird::getSpecies()
{
    return m_species;
}

void Bird::setSpecies(string species)
{
   m_species = species;
}
void Bird::speak()
{
    cout << getName() << " the " << getColor() << " " << getAge() << " year old " << getSpecies() << " chirps!" << endl;
}