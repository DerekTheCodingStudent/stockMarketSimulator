#ifndef STOCK_MAIN
#define STOCK_MAIN

#include <iostream>
#include <string>
#include <deque>
#include "market.h"

extern map<string, double> stockMarket;

class user; // need to forward declare so the program can break cicular dependency.

using namespace std;

// lowkey, I think I should be making the stock class into a linkedlist... 
// This will solve my name, price, and quantity mess.
class stock {
    private:
        map<string,map<double,double>> portfolio; // inner map = price, quantity. the price = price of stock bought at.
    
    public:
        stock() {};
        stock(string name, double quantity, double price) {
            portfolio[name][price] = quantity;
        }

        double getQuantity(string name, double price) {
            return portfolio[name][price];
        }

        void getPrice(string name) {
            for(auto n : portfolio) {
                if(n.first.compare(name) == 0) {
                    for(auto m : n.second) {
                        cout << name << "'s price: " << m.first << " and quantity: " << m.second << endl;
                    }
                }
            }
        }

        void addStock(string name, double quantity, double price) {
            portfolio[name][price] += quantity;
        }

        double subtractStock(string name, double price, double quantity) {
            double moneyBack = 0.0;
            // If whatever quantity is in the portfolio is greater then the requested amount,
            // sell the stock by the price. 
            // If it's less than or equal to, then sell x amount in the portfolio and erase it's entry in the map.
            if(portfolio[name][price] > quantity) {
                moneyBack = stockMarket[name] - portfolio[name][price] * price;
                portfolio[name][price] -= quantity;
            } else {
                moneyBack = portfolio[name][price] * price;
                portfolio.erase(name);
            }

            return moneyBack;
        }

        void lookAtPortfolio() {
            if(portfolio.empty()) {
                cout << "There's nothing in your portfolio!" << endl;
                return;
            }

            for(auto n : portfolio) {
                cout << n.first << " ";

                for(auto m : n.second) {
                    cout << "price: " << m.first << " quantity: " << m.second << endl;
                }
            }
        }
};

void buyStock(user *Player);
void sellStock(user *Player);


#endif