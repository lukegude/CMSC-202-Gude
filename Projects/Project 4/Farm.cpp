#include "Farm.h"

using namespace std;

Farm::Farm()
{
    m_food = 6;
    m_season = 1;
    m_money = 0;
}

Farm::~Farm()
{
}

int Farm::ChooseItem()
{
    string ag_items[] = {"Animal", "Vegetable", "Tree"};
    int chosen_item;
    cout << "Which agricultural item are you interested in?" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << ag_items[i] << endl;
    }
    cin >> chosen_item;

    return chosen_item;
}

void Farm::AddItem(int type, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        switch (type)
        {
        case 1: //Animal
        {
            Animal *chicken = new Animal;
            m_farm.push_back(chicken);
            delete chicken;
            cout << "New Animal added to the farm." << endl;
            break;
        }
        case 2: //Vegetable
        {
            Vegetable *vegetable = new Vegetable();
            m_farm.push_back(vegetable);
            delete vegetable;
            cout << "New Vegetable added to the farm." << endl;
            break;
        }
        case 3: //Tree
        {
            Tree *tree = new Tree();
            m_farm.push_back(tree);
            delete tree;
            cout << "New Tree added to the farm." << endl;
            break;
        }
        default:
            break;
        }
    }
}

void Farm::Tick(int season)
{
    for (int i = 0; i < season; i++)
    {
        cout << "SEASON: " << m_season << endl;
    }
}

int Farm::Menu()
{
    int choice;
    cout << "1. Add Item to Farm" << endl;
    cout << "2. Add Two of Each Item to Farm" << endl;
    cout << "3. Simulate Time" << endl;
    cout << "4. Farm Status" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;
    while (cin.fail() || choice > 5 || choice < 1)
    {
        cin.clear();
        cin.ignore();
        cout << "You must choose a number between 1 and 5" << endl;
        cin >> choice;
    }
    return choice;
}
void Farm::StartSimulation()
{
    cout << "Welcome to Stardew Valley Simulator" << endl;
    int choice;
    do
    {
        choice = Farm::Menu();
        switch (choice)
        {
        case 1:
        {
            int type = Farm::ChooseItem();
            Farm::AddItem(type, 1);
            break;
        }
        case 2:
            break;
        case 3:
            cout << "How many seasons to simulate?" << endl;
            cin >> choice;
            Farm::Tick(choice);
            break;
        case 4:
            break;
        case 5:
            cout << "Thank you for simulating Stardew Valley!" << endl;
            break;
        default:
            break;
        }
    } while (choice != 5);
}

void Farm::Status()
{
    cout << "\t**** Farm Status ****" << endl;
}