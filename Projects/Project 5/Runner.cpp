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
class Runner {
public:
    // Name: Default Constructor
    // Precondition: None
    // Postcondition: Initiates state/environment
    Runner(Vector<T>*, Vector<T>*);
    
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
Runner<T>::Runner(Vector<T>*,Vector<T>*){
    int choice;
    do {
    choice = Runner<T>::mainMenu();
    } while (choice != 9);
}

template <class T>
int Runner<T>::mainMenu(){
    int choice;
    string options[] = {"Display Vectors", "Vector comparison (<)", "Vector comparison (==)", "Vector addition", "Vector multiplication", "Compute median", "Compute mean", "Compute Standard Derivation", "Exit"};
    cout << "Choose an option" << endl;
    for (int i = 0; i < 9; i++){
        cout << i+1 << ". " << options[i] << endl;
    }
    cin >> choice;
    return choice;

}






#endif /* Runner_h */


