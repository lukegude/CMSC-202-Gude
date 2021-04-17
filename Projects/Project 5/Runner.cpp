//
//  Runner.cpp
//  Project 5 - Templates
//
//  Created by Nathenael Dereb
//

#ifndef RUNNER_CPP
#define RUNNER_CPP

#include <cstdlib>
#include "Vector.cpp"
using namespace std;

template <class T>
class Runner
{
public:
    // Name: Default Constructor
    // Precondition: None
    // Postcondition: Initiates state/environment
    Runner(Vector<T> *, Vector<T> *);

    // Name: mainMenu
    // Desc: Main Menu
    // Precondition: Existing Vectors
    // Postcondition: Handles various menu commands
    int mainMenu();

private:
    Vector<T> m_vector1;
    Vector<T> m_vector2;
};

// **** Add class definition below ****
template <class T>
Runner<T>::Runner(Vector<T> *vector1, Vector<T> *vector2)
{
    int choice;
    do
    {
        choice = Runner<T>::mainMenu();
        switch (choice)
        {
        case 1:
        {
            cout << "Vector 1: ";
            vector1->Display();
            cout << endl
                 << "Vector 2: ";
            vector2->Display();
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Vector1 < Vector2: ";
            Vector<T>* bool_vector = (*vector1) < (*vector2);
            bool_vector->Display();
            cout << endl;
        }
        case 4:
        {
            cout << "Vector1 + Vector2: ";
            Vector<T> *added_vector = (*vector1) + (*vector2);
            added_vector->Display();
            cout << endl;
            break;
        }
        case 5:
        {
            cout << "Vector1 * Vector2: ";
            Vector<T> *mul_vector = (*vector1) * (*vector2);
            mul_vector->Display();
            cout << endl;
            break;
        }
        default:
            break;
        }

    } while (choice != 9);
}

template <class T>
int Runner<T>::mainMenu()
{
    int choice;
    string options[] = {"Display Vectors", "Vector comparison (<)", "Vector comparison (==)", "Vector addition", "Vector multiplication", "Compute median", "Compute mean", "Compute Standard Derivation", "Exit"};
    do
    {
        cin.clear();
        cout << "Choose an option" << endl;
        for (int i = 0; i < 9; i++)
        {
            cout << i + 1 << ". " << options[i] << endl;
        }
        cin >> choice;
    } while (cin.fail() || choice > 9 || choice < 1);
    return choice;
}

#endif /* Runner_h */
