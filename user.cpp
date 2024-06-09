#include "user.h"

// file is used to simulate a person

/* Adds a stock the Player's portfolio.
*
*
*
*
*
*/
void addStockToPortfolio(user *Player, string name, double price, int quantity) {
    bool isStockInPortfolio = false;
    for(auto& item : Player->portfolio) {
        if(item.first.compare(name) == 0) { // If the stock is already in the portfolio, then add
            Player->subtractMoney(quantity * price);
            item.second->addStock(quantity * price);
            isStockInPortfolio = true;
        }
    }

    if(!isStockInPortfolio) {
        stock *newStock = new stock(quantity, price);
        Player->subtractMoney(quantity * price);
        Player->portfolio[name] = newStock;
    }
}
