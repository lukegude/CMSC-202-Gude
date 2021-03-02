#include <iostream>
using namespace std;
int main (){
    double num1 = 4.1;
    double num2 = 5.8;
    double z = num2 - static_cast<int>(num1);
    cout << z << endl;
}