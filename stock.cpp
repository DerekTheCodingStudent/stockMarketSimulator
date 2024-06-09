#include "stock.h"
#include "user.h"

extern map<string, double> stockMarket;


// Allows purchase of a stock.
void buyStock(user *Player) {
    string stock = "";
    int quantity = 0;
    callMarket();

    cout << "Choose a stock name!" << endl;

    cin >> stock;

    cout << "How many stocks in "<< stock << " do you want to purchase? You have: $" << Player->getMoney() << endl;

    cin >> quantity;

    if(quantity == 0) return;
    
    if (Player->getMoney() < stockMarket[stock] || Player->getMoney() < (stockMarket[stock] * quantity)) {
        cout << "Not enough money! You have $" << Player->getMoney() << endl;
        return;
    }
    
    addStockToPortfolio(Player, stock, stockMarket[stock], quantity);
}



// Sells a stock in the Player's portfolio
void sellStock(user *Player) {
    lookAtPortfolio(Player);

    string stockName = "";
    int quantity = 0;
    
    cout << "Choose a stock and how much of it to sell!" << endl;

    cin >> stockName >> quantity; 

    if (quantity == 0) return;

    if (quantity > Player->portfolio[stockName]->getQuantity()) {
        cout << "You choose a greater amount than the amount of stock you currently have!" << endl;
        return;
    }

    double priceToAddToPlayer = Player->portfolio[stockName]->getPrice() * quantity;
    Player->addMoney(priceToAddToPlayer);
    Player->portfolio[stockName]->subtractStock(quantity);

    if(Player->portfolio[stockName]->getQuantity() == 0) {
        delete(Player->portfolio[stockName]);
        Player->portfolio.erase(stockName);
    }
}