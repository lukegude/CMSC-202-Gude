#ifndef BIRD_H
#define BIRD_H


#include "Pet.h"

class Bird : public Pet
{
    public:
    Bird(string name, string color, int age, string breed);
    string getSpecies();
    void setSpecies(string species);
    void speak();
    private:
    string m_species;
};

#endif // BIRD_H