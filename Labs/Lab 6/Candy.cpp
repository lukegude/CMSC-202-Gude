#include <iostream>

#include "Candy.h"
using namespace std;

Candy::Candy(){};

Candy::Candy(string c_name, double c_price, int c_quantity){
    name = c_name;
    price = c_price;
    quantity = c_quantity;
}

void Candy::setName(string toSetName){
    name = toSetName;
}

void Candy::setPrice(double toSetPrice){
    price = toSetPrice;
}

string Candy::getName(){
    return name;
}

double Candy::getPrice(){
    return price;
}

int Candy::getQuantity(){
    return quantity;
} 