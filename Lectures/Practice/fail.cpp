#include <iostream>
#include <string>
using namespace std;
int main()
{
    int age;
    cout << "Age" << endl;
    cin >> age;

    if(cin.fail()){
        cin.clear();
        cin.ignore(256, '\n');
        cout << "as an integer" << endl;
        cin >> age;
    }
    cout << age << endl;
}