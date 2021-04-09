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
    for (int i = 0; i < m_farm.size(); i++)
    {
        delete m_farm[i];
    }
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
            m_farm.push_back(new Animal());
            cout << "New Animal added to the farm." << endl;
            break;
        }
        case 2: //Vegetable
        {
            m_farm.push_back(new Vegetable());
            cout << "New Vegetable added to the farm." << endl;
            break;
        }
        case 3: //Tree
        {
            m_farm.push_back(new Tree());
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
    for (int n = 0; n < season; n++)
    {
        vector<string> Harvested;
        for (int i = 0; i < m_farm.size(); i++)
        {
            bool gotHarvested;
            do
            {
                gotHarvested = false;
                if (m_farm.size() > 0)
                {
                    string type = m_farm[i]->GetType();

                    if (type == "Animal")
                    {
                        if (m_farm[i]->GetIsHarvestable())
                        {
                            int money = m_farm[i]->Harvest();
                            m_money += money;
                            Harvested.push_back("The " + m_farm[i]->GetType() + " was harvested");
                            delete m_farm[i];
                            m_farm.erase(m_farm.begin() + (i));
                            gotHarvested = true;
                        }
                        if (m_food != 0)
                        {
                            m_farm[i]->Tick(true);
                            m_food--;
                        }

                        else
                        {
                            m_farm[i]->Tick(false);
                        }
                    }
                    else if (type == "Vegetable")
                    {
                        if (m_farm[i]->GetIsHarvestable())
                        {
                            int food = m_farm[i]->Harvest();
                            m_food += food;
                            Harvested.push_back("The " + m_farm[i]->GetType() + " was harvested");
                            delete m_farm[i];
                            m_farm.erase(m_farm.begin() + (i));
                            gotHarvested = true;
                        }
                        m_farm[i]->Tick(true);
                    }
                    else if (type == "Tree")
                    {
                        if (m_farm[i]->GetIsHarvestable())
                        {
                            Harvested.push_back("The " + m_farm[i]->GetType() + " was harvested");
                            delete m_farm[i];
                            m_farm.erase(m_farm.begin() + (i));
                            gotHarvested = true;
                        }
                        else
                        {
                            m_farm[i]->Tick(true);
                        }
                    }
                }
            } while (gotHarvested);
        }
        cout << endl
             << "SEASON: " << m_season << endl;
        for (int i = 0; i < Harvested.size(); i++)
            cout << Harvested[i] << endl;
        Farm::Status();
        m_season++;
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
        {
            for (int i = 1; i < 4; i++)
            {
                Farm::AddItem(i, 2);
            }
            break;
        }
        case 3:
        {
            int tick_choice;
            cout << "How many seasons to simulate?" << endl;
            cin >> tick_choice;
            Farm::Tick(tick_choice);
            break;
        }
        case 4:
            Farm::Status();
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
    cout << "Food: " << m_food << endl;
    cout << "Money: " << m_money << endl;
    cout << "Season: " << m_season << endl;
    cout << "Agricultural Items:" << endl;
    if (m_farm.size() > 0)
    {
        for (int i = 0; i < m_farm.size(); i++)
        {
            (*m_farm.at(i)) << cout << endl;
        }
    }
    else
    {
        cout << "None" << endl;
    }
}