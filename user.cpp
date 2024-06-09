#include "user.h"

// file is used to simulate a person

// no clue if this works lol
void addStockToPortfolio(user& Player, string name, double price) {
    bool isStockInPortfolio = false;
    for(auto& item : Player.portfolio) {
        if(item.first.compare(name) == 0) { // If the stock is already in the portfolio, then add
            double quantity = Player.getMoney() / price;
            Player.subtractMoney(quantity);
            item.second.addStock(quantity);
            isStockInPortfolio = true;
        }
    }

    if(!isStockInPortfolio) {
        double quantity = Player.getMoney() / price;
        Player.subtractMoney(quantity);
        Player.portfolio[name] = quantity;
    }
}
