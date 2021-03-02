#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string comp_name;
    string rarity;
    string req_comp_1;
    string req_comp_2;

    ifstream myfile("proj2_data.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, comp_name, ','))
        {
            
            getline(myfile, rarity, ',');
            getline(myfile, req_comp_1, ',');
            getline(myfile, req_comp_2, ',');
            cout << comp_name << " " << rarity << " " << req_comp_1 << " " << req_comp_2 << " ";
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    return 0;
}