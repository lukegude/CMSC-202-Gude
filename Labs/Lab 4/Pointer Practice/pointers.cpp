#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
    public:
    Fraction(int num, int denom){
        numerator = num;
        denominator = denom;
    }
        void reciprocal(){
            int temp;
            temp = numerator;
            numerator = denominator;
            denominator = temp;
        };
        void print(){
            cout << numerator << "/" << denominator << endl;
        }
};


int main (){

    Fraction frac(4, 5);
    frac.reciprocal();
    frac.print();
}