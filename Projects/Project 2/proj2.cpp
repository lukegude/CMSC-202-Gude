
/*******************************************************************
** File: proj2.cpp 
** Project: CMSC 202 Project 2, Spring 2021
** Author: Luke Gude
** Date: 02/26/2021
** Section: 10/12
** E-Mail: lgude1@umbc.edu
**
** This is the main file for Project 2
*******************************************************************/

#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main () {
  srand(time(NULL));
  Game newGame;
  newGame.StartGame();
  return 0;
}
