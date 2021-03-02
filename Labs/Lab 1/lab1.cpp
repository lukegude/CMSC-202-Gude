/*******************************************************************
** File: lab1.cpp 
** Lab: CMSC 202 Lab 1, Spring 2021
** Author: Luke Gude
** Date: 01/27/2021
** Section: 10/12
** E-Mail: lgude1@umbc.edu
**
** This is the source code for Lab 1
*******************************************************************/
#include <iostream>
using namespace std;
int main()
{
    char cats_name[80];
    int cat_age;
    int choice;
    cout << "What is your cat's name?\n";
    cin >> cats_name;
    cout << "How old is your cat\n";
    cin >> cat_age;
    while (cat_age < 0 or cat_age > 22 or cin.fail())
    {
        cout << "Please enter your cat's age, it should be an integer between 0 and 22\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> cat_age;
    }
    cout << "Cat Name = " << cats_name << "\n"
         << "Cat Age = " << cat_age << "\n\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "What would you like to do?\n1. Pet Kitty\n2. Feed Kitty\n3. Chase Kitty\nEnter your choice:\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice;
        while (cin.fail() or choice > 3 or choice < 1)
        {
            cout << "Enter your choice (1-3): \n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }
        if (choice == 1)
        {
            cout << "You pet Kitty and they purr.\n";
        }
        else if (choice == 2)
        {
            cout << "Kitty meows gently as you feed them.\n";
        }
        else if (choice == 3)
        {
            cout << "You chase after Kitty and they hiss and try to bite.\n";
        }
    }
    cout << "That is enough for today. Good-bye\n";
}