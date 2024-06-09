#include "main.h"
#include "market.h"

extern map<string, double> stockMarket;

void menu() {
    cout << "What would you like to do today?" << endl;
    cout << "1. Look at the market" << endl;
    cout << "2. Buy a stock" << endl;
    cout << "3. Sell a stock" << endl;
    cout << "4. Look at your portfolio" << endl;
    cout << "9. Quit" << endl;
}


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

// Bring up the Player's portfolio
void lookAtPortfolio(user *Player) {
    if (Player->portfolio.empty()) {
        cout << "You don't have any stocks!" << endl;
        return;
    }

    for(auto item : Player->portfolio) {
        cout << "Stock name: " << item.first << " How much you have " << item.second->getQuantity() << endl;
    }
}

// Sells a stock in the Player's portfolio
void sellStock(user *Player) {
    lookAtPortfolio(Player);

    string stockName = "";
    int quantity = 0;
    
    cout << "Choose a stock and how much of it to tell!" << endl;

    cin >> stockName >> quantity; 

    if (quantity == 0) return;

    if (quantity > Player->portfolio[stockName]->getQuantity()) {
        cout << "You choose a greater amount than the amount of stock you have!" << endl;
        return;
    }

    double priceToAddToPlayer = Player->portfolio[stockName]->getPrice() * quantity;
    Player->addMoney(priceToAddToPlayer);
    Player->portfolio[stockName]->subtractStock(quantity);

    if(Player->portfolio[stockName]->getQuantity() == 0) {
        Player->portfolio.erase(stockName);
    }
}

int main(int argc, char *argv[]) {
    cout << "Welcome to the stock market simulator!" << endl;
    int choice = 0;
    
    user *BOBO = new user(1000.00); // the first player in the game :)
    
    addStocksToMarket();

    while(true) {
        menu();
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                callMarket();
                break;
            case 2:
                buyStock(BOBO);
                break;
            case 3:
                sellStock(BOBO);
                break;
            case 4:
                lookAtPortfolio(BOBO);
                break;
            case 9:
                return false;
            case 42:
                cout << "\033[2J\033[H"; // clears the terminal
                break;
            default:
                if(choice != 9 && (choice > 5 || choice <= 8)) {
                    cout << "That's not one of the choices!" << endl;
                }
        }
    }

    delete BOBO;
    return 0;
}
