#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

#include "Ship.h"
using namespace std;

Ship::Ship()
{
    m_shipRank = 'D';
};

Ship::Ship(string name)
{
    m_shipName = name;
    m_shipRank = 'D';
}

string Ship::GetName()
{
    return m_shipName;
}

void Ship::SetName(string name)
{
    m_shipName = name;
}

int Ship::CheckMaterial(Material newMaterial)
{

    for (int i = 0; i < m_numMaterials; i++)
    {
        if (newMaterial.m_name == m_myMaterials[i].m_name)
        {
            return i;
        }
    }
    return -2;
}

void Ship::AddMaterial(Material new_material)
{
    m_myMaterials[m_numMaterials] = new_material;
    m_numMaterials++;
}

void Ship::IncrementQuantity(Material new_material)
{
    int material_index = Ship::CheckMaterial(new_material);
    m_myMaterials[material_index].m_quantity++;
}

bool Ship::DecrementQuantity(Material new_material)
{
    int found_material = Ship::CheckMaterial(new_material);
    if (found_material != -2)
    {
        if (m_myMaterials[found_material].m_quantity > 0)
        {
            m_myMaterials[found_material].m_quantity--;
            return true;
        }
    }
    return false;
}

bool Ship::CheckQuantity(Material material1, Material material2)
{
    if (Ship::CheckMaterial(material1) != -2 && Ship::CheckMaterial(material2) != -2)
    {
        return true;
    }
    return false;
}

Material Ship::GetMaterial(int index)
{
    return m_myMaterials[index];
}

void Ship::IncRank()
{
    switch (Ship::GetRank())
    {
    case 'D':
        m_shipRank = RANKS[1];
        break;
    case 'C':
        m_shipRank = RANKS[2];
        break;
    case 'B':
        m_shipRank = RANKS[3];
        break;
    case 'A':
        m_shipRank = RANKS[4];
        break;

    default:
        break;
    }
}

char Ship::GetRank()
{
    return m_shipRank;
}
