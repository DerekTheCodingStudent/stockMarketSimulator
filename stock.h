#ifndef STOCK_MAIN
#define STOCK_MAIN

#include <iostream>
#include <string>

#include "market.h"

class user; // need to forward declare so the program can break cicular dependency.

using namespace std;

class stock {
    private:
        double quantity;
        double price;

    public:

        stock(double quantity, double price) {
            this->quantity = quantity;
            this->price = price;
        }

        double getQuantity() {
            return quantity;
        }

        double getPrice() {
            return price;
        }

        void addStock(double quantity) {
            this->quantity += quantity;
        }

        void subtractStock(double quantity) {
            this->quantity -= quantity;
        }
};

void buyStock(user *Player);
void sellStock(user *Player);


#endif