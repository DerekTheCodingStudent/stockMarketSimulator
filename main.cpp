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


// Should bring up a list of stocks and choose one to buy
void buyStock(user Player) {
    string stock = "";
    callMarket();

    cout << "Choose a stock name!" << endl;

    cin >> stock;

    cout << "does this show the stock price?";
    cout << stockMarket[stock] << endl;
    printf("\n\n\n\n");
    if (Player.getMoney() < stockMarket[stock]) {
        cout << "Not enough money!" << endl;
        return;
    }
    
    addStockToPortfolio(Player, stock, stockMarket[stock]);
}

// Should bring up their portfolio
void lookAtPortfolio() {

}

// Should bring up their portfolio and choose one (or a range) to sell
void sellStock() {

}





int main(int argc, char *argv[]) {
    cout << "Welcome to the stock market simulator!" << endl;
    int choice = 0;
    bool isLoop = true;
    user BOBO(100.00); // the first player in the game :)
    
    addStocksToMarket();

    while(isLoop) {
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
                sellStock();
                break;
            case 4:
                lookAtPortfolio();
                break;
            case 9:
                isLoop = false;
                break;
            case 42:
                cout << "\033[2J\033[H";
                break;
            default:
                if(choice != 9 && (choice > 5 || choice <= 8)) {
                    cout << "That's not one of the choices!" << endl;
                }

                
        }
    }

    return 0;
}
