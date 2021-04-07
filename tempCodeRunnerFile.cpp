#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int> v; 
    for (int i = 0; i < 6; i++){
        v.push_back(i+1);
    }
    for (int i = 0; i < v.size();i++){
        if (v[i] == 3){
            v.erase(v.begin()+(i));
            if (v[i] == 4){
                cout << "Same Loop" << endl;
            }
        }
    }

    for (auto n:v){
        cout << n << endl;
    }

}