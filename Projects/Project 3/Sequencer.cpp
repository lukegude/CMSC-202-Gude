#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "Sequencer.h"

using namespace std;

Sequencer::Sequencer(string filename)
{
    m_fileName = filename;
    Sequencer::ReadFile();
}

Sequencer::~Sequencer() {}

void Sequencer::DisplayStrands()
{
}

int Get_File_Lines(string filename)
{
    ifstream file(filename);
    string line;
    int line_counter = 0;
    while (getline(file, line))
    {
        line_counter++;
    }
    return line_counter;
}

void Sequencer::ReadFile()
{
    ifstream case_file(m_fileName);
    int num_line = Get_File_Lines(m_fileName);
    if (case_file.is_open())
    {

        for (int i = 0; i < num_line / 2; i++)
        {
            string name;
            string strand;
            getline(case_file, name);
            getline(case_file, strand);
            DNA new_Strand(name);
            for (int i = 0; i < strand.length(); i++)
            {
                if (strand[i] == ','){}
                else
                {
                    new_Strand.InsertEnd(strand[i]);
                }
            }
            if (name.find("Suspect")){
                m_suspects.push_back(&new_Strand);
            }
            else if (name.find("Evidence")){
                m_evidence.push_back(&new_Strand);
            }
        }
    }
}
