#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "Sequencer.h"

using namespace std;

Sequencer::Sequencer(string filename){
    m_fileName = filename;
}

Sequencer::~Sequencer(){
    delete &m_fileName;
    delete &m_suspects;
    delete &m_evidence;
}

void Sequencer::DisplayStrands(){
    
}

