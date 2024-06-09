#ifndef USER_MAIN
#define USER_MAIN

#include <map>
#include <string>
#include <cstring>
#include "stock.h"
using namespace std;

class user {
    private:
        double money;
        

    public:
        map<string, stock*> portfolio;


        user(int money) {
            this->money = money;
        }
        
        double getMoney() {
            return money;
        }
        void addMoney(double money) {
            this->money += money;
        }

        void subtractMoney(double money) {
            this->money -= money;
        }


};

void addStockToPortfolio(user *Player, string name, double price);

#endif