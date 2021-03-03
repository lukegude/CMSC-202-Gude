#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

#include "Game.h"
using namespace std;

Game::Game(){};

void Game::LoadMaterials()
{
    string comp_name;
    string rarity;
    string req_comp_1;
    string req_comp_2;
    ifstream material_file(PROJ2_DATA);
    if (material_file.is_open())
    {
        for (int i = 0; i < PROJ2_SIZE; i++)
        {
            getline(material_file, comp_name, ',');
            getline(material_file, rarity, ',');
            getline(material_file, req_comp_1, ',');
            getline(material_file, req_comp_2);
            Material new_material(comp_name, rarity, req_comp_1, req_comp_2, 0);
            m_materials[i] = new_material;
        }
        cout << PROJ2_SIZE << " materials loaded" << endl;
    }
}

void Game::StartGame()
{
    int unique_item_count = 0;
    string ship_name;
    int menu_option = -1;
    Game::GameTitle();
    Game::LoadMaterials();
    cout << "What is the name of your ship\n";
    getline(cin, ship_name);
    Ship player_ship(ship_name);
    m_myShip = player_ship;
    while (menu_option != 5)
    {
        menu_option = Game::MainMenu();
        switch (menu_option)
        {
        case 1:
            Game::DisplayMaterials();
            break;
        case 2:
            Game::SearchMaterials();
            break;
        case 3:
            Game::CombineMaterials();
            break;
        case 4:
            Game::CalcScore();
        default:
            break;
        }
    }
}

void Game::DisplayMaterials()
{
    for (int i = 0; i < PROJ2_SIZE; i++)
    {
        cout << i + 1 << ". " << m_materials[i].m_name << " " << m_materials[i].m_quantity << "\n\n";
    }
}

int Game::MainMenu()
{
    int choice;
    cout << "\nWhat would you like to do\n\n1. Display your Ship's Materials\n\n2. Search for Raw Materials\n\n3. Attempt to Merge Materials\n\n4. See Score\n\n5. Quit\n\n";
    cin >> choice;
    while (choice > 5)
    {
        cout << "Choice must be between 1-5\n";
        cin >> choice;
    }
    return choice;
}

void Game::SearchMaterials()
{
    int searched_material = rand() % 24;
    int material_available = m_myShip.CheckMaterial(m_materials[searched_material]);
    if (material_available == -2)
    {
        m_materials[searched_material].m_quantity++;
        m_myShip.AddMaterial(m_materials[searched_material]);
    }
    else
    {
        m_materials[searched_material].m_quantity++;
        m_myShip.IncrementQuantity(m_materials[searched_material]);
    }

    cout << "You found " << m_materials[searched_material].m_name << endl;
}

void Game::CombineMaterials()
{
    Material combine_material[2];
    bool enoughMaterials1 = false;
    bool enoughMaterials2 = false;
    int choices[2];
    int choice;
    for (int i = 0; i < 2; i++)
    {
        Game::RequestMaterial(choice);
        choices[i] = choice - 1;
        int material_choice = m_myShip.CheckMaterial(m_materials[choice - 1]);
        if (material_choice != -2)
        {
            combine_material[i] = m_myShip.GetMaterial(material_choice);
        }
    }
    if (combine_material[0].m_name == combine_material[1].m_name)
    {
        if (combine_material[0].m_quantity > 1 && combine_material[1].m_quantity > 1)
        {
            enoughMaterials1 = true;
            enoughMaterials2 = true;
        }
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            switch (i)
            {
            case 0:
                if (combine_material[i].m_quantity > 0)
                {
                    enoughMaterials1 = true;
                }
                break;
            case 1:
                if (combine_material[i].m_quantity > 0)
                {
                    enoughMaterials2 = true;
                }
                break;
            }
        }
    }

    if (enoughMaterials1 && enoughMaterials2)
    {
        int found_recipe = Game::SearchRecipes(combine_material[0].m_name, combine_material[1].m_name);
        if (found_recipe == -1)
        {
            cout << "Nothing happened when you tried to combine " << m_materials[choices[0]].m_name << " and " << m_materials[choices[1]].m_name << endl;
        }
        else
        {
            if (m_materials[found_recipe].m_type != "unique" && m_materials[found_recipe].m_quantity < 1)
            {
                cout << combine_material[0].m_name << " combined with " << combine_material[1].m_name << " to make " << m_materials[found_recipe].m_name << endl;
                m_myShip.DecrementQuantity(combine_material[0]);
                m_myShip.DecrementQuantity(combine_material[1]);
                m_myShip.IncrementQuantity(m_materials[found_recipe]);
                m_materials[choices[0]].m_quantity--;
                m_materials[choices[1]].m_quantity--;
                m_materials[found_recipe].m_quantity++;
            }
            else
            {
                cout << "You can only have one of " << m_materials[found_recipe].m_name << endl;
            }
        }
    }
    else
    {
        int found_recipe = Game::SearchRecipes(m_materials[choices[0]].m_name, m_materials[choices[1]].m_name);
        if (found_recipe == -1)
        {
            cout << "Nothing happened when you tried to combine " << m_materials[choices[0]].m_name << " and " << m_materials[choices[1]].m_name << endl;
        }
        else
        {
            cout << "You do not have enough " << m_materials[choices[0]].m_name << " or " << m_materials[choices[1]].m_name << " to attempt that merge" << endl;
        }
    }
}

void Game::RequestMaterial(int &choice)
{
    cout << "Which materials would you like to merge?\n\nTo list known materials enter -1\n\n";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> choice;
    while (choice == -1)
    {
        Game::DisplayMaterials();
        cout << "\n\nWhich materials would you like to merge?\n\nTo list known materials enter -1\n\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice;
    }
}

int Game::SearchRecipes(string item1, string item2)
{
    for (int i = 0; i < PROJ2_SIZE; i++)
    {
        if ((item1 == m_materials[i].m_material1 || item1 == m_materials[i].m_material2) && (item2 == m_materials[i].m_material1 || item2 == m_materials[i].m_material2))
        {
            return i;
        }
    }
    return -1;
}

void Game::CalcScore()
{
    cout << "\t\t*** The Ship ***\n\n";
    cout << "The Great Ship " << m_myShip.GetName() << endl;
    cout << "Ship Rank: " << m_myShip.GetRank() << endl;
}
