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
Runner<T>::Runner(Vector<T>*,Vector<T>*){}

template <class T>
int Runner<T>::mainMenu(){}






#endif /* Runner_h */


