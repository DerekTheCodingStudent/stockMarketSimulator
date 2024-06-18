#include "main.h"
#include "stock.h"
#include <chrono>


void menu() {
    cout << "What would you like to do today?" << endl;
    cout << "0. Check how much money you have!" << endl;
    cout << "1. Look at the market" << endl;
    cout << "2. Buy a stock" << endl;
    cout << "3. Sell a stock" << endl;
    cout << "4. Look at your portfolio" << endl;
    cout << "9. Quit" << endl;
}

void freeMemoryUsage(user *Player) {
    delete Player;
}


int main(int argc, char *argv[]) {
    auto start = chrono::high_resolution_clock::now();
    cout << "Welcome to the stock market simulator!" << endl;
    int choice = 0;
    
    user *BOBO = new user(1000.00); // the first player in the game :)
    
    openMarket();

    while(true) {
        menu();
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 0:
                cout << "You currently have $" << BOBO->getMoney() << endl << endl;
                break;
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
            case 42:
                cout << "\033[2J\033[H"; // clears the terminal
                break;
            default:
                if(choice != 9 && (choice >= 5 || choice <= 8)) {
                    cout << "That's not one of the choices!" << endl;
                }
            case 9:
                freeMemoryUsage(BOBO);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> dur = end - start;
                cout << "time taken = " << dur.count() << endl;
                return 0;
        }
    }
}
