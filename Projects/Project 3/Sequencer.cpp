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
    Sequencer::MainMenu();
}

Sequencer::~Sequencer()
{
    int suspect_size = m_suspects.size();
    int evidence_size = m_evidence.size();
    cout << "DNA removed from memory\n";
    cout << "Deleting Suspects\n";
    for (int i = 0; i < suspect_size;i++){
        delete m_suspects[i];
        m_suspects[i] = NULL;
    }
    m_suspects.clear();
    cout << "Deleting Evidence\n";
    for (int i = 0; i < evidence_size; i++){
        delete m_evidence[i];
        m_evidence[i] = NULL;
    }
    m_evidence.clear();
}

void Sequencer::MainMenu()
{
    int choice;
    do
    {
        cout << "What would you like to do?:\n\n";
        cout << "1. Display Strand\n\n";
        cout << "2. Reverse Sequence\n\n";
        cout << "3. Check Suspects\n\n";
        cout << "4. Exit\n\n";
        cin >> choice;
        if (choice > 4 || choice < 1 || cin.fail())
        {
            cin.clear();
            cout << "You must choose between 1 and 4\n";
        }
        switch (choice)
        {
        case 1:
            Sequencer::DisplayStrands();
            break;
        case 2:
            Sequencer::ReverseSequence();
            break;
        case 3:
            Sequencer::CheckSuspects();
            break;
        case 4:
            break;

        default:
            break;
        }
    } while (choice != 4);
}

void Sequencer::DisplayStrands()
{
    for (int i = 0; i < m_suspects.size(); i++)
    {
        cout << *m_suspects[i] << endl
             << endl;
    }
    for (int i = 0; i < m_evidence.size(); i++)
    {
        cout << *m_evidence[i] << endl;
    }
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

void Sequencer::CheckSuspects()
{
    for (int i = 0; i < m_suspects.size(); i++)
    {
        for (int j = 0; j < m_evidence.size(); j++)
        {
            if (m_suspects[i]->CompareSequence(*m_evidence[j]))
            {
                cout << "Suspect " << i + 1 << " matches Evidence " << j + 1 << endl;
            }
            else
            {
                cout << "Suspect " << i + 1 << " does NOT match Evidence " << j + 1 << endl;
            }
        }
    }
}

void Sequencer::ReadFile()
{
    int strands_loaded;
    ifstream case_file(m_fileName);
    int num_line = Get_File_Lines(m_fileName);
    if (case_file.is_open())
    {
        cout << "Opened File" << endl;
        for (int i = 0; i < num_line / 2; i++)
        {
            string name;
            string strand;
            getline(case_file, name);
            getline(case_file, strand);
            DNA *new_Strand = new DNA(name);
            for (int i = 0; i < strand.length(); i++)
            {
                if (strand[i] == ',')
                {
                }
                else
                {
                    new_Strand->InsertEnd(strand[i]);
                }
            }
            if (name.find("Suspect") && !name.find("Evidence"))
            {
                m_evidence.push_back(new_Strand);
            }
            else if (name.find("Evidence") && !name.find("Suspect"))
            {
                m_suspects.push_back(new_Strand);
            }
        }
        strands_loaded = m_suspects.size() + m_evidence.size();
        cout << strands_loaded << " strands loaded." << endl;
        case_file.close();
    }
}

void Sequencer::ReverseSequence(){
    int choice;
    cout << "What type of sequence to reverse?\n";
    cout << "1. Suspect\n";
    cout << "2. Evidence\n";
    cin >> choice;
    while (cin.fail()|| choice > 2 || choice < 1){
        cin.clear();
        cout << "Must choose 1 or 2\n";
        cout << "What type of sequence to reverse?\n";
        cout << "1. Suspect\n";
        cout << "2. Evidence\n";
        cin >> choice;
    }
    switch (choice){
        case 1:

        for (int i = 0; i < m_suspects.size();i++){
            m_suspects[i]->ReverseSequence();
        }
            break;
        case 2:
            for (int i = 0; i < m_evidence.size(); i++)
            {
                m_evidence[i]->ReverseSequence();
            }
            break;
        default:
            break;
    }
}
