#include "stock.h"
#include "user.h"

extern map<string, double> stockMarket;


// Allows purchase of a stock.
void buyStock(user *Player) {
    string stock = "";
    double quantity = 0;
    
    callMarket();

    cout << "Choose a stock name!" << endl;

    cin >> stock;

    cout << "How many stocks in "<< stock << " do you want to purchase? You have: $" << Player->getMoney() << endl;

    cin >> quantity;

    double price = stockMarket[stock];

    if(quantity == 0) return;
    
    if (Player->getMoney() < price || Player->getMoney() < (price * quantity)) {
        cout << "Not enough money! You have $" << Player->getMoney() << endl;
        return;
    }
    
    addStockToPortfolio(Player, stock, price, quantity);
    Player->subtractMoney(price*quantity);
}



// Sells a stock in the Player's portfolio
void sellStock(user *Player) {
    lookAtPortfolio(Player);

    string stockName = "";
    double quantity = 0;
    double price = 0.0;
    
    cout << "Choose a stock, it's price, and it's quantity to sell!" << endl;

    cin >> stockName >> price >> quantity; 

    
    if (quantity == 0) return;

    double moneyBack = Player->portfolio.subtractStock(stockName,price,quantity);

    Player->addMoney(moneyBack);
}   