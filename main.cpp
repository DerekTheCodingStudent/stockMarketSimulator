#include "main.h"
#include "stock.h"
#include "user.h"

extern map<string, double> stockMarket;

void menu() {
    cout << "What would you like to do today?" << endl;
    cout << "1. Look at the market" << endl;
    cout << "2. Buy a stock" << endl;
    cout << "3. Sell a stock" << endl;
    cout << "4. Look at your portfolio" << endl;
    cout << "9. Quit" << endl;
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
