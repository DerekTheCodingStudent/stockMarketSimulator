#include "user.h"

// file is used to simulate a person

/* Adds a stock the Player's portfolio.
*
*
*
*
*
*/
void addStockToPortfolio(user *Player, string name, double price) {
    bool isStockInPortfolio = false;
    for(auto& item : Player->portfolio) {
        if(item.first.compare(name) == 0) { // If the stock is already in the portfolio, then add
            double quantity = Player->getMoney() / price;
            Player->subtractMoney(quantity * price);
            item.second->addStock(quantity * price);
            isStockInPortfolio = true;
        }
    }

    if(!isStockInPortfolio) {
        double quantity = Player->getMoney() / price;
        stock *newStock = new stock(quantity, price);
        Player->subtractMoney(quantity * price);
        Player->portfolio[name] = newStock;
    }
}
